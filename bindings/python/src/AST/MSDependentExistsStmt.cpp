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

void RegisterMSDependentExistsStmt(py::module_ &m) {
  py::class_<MSDependentExistsStmt, Stmt>(m, "MSDependentExistsStmt")
    .def("__hash__", [](const MSDependentExistsStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const MSDependentExistsStmt& a, const MSDependentExistsStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &MSDependentExistsStmt::Children)
    .def_property_readonly("begin_token", &MSDependentExistsStmt::BeginToken)
    .def_property_readonly("end_token", &MSDependentExistsStmt::EndToken)
    .def_property_readonly("keyword_token", &MSDependentExistsStmt::KeywordToken)
    .def_property_readonly("sub_statement", &MSDependentExistsStmt::SubStatement)
    .def_property_readonly("is_if_exists", &MSDependentExistsStmt::IsIfExists)
    .def_property_readonly("is_if_not_exists", &MSDependentExistsStmt::IsIfNotExists);
}
} // namespace pasta
