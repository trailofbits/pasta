/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterObjCImplDecl(nb::module_ &m) {
  nb::class_<ObjCImplDecl, ObjCContainerDecl>(m, "ObjCImplDecl")
    .def("__hash__", [](const ObjCImplDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("class_interface", &ObjCImplDecl::ClassInterface)
    .def_prop_ro("property_implementations", &ObjCImplDecl::PropertyImplementations);
}
} // namespace pasta
