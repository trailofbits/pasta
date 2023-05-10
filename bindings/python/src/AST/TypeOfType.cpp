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

void RegisterTypeOfType(py::module_ &m) {
  py::class_<TypeOfType, Type>(m, "TypeOfType")
    .def("__hash__", [](const TypeOfType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TypeOfType& a, const TypeOfType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &TypeOfType::Desugar)
    .def_property_readonly("kind", &TypeOfType::Kind)
    .def_property_readonly("unmodified_type", &TypeOfType::UnmodifiedType)
    .def_property_readonly("is_sugared", &TypeOfType::IsSugared);
}
} // namespace pasta
