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

void RegisterOMPDeclareSimdDeclAttr(py::module_ &m) {
  py::class_<OMPDeclareSimdDeclAttr, Attr>(m, "OMPDeclareSimdDeclAttr")
    .def("__hash__", [](const OMPDeclareSimdDeclAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("branch_state", &OMPDeclareSimdDeclAttr::BranchState)
    .def_property_readonly("simdlen", &OMPDeclareSimdDeclAttr::Simdlen)
    .def_property_readonly("spelling", &OMPDeclareSimdDeclAttr::Spelling);
}
} // namespace pasta
