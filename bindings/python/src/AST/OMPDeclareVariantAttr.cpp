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

void RegisterOMPDeclareVariantAttr(nb::module_ &m) {
  nb::class_<OMPDeclareVariantAttr, InheritableAttr>(m, "OMPDeclareVariantAttr")
    .def("__hash__", [](const OMPDeclareVariantAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &OMPDeclareVariantAttr::Spelling)
    .def_prop_ro("variant_func_reference", &OMPDeclareVariantAttr::VariantFuncReference);
}
} // namespace pasta
