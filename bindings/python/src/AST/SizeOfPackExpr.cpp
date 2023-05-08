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
    .def_property_readonly("Children", &SizeOfPackExpr::Children)
    .def_property_readonly("BeginToken", &SizeOfPackExpr::BeginToken)
    .def_property_readonly("EndToken", &SizeOfPackExpr::EndToken)
    .def_property_readonly("OperatorToken", &SizeOfPackExpr::OperatorToken)
    .def_property_readonly("Pack", &SizeOfPackExpr::Pack)
    .def_property_readonly("PackLength", &SizeOfPackExpr::PackLength)
    .def_property_readonly("PackToken", &SizeOfPackExpr::PackToken)
    .def_property_readonly("PartialArguments", &SizeOfPackExpr::PartialArguments)
    .def_property_readonly("RParenToken", &SizeOfPackExpr::RParenToken)
    .def_property_readonly("IsPartiallySubstituted", &SizeOfPackExpr::IsPartiallySubstituted);
}
} // namespace pasta
