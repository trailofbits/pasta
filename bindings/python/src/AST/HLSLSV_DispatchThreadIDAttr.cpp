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

void RegisterHLSLSV_DispatchThreadIDAttr(py::module_ &m) {
  py::class_<HLSLSV_DispatchThreadIDAttr, HLSLAnnotationAttr>(m, "HLSLSV_DispatchThreadIDAttr")
    .def("__hash__", [](const HLSLSV_DispatchThreadIDAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const HLSLSV_DispatchThreadIDAttr& a, const HLSLSV_DispatchThreadIDAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &HLSLSV_DispatchThreadIDAttr::Spelling);
}
} // namespace pasta
