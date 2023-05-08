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

void RegisterLambdaExpr(py::module_ &m) {
  py::class_<LambdaExpr, Expr>(m, "LambdaExpr")
    .def("__hash__", [](const LambdaExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const LambdaExpr& a, const LambdaExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &LambdaExpr::Children)
    .def_property_readonly("BeginToken", &LambdaExpr::BeginToken)
    .def_property_readonly("Body", &LambdaExpr::Body)
    .def_property_readonly("CallOperator", &LambdaExpr::CallOperator)
    .def_property_readonly("CaptureDefault", &LambdaExpr::CaptureDefault)
    .def_property_readonly("CaptureDefaultToken", &LambdaExpr::CaptureDefaultToken)
    .def_property_readonly("CompoundStatementBody", &LambdaExpr::CompoundStatementBody)
    .def_property_readonly("DependentCallOperator", &LambdaExpr::DependentCallOperator)
    .def_property_readonly("EndToken", &LambdaExpr::EndToken)
    .def_property_readonly("ExplicitTemplateParameters", &LambdaExpr::ExplicitTemplateParameters)
    .def_property_readonly("IntroducerRange", &LambdaExpr::IntroducerRange)
    .def_property_readonly("LambdaClass", &LambdaExpr::LambdaClass)
    .def_property_readonly("TemplateParameterList", &LambdaExpr::TemplateParameterList)
    .def_property_readonly("TrailingRequiresClause", &LambdaExpr::TrailingRequiresClause)
    .def_property_readonly("HasExplicitParameters", &LambdaExpr::HasExplicitParameters)
    .def_property_readonly("HasExplicitResultType", &LambdaExpr::HasExplicitResultType)
    .def_property_readonly("IsGenericLambda", &LambdaExpr::IsGenericLambda)
    .def_property_readonly("IsMutable", &LambdaExpr::IsMutable);
}
} // namespace pasta
