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

void RegisterObjCTypeParamDecl(nb::module_ &m) {
  nb::class_<ObjCTypeParamDecl, TypedefNameDecl>(m, "ObjCTypeParamDecl")
    .def_prop_ro("colon_token", &ObjCTypeParamDecl::ColonToken)
    .def_prop_ro("index", &ObjCTypeParamDecl::Index)
    .def_prop_ro("variance", &ObjCTypeParamDecl::Variance)
    .def_prop_ro("variance_token", &ObjCTypeParamDecl::VarianceToken)
    .def_prop_ro("has_explicit_bound", &ObjCTypeParamDecl::HasExplicitBound);
}
} // namespace pasta
