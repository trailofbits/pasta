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

void RegisterImaginaryLiteral(py::module_ &m) {
  py::class_<ImaginaryLiteral, Expr>(m, "ImaginaryLiteral")
    .def("__hash__", [](const ImaginaryLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ImaginaryLiteral& a, const ImaginaryLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ImaginaryLiteral::Children)
    .def_property_readonly("BeginToken", &ImaginaryLiteral::BeginToken)
    .def_property_readonly("EndToken", &ImaginaryLiteral::EndToken)
    .def_property_readonly("SubExpression", &ImaginaryLiteral::SubExpression);
}
} // namespace pasta
