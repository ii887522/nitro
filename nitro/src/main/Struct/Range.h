// Copyright ii887522

#ifndef NITRO_SRC_MAIN_STRUCT_RANGE_H_
#define NITRO_SRC_MAIN_STRUCT_RANGE_H_

namespace ii887522::nitro {

template <typename T> struct Range final {
  T min;
  T max;

 public:
  explicit constexpr Range() { }
  explicit constexpr Range(const T& min, const T& max) : min{ min }, max{ max } { }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_STRUCT_RANGE_H_
