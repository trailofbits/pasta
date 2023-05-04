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

void RegisterObjCCategoryDecl(py::module_ &m) {
  py::class_<ObjCCategoryDecl, Decl, NamedDecl, ObjCContainerDecl>(m, "ObjCCategoryDecl")
    .def_property_readonly("IsClassExtension", &ObjCCategoryDecl::IsClassExtension)
    .def_property_readonly("CategoryNameToken", &ObjCCategoryDecl::CategoryNameToken)
    .def_property_readonly("ClassInterface", &ObjCCategoryDecl::ClassInterface)
    .def_property_readonly("Implementation", &ObjCCategoryDecl::Implementation)
    .def_property_readonly("InstanceVariableLBraceToken", &ObjCCategoryDecl::InstanceVariableLBraceToken)
    .def_property_readonly("InstanceVariableRBraceToken", &ObjCCategoryDecl::InstanceVariableRBraceToken)
    .def_property_readonly("NextClassCategory", &ObjCCategoryDecl::NextClassCategory)
    .def_property_readonly("NextClassCategoryRaw", &ObjCCategoryDecl::NextClassCategoryRaw)
    .def_property_readonly("InstanceVariables", &ObjCCategoryDecl::InstanceVariables)
    .def_property_readonly("ProtocolTokens", &ObjCCategoryDecl::ProtocolTokens)
    .def_property_readonly("Protocols", &ObjCCategoryDecl::Protocols);
}
} // namespace pasta
