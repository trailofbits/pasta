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

void RegisterDeducedType(nb::module_ &m) {
  nb::class_<DeducedType, Type>(m, "DeducedType")
    .def_prop_ro("desugar", &DeducedType::Desugar)
    .def_prop_ro("resolved_type", &DeducedType::ResolvedType)
    .def_prop_ro("is_deduced", &DeducedType::IsDeduced)
    .def_prop_ro("is_sugared", &DeducedType::IsSugared);
}
} // namespace pasta
