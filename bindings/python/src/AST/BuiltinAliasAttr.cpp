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

void RegisterBuiltinAliasAttr(py::module_ &m) {
  py::class_<BuiltinAliasAttr, Attr>(m, "BuiltinAliasAttr")
    .def("__hash__", [](const BuiltinAliasAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const BuiltinAliasAttr& a, const BuiltinAliasAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("SemanticSpelling", &BuiltinAliasAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &BuiltinAliasAttr::Spelling);
}
} // namespace pasta
