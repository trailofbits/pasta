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

void RegisterLifetimeExtendedTemporaryDecl(nb::module_ &m) {
  nb::class_<LifetimeExtendedTemporaryDecl, Decl>(m, "LifetimeExtendedTemporaryDecl")
    .def("__hash__", [](const LifetimeExtendedTemporaryDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("children", &LifetimeExtendedTemporaryDecl::Children)
    .def_prop_ro("extending_declaration", &LifetimeExtendedTemporaryDecl::ExtendingDeclaration)
    .def_prop_ro("mangling_number", &LifetimeExtendedTemporaryDecl::ManglingNumber)
    .def_prop_ro("storage_duration", &LifetimeExtendedTemporaryDecl::StorageDuration)
    .def_prop_ro("temporary_expression", &LifetimeExtendedTemporaryDecl::TemporaryExpression);
}
} // namespace pasta
