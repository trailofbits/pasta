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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterNamespaceDecl(py::module_ &m) {
  py::class_<NamespaceDecl, NamedDecl>(m, "NamespaceDecl")
    .def("__hash__", [](const NamespaceDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const NamespaceDecl& a, const NamespaceDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("anonymous_namespace", &NamespaceDecl::AnonymousNamespace)
    .def_property_readonly("begin_token", &NamespaceDecl::BeginToken)
    .def_property_readonly("canonical_declaration", &NamespaceDecl::CanonicalDeclaration)
    .def_property_readonly("original_namespace", &NamespaceDecl::OriginalNamespace)
    .def_property_readonly("r_brace_token", &NamespaceDecl::RBraceToken)
    .def_property_readonly("is_anonymous_namespace", &NamespaceDecl::IsAnonymousNamespace)
    .def_property_readonly("is_inline", &NamespaceDecl::IsInline)
    .def_property_readonly("is_nested", &NamespaceDecl::IsNested)
    .def_property_readonly("is_original_namespace", &NamespaceDecl::IsOriginalNamespace);
}
} // namespace pasta
