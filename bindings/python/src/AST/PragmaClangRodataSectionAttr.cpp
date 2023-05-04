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

void RegisterPragmaClangRodataSectionAttr(py::module_ &m) {
  py::class_<PragmaClangRodataSectionAttr, Attr, InheritableAttr>(m, "PragmaClangRodataSectionAttr")
    .def_property_readonly("Name", &PragmaClangRodataSectionAttr::Name)
    .def_property_readonly("NameLength", &PragmaClangRodataSectionAttr::NameLength)
    .def_property_readonly("Spelling", &PragmaClangRodataSectionAttr::Spelling);
}
} // namespace pasta
