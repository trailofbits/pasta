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

void RegisterExprWithCleanups(py::module_ &m) {
  py::class_<ExprWithCleanups, FullExpr>(m, "ExprWithCleanups")
    .def("__hash__", [](const ExprWithCleanups& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ExprWithCleanups& a, const ExprWithCleanups& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ExprWithCleanups::Children)
    .def_property_readonly("cleanups_have_side_effects", &ExprWithCleanups::CleanupsHaveSideEffects)
    .def_property_readonly("begin_token", &ExprWithCleanups::BeginToken)
    .def_property_readonly("end_token", &ExprWithCleanups::EndToken)
    .def_property_readonly("num_objects", &ExprWithCleanups::NumObjects);
}
} // namespace pasta
