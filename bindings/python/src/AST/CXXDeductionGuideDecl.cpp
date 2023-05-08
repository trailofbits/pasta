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

void RegisterCXXDeductionGuideDecl(py::module_ &m) {
  py::class_<CXXDeductionGuideDecl, FunctionDecl>(m, "CXXDeductionGuideDecl")
    .def("__hash__", [](const CXXDeductionGuideDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const CXXDeductionGuideDecl& a, const CXXDeductionGuideDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("corresponding_constructor", &CXXDeductionGuideDecl::CorrespondingConstructor)
    .def_property_readonly("deduced_template", &CXXDeductionGuideDecl::DeducedTemplate)
    .def_property_readonly("is_copy_deduction_candidate", &CXXDeductionGuideDecl::IsCopyDeductionCandidate)
    .def_property_readonly("is_explicit", &CXXDeductionGuideDecl::IsExplicit);
}
} // namespace pasta
