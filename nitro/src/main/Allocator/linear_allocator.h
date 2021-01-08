#ifdef LINEAR_ALLOCATOR

#ifndef II887522_NITRO_LINEAR_ALLOCATOR_H
#define II887522_NITRO_LINEAR_ALLOCATOR_H

#include "../Functions/math_ext.h"
#include <new>

using ii887522::nitro::min;
using std::bad_alloc;

#ifdef _DEBUG
#include <iostream>

using std::cout;
#endif

namespace ii887522::nitro
{
	enum class Term : unsigned int
	{
		LONG, SHORT
	};

	static char longTermData[LONG_TERM_ALLOCATOR_SIZE];
	static size_t longTermDataSize{ 0u };
#ifdef SHORT_TERM_ALLOCATOR_SIZE
	static char shortTermData[SHORT_TERM_ALLOCATOR_SIZE];
	static size_t shortTermDataSize{ 0u };
#endif
	static Term term{ Term::LONG };

	constexpr static size_t getAlignedDataSize(const size_t dataSize, const size_t size)
	{
		const auto alignmentRequirement{ min(size, alignof(max_align_t)) };
		return (dataSize / alignmentRequirement + 1u) * alignmentRequirement;
	}

	// Not Thread Safe
	static void* longTermAlloc(const size_t size)
	{
		longTermDataSize = getAlignedDataSize(longTermDataSize, size);
		const auto result{ longTermData + longTermDataSize };
		longTermDataSize += size;
#ifdef _DEBUG
		cout << "Long term data usage: " << longTermDataSize << " bytes\n";
#endif
		return result;
	}


	// Not Thread Safe
	static void* shortTermAlloc(const size_t size)
	{
#ifdef SHORT_TERM_ALLOCATOR_SIZE
		shortTermDataSize = getAlignedDataSize(shortTermDataSize, size);
		const auto result{ shortTermData + shortTermDataSize };
		shortTermDataSize += size;
#ifdef _DEBUG
		cout << "Short term data usage: " << shortTermDataSize << " bytes\n";
#endif
		return result;
#else
		size;
		return nullptr;
#endif
	}

#ifdef SHORT_TERM_ALLOCATOR_SIZE
	constexpr void beginShortTermAlloc()
	{
		term = Term::SHORT;
	}

	constexpr void endShortTermAlloc()
	{
		shortTermDataSize = 0u;
		term = Term::LONG;
	}
#endif
}

using ii887522::nitro::Term;
using ii887522::nitro::term;
using ii887522::nitro::longTermAlloc;
using ii887522::nitro::shortTermAlloc;

// Not Thread Safe
void* operator new(const size_t size)
{
	switch (term)
	{
	case Term::LONG: return longTermAlloc(size);
	case Term::SHORT: return shortTermAlloc(size);
	}
	throw bad_alloc{ };
}

// Not Thread Safe
void operator delete(void*const) { }

#endif
#endif
