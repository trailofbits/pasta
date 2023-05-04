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

void RegisterObjCCategoryImplDecl(py::module_ &m) {
  py::class_<ObjCCategoryImplDecl, Decl, NamedDecl, ObjCContainerDecl, ObjCImplDecl>(m, "ObjCCategoryImplDecl")
    .def_property_readonly("CategoryDeclaration", &ObjCCategoryImplDecl::CategoryDeclaration)
    .def_property_readonly("CategoryNameToken", &ObjCCategoryImplDecl::CategoryNameToken);
}
} // namespace pasta
