#ifndef II887522_NITRO_VECTOR_H
#define II887522_NITRO_VECTOR_H

namespace ii887522::nitro
{
	template <typename T> struct Vector final
	{
		T x;
		T y;

		explicit constexpr Vector(const T& x, const T& y) : x{ x }, y{ y } { }

		template <typename U> constexpr Vector<T> operator*(const U& scale) const
		{
			return Vector{ static_cast<T>(x * scale), static_cast<T>(y * scale) };
		}
	};
}

#endif
