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

void RegisterUsingEnumDecl(py::module_ &m) {
  py::class_<UsingEnumDecl, BaseUsingDecl>(m, "UsingEnumDecl")
    .def("__hash__", [](const UsingEnumDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UsingEnumDecl& a, const UsingEnumDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &UsingEnumDecl::CanonicalDeclaration)
    .def_property_readonly("enum_declaration", &UsingEnumDecl::EnumDeclaration)
    .def_property_readonly("enum_token", &UsingEnumDecl::EnumToken)
    .def_property_readonly("enum_type", &UsingEnumDecl::EnumType)
    .def_property_readonly("using_token", &UsingEnumDecl::UsingToken);
}
} // namespace pasta
