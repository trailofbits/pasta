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

void RegisterConstantExpr(py::module_ &m) {
  py::class_<ConstantExpr, FullExpr>(m, "ConstantExpr")
    .def("__hash__", [](const ConstantExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ConstantExpr& a, const ConstantExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ConstantExpr::Children)
    .def_property_readonly("begin_token", &ConstantExpr::BeginToken)
    .def_property_readonly("end_token", &ConstantExpr::EndToken)
    .def_property_readonly("result_as_aps_int", &ConstantExpr::ResultAsAPSInt)
    .def_property_readonly("result_storage_kind", &ConstantExpr::ResultStorageKind)
    .def_property_readonly("has_ap_value_result", &ConstantExpr::HasAPValueResult)
    .def_property_readonly("is_immediate_invocation", &ConstantExpr::IsImmediateInvocation);
}
} // namespace pasta
