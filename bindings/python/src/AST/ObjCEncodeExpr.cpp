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

void RegisterObjCEncodeExpr(py::module_ &m) {
  py::class_<ObjCEncodeExpr, Expr>(m, "ObjCEncodeExpr")
    .def("__hash__", [](const ObjCEncodeExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCEncodeExpr& a, const ObjCEncodeExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCEncodeExpr::Children)
    .def_property_readonly("at_token", &ObjCEncodeExpr::AtToken)
    .def_property_readonly("begin_token", &ObjCEncodeExpr::BeginToken)
    .def_property_readonly("encoded_type", &ObjCEncodeExpr::EncodedType)
    .def_property_readonly("end_token", &ObjCEncodeExpr::EndToken)
    .def_property_readonly("r_paren_token", &ObjCEncodeExpr::RParenToken);
}
} // namespace pasta
