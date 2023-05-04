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

void RegisterUserDefinedLiteral(py::module_ &m) {
  py::class_<UserDefinedLiteral, CallExpr, Expr, Stmt, ValueStmt>(m, "UserDefinedLiteral")
    .def("__hash__", [](const UserDefinedLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const UserDefinedLiteral& a, const UserDefinedLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("BeginToken", &UserDefinedLiteral::BeginToken)
    .def_property_readonly("CookedLiteral", &UserDefinedLiteral::CookedLiteral)
    .def_property_readonly("EndToken", &UserDefinedLiteral::EndToken)
    .def_property_readonly("LiteralOperatorKind", &UserDefinedLiteral::LiteralOperatorKind)
    .def_property_readonly("UDSuffixToken", &UserDefinedLiteral::UDSuffixToken);
}
} // namespace pasta
