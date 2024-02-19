/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include "SplitTokenTracker.h"

#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/FileEntry.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/TokenKinds.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/PPCallbacksEventKind.h>
#pragma GCC diagnostic pop

namespace pasta {

SplitTokenTracker::SplitTokenTracker(clang::SourceManager &sm_,
                                     ASTImpl *ast_)
    : sm(sm_),
      ast(ast_) {}

void SplitTokenTracker::Event(
    const clang::Token &tok, EventKind kind, uintptr_t) {
  if (kind != EventKind::SplitToken) {
    return;
  }

  auto sloc = tok.getLocation();
  if (sloc.isMacroID()) {
    sloc = sm.getFileLoc(sloc);
    if (!sloc.isFileID()) {
      assert(false);
      return;
    }
  }

  auto [file_id, offset] = sm.getDecomposedLoc(sloc);
  if (file_id != sm.getMainFileID()) {
    assert(false);
    return;
  }

  ast->parsed_tokens.SplitToken(sloc);
}

}  // namespace pasta
