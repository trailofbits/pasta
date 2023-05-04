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

void RegisterUsingDirectiveDecl(py::module_ &m) {
  py::class_<UsingDirectiveDecl, Decl, NamedDecl>(m, "UsingDirectiveDecl")
    .def_property_readonly("CommonAncestor", &UsingDirectiveDecl::CommonAncestor)
    .def_property_readonly("IdentifierToken", &UsingDirectiveDecl::IdentifierToken)
    .def_property_readonly("NamespaceKeyToken", &UsingDirectiveDecl::NamespaceKeyToken)
    .def_property_readonly("NominatedNamespace", &UsingDirectiveDecl::NominatedNamespace)
    .def_property_readonly("NominatedNamespaceAsWritten", &UsingDirectiveDecl::NominatedNamespaceAsWritten)
    .def_property_readonly("UsingToken", &UsingDirectiveDecl::UsingToken);
}
} // namespace pasta
