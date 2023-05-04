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

void RegisterCXXDestructorDecl(py::module_ &m) {
  py::class_<CXXDestructorDecl, CXXMethodDecl, Decl, DeclaratorDecl, FunctionDecl, NamedDecl, ValueDecl>(m, "CXXDestructorDecl")
    .def_property_readonly("CanonicalDeclaration", &CXXDestructorDecl::CanonicalDeclaration)
    .def_property_readonly("OperatorDelete", &CXXDestructorDecl::OperatorDelete)
    .def_property_readonly("OperatorDeleteThisArgument", &CXXDestructorDecl::OperatorDeleteThisArgument);
}
} // namespace pasta
