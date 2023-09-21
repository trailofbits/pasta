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

void RegisterExpr(nb::module_ &m) {
  nb::class_<Expr, ValueStmt>(m, "Expr")
    .def("__hash__", [](const Expr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("classify_l_value", &Expr::ClassifyLValue)
    .def_prop_ro("evaluate_known_const_int", &Expr::EvaluateKnownConstInt)
    .def_prop_ro("evaluate_known_const_int_check_overflow", &Expr::EvaluateKnownConstIntCheckOverflow)
    .def_prop_ro("has_side_effects", &Expr::HasSideEffects)
    .def_prop_ro("ignore_casts", &Expr::IgnoreCasts)
    .def_prop_ro("ignore_conversion_operator_single_step", &Expr::IgnoreConversionOperatorSingleStep)
    .def_prop_ro("ignore_implicit_casts", &Expr::IgnoreImplicitCasts)
    .def_prop_ro("ignore_implicit", &Expr::IgnoreImplicit)
    .def_prop_ro("ignore_implicit_as_written", &Expr::IgnoreImplicitAsWritten)
    .def_prop_ro("ignore_parenthesis_base_casts", &Expr::IgnoreParenthesisBaseCasts)
    .def_prop_ro("ignore_parenthesis_casts", &Expr::IgnoreParenthesisCasts)
    .def_prop_ro("ignore_parenthesis_implicit_casts", &Expr::IgnoreParenthesisImplicitCasts)
    .def_prop_ro("ignore_parenthesis_l_value_casts", &Expr::IgnoreParenthesisLValueCasts)
    .def_prop_ro("ignore_parenthesis_noop_casts", &Expr::IgnoreParenthesisNoopCasts)
    .def_prop_ro("ignore_parentheses", &Expr::IgnoreParentheses)
    .def_prop_ro("ignore_unless_spelled_in_source", &Expr::IgnoreUnlessSpelledInSource)
    .def_prop_ro("contains_errors", &Expr::ContainsErrors)
    .def_prop_ro("contains_unexpanded_parameter_pack", &Expr::ContainsUnexpandedParameterPack)
    .def_prop_ro("as_builtin_constant_declaration_reference", &Expr::AsBuiltinConstantDeclarationReference)
    .def_prop_ro("best_dynamic_class_type", &Expr::BestDynamicClassType)
    .def_prop_ro("dependence", &Expr::Dependence)
    .def_prop_ro("expression_token", &Expr::ExpressionToken)
    .def_prop_ro("obj_c_property", &Expr::ObjCProperty)
    .def_prop_ro("object_kind", &Expr::ObjectKind)
    .def_prop_ro("referenced_declaration_of_callee", &Expr::ReferencedDeclarationOfCallee)
    .def_prop_ro("source_bit_field", &Expr::SourceBitField)
    .def_prop_ro("type", &Expr::Type)
    .def_prop_ro("value_kind", &Expr::ValueKind)
    .def_prop_ro("has_non_trivial_call", &Expr::HasNonTrivialCall)
    .def_prop_ro("is_bound_member_function", &Expr::IsBoundMemberFunction)
    .def_prop_ro("is_cxx11_constant_expression", &Expr::IsCXX11ConstantExpression)
    .def_prop_ro("is_cxx98_integral_constant_expression", &Expr::IsCXX98IntegralConstantExpression)
    .def_prop_ro("is_default_argument", &Expr::IsDefaultArgument)
    .def_prop_ro("is_evaluatable", &Expr::IsEvaluatable)
    .def_prop_ro("is_gl_value", &Expr::IsGLValue)
    .def_prop_ro("is_implicit_cxx_this", &Expr::IsImplicitCXXThis)
    .def_prop_ro("is_instantiation_dependent", &Expr::IsInstantiationDependent)
    .def_prop_ro("is_integer_constant_expression", &Expr::IsIntegerConstantExpression)
    .def_prop_ro("is_known_to_have_boolean_value", &Expr::IsKnownToHaveBooleanValue)
    .def_prop_ro("is_l_value", &Expr::IsLValue)
    .def_prop_ro("is_modifiable_lvalue", &Expr::IsModifiableLvalue)
    .def_prop_ro("is_objcgc_candidate", &Expr::IsOBJCGCCandidate)
    .def_prop_ro("is_obj_c_self_expression", &Expr::IsObjCSelfExpression)
    .def_prop_ro("is_ordinary_or_bit_field_object", &Expr::IsOrdinaryOrBitFieldObject)
    .def_prop_ro("is_pr_value", &Expr::IsPRValue)
    .def_prop_ro("is_read_if_discarded_in_c_plus_plus11", &Expr::IsReadIfDiscardedInCPlusPlus11)
    .def_prop_ro("is_type_dependent", &Expr::IsTypeDependent)
    .def_prop_ro("is_value_dependent", &Expr::IsValueDependent)
    .def_prop_ro("is_x_value", &Expr::IsXValue)
    .def_prop_ro("refers_to_bit_field", &Expr::RefersToBitField)
    .def_prop_ro("refers_to_global_register_variable", &Expr::RefersToGlobalRegisterVariable)
    .def_prop_ro("refers_to_matrix_element", &Expr::RefersToMatrixElement)
    .def_prop_ro("refers_to_vector_element", &Expr::RefersToVectorElement);
}
} // namespace pasta
