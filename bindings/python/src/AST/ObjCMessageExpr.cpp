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

void RegisterObjCMessageExpr(py::module_ &m) {
  py::class_<ObjCMessageExpr, Expr>(m, "ObjCMessageExpr")
    .def("__hash__", [](const ObjCMessageExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("arguments", &ObjCMessageExpr::Arguments)
    .def_property_readonly("children", &ObjCMessageExpr::Children)
    .def_property_readonly("begin_token", &ObjCMessageExpr::BeginToken)
    .def("call_return_type", &ObjCMessageExpr::CallReturnType)
    .def_property_readonly("class_receiver", &ObjCMessageExpr::ClassReceiver)
    .def_property_readonly("class_receiver_type", &ObjCMessageExpr::ClassReceiverType)
    .def_property_readonly("end_token", &ObjCMessageExpr::EndToken)
    .def_property_readonly("instance_receiver", &ObjCMessageExpr::InstanceReceiver)
    .def_property_readonly("left_token", &ObjCMessageExpr::LeftToken)
    .def_property_readonly("method_declaration", &ObjCMessageExpr::MethodDeclaration)
    .def_property_readonly("method_family", &ObjCMessageExpr::MethodFamily)
    .def_property_readonly("num_arguments", &ObjCMessageExpr::NumArguments)
    .def_property_readonly("num_selector_tokens", &ObjCMessageExpr::NumSelectorTokens)
    .def_property_readonly("receiver_interface", &ObjCMessageExpr::ReceiverInterface)
    .def_property_readonly("receiver_kind", &ObjCMessageExpr::ReceiverKind)
    .def_property_readonly("receiver_range", &ObjCMessageExpr::ReceiverRange)
    .def_property_readonly("receiver_type", &ObjCMessageExpr::ReceiverType)
    .def_property_readonly("right_token", &ObjCMessageExpr::RightToken)
    .def_property_readonly("selector_start_token", &ObjCMessageExpr::SelectorStartToken)
    .def_property_readonly("super_token", &ObjCMessageExpr::SuperToken)
    .def_property_readonly("super_type", &ObjCMessageExpr::SuperType)
    .def_property_readonly("is_class_message", &ObjCMessageExpr::IsClassMessage)
    .def_property_readonly("is_delegate_initializer_call", &ObjCMessageExpr::IsDelegateInitializerCall)
    .def_property_readonly("is_implicit", &ObjCMessageExpr::IsImplicit)
    .def_property_readonly("is_instance_message", &ObjCMessageExpr::IsInstanceMessage);
}
} // namespace pasta
