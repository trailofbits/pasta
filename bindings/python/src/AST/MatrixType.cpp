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

void RegisterMatrixType(nb::module_ &m) {
  nb::class_<MatrixType, Type>(m, "MatrixType")
    .def_prop_ro("desugar", &MatrixType::Desugar)
    .def_prop_ro("element_type", &MatrixType::ElementType)
    .def_prop_ro("is_sugared", &MatrixType::IsSugared);
}
} // namespace pasta
