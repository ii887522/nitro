// Copyright ii887522

#include "fs_ext.h"  // NOLINT(build/include_subdir)
#include <string>
#include <filesystem>

using std::string;
using std::filesystem::remove_all;
using std::filesystem::create_directory;

namespace ii887522::nitro {

void emptyDir(const string& path) {
  remove_all(path);
  create_directory(path);
}

}  // namespace ii887522::nitro
