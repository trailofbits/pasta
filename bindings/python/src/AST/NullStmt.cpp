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

void RegisterNullStmt(py::module_ &m) {
  py::class_<NullStmt, Stmt>(m, "NullStmt")
    .def("__hash__", [](const NullStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const NullStmt& a, const NullStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &NullStmt::Children)
    .def_property_readonly("BeginToken", &NullStmt::BeginToken)
    .def_property_readonly("EndToken", &NullStmt::EndToken)
    .def_property_readonly("SemiToken", &NullStmt::SemiToken)
    .def_property_readonly("HasLeadingEmptyMacro", &NullStmt::HasLeadingEmptyMacro);
}
} // namespace pasta
