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

void RegisterHLSLResourceAttr(py::module_ &m) {
  py::class_<HLSLResourceAttr, InheritableAttr>(m, "HLSLResourceAttr")
    .def("__hash__", [](const HLSLResourceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const HLSLResourceAttr& a, const HLSLResourceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("resource_shape", &HLSLResourceAttr::ResourceShape)
    .def_property_readonly("resource_type", &HLSLResourceAttr::ResourceType)
    .def_property_readonly("spelling", &HLSLResourceAttr::Spelling);
}
} // namespace pasta
