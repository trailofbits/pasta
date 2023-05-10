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

void RegisterSEHTryStmt(py::module_ &m) {
  py::class_<SEHTryStmt, Stmt>(m, "SEHTryStmt")
    .def("__hash__", [](const SEHTryStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SEHTryStmt& a, const SEHTryStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &SEHTryStmt::Children)
    .def_property_readonly("begin_token", &SEHTryStmt::BeginToken)
    .def_property_readonly("end_token", &SEHTryStmt::EndToken)
    .def_property_readonly("except_handler", &SEHTryStmt::ExceptHandler)
    .def_property_readonly("finally_handler", &SEHTryStmt::FinallyHandler)
    .def_property_readonly("handler", &SEHTryStmt::Handler)
    .def_property_readonly("is_cxx_try", &SEHTryStmt::IsCXXTry)
    .def_property_readonly("try_block", &SEHTryStmt::TryBlock)
    .def_property_readonly("try_token", &SEHTryStmt::TryToken);
}
} // namespace pasta
