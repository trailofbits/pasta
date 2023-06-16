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

void RegisterUnresolvedLookupExpr(nb::module_ &m) {
  nb::class_<UnresolvedLookupExpr, OverloadExpr>(m, "UnresolvedLookupExpr")
    .def("__hash__", [](const UnresolvedLookupExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &UnresolvedLookupExpr::Children)
    .def_prop_ro("begin_token", &UnresolvedLookupExpr::BeginToken)
    .def_prop_ro("end_token", &UnresolvedLookupExpr::EndToken)
    .def_prop_ro("naming_class", &UnresolvedLookupExpr::NamingClass)
    .def_prop_ro("is_overloaded", &UnresolvedLookupExpr::IsOverloaded)
    .def_prop_ro("requires_adl", &UnresolvedLookupExpr::RequiresADL);
}
} // namespace pasta
