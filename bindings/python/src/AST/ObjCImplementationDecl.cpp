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

void RegisterObjCImplementationDecl(py::module_ &m) {
  py::class_<ObjCImplementationDecl, Decl, NamedDecl, ObjCContainerDecl, ObjCImplDecl>(m, "ObjCImplementationDecl")
    .def("__hash__", [](const ObjCImplementationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCImplementationDecl& a, const ObjCImplementationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("InstanceVariableLBraceToken", &ObjCImplementationDecl::InstanceVariableLBraceToken)
    .def_property_readonly("InstanceVariableRBraceToken", &ObjCImplementationDecl::InstanceVariableRBraceToken)
    .def_property_readonly("Name", &ObjCImplementationDecl::Name)
    .def_property_readonly("NumInstanceVariableInitializers", &ObjCImplementationDecl::NumInstanceVariableInitializers)
    .def_property_readonly("ObjCRuntimeNameAsString", &ObjCImplementationDecl::ObjCRuntimeNameAsString)
    .def_property_readonly("SuperClass", &ObjCImplementationDecl::SuperClass)
    .def_property_readonly("SuperClassToken", &ObjCImplementationDecl::SuperClassToken)
    .def_property_readonly("HasDestructors", &ObjCImplementationDecl::HasDestructors)
    .def_property_readonly("HasNonZeroConstructors", &ObjCImplementationDecl::HasNonZeroConstructors)
    .def_property_readonly("InstanceVariables", &ObjCImplementationDecl::InstanceVariables);
}
} // namespace pasta
