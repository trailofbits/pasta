/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterDependentTemplateSpecializationType(nb::module_ &m) {
  nb::class_<DependentTemplateSpecializationType, TypeWithKeyword>(m, "DependentTemplateSpecializationType")
    .def("__hash__", [](const DependentTemplateSpecializationType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &DependentTemplateSpecializationType::Desugar)
    .def_prop_ro("is_sugared", &DependentTemplateSpecializationType::IsSugared)
    .def_prop_ro("template_arguments", &DependentTemplateSpecializationType::TemplateArguments);
}
} // namespace pasta
