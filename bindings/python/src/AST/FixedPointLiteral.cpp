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

void RegisterFixedPointLiteral(py::module_ &m) {
  py::class_<FixedPointLiteral, Expr>(m, "FixedPointLiteral")
    .def("__hash__", [](const FixedPointLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const FixedPointLiteral& a, const FixedPointLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &FixedPointLiteral::Children)
    .def_property_readonly("begin_token", &FixedPointLiteral::BeginToken)
    .def_property_readonly("end_token", &FixedPointLiteral::EndToken)
    .def_property_readonly("token", &FixedPointLiteral::Token)
    .def_property_readonly("scale", &FixedPointLiteral::Scale);
}
} // namespace pasta
