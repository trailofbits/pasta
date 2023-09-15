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

void RegisterExprWithCleanups(nb::module_ &m) {
  nb::class_<ExprWithCleanups, FullExpr>(m, "ExprWithCleanups")
    .def("__hash__", [](const ExprWithCleanups& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ExprWithCleanups::Children)
    .def_prop_ro("cleanups_have_side_effects", &ExprWithCleanups::CleanupsHaveSideEffects)
    .def_prop_ro("begin_token", &ExprWithCleanups::BeginToken)
    .def_prop_ro("end_token", &ExprWithCleanups::EndToken)
    .def_prop_ro("num_objects", &ExprWithCleanups::NumObjects);
}
} // namespace pasta
