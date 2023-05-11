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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterCXXConstructorDecl(py::module_ &m) {
  py::class_<CXXConstructorDecl, CXXMethodDecl>(m, "CXXConstructorDecl")
    .def("__hash__", [](const CXXConstructorDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &CXXConstructorDecl::CanonicalDeclaration)
    .def_property_readonly("num_constructor_initializers", &CXXConstructorDecl::NumConstructorInitializers)
    .def_property_readonly("target_constructor", &CXXConstructorDecl::TargetConstructor)
    .def("is_converting_constructor", &CXXConstructorDecl::IsConvertingConstructor)
    .def_property_readonly("is_default_constructor", &CXXConstructorDecl::IsDefaultConstructor)
    .def_property_readonly("is_delegating_constructor", &CXXConstructorDecl::IsDelegatingConstructor)
    .def_property_readonly("is_explicit", &CXXConstructorDecl::IsExplicit)
    .def_property_readonly("is_inheriting_constructor", &CXXConstructorDecl::IsInheritingConstructor)
    .def_property_readonly("is_specialization_copying_object", &CXXConstructorDecl::IsSpecializationCopyingObject);
}
} // namespace pasta
