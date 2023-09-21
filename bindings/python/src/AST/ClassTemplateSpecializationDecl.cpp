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

void RegisterClassTemplateSpecializationDecl(nb::module_ &m) {
  nb::class_<ClassTemplateSpecializationDecl, CXXRecordDecl>(m, "ClassTemplateSpecializationDecl")
    .def("__hash__", [](const ClassTemplateSpecializationDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("extern_token", &ClassTemplateSpecializationDecl::ExternToken)
    .def_prop_ro("instantiated_from", &ClassTemplateSpecializationDecl::InstantiatedFrom)
    .def_prop_ro("point_of_instantiation", &ClassTemplateSpecializationDecl::PointOfInstantiation)
    .def_prop_ro("specialization_kind", &ClassTemplateSpecializationDecl::SpecializationKind)
    .def_prop_ro("specialized_template", &ClassTemplateSpecializationDecl::SpecializedTemplate)
    .def_prop_ro("specialized_template_or_partial", &ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial)
    .def_prop_ro("template_arguments", &ClassTemplateSpecializationDecl::TemplateArguments)
    .def_prop_ro("template_instantiation_arguments", &ClassTemplateSpecializationDecl::TemplateInstantiationArguments)
    .def_prop_ro("template_keyword_token", &ClassTemplateSpecializationDecl::TemplateKeywordToken)
    .def_prop_ro("type_as_written", &ClassTemplateSpecializationDecl::TypeAsWritten)
    .def_prop_ro("is_class_scope_explicit_specialization", &ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization)
    .def_prop_ro("is_explicit_instantiation_or_specialization", &ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization)
    .def_prop_ro("is_explicit_specialization", &ClassTemplateSpecializationDecl::IsExplicitSpecialization);
}
} // namespace pasta
