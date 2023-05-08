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

void RegisterObjCNonRuntimeProtocolAttr(py::module_ &m) {
  py::class_<ObjCNonRuntimeProtocolAttr, Attr>(m, "ObjCNonRuntimeProtocolAttr")
    .def("__hash__", [](const ObjCNonRuntimeProtocolAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCNonRuntimeProtocolAttr& a, const ObjCNonRuntimeProtocolAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ObjCNonRuntimeProtocolAttr::Spelling);
}
} // namespace pasta
