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

void RegisterCoroutineSuspendExpr(py::module_ &m) {
  py::class_<CoroutineSuspendExpr, Expr, Stmt, ValueStmt>(m, "CoroutineSuspendExpr")
    .def_property_readonly("Children", &CoroutineSuspendExpr::Children)
    .def_property_readonly("BeginToken", &CoroutineSuspendExpr::BeginToken)
    .def_property_readonly("CommonExpression", &CoroutineSuspendExpr::CommonExpression)
    .def_property_readonly("EndToken", &CoroutineSuspendExpr::EndToken)
    .def_property_readonly("KeywordToken", &CoroutineSuspendExpr::KeywordToken)
    .def_property_readonly("OpaqueValue", &CoroutineSuspendExpr::OpaqueValue)
    .def_property_readonly("Operand", &CoroutineSuspendExpr::Operand)
    .def_property_readonly("ReadyExpression", &CoroutineSuspendExpr::ReadyExpression)
    .def_property_readonly("ResumeExpression", &CoroutineSuspendExpr::ResumeExpression)
    .def_property_readonly("SuspendExpression", &CoroutineSuspendExpr::SuspendExpression);
}
} // namespace pasta
