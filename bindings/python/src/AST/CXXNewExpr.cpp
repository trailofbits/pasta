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

void RegisterCXXNewExpr(py::module_ &m) {
  py::class_<CXXNewExpr, Expr>(m, "CXXNewExpr")
    .def("__hash__", [](const CXXNewExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXNewExpr& a, const CXXNewExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXNewExpr::Children)
    .def_property_readonly("does_usual_array_delete_want_size", &CXXNewExpr::DoesUsualArrayDeleteWantSize)
    .def_property_readonly("allocated_type", &CXXNewExpr::AllocatedType)
    .def_property_readonly("array_size", &CXXNewExpr::ArraySize)
    .def_property_readonly("begin_token", &CXXNewExpr::BeginToken)
    .def_property_readonly("construct_expression", &CXXNewExpr::ConstructExpression)
    .def_property_readonly("direct_initializer_range", &CXXNewExpr::DirectInitializerRange)
    .def_property_readonly("end_token", &CXXNewExpr::EndToken)
    .def_property_readonly("initialization_style", &CXXNewExpr::InitializationStyle)
    .def_property_readonly("initializer", &CXXNewExpr::Initializer)
    .def_property_readonly("num_placement_arguments", &CXXNewExpr::NumPlacementArguments)
    .def_property_readonly("operator_delete", &CXXNewExpr::OperatorDelete)
    .def_property_readonly("operator_new", &CXXNewExpr::OperatorNew)
    .def_property_readonly("tokens", &CXXNewExpr::Tokens)
    .def_property_readonly("type_id_parentheses", &CXXNewExpr::TypeIdParentheses)
    .def_property_readonly("has_initializer", &CXXNewExpr::HasInitializer)
    .def_property_readonly("is_array", &CXXNewExpr::IsArray)
    .def_property_readonly("is_global_new", &CXXNewExpr::IsGlobalNew)
    .def_property_readonly("is_parenthesis_type_id", &CXXNewExpr::IsParenthesisTypeId)
    .def_property_readonly("pass_alignment", &CXXNewExpr::PassAlignment)
    .def_property_readonly("placement_arguments", &CXXNewExpr::PlacementArguments)
    .def_property_readonly("should_null_check_allocation", &CXXNewExpr::ShouldNullCheckAllocation);
}
} // namespace pasta
