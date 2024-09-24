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

void RegisterCallExpr(nb::module_ &m) {
  nb::class_<CallExpr, Expr>(m, "CallExpr")
    .def_prop_ro("arguments", &CallExpr::Arguments)
    .def_prop_ro("children", &CallExpr::Children)
    .def_prop_ro("adl_call_kind", &CallExpr::ADLCallKind)
    .def_prop_ro("begin_token", &CallExpr::BeginToken)
    .def_prop_ro("builtin_callee", &CallExpr::BuiltinCallee)
    .def_prop_ro("call_return_type", &CallExpr::CallReturnType)
    .def_prop_ro("callee", &CallExpr::Callee)
    .def_prop_ro("callee_declaration", &CallExpr::CalleeDeclaration)
    .def_prop_ro("direct_callee", &CallExpr::DirectCallee)
    .def_prop_ro("end_token", &CallExpr::EndToken)
    .def_prop_ro("num_arguments", &CallExpr::NumArguments)
    .def_prop_ro("r_paren_token", &CallExpr::RParenToken)
    .def_prop_ro("unused_result_attribute", &CallExpr::UnusedResultAttribute)
    .def_prop_ro("has_stored_fp_features", &CallExpr::HasStoredFPFeatures)
    .def_prop_ro("has_unused_result_attribute", &CallExpr::HasUnusedResultAttribute)
    .def_prop_ro("is_builtin_assume_false", &CallExpr::IsBuiltinAssumeFalse)
    .def_prop_ro("is_call_to_std_move", &CallExpr::IsCallToStdMove)
    .def_prop_ro("is_unevaluated_builtin_call", &CallExpr::IsUnevaluatedBuiltinCall)
    .def_prop_ro("uses_adl", &CallExpr::UsesADL);
}
} // namespace pasta
