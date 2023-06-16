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

void RegisterDependentAddressSpaceType(nb::module_ &m) {
  nb::class_<DependentAddressSpaceType, Type>(m, "DependentAddressSpaceType")
    .def("__hash__", [](const DependentAddressSpaceType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &DependentAddressSpaceType::Desugar)
    .def_prop_ro("address_space_expression", &DependentAddressSpaceType::AddressSpaceExpression)
    .def_prop_ro("attribute_token", &DependentAddressSpaceType::AttributeToken)
    .def_prop_ro("pointee_type", &DependentAddressSpaceType::PointeeType)
    .def_prop_ro("is_sugared", &DependentAddressSpaceType::IsSugared);
}
} // namespace pasta
