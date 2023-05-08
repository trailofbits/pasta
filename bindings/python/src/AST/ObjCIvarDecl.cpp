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

void RegisterObjCIvarDecl(py::module_ &m) {
  py::class_<ObjCIvarDecl, FieldDecl>(m, "ObjCIvarDecl")
    .def("__hash__", [](const ObjCIvarDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCIvarDecl& a, const ObjCIvarDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("AccessControl", &ObjCIvarDecl::AccessControl)
    .def_property_readonly("CanonicalAccessControl", &ObjCIvarDecl::CanonicalAccessControl)
    .def_property_readonly("CanonicalDeclaration", &ObjCIvarDecl::CanonicalDeclaration)
    .def_property_readonly("ContainingInterface", &ObjCIvarDecl::ContainingInterface)
    .def_property_readonly("NextInstanceVariable", &ObjCIvarDecl::NextInstanceVariable)
    .def_property_readonly("Synthesize", &ObjCIvarDecl::Synthesize);
}
} // namespace pasta
