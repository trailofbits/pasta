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

void RegisterUseHandleAttr(py::module_ &m) {
  py::class_<UseHandleAttr, Attr, InheritableAttr, InheritableParamAttr>(m, "UseHandleAttr")
    .def("__hash__", [](const UseHandleAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const UseHandleAttr& a, const UseHandleAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("HandleType", &UseHandleAttr::HandleType)
    .def_property_readonly("HandleTypeLength", &UseHandleAttr::HandleTypeLength)
    .def_property_readonly("Spelling", &UseHandleAttr::Spelling);
}
} // namespace pasta
