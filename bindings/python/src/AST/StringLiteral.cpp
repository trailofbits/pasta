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

void RegisterStringLiteral(nb::module_ &m) {
  nb::class_<StringLiteral, Expr>(m, "StringLiteral")
    .def_prop_ro("children", &StringLiteral::Children)
    .def_prop_ro("contains_non_ascii", &StringLiteral::ContainsNonAscii)
    .def_prop_ro("contains_non_ascii_or_null", &StringLiteral::ContainsNonAsciiOrNull)
    .def_prop_ro("begin_token", &StringLiteral::BeginToken)
    .def_prop_ro("byte_length", &StringLiteral::ByteLength)
    .def_prop_ro("bytes", &StringLiteral::Bytes)
    .def_prop_ro("character_byte_width", &StringLiteral::CharacterByteWidth)
    .def_prop_ro("end_token", &StringLiteral::EndToken)
    .def_prop_ro("literal_kind", &StringLiteral::LiteralKind)
    .def_prop_ro("length", &StringLiteral::Length)
    .def_prop_ro("num_concatenated", &StringLiteral::NumConcatenated)
    .def_prop_ro("string", &StringLiteral::String)
    .def_prop_ro("is_ordinary", &StringLiteral::IsOrdinary)
    .def_prop_ro("is_pascal", &StringLiteral::IsPascal)
    .def_prop_ro("is_utf16", &StringLiteral::IsUTF16)
    .def_prop_ro("is_utf32", &StringLiteral::IsUTF32)
    .def_prop_ro("is_utf8", &StringLiteral::IsUTF8)
    .def_prop_ro("is_unevaluated", &StringLiteral::IsUnevaluated)
    .def_prop_ro("is_wide", &StringLiteral::IsWide);
}
} // namespace pasta
