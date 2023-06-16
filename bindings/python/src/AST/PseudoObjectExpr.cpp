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

void RegisterPseudoObjectExpr(nb::module_ &m) {
  nb::class_<PseudoObjectExpr, Expr>(m, "PseudoObjectExpr")
    .def("__hash__", [](const PseudoObjectExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &PseudoObjectExpr::Children)
    .def_prop_ro("begin_token", &PseudoObjectExpr::BeginToken)
    .def_prop_ro("end_token", &PseudoObjectExpr::EndToken)
    .def_prop_ro("expression_token", &PseudoObjectExpr::ExpressionToken)
    .def_prop_ro("num_semantic_expressions", &PseudoObjectExpr::NumSemanticExpressions)
    .def_prop_ro("result_expression", &PseudoObjectExpr::ResultExpression)
    .def_prop_ro("result_expression_index", &PseudoObjectExpr::ResultExpressionIndex)
    .def_prop_ro("syntactic_form", &PseudoObjectExpr::SyntacticForm)
    .def_prop_ro("semantics", &PseudoObjectExpr::Semantics);
}
} // namespace pasta
