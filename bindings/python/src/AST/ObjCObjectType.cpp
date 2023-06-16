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

void RegisterObjCObjectType(nb::module_ &m) {
  nb::class_<ObjCObjectType, Type>(m, "ObjCObjectType")
    .def("__hash__", [](const ObjCObjectType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &ObjCObjectType::Desugar)
    .def_prop_ro("base_type", &ObjCObjectType::BaseType)
    .def_prop_ro("interface", &ObjCObjectType::Interface)
    .def_prop_ro("super_class_type", &ObjCObjectType::SuperClassType)
    .def_prop_ro("type_arguments", &ObjCObjectType::TypeArguments)
    .def_prop_ro("type_arguments_as_written", &ObjCObjectType::TypeArgumentsAsWritten)
    .def_prop_ro("is_kind_of_type", &ObjCObjectType::IsKindOfType)
    .def_prop_ro("is_kind_of_type_as_written", &ObjCObjectType::IsKindOfTypeAsWritten)
    .def_prop_ro("is_obj_c_class", &ObjCObjectType::IsObjCClass)
    .def_prop_ro("is_obj_c_id", &ObjCObjectType::IsObjCId)
    .def_prop_ro("is_obj_c_qualified_class", &ObjCObjectType::IsObjCQualifiedClass)
    .def_prop_ro("is_obj_c_qualified_id", &ObjCObjectType::IsObjCQualifiedId)
    .def_prop_ro("is_obj_c_unqualified_class", &ObjCObjectType::IsObjCUnqualifiedClass)
    .def_prop_ro("is_obj_c_unqualified_id", &ObjCObjectType::IsObjCUnqualifiedId)
    .def_prop_ro("is_obj_c_unqualified_id_or_class", &ObjCObjectType::IsObjCUnqualifiedIdOrClass)
    .def_prop_ro("is_specialized", &ObjCObjectType::IsSpecialized)
    .def_prop_ro("is_specialized_as_written", &ObjCObjectType::IsSpecializedAsWritten)
    .def_prop_ro("is_sugared", &ObjCObjectType::IsSugared)
    .def_prop_ro("is_unspecialized", &ObjCObjectType::IsUnspecialized)
    .def_prop_ro("is_unspecialized_as_written", &ObjCObjectType::IsUnspecializedAsWritten)
    .def("strip_obj_c_kind_of_type_and_qualifiers", &ObjCObjectType::StripObjCKindOfTypeAndQualifiers);
}
} // namespace pasta
