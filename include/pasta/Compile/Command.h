/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Error.h>

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
  CompileCommand(CompileCommand &&) noexcept = default;
  ~CompileCommand(void);

  // Create a compile command from a JSON object. This JSON should come from
  // a proper compile_commands.json compilation database.
  static llvm::Expected<CompileCommand>
  CreateOneFromJSON(const llvm::json::Object &obj);

  // Create zero or more compile commands from an array of JSON objects. This
  // JSON should come from a proper compile_commands.json compilation database.
  static std::vector<llvm::Expected<CompileCommand>>
  CreateManyFromJSON(const llvm::json::Array &array);

  // Create a compile command for a single file in a working directory.
  static llvm::Expected<CompileCommand>
  CreateOneForFile(const Compiler &compiler, std::string_view file_name,
                   std::string_view working_dir);

  // Create a compile command for a single file in a working directory.
  static llvm::Expected<CompileCommand>
  CreateFromArguments(const ArgumentVector &argv, std::string_view working_dir);

  // Return an argument vector associated with this compilation command.
  const ArgumentVector &Arguments(void) const;

  // Return the working directory in which this command executes.
  std::string_view WorkingDirectory(void) const;

  // The list of compiler jobs associated with this command.
  llvm::Expected<std::vector<CompileJob>> Jobs(const Compiler &compiler) const;

 private:
  friend class CompileJob;

  CompileCommand(const CompileCommand &) = delete;
  CompileCommand &operator=(CompileCommand &&) noexcept = delete;
  CompileCommand &operator=(const CompileCommand &) noexcept = delete;

  CompileCommand(CompileCommandImpl *impl_);

  std::unique_ptr<CompileCommandImpl> impl;
};

}  // namespace pasta
