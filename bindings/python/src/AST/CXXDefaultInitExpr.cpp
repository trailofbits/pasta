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

void RegisterCXXDefaultInitExpr(py::module_ &m) {
  py::class_<CXXDefaultInitExpr, Expr>(m, "CXXDefaultInitExpr")
    .def("__hash__", [](const CXXDefaultInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDefaultInitExpr& a, const CXXDefaultInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXDefaultInitExpr::Children)
    .def_property_readonly("begin_token", &CXXDefaultInitExpr::BeginToken)
    .def_property_readonly("end_token", &CXXDefaultInitExpr::EndToken)
    .def_property_readonly("expression", &CXXDefaultInitExpr::Expression)
    .def_property_readonly("field", &CXXDefaultInitExpr::Field)
    .def_property_readonly("rewritten_expression", &CXXDefaultInitExpr::RewrittenExpression)
    .def_property_readonly("used_context", &CXXDefaultInitExpr::UsedContext)
    .def_property_readonly("used_token", &CXXDefaultInitExpr::UsedToken)
    .def_property_readonly("has_rewritten_initializer", &CXXDefaultInitExpr::HasRewrittenInitializer);
}
} // namespace pasta
