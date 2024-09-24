/*
 * Copyright (c) 2020, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

class ASTImpl;

class SaveFirstErrorDiagConsumer final : public clang::DiagnosticConsumer {
 public:
  SaveFirstErrorDiagConsumer() = default;
  explicit SaveFirstErrorDiagConsumer(const std::shared_ptr<ASTImpl> &ast_);

  virtual ~SaveFirstErrorDiagConsumer(void);

  void HandleDiagnostic(clang::DiagnosticsEngine::Level level,
                        const clang::Diagnostic &info) override;

  const std::shared_ptr<ASTImpl> ast;
  std::string error;
};

}  // namespace pasta
