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

void RegisterReturnStmt(py::module_ &m) {
  py::class_<ReturnStmt, Stmt>(m, "ReturnStmt")
    .def("__hash__", [](const ReturnStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ReturnStmt::Children)
    .def_property_readonly("begin_token", &ReturnStmt::BeginToken)
    .def_property_readonly("end_token", &ReturnStmt::EndToken)
    .def_property_readonly("nrvo_candidate", &ReturnStmt::NRVOCandidate)
    .def_property_readonly("return_value", &ReturnStmt::ReturnValue)
    .def_property_readonly("return_token", &ReturnStmt::ReturnToken);
}
} // namespace pasta
