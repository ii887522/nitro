// Copyright ii887522

#ifndef NITRO_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
#define NITRO_SRC_MAIN_FUNCTIONS_MATH_EXT_H_

#include <algorithm>
#include "../Struct/Range.h"

namespace ii887522::nitro {

// Param value: it must not be assigned to nullptr and integer
template <typename T> constexpr void clamp(T*const value, const Range<T>& range) {
  if (*value < range.min) *value = range.min;
  else if (*value > range.max) *value = range.max;
}

template <typename T> constexpr bool isOverlapX(const T& x, const Range<T>& xRange) {
  return x >= xRange.min && x < xRange.max;
}

template <typename T> constexpr bool isOverlapY(const T& y, const Range<T>& yRange) {
  return y >= yRange.min && y < yRange.max;
}

template <typename T> constexpr T min(const T& l, const T& r) {
  return l < r ? l : r;
}

template <typename T> constexpr T max(const T& l, const T& r) {
  return l > r ? l : r;
}

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
