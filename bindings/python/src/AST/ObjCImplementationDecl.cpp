/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCImplementationDecl(nb::module_ &m) {
  nb::class_<ObjCImplementationDecl, ObjCImplDecl>(m, "ObjCImplementationDecl")
    .def("__hash__", [](const ObjCImplementationDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("instance_variable_l_brace_token", &ObjCImplementationDecl::InstanceVariableLBraceToken)
    .def_prop_ro("instance_variable_r_brace_token", &ObjCImplementationDecl::InstanceVariableRBraceToken)
    .def_prop_ro("name", &ObjCImplementationDecl::Name)
    .def_prop_ro("num_instance_variable_initializers", &ObjCImplementationDecl::NumInstanceVariableInitializers)
    .def_prop_ro("obj_c_runtime_name_as_string", &ObjCImplementationDecl::ObjCRuntimeNameAsString)
    .def_prop_ro("super_class", &ObjCImplementationDecl::SuperClass)
    .def_prop_ro("super_class_token", &ObjCImplementationDecl::SuperClassToken)
    .def_prop_ro("has_destructors", &ObjCImplementationDecl::HasDestructors)
    .def_prop_ro("has_non_zero_constructors", &ObjCImplementationDecl::HasNonZeroConstructors)
    .def_prop_ro("instance_variables", &ObjCImplementationDecl::InstanceVariables);
}
} // namespace pasta
