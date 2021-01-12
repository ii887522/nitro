// Copyright ii887522

#ifdef TEST

#include "UnaryReactive.test.h"
#include <cassert>
#include <cmath>
#include "../../main/Reactive/UnaryReactive.h"

namespace ii887522::nitro {

static void testSet() {
  {
    UnaryReactive<unsigned int, unsigned int> n{ 0u };
    n.set(1u);
    assert(n.get() == 1u);
    UnaryReactive<unsigned int, unsigned int> nx{ &n, [](const unsigned int*const value) {
      return *value + *value;
    } };
    n.set(2u);
    assert(n.get() == 2u);
    assert(nx.get() == 4u);
    UnaryReactive<unsigned int, unsigned int> ny{ &n, [](const unsigned int*const value) {
      return *value * *value;
    } };
    n.set(3u);
    assert(n.get() == 3u);
    assert(nx.get() == 6u);
    assert(ny.get() == 9u);
    UnaryReactive<unsigned int, unsigned int> nz{ &n, [](const unsigned int*const value) {
      return static_cast<unsigned int>(sqrt(*value));
    } };
    n.set(4u);
    assert(n.get() == 4u);
    assert(nx.get() == 8u);
    assert(ny.get() == 16u);
    assert(nz.get() == 2u);
    UnaryReactive<unsigned int, unsigned int> nw{ nullptr, [](const unsigned int*const) {
      return 0u;
    } };
  }
  {
    UnaryReactive<unsigned int, unsigned int> n{ 2u };
    n.set(1u);
    assert(n.get() == 1u);
    UnaryReactive<unsigned int, unsigned int> nx{ &n, [](const unsigned int*const value) {
      return *value + *value;
    } };
    n.set(2u);
    assert(n.get() == 2u);
    assert(nx.get() == 4u);
    UnaryReactive<unsigned int, unsigned int> ny{ &n, [](const unsigned int*const value) {
      return *value * *value;
    } };
    n.set(3u);
    assert(n.get() == 3u);
    assert(nx.get() == 6u);
    assert(ny.get() == 9u);
    UnaryReactive<unsigned int, unsigned int> nz{ &n, [](const unsigned int*const value) {
      return static_cast<unsigned int>(sqrt(*value));
    } };
    n.set(4u);
    assert(n.get() == 4u);
    assert(nx.get() == 8u);
    assert(ny.get() == 16u);
    assert(nz.get() == 2u);
    UnaryReactive<unsigned int, unsigned int> nw{ nullptr, [](const unsigned int*const) {
      return 0u;
    } };
  }
}

void testUnaryReactive() {
  testSet();
}

}  // namespace ii887522::nitro

#endif
