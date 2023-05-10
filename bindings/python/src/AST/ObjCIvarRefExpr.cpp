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

void RegisterObjCIvarRefExpr(py::module_ &m) {
  py::class_<ObjCIvarRefExpr, Expr>(m, "ObjCIvarRefExpr")
    .def("__hash__", [](const ObjCIvarRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCIvarRefExpr& a, const ObjCIvarRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCIvarRefExpr::Children)
    .def_property_readonly("base", &ObjCIvarRefExpr::Base)
    .def_property_readonly("begin_token", &ObjCIvarRefExpr::BeginToken)
    .def_property_readonly("declaration", &ObjCIvarRefExpr::Declaration)
    .def_property_readonly("end_token", &ObjCIvarRefExpr::EndToken)
    .def_property_readonly("token", &ObjCIvarRefExpr::Token)
    .def_property_readonly("operation_token", &ObjCIvarRefExpr::OperationToken)
    .def_property_readonly("is_arrow", &ObjCIvarRefExpr::IsArrow)
    .def_property_readonly("is_free_instance_variable", &ObjCIvarRefExpr::IsFreeInstanceVariable);
}
} // namespace pasta
