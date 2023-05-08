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
    .def("__hash__", [](const ObjCObjectPointerType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ObjCObjectPointerType& a, const ObjCObjectPointerType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &ObjCObjectPointerType::Desugar)
    .def_property_readonly("interface_declaration", &ObjCObjectPointerType::InterfaceDeclaration)
    .def_property_readonly("interface_type", &ObjCObjectPointerType::InterfaceType)
    .def_property_readonly("num_protocols", &ObjCObjectPointerType::NumProtocols)
    .def_property_readonly("object_type", &ObjCObjectPointerType::ObjectType)
    .def_property_readonly("pointee_type", &ObjCObjectPointerType::PointeeType)
    .def_property_readonly("super_class_type", &ObjCObjectPointerType::SuperClassType)
    .def_property_readonly("type_arguments", &ObjCObjectPointerType::TypeArguments)
    .def_property_readonly("type_arguments_as_written", &ObjCObjectPointerType::TypeArgumentsAsWritten)
    .def_property_readonly("is_kind_of_type", &ObjCObjectPointerType::IsKindOfType)
    .def_property_readonly("is_obj_c_class_type", &ObjCObjectPointerType::IsObjCClassType)
    .def_property_readonly("is_obj_c_id_or_class_type", &ObjCObjectPointerType::IsObjCIdOrClassType)
    .def_property_readonly("is_obj_c_id_type", &ObjCObjectPointerType::IsObjCIdType)
    .def_property_readonly("is_obj_c_qualified_class_type", &ObjCObjectPointerType::IsObjCQualifiedClassType)
    .def_property_readonly("is_obj_c_qualified_id_type", &ObjCObjectPointerType::IsObjCQualifiedIdType)
    .def_property_readonly("is_specialized", &ObjCObjectPointerType::IsSpecialized)
    .def_property_readonly("is_specialized_as_written", &ObjCObjectPointerType::IsSpecializedAsWritten)
    .def_property_readonly("is_sugared", &ObjCObjectPointerType::IsSugared)
    .def_property_readonly("is_unspecialized", &ObjCObjectPointerType::IsUnspecialized)
    .def_property_readonly("is_unspecialized_as_written", &ObjCObjectPointerType::IsUnspecializedAsWritten)
    .def_property_readonly("qualifiers", &ObjCObjectPointerType::Qualifiers)
    .def("strip_obj_c_kind_of_type_and_qualifiers", &ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers);
}
} // namespace pasta
