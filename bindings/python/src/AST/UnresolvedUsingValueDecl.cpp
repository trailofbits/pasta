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

void RegisterUnresolvedUsingValueDecl(py::module_ &m) {
  py::class_<UnresolvedUsingValueDecl, Decl, NamedDecl, ValueDecl>(m, "UnresolvedUsingValueDecl")
    .def_property_readonly("CanonicalDeclaration", &UnresolvedUsingValueDecl::CanonicalDeclaration)
    .def_property_readonly("EllipsisToken", &UnresolvedUsingValueDecl::EllipsisToken)
    .def_property_readonly("UsingToken", &UnresolvedUsingValueDecl::UsingToken)
    .def_property_readonly("IsAccessDeclaration", &UnresolvedUsingValueDecl::IsAccessDeclaration)
    .def_property_readonly("IsPackExpansion", &UnresolvedUsingValueDecl::IsPackExpansion);
}
} // namespace pasta
