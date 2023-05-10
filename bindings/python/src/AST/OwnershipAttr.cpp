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

void RegisterOwnershipAttr(py::module_ &m) {
  py::class_<OwnershipAttr, InheritableAttr>(m, "OwnershipAttr")
    .def("__hash__", [](const OwnershipAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OwnershipAttr& a, const OwnershipAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("own_kind", &OwnershipAttr::OwnKind)
    .def_property_readonly("semantic_spelling", &OwnershipAttr::SemanticSpelling)
    .def_property_readonly("spelling", &OwnershipAttr::Spelling)
    .def_property_readonly("is_holds", &OwnershipAttr::IsHolds)
    .def_property_readonly("is_returns", &OwnershipAttr::IsReturns)
    .def_property_readonly("is_takes", &OwnershipAttr::IsTakes);
}
} // namespace pasta
