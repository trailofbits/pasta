/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <filesystem>

namespace pasta {

// Make `path` absolute if it's not already.
std::filesystem::path AbsolutePath(
    std::filesystem::path path, std::filesystem::path working_dir);

// Canonicalize `path`, and ignore any errors.
std::filesystem::path CanonicalPath(std::filesystem::path path);

// Returns `true` if the directory pointed to by `path` looks like a resource
// directory.
bool IsResourceDir(std::filesystem::path path);

}  // namespace pasta
