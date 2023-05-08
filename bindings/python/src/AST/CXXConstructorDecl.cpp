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

void RegisterCXXConstructorDecl(py::module_ &m) {
  py::class_<CXXConstructorDecl, CXXMethodDecl>(m, "CXXConstructorDecl")
    .def("__hash__", [](const CXXConstructorDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const CXXConstructorDecl& a, const CXXConstructorDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &CXXConstructorDecl::CanonicalDeclaration)
    .def_property_readonly("NumConstructorInitializers", &CXXConstructorDecl::NumConstructorInitializers)
    .def_property_readonly("TargetConstructor", &CXXConstructorDecl::TargetConstructor)
    .def("IsConvertingConstructor", &CXXConstructorDecl::IsConvertingConstructor)
    .def_property_readonly("IsDefaultConstructor", &CXXConstructorDecl::IsDefaultConstructor)
    .def_property_readonly("IsDelegatingConstructor", &CXXConstructorDecl::IsDelegatingConstructor)
    .def_property_readonly("IsExplicit", &CXXConstructorDecl::IsExplicit)
    .def_property_readonly("IsInheritingConstructor", &CXXConstructorDecl::IsInheritingConstructor)
    .def_property_readonly("IsSpecializationCopyingObject", &CXXConstructorDecl::IsSpecializationCopyingObject);
}
} // namespace pasta
