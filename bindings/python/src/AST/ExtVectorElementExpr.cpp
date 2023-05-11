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

void RegisterExtVectorElementExpr(py::module_ &m) {
  py::class_<ExtVectorElementExpr, Expr>(m, "ExtVectorElementExpr")
    .def("__hash__", [](const ExtVectorElementExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ExtVectorElementExpr::Children)
    .def_property_readonly("contains_duplicate_elements", &ExtVectorElementExpr::ContainsDuplicateElements)
    .def_property_readonly("accessor_token", &ExtVectorElementExpr::AccessorToken)
    .def_property_readonly("base", &ExtVectorElementExpr::Base)
    .def_property_readonly("begin_token", &ExtVectorElementExpr::BeginToken)
    .def_property_readonly("end_token", &ExtVectorElementExpr::EndToken)
    .def_property_readonly("num_elements", &ExtVectorElementExpr::NumElements)
    .def_property_readonly("is_arrow", &ExtVectorElementExpr::IsArrow);
}
} // namespace pasta
