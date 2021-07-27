/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/Compiler.h>

#include <string>
#include <string_view>
#include <vector>

namespace pasta {

using IncludePath = std::pair<std::filesystem::path, IncludePathLocation>;

class CompilerImpl {
 public:
  inline CompilerImpl(FileManager file_manager_,
                      std::filesystem::path compiler_exe_,
                      CompilerName compiler_name_, TargetLanguage target_lang_)
      : compiler_name(compiler_name_),
        target_lang(target_lang_),
        file_manager(std::move(file_manager_)),
        compiler_exe(std::move(compiler_exe_)),
        fs(file_manager.FileSystem()) {}

  ~CompilerImpl(void) {}

  const CompilerName compiler_name;
  const TargetLanguage target_lang;
  const FileManager file_manager;
  const std::filesystem::path compiler_exe;

  FileSystemView fs;

  // Include paths.
  std::vector<IncludePath> user_includes;
  std::vector<IncludePath> system_includes;
  std::vector<IncludePath> frameworks;

  std::filesystem::path sysroot_dir;  // Optional.
  std::filesystem::path resource_dir;
  std::filesystem::path install_dir;
};

}  // namespace pasta
