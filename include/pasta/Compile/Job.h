/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Error.h>

#include <string_view>

namespace pasta {

class AST;
class ArgumentVector;
class CompileCommand;
class CompileJobImpl;

// A single backend compilation job. There is a one to many relationship
// between `CompileCommand`s and `CompilerJob`s, as a single compile command
// may actually reference multiple source files, whereas a compilation job
// references only one.
class CompileJob {
 public:
  ~CompileJob(void);
  CompileJob(CompileJob &&) noexcept;

  // Return an argument vector associated with this compilation job.
  const ArgumentVector &Arguments(void) const;

  // Return the working directory in which this command executes.
  std::string_view WorkingDirectory(void) const;

  // Return the compiler resource directory that this command should use.
  std::string_view ResourceDirectory(void) const;

  // Return the compiler system root directory that this command should use.
  std::string_view SystemRootDirectory(void) const;

  // Return the target triple to use.
  std::string_view TargetTriple(void) const;

  // Return the auxiliary target triple to use.
  std::string_view AuxiliaryTargetTriple(void) const;

  // Return the path to the source file that this job compiles.
  std::string_view SourceFile(void) const;

  // Run a backend compilation job and returns the AST or the first error.
  llvm::Expected<AST> Run(void) const;

 private:
  friend class CompileCommand;

  CompileJob(void) = delete;
  CompileJob(const CompileJob &) = delete;
  CompileJob &operator=(const CompileJob &) = delete;
  CompileJob &operator=(CompileJob &&) noexcept = delete;

  CompileJob(CompileJobImpl *impl_);

  CompileJobImpl *impl;
};

}  // namespace pasta
