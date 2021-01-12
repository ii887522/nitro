// Copyright ii887522

#ifndef NITRO_SRC_MAIN_STRUCT_RANGE_H_
#define NITRO_SRC_MAIN_STRUCT_RANGE_H_

namespace ii887522::nitro {

template <typename T> struct Range final {
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

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_STRUCT_RANGE_H_
