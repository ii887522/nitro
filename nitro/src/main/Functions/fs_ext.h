// Copyright ii887522

#ifndef NITRO_SRC_MAIN_FUNCTIONS_FS_EXT_H_
#define NITRO_SRC_MAIN_FUNCTIONS_FS_EXT_H_

#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

namespace ii887522::nitro {

// Param filePath: it must exist
template <typename T, template <typename> typename U> U<T> read(const string& filePath) {
  ifstream file{ filePath, ios::binary | ios::ate };
  file.exceptions(file.failbit);
  U<T> fileContent(static_cast<unsigned int>(file.tellg()) / sizeof T);
  file.seekg(0u);
  file.read(reinterpret_cast<char*>(fileContent.data()), fileContent.size() * sizeof T);
  file.close();
  return fileContent;
}

template <typename T, template <typename> typename U> void write(const string& filePath, const U<T>& objects) {
  ofstream file{ filePath, ios::binary };
  file.write(reinterpret_cast<const char*>(objects.data()), objects.size() * sizeof T);
  file.close();
}

}  // namespace ii887522::nitro

#endif  // NITRO_SRC_MAIN_FUNCTIONS_FS_EXT_H_
