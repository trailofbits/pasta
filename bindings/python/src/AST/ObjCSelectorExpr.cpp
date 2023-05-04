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

void RegisterObjCSelectorExpr(py::module_ &m) {
  py::class_<ObjCSelectorExpr, Expr, Stmt, ValueStmt>(m, "ObjCSelectorExpr")
    .def("__hash__", [](const ObjCSelectorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCSelectorExpr& a, const ObjCSelectorExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCSelectorExpr::Children)
    .def_property_readonly("AtToken", &ObjCSelectorExpr::AtToken)
    .def_property_readonly("BeginToken", &ObjCSelectorExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCSelectorExpr::EndToken)
    .def_property_readonly("NumArguments", &ObjCSelectorExpr::NumArguments)
    .def_property_readonly("RParenToken", &ObjCSelectorExpr::RParenToken);
}
} // namespace pasta
