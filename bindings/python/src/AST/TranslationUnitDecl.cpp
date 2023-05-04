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

void RegisterTranslationUnitDecl(py::module_ &m) {
  py::class_<TranslationUnitDecl, Decl>(m, "TranslationUnitDecl")
    .def("__hash__", [](const TranslationUnitDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TranslationUnitDecl& a, const TranslationUnitDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AnonymousNamespace", &TranslationUnitDecl::AnonymousNamespace);
}
} // namespace pasta