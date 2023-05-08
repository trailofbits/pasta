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

void RegisterDiagnoseIfAttr(py::module_ &m) {
  py::class_<DiagnoseIfAttr, InheritableAttr>(m, "DiagnoseIfAttr")
    .def("__hash__", [](const DiagnoseIfAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const DiagnoseIfAttr& a, const DiagnoseIfAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("ArgumentDependent", &DiagnoseIfAttr::ArgumentDependent)
    .def_property_readonly("Condition", &DiagnoseIfAttr::Condition)
    .def_property_readonly("DiagnosticType", &DiagnoseIfAttr::DiagnosticType)
    .def_property_readonly("Message", &DiagnoseIfAttr::Message)
    .def_property_readonly("MessageLength", &DiagnoseIfAttr::MessageLength)
    .def_property_readonly("Parent", &DiagnoseIfAttr::Parent)
    .def_property_readonly("Spelling", &DiagnoseIfAttr::Spelling)
    .def_property_readonly("IsError", &DiagnoseIfAttr::IsError)
    .def_property_readonly("IsWarning", &DiagnoseIfAttr::IsWarning);
}
} // namespace pasta
