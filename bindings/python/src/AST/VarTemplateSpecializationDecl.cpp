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

void RegisterVarTemplateSpecializationDecl(nb::module_ &m) {
  nb::class_<VarTemplateSpecializationDecl, VarDecl>(m, "VarTemplateSpecializationDecl")
    .def("__hash__", [](const VarTemplateSpecializationDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("extern_token", &VarTemplateSpecializationDecl::ExternToken)
    .def_prop_ro("instantiated_from", &VarTemplateSpecializationDecl::InstantiatedFrom)
    .def_prop_ro("point_of_instantiation", &VarTemplateSpecializationDecl::PointOfInstantiation)
    .def_prop_ro("specialization_kind", &VarTemplateSpecializationDecl::SpecializationKind)
    .def_prop_ro("specialized_template", &VarTemplateSpecializationDecl::SpecializedTemplate)
    .def_prop_ro("specialized_template_or_partial", &VarTemplateSpecializationDecl::SpecializedTemplateOrPartial)
    .def_prop_ro("template_arguments", &VarTemplateSpecializationDecl::TemplateArguments)
    .def_prop_ro("template_instantiation_arguments", &VarTemplateSpecializationDecl::TemplateInstantiationArguments)
    .def_prop_ro("template_keyword_token", &VarTemplateSpecializationDecl::TemplateKeywordToken)
    .def_prop_ro("type_as_written", &VarTemplateSpecializationDecl::TypeAsWritten)
    .def_prop_ro("is_class_scope_explicit_specialization", &VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization)
    .def_prop_ro("is_explicit_instantiation_or_specialization", &VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization)
    .def_prop_ro("is_explicit_specialization", &VarTemplateSpecializationDecl::IsExplicitSpecialization);
}
} // namespace pasta
