// Copyright ii887522

#ifdef TEST

#include "Reactive.test.h"
#include <cassert>
#include "../../main/Any/Reactive.h"

namespace ii887522::nitro {

static void testSet() {
  {
    Reactive n{ 0u };
    n.set(1u);
    assert(n.get() == 1u);
    auto count{ 0u };
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(2u);
    assert(n.get() == 2u);
    assert(count == 2u);
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(3u);
    assert(n.get() == 3u);
    assert(count == 8u);
    n.watch([&n, &count](const unsigned int& value, const int handlerI) {
      count += value;
      n.set(count, handlerI);
    });
    n.set(4u);
    assert(n.get() == 20u);
    assert(count == 60u);
  }
  {
    Reactive n{ 2u };
    n.set(1u);
    assert(n.get() == 1u);
    auto count{ 0u };
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(2u);
    assert(n.get() == 2u);
    assert(count == 2u);
    n.watch([&count](const unsigned int& value, const int) {
      count += value;
    });
    n.set(3u);
    assert(n.get() == 3u);
    assert(count == 8u);
    n.watch([&n, &count](const unsigned int& value, const int handlerI) {
      count += value;
      n.set(count, handlerI);
    });
    n.set(4u);
    assert(n.get() == 20u);
    assert(count == 60u);
  }
}

void testReactive() {
  testSet();
}

}  // namespace ii887522::nitro

#endif
