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

void RegisterSizeOfPackExpr(py::module_ &m) {
  py::class_<SizeOfPackExpr, Expr>(m, "SizeOfPackExpr")
    .def("__hash__", [](const SizeOfPackExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SizeOfPackExpr& a, const SizeOfPackExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &SizeOfPackExpr::Children)
    .def_property_readonly("begin_token", &SizeOfPackExpr::BeginToken)
    .def_property_readonly("end_token", &SizeOfPackExpr::EndToken)
    .def_property_readonly("operator_token", &SizeOfPackExpr::OperatorToken)
    .def_property_readonly("pack", &SizeOfPackExpr::Pack)
    .def_property_readonly("pack_length", &SizeOfPackExpr::PackLength)
    .def_property_readonly("pack_token", &SizeOfPackExpr::PackToken)
    .def_property_readonly("partial_arguments", &SizeOfPackExpr::PartialArguments)
    .def_property_readonly("r_paren_token", &SizeOfPackExpr::RParenToken)
    .def_property_readonly("is_partially_substituted", &SizeOfPackExpr::IsPartiallySubstituted);
}
} // namespace pasta
