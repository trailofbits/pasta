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

void RegisterUnaryTransformType(py::module_ &m) {
  py::class_<UnaryTransformType, Type>(m, "UnaryTransformType")
    .def_property_readonly("Desugar", &UnaryTransformType::Desugar)
    .def_property_readonly("BaseType", &UnaryTransformType::BaseType)
    .def_property_readonly("UTTKind", &UnaryTransformType::UTTKind)
    .def_property_readonly("UnderlyingType", &UnaryTransformType::UnderlyingType)
    .def_property_readonly("IsSugared", &UnaryTransformType::IsSugared);
}
} // namespace pasta
