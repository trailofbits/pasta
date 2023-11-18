/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCapturedDecl(nb::module_ &m) {
  nb::class_<CapturedDecl, Decl>(m, "CapturedDecl")
    .def_prop_ro("context_parameter", &CapturedDecl::ContextParameter)
    .def_prop_ro("context_parameter_position", &CapturedDecl::ContextParameterPosition)
    .def_prop_ro("num_parameters", &CapturedDecl::NumParameters)
    .def_prop_ro("is_nothrow", &CapturedDecl::IsNothrow)
    .def_prop_ro("parameters", &CapturedDecl::Parameters);
}
} // namespace pasta
