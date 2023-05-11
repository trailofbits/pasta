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

void RegisterLifetimeExtendedTemporaryDecl(py::module_ &m) {
  py::class_<LifetimeExtendedTemporaryDecl, Decl>(m, "LifetimeExtendedTemporaryDecl")
    .def("__hash__", [](const LifetimeExtendedTemporaryDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("children", &LifetimeExtendedTemporaryDecl::Children)
    .def_property_readonly("extending_declaration", &LifetimeExtendedTemporaryDecl::ExtendingDeclaration)
    .def_property_readonly("mangling_number", &LifetimeExtendedTemporaryDecl::ManglingNumber)
    .def_property_readonly("storage_duration", &LifetimeExtendedTemporaryDecl::StorageDuration)
    .def_property_readonly("temporary_expression", &LifetimeExtendedTemporaryDecl::TemporaryExpression);
}
} // namespace pasta
