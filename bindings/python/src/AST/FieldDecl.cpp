/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterFieldDecl(nb::module_ &m) {
  nb::class_<FieldDecl, DeclaratorDecl>(m, "FieldDecl")
    .def("__hash__", [](const FieldDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("bit_width", &FieldDecl::BitWidth)
    .def("bit_width_value", &FieldDecl::BitWidthValue)
    .def_prop_ro("canonical_declaration", &FieldDecl::CanonicalDeclaration)
    .def_prop_ro("captured_vla_type", &FieldDecl::CapturedVLAType)
    .def_prop_ro("field_index", &FieldDecl::FieldIndex)
    .def_prop_ro("in_class_initializer_style", &FieldDecl::InClassInitializerStyle)
    .def_prop_ro("in_class_initializer", &FieldDecl::InClassInitializer)
    .def_prop_ro("parent", &FieldDecl::Parent)
    .def_prop_ro("has_captured_vla_type", &FieldDecl::HasCapturedVLAType)
    .def_prop_ro("has_in_class_initializer", &FieldDecl::HasInClassInitializer)
    .def_prop_ro("is_anonymous_struct_or_union", &FieldDecl::IsAnonymousStructOrUnion)
    .def_prop_ro("is_bit_field", &FieldDecl::IsBitField)
    .def_prop_ro("is_mutable", &FieldDecl::IsMutable)
    .def_prop_ro("is_unnamed_bitfield", &FieldDecl::IsUnnamedBitfield)
    .def("is_zero_length_bit_field", &FieldDecl::IsZeroLengthBitField)
    .def("is_zero_size", &FieldDecl::IsZeroSize);
}
} // namespace pasta
