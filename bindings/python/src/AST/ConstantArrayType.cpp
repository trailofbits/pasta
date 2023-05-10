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

void RegisterConstantArrayType(py::module_ &m) {
  py::class_<ConstantArrayType, ArrayType>(m, "ConstantArrayType")
    .def("__hash__", [](const ConstantArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ConstantArrayType& a, const ConstantArrayType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &ConstantArrayType::Desugar)
    .def_property_readonly("size", &ConstantArrayType::Size)
    .def_property_readonly("size_expression", &ConstantArrayType::SizeExpression)
    .def_property_readonly("is_sugared", &ConstantArrayType::IsSugared);
}
} // namespace pasta
