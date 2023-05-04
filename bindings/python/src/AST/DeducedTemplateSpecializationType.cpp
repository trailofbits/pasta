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

void RegisterDeducedTemplateSpecializationType(py::module_ &m) {
  py::class_<DeducedTemplateSpecializationType, DeducedType, Type>(m, "DeducedTemplateSpecializationType")
    .def("__hash__", [](const DeducedTemplateSpecializationType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DeducedTemplateSpecializationType& a, const DeducedTemplateSpecializationType& b) { return a.RawType() == b.RawType(); });
}
} // namespace pasta
