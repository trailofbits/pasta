/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCPropertyRefExpr(nb::module_ &m) {
  nb::class_<ObjCPropertyRefExpr, Expr>(m, "ObjCPropertyRefExpr")
    .def("__hash__", [](const ObjCPropertyRefExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCPropertyRefExpr::Children)
    .def_prop_ro("base", &ObjCPropertyRefExpr::Base)
    .def_prop_ro("begin_token", &ObjCPropertyRefExpr::BeginToken)
    .def_prop_ro("class_receiver", &ObjCPropertyRefExpr::ClassReceiver)
    .def_prop_ro("end_token", &ObjCPropertyRefExpr::EndToken)
    .def_prop_ro("explicit_property", &ObjCPropertyRefExpr::ExplicitProperty)
    .def_prop_ro("implicit_property_getter", &ObjCPropertyRefExpr::ImplicitPropertyGetter)
    .def_prop_ro("implicit_property_setter", &ObjCPropertyRefExpr::ImplicitPropertySetter)
    .def_prop_ro("token", &ObjCPropertyRefExpr::Token)
    .def_prop_ro("receiver_token", &ObjCPropertyRefExpr::ReceiverToken)
    .def_prop_ro("receiver_type", &ObjCPropertyRefExpr::ReceiverType)
    .def_prop_ro("super_receiver_type", &ObjCPropertyRefExpr::SuperReceiverType)
    .def_prop_ro("is_class_receiver", &ObjCPropertyRefExpr::IsClassReceiver)
    .def_prop_ro("is_explicit_property", &ObjCPropertyRefExpr::IsExplicitProperty)
    .def_prop_ro("is_implicit_property", &ObjCPropertyRefExpr::IsImplicitProperty)
    .def_prop_ro("is_messaging_getter", &ObjCPropertyRefExpr::IsMessagingGetter)
    .def_prop_ro("is_messaging_setter", &ObjCPropertyRefExpr::IsMessagingSetter)
    .def_prop_ro("is_object_receiver", &ObjCPropertyRefExpr::IsObjectReceiver)
    .def_prop_ro("is_super_receiver", &ObjCPropertyRefExpr::IsSuperReceiver);
}
} // namespace pasta
