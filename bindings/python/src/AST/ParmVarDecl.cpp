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

void RegisterParmVarDecl(nb::module_ &m) {
  nb::class_<ParmVarDecl, VarDecl>(m, "ParmVarDecl")
    .def_prop_ro("default_argument", &ParmVarDecl::DefaultArgument)
    .def_prop_ro("default_argument_range", &ParmVarDecl::DefaultArgumentRange)
    .def_prop_ro("explicit_object_parameter_this_token", &ParmVarDecl::ExplicitObjectParameterThisToken)
    .def_prop_ro("function_scope_depth", &ParmVarDecl::FunctionScopeDepth)
    .def_prop_ro("function_scope_index", &ParmVarDecl::FunctionScopeIndex)
    .def_prop_ro("obj_c_decl_qualifier", &ParmVarDecl::ObjCDeclQualifier)
    .def_prop_ro("original_type", &ParmVarDecl::OriginalType)
    .def_prop_ro("uninstantiated_default_argument", &ParmVarDecl::UninstantiatedDefaultArgument)
    .def_prop_ro("has_default_argument", &ParmVarDecl::HasDefaultArgument)
    .def_prop_ro("has_inherited_default_argument", &ParmVarDecl::HasInheritedDefaultArgument)
    .def_prop_ro("has_uninstantiated_default_argument", &ParmVarDecl::HasUninstantiatedDefaultArgument)
    .def_prop_ro("has_unparsed_default_argument", &ParmVarDecl::HasUnparsedDefaultArgument)
    .def_prop_ro("is_destroyed_in_callee", &ParmVarDecl::IsDestroyedInCallee)
    .def_prop_ro("is_explicit_object_parameter", &ParmVarDecl::IsExplicitObjectParameter)
    .def_prop_ro("is_knr_promoted", &ParmVarDecl::IsKNRPromoted)
    .def_prop_ro("is_obj_c_method_parameter", &ParmVarDecl::IsObjCMethodParameter);
}
} // namespace pasta
