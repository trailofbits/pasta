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

void RegisterPragmaClangTextSectionAttr(py::module_ &m) {
  py::class_<PragmaClangTextSectionAttr, Attr, InheritableAttr>(m, "PragmaClangTextSectionAttr")
    .def_property_readonly("Name", &PragmaClangTextSectionAttr::Name)
    .def_property_readonly("NameLength", &PragmaClangTextSectionAttr::NameLength)
    .def_property_readonly("Spelling", &PragmaClangTextSectionAttr::Spelling);
}
} // namespace ogler
