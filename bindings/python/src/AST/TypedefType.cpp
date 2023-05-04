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

void RegisterTypedefType(py::module_ &m) {
  py::class_<TypedefType, Type>(m, "TypedefType")
    .def_property_readonly("Desugar", &TypedefType::Desugar)
    .def_property_readonly("Declaration", &TypedefType::Declaration)
    .def_property_readonly("IsSugared", &TypedefType::IsSugared)
    .def_property_readonly("TypeMatchesDeclaration", &TypedefType::TypeMatchesDeclaration);
}
} // namespace pasta
