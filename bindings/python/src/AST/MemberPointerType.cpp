/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterMemberPointerType(nb::module_ &m) {
  nb::class_<MemberPointerType, Type>(m, "MemberPointerType")
    .def("__hash__", [](const MemberPointerType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &MemberPointerType::Desugar)
    .def_prop_ro("class", &MemberPointerType::Class)
    .def_prop_ro("most_recent_cxx_record_declaration", &MemberPointerType::MostRecentCXXRecordDeclaration)
    .def_prop_ro("pointee_type", &MemberPointerType::PointeeType)
    .def_prop_ro("is_member_data_pointer", &MemberPointerType::IsMemberDataPointer)
    .def_prop_ro("is_member_function_pointer", &MemberPointerType::IsMemberFunctionPointer)
    .def_prop_ro("is_sugared", &MemberPointerType::IsSugared);
}
} // namespace pasta
