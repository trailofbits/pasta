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

void RegisterObjCObjectType(py::module_ &m) {
  py::class_<ObjCObjectType, Type>(m, "ObjCObjectType")
    .def_property_readonly("Desugar", &ObjCObjectType::Desugar)
    .def_property_readonly("BaseType", &ObjCObjectType::BaseType)
    .def_property_readonly("Interface", &ObjCObjectType::Interface)
    .def_property_readonly("SuperClassType", &ObjCObjectType::SuperClassType)
    .def_property_readonly("TypeArguments", &ObjCObjectType::TypeArguments)
    .def_property_readonly("TypeArgumentsAsWritten", &ObjCObjectType::TypeArgumentsAsWritten)
    .def_property_readonly("IsKindOfType", &ObjCObjectType::IsKindOfType)
    .def_property_readonly("IsKindOfTypeAsWritten", &ObjCObjectType::IsKindOfTypeAsWritten)
    .def_property_readonly("IsObjCClass", &ObjCObjectType::IsObjCClass)
    .def_property_readonly("IsObjCId", &ObjCObjectType::IsObjCId)
    .def_property_readonly("IsObjCQualifiedClass", &ObjCObjectType::IsObjCQualifiedClass)
    .def_property_readonly("IsObjCQualifiedId", &ObjCObjectType::IsObjCQualifiedId)
    .def_property_readonly("IsObjCUnqualifiedClass", &ObjCObjectType::IsObjCUnqualifiedClass)
    .def_property_readonly("IsObjCUnqualifiedId", &ObjCObjectType::IsObjCUnqualifiedId)
    .def_property_readonly("IsObjCUnqualifiedIdOrClass", &ObjCObjectType::IsObjCUnqualifiedIdOrClass)
    .def_property_readonly("IsSpecialized", &ObjCObjectType::IsSpecialized)
    .def_property_readonly("IsSpecializedAsWritten", &ObjCObjectType::IsSpecializedAsWritten)
    .def_property_readonly("IsSugared", &ObjCObjectType::IsSugared)
    .def_property_readonly("IsUnspecialized", &ObjCObjectType::IsUnspecialized)
    .def_property_readonly("IsUnspecializedAsWritten", &ObjCObjectType::IsUnspecializedAsWritten)
    .def("StripObjCKindOfTypeAndQualifiers", &ObjCObjectType::StripObjCKindOfTypeAndQualifiers);
}
} // namespace pasta
