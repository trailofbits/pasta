/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Diagnostic.h"

namespace pasta {

SaveFirstErrorDiagConsumer::~SaveFirstErrorDiagConsumer(void) {}

void SaveFirstErrorDiagConsumer::HandleDiagnostic(
    clang::DiagnosticsEngine::Level level,
    const clang::Diagnostic &info) {
  if (clang::DiagnosticsEngine::Error == level ||
      clang::DiagnosticsEngine::Fatal == level) {
    llvm::SmallString<100> data;
    info.FormatDiagnostic(data);
    data.str().str().swap(error);
  }
}

}  // namespace pasta
