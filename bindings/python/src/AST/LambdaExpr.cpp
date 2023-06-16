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

void RegisterLambdaExpr(nb::module_ &m) {
  nb::class_<LambdaExpr, Expr>(m, "LambdaExpr")
    .def("__hash__", [](const LambdaExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &LambdaExpr::Children)
    .def_prop_ro("begin_token", &LambdaExpr::BeginToken)
    .def_prop_ro("body", &LambdaExpr::Body)
    .def_prop_ro("call_operator", &LambdaExpr::CallOperator)
    .def_prop_ro("capture_default", &LambdaExpr::CaptureDefault)
    .def_prop_ro("capture_default_token", &LambdaExpr::CaptureDefaultToken)
    .def_prop_ro("compound_statement_body", &LambdaExpr::CompoundStatementBody)
    .def_prop_ro("dependent_call_operator", &LambdaExpr::DependentCallOperator)
    .def_prop_ro("end_token", &LambdaExpr::EndToken)
    .def_prop_ro("explicit_template_parameters", &LambdaExpr::ExplicitTemplateParameters)
    .def_prop_ro("introducer_range", &LambdaExpr::IntroducerRange)
    .def_prop_ro("lambda_class", &LambdaExpr::LambdaClass)
    .def_prop_ro("template_parameter_list", &LambdaExpr::TemplateParameterList)
    .def_prop_ro("trailing_requires_clause", &LambdaExpr::TrailingRequiresClause)
    .def_prop_ro("has_explicit_parameters", &LambdaExpr::HasExplicitParameters)
    .def_prop_ro("has_explicit_result_type", &LambdaExpr::HasExplicitResultType)
    .def_prop_ro("is_generic_lambda", &LambdaExpr::IsGenericLambda)
    .def_prop_ro("is_mutable", &LambdaExpr::IsMutable);
}
} // namespace pasta
