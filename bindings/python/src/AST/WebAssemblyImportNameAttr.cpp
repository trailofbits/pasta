/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterWebAssemblyImportNameAttr(nb::module_ &m) {
  nb::class_<WebAssemblyImportNameAttr, InheritableAttr>(m, "WebAssemblyImportNameAttr")
    .def("__hash__", [](const WebAssemblyImportNameAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("import_name", &WebAssemblyImportNameAttr::ImportName)
    .def_prop_ro("import_name_length", &WebAssemblyImportNameAttr::ImportNameLength)
    .def_prop_ro("spelling", &WebAssemblyImportNameAttr::Spelling);
}
} // namespace pasta
