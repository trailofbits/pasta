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

void RegisterAccessSpecDecl(py::module_ &m) {
  py::class_<AccessSpecDecl, Decl>(m, "AccessSpecDecl")
    .def("__hash__", [](const AccessSpecDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const AccessSpecDecl& a, const AccessSpecDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("access_specifier_token", &AccessSpecDecl::AccessSpecifierToken)
    .def_property_readonly("colon_token", &AccessSpecDecl::ColonToken);
}
} // namespace pasta
