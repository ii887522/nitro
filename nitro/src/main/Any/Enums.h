// Copyright ii887522

#ifndef NITRO_SRC_MAIN_ANY_ENUMS_H_
#define NITRO_SRC_MAIN_ANY_ENUMS_H_

namespace ii887522::nitro {

enum Action : unsigned int {
  NONE = 0u, QUIT = 1u, CONSUME_EVENT = 2u, RETURN_FROM_CALLER = 4u, START_ANIMATION = 8u, STOP_ANIMATION = 16u
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_ANY_ENUMS_H_
