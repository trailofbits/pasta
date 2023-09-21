/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCObjectPointerType(nb::module_ &m) {
  nb::class_<ObjCObjectPointerType, Type>(m, "ObjCObjectPointerType")
    .def("__hash__", [](const ObjCObjectPointerType &type) { return reinterpret_cast<intptr_t>(type.RawType()); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &ObjCObjectPointerType::Desugar)
    .def_prop_ro("interface_declaration", &ObjCObjectPointerType::InterfaceDeclaration)
    .def_prop_ro("interface_type", &ObjCObjectPointerType::InterfaceType)
    .def_prop_ro("num_protocols", &ObjCObjectPointerType::NumProtocols)
    .def_prop_ro("object_type", &ObjCObjectPointerType::ObjectType)
    .def_prop_ro("pointee_type", &ObjCObjectPointerType::PointeeType)
    .def_prop_ro("super_class_type", &ObjCObjectPointerType::SuperClassType)
    .def_prop_ro("type_arguments", &ObjCObjectPointerType::TypeArguments)
    .def_prop_ro("type_arguments_as_written", &ObjCObjectPointerType::TypeArgumentsAsWritten)
    .def_prop_ro("is_kind_of_type", &ObjCObjectPointerType::IsKindOfType)
    .def_prop_ro("is_obj_c_class_type", &ObjCObjectPointerType::IsObjCClassType)
    .def_prop_ro("is_obj_c_id_or_class_type", &ObjCObjectPointerType::IsObjCIdOrClassType)
    .def_prop_ro("is_obj_c_id_type", &ObjCObjectPointerType::IsObjCIdType)
    .def_prop_ro("is_obj_c_qualified_class_type", &ObjCObjectPointerType::IsObjCQualifiedClassType)
    .def_prop_ro("is_obj_c_qualified_id_type", &ObjCObjectPointerType::IsObjCQualifiedIdType)
    .def_prop_ro("is_specialized", &ObjCObjectPointerType::IsSpecialized)
    .def_prop_ro("is_specialized_as_written", &ObjCObjectPointerType::IsSpecializedAsWritten)
    .def_prop_ro("is_sugared", &ObjCObjectPointerType::IsSugared)
    .def_prop_ro("is_unspecialized", &ObjCObjectPointerType::IsUnspecialized)
    .def_prop_ro("is_unspecialized_as_written", &ObjCObjectPointerType::IsUnspecializedAsWritten)
    .def_prop_ro("qualifiers", &ObjCObjectPointerType::Qualifiers)
    .def_prop_ro("strip_obj_c_kind_of_type_and_qualifiers", &ObjCObjectPointerType::StripObjCKindOfTypeAndQualifiers);
}
} // namespace pasta
