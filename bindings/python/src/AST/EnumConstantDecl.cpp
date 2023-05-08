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

void RegisterEnumConstantDecl(py::module_ &m) {
  py::class_<EnumConstantDecl, ValueDecl>(m, "EnumConstantDecl")
    .def("__hash__", [](const EnumConstantDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const EnumConstantDecl& a, const EnumConstantDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &EnumConstantDecl::CanonicalDeclaration)
    .def_property_readonly("initializer_expression", &EnumConstantDecl::InitializerExpression)
    .def_property_readonly("initializer_value", &EnumConstantDecl::InitializerValue);
}
} // namespace pasta
