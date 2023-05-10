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

void RegisterExpr(py::module_ &m) {
  py::class_<Expr, ValueStmt>(m, "Expr")
    .def("__hash__", [](const Expr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Expr& a, const Expr& b) { return a.RawStmt() == b.RawStmt(); })
    .def("classify_l_value", &Expr::ClassifyLValue)
    .def("evaluate_known_const_int", &Expr::EvaluateKnownConstInt)
    .def("evaluate_known_const_int_check_overflow", &Expr::EvaluateKnownConstIntCheckOverflow)
    .def("has_side_effects", &Expr::HasSideEffects)
    .def_property_readonly("ignore_casts", &Expr::IgnoreCasts)
    .def_property_readonly("ignore_conversion_operator_single_step", &Expr::IgnoreConversionOperatorSingleStep)
    .def_property_readonly("ignore_implicit_casts", &Expr::IgnoreImplicitCasts)
    .def_property_readonly("ignore_implicit", &Expr::IgnoreImplicit)
    .def_property_readonly("ignore_implicit_as_written", &Expr::IgnoreImplicitAsWritten)
    .def_property_readonly("ignore_parenthesis_base_casts", &Expr::IgnoreParenthesisBaseCasts)
    .def_property_readonly("ignore_parenthesis_casts", &Expr::IgnoreParenthesisCasts)
    .def_property_readonly("ignore_parenthesis_implicit_casts", &Expr::IgnoreParenthesisImplicitCasts)
    .def_property_readonly("ignore_parenthesis_l_value_casts", &Expr::IgnoreParenthesisLValueCasts)
    .def("ignore_parenthesis_noop_casts", &Expr::IgnoreParenthesisNoopCasts)
    .def_property_readonly("ignore_parentheses", &Expr::IgnoreParentheses)
    .def_property_readonly("ignore_unless_spelled_in_source", &Expr::IgnoreUnlessSpelledInSource)
    .def_property_readonly("contains_errors", &Expr::ContainsErrors)
    .def_property_readonly("contains_unexpanded_parameter_pack", &Expr::ContainsUnexpandedParameterPack)
    .def("as_builtin_constant_declaration_reference", &Expr::AsBuiltinConstantDeclarationReference)
    .def_property_readonly("best_dynamic_class_type", &Expr::BestDynamicClassType)
    .def_property_readonly("best_dynamic_class_type_expression", &Expr::BestDynamicClassTypeExpression)
    .def_property_readonly("dependence", &Expr::Dependence)
    .def_property_readonly("expression_token", &Expr::ExpressionToken)
    .def_property_readonly("obj_c_property", &Expr::ObjCProperty)
    .def_property_readonly("object_kind", &Expr::ObjectKind)
    .def_property_readonly("referenced_declaration_of_callee", &Expr::ReferencedDeclarationOfCallee)
    .def_property_readonly("source_bit_field", &Expr::SourceBitField)
    .def_property_readonly("type", &Expr::Type)
    .def_property_readonly("value_kind", &Expr::ValueKind)
    .def("has_non_trivial_call", &Expr::HasNonTrivialCall)
    .def("is_bound_member_function", &Expr::IsBoundMemberFunction)
    .def("is_cxx11_constant_expression", &Expr::IsCXX11ConstantExpression)
    .def("is_cxx98_integral_constant_expression", &Expr::IsCXX98IntegralConstantExpression)
    .def_property_readonly("is_default_argument", &Expr::IsDefaultArgument)
    .def("is_evaluatable", &Expr::IsEvaluatable)
    .def_property_readonly("is_gl_value", &Expr::IsGLValue)
    .def_property_readonly("is_implicit_cxx_this", &Expr::IsImplicitCXXThis)
    .def_property_readonly("is_instantiation_dependent", &Expr::IsInstantiationDependent)
    .def("is_integer_constant_expression", &Expr::IsIntegerConstantExpression)
    .def_property_readonly("is_known_to_have_boolean_value", &Expr::IsKnownToHaveBooleanValue)
    .def_property_readonly("is_l_value", &Expr::IsLValue)
    .def("is_modifiable_lvalue", &Expr::IsModifiableLvalue)
    .def("is_objcgc_candidate", &Expr::IsOBJCGCCandidate)
    .def_property_readonly("is_obj_c_self_expression", &Expr::IsObjCSelfExpression)
    .def_property_readonly("is_ordinary_or_bit_field_object", &Expr::IsOrdinaryOrBitFieldObject)
    .def_property_readonly("is_pr_value", &Expr::IsPRValue)
    .def_property_readonly("is_read_if_discarded_in_c_plus_plus11", &Expr::IsReadIfDiscardedInCPlusPlus11)
    .def_property_readonly("is_type_dependent", &Expr::IsTypeDependent)
    .def_property_readonly("is_value_dependent", &Expr::IsValueDependent)
    .def_property_readonly("is_x_value", &Expr::IsXValue)
    .def_property_readonly("refers_to_bit_field", &Expr::RefersToBitField)
    .def_property_readonly("refers_to_global_register_variable", &Expr::RefersToGlobalRegisterVariable)
    .def_property_readonly("refers_to_matrix_element", &Expr::RefersToMatrixElement)
    .def_property_readonly("refers_to_vector_element", &Expr::RefersToVectorElement);
}
} // namespace pasta
