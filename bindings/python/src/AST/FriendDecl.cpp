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

void RegisterFriendDecl(py::module_ &m) {
  py::class_<FriendDecl, Decl>(m, "FriendDecl")
    .def_property_readonly("FriendDeclaration", &FriendDecl::FriendDeclaration)
    .def_property_readonly("FriendToken", &FriendDecl::FriendToken)
    .def_property_readonly("FriendType", &FriendDecl::FriendType)
    .def_property_readonly("FriendTypeNumTemplateParameterLists", &FriendDecl::FriendTypeNumTemplateParameterLists)
    .def_property_readonly("IsUnsupportedFriend", &FriendDecl::IsUnsupportedFriend);
}
} // namespace pasta
