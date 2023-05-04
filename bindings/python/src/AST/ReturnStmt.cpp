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

void RegisterReturnStmt(py::module_ &m) {
  py::class_<ReturnStmt, Stmt>(m, "ReturnStmt")
    .def("__hash__", [](const ReturnStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ReturnStmt& a, const ReturnStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ReturnStmt::Children)
    .def_property_readonly("BeginToken", &ReturnStmt::BeginToken)
    .def_property_readonly("EndToken", &ReturnStmt::EndToken)
    .def_property_readonly("NRVOCandidate", &ReturnStmt::NRVOCandidate)
    .def_property_readonly("ReturnValue", &ReturnStmt::ReturnValue)
    .def_property_readonly("ReturnToken", &ReturnStmt::ReturnToken);
}
} // namespace pasta
