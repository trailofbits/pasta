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

void RegisterExpr(py::module_ &m) {
  py::class_<Expr, Stmt, ValueStmt>(m, "Expr")
    .def("__hash__", [](const Expr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Expr& a, const Expr& b) { return a.RawStmt() == b.RawStmt(); })
    .def("ClassifyLValue", &Expr::ClassifyLValue)
    .def("EvaluateKnownConstInt", &Expr::EvaluateKnownConstInt)
    .def("EvaluateKnownConstIntCheckOverflow", &Expr::EvaluateKnownConstIntCheckOverflow)
    .def("HasSideEffects", &Expr::HasSideEffects)
    .def_property_readonly("IgnoreCasts", &Expr::IgnoreCasts)
    .def_property_readonly("IgnoreConversionOperatorSingleStep", &Expr::IgnoreConversionOperatorSingleStep)
    .def_property_readonly("IgnoreImplicitCasts", &Expr::IgnoreImplicitCasts)
    .def_property_readonly("IgnoreImplicit", &Expr::IgnoreImplicit)
    .def_property_readonly("IgnoreImplicitAsWritten", &Expr::IgnoreImplicitAsWritten)
    .def_property_readonly("IgnoreParenthesisBaseCasts", &Expr::IgnoreParenthesisBaseCasts)
    .def_property_readonly("IgnoreParenthesisCasts", &Expr::IgnoreParenthesisCasts)
    .def_property_readonly("IgnoreParenthesisImplicitCasts", &Expr::IgnoreParenthesisImplicitCasts)
    .def_property_readonly("IgnoreParenthesisLValueCasts", &Expr::IgnoreParenthesisLValueCasts)
    .def("IgnoreParenthesisNoopCasts", &Expr::IgnoreParenthesisNoopCasts)
    .def_property_readonly("IgnoreParentheses", &Expr::IgnoreParentheses)
    .def_property_readonly("IgnoreUnlessSpelledInSource", &Expr::IgnoreUnlessSpelledInSource)
    .def_property_readonly("ContainsErrors", &Expr::ContainsErrors)
    .def_property_readonly("ContainsUnexpandedParameterPack", &Expr::ContainsUnexpandedParameterPack)
    .def("AsBuiltinConstantDeclarationReference", &Expr::AsBuiltinConstantDeclarationReference)
    .def_property_readonly("BestDynamicClassType", &Expr::BestDynamicClassType)
    .def_property_readonly("BestDynamicClassTypeExpression", &Expr::BestDynamicClassTypeExpression)
    .def_property_readonly("Dependence", &Expr::Dependence)
    .def_property_readonly("ExpressionToken", &Expr::ExpressionToken)
    .def_property_readonly("ObjCProperty", &Expr::ObjCProperty)
    .def_property_readonly("ObjectKind", &Expr::ObjectKind)
    .def_property_readonly("ReferencedDeclarationOfCallee", &Expr::ReferencedDeclarationOfCallee)
    .def_property_readonly("SourceBitField", &Expr::SourceBitField)
    .def_property_readonly("Type", &Expr::Type)
    .def_property_readonly("ValueKind", &Expr::ValueKind)
    .def("HasNonTrivialCall", &Expr::HasNonTrivialCall)
    .def("IsBoundMemberFunction", &Expr::IsBoundMemberFunction)
    .def("IsCXX11ConstantExpression", &Expr::IsCXX11ConstantExpression)
    .def("IsCXX98IntegralConstantExpression", &Expr::IsCXX98IntegralConstantExpression)
    .def_property_readonly("IsDefaultArgument", &Expr::IsDefaultArgument)
    .def("IsEvaluatable", &Expr::IsEvaluatable)
    .def_property_readonly("IsGLValue", &Expr::IsGLValue)
    .def_property_readonly("IsImplicitCXXThis", &Expr::IsImplicitCXXThis)
    .def_property_readonly("IsInstantiationDependent", &Expr::IsInstantiationDependent)
    .def("IsIntegerConstantExpression", &Expr::IsIntegerConstantExpression)
    .def_property_readonly("IsKnownToHaveBooleanValue", &Expr::IsKnownToHaveBooleanValue)
    .def_property_readonly("IsLValue", &Expr::IsLValue)
    .def("IsModifiableLvalue", &Expr::IsModifiableLvalue)
    .def("IsOBJCGCCandidate", &Expr::IsOBJCGCCandidate)
    .def_property_readonly("IsObjCSelfExpression", &Expr::IsObjCSelfExpression)
    .def_property_readonly("IsOrdinaryOrBitFieldObject", &Expr::IsOrdinaryOrBitFieldObject)
    .def_property_readonly("IsPRValue", &Expr::IsPRValue)
    .def_property_readonly("IsReadIfDiscardedInCPlusPlus11", &Expr::IsReadIfDiscardedInCPlusPlus11)
    .def_property_readonly("IsTypeDependent", &Expr::IsTypeDependent)
    .def_property_readonly("IsValueDependent", &Expr::IsValueDependent)
    .def_property_readonly("IsXValue", &Expr::IsXValue)
    .def_property_readonly("RefersToBitField", &Expr::RefersToBitField)
    .def_property_readonly("RefersToGlobalRegisterVariable", &Expr::RefersToGlobalRegisterVariable)
    .def_property_readonly("RefersToMatrixElement", &Expr::RefersToMatrixElement)
    .def_property_readonly("RefersToVectorElement", &Expr::RefersToVectorElement);
}
} // namespace pasta
