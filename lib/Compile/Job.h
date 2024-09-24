/*
 * Copyright (c) 2020, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>

namespace llvm {
template <typename T>
class ArrayRef;

namespace opt {
class InputArgList;
}  // namespace opt
}  // namespace llvm
namespace pasta {

class CompileJobImpl : public std::enable_shared_from_this<CompileJobImpl> {
 public:
  inline CompileJobImpl(ArgumentVector argv_, FileManager file_manager_,
                        std::filesystem::path working_dir_,
                        std::filesystem::path resource_dir_,
                        std::filesystem::path sysroot_dir_,
                        std::filesystem::path isysroot_dir_,
                        File source_file_,
                        std::string target_triple_,
                        std::string aux_triple_)
      : argv(std::move(argv_)),
        file_manager(std::move(file_manager_)),
        working_dir(std::move(working_dir_)),
        resource_dir(std::move(resource_dir_)),
        sysroot_dir(std::move(sysroot_dir_)),
        isysroot_dir(std::move(isysroot_dir_)),
        source_file(std::move(source_file_)),
        target_triple(std::move(target_triple_)),
        aux_triple(std::move(aux_triple_)) {}

  static llvm::opt::InputArgList ParseDriverArguments(
      const llvm::ArrayRef<const char *> &args, bool enable_cl,
      unsigned &missing_arg_index, unsigned &missing_arg_count);

  // Arguments of the frontend compile command.
  const ArgumentVector argv;

  // File manager associated with this job.
  const FileManager file_manager;

  // Directory in which this command should execute.
  const std::filesystem::path working_dir;

  // Resource directory. May be different than what's configured for the
  // compiler.
  const std::filesystem::path resource_dir;

  // System root directory. May be different than what's configured for the
  // compiler.
  const std::filesystem::path sysroot_dir;

  // System root directory for includes. May be different than what's configured
  // for the compiler.
  const std::filesystem::path isysroot_dir;

  // Source file that this job will compile.
  const File source_file;

  // Target triple.
  const std::string target_triple;

  // Auxiliary target triple (for CUDA).
  const std::string aux_triple;
};

}  // namespace pasta
