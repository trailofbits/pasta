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

void RegisterFunctionReturnThunksAttr(nb::module_ &m) {
  nb::class_<FunctionReturnThunksAttr, InheritableAttr>(m, "FunctionReturnThunksAttr")
    .def("__hash__", [](const FunctionReturnThunksAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("spelling", &FunctionReturnThunksAttr::Spelling)
    .def_prop_ro("thunk_type", &FunctionReturnThunksAttr::ThunkType);
}
} // namespace pasta
