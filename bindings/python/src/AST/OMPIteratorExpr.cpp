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

void RegisterOMPIteratorExpr(py::module_ &m) {
  py::class_<OMPIteratorExpr, Expr>(m, "OMPIteratorExpr")
    .def("__hash__", [](const OMPIteratorExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &OMPIteratorExpr::Children)
    .def_property_readonly("begin_token", &OMPIteratorExpr::BeginToken)
    .def_property_readonly("end_token", &OMPIteratorExpr::EndToken)
    .def_property_readonly("iterator_kw_token", &OMPIteratorExpr::IteratorKwToken)
    .def_property_readonly("l_paren_token", &OMPIteratorExpr::LParenToken)
    .def_property_readonly("r_paren_token", &OMPIteratorExpr::RParenToken)
    .def_property_readonly("num_of_iterators", &OMPIteratorExpr::NumOfIterators);
}
} // namespace pasta
