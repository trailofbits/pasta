/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterDiagnoseIfAttr(nb::module_ &m) {
  nb::class_<DiagnoseIfAttr, InheritableAttr>(m, "DiagnoseIfAttr")
    .def("__hash__", [](const DiagnoseIfAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Attr& a, const Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_prop_ro("argument_dependent", &DiagnoseIfAttr::ArgumentDependent)
    .def_prop_ro("condition", &DiagnoseIfAttr::Condition)
    .def_prop_ro("diagnostic_type", &DiagnoseIfAttr::DiagnosticType)
    .def_prop_ro("message", &DiagnoseIfAttr::Message)
    .def_prop_ro("message_length", &DiagnoseIfAttr::MessageLength)
    .def_prop_ro("parent", &DiagnoseIfAttr::Parent)
    .def_prop_ro("spelling", &DiagnoseIfAttr::Spelling)
    .def_prop_ro("is_error", &DiagnoseIfAttr::IsError)
    .def_prop_ro("is_warning", &DiagnoseIfAttr::IsWarning);
}
} // namespace pasta
