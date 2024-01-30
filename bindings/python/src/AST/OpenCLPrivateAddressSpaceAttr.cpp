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

void RegisterOpenCLPrivateAddressSpaceAttr(nb::module_ &m) {
  nb::class_<OpenCLPrivateAddressSpaceAttr, TypeAttr>(m, "OpenCLPrivateAddressSpaceAttr")
    .def("__hash__", [](const OpenCLPrivateAddressSpaceAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &OpenCLPrivateAddressSpaceAttr::SemanticSpelling)
    .def_prop_ro("spelling", &OpenCLPrivateAddressSpaceAttr::Spelling);
}
} // namespace pasta
