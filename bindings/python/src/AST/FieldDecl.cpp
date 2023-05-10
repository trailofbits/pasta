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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterFieldDecl(py::module_ &m) {
  py::class_<FieldDecl, DeclaratorDecl>(m, "FieldDecl")
    .def("__hash__", [](const FieldDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const FieldDecl& a, const FieldDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("bit_width", &FieldDecl::BitWidth)
    .def("bit_width_value", &FieldDecl::BitWidthValue)
    .def_property_readonly("canonical_declaration", &FieldDecl::CanonicalDeclaration)
    .def_property_readonly("captured_vla_type", &FieldDecl::CapturedVLAType)
    .def_property_readonly("field_index", &FieldDecl::FieldIndex)
    .def_property_readonly("in_class_initializer_style", &FieldDecl::InClassInitializerStyle)
    .def_property_readonly("in_class_initializer", &FieldDecl::InClassInitializer)
    .def_property_readonly("parent", &FieldDecl::Parent)
    .def_property_readonly("has_captured_vla_type", &FieldDecl::HasCapturedVLAType)
    .def_property_readonly("has_in_class_initializer", &FieldDecl::HasInClassInitializer)
    .def_property_readonly("is_anonymous_struct_or_union", &FieldDecl::IsAnonymousStructOrUnion)
    .def_property_readonly("is_bit_field", &FieldDecl::IsBitField)
    .def_property_readonly("is_mutable", &FieldDecl::IsMutable)
    .def_property_readonly("is_unnamed_bitfield", &FieldDecl::IsUnnamedBitfield)
    .def("is_zero_length_bit_field", &FieldDecl::IsZeroLengthBitField)
    .def("is_zero_size", &FieldDecl::IsZeroSize);
}
} // namespace pasta
