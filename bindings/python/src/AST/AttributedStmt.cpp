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

void RegisterAttributedStmt(py::module_ &m) {
  py::class_<AttributedStmt, ValueStmt>(m, "AttributedStmt")
    .def("__hash__", [](const AttributedStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const AttributedStmt& a, const AttributedStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &AttributedStmt::Children)
    .def_property_readonly("AttributeToken", &AttributedStmt::AttributeToken)
    .def_property_readonly("Attributes", &AttributedStmt::Attributes)
    .def_property_readonly("BeginToken", &AttributedStmt::BeginToken)
    .def_property_readonly("EndToken", &AttributedStmt::EndToken)
    .def_property_readonly("SubStatement", &AttributedStmt::SubStatement);
}
} // namespace pasta
