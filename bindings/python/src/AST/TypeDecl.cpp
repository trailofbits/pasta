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

void RegisterTypeDecl(py::module_ &m) {
  py::class_<TypeDecl, NamedDecl>(m, "TypeDecl")
    .def("__hash__", [](const TypeDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TypeDecl& a, const TypeDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("BeginToken", &TypeDecl::BeginToken)
    .def_property_readonly("TypeForDeclaration", &TypeDecl::TypeForDeclaration);
}
} // namespace pasta
