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

void RegisterTypedefNameDecl(py::module_ &m) {
  py::class_<TypedefNameDecl, Decl, NamedDecl, TypeDecl>(m, "TypedefNameDecl")
    .def("__hash__", [](const TypedefNameDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TypedefNameDecl& a, const TypedefNameDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AnonymousDeclarationWithTypedefName", &TypedefNameDecl::AnonymousDeclarationWithTypedefName)
    .def_property_readonly("CanonicalDeclaration", &TypedefNameDecl::CanonicalDeclaration)
    .def_property_readonly("Type", &TypedefNameDecl::Type)
    .def_property_readonly("UnderlyingType", &TypedefNameDecl::UnderlyingType)
    .def_property_readonly("IsModed", &TypedefNameDecl::IsModed)
    .def_property_readonly("IsTransparentTag", &TypedefNameDecl::IsTransparentTag);
}
} // namespace pasta
