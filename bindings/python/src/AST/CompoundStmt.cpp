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

void RegisterCompoundStmt(nb::module_ &m) {
  nb::class_<CompoundStmt, Stmt>(m, "CompoundStmt")
    .def("__hash__", [](const CompoundStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CompoundStmt::Children)
    .def_prop_ro("begin_token", &CompoundStmt::BeginToken)
    .def_prop_ro("end_token", &CompoundStmt::EndToken)
    .def_prop_ro("left_brace_token", &CompoundStmt::LeftBraceToken)
    .def_prop_ro("right_brace_token", &CompoundStmt::RightBraceToken)
    .def_prop_ro("statement_expression_result", &CompoundStmt::StatementExpressionResult)
    .def_prop_ro("has_stored_fp_features", &CompoundStmt::HasStoredFPFeatures)
    .def_prop_ro("size", &CompoundStmt::Size);
}
} // namespace pasta
