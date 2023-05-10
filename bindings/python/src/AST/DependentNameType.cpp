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

void RegisterDependentNameType(py::module_ &m) {
  py::class_<DependentNameType, TypeWithKeyword>(m, "DependentNameType")
    .def("__hash__", [](const DependentNameType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentNameType& a, const DependentNameType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DependentNameType::Desugar)
    .def_property_readonly("is_sugared", &DependentNameType::IsSugared);
}
} // namespace pasta
