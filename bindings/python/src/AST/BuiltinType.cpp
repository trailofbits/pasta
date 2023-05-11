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

void RegisterBuiltinType(py::module_ &m) {
  py::class_<BuiltinType, Type>(m, "BuiltinType")
    .def("__hash__", [](const BuiltinType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &BuiltinType::Desugar)
    .def_property_readonly("kind", &BuiltinType::Kind)
    .def_property_readonly("is_floating_point", &BuiltinType::IsFloatingPoint)
    .def_property_readonly("is_integer", &BuiltinType::IsInteger)
    .def_property_readonly("is_non_overload_placeholder_type", &BuiltinType::IsNonOverloadPlaceholderType)
    .def_property_readonly("is_placeholder_type", &BuiltinType::IsPlaceholderType)
    .def_property_readonly("is_sve_bool", &BuiltinType::IsSVEBool)
    .def_property_readonly("is_signed_integer", &BuiltinType::IsSignedInteger)
    .def_property_readonly("is_sugared", &BuiltinType::IsSugared)
    .def_property_readonly("is_unsigned_integer", &BuiltinType::IsUnsignedInteger);
}
} // namespace pasta
