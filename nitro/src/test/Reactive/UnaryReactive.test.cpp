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
    const auto nx{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(&n, [](const unsigned int*const value) {
      return *value + *value;
    }) };
    n.set(2u);
    REQUIRE(n.get() == 2u);
    REQUIRE(nx->get() == 4u);
    const auto ny{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(&n, [](const unsigned int*const value) {
      return *value * *value;
    }) };
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(nx->get() == 6u);
    REQUIRE(ny->get() == 9u);
    const auto nz{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(&n, [](const unsigned int*const value) {
      return static_cast<unsigned int>(sqrt(*value));
    }) };
    n.set(4u);
    REQUIRE(n.get() == 4u);
    REQUIRE(nx->get() == 8u);
    REQUIRE(ny->get() == 16u);
    REQUIRE(nz->get() == 2u);
    const auto nw{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(nullptr, [](const unsigned int*const) {
      return 0u;
    }) };

    delete nw;
    delete nz;
    delete ny;
    delete nx;
  }
  {
    UnaryReactive<unsigned int, unsigned int> n{ 2u };
    n.set(1u);
    REQUIRE(n.get() == 1u);
    const auto nx{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(&n, [](const unsigned int*const value) {
      return *value + *value;
    }) };
    n.set(2u);
    REQUIRE(n.get() == 2u);
    REQUIRE(nx->get() == 4u);
    const auto ny{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(&n, [](const unsigned int*const value) {
      return *value * *value;
    }) };
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(nx->get() == 6u);
    REQUIRE(ny->get() == 9u);
    const auto nz{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(&n, [](const unsigned int*const value) {
      return static_cast<unsigned int>(sqrt(*value));
    }) };
    n.set(4u);
    REQUIRE(n.get() == 4u);
    REQUIRE(nx->get() == 8u);
    REQUIRE(ny->get() == 16u);
    REQUIRE(nz->get() == 2u);
    const auto nw{ UnaryReactive<unsigned int, unsigned int>::make<unsigned int>(nullptr, [](const unsigned int*const) {
      return 0u;
    }) };

    delete nw;
    delete nz;
    delete ny;
    delete nx;
  }
}

}  // namespace ii887522::nitro

#endif
