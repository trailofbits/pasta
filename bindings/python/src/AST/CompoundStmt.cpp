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

void RegisterCompoundStmt(py::module_ &m) {
  py::class_<CompoundStmt, Stmt>(m, "CompoundStmt")
    .def("__hash__", [](const CompoundStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CompoundStmt& a, const CompoundStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CompoundStmt::Children)
    .def_property_readonly("BeginToken", &CompoundStmt::BeginToken)
    .def_property_readonly("EndToken", &CompoundStmt::EndToken)
    .def_property_readonly("LeftBraceToken", &CompoundStmt::LeftBraceToken)
    .def_property_readonly("RightBraceToken", &CompoundStmt::RightBraceToken)
    .def_property_readonly("StatementExpressionResult", &CompoundStmt::StatementExpressionResult)
    .def_property_readonly("HasStoredFPFeatures", &CompoundStmt::HasStoredFPFeatures)
    .def_property_readonly("Size", &CompoundStmt::Size);
}
} // namespace pasta
