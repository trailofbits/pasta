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

namespace pasta {
namespace py = pybind11;

void RegisterCaseStmt(py::module_ &m) {
  py::class_<CaseStmt, Stmt, SwitchCase>(m, "CaseStmt")
    .def("__hash__", [](const CaseStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CaseStmt& a, const CaseStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("CaseStatementIsGNURange", &CaseStmt::CaseStatementIsGNURange)
    .def_property_readonly("Children", &CaseStmt::Children)
    .def_property_readonly("BeginToken", &CaseStmt::BeginToken)
    .def_property_readonly("CaseToken", &CaseStmt::CaseToken)
    .def_property_readonly("EllipsisToken", &CaseStmt::EllipsisToken)
    .def_property_readonly("EndToken", &CaseStmt::EndToken)
    .def_property_readonly("LHS", &CaseStmt::LHS)
    .def_property_readonly("RHS", &CaseStmt::RHS)
    .def_property_readonly("SubStatement", &CaseStmt::SubStatement);
}
} // namespace pasta
