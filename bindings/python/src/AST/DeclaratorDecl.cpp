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

void RegisterDeclaratorDecl(py::module_ &m) {
  py::class_<DeclaratorDecl, Decl, NamedDecl, ValueDecl>(m, "DeclaratorDecl")
    .def_property_readonly("BeginToken", &DeclaratorDecl::BeginToken)
    .def_property_readonly("FirstInnerToken", &DeclaratorDecl::FirstInnerToken)
    .def_property_readonly("NumTemplateParameterLists", &DeclaratorDecl::NumTemplateParameterLists)
    .def_property_readonly("FirstOuterToken", &DeclaratorDecl::FirstOuterToken)
    .def_property_readonly("TrailingRequiresClause", &DeclaratorDecl::TrailingRequiresClause)
    .def_property_readonly("Type", &DeclaratorDecl::Type)
    .def_property_readonly("TypeSpecEndToken", &DeclaratorDecl::TypeSpecEndToken)
    .def_property_readonly("TypeSpecStartToken", &DeclaratorDecl::TypeSpecStartToken);
}
} // namespace pasta
