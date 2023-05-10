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

void RegisterAMDGPUFlatWorkGroupSizeAttr(py::module_ &m) {
  py::class_<AMDGPUFlatWorkGroupSizeAttr, InheritableAttr>(m, "AMDGPUFlatWorkGroupSizeAttr")
    .def("__hash__", [](const AMDGPUFlatWorkGroupSizeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AMDGPUFlatWorkGroupSizeAttr& a, const AMDGPUFlatWorkGroupSizeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("max", &AMDGPUFlatWorkGroupSizeAttr::Max)
    .def_property_readonly("min", &AMDGPUFlatWorkGroupSizeAttr::Min)
    .def_property_readonly("spelling", &AMDGPUFlatWorkGroupSizeAttr::Spelling);
}
} // namespace pasta
