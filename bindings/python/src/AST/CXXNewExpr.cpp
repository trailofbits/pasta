/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCXXNewExpr(nb::module_ &m) {
  nb::class_<CXXNewExpr, Expr>(m, "CXXNewExpr")
    .def("__hash__", [](const CXXNewExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXNewExpr::Children)
    .def_prop_ro("does_usual_array_delete_want_size", &CXXNewExpr::DoesUsualArrayDeleteWantSize)
    .def_prop_ro("allocated_type", &CXXNewExpr::AllocatedType)
    .def_prop_ro("array_size", &CXXNewExpr::ArraySize)
    .def_prop_ro("begin_token", &CXXNewExpr::BeginToken)
    .def_prop_ro("construct_expression", &CXXNewExpr::ConstructExpression)
    .def_prop_ro("direct_initializer_range", &CXXNewExpr::DirectInitializerRange)
    .def_prop_ro("end_token", &CXXNewExpr::EndToken)
    .def_prop_ro("initialization_style", &CXXNewExpr::InitializationStyle)
    .def_prop_ro("initializer", &CXXNewExpr::Initializer)
    .def_prop_ro("num_placement_arguments", &CXXNewExpr::NumPlacementArguments)
    .def_prop_ro("operator_delete", &CXXNewExpr::OperatorDelete)
    .def_prop_ro("operator_new", &CXXNewExpr::OperatorNew)
    .def_prop_ro("tokens", &CXXNewExpr::Tokens)
    .def_prop_ro("type_id_parentheses", &CXXNewExpr::TypeIdParentheses)
    .def_prop_ro("has_initializer", &CXXNewExpr::HasInitializer)
    .def_prop_ro("is_array", &CXXNewExpr::IsArray)
    .def_prop_ro("is_global_new", &CXXNewExpr::IsGlobalNew)
    .def_prop_ro("is_parenthesis_type_id", &CXXNewExpr::IsParenthesisTypeId)
    .def_prop_ro("pass_alignment", &CXXNewExpr::PassAlignment)
    .def_prop_ro("placement_arguments", &CXXNewExpr::PlacementArguments)
    .def_prop_ro("should_null_check_allocation", &CXXNewExpr::ShouldNullCheckAllocation);
}
} // namespace pasta
