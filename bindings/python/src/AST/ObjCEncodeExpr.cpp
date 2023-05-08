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
    .def_property_readonly("Children", &ObjCEncodeExpr::Children)
    .def_property_readonly("AtToken", &ObjCEncodeExpr::AtToken)
    .def_property_readonly("BeginToken", &ObjCEncodeExpr::BeginToken)
    .def_property_readonly("EncodedType", &ObjCEncodeExpr::EncodedType)
    .def_property_readonly("EndToken", &ObjCEncodeExpr::EndToken)
    .def_property_readonly("RParenToken", &ObjCEncodeExpr::RParenToken);
}
} // namespace pasta
