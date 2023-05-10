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

void RegisterParenType(py::module_ &m) {
  py::class_<ParenType, Type>(m, "ParenType")
    .def("__hash__", [](const ParenType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ParenType& a, const ParenType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &ParenType::Desugar)
    .def_property_readonly("inner_type", &ParenType::InnerType)
    .def_property_readonly("is_sugared", &ParenType::IsSugared);
}
} // namespace pasta
