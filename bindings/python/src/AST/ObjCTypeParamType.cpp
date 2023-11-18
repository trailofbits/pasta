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

void RegisterObjCTypeParamType(nb::module_ &m) {
  nb::class_<ObjCTypeParamType, Type>(m, "ObjCTypeParamType")
    .def_prop_ro("desugar", &ObjCTypeParamType::Desugar)
    .def_prop_ro("declaration", &ObjCTypeParamType::Declaration)
    .def_prop_ro("is_sugared", &ObjCTypeParamType::IsSugared);
}
} // namespace pasta
