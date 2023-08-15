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

void RegisterCXXMethodDecl(nb::module_ &m) {
  nb::class_<CXXMethodDecl, FunctionDecl>(m, "CXXMethodDecl")
    .def("__hash__", [](const CXXMethodDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &CXXMethodDecl::CanonicalDeclaration)
    .def_prop_ro("most_recent_declaration", &CXXMethodDecl::MostRecentDeclaration)
    .def_prop_ro("parent", &CXXMethodDecl::Parent)
    .def_prop_ro("reference_qualifier", &CXXMethodDecl::ReferenceQualifier)
    .def_prop_ro("this_object_type", &CXXMethodDecl::ThisObjectType)
    .def_prop_ro("this_type", &CXXMethodDecl::ThisType)
    .def_prop_ro("has_inline_body", &CXXMethodDecl::HasInlineBody)
    .def_prop_ro("is_const", &CXXMethodDecl::IsConst)
    .def_prop_ro("is_copy_assignment_operator", &CXXMethodDecl::IsCopyAssignmentOperator)
    .def_prop_ro("is_instance", &CXXMethodDecl::IsInstance)
    .def_prop_ro("is_lambda_static_invoker", &CXXMethodDecl::IsLambdaStaticInvoker)
    .def_prop_ro("is_move_assignment_operator", &CXXMethodDecl::IsMoveAssignmentOperator)
    .def_prop_ro("is_static", &CXXMethodDecl::IsStatic)
    .def_prop_ro("is_virtual", &CXXMethodDecl::IsVirtual)
    .def_prop_ro("is_volatile", &CXXMethodDecl::IsVolatile)
    .def_prop_ro("overridden_methods", &CXXMethodDecl::OverriddenMethods)
    .def_prop_ro("size_overridden_methods", &CXXMethodDecl::SizeOverriddenMethods);
}
} // namespace pasta
