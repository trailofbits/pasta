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

void RegisterObjCCategoryDecl(py::module_ &m) {
  py::class_<ObjCCategoryDecl, ObjCContainerDecl>(m, "ObjCCategoryDecl")
    .def("__hash__", [](const ObjCCategoryDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("is_class_extension", &ObjCCategoryDecl::IsClassExtension)
    .def_property_readonly("category_name_token", &ObjCCategoryDecl::CategoryNameToken)
    .def_property_readonly("class_interface", &ObjCCategoryDecl::ClassInterface)
    .def_property_readonly("implementation", &ObjCCategoryDecl::Implementation)
    .def_property_readonly("instance_variable_l_brace_token", &ObjCCategoryDecl::InstanceVariableLBraceToken)
    .def_property_readonly("instance_variable_r_brace_token", &ObjCCategoryDecl::InstanceVariableRBraceToken)
    .def_property_readonly("next_class_category", &ObjCCategoryDecl::NextClassCategory)
    .def_property_readonly("next_class_category_raw", &ObjCCategoryDecl::NextClassCategoryRaw)
    .def_property_readonly("instance_variables", &ObjCCategoryDecl::InstanceVariables)
    .def_property_readonly("protocol_tokens", &ObjCCategoryDecl::ProtocolTokens)
    .def_property_readonly("protocols", &ObjCCategoryDecl::Protocols);
}
} // namespace pasta
