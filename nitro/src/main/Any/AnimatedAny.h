#ifndef II887522_NITRO_ANIMATED_ANY_H
#define II887522_NITRO_ANIMATED_ANY_H

#include "../Functions/math_ext.h"
#include "../Struct/Range.h"
#include <stdexcept>
#include <typeinfo>
#include <string>
#include "Reactive.h"
#include <functional>

using std::runtime_error;
using std::string;
using std::function;

namespace ii887522::nitro
{
	// Param T: it must not be equal to unsigned type
	template <typename T> struct AnimatedAny final
	{
		// Not Thread Safe
		class Builder final
		{
			// remove copy semantics
			Builder(const Builder&) = delete;
			Builder& operator=(const Builder&) = delete;

			// remove move semantics
			Builder(Builder&&) = delete;
			Builder& operator=(Builder&&) = delete;

			const T value;
			unsigned int duration; // animation duration
			bool hasSetDuration; // has set animation duration
			const function<void()> onAnimationEnd;

		public:
			explicit constexpr Builder(const T& value, const function<void()>& onAnimationEnd = []() { }) : value{ value }, duration{ 0u },
				hasSetDuration{ false }, onAnimationEnd{ onAnimationEnd } { }

			// Animation duration
			// Param p_value: it must not be assigned to 0
			// Must Call Time(s): At least 1
			constexpr Builder& setDuration(const unsigned int p_value)
			{
				duration = p_value;
				hasSetDuration = true;
				return *this;
			}

			// Must Call Time(s): At least 1
			AnimatedAny<T> build()
			{
				if (hasSetDuration) return AnimatedAny{ *this };
				throw runtime_error{ string{ "AnimatedAny<" } + typeid(T).name() + "> duration is required!" };
			}

			friend struct AnimatedAny;
		};

	private:
		T start;
		T now;
		T end;
		const unsigned int duration; // animation duration
		unsigned int elaspedTime;
		const function<void()> onAnimationEnd;

		explicit constexpr AnimatedAny(const Builder& builder) : start{ builder.value }, now{ builder.value }, end{ builder.value },
			duration{ builder.duration }, elaspedTime{ 0u }, onAnimationEnd{ builder.onAnimationEnd } { }

	public:
		constexpr const T& getStart() const
		{
			return start;
		}

		constexpr const T& get() const
		{
			return now;
		}

		constexpr const T& getEnd() const
		{
			return end;
		}

		constexpr void set(const T& value)
		{
			start = now;
			end = value;
			elaspedTime = 0u;
		}

		constexpr void teleport(const T& value)
		{
			start = now;
			now = value;
			end = value;
			elaspedTime = duration;
		}

		constexpr void step(const unsigned int dt)
		{
			if (elaspedTime == duration) return;
			elaspedTime += dt;
			clamp(elaspedTime, Range{ 0u, duration });
			now = static_cast<T>(start + (end - start) * (static_cast<float>(elaspedTime) / duration));
			if (elaspedTime == duration) onAnimationEnd();
		}
	};
}

#endif
