#ifndef II887522_NITRO_RANGE_H
#define II887522_NITRO_RANGE_H

namespace ii887522::nitro
{
	template <typename T> struct Range final
	{
		// remove copy semantics
		Range(const Range&) = delete;
		Range& operator=(const Range&) = delete;

		// remove move semantics
		Range(Range&&) = delete;
		Range& operator=(Range&&) = delete;

		const T min;
		const T max;

	public:
		explicit constexpr Range(const T& min, const T& max) : min{ min }, max{ max } { }
	};
}

#endif
