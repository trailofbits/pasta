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

void RegisterObjCExceptionAttr(py::module_ &m) {
  py::class_<ObjCExceptionAttr, Attr, InheritableAttr>(m, "ObjCExceptionAttr")
    .def("__hash__", [](const ObjCExceptionAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCExceptionAttr& a, const ObjCExceptionAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &ObjCExceptionAttr::Spelling);
}
} // namespace pasta