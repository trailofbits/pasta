/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterErrorAttr(py::module_ &m) {
  py::class_<ErrorAttr, InheritableAttr>(m, "ErrorAttr")
    .def("__hash__", [](const ErrorAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ErrorAttr& a, const ErrorAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &ErrorAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &ErrorAttr::Spelling)
    .def_property_readonly("UserDiagnostic", &ErrorAttr::UserDiagnostic)
    .def_property_readonly("UserDiagnosticLength", &ErrorAttr::UserDiagnosticLength)
    .def_property_readonly("IsError", &ErrorAttr::IsError)
    .def_property_readonly("IsWarning", &ErrorAttr::IsWarning);
}
} // namespace pasta
