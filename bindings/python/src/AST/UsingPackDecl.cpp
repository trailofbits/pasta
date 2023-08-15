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

void RegisterUsingPackDecl(nb::module_ &m) {
  nb::class_<UsingPackDecl, NamedDecl>(m, "UsingPackDecl")
    .def("__hash__", [](const UsingPackDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("expansions", &UsingPackDecl::Expansions)
    .def_prop_ro("canonical_declaration", &UsingPackDecl::CanonicalDeclaration)
    .def_prop_ro("instantiated_from_using_declaration", &UsingPackDecl::InstantiatedFromUsingDeclaration);
}
} // namespace pasta
