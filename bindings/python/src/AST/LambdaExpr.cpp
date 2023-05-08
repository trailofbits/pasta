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
    .def_property_readonly("children", &LambdaExpr::Children)
    .def_property_readonly("begin_token", &LambdaExpr::BeginToken)
    .def_property_readonly("body", &LambdaExpr::Body)
    .def_property_readonly("call_operator", &LambdaExpr::CallOperator)
    .def_property_readonly("capture_default", &LambdaExpr::CaptureDefault)
    .def_property_readonly("capture_default_token", &LambdaExpr::CaptureDefaultToken)
    .def_property_readonly("compound_statement_body", &LambdaExpr::CompoundStatementBody)
    .def_property_readonly("dependent_call_operator", &LambdaExpr::DependentCallOperator)
    .def_property_readonly("end_token", &LambdaExpr::EndToken)
    .def_property_readonly("explicit_template_parameters", &LambdaExpr::ExplicitTemplateParameters)
    .def_property_readonly("introducer_range", &LambdaExpr::IntroducerRange)
    .def_property_readonly("lambda_class", &LambdaExpr::LambdaClass)
    .def_property_readonly("template_parameter_list", &LambdaExpr::TemplateParameterList)
    .def_property_readonly("trailing_requires_clause", &LambdaExpr::TrailingRequiresClause)
    .def_property_readonly("has_explicit_parameters", &LambdaExpr::HasExplicitParameters)
    .def_property_readonly("has_explicit_result_type", &LambdaExpr::HasExplicitResultType)
    .def_property_readonly("is_generic_lambda", &LambdaExpr::IsGenericLambda)
    .def_property_readonly("is_mutable", &LambdaExpr::IsMutable);
}
} // namespace pasta
