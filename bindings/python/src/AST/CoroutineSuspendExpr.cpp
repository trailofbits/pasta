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

void RegisterCoroutineSuspendExpr(nb::module_ &m) {
  nb::class_<CoroutineSuspendExpr, Expr>(m, "CoroutineSuspendExpr")
    .def_prop_ro("children", &CoroutineSuspendExpr::Children)
    .def_prop_ro("begin_token", &CoroutineSuspendExpr::BeginToken)
    .def_prop_ro("common_expression", &CoroutineSuspendExpr::CommonExpression)
    .def_prop_ro("end_token", &CoroutineSuspendExpr::EndToken)
    .def_prop_ro("keyword_token", &CoroutineSuspendExpr::KeywordToken)
    .def_prop_ro("opaque_value", &CoroutineSuspendExpr::OpaqueValue)
    .def_prop_ro("operand", &CoroutineSuspendExpr::Operand)
    .def_prop_ro("ready_expression", &CoroutineSuspendExpr::ReadyExpression)
    .def_prop_ro("resume_expression", &CoroutineSuspendExpr::ResumeExpression)
    .def_prop_ro("suspend_expression", &CoroutineSuspendExpr::SuspendExpression);
}
} // namespace pasta
