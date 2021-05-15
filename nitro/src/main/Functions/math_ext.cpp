// Copyright ii887522

#include "math_ext.h"  // NOLINT(build/include_subdir)
#include <string>

using std::string;

namespace ii887522::nitro {

bool isUint(const string& str) {
  for (const auto ch : str) {
    if (!isDigit(ch)) return false;
  }
  return true;
}

unsigned int parseUint(const string& uintStr) {
  auto result{ 0u };
  auto placeValue{ 1u };
  constexpr auto radix{ 10u };
  for (auto i{ static_cast<int>(uintStr.length() - 1u) }; i >= 0; --i) {
    result += parseUint(uintStr[i]) * placeValue;
    placeValue *= radix;
  }
  return result;
}

}  // namespace ii887522::nitro
