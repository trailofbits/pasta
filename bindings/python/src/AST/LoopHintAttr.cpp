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

void RegisterLoopHintAttr(py::module_ &m) {
  py::class_<LoopHintAttr, Attr>(m, "LoopHintAttr")
    .def("__hash__", [](const LoopHintAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const LoopHintAttr& a, const LoopHintAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Option", &LoopHintAttr::Option)
    .def_property_readonly("SemanticSpelling", &LoopHintAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &LoopHintAttr::Spelling)
    .def_property_readonly("State", &LoopHintAttr::State)
    .def_property_readonly("Value", &LoopHintAttr::Value);
}
} // namespace pasta
