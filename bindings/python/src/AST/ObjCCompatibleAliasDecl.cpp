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

void RegisterObjCCompatibleAliasDecl(nb::module_ &m) {
  nb::class_<ObjCCompatibleAliasDecl, NamedDecl>(m, "ObjCCompatibleAliasDecl")
    .def("__hash__", [](const ObjCCompatibleAliasDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("class_interface", &ObjCCompatibleAliasDecl::ClassInterface);
}
} // namespace pasta
