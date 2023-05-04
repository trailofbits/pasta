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

void RegisterConstantArrayType(py::module_ &m) {
  py::class_<ConstantArrayType, ArrayType, Type>(m, "ConstantArrayType")
    .def_property_readonly("Desugar", &ConstantArrayType::Desugar)
    .def_property_readonly("Size", &ConstantArrayType::Size)
    .def_property_readonly("SizeExpression", &ConstantArrayType::SizeExpression)
    .def_property_readonly("IsSugared", &ConstantArrayType::IsSugared);
}
} // namespace pasta
