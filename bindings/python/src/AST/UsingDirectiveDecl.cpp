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

void RegisterUsingDirectiveDecl(py::module_ &m) {
  py::class_<UsingDirectiveDecl, NamedDecl>(m, "UsingDirectiveDecl")
    .def("__hash__", [](const UsingDirectiveDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("common_ancestor", &UsingDirectiveDecl::CommonAncestor)
    .def_property_readonly("identifier_token", &UsingDirectiveDecl::IdentifierToken)
    .def_property_readonly("namespace_key_token", &UsingDirectiveDecl::NamespaceKeyToken)
    .def_property_readonly("nominated_namespace", &UsingDirectiveDecl::NominatedNamespace)
    .def_property_readonly("nominated_namespace_as_written", &UsingDirectiveDecl::NominatedNamespaceAsWritten)
    .def_property_readonly("using_token", &UsingDirectiveDecl::UsingToken);
}
} // namespace pasta
