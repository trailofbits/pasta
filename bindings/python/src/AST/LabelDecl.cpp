/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterLabelDecl(py::module_ &m) {
  py::class_<LabelDecl, NamedDecl>(m, "LabelDecl")
    .def("__hash__", [](const LabelDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("ms_assembly_label", &LabelDecl::MSAssemblyLabel)
    .def_property_readonly("statement", &LabelDecl::Statement)
    .def_property_readonly("is_gnu_local", &LabelDecl::IsGnuLocal)
    .def_property_readonly("is_ms_assembly_label", &LabelDecl::IsMSAssemblyLabel)
    .def_property_readonly("is_resolved_ms_assembly_label", &LabelDecl::IsResolvedMSAssemblyLabel);
}
} // namespace pasta
