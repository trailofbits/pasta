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

void RegisterOMPAllocateDecl(nb::module_ &m) {
  nb::class_<OMPAllocateDecl, OMPDeclarativeDirectiveDecl>(m, "OMPAllocateDecl")
    .def("__hash__", [](const OMPAllocateDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("varlists", &OMPAllocateDecl::Varlists);
}
} // namespace pasta
