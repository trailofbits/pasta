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

void RegisterRedeclarableTemplateDecl(py::module_ &m) {
  py::class_<RedeclarableTemplateDecl, TemplateDecl>(m, "RedeclarableTemplateDecl")
    .def("__hash__", [](const RedeclarableTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const RedeclarableTemplateDecl& a, const RedeclarableTemplateDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &RedeclarableTemplateDecl::CanonicalDeclaration)
    .def_property_readonly("InstantiatedFromMemberTemplate", &RedeclarableTemplateDecl::InstantiatedFromMemberTemplate)
    .def_property_readonly("IsMemberSpecialization", &RedeclarableTemplateDecl::IsMemberSpecialization);
}
} // namespace pasta
