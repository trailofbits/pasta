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
  py::class_<NamespaceAliasDecl, NamedDecl>(m, "NamespaceAliasDecl")
    .def("__hash__", [](const NamespaceAliasDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const NamespaceAliasDecl& a, const NamespaceAliasDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("alias_token", &NamespaceAliasDecl::AliasToken)
    .def_property_readonly("aliased_namespace", &NamespaceAliasDecl::AliasedNamespace)
    .def_property_readonly("canonical_declaration", &NamespaceAliasDecl::CanonicalDeclaration)
    .def_property_readonly("namespace", &NamespaceAliasDecl::Namespace)
    .def_property_readonly("namespace_token", &NamespaceAliasDecl::NamespaceToken)
    .def_property_readonly("target_name_token", &NamespaceAliasDecl::TargetNameToken);
}
} // namespace pasta
