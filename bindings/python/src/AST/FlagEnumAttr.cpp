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

void RegisterFlagEnumAttr(py::module_ &m) {
  py::class_<FlagEnumAttr, InheritableAttr>(m, "FlagEnumAttr")
    .def("__hash__", [](const FlagEnumAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const FlagEnumAttr& a, const FlagEnumAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &FlagEnumAttr::Spelling);
}
} // namespace pasta
