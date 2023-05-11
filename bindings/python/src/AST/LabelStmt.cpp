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

void RegisterLabelStmt(py::module_ &m) {
  py::class_<LabelStmt, ValueStmt>(m, "LabelStmt")
    .def("__hash__", [](const LabelStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &LabelStmt::Children)
    .def_property_readonly("begin_token", &LabelStmt::BeginToken)
    .def_property_readonly("declaration", &LabelStmt::Declaration)
    .def_property_readonly("end_token", &LabelStmt::EndToken)
    .def_property_readonly("identifier_token", &LabelStmt::IdentifierToken)
    .def_property_readonly("name", &LabelStmt::Name)
    .def_property_readonly("sub_statement", &LabelStmt::SubStatement)
    .def_property_readonly("is_side_entry", &LabelStmt::IsSideEntry);
}
} // namespace pasta
