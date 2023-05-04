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

void RegisterAMDGPUWavesPerEUAttr(py::module_ &m) {
  py::class_<AMDGPUWavesPerEUAttr, Attr, InheritableAttr>(m, "AMDGPUWavesPerEUAttr")
    .def("__hash__", [](const AMDGPUWavesPerEUAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AMDGPUWavesPerEUAttr& a, const AMDGPUWavesPerEUAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Max", &AMDGPUWavesPerEUAttr::Max)
    .def_property_readonly("Min", &AMDGPUWavesPerEUAttr::Min)
    .def_property_readonly("Spelling", &AMDGPUWavesPerEUAttr::Spelling);
}
} // namespace pasta