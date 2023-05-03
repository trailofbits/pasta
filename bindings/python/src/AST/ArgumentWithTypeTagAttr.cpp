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

void RegisterArgumentWithTypeTagAttr(py::module_ &m) {
  py::class_<ArgumentWithTypeTagAttr, Attr, InheritableAttr>(m, "ArgumentWithTypeTagAttr")
    .def_property_readonly("IsPointer", &ArgumentWithTypeTagAttr::IsPointer)
    .def_property_readonly("SemanticSpelling", &ArgumentWithTypeTagAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &ArgumentWithTypeTagAttr::Spelling);
}
} // namespace ogler
