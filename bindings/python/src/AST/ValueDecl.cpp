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

void RegisterValueDecl(nb::module_ &m) {
  nb::class_<ValueDecl, NamedDecl>(m, "ValueDecl")
    .def("__hash__", [](const ValueDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("potentially_decomposed_variable_declaration", &ValueDecl::PotentiallyDecomposedVariableDeclaration)
    .def_prop_ro("type", &ValueDecl::Type)
    .def_prop_ro("is_initializer_capture", &ValueDecl::IsInitializerCapture)
    .def_prop_ro("is_weak", &ValueDecl::IsWeak);
}
} // namespace pasta
