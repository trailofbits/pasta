/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCallExpr(nb::module_ &m) {
  nb::class_<CallExpr, Expr>(m, "CallExpr")
    .def("__hash__", [](const CallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("arguments", &CallExpr::Arguments)
    .def_prop_ro("children", &CallExpr::Children)
    .def_prop_ro("adl_call_kind", &CallExpr::ADLCallKind)
    .def_prop_ro("begin_token", &CallExpr::BeginToken)
    .def_prop_ro("builtin_callee", &CallExpr::BuiltinCallee)
    .def("call_return_type", &CallExpr::CallReturnType)
    .def_prop_ro("callee", &CallExpr::Callee)
    .def_prop_ro("callee_declaration", &CallExpr::CalleeDeclaration)
    .def_prop_ro("direct_callee", &CallExpr::DirectCallee)
    .def_prop_ro("end_token", &CallExpr::EndToken)
    .def_prop_ro("num_arguments", &CallExpr::NumArguments)
    .def_prop_ro("r_paren_token", &CallExpr::RParenToken)
    .def("unused_result_attribute", &CallExpr::UnusedResultAttribute)
    .def_prop_ro("has_stored_fp_features", &CallExpr::HasStoredFPFeatures)
    .def("has_unused_result_attribute", &CallExpr::HasUnusedResultAttribute)
    .def("is_builtin_assume_false", &CallExpr::IsBuiltinAssumeFalse)
    .def_prop_ro("is_call_to_std_move", &CallExpr::IsCallToStdMove)
    .def("is_unevaluated_builtin_call", &CallExpr::IsUnevaluatedBuiltinCall)
    .def_prop_ro("uses_adl", &CallExpr::UsesADL);
}
} // namespace pasta
