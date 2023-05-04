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

void RegisterCapturedStmt(py::module_ &m) {
  py::class_<CapturedStmt, Stmt>(m, "CapturedStmt")
    .def_property_readonly("Children", &CapturedStmt::Children)
    .def_property_readonly("BeginToken", &CapturedStmt::BeginToken)
    .def_property_readonly("CapturedDeclaration", &CapturedStmt::CapturedDeclaration)
    .def_property_readonly("CapturedRecordDeclaration", &CapturedStmt::CapturedRecordDeclaration)
    .def_property_readonly("CapturedRegionKind", &CapturedStmt::CapturedRegionKind)
    .def_property_readonly("CapturedStatement", &CapturedStmt::CapturedStatement)
    .def_property_readonly("EndToken", &CapturedStmt::EndToken)
    .def_property_readonly("Tokens", &CapturedStmt::Tokens);
}
} // namespace pasta
