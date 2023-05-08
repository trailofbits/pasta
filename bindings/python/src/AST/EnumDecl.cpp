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

void RegisterEnumDecl(py::module_ &m) {
  py::class_<EnumDecl, TagDecl>(m, "EnumDecl")
    .def("__hash__", [](const EnumDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const EnumDecl& a, const EnumDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("enumerators", &EnumDecl::Enumerators)
    .def_property_readonly("canonical_declaration", &EnumDecl::CanonicalDeclaration)
    .def_property_readonly("definition", &EnumDecl::Definition)
    .def_property_readonly("instantiated_from_member_enum", &EnumDecl::InstantiatedFromMemberEnum)
    .def_property_readonly("integer_type", &EnumDecl::IntegerType)
    .def_property_readonly("integer_type_range", &EnumDecl::IntegerTypeRange)
    .def_property_readonly("most_recent_declaration", &EnumDecl::MostRecentDeclaration)
    .def_property_readonly("num_negative_bits", &EnumDecl::NumNegativeBits)
    .def_property_readonly("num_positive_bits", &EnumDecl::NumPositiveBits)
    .def_property_readonly("odr_hash", &EnumDecl::ODRHash)
    .def_property_readonly("previous_declaration", &EnumDecl::PreviousDeclaration)
    .def_property_readonly("promotion_type", &EnumDecl::PromotionType)
    .def_property_readonly("template_instantiation_pattern", &EnumDecl::TemplateInstantiationPattern)
    .def_property_readonly("template_specialization_kind", &EnumDecl::TemplateSpecializationKind)
    .def_property_readonly("is_closed", &EnumDecl::IsClosed)
    .def_property_readonly("is_closed_flag", &EnumDecl::IsClosedFlag)
    .def_property_readonly("is_closed_non_flag", &EnumDecl::IsClosedNonFlag)
    .def_property_readonly("is_complete", &EnumDecl::IsComplete)
    .def_property_readonly("is_fixed", &EnumDecl::IsFixed)
    .def_property_readonly("is_scoped", &EnumDecl::IsScoped)
    .def_property_readonly("is_scoped_using_class_tag", &EnumDecl::IsScopedUsingClassTag);
}
} // namespace pasta
