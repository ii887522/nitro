// Copyright ii887522

#ifndef NITRO_SRC_MAIN_REACTIVE_UNARYREACTIVE_H_
#define NITRO_SRC_MAIN_REACTIVE_UNARYREACTIVE_H_

#include <vector>
#include <functional>
#include "../Any/Reactive.h"

using std::vector;
using std::function;

namespace ii887522::nitro {

// Not Thread Safe
template <typename R, typename T> class UnaryReactive final : public Reactive<T> {
  // remove copy semantics
  UnaryReactive(const UnaryReactive&) = delete;
  UnaryReactive& operator=(const UnaryReactive&) = delete;

  // remove move semantics
  UnaryReactive(UnaryReactive&&) = delete;
  UnaryReactive& operator=(UnaryReactive&&) = delete;

  vector<Reactive<T>*> children;
  vector<function<R(const T*const)>> functions;

 public:
  explicit constexpr UnaryReactive(const T& value) : Reactive<T>{ value } { }

  explicit constexpr UnaryReactive(UnaryReactive<R, T>*const parent, const function<R(const T*const)>& function) :
    Reactive<T>{ function(parent ? &parent->get() : nullptr) } {
    if (!parent) return;
    parent->children.push_back(this);
    parent->functions.push_back(function);
  }

  void set(const T& value, const int ignoredHandlerI = -1) override {
    Reactive<T>::set(value, ignoredHandlerI);
    for (auto i{ 0u }; i != children.size(); ++i) children[i]->set(functions[i](&this->get()));
  }
};

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_REACTIVE_UNARYREACTIVE_H_
