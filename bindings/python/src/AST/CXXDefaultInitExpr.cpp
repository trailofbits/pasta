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

void RegisterCXXDefaultInitExpr(py::module_ &m) {
  py::class_<CXXDefaultInitExpr, Expr, Stmt, ValueStmt>(m, "CXXDefaultInitExpr")
    .def_property_readonly("Children", &CXXDefaultInitExpr::Children)
    .def_property_readonly("BeginToken", &CXXDefaultInitExpr::BeginToken)
    .def_property_readonly("EndToken", &CXXDefaultInitExpr::EndToken)
    .def_property_readonly("Expression", &CXXDefaultInitExpr::Expression)
    .def_property_readonly("Field", &CXXDefaultInitExpr::Field)
    .def_property_readonly("RewrittenExpression", &CXXDefaultInitExpr::RewrittenExpression)
    .def_property_readonly("UsedContext", &CXXDefaultInitExpr::UsedContext)
    .def_property_readonly("UsedToken", &CXXDefaultInitExpr::UsedToken)
    .def_property_readonly("HasRewrittenInitializer", &CXXDefaultInitExpr::HasRewrittenInitializer);
}
} // namespace pasta
