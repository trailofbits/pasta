/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterTypedefNameDecl(nb::module_ &m) {
  nb::class_<TypedefNameDecl, TypeDecl>(m, "TypedefNameDecl")
    .def("__hash__", [](const TypedefNameDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("anonymous_declaration_with_typedef_name", &TypedefNameDecl::AnonymousDeclarationWithTypedefName)
    .def_prop_ro("canonical_declaration", &TypedefNameDecl::CanonicalDeclaration)
    .def_prop_ro("type", &TypedefNameDecl::Type)
    .def_prop_ro("underlying_type", &TypedefNameDecl::UnderlyingType)
    .def_prop_ro("is_moded", &TypedefNameDecl::IsModed)
    .def_prop_ro("is_transparent_tag", &TypedefNameDecl::IsTransparentTag);
}
} // namespace pasta
