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
#include <clang/Basic/SourceManager.h>
#pragma clang diagnostic pop

namespace pasta {

SaveFirstErrorDiagConsumer::~SaveFirstErrorDiagConsumer(void) {}

void SaveFirstErrorDiagConsumer::HandleDiagnostic(
    clang::DiagnosticsEngine::Level level, const clang::Diagnostic &info) {
  if (error.empty() && (clang::DiagnosticsEngine::Error == level ||
                        clang::DiagnosticsEngine::Fatal == level)) {

    std::stringstream ss;

    // Build up relevant source location info for the diagnostic.
    const auto &source_location = info.getLocation();
    if (source_location.isValid() && info.hasSourceManager()) {
      const auto &source_manager = info.getSourceManager();
      auto presumed_loc = source_manager.getPresumedLoc(source_location);

      if (presumed_loc.isInvalid()) {
        auto file_id = source_manager.getFileID(source_location);
        if (file_id.isValid()) {
          auto file_entry = source_manager.getFileEntryForID(file_id);
          if (file_entry && file_entry->isValid()) {
            ss << file_entry->getName().str() << ": ";
          }
        }
      } else {
        ss << presumed_loc.getFilename();
        ss << ':' << static_cast<int>(presumed_loc.getLine()) << ':'
           << static_cast<int>(presumed_loc.getColumn()) << ' ';
      }
    }

    llvm::SmallString<100> data;
    info.FormatDiagnostic(data);
    ss << data.str().str();

    ss.str().swap(error);
  }
}

}  // namespace pasta
