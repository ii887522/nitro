// Copyright ii887522

#include "fs_ext.h"  // NOLINT(build/include_subdir)
#include <string>
#include <filesystem>

using std::string;
using std::filesystem::remove_all;
using std::filesystem::create_directory;
using std::filesystem::directory_iterator;

namespace ii887522::nitro {

void emptyDir(const string& path) {
  remove_all(path);
  create_directory(path);
}

bool hasFileWithExtension(const string& dirPath, const string& extensionName) {
  for (const auto& entry : directory_iterator{ dirPath }) {
    if (entry.path().string().ends_with(extensionName)) return true;
  }
  return false;
}

}  // namespace ii887522::nitro
