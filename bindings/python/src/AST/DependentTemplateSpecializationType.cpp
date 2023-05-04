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

void RegisterDependentTemplateSpecializationType(py::module_ &m) {
  py::class_<DependentTemplateSpecializationType, Type, TypeWithKeyword>(m, "DependentTemplateSpecializationType")
    .def_property_readonly("Desugar", &DependentTemplateSpecializationType::Desugar)
    .def_property_readonly("IsSugared", &DependentTemplateSpecializationType::IsSugared)
    .def_property_readonly("TemplateArguments", &DependentTemplateSpecializationType::TemplateArguments);
}
} // namespace pasta
