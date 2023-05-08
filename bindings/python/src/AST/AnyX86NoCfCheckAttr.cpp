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

void RegisterAnyX86NoCfCheckAttr(py::module_ &m) {
  py::class_<AnyX86NoCfCheckAttr, InheritableAttr>(m, "AnyX86NoCfCheckAttr")
    .def("__hash__", [](const AnyX86NoCfCheckAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AnyX86NoCfCheckAttr& a, const AnyX86NoCfCheckAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &AnyX86NoCfCheckAttr::Spelling);
}
} // namespace pasta
