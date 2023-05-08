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
    .def_property_readonly("Children", &GenericSelectionExpr::Children)
    .def_property_readonly("AssociationExpressions", &GenericSelectionExpr::AssociationExpressions)
    .def_property_readonly("BeginToken", &GenericSelectionExpr::BeginToken)
    .def_property_readonly("ControllingExpression", &GenericSelectionExpr::ControllingExpression)
    .def_property_readonly("DefaultToken", &GenericSelectionExpr::DefaultToken)
    .def_property_readonly("EndToken", &GenericSelectionExpr::EndToken)
    .def_property_readonly("GenericToken", &GenericSelectionExpr::GenericToken)
    .def_property_readonly("NumAssociations", &GenericSelectionExpr::NumAssociations)
    .def_property_readonly("RParenToken", &GenericSelectionExpr::RParenToken)
    .def_property_readonly("ResultExpression", &GenericSelectionExpr::ResultExpression)
    .def_property_readonly("ResultIndex", &GenericSelectionExpr::ResultIndex)
    .def_property_readonly("IsResultDependent", &GenericSelectionExpr::IsResultDependent);
}
} // namespace pasta
