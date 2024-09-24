/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterDependentAddressSpaceType(nb::module_ &m) {
  nb::class_<DependentAddressSpaceType, Type>(m, "DependentAddressSpaceType")
    .def_prop_ro("desugar", &DependentAddressSpaceType::Desugar)
    .def_prop_ro("address_space_expression", &DependentAddressSpaceType::AddressSpaceExpression)
    .def_prop_ro("attribute_token", &DependentAddressSpaceType::AttributeToken)
    .def_prop_ro("pointee_type", &DependentAddressSpaceType::PointeeType)
    .def_prop_ro("is_sugared", &DependentAddressSpaceType::IsSugared);
}
} // namespace pasta
