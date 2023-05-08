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

void RegisterAlignValueAttr(py::module_ &m) {
  py::class_<AlignValueAttr, Attr>(m, "AlignValueAttr")
    .def("__hash__", [](const AlignValueAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AlignValueAttr& a, const AlignValueAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("alignment", &AlignValueAttr::Alignment)
    .def_property_readonly("spelling", &AlignValueAttr::Spelling);
}
} // namespace pasta
