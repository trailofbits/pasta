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

void RegisterUnlikelyAttr(py::module_ &m) {
  py::class_<UnlikelyAttr, StmtAttr>(m, "UnlikelyAttr")
    .def("__hash__", [](const UnlikelyAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const UnlikelyAttr& a, const UnlikelyAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &UnlikelyAttr::Spelling);
}
} // namespace pasta
