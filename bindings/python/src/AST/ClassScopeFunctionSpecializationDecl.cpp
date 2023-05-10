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

void RegisterClassScopeFunctionSpecializationDecl(py::module_ &m) {
  py::class_<ClassScopeFunctionSpecializationDecl, Decl>(m, "ClassScopeFunctionSpecializationDecl")
    .def("__hash__", [](const ClassScopeFunctionSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ClassScopeFunctionSpecializationDecl& a, const ClassScopeFunctionSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("specialization", &ClassScopeFunctionSpecializationDecl::Specialization)
    .def_property_readonly("has_explicit_template_arguments", &ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArguments);
}
} // namespace pasta
