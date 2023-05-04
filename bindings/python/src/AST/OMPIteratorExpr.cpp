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

void RegisterOMPIteratorExpr(py::module_ &m) {
  py::class_<OMPIteratorExpr, Expr, Stmt, ValueStmt>(m, "OMPIteratorExpr")
    .def_property_readonly("Children", &OMPIteratorExpr::Children)
    .def_property_readonly("BeginToken", &OMPIteratorExpr::BeginToken)
    .def_property_readonly("EndToken", &OMPIteratorExpr::EndToken)
    .def_property_readonly("IteratorKwToken", &OMPIteratorExpr::IteratorKwToken)
    .def_property_readonly("LParenToken", &OMPIteratorExpr::LParenToken)
    .def_property_readonly("RParenToken", &OMPIteratorExpr::RParenToken)
    .def_property_readonly("NumOfIterators", &OMPIteratorExpr::NumOfIterators);
}
} // namespace pasta
