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
                        std::string resource_dir_, std::string sysroot_dir_,
                        std::string source_file_, std::string target_triple_,
                        std::string aux_triple_)
      : argv(std::move(argv_)),
        working_dir(std::move(working_dir_)),
        resource_dir(std::move(working_dir_)),
        sysroot_dir(std::move(working_dir_)),
        source_file(std::move(source_file_)),
        target_triple(std::move(target_triple_)),
        aux_triple(std::move(aux_triple_)) {}

  // Arguments of the frontend compile command.
  const ArgumentVector argv;

  // Directory in which this command should execute.
  const std::string working_dir;

  // Resource directory. May be different than what's configured for the
  // compiler.
  const std::string resource_dir;

  // System root directory. May be different than what's configured for the
  // compiler.
  const std::string sysroot_dir;

  // Source file that this job will compile.
  const std::string source_file;

  // Target triple.
  const std::string target_triple;

  // Auxiliary target triple (for CUDA).
  const std::string aux_triple;
};

}  // namespace pasta
