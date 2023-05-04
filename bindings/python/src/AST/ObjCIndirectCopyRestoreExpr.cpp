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

void RegisterObjCIndirectCopyRestoreExpr(py::module_ &m) {
  py::class_<ObjCIndirectCopyRestoreExpr, Expr, Stmt, ValueStmt>(m, "ObjCIndirectCopyRestoreExpr")
    .def_property_readonly("Children", &ObjCIndirectCopyRestoreExpr::Children)
    .def_property_readonly("BeginToken", &ObjCIndirectCopyRestoreExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCIndirectCopyRestoreExpr::EndToken)
    .def_property_readonly("ExpressionToken", &ObjCIndirectCopyRestoreExpr::ExpressionToken)
    .def_property_readonly("SubExpression", &ObjCIndirectCopyRestoreExpr::SubExpression)
    .def_property_readonly("ShouldCopy", &ObjCIndirectCopyRestoreExpr::ShouldCopy);
}
} // namespace pasta
