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

void RegisterLabelDecl(nb::module_ &m) {
  nb::class_<LabelDecl, NamedDecl>(m, "LabelDecl")
    .def_prop_ro("ms_assembly_label", &LabelDecl::MSAssemblyLabel)
    .def_prop_ro("statement", &LabelDecl::Statement)
    .def_prop_ro("is_gnu_local", &LabelDecl::IsGnuLocal)
    .def_prop_ro("is_ms_assembly_label", &LabelDecl::IsMSAssemblyLabel)
    .def_prop_ro("is_resolved_ms_assembly_label", &LabelDecl::IsResolvedMSAssemblyLabel);
}
} // namespace pasta
