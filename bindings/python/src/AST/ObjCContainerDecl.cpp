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

void RegisterObjCContainerDecl(py::module_ &m) {
  py::class_<ObjCContainerDecl, NamedDecl>(m, "ObjCContainerDecl")
    .def("__hash__", [](const ObjCContainerDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("class_methods", &ObjCContainerDecl::ClassMethods)
    .def_property_readonly("class_properties", &ObjCContainerDecl::ClassProperties)
    .def_property_readonly("at_end_range", &ObjCContainerDecl::AtEndRange)
    .def_property_readonly("at_start_token", &ObjCContainerDecl::AtStartToken)
    .def_property_readonly("instance_methods", &ObjCContainerDecl::InstanceMethods)
    .def_property_readonly("instance_properties", &ObjCContainerDecl::InstanceProperties)
    .def_property_readonly("methods", &ObjCContainerDecl::Methods)
    .def_property_readonly("properties", &ObjCContainerDecl::Properties);
}
} // namespace pasta
