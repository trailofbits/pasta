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
  py::class_<CXXConversionDecl, CXXMethodDecl, Decl, DeclaratorDecl, FunctionDecl, NamedDecl, ValueDecl>(m, "CXXConversionDecl")
    .def_property_readonly("CanonicalDeclaration", &CXXConversionDecl::CanonicalDeclaration)
    .def_property_readonly("ConversionType", &CXXConversionDecl::ConversionType)
    .def_property_readonly("IsExplicit", &CXXConversionDecl::IsExplicit)
    .def_property_readonly("IsLambdaToBlockPointerConversion", &CXXConversionDecl::IsLambdaToBlockPointerConversion);
}
} // namespace pasta
