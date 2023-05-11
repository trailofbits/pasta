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

void RegisterObjCCategoryImplDecl(py::module_ &m) {
  py::class_<ObjCCategoryImplDecl, ObjCImplDecl>(m, "ObjCCategoryImplDecl")
    .def("__hash__", [](const ObjCCategoryImplDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("category_declaration", &ObjCCategoryImplDecl::CategoryDeclaration)
    .def_property_readonly("category_name_token", &ObjCCategoryImplDecl::CategoryNameToken);
}
} // namespace pasta
