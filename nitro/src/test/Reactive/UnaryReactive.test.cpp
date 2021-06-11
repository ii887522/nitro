// Copyright ii887522

#ifdef TEST

#include <cmath>
#include <catch.hpp>
#include "../../main/Reactive/UnaryReactive.h"

namespace ii887522::nitro {

TEST_CASE("test UnaryReactive<R, T>::set() function") {
  {
    UnaryReactive<unsigned int, unsigned int> n{ 0u };
    n.set(1u);
    REQUIRE(n.get() == 1u);
    UnaryReactive<unsigned int, unsigned int> nx{ &n, [](const unsigned int* const value) {
      return *value + *value;
    } };
    n.set(2u);
    REQUIRE(n.get() == 2u);
    REQUIRE(nx.get() == 4u);
    UnaryReactive<unsigned int, unsigned int> ny{ &n, [](const unsigned int* const value) {
      return *value * *value;
    } };
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(nx.get() == 6u);
    REQUIRE(ny.get() == 9u);
    UnaryReactive<unsigned int, unsigned int> nz{ &n, [](const unsigned int* const value) {
      return static_cast<unsigned int>(sqrt(*value));
    } };
    n.set(4u);
    REQUIRE(n.get() == 4u);
    REQUIRE(nx.get() == 8u);
    REQUIRE(ny.get() == 16u);
    REQUIRE(nz.get() == 2u);
    UnaryReactive<unsigned int, unsigned int> nw{ nullptr, [](const unsigned int* const) {
      return 0u;
    } };
  }
  {
    UnaryReactive<unsigned int, unsigned int> n{ 2u };
    n.set(1u);
    REQUIRE(n.get() == 1u);
    UnaryReactive<unsigned int, unsigned int> nx{ &n, [](const unsigned int* const value) {
      return *value + *value;
    } };
    n.set(2u);
    REQUIRE(n.get() == 2u);
    REQUIRE(nx.get() == 4u);
    UnaryReactive<unsigned int, unsigned int> ny{ &n, [](const unsigned int* const value) {
      return *value * *value;
    } };
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(nx.get() == 6u);
    REQUIRE(ny.get() == 9u);
    UnaryReactive<unsigned int, unsigned int> nz{ &n, [](const unsigned int* const value) {
      return static_cast<unsigned int>(sqrt(*value));
    } };
    n.set(4u);
    REQUIRE(n.get() == 4u);
    REQUIRE(nx.get() == 8u);
    REQUIRE(ny.get() == 16u);
    REQUIRE(nz.get() == 2u);
    UnaryReactive<unsigned int, unsigned int> nw{ nullptr, [](const unsigned int* const) {
      return 0u;
    } };
  }
}

}  // namespace ii887522::nitro

#endif
