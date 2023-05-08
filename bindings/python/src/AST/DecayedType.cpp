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
  py::class_<DecayedType, AdjustedType>(m, "DecayedType")
    .def("__hash__", [](const DecayedType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DecayedType& a, const DecayedType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("resolved_type", &DecayedType::ResolvedType)
    .def_property_readonly("pointee_type", &DecayedType::PointeeType);
}
} // namespace pasta
