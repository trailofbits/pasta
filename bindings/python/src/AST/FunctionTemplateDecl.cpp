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

void RegisterFunctionTemplateDecl(py::module_ &m) {
  py::class_<FunctionTemplateDecl, RedeclarableTemplateDecl>(m, "FunctionTemplateDecl")
    .def("__hash__", [](const FunctionTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const FunctionTemplateDecl& a, const FunctionTemplateDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &FunctionTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("InstantiatedFromMemberTemplate", &FunctionTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("MostRecentDeclaration", &FunctionTemplateDecl::MostRecentDeclaration)
    .def_property_readonly("PreviousDeclaration", &FunctionTemplateDecl::PreviousDeclaration)
    .def_property_readonly("TemplatedDeclaration", &FunctionTemplateDecl::TemplatedDeclaration)
    .def_property_readonly("IsAbbreviated", &FunctionTemplateDecl::IsAbbreviated)
    .def_property_readonly("IsThisDeclarationADefinition", &FunctionTemplateDecl::IsThisDeclarationADefinition)
    .def_property_readonly("Specializations", &FunctionTemplateDecl::Specializations);
}
} // namespace pasta
