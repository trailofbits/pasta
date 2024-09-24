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

void RegisterDependentBitIntType(nb::module_ &m) {
  nb::class_<DependentBitIntType, Type>(m, "DependentBitIntType")
    .def_prop_ro("desugar", &DependentBitIntType::Desugar)
    .def_prop_ro("num_bits_expression", &DependentBitIntType::NumBitsExpression)
    .def_prop_ro("is_signed", &DependentBitIntType::IsSigned)
    .def_prop_ro("is_sugared", &DependentBitIntType::IsSugared)
    .def_prop_ro("is_unsigned", &DependentBitIntType::IsUnsigned);
}
} // namespace pasta
