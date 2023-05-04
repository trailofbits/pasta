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

void RegisterBindingDecl(py::module_ &m) {
  py::class_<BindingDecl, Decl, NamedDecl, ValueDecl>(m, "BindingDecl")
    .def_property_readonly("Binding", &BindingDecl::Binding)
    .def_property_readonly("DecomposedDeclaration", &BindingDecl::DecomposedDeclaration)
    .def_property_readonly("HoldingVariable", &BindingDecl::HoldingVariable);
}
} // namespace pasta
