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

SplitTokenTracker::SplitTokenTracker(clang::Preprocessor &pp_,
                                     clang::SourceManager &sm_,
                                     ASTImpl *ast_)
    : pp(pp_),
      sm(sm_),
      ci(*(ast_->ci)),
      lo(ci.getLangOpts()),
      ast(ast_) {}

void SplitTokenTracker::Event(
    const clang::Token &tok, EventKind kind, uintptr_t) {
  if (kind != EventKind::SplitToken) {
    return;
  }

  (void) tok;
  std::cerr << "!!! " << clang::tok::getTokenName(tok.getKind()) << '\n';
}

}  // namespace pasta
