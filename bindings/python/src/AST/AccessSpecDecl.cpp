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

void RegisterAccessSpecDecl(py::module_ &m) {
  py::class_<AccessSpecDecl, Decl>(m, "AccessSpecDecl")
    .def_property_readonly("AccessSpecifierToken", &AccessSpecDecl::AccessSpecifierToken)
    .def_property_readonly("ColonToken", &AccessSpecDecl::ColonToken);
}
} // namespace pasta
