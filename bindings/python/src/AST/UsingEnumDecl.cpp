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

void RegisterUsingEnumDecl(nb::module_ &m) {
  nb::class_<UsingEnumDecl, BaseUsingDecl>(m, "UsingEnumDecl")
    .def("__hash__", [](const UsingEnumDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &UsingEnumDecl::CanonicalDeclaration)
    .def_prop_ro("enum_declaration", &UsingEnumDecl::EnumDeclaration)
    .def_prop_ro("enum_token", &UsingEnumDecl::EnumToken)
    .def_prop_ro("enum_type", &UsingEnumDecl::EnumType)
    .def_prop_ro("using_token", &UsingEnumDecl::UsingToken);
}
} // namespace pasta
