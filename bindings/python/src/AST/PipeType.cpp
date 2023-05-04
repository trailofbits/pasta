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

void RegisterPipeType(py::module_ &m) {
  py::class_<PipeType, Type>(m, "PipeType")
    .def_property_readonly("Desugar", &PipeType::Desugar)
    .def_property_readonly("ElementType", &PipeType::ElementType)
    .def_property_readonly("IsReadOnly", &PipeType::IsReadOnly)
    .def_property_readonly("IsSugared", &PipeType::IsSugared);
}
} // namespace pasta
