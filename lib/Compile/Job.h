/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

namespace pasta {

class CompileJobImpl {
 public:
  inline CompileJobImpl(ArgumentVector argv_, std::string working_dir_,
                        std::string source_file_)
      : argv(std::move(argv_)),
        working_dir(std::move(working_dir_)),
        source_file(std::move(source_file_)) {}

  // Arguments of the frontend compile command.
  const ArgumentVector argv;

  // Directory in which this command should execute.
  const std::string working_dir;

  // Source file that this job will compile.
  const std::string source_file;
};

}  // namespace pasta
