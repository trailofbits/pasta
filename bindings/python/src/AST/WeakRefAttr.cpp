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

void RegisterWeakRefAttr(py::module_ &m) {
  py::class_<WeakRefAttr, InheritableAttr>(m, "WeakRefAttr")
    .def("__hash__", [](const WeakRefAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const WeakRefAttr& a, const WeakRefAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("aliasee", &WeakRefAttr::Aliasee)
    .def_property_readonly("aliasee_length", &WeakRefAttr::AliaseeLength)
    .def_property_readonly("spelling", &WeakRefAttr::Spelling);
}
} // namespace pasta
