// Copyright ii887522

#ifdef TEST

#include "Vector.test.h"
#include "../../main/Struct/Vector.h"

namespace ii887522::nitro {

constexpr static void testMultiplication() {
  static_assert((Vector { 1u, 2u } * 0u).x == 0u);
  static_assert((Vector { 3u, 4u } * 1u).y == 4u);
  static_assert((Vector { 5u, 6u } * 2u).x == 10u);
  static_assert((Vector { 7u, 8u } * 3u).y == 24u);
}

void testVector() {
  testMultiplication();
}

}  // namespace ii887522::nitro

#endif
