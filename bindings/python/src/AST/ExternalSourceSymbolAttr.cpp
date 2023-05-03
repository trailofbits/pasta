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

void RegisterExternalSourceSymbolAttr(py::module_ &m) {
  py::class_<ExternalSourceSymbolAttr, Attr, InheritableAttr>(m, "ExternalSourceSymbolAttr")
    .def_property_readonly("DefinedIn", &ExternalSourceSymbolAttr::DefinedIn)
    .def_property_readonly("DefinedInLength", &ExternalSourceSymbolAttr::DefinedInLength)
    .def_property_readonly("GeneratedDeclaration", &ExternalSourceSymbolAttr::GeneratedDeclaration)
    .def_property_readonly("Language", &ExternalSourceSymbolAttr::Language)
    .def_property_readonly("LanguageLength", &ExternalSourceSymbolAttr::LanguageLength)
    .def_property_readonly("Spelling", &ExternalSourceSymbolAttr::Spelling);
}
} // namespace ogler
