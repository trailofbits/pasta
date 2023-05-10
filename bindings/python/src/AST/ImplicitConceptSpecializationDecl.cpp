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

void RegisterImplicitConceptSpecializationDecl(py::module_ &m) {
  py::class_<ImplicitConceptSpecializationDecl, Decl>(m, "ImplicitConceptSpecializationDecl")
    .def("__hash__", [](const ImplicitConceptSpecializationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ImplicitConceptSpecializationDecl& a, const ImplicitConceptSpecializationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("template_arguments", &ImplicitConceptSpecializationDecl::TemplateArguments);
}
} // namespace pasta
