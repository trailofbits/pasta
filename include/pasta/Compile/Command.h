/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Result.h>

#include <memory>
#include <string_view>
#include <vector>

#include "Job.h"

namespace llvm {
namespace json {
class Array;
class Object;
}  // namespace json
}  // namespace llvm
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

  // Create a compile command from a JSON object. This JSON should come from
  // a proper compile_commands.json compilation database.
  static Result<CompileCommand, std::string_view>
  CreateOneFromJSON(const llvm::json::Object &obj);

  // Create zero or more compile commands from an array of JSON objects. This
  // JSON should come from a proper compile_commands.json compilation database.
  static std::vector<Result<CompileCommand, std::string_view>>
  CreateManyFromJSON(const llvm::json::Array &array);

  // Create a compile command for a single file in a working directory.
  static Result<CompileCommand, std::string_view>
  CreateFromArguments(const ArgumentVector &argv, std::string_view working_dir);

  // Return an argument vector associated with this compilation command.
  const ArgumentVector &Arguments(void) const;

  // Return the working directory in which this command executes.
  std::string_view WorkingDirectory(void) const;

 private:
  friend class CompileJob;
  friend class Compiler;

  CompileCommand(void) = delete;

  CompileCommand(std::shared_ptr<CompileCommandImpl> impl_);

  std::shared_ptr<CompileCommandImpl> impl;
};

}  // namespace pasta
