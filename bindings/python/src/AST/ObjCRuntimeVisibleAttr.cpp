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

void RegisterObjCRuntimeVisibleAttr(py::module_ &m) {
  py::class_<ObjCRuntimeVisibleAttr, Attr>(m, "ObjCRuntimeVisibleAttr")
    .def("__hash__", [](const ObjCRuntimeVisibleAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCRuntimeVisibleAttr& a, const ObjCRuntimeVisibleAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ObjCRuntimeVisibleAttr::Spelling);
}
} // namespace pasta
