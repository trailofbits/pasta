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

void RegisterUsingDecl(nb::module_ &m) {
  nb::class_<UsingDecl, BaseUsingDecl>(m, "UsingDecl")
    .def("__hash__", [](const UsingDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &UsingDecl::CanonicalDeclaration)
    .def_prop_ro("using_token", &UsingDecl::UsingToken)
    .def_prop_ro("has_typename", &UsingDecl::HasTypename)
    .def_prop_ro("is_access_declaration", &UsingDecl::IsAccessDeclaration);
}
} // namespace pasta
