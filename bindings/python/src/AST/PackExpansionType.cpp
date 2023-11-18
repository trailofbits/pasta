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

void RegisterPackExpansionType(nb::module_ &m) {
  nb::class_<PackExpansionType, Type>(m, "PackExpansionType")
    .def_prop_ro("desugar", &PackExpansionType::Desugar)
    .def_prop_ro("num_expansions", &PackExpansionType::NumExpansions)
    .def_prop_ro("pattern", &PackExpansionType::Pattern)
    .def_prop_ro("is_sugared", &PackExpansionType::IsSugared);
}
} // namespace pasta
