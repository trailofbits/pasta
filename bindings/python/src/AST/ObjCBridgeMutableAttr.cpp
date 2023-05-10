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

void RegisterObjCBridgeMutableAttr(py::module_ &m) {
  py::class_<ObjCBridgeMutableAttr, InheritableAttr>(m, "ObjCBridgeMutableAttr")
    .def("__hash__", [](const ObjCBridgeMutableAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCBridgeMutableAttr& a, const ObjCBridgeMutableAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ObjCBridgeMutableAttr::Spelling);
}
} // namespace pasta
