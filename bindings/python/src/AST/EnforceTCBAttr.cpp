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

void RegisterEnforceTCBAttr(py::module_ &m) {
  py::class_<EnforceTCBAttr, InheritableAttr>(m, "EnforceTCBAttr")
    .def("__hash__", [](const EnforceTCBAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const EnforceTCBAttr& a, const EnforceTCBAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &EnforceTCBAttr::Spelling)
    .def_property_readonly("tcb_name", &EnforceTCBAttr::TCBName)
    .def_property_readonly("tcb_name_length", &EnforceTCBAttr::TCBNameLength);
}
} // namespace pasta
