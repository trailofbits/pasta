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

void RegisterCXXConversionDecl(py::module_ &m) {
  py::class_<CXXConversionDecl, CXXMethodDecl>(m, "CXXConversionDecl")
    .def("__hash__", [](const CXXConversionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const CXXConversionDecl& a, const CXXConversionDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("canonical_declaration", &CXXConversionDecl::CanonicalDeclaration)
    .def_property_readonly("conversion_type", &CXXConversionDecl::ConversionType)
    .def_property_readonly("is_explicit", &CXXConversionDecl::IsExplicit)
    .def_property_readonly("is_lambda_to_block_pointer_conversion", &CXXConversionDecl::IsLambdaToBlockPointerConversion);
}
} // namespace pasta
