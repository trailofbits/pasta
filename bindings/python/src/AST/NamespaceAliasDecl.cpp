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

void RegisterNamespaceAliasDecl(py::module_ &m) {
  py::class_<NamespaceAliasDecl, Decl, NamedDecl>(m, "NamespaceAliasDecl")
    .def("__hash__", [](const NamespaceAliasDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const NamespaceAliasDecl& a, const NamespaceAliasDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AliasToken", &NamespaceAliasDecl::AliasToken)
    .def_property_readonly("AliasedNamespace", &NamespaceAliasDecl::AliasedNamespace)
    .def_property_readonly("CanonicalDeclaration", &NamespaceAliasDecl::CanonicalDeclaration)
    .def_property_readonly("Namespace", &NamespaceAliasDecl::Namespace)
    .def_property_readonly("NamespaceToken", &NamespaceAliasDecl::NamespaceToken)
    .def_property_readonly("TargetNameToken", &NamespaceAliasDecl::TargetNameToken);
}
} // namespace pasta
