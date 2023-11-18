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

void RegisterIncompleteArrayType(nb::module_ &m) {
  nb::class_<IncompleteArrayType, ArrayType>(m, "IncompleteArrayType")
    .def_prop_ro("desugar", &IncompleteArrayType::Desugar)
    .def_prop_ro("is_sugared", &IncompleteArrayType::IsSugared);
}
} // namespace pasta
