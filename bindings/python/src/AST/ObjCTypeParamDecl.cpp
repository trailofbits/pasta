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

void RegisterObjCTypeParamDecl(py::module_ &m) {
  py::class_<ObjCTypeParamDecl, TypedefNameDecl>(m, "ObjCTypeParamDecl")
    .def("__hash__", [](const ObjCTypeParamDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCTypeParamDecl& a, const ObjCTypeParamDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("colon_token", &ObjCTypeParamDecl::ColonToken)
    .def_property_readonly("index", &ObjCTypeParamDecl::Index)
    .def_property_readonly("variance", &ObjCTypeParamDecl::Variance)
    .def_property_readonly("variance_token", &ObjCTypeParamDecl::VarianceToken)
    .def_property_readonly("has_explicit_bound", &ObjCTypeParamDecl::HasExplicitBound);
}
} // namespace pasta
