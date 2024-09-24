/*
 * Copyright (c) 2020, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <pasta/Compile/Compiler.h>

#include <string>
#include <string_view>
#include <vector>

namespace pasta {

class CompilerImpl {
 public:
  inline CompilerImpl(FileManager file_manager_,
                      std::filesystem::path compiler_exe_,
                      CompilerName compiler_name_, TargetLanguage target_lang_,
                      std::string triple_)
      : compiler_name(compiler_name_),
        target_lang(target_lang_),
        file_manager(std::move(file_manager_)),
        compiler_exe(std::move(compiler_exe_)),
        fs(file_manager.FileSystem()),
        triple(std::move(triple_)) {}

  ~CompilerImpl(void) {}

  const CompilerName compiler_name;
  const TargetLanguage target_lang;
  const FileManager file_manager;
  std::filesystem::path compiler_exe;

  FileSystemView fs;

  // Include paths.
  std::vector<IncludePath> user_includes;
  std::vector<IncludePath> system_includes;
  std::vector<IncludePath> frameworks;

  std::string triple;
  std::filesystem::path sysroot_dir;  // Optional.
  std::filesystem::path isysroot_dir;  // Optional.
  std::filesystem::path resource_dir;
  std::filesystem::path install_dir;
};

}  // namespace pasta
