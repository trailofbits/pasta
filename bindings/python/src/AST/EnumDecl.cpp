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

void RegisterEnumDecl(nb::module_ &m) {
  nb::class_<EnumDecl, TagDecl>(m, "EnumDecl")
    .def_prop_ro("canonical_declaration", &EnumDecl::CanonicalDeclaration)
    .def_prop_ro("definition", &EnumDecl::Definition)
    .def_prop_ro("instantiated_from_member_enum", &EnumDecl::InstantiatedFromMemberEnum)
    .def_prop_ro("integer_type", &EnumDecl::IntegerType)
    .def_prop_ro("integer_type_range", &EnumDecl::IntegerTypeRange)
    .def_prop_ro("most_recent_declaration", &EnumDecl::MostRecentDeclaration)
    .def_prop_ro("num_negative_bits", &EnumDecl::NumNegativeBits)
    .def_prop_ro("num_positive_bits", &EnumDecl::NumPositiveBits)
    .def_prop_ro("odr_hash", &EnumDecl::ODRHash)
    .def_prop_ro("previous_declaration", &EnumDecl::PreviousDeclaration)
    .def_prop_ro("promotion_type", &EnumDecl::PromotionType)
    .def_prop_ro("template_instantiation_pattern", &EnumDecl::TemplateInstantiationPattern)
    .def_prop_ro("template_specialization_kind", &EnumDecl::TemplateSpecializationKind)
    .def_prop_ro("is_closed", &EnumDecl::IsClosed)
    .def_prop_ro("is_closed_flag", &EnumDecl::IsClosedFlag)
    .def_prop_ro("is_closed_non_flag", &EnumDecl::IsClosedNonFlag)
    .def_prop_ro("is_complete", &EnumDecl::IsComplete)
    .def_prop_ro("is_fixed", &EnumDecl::IsFixed)
    .def_prop_ro("is_scoped", &EnumDecl::IsScoped)
    .def_prop_ro("is_scoped_using_class_tag", &EnumDecl::IsScopedUsingClassTag);
}
} // namespace pasta
