/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Diagnostic.h"

#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wfloat-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceManager.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Token.h"

namespace pasta {

SaveFirstErrorDiagConsumer::SaveFirstErrorDiagConsumer(
    const std::shared_ptr<ASTImpl> &ast_)
    : ast(ast_) {}

SaveFirstErrorDiagConsumer::~SaveFirstErrorDiagConsumer(void) {}

void SaveFirstErrorDiagConsumer::HandleDiagnostic(
    clang::DiagnosticsEngine::Level level, const clang::Diagnostic &info) {
  if (!error.empty()) {
    return;
  }
  if (clang::DiagnosticsEngine::Error != level &&
      clang::DiagnosticsEngine::Fatal != level) {
    return;
  }

  std::stringstream ss;
  const auto &tokens = ast->tokens;
  clang::PresumedLoc presumed_loc;
  unsigned line_number = 0;

  // Build up relevant source location info for the diagnostic.
  auto source_location = info.getLocation();
  if (source_location.isValid() && info.hasSourceManager()) {

    const auto &source_manager = info.getSourceManager();
    auto try_get_loc_info = [&] (clang::SourceLocation loc) -> bool {
      presumed_loc = source_manager.getPresumedLoc(loc);
      auto file_id = source_manager.getFileID(source_location);

      if (presumed_loc.isInvalid() && file_id.isValid()) {
        auto file_entry = source_manager.getFileEntryForID(file_id);
        if (file_entry && file_entry->isValid()) {
          ss << file_entry->getName().str() << ": ";
        }
        return false;
      }
      return true;
    };

    if (!try_get_loc_info(source_location)) {
      goto bail;
    }

    // We may be in a big file full of pre-processed code, with one token
    // per line, so go and try to get an actual location from the original
    // tokens.
    line_number = presumed_loc.getLine();
    if (ast && 0u < line_number && line_number <= tokens.size()) {
      source_location = clang::SourceLocation::getFromRawEncoding(
          tokens[line_number - 1u].opaque_source_loc);
      if (!try_get_loc_info(source_location)) {
        goto bail;
      }
    }

    ss << presumed_loc.getFilename()
       << ':' << static_cast<int>(line_number) << ':'
       << static_cast<int>(presumed_loc.getColumn()) << ' ';
  }

bail:
  llvm::SmallString<100> data;
  info.FormatDiagnostic(data);
  ss << data.str().str();
  ss.str().swap(error);
}

}  // namespace pasta
