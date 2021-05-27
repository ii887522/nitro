// Copyright ii887522

#ifndef NITRO_SRC_MAIN_REACTIVE_BINARYREACTIVE_H_
#define NITRO_SRC_MAIN_REACTIVE_BINARYREACTIVE_H_

#include <vector>
#include <functional>
#include "../Any/Reactive.h"

using std::vector;
using std::function;

namespace ii887522::nitro {

/// <summary>Not Thread Safe</summary>
template <typename R, typename T, typename U> class BinaryReactive final : public Reactive<T> {
  // remove copy semantics
  BinaryReactive(const BinaryReactive&) = delete;
  BinaryReactive& operator=(const BinaryReactive&) = delete;

  // remove move semantics
  BinaryReactive(BinaryReactive&&) = delete;
  BinaryReactive& operator=(BinaryReactive&&) = delete;

  vector<Reactive<T>*> children;
  vector<function<R(const T*const, const U*const)>> functions;
  vector<Reactive<T>*> thats;

 public:
  explicit constexpr BinaryReactive(const T& value) : Reactive<T>{ value } { }

  /// <param name="function">It must be commutative</param>
  explicit constexpr BinaryReactive(BinaryReactive<R, T, U>*const leftParent, BinaryReactive<R, T, U>*const rightParent,
    const function<R(const T*const, const U*const)>& function) :
    Reactive<T>{ function(leftParent ? &leftParent->get() : nullptr, rightParent ? &rightParent->get() : nullptr) } {
    if (leftParent) {
      leftParent->children.push_back(this);
      leftParent->functions.push_back(function);
      leftParent->thats.push_back(rightParent);
    }
    if (rightParent) {
      rightParent->children.push_back(this);
      rightParent->functions.push_back(function);
      rightParent->thats.push_back(leftParent);
    }
  }

  void set(const T& value, const int ignoredHandlerI = -1) override {
    Reactive<T>::set(value, ignoredHandlerI);
    for (auto i{ 0u }; i != children.size(); ++i) children[i]->set(functions[i](&this->get(), thats[i] ? &thats[i]->get() : nullptr));
  }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_REACTIVE_BINARYREACTIVE_H_
