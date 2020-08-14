/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticIDs.h>
#include <clang/Basic/DiagnosticOptions.h>
#pragma clang diagnostic pop

namespace pasta {

class SaveFirstErrorDiagConsumer final : public clang::DiagnosticConsumer {
 public:
  virtual ~SaveFirstErrorDiagConsumer(void);

  void HandleDiagnostic(clang::DiagnosticsEngine::Level level,
                        const clang::Diagnostic &info) override;

  std::string error;
};

}  // namespace pasta
