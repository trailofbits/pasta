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

void RegisterRequiresExpr(py::module_ &m) {
  py::class_<RequiresExpr, Expr>(m, "RequiresExpr")
    .def("__hash__", [](const RequiresExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &RequiresExpr::Children)
    .def_property_readonly("begin_token", &RequiresExpr::BeginToken)
    .def_property_readonly("body", &RequiresExpr::Body)
    .def_property_readonly("end_token", &RequiresExpr::EndToken)
    .def_property_readonly("local_parameters", &RequiresExpr::LocalParameters)
    .def_property_readonly("r_brace_token", &RequiresExpr::RBraceToken)
    .def_property_readonly("requires_keyword_token", &RequiresExpr::RequiresKeywordToken)
    .def_property_readonly("is_satisfied", &RequiresExpr::IsSatisfied);
}
} // namespace pasta
