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

void RegisterDecayedType(py::module_ &m) {
  py::class_<DecayedType, AdjustedType, Type>(m, "DecayedType")
    .def_property_readonly("ResolvedType", &DecayedType::ResolvedType)
    .def_property_readonly("PointeeType", &DecayedType::PointeeType);
}
} // namespace pasta
