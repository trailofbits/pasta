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

void RegisterReferenceType(nb::module_ &m) {
  nb::class_<ReferenceType, Type>(m, "ReferenceType")
    .def_prop_ro("pointee_type", &ReferenceType::PointeeType)
    .def_prop_ro("pointee_type_as_written", &ReferenceType::PointeeTypeAsWritten)
    .def_prop_ro("is_inner_reference", &ReferenceType::IsInnerReference)
    .def_prop_ro("is_spelled_as_l_value", &ReferenceType::IsSpelledAsLValue);
}
} // namespace pasta
