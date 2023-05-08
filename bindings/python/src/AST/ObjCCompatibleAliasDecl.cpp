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

void RegisterObjCCompatibleAliasDecl(py::module_ &m) {
  py::class_<ObjCCompatibleAliasDecl, NamedDecl>(m, "ObjCCompatibleAliasDecl")
    .def("__hash__", [](const ObjCCompatibleAliasDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCCompatibleAliasDecl& a, const ObjCCompatibleAliasDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("class_interface", &ObjCCompatibleAliasDecl::ClassInterface);
}
} // namespace pasta
