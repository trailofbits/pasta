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

void RegisterDefaultStmt(py::module_ &m) {
  py::class_<DefaultStmt, SwitchCase>(m, "DefaultStmt")
    .def("__hash__", [](const DefaultStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DefaultStmt& a, const DefaultStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &DefaultStmt::Children)
    .def_property_readonly("BeginToken", &DefaultStmt::BeginToken)
    .def_property_readonly("DefaultToken", &DefaultStmt::DefaultToken)
    .def_property_readonly("EndToken", &DefaultStmt::EndToken)
    .def_property_readonly("SubStatement", &DefaultStmt::SubStatement);
}
} // namespace pasta
