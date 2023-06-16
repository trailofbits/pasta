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

void RegisterBuiltinType(nb::module_ &m) {
  nb::class_<BuiltinType, Type>(m, "BuiltinType")
    .def("__hash__", [](const BuiltinType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &BuiltinType::Desugar)
    .def_prop_ro("kind", &BuiltinType::Kind)
    .def_prop_ro("is_floating_point", &BuiltinType::IsFloatingPoint)
    .def_prop_ro("is_integer", &BuiltinType::IsInteger)
    .def_prop_ro("is_non_overload_placeholder_type", &BuiltinType::IsNonOverloadPlaceholderType)
    .def_prop_ro("is_placeholder_type", &BuiltinType::IsPlaceholderType)
    .def_prop_ro("is_sve_bool", &BuiltinType::IsSVEBool)
    .def_prop_ro("is_signed_integer", &BuiltinType::IsSignedInteger)
    .def_prop_ro("is_sugared", &BuiltinType::IsSugared)
    .def_prop_ro("is_unsigned_integer", &BuiltinType::IsUnsignedInteger);
}
} // namespace pasta
