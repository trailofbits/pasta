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

void RegisterReqdWorkGroupSizeAttr(nb::module_ &m) {
  nb::class_<ReqdWorkGroupSizeAttr, InheritableAttr>(m, "ReqdWorkGroupSizeAttr")
    .def("__hash__", [](const ReqdWorkGroupSizeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &ReqdWorkGroupSizeAttr::Spelling)
    .def_prop_ro("x_dim", &ReqdWorkGroupSizeAttr::XDim)
    .def_prop_ro("y_dim", &ReqdWorkGroupSizeAttr::YDim)
    .def_prop_ro("z_dim", &ReqdWorkGroupSizeAttr::ZDim);
}
} // namespace pasta
