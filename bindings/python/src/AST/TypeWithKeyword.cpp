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

void RegisterTypeWithKeyword(py::module_ &m) {
  py::class_<TypeWithKeyword>(m, "TypeWithKeyword")
    .def("__hash__", [](const TypeWithKeyword& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TypeWithKeyword& a, const TypeWithKeyword& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Keyword", &TypeWithKeyword::Keyword);
}
} // namespace pasta