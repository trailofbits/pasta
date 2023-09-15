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

void RegisterCapturedDecl(nb::module_ &m) {
  nb::class_<CapturedDecl, Decl>(m, "CapturedDecl")
    .def("__hash__", [](const CapturedDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("context_parameter", &CapturedDecl::ContextParameter)
    .def_prop_ro("context_parameter_position", &CapturedDecl::ContextParameterPosition)
    .def_prop_ro("num_parameters", &CapturedDecl::NumParameters)
    .def_prop_ro("is_nothrow", &CapturedDecl::IsNothrow)
    .def_prop_ro("parameters", &CapturedDecl::Parameters);
}
} // namespace pasta
