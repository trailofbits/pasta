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

namespace pasta {
namespace py = pybind11;

void RegisterLabelDecl(py::module_ &m) {
  py::class_<LabelDecl, Decl, NamedDecl>(m, "LabelDecl")
    .def("__hash__", [](const LabelDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const LabelDecl& a, const LabelDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("MSAssemblyLabel", &LabelDecl::MSAssemblyLabel)
    .def_property_readonly("Statement", &LabelDecl::Statement)
    .def_property_readonly("IsGnuLocal", &LabelDecl::IsGnuLocal)
    .def_property_readonly("IsMSAssemblyLabel", &LabelDecl::IsMSAssemblyLabel)
    .def_property_readonly("IsResolvedMSAssemblyLabel", &LabelDecl::IsResolvedMSAssemblyLabel);
}
} // namespace pasta
