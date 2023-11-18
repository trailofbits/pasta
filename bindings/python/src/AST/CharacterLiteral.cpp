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

void RegisterCharacterLiteral(nb::module_ &m) {
  nb::class_<CharacterLiteral, Expr>(m, "CharacterLiteral")
    .def_prop_ro("children", &CharacterLiteral::Children)
    .def_prop_ro("begin_token", &CharacterLiteral::BeginToken)
    .def_prop_ro("end_token", &CharacterLiteral::EndToken)
    .def_prop_ro("literal_kind", &CharacterLiteral::LiteralKind)
    .def_prop_ro("token", &CharacterLiteral::Token)
    .def_prop_ro("value", &CharacterLiteral::Value);
}
} // namespace pasta
