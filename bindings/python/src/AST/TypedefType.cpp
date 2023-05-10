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

void RegisterTypedefType(py::module_ &m) {
  py::class_<TypedefType, Type>(m, "TypedefType")
    .def("__hash__", [](const TypedefType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TypedefType& a, const TypedefType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &TypedefType::Desugar)
    .def_property_readonly("declaration", &TypedefType::Declaration)
    .def_property_readonly("is_sugared", &TypedefType::IsSugared)
    .def_property_readonly("type_matches_declaration", &TypedefType::TypeMatchesDeclaration);
}
} // namespace pasta
