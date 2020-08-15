/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/Compiler.h>

#include <string>
#include <string_view>
#include <vector>

namespace pasta {

class CompilerImpl {
 public:
  inline CompilerImpl(CompilerName compiler_name_, TargetLanguage target_lang_,
                      std::string_view compiler_exe_)
      : compiler_name(compiler_name_),
        target_lang(target_lang_),
        compiler_exe(compiler_exe_) {}

  ~CompilerImpl(void) {}

  const CompilerName compiler_name;
  const TargetLanguage target_lang;
  const std::string compiler_exe;

  // Include paths.
  std::vector<std::string> user_includes;
  std::vector<std::string> system_includes;
  std::vector<std::string> frameworks;

  std::string sysroot_dir;  // Optional.
  std::string resource_dir;
  std::string install_dir;
};

}  // namespace pasta
