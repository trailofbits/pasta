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

void RegisterUnresolvedUsingValueDecl(nb::module_ &m) {
  nb::class_<UnresolvedUsingValueDecl, ValueDecl>(m, "UnresolvedUsingValueDecl")
    .def("__hash__", [](const UnresolvedUsingValueDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &UnresolvedUsingValueDecl::CanonicalDeclaration)
    .def_prop_ro("ellipsis_token", &UnresolvedUsingValueDecl::EllipsisToken)
    .def_prop_ro("using_token", &UnresolvedUsingValueDecl::UsingToken)
    .def_prop_ro("is_access_declaration", &UnresolvedUsingValueDecl::IsAccessDeclaration)
    .def_prop_ro("is_pack_expansion", &UnresolvedUsingValueDecl::IsPackExpansion);
}
} // namespace pasta
