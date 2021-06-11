// Copyright ii887522

#ifdef TEST

#include <cmath>
#include <catch.hpp>
#include "../../main/Reactive/BinaryReactive.h"

namespace ii887522::nitro {

TEST_CASE("test BinaryReactive<R, T, U>::set() function") {
  {
    BinaryReactive<unsigned int, unsigned int, unsigned int> m{ 0u };
    m.set(1u);
    REQUIRE(m.get() == 1u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> n{ 1u };
    n.set(2u);
    REQUIRE(n.get() == 2u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> p{
      &m, &n, [](const unsigned int* const left, const unsigned int* const right) {
        return *left + *right;
      }
    };
    m.set(2u);
    REQUIRE(m.get() == 2u);
    REQUIRE(p.get() == 4u);
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(p.get() == 5u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> q{
      &m, &n, [](const unsigned int* const left, const unsigned int* const right) {
        return *left * *right;
      }
    };
    m.set(3u);
    REQUIRE(m.get() == 3u);
    REQUIRE(p.get() == 6u);
    REQUIRE(q.get() == 9u);
    n.set(4u);
    REQUIRE(n.get() == 4u);
    REQUIRE(p.get() == 7u);
    REQUIRE(q.get() == 12u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> r{
      &m, &n, [](const unsigned int* const left, const unsigned int* const right) {
        return static_cast<unsigned int>(pow(*left, *right));
      }
    };
    m.set(4u);
    REQUIRE(m.get() == 4u);
    REQUIRE(p.get() == 8u);
    REQUIRE(q.get() == 16u);
    REQUIRE(r.get() == 256u);
    n.set(5u);
    REQUIRE(n.get() == 5u);
    REQUIRE(p.get() == 9u);
    REQUIRE(q.get() == 20u);
    REQUIRE(r.get() == 625u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> s{
      &m, nullptr, [](const unsigned int* const left, const unsigned int* const) {
        return *left;
      }
    };
    m.set(5u);
    REQUIRE(m.get() == 5u);
    REQUIRE(p.get() == 10u);
    REQUIRE(q.get() == 25u);
    REQUIRE(r.get() == 3125u);
    REQUIRE(s.get() == 5u);
    n.set(6u);
    REQUIRE(n.get() == 6u);
    REQUIRE(p.get() == 11u);
    REQUIRE(q.get() == 30u);
    REQUIRE(r.get() == 7776u);
    REQUIRE(s.get() == 5u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> t{
      nullptr, &n, [](const unsigned int* const, const unsigned int* const) {
        return 0u;
      }
    };
    m.set(6u);
    REQUIRE(m.get() == 6u);
    REQUIRE(p.get() == 12u);
    REQUIRE(q.get() == 36u);
    REQUIRE(r.get() == 46656u);
    REQUIRE(s.get() == 6u);
    REQUIRE(t.get() == 0u);
    n.set(7u);
    REQUIRE(n.get() == 7u);
    REQUIRE(p.get() == 13u);
    REQUIRE(q.get() == 42u);
    REQUIRE(r.get() == 117649u);
    REQUIRE(s.get() == 6u);
    REQUIRE(t.get() == 0u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> u{
      nullptr, nullptr, [](const unsigned int* const, const unsigned int* const) {
        return 1u;
      }
    };
  }
  {
    BinaryReactive<unsigned int, unsigned int, unsigned int> m{ 2u };
    m.set(1u);
    REQUIRE(m.get() == 1u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> n{ 3u };
    n.set(2u);
    REQUIRE(n.get() == 2u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> p{
      &m, &n, [](const unsigned int* const left, const unsigned int* const right) {
        return *left + *right;
      }
    };
    m.set(2u);
    REQUIRE(m.get() == 2u);
    REQUIRE(p.get() == 4u);
    n.set(3u);
    REQUIRE(n.get() == 3u);
    REQUIRE(p.get() == 5u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> q{
      &m, &n, [](const unsigned int* const left, const unsigned int* const right) {
        return *left * *right;
      }
    };
    m.set(3u);
    REQUIRE(m.get() == 3u);
    REQUIRE(p.get() == 6u);
    REQUIRE(q.get() == 9u);
    n.set(4u);
    REQUIRE(n.get() == 4u);
    REQUIRE(p.get() == 7u);
    REQUIRE(q.get() == 12u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> r{
      &m, &n, [](const unsigned int* const left, const unsigned int* const right) {
        return static_cast<unsigned int>(pow(*left, *right));
      }
    };
    m.set(4u);
    REQUIRE(m.get() == 4u);
    REQUIRE(p.get() == 8u);
    REQUIRE(q.get() == 16u);
    REQUIRE(r.get() == 256u);
    n.set(5u);
    REQUIRE(n.get() == 5u);
    REQUIRE(p.get() == 9u);
    REQUIRE(q.get() == 20u);
    REQUIRE(r.get() == 625u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> s{
      &m, nullptr, [](const unsigned int* const left, const unsigned int* const) {
        return *left;
      }
    };
    m.set(5u);
    REQUIRE(m.get() == 5u);
    REQUIRE(p.get() == 10u);
    REQUIRE(q.get() == 25u);
    REQUIRE(r.get() == 3125u);
    REQUIRE(s.get() == 5u);
    n.set(6u);
    REQUIRE(n.get() == 6u);
    REQUIRE(p.get() == 11u);
    REQUIRE(q.get() == 30u);
    REQUIRE(r.get() == 7776u);
    REQUIRE(s.get() == 5u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> t{
      nullptr, &n, [](const unsigned int* const, const unsigned int* const) {
        return 0u;
      }
    };
    m.set(6u);
    REQUIRE(m.get() == 6u);
    REQUIRE(p.get() == 12u);
    REQUIRE(q.get() == 36u);
    REQUIRE(r.get() == 46656u);
    REQUIRE(s.get() == 6u);
    REQUIRE(t.get() == 0u);
    n.set(7u);
    REQUIRE(n.get() == 7u);
    REQUIRE(p.get() == 13u);
    REQUIRE(q.get() == 42u);
    REQUIRE(r.get() == 117649u);
    REQUIRE(s.get() == 6u);
    REQUIRE(t.get() == 0u);
    BinaryReactive<unsigned int, unsigned int, unsigned int> u{
      nullptr, nullptr, [](const unsigned int* const, const unsigned int* const) {
        return 1u;
      }
    };
  }
}

}  // namespace ii887522::nitro

#endif
