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

void RegisterDiagnoseAsBuiltinAttr(nb::module_ &m) {
  nb::class_<DiagnoseAsBuiltinAttr, InheritableAttr>(m, "DiagnoseAsBuiltinAttr")
    .def("__hash__", [](const DiagnoseAsBuiltinAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("function", &DiagnoseAsBuiltinAttr::Function)
    .def_prop_ro("spelling", &DiagnoseAsBuiltinAttr::Spelling);
}
} // namespace pasta
