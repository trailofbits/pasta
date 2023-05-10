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

void RegisterParmVarDecl(py::module_ &m) {
  py::class_<ParmVarDecl, VarDecl>(m, "ParmVarDecl")
    .def("__hash__", [](const ParmVarDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ParmVarDecl& a, const ParmVarDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("default_argument", &ParmVarDecl::DefaultArgument)
    .def_property_readonly("default_argument_range", &ParmVarDecl::DefaultArgumentRange)
    .def_property_readonly("function_scope_depth", &ParmVarDecl::FunctionScopeDepth)
    .def_property_readonly("function_scope_index", &ParmVarDecl::FunctionScopeIndex)
    .def_property_readonly("obj_c_decl_qualifier", &ParmVarDecl::ObjCDeclQualifier)
    .def_property_readonly("original_type", &ParmVarDecl::OriginalType)
    .def_property_readonly("uninstantiated_default_argument", &ParmVarDecl::UninstantiatedDefaultArgument)
    .def_property_readonly("has_default_argument", &ParmVarDecl::HasDefaultArgument)
    .def_property_readonly("has_inherited_default_argument", &ParmVarDecl::HasInheritedDefaultArgument)
    .def_property_readonly("has_uninstantiated_default_argument", &ParmVarDecl::HasUninstantiatedDefaultArgument)
    .def_property_readonly("has_unparsed_default_argument", &ParmVarDecl::HasUnparsedDefaultArgument)
    .def_property_readonly("is_destroyed_in_callee", &ParmVarDecl::IsDestroyedInCallee)
    .def_property_readonly("is_knr_promoted", &ParmVarDecl::IsKNRPromoted)
    .def_property_readonly("is_obj_c_method_parameter", &ParmVarDecl::IsObjCMethodParameter);
}
} // namespace pasta
