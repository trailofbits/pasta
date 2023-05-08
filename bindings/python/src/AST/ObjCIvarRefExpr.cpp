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

void RegisterObjCIvarRefExpr(py::module_ &m) {
  py::class_<ObjCIvarRefExpr, Expr>(m, "ObjCIvarRefExpr")
    .def("__hash__", [](const ObjCIvarRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCIvarRefExpr& a, const ObjCIvarRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCIvarRefExpr::Children)
    .def_property_readonly("Base", &ObjCIvarRefExpr::Base)
    .def_property_readonly("BeginToken", &ObjCIvarRefExpr::BeginToken)
    .def_property_readonly("Declaration", &ObjCIvarRefExpr::Declaration)
    .def_property_readonly("EndToken", &ObjCIvarRefExpr::EndToken)
    .def_property_readonly("Token", &ObjCIvarRefExpr::Token)
    .def_property_readonly("OperationToken", &ObjCIvarRefExpr::OperationToken)
    .def_property_readonly("IsArrow", &ObjCIvarRefExpr::IsArrow)
    .def_property_readonly("IsFreeInstanceVariable", &ObjCIvarRefExpr::IsFreeInstanceVariable);
}
} // namespace pasta
