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

void RegisterParenType(py::module_ &m) {
  py::class_<ParenType, Type>(m, "ParenType")
    .def("__hash__", [](const ParenType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ParenType& a, const ParenType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &ParenType::Desugar)
    .def_property_readonly("InnerType", &ParenType::InnerType)
    .def_property_readonly("IsSugared", &ParenType::IsSugared);
}
} // namespace pasta
