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

void RegisterObjCPropertyRefExpr(py::module_ &m) {
  py::class_<ObjCPropertyRefExpr, Expr, Stmt, ValueStmt>(m, "ObjCPropertyRefExpr")
    .def("__hash__", [](const ObjCPropertyRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCPropertyRefExpr& a, const ObjCPropertyRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCPropertyRefExpr::Children)
    .def_property_readonly("Base", &ObjCPropertyRefExpr::Base)
    .def_property_readonly("BeginToken", &ObjCPropertyRefExpr::BeginToken)
    .def_property_readonly("ClassReceiver", &ObjCPropertyRefExpr::ClassReceiver)
    .def_property_readonly("EndToken", &ObjCPropertyRefExpr::EndToken)
    .def_property_readonly("ExplicitProperty", &ObjCPropertyRefExpr::ExplicitProperty)
    .def_property_readonly("ImplicitPropertyGetter", &ObjCPropertyRefExpr::ImplicitPropertyGetter)
    .def_property_readonly("ImplicitPropertySetter", &ObjCPropertyRefExpr::ImplicitPropertySetter)
    .def_property_readonly("Token", &ObjCPropertyRefExpr::Token)
    .def_property_readonly("ReceiverToken", &ObjCPropertyRefExpr::ReceiverToken)
    .def("ReceiverType", &ObjCPropertyRefExpr::ReceiverType)
    .def_property_readonly("SuperReceiverType", &ObjCPropertyRefExpr::SuperReceiverType)
    .def_property_readonly("IsClassReceiver", &ObjCPropertyRefExpr::IsClassReceiver)
    .def_property_readonly("IsExplicitProperty", &ObjCPropertyRefExpr::IsExplicitProperty)
    .def_property_readonly("IsImplicitProperty", &ObjCPropertyRefExpr::IsImplicitProperty)
    .def_property_readonly("IsMessagingGetter", &ObjCPropertyRefExpr::IsMessagingGetter)
    .def_property_readonly("IsMessagingSetter", &ObjCPropertyRefExpr::IsMessagingSetter)
    .def_property_readonly("IsObjectReceiver", &ObjCPropertyRefExpr::IsObjectReceiver)
    .def_property_readonly("IsSuperReceiver", &ObjCPropertyRefExpr::IsSuperReceiver);
}
} // namespace pasta
