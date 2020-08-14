/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Util/FileSystem.h>

namespace pasta {

// Make `path` absolute if it's not already.
std::filesystem::path AbsolutePath(std::filesystem::path path,
                                   std::filesystem::path working_dir) {
  if (!path.is_absolute()) {
    path = working_dir / path;
  }
  return path;
}

std::filesystem::path CanonicalPath(std::filesystem::path path) {
  std::error_code ec;
  std::filesystem::canonical(path, ec);
  return path;
}

// Returns `true` if the directory pointed to by `path` looks like a resource
// directory.
bool IsResourceDir(std::filesystem::path path) {
  return std::filesystem::is_regular_file(path / "include" / "stdarg.h");
}

}  // namespace pasta
