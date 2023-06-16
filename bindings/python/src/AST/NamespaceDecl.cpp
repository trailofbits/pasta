/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterNamespaceDecl(nb::module_ &m) {
  nb::class_<NamespaceDecl, NamedDecl>(m, "NamespaceDecl")
    .def("__hash__", [](const NamespaceDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("anonymous_namespace", &NamespaceDecl::AnonymousNamespace)
    .def_prop_ro("begin_token", &NamespaceDecl::BeginToken)
    .def_prop_ro("canonical_declaration", &NamespaceDecl::CanonicalDeclaration)
    .def_prop_ro("original_namespace", &NamespaceDecl::OriginalNamespace)
    .def_prop_ro("r_brace_token", &NamespaceDecl::RBraceToken)
    .def_prop_ro("is_anonymous_namespace", &NamespaceDecl::IsAnonymousNamespace)
    .def_prop_ro("is_inline", &NamespaceDecl::IsInline)
    .def_prop_ro("is_nested", &NamespaceDecl::IsNested)
    .def_prop_ro("is_original_namespace", &NamespaceDecl::IsOriginalNamespace);
}
} // namespace pasta
