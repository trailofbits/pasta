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
  py::class_<StringLiteral, Expr, Stmt, ValueStmt>(m, "StringLiteral")
    .def("__hash__", [](const StringLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const StringLiteral& a, const StringLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &StringLiteral::Children)
    .def_property_readonly("ContainsNonAscii", &StringLiteral::ContainsNonAscii)
    .def_property_readonly("ContainsNonAsciiOrNull", &StringLiteral::ContainsNonAsciiOrNull)
    .def_property_readonly("BeginToken", &StringLiteral::BeginToken)
    .def_property_readonly("ByteLength", &StringLiteral::ByteLength)
    .def_property_readonly("Bytes", &StringLiteral::Bytes)
    .def_property_readonly("CharacterByteWidth", &StringLiteral::CharacterByteWidth)
    .def_property_readonly("EndToken", &StringLiteral::EndToken)
    .def_property_readonly("Kind", &StringLiteral::Kind)
    .def_property_readonly("Length", &StringLiteral::Length)
    .def_property_readonly("NumConcatenated", &StringLiteral::NumConcatenated)
    .def_property_readonly("String", &StringLiteral::String)
    .def_property_readonly("IsOrdinary", &StringLiteral::IsOrdinary)
    .def_property_readonly("IsPascal", &StringLiteral::IsPascal)
    .def_property_readonly("IsUTF16", &StringLiteral::IsUTF16)
    .def_property_readonly("IsUTF32", &StringLiteral::IsUTF32)
    .def_property_readonly("IsUTF8", &StringLiteral::IsUTF8)
    .def_property_readonly("IsWide", &StringLiteral::IsWide);
}
} // namespace pasta
