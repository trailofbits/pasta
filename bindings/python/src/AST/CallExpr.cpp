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

void RegisterCallExpr(py::module_ &m) {
  py::class_<CallExpr, Expr, Stmt, ValueStmt>(m, "CallExpr")
    .def("__hash__", [](const CallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CallExpr& a, const CallExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Arguments", &CallExpr::Arguments)
    .def_property_readonly("Children", &CallExpr::Children)
    .def_property_readonly("ADLCallKind", &CallExpr::ADLCallKind)
    .def_property_readonly("BeginToken", &CallExpr::BeginToken)
    .def_property_readonly("BuiltinCallee", &CallExpr::BuiltinCallee)
    .def("CallReturnType", &CallExpr::CallReturnType)
    .def_property_readonly("Callee", &CallExpr::Callee)
    .def_property_readonly("CalleeDeclaration", &CallExpr::CalleeDeclaration)
    .def_property_readonly("DirectCallee", &CallExpr::DirectCallee)
    .def_property_readonly("EndToken", &CallExpr::EndToken)
    .def_property_readonly("NumArguments", &CallExpr::NumArguments)
    .def_property_readonly("RParenToken", &CallExpr::RParenToken)
    .def("UnusedResultAttribute", &CallExpr::UnusedResultAttribute)
    .def_property_readonly("HasStoredFPFeatures", &CallExpr::HasStoredFPFeatures)
    .def("HasUnusedResultAttribute", &CallExpr::HasUnusedResultAttribute)
    .def("IsBuiltinAssumeFalse", &CallExpr::IsBuiltinAssumeFalse)
    .def_property_readonly("IsCallToStdMove", &CallExpr::IsCallToStdMove)
    .def("IsUnevaluatedBuiltinCall", &CallExpr::IsUnevaluatedBuiltinCall)
    .def_property_readonly("UsesADL", &CallExpr::UsesADL);
}
} // namespace pasta
