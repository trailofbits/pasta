/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#pragma once

#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"

#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/PPCallbacksEventKind.h>
#pragma GCC diagnostic pop

#if !defined(LLVM_CLANG_HAS_PASTA_EVENTS)
# error "PASTA requires patches to clang::PPCallbacks."
#endif

#include <pasta/Util/Compiler.h>

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

namespace clang {
class CompilerInstance;
class LangOptions;
class Preprocessor;
class SourceManager;
class Token;
}  // namespace clang
namespace pasta {

class ASTImpl;

// Tracks macros using patched-in events to Clang.
class SplitTokenTracker : public clang::PPCallbacks {
 private:
  clang::Preprocessor &pp;
  clang::SourceManager &sm;
  clang::CompilerInstance &ci;
  clang::LangOptions &lo;
  clang::Token skipped_hash;

  ASTImpl * const ast;

 public:
  virtual ~SplitTokenTracker(void) = default;

  explicit SplitTokenTracker(clang::Preprocessor &pp_,
                             clang::SourceManager &sm_,
                             ASTImpl *ast_);

 public:
  void Event(const clang::Token &tok, EventKind kind, uintptr_t) final;
};

}  // namespace pasta
