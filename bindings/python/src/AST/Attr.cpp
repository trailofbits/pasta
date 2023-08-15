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

void RegisterAttr(nb::module_ &m) {
  nb::class_<Attr>(m, "Attr")
    .def("__hash__", [](const Attr &attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def("kind", &Attr::Kind)
    .def("kind_name", &Attr::KindName)
    .def_prop_ro("token", &Attr::Token)
    .def_prop_ro("spelling", &Attr::Spelling)
    .def_prop_ro("spelling_list_index", &Attr::SpellingListIndex)
    .def_prop_ro("is_implicit", &Attr::IsImplicit)
    .def_prop_ro("is_inherited", &Attr::IsInherited)
    .def_prop_ro("is_late_parsed", &Attr::IsLateParsed)
    .def_prop_ro("is_pack_expansion", &Attr::IsPackExpansion);
}
} // namespace pasta
