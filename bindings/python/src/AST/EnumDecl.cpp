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
  py::class_<EnumDecl, Decl, NamedDecl, TagDecl, TypeDecl>(m, "EnumDecl")
    .def_property_readonly("Enumerators", &EnumDecl::Enumerators)
    .def_property_readonly("CanonicalDeclaration", &EnumDecl::CanonicalDeclaration)
    .def_property_readonly("Definition", &EnumDecl::Definition)
    .def_property_readonly("InstantiatedFromMemberEnum", &EnumDecl::InstantiatedFromMemberEnum)
    .def_property_readonly("IntegerType", &EnumDecl::IntegerType)
    .def_property_readonly("IntegerTypeRange", &EnumDecl::IntegerTypeRange)
    .def_property_readonly("MostRecentDeclaration", &EnumDecl::MostRecentDeclaration)
    .def_property_readonly("NumNegativeBits", &EnumDecl::NumNegativeBits)
    .def_property_readonly("NumPositiveBits", &EnumDecl::NumPositiveBits)
    .def_property_readonly("ODRHash", &EnumDecl::ODRHash)
    .def_property_readonly("PreviousDeclaration", &EnumDecl::PreviousDeclaration)
    .def_property_readonly("PromotionType", &EnumDecl::PromotionType)
    .def_property_readonly("TemplateInstantiationPattern", &EnumDecl::TemplateInstantiationPattern)
    .def_property_readonly("TemplateSpecializationKind", &EnumDecl::TemplateSpecializationKind)
    .def_property_readonly("IsClosed", &EnumDecl::IsClosed)
    .def_property_readonly("IsClosedFlag", &EnumDecl::IsClosedFlag)
    .def_property_readonly("IsClosedNonFlag", &EnumDecl::IsClosedNonFlag)
    .def_property_readonly("IsComplete", &EnumDecl::IsComplete)
    .def_property_readonly("IsFixed", &EnumDecl::IsFixed)
    .def_property_readonly("IsScoped", &EnumDecl::IsScoped)
    .def_property_readonly("IsScopedUsingClassTag", &EnumDecl::IsScopedUsingClassTag);
}
} // namespace pasta
