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

void RegisterHLSLBufferDecl(nb::module_ &m) {
  nb::class_<HLSLBufferDecl, NamedDecl>(m, "HLSLBufferDecl")
    .def("__hash__", [](const HLSLBufferDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("l_brace_token", &HLSLBufferDecl::LBraceToken)
    .def_prop_ro("token_start", &HLSLBufferDecl::TokenStart)
    .def_prop_ro("r_brace_token", &HLSLBufferDecl::RBraceToken)
    .def_prop_ro("is_c_buffer", &HLSLBufferDecl::IsCBuffer);
}
} // namespace pasta
