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

void RegisterGenericSelectionExpr(py::module_ &m) {
  py::class_<GenericSelectionExpr, Expr>(m, "GenericSelectionExpr")
    .def("__hash__", [](const GenericSelectionExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const GenericSelectionExpr& a, const GenericSelectionExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &GenericSelectionExpr::Children)
    .def_property_readonly("association_expressions", &GenericSelectionExpr::AssociationExpressions)
    .def_property_readonly("begin_token", &GenericSelectionExpr::BeginToken)
    .def_property_readonly("controlling_expression", &GenericSelectionExpr::ControllingExpression)
    .def_property_readonly("default_token", &GenericSelectionExpr::DefaultToken)
    .def_property_readonly("end_token", &GenericSelectionExpr::EndToken)
    .def_property_readonly("generic_token", &GenericSelectionExpr::GenericToken)
    .def_property_readonly("num_associations", &GenericSelectionExpr::NumAssociations)
    .def_property_readonly("r_paren_token", &GenericSelectionExpr::RParenToken)
    .def_property_readonly("result_expression", &GenericSelectionExpr::ResultExpression)
    .def_property_readonly("result_index", &GenericSelectionExpr::ResultIndex)
    .def_property_readonly("is_result_dependent", &GenericSelectionExpr::IsResultDependent);
}
} // namespace pasta
