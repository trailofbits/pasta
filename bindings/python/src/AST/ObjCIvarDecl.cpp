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

void RegisterObjCIvarDecl(nb::module_ &m) {
  nb::class_<ObjCIvarDecl, FieldDecl>(m, "ObjCIvarDecl")
    .def("__hash__", [](const ObjCIvarDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("access_control", &ObjCIvarDecl::AccessControl)
    .def_prop_ro("canonical_access_control", &ObjCIvarDecl::CanonicalAccessControl)
    .def_prop_ro("canonical_declaration", &ObjCIvarDecl::CanonicalDeclaration)
    .def_prop_ro("containing_interface", &ObjCIvarDecl::ContainingInterface)
    .def_prop_ro("next_instance_variable", &ObjCIvarDecl::NextInstanceVariable)
    .def_prop_ro("synthesize", &ObjCIvarDecl::Synthesize);
}
} // namespace pasta
