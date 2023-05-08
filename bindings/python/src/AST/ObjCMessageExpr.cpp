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

void RegisterObjCMessageExpr(py::module_ &m) {
  py::class_<ObjCMessageExpr, Expr>(m, "ObjCMessageExpr")
    .def("__hash__", [](const ObjCMessageExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCMessageExpr& a, const ObjCMessageExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Arguments", &ObjCMessageExpr::Arguments)
    .def_property_readonly("Children", &ObjCMessageExpr::Children)
    .def_property_readonly("BeginToken", &ObjCMessageExpr::BeginToken)
    .def("CallReturnType", &ObjCMessageExpr::CallReturnType)
    .def_property_readonly("ClassReceiver", &ObjCMessageExpr::ClassReceiver)
    .def_property_readonly("ClassReceiverType", &ObjCMessageExpr::ClassReceiverType)
    .def_property_readonly("EndToken", &ObjCMessageExpr::EndToken)
    .def_property_readonly("InstanceReceiver", &ObjCMessageExpr::InstanceReceiver)
    .def_property_readonly("LeftToken", &ObjCMessageExpr::LeftToken)
    .def_property_readonly("MethodDeclaration", &ObjCMessageExpr::MethodDeclaration)
    .def_property_readonly("MethodFamily", &ObjCMessageExpr::MethodFamily)
    .def_property_readonly("NumArguments", &ObjCMessageExpr::NumArguments)
    .def_property_readonly("NumSelectorTokens", &ObjCMessageExpr::NumSelectorTokens)
    .def_property_readonly("ReceiverInterface", &ObjCMessageExpr::ReceiverInterface)
    .def_property_readonly("ReceiverKind", &ObjCMessageExpr::ReceiverKind)
    .def_property_readonly("ReceiverRange", &ObjCMessageExpr::ReceiverRange)
    .def_property_readonly("ReceiverType", &ObjCMessageExpr::ReceiverType)
    .def_property_readonly("RightToken", &ObjCMessageExpr::RightToken)
    .def_property_readonly("SelectorStartToken", &ObjCMessageExpr::SelectorStartToken)
    .def_property_readonly("SuperToken", &ObjCMessageExpr::SuperToken)
    .def_property_readonly("SuperType", &ObjCMessageExpr::SuperType)
    .def_property_readonly("IsClassMessage", &ObjCMessageExpr::IsClassMessage)
    .def_property_readonly("IsDelegateInitializerCall", &ObjCMessageExpr::IsDelegateInitializerCall)
    .def_property_readonly("IsImplicit", &ObjCMessageExpr::IsImplicit)
    .def_property_readonly("IsInstanceMessage", &ObjCMessageExpr::IsInstanceMessage);
}
} // namespace pasta
