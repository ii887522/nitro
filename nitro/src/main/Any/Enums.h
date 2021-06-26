// Copyright ii887522

#ifndef NITRO_SRC_MAIN_ANY_ENUMS_H_
#define NITRO_SRC_MAIN_ANY_ENUMS_H_

namespace ii887522::nitro {

enum class Action : unsigned int {
  NONE, QUIT, WINDOW_MINIMIZED, WINDOW_RESTORED, CONSUME_EVENT, RETURN_FROM_CALLER, START_ANIMATION, STOP_ANIMATION
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_ANY_ENUMS_H_
