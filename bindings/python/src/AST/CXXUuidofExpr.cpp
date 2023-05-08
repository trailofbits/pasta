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
    .def_property_readonly("children", &CXXUuidofExpr::Children)
    .def_property_readonly("begin_token", &CXXUuidofExpr::BeginToken)
    .def_property_readonly("end_token", &CXXUuidofExpr::EndToken)
    .def_property_readonly("expression_operand", &CXXUuidofExpr::ExpressionOperand)
    .def_property_readonly("guid_declaration", &CXXUuidofExpr::GuidDeclaration)
    .def_property_readonly("tokens", &CXXUuidofExpr::Tokens)
    .def("type_operand", &CXXUuidofExpr::TypeOperand)
    .def_property_readonly("type_operand_source_info", &CXXUuidofExpr::TypeOperandSourceInfo)
    .def_property_readonly("is_type_operand", &CXXUuidofExpr::IsTypeOperand);
}
} // namespace pasta
