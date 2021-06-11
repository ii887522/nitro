// Copyright ii887522

#ifdef TEST

#include <queue>
#include <catch.hpp>
#include "../../main/Functions/queue_ext.h"

using std::queue;

namespace ii887522::nitro {

TEST_CASE("test clear() function") {
  queue<unsigned int> queue;
  clear(&queue);
  REQUIRE(queue.empty());
  REQUIRE(queue.size() == 0u);
  queue.push(1u);
  clear(&queue);
  REQUIRE(queue.empty());
  REQUIRE(queue.size() == 0u);
  queue.push(2u);
  queue.push(3u);
  clear(&queue);
  REQUIRE(queue.empty());
  REQUIRE(queue.size() == 0u);
  queue.push(4u);
  queue.push(5u);
  queue.push(6u);
  clear(&queue);
  REQUIRE(queue.empty());
  REQUIRE(queue.size() == 0u);
}

}  // namespace ii887522::nitro

#endif
