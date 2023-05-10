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

void RegisterObjCPropertyRefExpr(py::module_ &m) {
  py::class_<ObjCPropertyRefExpr, Expr>(m, "ObjCPropertyRefExpr")
    .def("__hash__", [](const ObjCPropertyRefExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCPropertyRefExpr& a, const ObjCPropertyRefExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCPropertyRefExpr::Children)
    .def_property_readonly("base", &ObjCPropertyRefExpr::Base)
    .def_property_readonly("begin_token", &ObjCPropertyRefExpr::BeginToken)
    .def_property_readonly("class_receiver", &ObjCPropertyRefExpr::ClassReceiver)
    .def_property_readonly("end_token", &ObjCPropertyRefExpr::EndToken)
    .def_property_readonly("explicit_property", &ObjCPropertyRefExpr::ExplicitProperty)
    .def_property_readonly("implicit_property_getter", &ObjCPropertyRefExpr::ImplicitPropertyGetter)
    .def_property_readonly("implicit_property_setter", &ObjCPropertyRefExpr::ImplicitPropertySetter)
    .def_property_readonly("token", &ObjCPropertyRefExpr::Token)
    .def_property_readonly("receiver_token", &ObjCPropertyRefExpr::ReceiverToken)
    .def("receiver_type", &ObjCPropertyRefExpr::ReceiverType)
    .def_property_readonly("super_receiver_type", &ObjCPropertyRefExpr::SuperReceiverType)
    .def_property_readonly("is_class_receiver", &ObjCPropertyRefExpr::IsClassReceiver)
    .def_property_readonly("is_explicit_property", &ObjCPropertyRefExpr::IsExplicitProperty)
    .def_property_readonly("is_implicit_property", &ObjCPropertyRefExpr::IsImplicitProperty)
    .def_property_readonly("is_messaging_getter", &ObjCPropertyRefExpr::IsMessagingGetter)
    .def_property_readonly("is_messaging_setter", &ObjCPropertyRefExpr::IsMessagingSetter)
    .def_property_readonly("is_object_receiver", &ObjCPropertyRefExpr::IsObjectReceiver)
    .def_property_readonly("is_super_receiver", &ObjCPropertyRefExpr::IsSuperReceiver);
}
} // namespace pasta
