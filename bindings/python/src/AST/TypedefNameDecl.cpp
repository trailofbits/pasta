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

void RegisterTypedefNameDecl(py::module_ &m) {
  py::class_<TypedefNameDecl, TypeDecl>(m, "TypedefNameDecl")
    .def("__hash__", [](const TypedefNameDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TypedefNameDecl& a, const TypedefNameDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("anonymous_declaration_with_typedef_name", &TypedefNameDecl::AnonymousDeclarationWithTypedefName)
    .def_property_readonly("canonical_declaration", &TypedefNameDecl::CanonicalDeclaration)
    .def_property_readonly("type", &TypedefNameDecl::Type)
    .def_property_readonly("underlying_type", &TypedefNameDecl::UnderlyingType)
    .def_property_readonly("is_moded", &TypedefNameDecl::IsModed)
    .def_property_readonly("is_transparent_tag", &TypedefNameDecl::IsTransparentTag);
}
} // namespace pasta
