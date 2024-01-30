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

void RegisterZeroCallUsedRegsAttr(nb::module_ &m) {
  nb::class_<ZeroCallUsedRegsAttr, InheritableAttr>(m, "ZeroCallUsedRegsAttr")
    .def("__hash__", [](const ZeroCallUsedRegsAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("spelling", &ZeroCallUsedRegsAttr::Spelling)
    .def_prop_ro("zero_call_used_regs", &ZeroCallUsedRegsAttr::ZeroCallUsedRegs);
}
} // namespace pasta
