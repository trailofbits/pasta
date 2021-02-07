/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Clang.h"

namespace pasta {
namespace py {
namespace {
DEFINE_PYTHON_METHOD(SourceLocation, File, file);
DEFINE_PYTHON_METHOD(SourceLocation, LineNumber, line_number);
DEFINE_PYTHON_METHOD(SourceLocation, ColumnNumber, column_number);

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

std::string_view SourceLocation::File(void) {
  return loc->getFileEntry()->getName();
}

unsigned SourceLocation::LineNumber(void) {
  return loc->getLineNumber();
}

unsigned SourceLocation::ColumnNumber(void) {
  return loc->getColumnNumber();
}

std::string_view SourceLocation::Str(void) {
  // Adrian: TODO
  return "";
}

bool SourceLocation::TryAddToModule(PyObject *module) {
  gType.tp_name = "pasta.SourceLocation";
  gType.tp_doc = "Clang source location.";
  gType.tp_methods = nullptr;
  gType.tp_getset = gSourceLocationGettersSetters;
  gType.tp_str = [] (PyObject *self_) {
    auto self = reinterpret_cast<SourceLocation*>(self_);
    return convert::FromStdStrView(self->Str());
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