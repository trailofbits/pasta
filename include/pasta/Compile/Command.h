/*
 * Copyright (c) 2020, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <pasta/Util/Result.h>
#include <pasta/Util/StdFileSystem.h>

#include <memory>
#include <string_view>
#include <vector>

#include "Job.h"

namespace pasta {

class ArgumentVector;
class CompileCommandImpl;
class Compiler;

// A high-level compile command. This is a frontent compile command. It may
// include multiple files.
class CompileCommand {
 public:
  ~CompileCommand(void);

  CompileCommand(const CompileCommand &) = default;
  CompileCommand &operator=(const CompileCommand &) = default;
  CompileCommand(CompileCommand &&) noexcept = default;
  CompileCommand &operator=(CompileCommand &&) noexcept = default;

  // Create a compile command for a single file in a working directory.
  static Result<CompileCommand, std::string_view>
  CreateFromArguments(const ArgumentVector &argv,
                      std::filesystem::path working_dir);

  // Return an argument vector associated with this compilation command.
  const ArgumentVector &Arguments(void) const;

  // Return the working directory in which this command executes.
  std::filesystem::path WorkingDirectory(void) const;

 private:
  friend class CompileJob;
  friend class Compiler;

  CompileCommand(void) = delete;

  CompileCommand(std::shared_ptr<CompileCommandImpl> impl_);

  std::shared_ptr<CompileCommandImpl> impl;
};

}  // namespace pasta
