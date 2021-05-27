// Copyright ii887522

#ifndef NITRO_SRC_MAIN_ANY_ANIMATEDANY_H_
#define NITRO_SRC_MAIN_ANY_ANIMATEDANY_H_

#include <stdexcept>
#include <typeinfo>
#include <string>
#include <functional>
#include "../Functions/math_ext.h"
#include "../Struct/Range.h"
#include "Reactive.h"

using std::runtime_error;
using std::string;
using std::function;

namespace ii887522::nitro {

/// <param name="T">It must not be equal to unsigned integer type</param>
template <typename T> struct AnimatedAny final {

  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    const T value;

    /// <summary>Animation duration</summary>
    unsigned int duration;

    /// <summary>Has set animation duration </summary>
    bool hasSetDuration;

    const function<void()> onAnimationEnd;

   public:
    explicit constexpr Builder(const T& value, const function<void()>& onAnimationEnd = []() { }) : value{ value }, duration{ 0u },
      hasSetDuration{ false }, onAnimationEnd{ onAnimationEnd } { }

    /// <summary>
    ///   <para>Animation duration.</para>
    ///   <para>It must be called at least 1 time before building AnimatedAny&lt;T&gt; object.</para>
    /// </summary>
    /// <param name="p_value">It must not be assigned to 0</param>
    constexpr Builder& setDuration(const unsigned int p_value) {
      duration = p_value;
      hasSetDuration = true;
      return *this;
    }

    /// <summary>It must be called to build AnimatedAny&lt;T&gt; object</summary>
    AnimatedAny<T> build() {
      if (hasSetDuration) return AnimatedAny{ *this };
      throw runtime_error{ string { "AnimatedAny<" } + typeid(T).name() + "> duration is required!" };
    }

    friend struct AnimatedAny;
  };

 private:
  T start;
  T now;
  T end;

  /// <summary>Animation duration</summary>
  const unsigned int duration;

  unsigned int elaspedTime;
  const function<void()> onAnimationEnd;

  explicit constexpr AnimatedAny(const Builder& builder) : start{ builder.value }, now{ builder.value }, end{ builder.value },
    duration{ builder.duration }, elaspedTime{ 0u }, onAnimationEnd{ builder.onAnimationEnd } { }

 public:
  constexpr const T& getStart() const {
    return start;
  }

  constexpr const T& get() const {
    return now;
  }

  constexpr const T& getEnd() const {
    return end;
  }

  constexpr void set(const T& value) {
    start = now;
    end = value;
    elaspedTime = 0u;
  }

  constexpr void teleport(const T& value) {
    start = now;
    now = value;
    end = value;
    elaspedTime = duration;
  }

  constexpr void step(const unsigned int dt) {
    if (elaspedTime == duration) return;
    elaspedTime += dt;
    clamp(&elaspedTime, Range{ 0u, duration });
    now = static_cast<T>(start + (end - start) * (static_cast<float>(elaspedTime) / duration));
    if (elaspedTime == duration) onAnimationEnd();
  }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_ANY_ANIMATEDANY_H_
