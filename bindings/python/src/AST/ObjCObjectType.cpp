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

void RegisterObjCObjectType(py::module_ &m) {
  py::class_<ObjCObjectType, Type>(m, "ObjCObjectType")
    .def("__hash__", [](const ObjCObjectType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &ObjCObjectType::Desugar)
    .def_property_readonly("base_type", &ObjCObjectType::BaseType)
    .def_property_readonly("interface", &ObjCObjectType::Interface)
    .def_property_readonly("super_class_type", &ObjCObjectType::SuperClassType)
    .def_property_readonly("type_arguments", &ObjCObjectType::TypeArguments)
    .def_property_readonly("type_arguments_as_written", &ObjCObjectType::TypeArgumentsAsWritten)
    .def_property_readonly("is_kind_of_type", &ObjCObjectType::IsKindOfType)
    .def_property_readonly("is_kind_of_type_as_written", &ObjCObjectType::IsKindOfTypeAsWritten)
    .def_property_readonly("is_obj_c_class", &ObjCObjectType::IsObjCClass)
    .def_property_readonly("is_obj_c_id", &ObjCObjectType::IsObjCId)
    .def_property_readonly("is_obj_c_qualified_class", &ObjCObjectType::IsObjCQualifiedClass)
    .def_property_readonly("is_obj_c_qualified_id", &ObjCObjectType::IsObjCQualifiedId)
    .def_property_readonly("is_obj_c_unqualified_class", &ObjCObjectType::IsObjCUnqualifiedClass)
    .def_property_readonly("is_obj_c_unqualified_id", &ObjCObjectType::IsObjCUnqualifiedId)
    .def_property_readonly("is_obj_c_unqualified_id_or_class", &ObjCObjectType::IsObjCUnqualifiedIdOrClass)
    .def_property_readonly("is_specialized", &ObjCObjectType::IsSpecialized)
    .def_property_readonly("is_specialized_as_written", &ObjCObjectType::IsSpecializedAsWritten)
    .def_property_readonly("is_sugared", &ObjCObjectType::IsSugared)
    .def_property_readonly("is_unspecialized", &ObjCObjectType::IsUnspecialized)
    .def_property_readonly("is_unspecialized_as_written", &ObjCObjectType::IsUnspecializedAsWritten)
    .def("strip_obj_c_kind_of_type_and_qualifiers", &ObjCObjectType::StripObjCKindOfTypeAndQualifiers);
}
} // namespace pasta
