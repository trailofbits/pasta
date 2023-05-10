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

void RegisterMSVtorDispAttr(py::module_ &m) {
  py::class_<MSVtorDispAttr, InheritableAttr>(m, "MSVtorDispAttr")
    .def("__hash__", [](const MSVtorDispAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MSVtorDispAttr& a, const MSVtorDispAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &MSVtorDispAttr::Spelling)
    .def_property_readonly("vdm", &MSVtorDispAttr::Vdm)
    .def_property_readonly("vtor_disp_mode", &MSVtorDispAttr::VtorDispMode);
}
} // namespace pasta
