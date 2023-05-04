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

void RegisterObjCRuntimeNameAttr(py::module_ &m) {
  py::class_<ObjCRuntimeNameAttr, Attr>(m, "ObjCRuntimeNameAttr")
    .def("__hash__", [](const ObjCRuntimeNameAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCRuntimeNameAttr& a, const ObjCRuntimeNameAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("MetadataName", &ObjCRuntimeNameAttr::MetadataName)
    .def_property_readonly("MetadataNameLength", &ObjCRuntimeNameAttr::MetadataNameLength)
    .def_property_readonly("Spelling", &ObjCRuntimeNameAttr::Spelling);
}
} // namespace pasta
