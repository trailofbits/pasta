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
  py::class_<UsingEnumDecl, BaseUsingDecl, Decl, NamedDecl>(m, "UsingEnumDecl")
    .def_property_readonly("CanonicalDeclaration", &UsingEnumDecl::CanonicalDeclaration)
    .def_property_readonly("EnumDeclaration", &UsingEnumDecl::EnumDeclaration)
    .def_property_readonly("EnumToken", &UsingEnumDecl::EnumToken)
    .def_property_readonly("EnumType", &UsingEnumDecl::EnumType)
    .def_property_readonly("UsingToken", &UsingEnumDecl::UsingToken);
}
} // namespace pasta
