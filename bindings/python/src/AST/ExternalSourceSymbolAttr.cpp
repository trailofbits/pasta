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
  py::class_<ExternalSourceSymbolAttr, InheritableAttr>(m, "ExternalSourceSymbolAttr")
    .def("__hash__", [](const ExternalSourceSymbolAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ExternalSourceSymbolAttr& a, const ExternalSourceSymbolAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("defined_in", &ExternalSourceSymbolAttr::DefinedIn)
    .def_property_readonly("defined_in_length", &ExternalSourceSymbolAttr::DefinedInLength)
    .def_property_readonly("generated_declaration", &ExternalSourceSymbolAttr::GeneratedDeclaration)
    .def_property_readonly("language", &ExternalSourceSymbolAttr::Language)
    .def_property_readonly("language_length", &ExternalSourceSymbolAttr::LanguageLength)
    .def_property_readonly("spelling", &ExternalSourceSymbolAttr::Spelling);
}
} // namespace pasta
