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

void RegisterSEHExceptStmt(py::module_ &m) {
  py::class_<SEHExceptStmt, Stmt>(m, "SEHExceptStmt")
    .def("__hash__", [](const SEHExceptStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SEHExceptStmt& a, const SEHExceptStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &SEHExceptStmt::Children)
    .def_property_readonly("BeginToken", &SEHExceptStmt::BeginToken)
    .def_property_readonly("Block", &SEHExceptStmt::Block)
    .def_property_readonly("EndToken", &SEHExceptStmt::EndToken)
    .def_property_readonly("ExceptToken", &SEHExceptStmt::ExceptToken)
    .def_property_readonly("FilterExpression", &SEHExceptStmt::FilterExpression);
}
} // namespace pasta
