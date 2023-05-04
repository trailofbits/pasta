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

void RegisterConstantExpr(py::module_ &m) {
  py::class_<ConstantExpr, Expr, FullExpr, Stmt, ValueStmt>(m, "ConstantExpr")
    .def_property_readonly("Children", &ConstantExpr::Children)
    .def_property_readonly("BeginToken", &ConstantExpr::BeginToken)
    .def_property_readonly("EndToken", &ConstantExpr::EndToken)
    .def_property_readonly("ResultAsAPSInt", &ConstantExpr::ResultAsAPSInt)
    .def_property_readonly("ResultStorageKind", &ConstantExpr::ResultStorageKind)
    .def_property_readonly("HasAPValueResult", &ConstantExpr::HasAPValueResult)
    .def_property_readonly("IsImmediateInvocation", &ConstantExpr::IsImmediateInvocation);
}
} // namespace pasta
