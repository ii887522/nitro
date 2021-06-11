// Copyright ii887522

#ifdef TEST

#include <catch.hpp>
#include "../../main/Any/Reactive.h"

namespace ii887522::nitro {

TEST_CASE("test Reactive<T>::set() function") {
  {
    Reactive n{ 0u };
    n.set(1u);
    REQUIRE(n.get() == 1u);
    auto count{ 0u };
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(2u);
    REQUIRE(n.get() == 2u);
    REQUIRE(count == 2u);
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(count == 8u);
    n.watch([&n, &count](const unsigned int& value, const int handlerI) {
      count += value;
      n.set(count, handlerI);
    });
    n.set(4u);
    REQUIRE(n.get() == 20u);
    REQUIRE(count == 60u);
  }
  {
    Reactive n{ 2u };
    n.set(1u);
    REQUIRE(n.get() == 1u);
    auto count{ 0u };
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(2u);
    REQUIRE(n.get() == 2u);
    REQUIRE(count == 2u);
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(count == 8u);
    n.watch([&n, &count](const unsigned int& value, const int handlerI) {
      count += value;
      n.set(count, handlerI);
    });
    n.set(4u);
    REQUIRE(n.get() == 20u);
    REQUIRE(count == 60u);
  }
}

}  // namespace ii887522::nitro

#endif
