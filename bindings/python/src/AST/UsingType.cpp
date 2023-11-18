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

void RegisterUsingType(nb::module_ &m) {
  nb::class_<UsingType, Type>(m, "UsingType")
    .def_prop_ro("desugar", &UsingType::Desugar)
    .def_prop_ro("found_declaration", &UsingType::FoundDeclaration)
    .def_prop_ro("underlying_type", &UsingType::UnderlyingType)
    .def_prop_ro("is_sugared", &UsingType::IsSugared)
    .def_prop_ro("type_matches_declaration", &UsingType::TypeMatchesDeclaration);
}
} // namespace pasta
