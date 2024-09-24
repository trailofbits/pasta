/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCMessageExpr(nb::module_ &m) {
  nb::class_<ObjCMessageExpr, Expr>(m, "ObjCMessageExpr")
    .def_prop_ro("arguments", &ObjCMessageExpr::Arguments)
    .def_prop_ro("children", &ObjCMessageExpr::Children)
    .def_prop_ro("begin_token", &ObjCMessageExpr::BeginToken)
    .def_prop_ro("call_return_type", &ObjCMessageExpr::CallReturnType)
    .def_prop_ro("class_receiver", &ObjCMessageExpr::ClassReceiver)
    .def_prop_ro("end_token", &ObjCMessageExpr::EndToken)
    .def_prop_ro("instance_receiver", &ObjCMessageExpr::InstanceReceiver)
    .def_prop_ro("left_token", &ObjCMessageExpr::LeftToken)
    .def_prop_ro("method_declaration", &ObjCMessageExpr::MethodDeclaration)
    .def_prop_ro("method_family", &ObjCMessageExpr::MethodFamily)
    .def_prop_ro("num_arguments", &ObjCMessageExpr::NumArguments)
    .def_prop_ro("num_selector_tokens", &ObjCMessageExpr::NumSelectorTokens)
    .def_prop_ro("receiver_interface", &ObjCMessageExpr::ReceiverInterface)
    .def_prop_ro("receiver_kind", &ObjCMessageExpr::ReceiverKind)
    .def_prop_ro("receiver_range", &ObjCMessageExpr::ReceiverRange)
    .def_prop_ro("receiver_type", &ObjCMessageExpr::ReceiverType)
    .def_prop_ro("right_token", &ObjCMessageExpr::RightToken)
    .def_prop_ro("selector_start_token", &ObjCMessageExpr::SelectorStartToken)
    .def_prop_ro("super_token", &ObjCMessageExpr::SuperToken)
    .def_prop_ro("super_type", &ObjCMessageExpr::SuperType)
    .def_prop_ro("is_class_message", &ObjCMessageExpr::IsClassMessage)
    .def_prop_ro("is_delegate_initializer_call", &ObjCMessageExpr::IsDelegateInitializerCall)
    .def_prop_ro("is_implicit", &ObjCMessageExpr::IsImplicit)
    .def_prop_ro("is_instance_message", &ObjCMessageExpr::IsInstanceMessage);
}
} // namespace pasta
