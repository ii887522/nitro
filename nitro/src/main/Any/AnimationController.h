// Copyright ii887522

#ifndef NITRO_SRC_MAIN_ANY_ANIMATIONCONTROLLER_H_
#define NITRO_SRC_MAIN_ANY_ANIMATIONCONTROLLER_H_

#include "Reactive.h"
#include "Enums.h"

namespace ii887522::nitro {

/// <summary>Not Thread Safe</summary>
class AnimationController final {
  // remove copy semantics
  AnimationController(const AnimationController&) = delete;
  AnimationController& operator=(const AnimationController&) = delete;

  // remove move semantics
  AnimationController(AnimationController&&) = delete;
  AnimationController& operator=(AnimationController&&) = delete;

  unsigned int animationCount;
  bool hasStartAnimation;

 public:
  explicit constexpr AnimationController() : animationCount{ 0u }, hasStartAnimation{ false } { }

  /// <param name="isAnimating">It must not be assigned to nullptr or integer</param>
  constexpr void subscribe(Reactive<bool>*const isAnimating) {
    isAnimating->watch([this](const bool& oldValue, const bool& newValue, const int) {
      if (!oldValue && newValue) ++animationCount;
      else if (oldValue && !newValue) --animationCount;
    });
  }

  constexpr Action nextAction() {
    if (animationCount != 0u && !hasStartAnimation) {
      hasStartAnimation = true;
      return Action::START_ANIMATION;
    } else if (animationCount == 0u && hasStartAnimation) {
      hasStartAnimation = false;
      return Action::STOP_ANIMATION;
    }
    return Action::NONE;
  }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_ANY_ANIMATIONCONTROLLER_H_
