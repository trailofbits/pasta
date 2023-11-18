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

void RegisterImplicitParamDecl(nb::module_ &m) {
  nb::class_<ImplicitParamDecl, VarDecl>(m, "ImplicitParamDecl")
    .def_prop_ro("parameter_kind", &ImplicitParamDecl::ParameterKind);
}
} // namespace pasta
