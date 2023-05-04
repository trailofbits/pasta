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

void RegisterUsingType(py::module_ &m) {
  py::class_<UsingType, Type>(m, "UsingType")
    .def_property_readonly("Desugar", &UsingType::Desugar)
    .def_property_readonly("FoundDeclaration", &UsingType::FoundDeclaration)
    .def_property_readonly("UnderlyingType", &UsingType::UnderlyingType)
    .def_property_readonly("IsSugared", &UsingType::IsSugared)
    .def_property_readonly("TypeMatchesDeclaration", &UsingType::TypeMatchesDeclaration);
}
} // namespace pasta
