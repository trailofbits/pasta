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

void RegisterMemberPointerType(nb::module_ &m) {
  nb::class_<MemberPointerType, Type>(m, "MemberPointerType")
    .def_prop_ro("desugar", &MemberPointerType::Desugar)
    .def_prop_ro("class", &MemberPointerType::Class)
    .def_prop_ro("most_recent_cxx_record_declaration", &MemberPointerType::MostRecentCXXRecordDeclaration)
    .def_prop_ro("pointee_type", &MemberPointerType::PointeeType)
    .def_prop_ro("is_member_data_pointer", &MemberPointerType::IsMemberDataPointer)
    .def_prop_ro("is_member_function_pointer", &MemberPointerType::IsMemberFunctionPointer)
    .def_prop_ro("is_sugared", &MemberPointerType::IsSugared);
}
} // namespace pasta
