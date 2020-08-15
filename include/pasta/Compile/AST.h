/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Util/Error.h>

#include <memory>
#include <string_view>

namespace pasta {

class ASTImpl;
class CompileJob;
class Compiler;

// Abstraction around a Clang AST and the various data structures that need to
// be retained in order to use it.
class AST {
 public:
  ~AST(void);

  // Load a serialized AST from a file.
  static llvm::Expected<AST> LoadFromFile(std::string_view path);

 private:
  friend class Compiler;
  friend class CompileJob;

  AST(std::shared_ptr<ASTImpl> impl_);

  std::shared_ptr<ASTImpl> impl;
};

}  // namespace pasta
