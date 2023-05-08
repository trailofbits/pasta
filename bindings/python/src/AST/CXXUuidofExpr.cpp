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

void RegisterCXXUuidofExpr(py::module_ &m) {
  py::class_<CXXUuidofExpr, Expr>(m, "CXXUuidofExpr")
    .def("__hash__", [](const CXXUuidofExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXUuidofExpr& a, const CXXUuidofExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &CXXUuidofExpr::Children)
    .def_property_readonly("BeginToken", &CXXUuidofExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXUuidofExpr::EndToken)
    .def_property_readonly("ExpressionOperand", &CXXUuidofExpr::ExpressionOperand)
    .def_property_readonly("GuidDeclaration", &CXXUuidofExpr::GuidDeclaration)
    .def_property_readonly("Tokens", &CXXUuidofExpr::Tokens)
    .def("TypeOperand", &CXXUuidofExpr::TypeOperand)
    .def_property_readonly("TypeOperandSourceInfo", &CXXUuidofExpr::TypeOperandSourceInfo)
    .def_property_readonly("IsTypeOperand", &CXXUuidofExpr::IsTypeOperand);
}
} // namespace pasta
