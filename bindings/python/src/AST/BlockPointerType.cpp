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

void RegisterBlockPointerType(py::module_ &m) {
  py::class_<BlockPointerType, Type>(m, "BlockPointerType")
    .def("__hash__", [](const BlockPointerType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const BlockPointerType& a, const BlockPointerType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &BlockPointerType::Desugar)
    .def_property_readonly("PointeeType", &BlockPointerType::PointeeType)
    .def_property_readonly("IsSugared", &BlockPointerType::IsSugared);
}
} // namespace pasta
