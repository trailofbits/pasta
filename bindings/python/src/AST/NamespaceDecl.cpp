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

void RegisterNamespaceDecl(py::module_ &m) {
  py::class_<NamespaceDecl, Decl, NamedDecl>(m, "NamespaceDecl")
    .def("__hash__", [](const NamespaceDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const NamespaceDecl& a, const NamespaceDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AnonymousNamespace", &NamespaceDecl::AnonymousNamespace)
    .def_property_readonly("BeginToken", &NamespaceDecl::BeginToken)
    .def_property_readonly("CanonicalDeclaration", &NamespaceDecl::CanonicalDeclaration)
    .def_property_readonly("OriginalNamespace", &NamespaceDecl::OriginalNamespace)
    .def_property_readonly("RBraceToken", &NamespaceDecl::RBraceToken)
    .def_property_readonly("IsAnonymousNamespace", &NamespaceDecl::IsAnonymousNamespace)
    .def_property_readonly("IsInline", &NamespaceDecl::IsInline)
    .def_property_readonly("IsNested", &NamespaceDecl::IsNested)
    .def_property_readonly("IsOriginalNamespace", &NamespaceDecl::IsOriginalNamespace);
}
} // namespace pasta
