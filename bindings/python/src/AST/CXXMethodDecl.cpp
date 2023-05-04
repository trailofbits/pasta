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

void RegisterCXXMethodDecl(py::module_ &m) {
  py::class_<CXXMethodDecl, Decl, DeclaratorDecl, FunctionDecl, NamedDecl, ValueDecl>(m, "CXXMethodDecl")
    .def("__hash__", [](const CXXMethodDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const CXXMethodDecl& a, const CXXMethodDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("CanonicalDeclaration", &CXXMethodDecl::CanonicalDeclaration)
    .def_property_readonly("MostRecentDeclaration", &CXXMethodDecl::MostRecentDeclaration)
    .def_property_readonly("Parent", &CXXMethodDecl::Parent)
    .def_property_readonly("ReferenceQualifier", &CXXMethodDecl::ReferenceQualifier)
    .def_property_readonly("ThisObjectType", &CXXMethodDecl::ThisObjectType)
    .def_property_readonly("ThisType", &CXXMethodDecl::ThisType)
    .def_property_readonly("HasInlineBody", &CXXMethodDecl::HasInlineBody)
    .def_property_readonly("IsConst", &CXXMethodDecl::IsConst)
    .def_property_readonly("IsCopyAssignmentOperator", &CXXMethodDecl::IsCopyAssignmentOperator)
    .def_property_readonly("IsInstance", &CXXMethodDecl::IsInstance)
    .def_property_readonly("IsLambdaStaticInvoker", &CXXMethodDecl::IsLambdaStaticInvoker)
    .def_property_readonly("IsMoveAssignmentOperator", &CXXMethodDecl::IsMoveAssignmentOperator)
    .def_property_readonly("IsStatic", &CXXMethodDecl::IsStatic)
    .def_property_readonly("IsVirtual", &CXXMethodDecl::IsVirtual)
    .def_property_readonly("IsVolatile", &CXXMethodDecl::IsVolatile)
    .def_property_readonly("OverriddenMethods", &CXXMethodDecl::OverriddenMethods)
    .def_property_readonly("SizeOverriddenMethods", &CXXMethodDecl::SizeOverriddenMethods);
}
} // namespace pasta
