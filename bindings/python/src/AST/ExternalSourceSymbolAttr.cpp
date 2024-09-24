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

void RegisterExternalSourceSymbolAttr(nb::module_ &m) {
  nb::class_<ExternalSourceSymbolAttr, InheritableAttr>(m, "ExternalSourceSymbolAttr")
    .def("__hash__", [](const ExternalSourceSymbolAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("__ne__", [](const Attr &a, const Attr &b) { return a.RawAttr() != b.RawAttr(); })
    .def_prop_ro("defined_in", &ExternalSourceSymbolAttr::DefinedIn)
    .def_prop_ro("defined_in_length", &ExternalSourceSymbolAttr::DefinedInLength)
    .def_prop_ro("generated_declaration", &ExternalSourceSymbolAttr::GeneratedDeclaration)
    .def_prop_ro("language", &ExternalSourceSymbolAttr::Language)
    .def_prop_ro("language_length", &ExternalSourceSymbolAttr::LanguageLength)
    .def_prop_ro("spelling", &ExternalSourceSymbolAttr::Spelling)
    .def_prop_ro("usr", &ExternalSourceSymbolAttr::USR)
    .def_prop_ro("usr_length", &ExternalSourceSymbolAttr::USRLength);
}
} // namespace pasta
