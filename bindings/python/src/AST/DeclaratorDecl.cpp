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

void RegisterDeclaratorDecl(py::module_ &m) {
  py::class_<DeclaratorDecl, ValueDecl>(m, "DeclaratorDecl")
    .def("__hash__", [](const DeclaratorDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const DeclaratorDecl& a, const DeclaratorDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("begin_token", &DeclaratorDecl::BeginToken)
    .def_property_readonly("first_inner_token", &DeclaratorDecl::FirstInnerToken)
    .def_property_readonly("num_template_parameter_lists", &DeclaratorDecl::NumTemplateParameterLists)
    .def_property_readonly("first_outer_token", &DeclaratorDecl::FirstOuterToken)
    .def_property_readonly("trailing_requires_clause", &DeclaratorDecl::TrailingRequiresClause)
    .def_property_readonly("type", &DeclaratorDecl::Type)
    .def_property_readonly("type_spec_end_token", &DeclaratorDecl::TypeSpecEndToken)
    .def_property_readonly("type_spec_start_token", &DeclaratorDecl::TypeSpecStartToken);
}
} // namespace pasta
