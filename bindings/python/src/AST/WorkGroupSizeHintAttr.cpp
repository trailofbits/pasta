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

void RegisterWorkGroupSizeHintAttr(nb::module_ &m) {
  nb::class_<WorkGroupSizeHintAttr, InheritableAttr>(m, "WorkGroupSizeHintAttr")
    .def("__hash__", [](const WorkGroupSizeHintAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &WorkGroupSizeHintAttr::Spelling)
    .def_prop_ro("x_dim", &WorkGroupSizeHintAttr::XDim)
    .def_prop_ro("y_dim", &WorkGroupSizeHintAttr::YDim)
    .def_prop_ro("z_dim", &WorkGroupSizeHintAttr::ZDim);
}
} // namespace pasta
