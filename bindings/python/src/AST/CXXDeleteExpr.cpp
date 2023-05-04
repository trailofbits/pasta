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

void RegisterCXXDeleteExpr(py::module_ &m) {
  py::class_<CXXDeleteExpr, Expr, Stmt, ValueStmt>(m, "CXXDeleteExpr")
    .def_property_readonly("Children", &CXXDeleteExpr::Children)
    .def_property_readonly("DoesUsualArrayDeleteWantSize", &CXXDeleteExpr::DoesUsualArrayDeleteWantSize)
    .def_property_readonly("Argument", &CXXDeleteExpr::Argument)
    .def_property_readonly("BeginToken", &CXXDeleteExpr::BeginToken)
    .def_property_readonly("DestroyedType", &CXXDeleteExpr::DestroyedType)
    .def_property_readonly("EndToken", &CXXDeleteExpr::EndToken)
    .def_property_readonly("OperatorDelete", &CXXDeleteExpr::OperatorDelete)
    .def_property_readonly("IsArrayForm", &CXXDeleteExpr::IsArrayForm)
    .def_property_readonly("IsArrayFormAsWritten", &CXXDeleteExpr::IsArrayFormAsWritten)
    .def_property_readonly("IsGlobalDelete", &CXXDeleteExpr::IsGlobalDelete);
}
} // namespace pasta
