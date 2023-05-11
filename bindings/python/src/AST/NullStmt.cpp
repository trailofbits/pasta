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

void RegisterNullStmt(py::module_ &m) {
  py::class_<NullStmt, Stmt>(m, "NullStmt")
    .def("__hash__", [](const NullStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &NullStmt::Children)
    .def_property_readonly("begin_token", &NullStmt::BeginToken)
    .def_property_readonly("end_token", &NullStmt::EndToken)
    .def_property_readonly("semi_token", &NullStmt::SemiToken)
    .def_property_readonly("has_leading_empty_macro", &NullStmt::HasLeadingEmptyMacro);
}
} // namespace pasta
