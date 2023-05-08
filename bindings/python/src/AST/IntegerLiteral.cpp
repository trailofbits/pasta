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

void RegisterIntegerLiteral(py::module_ &m) {
  py::class_<IntegerLiteral, Expr>(m, "IntegerLiteral")
    .def("__hash__", [](const IntegerLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const IntegerLiteral& a, const IntegerLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &IntegerLiteral::Children)
    .def_property_readonly("begin_token", &IntegerLiteral::BeginToken)
    .def_property_readonly("end_token", &IntegerLiteral::EndToken)
    .def_property_readonly("token", &IntegerLiteral::Token);
}
} // namespace pasta
