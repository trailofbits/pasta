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

void RegisterObjCSelectorExpr(py::module_ &m) {
  py::class_<ObjCSelectorExpr, Expr>(m, "ObjCSelectorExpr")
    .def("__hash__", [](const ObjCSelectorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCSelectorExpr::Children)
    .def_property_readonly("at_token", &ObjCSelectorExpr::AtToken)
    .def_property_readonly("begin_token", &ObjCSelectorExpr::BeginToken)
    .def_property_readonly("end_token", &ObjCSelectorExpr::EndToken)
    .def_property_readonly("num_arguments", &ObjCSelectorExpr::NumArguments)
    .def_property_readonly("r_paren_token", &ObjCSelectorExpr::RParenToken);
}
} // namespace pasta
