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

void RegisterObjCIndirectCopyRestoreExpr(py::module_ &m) {
  py::class_<ObjCIndirectCopyRestoreExpr, Expr>(m, "ObjCIndirectCopyRestoreExpr")
    .def("__hash__", [](const ObjCIndirectCopyRestoreExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCIndirectCopyRestoreExpr& a, const ObjCIndirectCopyRestoreExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCIndirectCopyRestoreExpr::Children)
    .def_property_readonly("begin_token", &ObjCIndirectCopyRestoreExpr::BeginToken)
    .def_property_readonly("end_token", &ObjCIndirectCopyRestoreExpr::EndToken)
    .def_property_readonly("expression_token", &ObjCIndirectCopyRestoreExpr::ExpressionToken)
    .def_property_readonly("sub_expression", &ObjCIndirectCopyRestoreExpr::SubExpression)
    .def_property_readonly("should_copy", &ObjCIndirectCopyRestoreExpr::ShouldCopy);
}
} // namespace pasta
