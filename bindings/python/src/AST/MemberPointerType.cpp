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

void RegisterMemberPointerType(py::module_ &m) {
  py::class_<MemberPointerType, Type>(m, "MemberPointerType")
    .def("__hash__", [](const MemberPointerType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &MemberPointerType::Desugar)
    .def_property_readonly("class", &MemberPointerType::Class)
    .def_property_readonly("most_recent_cxx_record_declaration", &MemberPointerType::MostRecentCXXRecordDeclaration)
    .def_property_readonly("pointee_type", &MemberPointerType::PointeeType)
    .def_property_readonly("is_member_data_pointer", &MemberPointerType::IsMemberDataPointer)
    .def_property_readonly("is_member_function_pointer", &MemberPointerType::IsMemberFunctionPointer)
    .def_property_readonly("is_sugared", &MemberPointerType::IsSugared);
}
} // namespace pasta
