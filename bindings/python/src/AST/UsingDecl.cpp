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

void RegisterUsingDecl(py::module_ &m) {
  py::class_<UsingDecl, BaseUsingDecl>(m, "UsingDecl")
    .def("__hash__", [](const UsingDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UsingDecl& a, const UsingDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &UsingDecl::CanonicalDeclaration)
    .def_property_readonly("using_token", &UsingDecl::UsingToken)
    .def_property_readonly("has_typename", &UsingDecl::HasTypename)
    .def_property_readonly("is_access_declaration", &UsingDecl::IsAccessDeclaration);
}
} // namespace pasta
