/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterStringLiteral(py::module_ &m) {
  py::class_<StringLiteral, Expr>(m, "StringLiteral")
    .def("__hash__", [](const StringLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const StringLiteral& a, const StringLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &StringLiteral::Children)
    .def_property_readonly("contains_non_ascii", &StringLiteral::ContainsNonAscii)
    .def_property_readonly("contains_non_ascii_or_null", &StringLiteral::ContainsNonAsciiOrNull)
    .def_property_readonly("begin_token", &StringLiteral::BeginToken)
    .def_property_readonly("byte_length", &StringLiteral::ByteLength)
    .def_property_readonly("bytes", &StringLiteral::Bytes)
    .def_property_readonly("character_byte_width", &StringLiteral::CharacterByteWidth)
    .def_property_readonly("end_token", &StringLiteral::EndToken)
    .def_property_readonly("kind", &StringLiteral::Kind)
    .def_property_readonly("length", &StringLiteral::Length)
    .def_property_readonly("num_concatenated", &StringLiteral::NumConcatenated)
    .def_property_readonly("string", &StringLiteral::String)
    .def_property_readonly("is_ordinary", &StringLiteral::IsOrdinary)
    .def_property_readonly("is_pascal", &StringLiteral::IsPascal)
    .def_property_readonly("is_utf16", &StringLiteral::IsUTF16)
    .def_property_readonly("is_utf32", &StringLiteral::IsUTF32)
    .def_property_readonly("is_utf8", &StringLiteral::IsUTF8)
    .def_property_readonly("is_wide", &StringLiteral::IsWide);
}
} // namespace pasta
