/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterVarTemplatePartialSpecializationDecl(nb::module_ &m) {
  nb::class_<VarTemplatePartialSpecializationDecl, VarTemplateSpecializationDecl>(m, "VarTemplatePartialSpecializationDecl")
    .def_prop_ro("instantiated_from_member", &VarTemplatePartialSpecializationDecl::InstantiatedFromMember)
    .def_prop_ro("template_parameters", &VarTemplatePartialSpecializationDecl::TemplateParameters)
    .def_prop_ro("has_associated_constraints", &VarTemplatePartialSpecializationDecl::HasAssociatedConstraints);
}
} // namespace pasta
