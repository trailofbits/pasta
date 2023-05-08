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

void RegisterObjCRootClassAttr(py::module_ &m) {
  py::class_<ObjCRootClassAttr, InheritableAttr>(m, "ObjCRootClassAttr")
    .def("__hash__", [](const ObjCRootClassAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCRootClassAttr& a, const ObjCRootClassAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ObjCRootClassAttr::Spelling);
}
} // namespace pasta
