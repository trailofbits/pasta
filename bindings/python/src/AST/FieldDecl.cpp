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

void RegisterFieldDecl(py::module_ &m) {
  py::class_<FieldDecl, DeclaratorDecl>(m, "FieldDecl")
    .def("__hash__", [](const FieldDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const FieldDecl& a, const FieldDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("BitWidth", &FieldDecl::BitWidth)
    .def("BitWidthValue", &FieldDecl::BitWidthValue)
    .def_property_readonly("CanonicalDeclaration", &FieldDecl::CanonicalDeclaration)
    .def_property_readonly("CapturedVLAType", &FieldDecl::CapturedVLAType)
    .def_property_readonly("FieldIndex", &FieldDecl::FieldIndex)
    .def_property_readonly("InClassInitializerStyle", &FieldDecl::InClassInitializerStyle)
    .def_property_readonly("InClassInitializer", &FieldDecl::InClassInitializer)
    .def_property_readonly("Parent", &FieldDecl::Parent)
    .def_property_readonly("HasCapturedVLAType", &FieldDecl::HasCapturedVLAType)
    .def_property_readonly("HasInClassInitializer", &FieldDecl::HasInClassInitializer)
    .def_property_readonly("IsAnonymousStructOrUnion", &FieldDecl::IsAnonymousStructOrUnion)
    .def_property_readonly("IsBitField", &FieldDecl::IsBitField)
    .def_property_readonly("IsMutable", &FieldDecl::IsMutable)
    .def_property_readonly("IsUnnamedBitfield", &FieldDecl::IsUnnamedBitfield)
    .def("IsZeroLengthBitField", &FieldDecl::IsZeroLengthBitField)
    .def("IsZeroSize", &FieldDecl::IsZeroSize);
}
} // namespace pasta
