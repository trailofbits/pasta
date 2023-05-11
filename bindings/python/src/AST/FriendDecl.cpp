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

void RegisterFriendDecl(py::module_ &m) {
  py::class_<FriendDecl, Decl>(m, "FriendDecl")
    .def("__hash__", [](const FriendDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("friend_declaration", &FriendDecl::FriendDeclaration)
    .def_property_readonly("friend_token", &FriendDecl::FriendToken)
    .def_property_readonly("friend_type", &FriendDecl::FriendType)
    .def_property_readonly("friend_type_num_template_parameter_lists", &FriendDecl::FriendTypeNumTemplateParameterLists)
    .def_property_readonly("is_unsupported_friend", &FriendDecl::IsUnsupportedFriend);
}
} // namespace pasta
