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

void RegisterHLSLSV_GroupIndexAttr(py::module_ &m) {
  py::class_<HLSLSV_GroupIndexAttr, Attr, HLSLAnnotationAttr, InheritableAttr>(m, "HLSLSV_GroupIndexAttr")
    .def("__hash__", [](const HLSLSV_GroupIndexAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const HLSLSV_GroupIndexAttr& a, const HLSLSV_GroupIndexAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &HLSLSV_GroupIndexAttr::Spelling);
}
} // namespace pasta
