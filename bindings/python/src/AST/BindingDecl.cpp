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
  py::class_<BindingDecl, ValueDecl>(m, "BindingDecl")
    .def("__hash__", [](const BindingDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const BindingDecl& a, const BindingDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("Binding", &BindingDecl::Binding)
    .def_property_readonly("DecomposedDeclaration", &BindingDecl::DecomposedDeclaration)
    .def_property_readonly("HoldingVariable", &BindingDecl::HoldingVariable);
}
} // namespace pasta
