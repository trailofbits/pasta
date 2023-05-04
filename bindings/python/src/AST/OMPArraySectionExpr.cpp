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
  py::class_<OMPArraySectionExpr, Expr, Stmt, ValueStmt>(m, "OMPArraySectionExpr")
    .def("__hash__", [](const OMPArraySectionExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPArraySectionExpr& a, const OMPArraySectionExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &OMPArraySectionExpr::Children)
    .def_property_readonly("Base", &OMPArraySectionExpr::Base)
    .def_property_readonly("BeginToken", &OMPArraySectionExpr::BeginToken)
    .def_property_readonly("FirstColonToken", &OMPArraySectionExpr::FirstColonToken)
    .def_property_readonly("SecondColonToken", &OMPArraySectionExpr::SecondColonToken)
    .def_property_readonly("EndToken", &OMPArraySectionExpr::EndToken)
    .def_property_readonly("ExpressionToken", &OMPArraySectionExpr::ExpressionToken)
    .def_property_readonly("Length", &OMPArraySectionExpr::Length)
    .def_property_readonly("LowerBound", &OMPArraySectionExpr::LowerBound)
    .def_property_readonly("RBracketToken", &OMPArraySectionExpr::RBracketToken)
    .def_property_readonly("Stride", &OMPArraySectionExpr::Stride);
}
} // namespace pasta
