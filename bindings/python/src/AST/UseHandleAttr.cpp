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

void RegisterUseHandleAttr(nb::module_ &m) {
  nb::class_<UseHandleAttr, InheritableParamAttr>(m, "UseHandleAttr")
    .def("__hash__", [](const UseHandleAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("handle_type", &UseHandleAttr::HandleType)
    .def_prop_ro("handle_type_length", &UseHandleAttr::HandleTypeLength)
    .def_prop_ro("spelling", &UseHandleAttr::Spelling);
}
} // namespace pasta
