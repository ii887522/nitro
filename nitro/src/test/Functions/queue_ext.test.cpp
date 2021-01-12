// Copyright ii887522

#ifdef TEST

#include "../Functions/queue_ext.test.h"
#include <queue>
#include <cassert>
#include "../../main/Functions/queue_ext.h"

using std::queue;

namespace ii887522::nitro {

static void testClear() {
  queue<unsigned int> queue;
  clear(&queue);
  assert(queue.empty());
  assert(queue.size() == 0u);
  queue.push(1u);
  clear(&queue);
  assert(queue.empty());
  assert(queue.size() == 0u);
  queue.push(2u);
  queue.push(3u);
  clear(&queue);
  assert(queue.empty());
  assert(queue.size() == 0u);
  queue.push(4u);
  queue.push(5u);
  queue.push(6u);
  clear(&queue);
  assert(queue.empty());
  assert(queue.size() == 0u);
}

void testQueueExt() {
  testClear();
}

}  // namespace ii887522::nitro

#endif
