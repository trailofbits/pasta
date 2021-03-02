/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/Token.h>
#include <pasta/Python/Bindings.h>

#include <optional>

namespace clang {
class SourceLocation;
} // namespace clang

namespace pasta {
namespace py {

// Python wrapper for a source location.
class SourceLocation : public PythonObject<::pasta::py::SourceLocation> {
 public:
  ~SourceLocation(void);

  inline SourceLocation(clang::FullSourceLoc loc_) : loc(std::move(loc_)) {}

  DEFINE_PYTHON_CONSTRUCTOR(SourceLocation, void);

  // Location where the token was ultimately expanded
  BorrowedPythonPtr<SourceLocation> ExpansionLoc(void);

  // Location of the token's character data
  BorrowedPythonPtr<SourceLocation> SpellingLoc(void);

  // Expansion or spelling location for a macro
  BorrowedPythonPtr<SourceLocation> FileLoc(void);

  // Source file
  std::string_view File(void);

  // Line number
  unsigned LineNumber(void);

  // Column number
  unsigned ColumnNumber(void);

  // String representation of a source location
  std::string Str(void) const;

  // Tries to add the `SourceLocation` type to the `pasta` module
  static bool TryAddToModule(PyObject *module);

  std::optional<clang::FullSourceLoc> loc;
};

}  // namespace py
}  // namespace pasta
