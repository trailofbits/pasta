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

void RegisterCXXConversionDecl(nb::module_ &m) {
  nb::class_<CXXConversionDecl, CXXMethodDecl>(m, "CXXConversionDecl")
    .def("__hash__", [](const CXXConversionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &CXXConversionDecl::CanonicalDeclaration)
    .def_prop_ro("conversion_type", &CXXConversionDecl::ConversionType)
    .def_prop_ro("is_explicit", &CXXConversionDecl::IsExplicit)
    .def_prop_ro("is_lambda_to_block_pointer_conversion", &CXXConversionDecl::IsLambdaToBlockPointerConversion);
}
} // namespace pasta
