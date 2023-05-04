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

void RegisterLifetimeExtendedTemporaryDecl(py::module_ &m) {
  py::class_<LifetimeExtendedTemporaryDecl, Decl>(m, "LifetimeExtendedTemporaryDecl")
    .def_property_readonly("Children", &LifetimeExtendedTemporaryDecl::Children)
    .def_property_readonly("ExtendingDeclaration", &LifetimeExtendedTemporaryDecl::ExtendingDeclaration)
    .def_property_readonly("ManglingNumber", &LifetimeExtendedTemporaryDecl::ManglingNumber)
    .def_property_readonly("StorageDuration", &LifetimeExtendedTemporaryDecl::StorageDuration)
    .def_property_readonly("TemporaryExpression", &LifetimeExtendedTemporaryDecl::TemporaryExpression);
}
} // namespace pasta
