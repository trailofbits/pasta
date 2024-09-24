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

void RegisterDependentSizedArrayType(nb::module_ &m) {
  nb::class_<DependentSizedArrayType, ArrayType>(m, "DependentSizedArrayType")
    .def_prop_ro("desugar", &DependentSizedArrayType::Desugar)
    .def_prop_ro("brackets_range", &DependentSizedArrayType::BracketsRange)
    .def_prop_ro("l_bracket_token", &DependentSizedArrayType::LBracketToken)
    .def_prop_ro("r_bracket_token", &DependentSizedArrayType::RBracketToken)
    .def_prop_ro("size_expression", &DependentSizedArrayType::SizeExpression)
    .def_prop_ro("is_sugared", &DependentSizedArrayType::IsSugared);
}
} // namespace pasta
