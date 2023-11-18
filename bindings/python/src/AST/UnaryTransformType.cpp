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

void RegisterUnaryTransformType(nb::module_ &m) {
  nb::class_<UnaryTransformType, Type>(m, "UnaryTransformType")
    .def_prop_ro("desugar", &UnaryTransformType::Desugar)
    .def_prop_ro("base_type", &UnaryTransformType::BaseType)
    .def_prop_ro("utt_kind", &UnaryTransformType::UTTKind)
    .def_prop_ro("underlying_type", &UnaryTransformType::UnderlyingType)
    .def_prop_ro("is_sugared", &UnaryTransformType::IsSugared);
}
} // namespace pasta
