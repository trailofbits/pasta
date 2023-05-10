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

void RegisterObjCImplementationDecl(py::module_ &m) {
  py::class_<ObjCImplementationDecl, ObjCImplDecl>(m, "ObjCImplementationDecl")
    .def("__hash__", [](const ObjCImplementationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ObjCImplementationDecl& a, const ObjCImplementationDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("instance_variable_l_brace_token", &ObjCImplementationDecl::InstanceVariableLBraceToken)
    .def_property_readonly("instance_variable_r_brace_token", &ObjCImplementationDecl::InstanceVariableRBraceToken)
    .def_property_readonly("name", &ObjCImplementationDecl::Name)
    .def_property_readonly("num_instance_variable_initializers", &ObjCImplementationDecl::NumInstanceVariableInitializers)
    .def_property_readonly("obj_c_runtime_name_as_string", &ObjCImplementationDecl::ObjCRuntimeNameAsString)
    .def_property_readonly("super_class", &ObjCImplementationDecl::SuperClass)
    .def_property_readonly("super_class_token", &ObjCImplementationDecl::SuperClassToken)
    .def_property_readonly("has_destructors", &ObjCImplementationDecl::HasDestructors)
    .def_property_readonly("has_non_zero_constructors", &ObjCImplementationDecl::HasNonZeroConstructors)
    .def_property_readonly("instance_variables", &ObjCImplementationDecl::InstanceVariables);
}
} // namespace pasta
