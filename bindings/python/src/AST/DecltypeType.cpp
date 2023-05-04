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

void RegisterDecltypeType(py::module_ &m) {
  py::class_<DecltypeType, Type>(m, "DecltypeType")
    .def("__hash__", [](const DecltypeType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DecltypeType& a, const DecltypeType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &DecltypeType::Desugar)
    .def_property_readonly("UnderlyingExpression", &DecltypeType::UnderlyingExpression)
    .def_property_readonly("UnderlyingType", &DecltypeType::UnderlyingType)
    .def_property_readonly("IsSugared", &DecltypeType::IsSugared);
}
} // namespace pasta
