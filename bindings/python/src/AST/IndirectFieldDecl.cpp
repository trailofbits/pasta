/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterIndirectFieldDecl(nb::module_ &m) {
  nb::class_<IndirectFieldDecl, ValueDecl>(m, "IndirectFieldDecl")
    .def("__hash__", [](const IndirectFieldDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("chain", &IndirectFieldDecl::Chain)
    .def_prop_ro("anonymous_field", &IndirectFieldDecl::AnonymousField)
    .def_prop_ro("canonical_declaration", &IndirectFieldDecl::CanonicalDeclaration)
    .def_prop_ro("chaining_size", &IndirectFieldDecl::ChainingSize)
    .def_prop_ro("variable_declaration", &IndirectFieldDecl::VariableDeclaration);
}
} // namespace pasta
