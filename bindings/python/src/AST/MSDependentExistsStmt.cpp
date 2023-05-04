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

void RegisterMSDependentExistsStmt(py::module_ &m) {
  py::class_<MSDependentExistsStmt, Stmt>(m, "MSDependentExistsStmt")
    .def_property_readonly("Children", &MSDependentExistsStmt::Children)
    .def_property_readonly("BeginToken", &MSDependentExistsStmt::BeginToken)
    .def_property_readonly("EndToken", &MSDependentExistsStmt::EndToken)
    .def_property_readonly("KeywordToken", &MSDependentExistsStmt::KeywordToken)
    .def_property_readonly("SubStatement", &MSDependentExistsStmt::SubStatement)
    .def_property_readonly("IsIfExists", &MSDependentExistsStmt::IsIfExists)
    .def_property_readonly("IsIfNotExists", &MSDependentExistsStmt::IsIfNotExists);
}
} // namespace pasta
