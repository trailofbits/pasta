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

void RegisterUnresolvedUsingTypenameDecl(nb::module_ &m) {
  nb::class_<UnresolvedUsingTypenameDecl, TypeDecl>(m, "UnresolvedUsingTypenameDecl")
    .def("__hash__", [](const UnresolvedUsingTypenameDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &UnresolvedUsingTypenameDecl::CanonicalDeclaration)
    .def_prop_ro("ellipsis_token", &UnresolvedUsingTypenameDecl::EllipsisToken)
    .def_prop_ro("typename_token", &UnresolvedUsingTypenameDecl::TypenameToken)
    .def_prop_ro("using_token", &UnresolvedUsingTypenameDecl::UsingToken)
    .def_prop_ro("is_pack_expansion", &UnresolvedUsingTypenameDecl::IsPackExpansion);
}
} // namespace pasta
