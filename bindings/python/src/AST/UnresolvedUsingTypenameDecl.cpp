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

void RegisterUnresolvedUsingTypenameDecl(py::module_ &m) {
  py::class_<UnresolvedUsingTypenameDecl, Decl, NamedDecl, TypeDecl>(m, "UnresolvedUsingTypenameDecl")
    .def_property_readonly("CanonicalDeclaration", &UnresolvedUsingTypenameDecl::CanonicalDeclaration)
    .def_property_readonly("EllipsisToken", &UnresolvedUsingTypenameDecl::EllipsisToken)
    .def_property_readonly("TypenameToken", &UnresolvedUsingTypenameDecl::TypenameToken)
    .def_property_readonly("UsingToken", &UnresolvedUsingTypenameDecl::UsingToken)
    .def_property_readonly("IsPackExpansion", &UnresolvedUsingTypenameDecl::IsPackExpansion);
}
} // namespace pasta
