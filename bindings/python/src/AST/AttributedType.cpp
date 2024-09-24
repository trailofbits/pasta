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

void RegisterAttributedType(nb::module_ &m) {
  nb::class_<AttributedType, Type>(m, "AttributedType")
    .def_prop_ro("desugar", &AttributedType::Desugar)
    .def_prop_ro("attribute", &AttributedType::Attribute)
    .def_prop_ro("attribute_kind", &AttributedType::AttributeKind)
    .def_prop_ro("equivalent_type", &AttributedType::EquivalentType)
    .def_prop_ro("immediate_nullability", &AttributedType::ImmediateNullability)
    .def_prop_ro("modified_type", &AttributedType::ModifiedType)
    .def_prop_ro("has_attribute", &AttributedType::HasAttribute)
    .def_prop_ro("is_calling_conv", &AttributedType::IsCallingConv)
    .def_prop_ro("is_ms_type_spec", &AttributedType::IsMSTypeSpec)
    .def_prop_ro("is_qualifier", &AttributedType::IsQualifier)
    .def_prop_ro("is_sugared", &AttributedType::IsSugared)
    .def_prop_ro("is_web_assembly_funcref_spec", &AttributedType::IsWebAssemblyFuncrefSpec);
}
} // namespace pasta
