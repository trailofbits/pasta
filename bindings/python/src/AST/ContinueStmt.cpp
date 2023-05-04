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

void RegisterContinueStmt(py::module_ &m) {
  py::class_<ContinueStmt, Stmt>(m, "ContinueStmt")
    .def("__hash__", [](const ContinueStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ContinueStmt& a, const ContinueStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ContinueStmt::Children)
    .def_property_readonly("BeginToken", &ContinueStmt::BeginToken)
    .def_property_readonly("ContinueToken", &ContinueStmt::ContinueToken)
    .def_property_readonly("EndToken", &ContinueStmt::EndToken);
}
} // namespace pasta
