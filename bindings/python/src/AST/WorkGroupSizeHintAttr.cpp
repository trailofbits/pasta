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
    .def("__hash__", [](const WorkGroupSizeHintAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const WorkGroupSizeHintAttr& a, const WorkGroupSizeHintAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &WorkGroupSizeHintAttr::Spelling)
    .def_property_readonly("XDim", &WorkGroupSizeHintAttr::XDim)
    .def_property_readonly("YDim", &WorkGroupSizeHintAttr::YDim)
    .def_property_readonly("ZDim", &WorkGroupSizeHintAttr::ZDim);
}
} // namespace pasta
