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

void RegisterFriendDecl(nb::module_ &m) {
  nb::class_<FriendDecl, Decl>(m, "FriendDecl")
    .def_prop_ro("friend_declaration", &FriendDecl::FriendDeclaration)
    .def_prop_ro("friend_token", &FriendDecl::FriendToken)
    .def_prop_ro("friend_type", &FriendDecl::FriendType)
    .def_prop_ro("friend_type_num_template_parameter_lists", &FriendDecl::FriendTypeNumTemplateParameterLists)
    .def_prop_ro("is_unsupported_friend", &FriendDecl::IsUnsupportedFriend);
}
} // namespace pasta
