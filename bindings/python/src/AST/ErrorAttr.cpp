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

void RegisterErrorAttr(nb::module_ &m) {
  nb::class_<ErrorAttr, InheritableAttr>(m, "ErrorAttr")
    .def("__hash__", [](const ErrorAttr &attr) { return reinterpret_cast<intptr_t>(attr.RawAttr()); })
    .def("__eq__", [](const Attr &a, const Attr &b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("semantic_spelling", &ErrorAttr::SemanticSpelling)
    .def_prop_ro("spelling", &ErrorAttr::Spelling)
    .def_prop_ro("user_diagnostic", &ErrorAttr::UserDiagnostic)
    .def_prop_ro("user_diagnostic_length", &ErrorAttr::UserDiagnosticLength)
    .def_prop_ro("is_error", &ErrorAttr::IsError)
    .def_prop_ro("is_warning", &ErrorAttr::IsWarning);
}
} // namespace pasta
