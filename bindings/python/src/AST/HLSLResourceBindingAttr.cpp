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

void RegisterHLSLResourceBindingAttr(py::module_ &m) {
  py::class_<HLSLResourceBindingAttr, Attr, InheritableAttr>(m, "HLSLResourceBindingAttr")
    .def_property_readonly("Slot", &HLSLResourceBindingAttr::Slot)
    .def_property_readonly("SlotLength", &HLSLResourceBindingAttr::SlotLength)
    .def_property_readonly("Space", &HLSLResourceBindingAttr::Space)
    .def_property_readonly("SpaceLength", &HLSLResourceBindingAttr::SpaceLength)
    .def_property_readonly("Spelling", &HLSLResourceBindingAttr::Spelling);
}
} // namespace ogler
