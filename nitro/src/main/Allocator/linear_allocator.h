// Copyright ii887522

#ifdef LINEAR_ALLOCATOR

#ifndef NITRO_SRC_MAIN_ALLOCATOR_LINEAR_ALLOCATOR_H_
#define NITRO_SRC_MAIN_ALLOCATOR_LINEAR_ALLOCATOR_H_

#include <new>
#include <algorithm>
#include "../Functions/math_ext.h"

using ii887522::nitro::min;
using std::bad_alloc;

#ifdef _DEBUG
#include <iostream>

using std::cout;
#endif

namespace ii887522::nitro {

enum class Term : unsigned int {
  LONG, SHORT
};

#ifdef ALLOCATOR_IMPLEMENTATIONS
static char longTermData[LONG_TERM_ALLOCATOR_SIZE];
static size_t longTermDataSize{ 0u };
#ifdef SHORT_TERM_ALLOCATOR_SIZE
static char shortTermData[SHORT_TERM_ALLOCATOR_SIZE];
static size_t shortTermDataSize{ 0u };
#endif
static Term term{ Term::LONG };
#endif

constexpr static size_t getAlignedDataSize(const size_t dataSize, const size_t size) {
  const auto alignmentRequirement{ min(size, alignof(max_align_t)) };
  return (dataSize / alignmentRequirement + 1u) * alignmentRequirement;
}

#ifdef ALLOCATOR_IMPLEMENTATIONS
// Not Thread Safe
static void* longTermAlloc(const size_t size) {
  longTermDataSize = getAlignedDataSize(longTermDataSize, size);
  const auto result{ longTermData + longTermDataSize };
  longTermDataSize += size;
#ifdef _DEBUG
  cout << "Long term data usage: " << longTermDataSize << " bytes\n";
#endif
  return result;
}

// Not Thread Safe
static void* shortTermAlloc(const size_t size) {
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
#endif

#ifdef SHORT_TERM_ALLOCATOR_SIZE
void beginShortTermAlloc()
#ifdef ALLOCATOR_IMPLEMENTATIONS
{
  term = Term::SHORT;
}
#else
;  // NOLINT(whitespace/semicolon)
#endif

void endShortTermAlloc()
#ifdef ALLOCATOR_IMPLEMENTATIONS
{
  shortTermDataSize = 0u;
  term = Term::LONG;
}
#else
;  // NOLINT(whitespace/semicolon)
#endif
#endif

}  // namespace ii887522::nitro

#ifdef ALLOCATOR_IMPLEMENTATIONS
using ii887522::nitro::Term;
using ii887522::nitro::term;
using ii887522::nitro::longTermAlloc;
using ii887522::nitro::shortTermAlloc;
#endif

// Not Thread Safe
void* operator new(const size_t size)
#ifdef ALLOCATOR_IMPLEMENTATIONS
{
  switch (term) {
    case Term::LONG: return longTermAlloc(size);
    case Term::SHORT: return shortTermAlloc(size);
  }
  throw bad_alloc{ };
}
#else
;  // NOLINT(whitespace/semicolon)
#endif

// Not Thread Safe
void operator delete(void* const)
#ifdef ALLOCATOR_IMPLEMENTATIONS
{ }
#else
;  // NOLINT(whitespace/semicolon)
#endif

#endif
#endif  // NITRO_SRC_MAIN_ALLOCATOR_LINEAR_ALLOCATOR_H_
