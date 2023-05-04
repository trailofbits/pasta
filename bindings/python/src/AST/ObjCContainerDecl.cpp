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

void RegisterObjCContainerDecl(py::module_ &m) {
  py::class_<ObjCContainerDecl, Decl, NamedDecl>(m, "ObjCContainerDecl")
    .def("__hash__", [](const ObjCContainerDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCContainerDecl& a, const ObjCContainerDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("ClassMethods", &ObjCContainerDecl::ClassMethods)
    .def_property_readonly("ClassProperties", &ObjCContainerDecl::ClassProperties)
    .def_property_readonly("AtEndRange", &ObjCContainerDecl::AtEndRange)
    .def_property_readonly("AtStartToken", &ObjCContainerDecl::AtStartToken)
    .def_property_readonly("InstanceMethods", &ObjCContainerDecl::InstanceMethods)
    .def_property_readonly("InstanceProperties", &ObjCContainerDecl::InstanceProperties)
    .def_property_readonly("Methods", &ObjCContainerDecl::Methods)
    .def_property_readonly("Properties", &ObjCContainerDecl::Properties);
}
} // namespace pasta
