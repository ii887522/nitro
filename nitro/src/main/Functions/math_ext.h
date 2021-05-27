// Copyright ii887522

#ifndef NITRO_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
#define NITRO_SRC_MAIN_FUNCTIONS_MATH_EXT_H_

#include <algorithm>
#include <string>
#include "../Struct/Range.h"

using std::string;

namespace ii887522::nitro {

/// <param name="value">It must not be assigned to nullptr and integer</param>
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

constexpr bool isDigit(const char ch) {
  return ch >= '0' && ch <= '9';
}

bool isUint(const string&);

constexpr unsigned int parseUint(const char ch) {
  return ch - '0';
}

unsigned int parseUint(const string& uintStr);

/// <summary>Power of Two is a number that is equal to 2^n where n is an integer.</summary>
template <typename T> bool isPowerOfTwo(const T& n) {
  const auto power{ log2f(static_cast<float>(n)) };
  return power == static_cast<int>(power);
}

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
