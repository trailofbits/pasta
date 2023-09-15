/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCContainerDecl(nb::module_ &m) {
  nb::class_<ObjCContainerDecl, NamedDecl>(m, "ObjCContainerDecl")
    .def("__hash__", [](const ObjCContainerDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("class_methods", &ObjCContainerDecl::ClassMethods)
    .def_prop_ro("class_properties", &ObjCContainerDecl::ClassProperties)
    .def_prop_ro("at_end_range", &ObjCContainerDecl::AtEndRange)
    .def_prop_ro("at_start_token", &ObjCContainerDecl::AtStartToken)
    .def_prop_ro("instance_methods", &ObjCContainerDecl::InstanceMethods)
    .def_prop_ro("instance_properties", &ObjCContainerDecl::InstanceProperties)
    .def_prop_ro("methods", &ObjCContainerDecl::Methods)
    .def_prop_ro("properties", &ObjCContainerDecl::Properties);
}
} // namespace pasta
