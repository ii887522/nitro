// Copyright ii887522

#include "string_ext.h"  // NOLINT(build/include_subdir)
#include <string>

using std::string;

namespace ii887522::nitro {

size_t getLastPathDelimiterI(const string& filePath) {
  auto result{ filePath.rfind('/') };
  return result == string::npos ? filePath.rfind('\\') : result;
}

string getFileName(const string& filePath) {
  const auto lastPathDelimiterI{ getLastPathDelimiterI(filePath) };
  return filePath.substr(lastPathDelimiterI + 1u, filePath.rfind('.') - lastPathDelimiterI - 1u);
}

void toUpperCase(string*const str) {
  for (auto& ch : *str) ch = toUpperCase(ch);
}

void toLowerCase(string*const str) {
  for (auto& ch : *str) ch = toLowerCase(ch);
}

}  // namespace ii887522::nitro
