/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterCompoundStmt(py::module_ &m) {
  py::class_<CompoundStmt, Stmt>(m, "CompoundStmt")
    .def("__hash__", [](const CompoundStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CompoundStmt::Children)
    .def_property_readonly("begin_token", &CompoundStmt::BeginToken)
    .def_property_readonly("end_token", &CompoundStmt::EndToken)
    .def_property_readonly("left_brace_token", &CompoundStmt::LeftBraceToken)
    .def_property_readonly("right_brace_token", &CompoundStmt::RightBraceToken)
    .def_property_readonly("statement_expression_result", &CompoundStmt::StatementExpressionResult)
    .def_property_readonly("has_stored_fp_features", &CompoundStmt::HasStoredFPFeatures)
    .def_property_readonly("size", &CompoundStmt::Size);
}
} // namespace pasta
