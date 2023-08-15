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

void RegisterTemplateDecl(nb::module_ &m) {
  nb::class_<TemplateDecl, NamedDecl>(m, "TemplateDecl")
    .def("__hash__", [](const TemplateDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("template_parameters", &TemplateDecl::TemplateParameters)
    .def_prop_ro("templated_declaration", &TemplateDecl::TemplatedDeclaration)
    .def_prop_ro("has_associated_constraints", &TemplateDecl::HasAssociatedConstraints)
    .def_prop_ro("is_type_alias", &TemplateDecl::IsTypeAlias);
}
} // namespace pasta
