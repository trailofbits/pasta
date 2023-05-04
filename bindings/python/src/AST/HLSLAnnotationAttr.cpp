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

void RegisterHLSLAnnotationAttr(py::module_ &m) {
  py::class_<HLSLAnnotationAttr, Attr, InheritableAttr>(m, "HLSLAnnotationAttr")
    .def("__hash__", [](const HLSLAnnotationAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const HLSLAnnotationAttr& a, const HLSLAnnotationAttr& b) { return a.RawAttr() == b.RawAttr(); });
}
} // namespace pasta