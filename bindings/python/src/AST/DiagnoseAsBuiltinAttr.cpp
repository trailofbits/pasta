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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterDiagnoseAsBuiltinAttr(py::module_ &m) {
  py::class_<DiagnoseAsBuiltinAttr, InheritableAttr>(m, "DiagnoseAsBuiltinAttr")
    .def("__hash__", [](const DiagnoseAsBuiltinAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const DiagnoseAsBuiltinAttr& a, const DiagnoseAsBuiltinAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("function", &DiagnoseAsBuiltinAttr::Function)
    .def_property_readonly("spelling", &DiagnoseAsBuiltinAttr::Spelling);
}
} // namespace pasta
