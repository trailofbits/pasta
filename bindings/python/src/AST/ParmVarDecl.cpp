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

void RegisterParmVarDecl(py::module_ &m) {
  py::class_<ParmVarDecl, Decl, DeclaratorDecl, NamedDecl, ValueDecl, VarDecl>(m, "ParmVarDecl")
    .def_property_readonly("DefaultArgument", &ParmVarDecl::DefaultArgument)
    .def_property_readonly("DefaultArgumentRange", &ParmVarDecl::DefaultArgumentRange)
    .def_property_readonly("FunctionScopeDepth", &ParmVarDecl::FunctionScopeDepth)
    .def_property_readonly("FunctionScopeIndex", &ParmVarDecl::FunctionScopeIndex)
    .def_property_readonly("ObjCDeclQualifier", &ParmVarDecl::ObjCDeclQualifier)
    .def_property_readonly("OriginalType", &ParmVarDecl::OriginalType)
    .def_property_readonly("UninstantiatedDefaultArgument", &ParmVarDecl::UninstantiatedDefaultArgument)
    .def_property_readonly("HasDefaultArgument", &ParmVarDecl::HasDefaultArgument)
    .def_property_readonly("HasInheritedDefaultArgument", &ParmVarDecl::HasInheritedDefaultArgument)
    .def_property_readonly("HasUninstantiatedDefaultArgument", &ParmVarDecl::HasUninstantiatedDefaultArgument)
    .def_property_readonly("HasUnparsedDefaultArgument", &ParmVarDecl::HasUnparsedDefaultArgument)
    .def_property_readonly("IsDestroyedInCallee", &ParmVarDecl::IsDestroyedInCallee)
    .def_property_readonly("IsKNRPromoted", &ParmVarDecl::IsKNRPromoted)
    .def_property_readonly("IsObjCMethodParameter", &ParmVarDecl::IsObjCMethodParameter);
}
} // namespace pasta
