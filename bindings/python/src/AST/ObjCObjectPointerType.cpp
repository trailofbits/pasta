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

void RegisterObjCObjectPointerType(py::module_ &m) {
  py::class_<ObjCObjectPointerType, Type>(m, "ObjCObjectPointerType")
    .def_property_readonly("Desugar", &ObjCObjectPointerType::Desugar)
    .def_property_readonly("InterfaceDeclaration", &ObjCObjectPointerType::InterfaceDeclaration)
    .def_property_readonly("InterfaceType", &ObjCObjectPointerType::InterfaceType)
    .def_property_readonly("NumProtocols", &ObjCObjectPointerType::NumProtocols)
    .def_property_readonly("ObjectType", &ObjCObjectPointerType::ObjectType)
    .def_property_readonly("PointeeType", &ObjCObjectPointerType::PointeeType)
    .def_property_readonly("SuperClassType", &ObjCObjectPointerType::SuperClassType)
    .def_property_readonly("TypeArguments", &ObjCObjectPointerType::TypeArguments)
    .def_property_readonly("TypeArgumentsAsWritten", &ObjCObjectPointerType::TypeArgumentsAsWritten)
    .def_property_readonly("IsKindOfType", &ObjCObjectPointerType::IsKindOfType)
    .def_property_readonly("IsObjCClassType", &ObjCObjectPointerType::IsObjCClassType)
    .def_property_readonly("IsObjCIdOrClassType", &ObjCObjectPointerType::IsObjCIdOrClassType)
    .def_property_readonly("IsObjCIdType", &ObjCObjectPointerType::IsObjCIdType)
    .def_property_readonly("IsObjCQualifiedClassType", &ObjCObjectPointerType::IsObjCQualifiedClassType)
    .def_property_readonly("IsObjCQualifiedIdType", &ObjCObjectPointerType::IsObjCQualifiedIdType)
    .def_property_readonly("IsSpecialized", &ObjCObjectPointerType::IsSpecialized)
    .def_property_readonly("IsSpecializedAsWritten", &ObjCObjectPointerType::IsSpecializedAsWritten)
    .def_property_readonly("IsSugared", &ObjCObjectPointerType::IsSugared)
    .def_property_readonly("IsUnspecialized", &ObjCObjectPointerType::IsUnspecialized)
    .def_property_readonly("IsUnspecializedAsWritten", &ObjCObjectPointerType::IsUnspecializedAsWritten)
    .def_property_readonly("Qualifiers", &ObjCObjectPointerType::Qualifiers)
    .def("StripObjCKindOfTypeAndQualifiers", &ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers);
}
} // namespace pasta
