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

void RegisterCaseStmt(py::module_ &m) {
  py::class_<CaseStmt, SwitchCase>(m, "CaseStmt")
    .def("__hash__", [](const CaseStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CaseStmt& a, const CaseStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("case_statement_is_gnu_range", &CaseStmt::CaseStatementIsGNURange)
    .def_property_readonly("children", &CaseStmt::Children)
    .def_property_readonly("begin_token", &CaseStmt::BeginToken)
    .def_property_readonly("case_token", &CaseStmt::CaseToken)
    .def_property_readonly("ellipsis_token", &CaseStmt::EllipsisToken)
    .def_property_readonly("end_token", &CaseStmt::EndToken)
    .def_property_readonly("lhs", &CaseStmt::LHS)
    .def_property_readonly("rhs", &CaseStmt::RHS)
    .def_property_readonly("sub_statement", &CaseStmt::SubStatement);
}
} // namespace pasta
