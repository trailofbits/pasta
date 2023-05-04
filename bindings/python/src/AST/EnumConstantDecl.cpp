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
  py::class_<EnumConstantDecl, Decl, NamedDecl, ValueDecl>(m, "EnumConstantDecl")
    .def("__hash__", [](const EnumConstantDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const EnumConstantDecl& a, const EnumConstantDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &EnumConstantDecl::CanonicalDeclaration)
    .def_property_readonly("InitializerExpression", &EnumConstantDecl::InitializerExpression)
    .def_property_readonly("InitializerValue", &EnumConstantDecl::InitializerValue);
}
} // namespace pasta
