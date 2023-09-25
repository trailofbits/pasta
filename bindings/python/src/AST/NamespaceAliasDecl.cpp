/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterNamespaceAliasDecl(nb::module_ &m) {
  nb::class_<NamespaceAliasDecl, NamedDecl>(m, "NamespaceAliasDecl")
    .def("__hash__", [](const NamespaceAliasDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("alias_token", &NamespaceAliasDecl::AliasToken)
    .def_prop_ro("aliased_namespace", &NamespaceAliasDecl::AliasedNamespace)
    .def_prop_ro("canonical_declaration", &NamespaceAliasDecl::CanonicalDeclaration)
    .def_prop_ro("namespace", &NamespaceAliasDecl::Namespace)
    .def_prop_ro("namespace_token", &NamespaceAliasDecl::NamespaceToken)
    .def_prop_ro("target_name_token", &NamespaceAliasDecl::TargetNameToken);
}
} // namespace pasta
