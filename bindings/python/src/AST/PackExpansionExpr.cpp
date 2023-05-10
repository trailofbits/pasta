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

void RegisterPackExpansionExpr(py::module_ &m) {
  py::class_<PackExpansionExpr, Expr>(m, "PackExpansionExpr")
    .def("__hash__", [](const PackExpansionExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const PackExpansionExpr& a, const PackExpansionExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &PackExpansionExpr::Children)
    .def_property_readonly("begin_token", &PackExpansionExpr::BeginToken)
    .def_property_readonly("ellipsis_token", &PackExpansionExpr::EllipsisToken)
    .def_property_readonly("end_token", &PackExpansionExpr::EndToken)
    .def_property_readonly("num_expansions", &PackExpansionExpr::NumExpansions)
    .def_property_readonly("pattern", &PackExpansionExpr::Pattern);
}
} // namespace pasta
