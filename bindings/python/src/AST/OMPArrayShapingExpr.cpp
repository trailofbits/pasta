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

void RegisterOMPArrayShapingExpr(py::module_ &m) {
  py::class_<OMPArrayShapingExpr, Expr>(m, "OMPArrayShapingExpr")
    .def("__hash__", [](const OMPArrayShapingExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPArrayShapingExpr& a, const OMPArrayShapingExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &OMPArrayShapingExpr::Children)
    .def_property_readonly("Base", &OMPArrayShapingExpr::Base)
    .def_property_readonly("BeginToken", &OMPArrayShapingExpr::BeginToken)
    .def_property_readonly("BracketsRanges", &OMPArrayShapingExpr::BracketsRanges)
    .def_property_readonly("Dimensions", &OMPArrayShapingExpr::Dimensions)
    .def_property_readonly("EndToken", &OMPArrayShapingExpr::EndToken)
    .def_property_readonly("LParenToken", &OMPArrayShapingExpr::LParenToken)
    .def_property_readonly("RParenToken", &OMPArrayShapingExpr::RParenToken);
}
} // namespace pasta
