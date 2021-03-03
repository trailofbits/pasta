/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>

#include "AST.h"

namespace pasta {
namespace py {
namespace {
DEFINE_PYTHON_METHOD(SourceLocation, ExpansionLoc, expansion_loc);
DEFINE_PYTHON_METHOD(SourceLocation, SpellingLoc, spelling_loc);
DEFINE_PYTHON_METHOD(SourceLocation, FileLoc, file_loc);
DEFINE_PYTHON_METHOD(SourceLocation, File, file);
DEFINE_PYTHON_METHOD(SourceLocation, LineNumber, line_number);
DEFINE_PYTHON_METHOD(SourceLocation, ColumnNumber, column_number);

static PyMethodDef gSourceLocationMethods[] = {
  PYTHON_METHOD(expansion_loc, "Location where token was ultimately expanded."),
  PYTHON_METHOD(spelling_loc, "Location of the token's character data."),
  PYTHON_METHOD(file_loc, "Expansion or spelling location for a macro."),
  PYTHON_METHOD_SENTINEL
};

static PyGetSetDef gSourceLocationGettersSetters[] = {
  PYTHON_GETTER(file, "Source file"),
  PYTHON_GETTER(line_number, "Line number"),
  PYTHON_GETTER(column_number, "Column number"),
  PYTHON_GETTER_SETTER_SENTINEL
};
} // namespace

SourceLocation::~SourceLocation(void) {}

SourceLocation::SourceLocation(void) {
  PythonErrorStreamer(PyExc_NotImplementedError)
      << "pasta.SourceLocation cannot be directly instantiated.";
}

BorrowedPythonPtr<SourceLocation> SourceLocation::ExpansionLoc(void) {
  return SourceLocation::New(loc->getExpansionLoc());
}

BorrowedPythonPtr<SourceLocation> SourceLocation::SpellingLoc(void) {
  return SourceLocation::New(loc->getSpellingLoc());
}

BorrowedPythonPtr<SourceLocation> SourceLocation::FileLoc(void) {
  return SourceLocation::New(loc->getFileLoc());
}

std::string_view SourceLocation::File(void) {
  return loc->getFileEntry()->getName();
}

unsigned SourceLocation::LineNumber(void) {
  return loc->getLineNumber();
}

unsigned SourceLocation::ColumnNumber(void) {
  return loc->getColumnNumber();
}

std::string SourceLocation::Str(void) const {
  return loc->printToString(loc->getManager());
}

bool SourceLocation::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.SourceLocation";
  gType.tp_doc = "Clang source location.";
  gType.tp_methods = gSourceLocationMethods;
  gType.tp_getset = gSourceLocationGettersSetters;
  gType.tp_str = [] (PyObject *self_) {
    auto self = reinterpret_cast<SourceLocation*>(self_);
    return convert::FromStdStr(self->Str());
  };
  if (0 != PyType_Ready(&gType)) {
    return false;
  }

  Py_INCREF(&gType);
  return !PyModule_AddObject(module, "SourceLocation",
                             reinterpret_cast<PyObject *>(&gType));
}

} // namespace py
} // namespace pasta
