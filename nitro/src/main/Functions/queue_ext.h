// Copyright ii887522

#ifndef NITRO_SRC_MAIN_FUNCTIONS_QUEUE_EXT_H_
#define NITRO_SRC_MAIN_FUNCTIONS_QUEUE_EXT_H_

#include <queue>

using std::queue;

namespace ii887522::nitro {

// Param queue: it must not be assigned to nullptr and integer
template <typename T> void clear(queue<T>*const queue) {
  while (!queue->empty()) queue->pop();
}

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_FUNCTIONS_QUEUE_EXT_H_
