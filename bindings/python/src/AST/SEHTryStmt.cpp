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

void RegisterSEHTryStmt(py::module_ &m) {
  py::class_<SEHTryStmt, Stmt>(m, "SEHTryStmt")
    .def_property_readonly("Children", &SEHTryStmt::Children)
    .def_property_readonly("BeginToken", &SEHTryStmt::BeginToken)
    .def_property_readonly("EndToken", &SEHTryStmt::EndToken)
    .def_property_readonly("ExceptHandler", &SEHTryStmt::ExceptHandler)
    .def_property_readonly("FinallyHandler", &SEHTryStmt::FinallyHandler)
    .def_property_readonly("Handler", &SEHTryStmt::Handler)
    .def_property_readonly("IsCXXTry", &SEHTryStmt::IsCXXTry)
    .def_property_readonly("TryBlock", &SEHTryStmt::TryBlock)
    .def_property_readonly("TryToken", &SEHTryStmt::TryToken);
}
} // namespace pasta
