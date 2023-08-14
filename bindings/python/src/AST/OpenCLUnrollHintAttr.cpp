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

void RegisterOpenCLUnrollHintAttr(nb::module_ &m) {
  nb::class_<OpenCLUnrollHintAttr, StmtAttr>(m, "OpenCLUnrollHintAttr")
    .def("__hash__", [](const OpenCLUnrollHintAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &OpenCLUnrollHintAttr::Spelling)
    .def_prop_ro("unroll_hint", &OpenCLUnrollHintAttr::UnrollHint);
}
} // namespace pasta
