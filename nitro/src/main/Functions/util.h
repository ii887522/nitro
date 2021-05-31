// Copyright ii887522

#ifndef NITRO_SRC_MAIN_FUNCTIONS_UTIL_H_
#define NITRO_SRC_MAIN_FUNCTIONS_UTIL_H_

#include <functional>
#include <cstring>
#include <string>
#include "math_ext.h"  // NOLINT(build/include_subdir)
#include "../Struct/Range.h"

using std::function;
using std::string;

namespace ii887522::nitro {

template <typename T> constexpr void swap(T& l, T& r) {
  const T aux{ l };
  l = r;
  r = aux;
}

/// <param name="objects">It must not be assigned to nullptr or integer and must not be an empty vector</param>
/// <param name="indices">
///   min must be lower than objects.size(), max must be higher than or equal to min,
///   max can be higher than or equal to objects.size() which means until the end of objects need to be sorted
/// </param>
/// <param name="compare">It returns true if two objects passed in needs to be sorted</param>
template <typename T, template <typename> typename U> void insertionSort(U<T>*const objects, const Range<unsigned int>& indices = Range{ 0u, UINT_MAX },
  const function<bool(const T& l, const T& r)>& compare = [](const T& l, const T& r) {
    return l > r;
  }) {
  const auto maxI{ min(indices.max, static_cast<unsigned int>(objects->size() - 1u)) };
  for (auto i{ indices.min + 1u }; i <= maxI; ++i) {
    for (auto j{ i }; j > indices.min; --j) {
      if (compare((*objects)[j - 1u], (*objects)[j])) swap((*objects)[j - 1u], (*objects)[j]);
      else
        break;
    }
  }
}

/// <param name="objects">It must not be assigned to nullptr or integer and must be an empty vector</param>
/// <param name="startStep">It is a starting number of consecutive items in objects that will become sorted. It must be a power of two and higher than 1</param>
/// <param name="compare">It returns true if two objects passed in needs to be sorted</param>
template <typename T, template <typename> typename U> void mergeSort(U<T>*const objects, const unsigned int startStep = 2u, const function<bool(const T& l, const T& r)>& compare =
  [](const T& l, const T& r) {
    return l > r;
  }) {
  U<T> aux(objects->size());
  auto step{ startStep };
  U<T>* currentObjects{ &aux };
  U<T>* nextObjects{ objects };
  while (true) {
    for (auto i{ 0u }; i < objects->size(); i += step) {
      auto l{ i };
      auto r{ i + (step >> 1u) };  // which means r = i + step / 2
      for (auto j{ i }; j != min(i + step, static_cast<unsigned int>(objects->size())); ++j) {
        if (r < objects->size() && r != i + step && (l == i + (step >> 1u)  /* which means l == i + step / 2 */ || compare((*nextObjects)[l], (*nextObjects)[r]))) {
          (*currentObjects)[j] = (*nextObjects)[r];
          ++r;
        } else {
          (*currentObjects)[j] = (*nextObjects)[l];
          ++l;
        }
      }
    }
    ii887522::nitro::swap(currentObjects, nextObjects);  // NOLINT(build/include_what_you_use)
    if (step >= objects->size()) break;
    step <<= 1u;  // which means step *= 2
  }
  if (currentObjects == objects) memcpy(objects->data(), aux.data(), objects->size() * sizeof T);
}

/// <param name="objects">It must not be assigned to nullptr or integer and must not be an empty vector</param>
/// <param name="runSize">
///   It is a number of consecutive items in objects that will become sorted. It must be higher than 0.
///   It can be higher than the size of objects which means the whole objects will become sorted.
/// </param>
/// <param name="compare">It returns true if two objects passed in needs to be sorted</param>
template <typename T, template <typename> typename U> void insertionSorts(U<T>*const objects, const unsigned int runSize = UINT_MAX, const function<bool(const T& l, const T& r)>& compare =
  [](const T& l, const T& r) {
    return l > r;
  }) {
  for (auto i{ 0u }; i < objects->size(); i += runSize) insertionSort<T, U>(objects, Range{ i, i + runSize - 1u }, compare);
}

/// <param name="objects">It must not be assigned to nullptr or integer and must not be an empty vector</param>
/// <param name="compare">It returns true if two objects passed in needs to be sorted</param>
template <typename T, template <typename> typename U> void sort(U<T>*const objects, const function<bool(const T& l, const T& r)>& compare = [](const T& l, const T& r) {  // NOLINT(build/include_what_you_use)
  return l > r;
}) {
  constexpr auto runSize{ 32u };
  insertionSorts<T, U>(objects, runSize, compare);
  mergeSort<T, U>(objects, runSize, compare);
}

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_FUNCTIONS_UTIL_H_
