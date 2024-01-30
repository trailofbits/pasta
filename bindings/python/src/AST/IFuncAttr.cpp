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

void RegisterIFuncAttr(nb::module_ &m) {
  nb::class_<IFuncAttr, Attr>(m, "IFuncAttr")
    .def("__hash__", [](const IFuncAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("resolver", &IFuncAttr::Resolver)
    .def_prop_ro("resolver_length", &IFuncAttr::ResolverLength)
    .def_prop_ro("spelling", &IFuncAttr::Spelling);
}
} // namespace pasta
