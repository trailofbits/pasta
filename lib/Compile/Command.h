/*
 * Copyright (c) 2020, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <pasta/Compile/Command.h>
#include <pasta/Util/ArgumentVector.h>

namespace pasta {

class CompileCommandImpl
    : public std::enable_shared_from_this<CompileCommandImpl> {
 public:
  inline CompileCommandImpl(ArgumentVector argv_,
                            std::filesystem::path working_dir_)
      : argv(std::move(argv_)),
        working_dir(std::move(working_dir_)) {}

  // Arguments of the frontend compile command.
  const ArgumentVector argv;

  // Directory in which this command should execute.
  const std::filesystem::path working_dir;
};

}  // namespace pasta
