// Copyright ii887522

#ifndef NITRO_SRC_MAIN_STRUCT_VECTOR_H_
#define NITRO_SRC_MAIN_STRUCT_VECTOR_H_

namespace ii887522::nitro {

template <typename T> struct Vector final {
  T x;
  T y;

  explicit constexpr Vector(const T& x, const T& y) : x{ x }, y{ y } { }

  template <typename U> constexpr Vector<T> operator*(const U& scale) const {
    return Vector{ static_cast<T>(x * scale), static_cast<T>(y * scale) };
  }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_STRUCT_VECTOR_H_
