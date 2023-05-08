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

void RegisterObjCIndependentClassAttr(py::module_ &m) {
  py::class_<ObjCIndependentClassAttr, InheritableAttr>(m, "ObjCIndependentClassAttr")
    .def("__hash__", [](const ObjCIndependentClassAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCIndependentClassAttr& a, const ObjCIndependentClassAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ObjCIndependentClassAttr::Spelling);
}
} // namespace pasta
