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

void RegisterConstructorUsingShadowDecl(py::module_ &m) {
  py::class_<ConstructorUsingShadowDecl, UsingShadowDecl>(m, "ConstructorUsingShadowDecl")
    .def("__hash__", [](const ConstructorUsingShadowDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("constructs_virtual_base", &ConstructorUsingShadowDecl::ConstructsVirtualBase)
    .def_property_readonly("constructed_base_class", &ConstructorUsingShadowDecl::ConstructedBaseClass)
    .def_property_readonly("constructed_base_class_shadow_declaration", &ConstructorUsingShadowDecl::ConstructedBaseClassShadowDeclaration)
    .def_property_readonly("introducer", &ConstructorUsingShadowDecl::Introducer)
    .def_property_readonly("nominated_base_class", &ConstructorUsingShadowDecl::NominatedBaseClass)
    .def_property_readonly("nominated_base_class_shadow_declaration", &ConstructorUsingShadowDecl::NominatedBaseClassShadowDeclaration)
    .def_property_readonly("parent", &ConstructorUsingShadowDecl::Parent);
}
} // namespace pasta
