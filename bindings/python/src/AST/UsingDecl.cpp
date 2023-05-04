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

void RegisterUsingDecl(py::module_ &m) {
  py::class_<UsingDecl, BaseUsingDecl, Decl, NamedDecl>(m, "UsingDecl")
    .def("__hash__", [](const UsingDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UsingDecl& a, const UsingDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &UsingDecl::CanonicalDeclaration)
    .def_property_readonly("UsingToken", &UsingDecl::UsingToken)
    .def_property_readonly("HasTypename", &UsingDecl::HasTypename)
    .def_property_readonly("IsAccessDeclaration", &UsingDecl::IsAccessDeclaration);
}
} // namespace pasta