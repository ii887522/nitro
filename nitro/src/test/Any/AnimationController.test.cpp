// Copyright ii887522

#ifdef TEST

#include <catch.hpp>
#include "../../main/Any/AnimationController.h"
#include "../../main/Any/Enums.h"
#include "../../main/Any/Reactive.h"

namespace ii887522::nitro {

TEST_CASE("test AnimationController::nextAction() function") {
  AnimationController controller;
  REQUIRE(controller.nextAction() == Action::NONE);
  Reactive<bool> is1Animating{ false };
  controller.subscribe(&is1Animating);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(false);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(true);
  REQUIRE(controller.nextAction() == Action::START_ANIMATION);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(true);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(false);
  REQUIRE(controller.nextAction() == Action::STOP_ANIMATION);
  REQUIRE(controller.nextAction() == Action::NONE);
  Reactive<bool> is2Animating{ false };
  controller.subscribe(&is2Animating);
  REQUIRE(controller.nextAction() == Action::NONE);
  is2Animating.set(true);
  REQUIRE(controller.nextAction() == Action::START_ANIMATION);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(true);
  REQUIRE(controller.nextAction() == Action::NONE);
  is2Animating.set(false);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(false);
  REQUIRE(controller.nextAction() == Action::STOP_ANIMATION);
  REQUIRE(controller.nextAction() == Action::NONE);
  Reactive<bool> is3Animating{ false };
  controller.subscribe(&is3Animating);
  REQUIRE(controller.nextAction() == Action::NONE);
  is3Animating.set(true);
  REQUIRE(controller.nextAction() == Action::START_ANIMATION);
  REQUIRE(controller.nextAction() == Action::NONE);
  is2Animating.set(true);
  REQUIRE(controller.nextAction() == Action::NONE);
  is3Animating.set(false);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(true);
  REQUIRE(controller.nextAction() == Action::NONE);
  is3Animating.set(true);
  REQUIRE(controller.nextAction() == Action::NONE);
  is2Animating.set(false);
  REQUIRE(controller.nextAction() == Action::NONE);
  is3Animating.set(false);
  REQUIRE(controller.nextAction() == Action::NONE);
  is1Animating.set(false);
  REQUIRE(controller.nextAction() == Action::STOP_ANIMATION);
  REQUIRE(controller.nextAction() == Action::NONE);
}

}  // namespace ii887522::nitro

#endif
