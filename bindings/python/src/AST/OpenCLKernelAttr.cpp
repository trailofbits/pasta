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

void RegisterOpenCLKernelAttr(nb::module_ &m) {
  nb::class_<OpenCLKernelAttr, InheritableAttr>(m, "OpenCLKernelAttr")
    .def("__hash__", [](const OpenCLKernelAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &OpenCLKernelAttr::Spelling);
}
} // namespace pasta
