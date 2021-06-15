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

  vector<Reactive<R>*> children;
  vector<function<R(const T*const, const U*const)>> functions;
  vector<Reactive<U>*> thats;

 public:
  explicit constexpr BinaryReactive(const T& value) : Reactive<T>{ value } { }

  /// <param name="leftParent">It must not be assigned to integer</param>
  /// <param name="rightParent">It must not be assigned to integer</param>
  template <typename V, typename W> constexpr static BinaryReactive<R, T, U>* make(BinaryReactive<T, V, W>*const leftParent, BinaryReactive<T, W, V>*const rightParent,
    const function<T(const V*const, const W*const)>& function) {
    const auto result{ new BinaryReactive{ function(leftParent ? &leftParent->get() : nullptr, rightParent ? &rightParent->get() : nullptr) } };
    if (leftParent) {
      leftParent->children.push_back(result);
      leftParent->functions.push_back(function);
      leftParent->thats.push_back(rightParent);
    }
    if (rightParent) {
      rightParent->children.push_back(result);
      rightParent->functions.push_back([function](const W*const right, const V*const left) {
        return function(left, right);
      });
      rightParent->thats.push_back(leftParent);
    }
    return result;
  }

  /// <param name="ignoredHandlerI">-1 means no handlers are ignored</param>
  void set(const T& value, const int ignoredHandlerI = -1) override {
    Reactive<T>::set(value, ignoredHandlerI);
    for (auto i{ 0u }; i != children.size(); ++i) children[i]->set(functions[i](&this->get(), thats[i] ? &thats[i]->get() : nullptr));
  }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_REACTIVE_BINARYREACTIVE_H_
