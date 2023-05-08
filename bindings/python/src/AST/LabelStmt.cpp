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

void RegisterLabelStmt(py::module_ &m) {
  py::class_<LabelStmt, ValueStmt>(m, "LabelStmt")
    .def("__hash__", [](const LabelStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const LabelStmt& a, const LabelStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &LabelStmt::Children)
    .def_property_readonly("BeginToken", &LabelStmt::BeginToken)
    .def_property_readonly("Declaration", &LabelStmt::Declaration)
    .def_property_readonly("EndToken", &LabelStmt::EndToken)
    .def_property_readonly("IdentifierToken", &LabelStmt::IdentifierToken)
    .def_property_readonly("Name", &LabelStmt::Name)
    .def_property_readonly("SubStatement", &LabelStmt::SubStatement)
    .def_property_readonly("IsSideEntry", &LabelStmt::IsSideEntry);
}
} // namespace pasta
