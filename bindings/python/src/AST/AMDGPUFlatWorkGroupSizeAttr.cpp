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

void RegisterAMDGPUFlatWorkGroupSizeAttr(py::module_ &m) {
  py::class_<AMDGPUFlatWorkGroupSizeAttr, Attr, InheritableAttr>(m, "AMDGPUFlatWorkGroupSizeAttr")
    .def_property_readonly("Max", &AMDGPUFlatWorkGroupSizeAttr::Max)
    .def_property_readonly("Min", &AMDGPUFlatWorkGroupSizeAttr::Min)
    .def_property_readonly("Spelling", &AMDGPUFlatWorkGroupSizeAttr::Spelling);
}
} // namespace ogler
