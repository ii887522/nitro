#ifndef II887522_NITRO_REACTIVE_H
#define II887522_NITRO_REACTIVE_H

#include <functional>
#include <vector>

using std::function;
using std::vector;

namespace ii887522::nitro
{
	// Not Thread Safe
	template <typename T> class Reactive
	{
		// remove copy semantics
		Reactive(const Reactive&) = delete;
		Reactive& operator=(const Reactive&) = delete;

		// remove move semantics
		Reactive(Reactive&&) = delete;
		Reactive& operator=(Reactive&&) = delete;

		T value;
		vector<function<void(const T&, const int)>> handlers;

	public:
		explicit constexpr Reactive(const T& value) : value{ value } { }

		constexpr const T& get() const
		{
			return value;
		}

		virtual void set(const T& p_value, const int ignoredHandlerI = -1)
		{
			value = p_value;
			for (auto i{ 0u }; i != handlers.size(); ++i) if (static_cast<int>(i) != ignoredHandlerI) handlers[i](value, i);
		}

		constexpr void watch(const function<void(const T&, const int)>& handler)
		{
			handlers.push_back(handler);
		}
	};
}

#endif
