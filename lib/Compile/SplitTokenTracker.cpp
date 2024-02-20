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
    const clang::Token &tok, EventKind kind, uintptr_t data) {
  if (kind != EventKind::SplitToken && kind != EventKind::LAngleToken &&
      kind != EventKind::RAngleToken) {
    return;
  }

  auto sloc = tok.getLocation();
  if (sloc.isInvalid()) {
    assert(kind == EventKind::LAngleToken || kind == EventKind::RAngleToken);
    return;
  }

  if (sloc.isMacroID()) {
    sloc = sm.getFileLoc(sloc);
    if (!sloc.isFileID()) {
      assert(false);
      return;
    }
  }

  auto [file_id, file_offset] = sm.getDecomposedLoc(sloc);
  if (file_id != sm.getMainFileID()) {
    assert(false);
    return;
  }

  auto maybe_offset = ast->parsed_tokens.DataOffsetToTokenIndex(file_offset);
  if (!maybe_offset) {
    assert(false);
    return;
  }

  DerivedTokenIndex offset = maybe_offset.value();

  if (auto out_loc = reinterpret_cast<clang::SourceLocation *>(data)) {
    *out_loc = sloc;
  }

  if (kind == EventKind::SplitToken) {
    ast->parsed_tokens.SplitToken(offset);

  } else if (kind == EventKind::LAngleToken) {
    assert(ast->parsed_tokens.Kind(offset) == TokenKind::kLess ||
           ast->parsed_tokens.Kind(offset) == TokenKind::kLAngle);
    ast->parsed_tokens.SetKind(offset, TokenKind::kLAngle);

  } else if (kind == EventKind::RAngleToken) {
    assert(ast->parsed_tokens.Kind(offset) == TokenKind::kGreater ||
           ast->parsed_tokens.Kind(offset) == TokenKind::kRAngle);
    ast->parsed_tokens.SetKind(offset, TokenKind::kRAngle);
  }
}

}  // namespace pasta
