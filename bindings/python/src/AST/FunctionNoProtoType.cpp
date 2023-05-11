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

void RegisterFunctionNoProtoType(py::module_ &m) {
  py::class_<FunctionNoProtoType, FunctionType>(m, "FunctionNoProtoType")
    .def("__hash__", [](const FunctionNoProtoType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &FunctionNoProtoType::Desugar)
    .def_property_readonly("is_sugared", &FunctionNoProtoType::IsSugared);
}
} // namespace pasta
