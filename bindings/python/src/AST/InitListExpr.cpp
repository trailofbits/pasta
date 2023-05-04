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

void RegisterInitListExpr(py::module_ &m) {
  py::class_<InitListExpr, Expr, Stmt, ValueStmt>(m, "InitListExpr")
    .def("__hash__", [](const InitListExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const InitListExpr& a, const InitListExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &InitListExpr::Children)
    .def_property_readonly("ArrayFiller", &InitListExpr::ArrayFiller)
    .def_property_readonly("BeginToken", &InitListExpr::BeginToken)
    .def_property_readonly("EndToken", &InitListExpr::EndToken)
    .def_property_readonly("InitializedFieldInUnion", &InitListExpr::InitializedFieldInUnion)
    .def_property_readonly("LBraceToken", &InitListExpr::LBraceToken)
    .def_property_readonly("NumInitializers", &InitListExpr::NumInitializers)
    .def_property_readonly("RBraceToken", &InitListExpr::RBraceToken)
    .def_property_readonly("SemanticForm", &InitListExpr::SemanticForm)
    .def_property_readonly("SyntacticForm", &InitListExpr::SyntacticForm)
    .def_property_readonly("HadArrayRangeDesignator", &InitListExpr::HadArrayRangeDesignator)
    .def_property_readonly("HasArrayFiller", &InitListExpr::HasArrayFiller)
    .def_property_readonly("Initializers", &InitListExpr::Initializers)
    .def_property_readonly("IsExplicit", &InitListExpr::IsExplicit)
    .def_property_readonly("IsSemanticForm", &InitListExpr::IsSemanticForm)
    .def_property_readonly("IsStringLiteralInitializer", &InitListExpr::IsStringLiteralInitializer)
    .def_property_readonly("IsSyntacticForm", &InitListExpr::IsSyntacticForm)
    .def_property_readonly("IsTransparent", &InitListExpr::IsTransparent);
}
} // namespace pasta
