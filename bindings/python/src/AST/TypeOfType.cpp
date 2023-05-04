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

void RegisterTypeOfType(py::module_ &m) {
  py::class_<TypeOfType, Type>(m, "TypeOfType")
    .def_property_readonly("Desugar", &TypeOfType::Desugar)
    .def_property_readonly("Kind", &TypeOfType::Kind)
    .def_property_readonly("UnmodifiedType", &TypeOfType::UnmodifiedType)
    .def_property_readonly("IsSugared", &TypeOfType::IsSugared);
}
} // namespace pasta
