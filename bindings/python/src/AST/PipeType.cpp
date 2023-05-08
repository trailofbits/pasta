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
    .def("__hash__", [](const PipeType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const PipeType& a, const PipeType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &PipeType::Desugar)
    .def_property_readonly("element_type", &PipeType::ElementType)
    .def_property_readonly("is_read_only", &PipeType::IsReadOnly)
    .def_property_readonly("is_sugared", &PipeType::IsSugared);
}
} // namespace pasta
