/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterStringLiteral(nb::module_ &m) {
  nb::class_<StringLiteral, Expr>(m, "StringLiteral")
    .def("__hash__", [](const StringLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &StringLiteral::Children)
    .def_prop_ro("contains_non_ascii", &StringLiteral::ContainsNonAscii)
    .def_prop_ro("contains_non_ascii_or_null", &StringLiteral::ContainsNonAsciiOrNull)
    .def_prop_ro("begin_token", &StringLiteral::BeginToken)
    .def_prop_ro("byte_length", &StringLiteral::ByteLength)
    .def_prop_ro("bytes", &StringLiteral::Bytes)
    .def_prop_ro("character_byte_width", &StringLiteral::CharacterByteWidth)
    .def_prop_ro("end_token", &StringLiteral::EndToken)
    .def_prop_ro("kind", &StringLiteral::Kind)
    .def_prop_ro("length", &StringLiteral::Length)
    .def_prop_ro("num_concatenated", &StringLiteral::NumConcatenated)
    .def_prop_ro("string", &StringLiteral::String)
    .def_prop_ro("is_ordinary", &StringLiteral::IsOrdinary)
    .def_prop_ro("is_pascal", &StringLiteral::IsPascal)
    .def_prop_ro("is_utf16", &StringLiteral::IsUTF16)
    .def_prop_ro("is_utf32", &StringLiteral::IsUTF32)
    .def_prop_ro("is_utf8", &StringLiteral::IsUTF8)
    .def_prop_ro("is_wide", &StringLiteral::IsWide);
}
} // namespace pasta
