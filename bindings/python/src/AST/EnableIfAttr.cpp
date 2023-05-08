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

void RegisterEnableIfAttr(py::module_ &m) {
  py::class_<EnableIfAttr, InheritableAttr>(m, "EnableIfAttr")
    .def("__hash__", [](const EnableIfAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const EnableIfAttr& a, const EnableIfAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("condition", &EnableIfAttr::Condition)
    .def_property_readonly("message", &EnableIfAttr::Message)
    .def_property_readonly("message_length", &EnableIfAttr::MessageLength)
    .def_property_readonly("spelling", &EnableIfAttr::Spelling);
}
} // namespace pasta
