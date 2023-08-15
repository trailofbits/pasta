/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterConstructorUsingShadowDecl(nb::module_ &m) {
  nb::class_<ConstructorUsingShadowDecl, UsingShadowDecl>(m, "ConstructorUsingShadowDecl")
    .def("__hash__", [](const ConstructorUsingShadowDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("constructs_virtual_base", &ConstructorUsingShadowDecl::ConstructsVirtualBase)
    .def_prop_ro("constructed_base_class", &ConstructorUsingShadowDecl::ConstructedBaseClass)
    .def_prop_ro("constructed_base_class_shadow_declaration", &ConstructorUsingShadowDecl::ConstructedBaseClassShadowDeclaration)
    .def_prop_ro("introducer", &ConstructorUsingShadowDecl::Introducer)
    .def_prop_ro("nominated_base_class", &ConstructorUsingShadowDecl::NominatedBaseClass)
    .def_prop_ro("nominated_base_class_shadow_declaration", &ConstructorUsingShadowDecl::NominatedBaseClassShadowDeclaration)
    .def_prop_ro("parent", &ConstructorUsingShadowDecl::Parent);
}
} // namespace pasta
