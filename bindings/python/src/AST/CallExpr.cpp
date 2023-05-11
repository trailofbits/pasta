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

void RegisterCallExpr(py::module_ &m) {
  py::class_<CallExpr, Expr>(m, "CallExpr")
    .def("__hash__", [](const CallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("arguments", &CallExpr::Arguments)
    .def_property_readonly("children", &CallExpr::Children)
    .def_property_readonly("adl_call_kind", &CallExpr::ADLCallKind)
    .def_property_readonly("begin_token", &CallExpr::BeginToken)
    .def_property_readonly("builtin_callee", &CallExpr::BuiltinCallee)
    .def("call_return_type", &CallExpr::CallReturnType)
    .def_property_readonly("callee", &CallExpr::Callee)
    .def_property_readonly("callee_declaration", &CallExpr::CalleeDeclaration)
    .def_property_readonly("direct_callee", &CallExpr::DirectCallee)
    .def_property_readonly("end_token", &CallExpr::EndToken)
    .def_property_readonly("num_arguments", &CallExpr::NumArguments)
    .def_property_readonly("r_paren_token", &CallExpr::RParenToken)
    .def("unused_result_attribute", &CallExpr::UnusedResultAttribute)
    .def_property_readonly("has_stored_fp_features", &CallExpr::HasStoredFPFeatures)
    .def("has_unused_result_attribute", &CallExpr::HasUnusedResultAttribute)
    .def("is_builtin_assume_false", &CallExpr::IsBuiltinAssumeFalse)
    .def_property_readonly("is_call_to_std_move", &CallExpr::IsCallToStdMove)
    .def("is_unevaluated_builtin_call", &CallExpr::IsUnevaluatedBuiltinCall)
    .def_property_readonly("uses_adl", &CallExpr::UsesADL);
}
} // namespace pasta
