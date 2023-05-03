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

void RegisterReqdWorkGroupSizeAttr(py::module_ &m) {
  py::class_<ReqdWorkGroupSizeAttr, Attr, InheritableAttr>(m, "ReqdWorkGroupSizeAttr")
    .def_property_readonly("Spelling", &ReqdWorkGroupSizeAttr::Spelling)
    .def_property_readonly("XDim", &ReqdWorkGroupSizeAttr::XDim)
    .def_property_readonly("YDim", &ReqdWorkGroupSizeAttr::YDim)
    .def_property_readonly("ZDim", &ReqdWorkGroupSizeAttr::ZDim);
}
} // namespace ogler
