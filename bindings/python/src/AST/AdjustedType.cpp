/*
 * Copyright (c) 2023 Trail of Bits, Inc.
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

void RegisterAdjustedType(nb::module_ &m) {
  nb::class_<AdjustedType, Type>(m, "AdjustedType")
    .def_prop_ro("desugar", &AdjustedType::Desugar)
    .def_prop_ro("resolved_type", &AdjustedType::ResolvedType)
    .def_prop_ro("original_type", &AdjustedType::OriginalType)
    .def_prop_ro("is_sugared", &AdjustedType::IsSugared);
}
} // namespace pasta
