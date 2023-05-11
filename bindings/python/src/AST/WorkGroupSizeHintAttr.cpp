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

void RegisterWorkGroupSizeHintAttr(py::module_ &m) {
  py::class_<WorkGroupSizeHintAttr, InheritableAttr>(m, "WorkGroupSizeHintAttr")
    .def("__hash__", [](const WorkGroupSizeHintAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &WorkGroupSizeHintAttr::Spelling)
    .def_property_readonly("x_dim", &WorkGroupSizeHintAttr::XDim)
    .def_property_readonly("y_dim", &WorkGroupSizeHintAttr::YDim)
    .def_property_readonly("z_dim", &WorkGroupSizeHintAttr::ZDim);
}
} // namespace pasta
