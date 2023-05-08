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
    .def_property_readonly("children", &OMPArrayShapingExpr::Children)
    .def_property_readonly("base", &OMPArrayShapingExpr::Base)
    .def_property_readonly("begin_token", &OMPArrayShapingExpr::BeginToken)
    .def_property_readonly("brackets_ranges", &OMPArrayShapingExpr::BracketsRanges)
    .def_property_readonly("dimensions", &OMPArrayShapingExpr::Dimensions)
    .def_property_readonly("end_token", &OMPArrayShapingExpr::EndToken)
    .def_property_readonly("l_paren_token", &OMPArrayShapingExpr::LParenToken)
    .def_property_readonly("r_paren_token", &OMPArrayShapingExpr::RParenToken);
}
} // namespace pasta
