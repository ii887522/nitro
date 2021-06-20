// Copyright ii887522

#ifndef NITRO_SRC_MAIN_STRUCT_PAIR_H_
#define NITRO_SRC_MAIN_STRUCT_PAIR_H_

namespace ii887522::nitro {

template <typename T, typename U> struct Pair final {
  T key;
  U value;

  explicit constexpr Pair(const T& key, const U& value) : key{ key }, value{ value } { }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_STRUCT_PAIR_H_
