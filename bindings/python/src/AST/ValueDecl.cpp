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

void RegisterValueDecl(py::module_ &m) {
  py::class_<ValueDecl, Decl, NamedDecl>(m, "ValueDecl")
    .def("__hash__", [](const ValueDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ValueDecl& a, const ValueDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("PotentiallyDecomposedVariableDeclaration", &ValueDecl::PotentiallyDecomposedVariableDeclaration)
    .def_property_readonly("Type", &ValueDecl::Type)
    .def_property_readonly("IsInitializerCapture", &ValueDecl::IsInitializerCapture)
    .def_property_readonly("IsWeak", &ValueDecl::IsWeak);
}
} // namespace pasta
