/*
 * Copyright (c) 2022, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include "Compiler.h"
#include "Diagnostic.h"
#include "Job.h"

#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <iostream>
#include <unordered_set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#pragma GCC diagnostic pop

#include "../AST/AST.h"
#include "../AST/Token.h"
#include "../Util/FileManager.h"

namespace pasta {

// Tracks open files.
class ParsedFileTracker : public clang::PPCallbacks {
 private:
  clang::SourceManager &sm;
  const clang::LangOptions &lang_opts;
  const pasta::FileManager fm;
  std::shared_ptr<pasta::FileSystem> fs;
  const std::filesystem::path cwd;

  ASTImpl * const ast;
 public:

  explicit ParsedFileTracker(clang::SourceManager &sm_,
                             const clang::LangOptions &lang_opts_,
                             const pasta::FileManager &fm_,
                             std::filesystem::path cwd_,
                             ASTImpl *ast_)
      : sm(sm_),
        lang_opts(lang_opts_),
        fm(fm_),
        fs(fm.FileSystem()),
        cwd(std::move(cwd_)),
        ast(ast_) {}

  virtual ~ParsedFileTracker(void);

  void Clear(void);

  void AddEOF(File &file, clang::FileID file_id, clang::SourceManager &sm);

  // Each time we enter a source file, try to keep track of it.
  void FileChanged(clang::SourceLocation loc,
                   clang::PPCallbacks::FileChangeReason reason,
                   clang::SrcMgr::CharacteristicKind file_type,
                   clang::FileID file_id = clang::FileID()) final;
};

}  // namespace pasta
