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

void RegisterReleaseHandleAttr(py::module_ &m) {
  py::class_<ReleaseHandleAttr, InheritableParamAttr>(m, "ReleaseHandleAttr")
    .def("__hash__", [](const ReleaseHandleAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ReleaseHandleAttr& a, const ReleaseHandleAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("handle_type", &ReleaseHandleAttr::HandleType)
    .def_property_readonly("handle_type_length", &ReleaseHandleAttr::HandleTypeLength)
    .def_property_readonly("spelling", &ReleaseHandleAttr::Spelling);
}
} // namespace pasta
