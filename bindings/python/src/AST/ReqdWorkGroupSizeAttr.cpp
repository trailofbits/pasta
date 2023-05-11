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

void RegisterReqdWorkGroupSizeAttr(py::module_ &m) {
  py::class_<ReqdWorkGroupSizeAttr, InheritableAttr>(m, "ReqdWorkGroupSizeAttr")
    .def("__hash__", [](const ReqdWorkGroupSizeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ReqdWorkGroupSizeAttr::Spelling)
    .def_property_readonly("x_dim", &ReqdWorkGroupSizeAttr::XDim)
    .def_property_readonly("y_dim", &ReqdWorkGroupSizeAttr::YDim)
    .def_property_readonly("z_dim", &ReqdWorkGroupSizeAttr::ZDim);
}
} // namespace pasta
