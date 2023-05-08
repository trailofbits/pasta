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

void RegisterReturnTypestateAttr(py::module_ &m) {
  py::class_<ReturnTypestateAttr, InheritableAttr>(m, "ReturnTypestateAttr")
    .def("__hash__", [](const ReturnTypestateAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ReturnTypestateAttr& a, const ReturnTypestateAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ReturnTypestateAttr::Spelling)
    .def_property_readonly("state", &ReturnTypestateAttr::State);
}
} // namespace pasta
