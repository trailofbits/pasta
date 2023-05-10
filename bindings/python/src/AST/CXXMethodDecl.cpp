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

void RegisterCXXMethodDecl(py::module_ &m) {
  py::class_<CXXMethodDecl, FunctionDecl>(m, "CXXMethodDecl")
    .def("__hash__", [](const CXXMethodDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const CXXMethodDecl& a, const CXXMethodDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &CXXMethodDecl::CanonicalDeclaration)
    .def_property_readonly("most_recent_declaration", &CXXMethodDecl::MostRecentDeclaration)
    .def_property_readonly("parent", &CXXMethodDecl::Parent)
    .def_property_readonly("reference_qualifier", &CXXMethodDecl::ReferenceQualifier)
    .def_property_readonly("this_object_type", &CXXMethodDecl::ThisObjectType)
    .def_property_readonly("this_type", &CXXMethodDecl::ThisType)
    .def_property_readonly("has_inline_body", &CXXMethodDecl::HasInlineBody)
    .def_property_readonly("is_const", &CXXMethodDecl::IsConst)
    .def_property_readonly("is_copy_assignment_operator", &CXXMethodDecl::IsCopyAssignmentOperator)
    .def_property_readonly("is_instance", &CXXMethodDecl::IsInstance)
    .def_property_readonly("is_lambda_static_invoker", &CXXMethodDecl::IsLambdaStaticInvoker)
    .def_property_readonly("is_move_assignment_operator", &CXXMethodDecl::IsMoveAssignmentOperator)
    .def_property_readonly("is_static", &CXXMethodDecl::IsStatic)
    .def_property_readonly("is_virtual", &CXXMethodDecl::IsVirtual)
    .def_property_readonly("is_volatile", &CXXMethodDecl::IsVolatile)
    .def_property_readonly("overridden_methods", &CXXMethodDecl::OverriddenMethods)
    .def_property_readonly("size_overridden_methods", &CXXMethodDecl::SizeOverriddenMethods);
}
} // namespace pasta
