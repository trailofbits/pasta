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

void RegisterNSConsumesSelfAttr(py::module_ &m) {
  py::class_<NSConsumesSelfAttr, Attr, InheritableAttr>(m, "NSConsumesSelfAttr")
    .def("__hash__", [](const NSConsumesSelfAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const NSConsumesSelfAttr& a, const NSConsumesSelfAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &NSConsumesSelfAttr::Spelling);
}
} // namespace pasta