// Copyright ii887522

#ifndef NITRO_SRC_MAIN_FUNCTIONS_STRING_EXT_H_
#define NITRO_SRC_MAIN_FUNCTIONS_STRING_EXT_H_

#include <string>

using std::string;

namespace ii887522::nitro {

size_t getLastPathDelimiterI(const string& filePath);
string getFileName(const string& filePath);

constexpr char toUpperCase(const char ch) {
  return ch >= 'a' && ch <= 'z' ? ch - 32u : ch;
}

constexpr char toLowerCase(const char ch) {
  return ch >= 'A' && ch <= 'Z' ? ch + 32u : ch;
}

/// <param name="str">It must not be assigned to nullptr or integer</param>
void toUpperCase(string*const str);

/// <param name="str">It must not be assigned to nullptr or integer</param>
void toLowerCase(string*const str);

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_FUNCTIONS_STRING_EXT_H_
