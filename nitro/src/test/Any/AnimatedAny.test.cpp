// Copyright ii887522

#ifdef TEST

#include <stdexcept>
#include <catch.hpp>
#include "../../main/Any/AnimatedAny.h"
#include "../../main/Any/Reactive.h"

using std::runtime_error;

namespace ii887522::nitro {

TEST_CASE("test AnimatedAny<T>::Builder::build() function") {
  REQUIRE(AnimatedAny<int>::Builder{ 0 }.setDuration(250u).build().get() == 0);
  REQUIRE(AnimatedAny<int>::Builder{ 1 }.setDuration(250u).build().get() == 1);
  REQUIRE(AnimatedAny<int>::Builder{ 1 }.setDuration(500u).build().get() == 1);
  {
    auto n{ 0u };
    REQUIRE((AnimatedAny<int>::Builder{ 1, [&n]() {
      ++n;
    } }.setDuration(500u).build().get() == 1));
    REQUIRE(n == 0u);
  }
  REQUIRE_THROWS(AnimatedAny<int>::Builder{ 0 }.build());
  REQUIRE_THROWS(AnimatedAny<int>::Builder{ 1 }.build());
  {
    auto n{ 0u };
    REQUIRE_THROWS(AnimatedAny<int>::Builder{ 1, [&n]() {
      ++n;
    } }.build());
  }
}

TEST_CASE("test AnimatedAny<T>::teleport() function") {
  {
    AnimatedAny n{ AnimatedAny<int>::Builder{ 0 }.setDuration(250u).build() };
    n.teleport(1);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 1);
    REQUIRE(n.getEnd() == 1);
    n.teleport(2);
    REQUIRE(n.getStart() == 1);
    REQUIRE(n.get() == 2);
    REQUIRE(n.getEnd() == 2);
  }
  {
    AnimatedAny n{ AnimatedAny<int>::Builder{ 10 }.setDuration(250u).build() };
    n.teleport(1);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 1);
    REQUIRE(n.getEnd() == 1);
    n.teleport(2);
    REQUIRE(n.getStart() == 1);
    REQUIRE(n.get() == 2);
    REQUIRE(n.getEnd() == 2);
  }
  {
    AnimatedAny n{ AnimatedAny<int>::Builder{ 10 }.setDuration(500u).build() };
    n.teleport(1);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 1);
    REQUIRE(n.getEnd() == 1);
    n.teleport(2);
    REQUIRE(n.getStart() == 1);
    REQUIRE(n.get() == 2);
    REQUIRE(n.getEnd() == 2);
  }
  {
    auto m{ 0u };
    AnimatedAny n{ AnimatedAny<int>::Builder{ 10, [&m]() {
      ++m;
    } }.setDuration(500u).build() };
    n.teleport(1);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 1);
    REQUIRE(n.getEnd() == 1);
    REQUIRE(m == 0u);
    n.teleport(2);
    REQUIRE(n.getStart() == 1);
    REQUIRE(n.get() == 2);
    REQUIRE(n.getEnd() == 2);
    REQUIRE(m == 0u);
  }
}

TEST_CASE("test AnimatedAny<T>::step() function") {
  {
    AnimatedAny n{ AnimatedAny<int>::Builder{ 0 }.setDuration(250u).build() };
    n.set(100);
    n.step(0u);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 0);
    REQUIRE(n.getEnd() == 100);
    n.step(30u);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 12);
    REQUIRE(n.getEnd() == 100);
    n.step(40u);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 28);
    REQUIRE(n.getEnd() == 100);
    n.step(50u);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 48);
    REQUIRE(n.getEnd() == 100);
    n.step(60u);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 72);
    REQUIRE(n.getEnd() == 100);
    n.step(70u);
    REQUIRE(n.getStart() == 0);
    REQUIRE(n.get() == 100);
    REQUIRE(n.getEnd() == 100);
  }
  {
    AnimatedAny n{ AnimatedAny<unsigned int>::Builder{ 10 }.setDuration(250u).build() };
    n.set(110);
    n.step(0u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 10);
    REQUIRE(n.getEnd() == 110);
    n.step(30u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 22);
    REQUIRE(n.getEnd() == 110);
    n.step(40u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 38);
    REQUIRE(n.getEnd() == 110);
    n.step(50u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 58);
    REQUIRE(n.getEnd() == 110);
    n.step(60u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 82);
    REQUIRE(n.getEnd() == 110);
    n.step(70u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 110);
    REQUIRE(n.getEnd() == 110);
  }
  {
    AnimatedAny n{ AnimatedAny<unsigned int>::Builder{ 10 }.setDuration(500u).build() };
    n.set(110);
    n.step(0u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 10);
    REQUIRE(n.getEnd() == 110);
    n.step(60u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 22);
    REQUIRE(n.getEnd() == 110);
    n.step(80u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 38);
    REQUIRE(n.getEnd() == 110);
    n.step(100u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 58);
    REQUIRE(n.getEnd() == 110);
    n.step(120u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 82);
    REQUIRE(n.getEnd() == 110);
    n.step(140u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 110);
    REQUIRE(n.getEnd() == 110);
  }
  {
    auto m{ 0u };
    AnimatedAny n{ AnimatedAny<unsigned int>::Builder{ 10, [&m]() {
      ++m;
    } }.setDuration(500u).build() };
    n.set(110);
    n.step(0u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 10);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 0u);
    n.step(60u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 22);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 0u);
    n.step(80u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 38);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 0u);
    n.step(100u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 58);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 0u);
    n.step(120u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 82);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 0u);
    n.step(140u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 110);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 1u);
    n.step(10u);
    REQUIRE(n.getStart() == 10);
    REQUIRE(n.get() == 110);
    REQUIRE(n.getEnd() == 110);
    REQUIRE(m == 1u);
  }
}

}  // namespace ii887522::nitro

#endif
