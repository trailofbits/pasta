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

void RegisterConstructorUsingShadowDecl(py::module_ &m) {
  py::class_<ConstructorUsingShadowDecl, Decl, NamedDecl, UsingShadowDecl>(m, "ConstructorUsingShadowDecl")
    .def("__hash__", [](const ConstructorUsingShadowDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ConstructorUsingShadowDecl& a, const ConstructorUsingShadowDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("ConstructsVirtualBase", &ConstructorUsingShadowDecl::ConstructsVirtualBase)
    .def_property_readonly("ConstructedBaseClass", &ConstructorUsingShadowDecl::ConstructedBaseClass)
    .def_property_readonly("ConstructedBaseClassShadowDeclaration", &ConstructorUsingShadowDecl::ConstructedBaseClassShadowDeclaration)
    .def_property_readonly("Introducer", &ConstructorUsingShadowDecl::Introducer)
    .def_property_readonly("NominatedBaseClass", &ConstructorUsingShadowDecl::NominatedBaseClass)
    .def_property_readonly("NominatedBaseClassShadowDeclaration", &ConstructorUsingShadowDecl::NominatedBaseClassShadowDeclaration)
    .def_property_readonly("Parent", &ConstructorUsingShadowDecl::Parent);
}
} // namespace pasta
