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

void RegisterUsingPackDecl(py::module_ &m) {
  py::class_<UsingPackDecl, Decl, NamedDecl>(m, "UsingPackDecl")
    .def("__hash__", [](const UsingPackDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UsingPackDecl& a, const UsingPackDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("Expansions", &UsingPackDecl::Expansions)
    .def_property_readonly("CanonicalDeclaration", &UsingPackDecl::CanonicalDeclaration)
    .def_property_readonly("InstantiatedFromUsingDeclaration", &UsingPackDecl::InstantiatedFromUsingDeclaration);
}
} // namespace pasta
