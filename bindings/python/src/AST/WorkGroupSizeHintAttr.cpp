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

void RegisterWorkGroupSizeHintAttr(py::module_ &m) {
  py::class_<WorkGroupSizeHintAttr, Attr, InheritableAttr>(m, "WorkGroupSizeHintAttr")
    .def_property_readonly("Spelling", &WorkGroupSizeHintAttr::Spelling)
    .def_property_readonly("XDim", &WorkGroupSizeHintAttr::XDim)
    .def_property_readonly("YDim", &WorkGroupSizeHintAttr::YDim)
    .def_property_readonly("ZDim", &WorkGroupSizeHintAttr::ZDim);
}
} // namespace pasta
