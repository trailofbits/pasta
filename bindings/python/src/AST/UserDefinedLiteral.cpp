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

void RegisterUserDefinedLiteral(py::module_ &m) {
  py::class_<UserDefinedLiteral, CallExpr>(m, "UserDefinedLiteral")
    .def("__hash__", [](const UserDefinedLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &UserDefinedLiteral::BeginToken)
    .def_property_readonly("cooked_literal", &UserDefinedLiteral::CookedLiteral)
    .def_property_readonly("end_token", &UserDefinedLiteral::EndToken)
    .def_property_readonly("literal_operator_kind", &UserDefinedLiteral::LiteralOperatorKind)
    .def_property_readonly("ud_suffix_token", &UserDefinedLiteral::UDSuffixToken);
}
} // namespace pasta
