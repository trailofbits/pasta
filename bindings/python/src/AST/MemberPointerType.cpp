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

void RegisterMemberPointerType(py::module_ &m) {
  py::class_<MemberPointerType, Type>(m, "MemberPointerType")
    .def("__hash__", [](const MemberPointerType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const MemberPointerType& a, const MemberPointerType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &MemberPointerType::Desugar)
    .def_property_readonly("Class", &MemberPointerType::Class)
    .def_property_readonly("MostRecentCXXRecordDeclaration", &MemberPointerType::MostRecentCXXRecordDeclaration)
    .def_property_readonly("PointeeType", &MemberPointerType::PointeeType)
    .def_property_readonly("IsMemberDataPointer", &MemberPointerType::IsMemberDataPointer)
    .def_property_readonly("IsMemberFunctionPointer", &MemberPointerType::IsMemberFunctionPointer)
    .def_property_readonly("IsSugared", &MemberPointerType::IsSugared);
}
} // namespace pasta
