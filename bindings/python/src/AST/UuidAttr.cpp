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

void RegisterUuidAttr(py::module_ &m) {
  py::class_<UuidAttr, InheritableAttr>(m, "UuidAttr")
    .def("__hash__", [](const UuidAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const UuidAttr& a, const UuidAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("guid", &UuidAttr::Guid)
    .def_property_readonly("guid_declaration", &UuidAttr::GuidDeclaration)
    .def_property_readonly("guid_length", &UuidAttr::GuidLength)
    .def_property_readonly("spelling", &UuidAttr::Spelling);
}
} // namespace pasta
