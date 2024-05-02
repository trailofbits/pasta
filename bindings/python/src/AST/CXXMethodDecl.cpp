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

void RegisterCXXMethodDecl(nb::module_ &m) {
  nb::class_<CXXMethodDecl, FunctionDecl>(m, "CXXMethodDecl")
    .def_prop_ro("canonical_declaration", &CXXMethodDecl::CanonicalDeclaration)
    .def_prop_ro("function_object_parameter_reference_type", &CXXMethodDecl::FunctionObjectParameterReferenceType)
    .def_prop_ro("function_object_parameter_type", &CXXMethodDecl::FunctionObjectParameterType)
    .def_prop_ro("most_recent_declaration", &CXXMethodDecl::MostRecentDeclaration)
    .def_prop_ro("num_explicit_parameters", &CXXMethodDecl::NumExplicitParameters)
    .def_prop_ro("parent", &CXXMethodDecl::Parent)
    .def_prop_ro("reference_qualifier", &CXXMethodDecl::ReferenceQualifier)
    .def_prop_ro("this_type", &CXXMethodDecl::ThisType)
    .def_prop_ro("has_inline_body", &CXXMethodDecl::HasInlineBody)
    .def_prop_ro("is_const", &CXXMethodDecl::IsConst)
    .def_prop_ro("is_copy_assignment_operator", &CXXMethodDecl::IsCopyAssignmentOperator)
    .def_prop_ro("is_explicit_object_member_function", &CXXMethodDecl::IsExplicitObjectMemberFunction)
    .def_prop_ro("is_implicit_object_member_function", &CXXMethodDecl::IsImplicitObjectMemberFunction)
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
