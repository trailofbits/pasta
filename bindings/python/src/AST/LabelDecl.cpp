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

void RegisterLabelDecl(nb::module_ &m) {
  nb::class_<LabelDecl, NamedDecl>(m, "LabelDecl")
    .def("__hash__", [](const LabelDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("ms_assembly_label", &LabelDecl::MSAssemblyLabel)
    .def_prop_ro("statement", &LabelDecl::Statement)
    .def_prop_ro("is_gnu_local", &LabelDecl::IsGnuLocal)
    .def_prop_ro("is_ms_assembly_label", &LabelDecl::IsMSAssemblyLabel)
    .def_prop_ro("is_resolved_ms_assembly_label", &LabelDecl::IsResolvedMSAssemblyLabel);
}
} // namespace pasta
