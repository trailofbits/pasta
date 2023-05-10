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

void RegisterCoroutineSuspendExpr(py::module_ &m) {
  py::class_<CoroutineSuspendExpr, Expr>(m, "CoroutineSuspendExpr")
    .def("__hash__", [](const CoroutineSuspendExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CoroutineSuspendExpr& a, const CoroutineSuspendExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CoroutineSuspendExpr::Children)
    .def_property_readonly("begin_token", &CoroutineSuspendExpr::BeginToken)
    .def_property_readonly("common_expression", &CoroutineSuspendExpr::CommonExpression)
    .def_property_readonly("end_token", &CoroutineSuspendExpr::EndToken)
    .def_property_readonly("keyword_token", &CoroutineSuspendExpr::KeywordToken)
    .def_property_readonly("opaque_value", &CoroutineSuspendExpr::OpaqueValue)
    .def_property_readonly("operand", &CoroutineSuspendExpr::Operand)
    .def_property_readonly("ready_expression", &CoroutineSuspendExpr::ReadyExpression)
    .def_property_readonly("resume_expression", &CoroutineSuspendExpr::ResumeExpression)
    .def_property_readonly("suspend_expression", &CoroutineSuspendExpr::SuspendExpression);
}
} // namespace pasta
