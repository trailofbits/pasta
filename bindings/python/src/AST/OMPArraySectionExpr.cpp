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

void RegisterOMPArraySectionExpr(py::module_ &m) {
  py::class_<OMPArraySectionExpr, Expr>(m, "OMPArraySectionExpr")
    .def("__hash__", [](const OMPArraySectionExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPArraySectionExpr& a, const OMPArraySectionExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &OMPArraySectionExpr::Children)
    .def_property_readonly("base", &OMPArraySectionExpr::Base)
    .def_property_readonly("begin_token", &OMPArraySectionExpr::BeginToken)
    .def_property_readonly("first_colon_token", &OMPArraySectionExpr::FirstColonToken)
    .def_property_readonly("second_colon_token", &OMPArraySectionExpr::SecondColonToken)
    .def_property_readonly("end_token", &OMPArraySectionExpr::EndToken)
    .def_property_readonly("expression_token", &OMPArraySectionExpr::ExpressionToken)
    .def_property_readonly("length", &OMPArraySectionExpr::Length)
    .def_property_readonly("lower_bound", &OMPArraySectionExpr::LowerBound)
    .def_property_readonly("r_bracket_token", &OMPArraySectionExpr::RBracketToken)
    .def_property_readonly("stride", &OMPArraySectionExpr::Stride);
}
} // namespace pasta
