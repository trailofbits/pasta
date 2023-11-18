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

void RegisterOMPExecutableDirective(nb::module_ &m) {
  nb::class_<OMPExecutableDirective, Stmt>(m, "OMPExecutableDirective")
    .def_prop_ro("children", &OMPExecutableDirective::Children)
    .def_prop_ro("associated_statement", &OMPExecutableDirective::AssociatedStatement)
    .def_prop_ro("begin_token", &OMPExecutableDirective::BeginToken)
    .def_prop_ro("end_token", &OMPExecutableDirective::EndToken)
    .def_prop_ro("innermost_captured_statement", &OMPExecutableDirective::InnermostCapturedStatement)
    .def_prop_ro("num_clauses", &OMPExecutableDirective::NumClauses)
    .def_prop_ro("raw_statement", &OMPExecutableDirective::RawStatement)
    .def_prop_ro("structured_block", &OMPExecutableDirective::StructuredBlock)
    .def_prop_ro("has_associated_statement", &OMPExecutableDirective::HasAssociatedStatement)
    .def_prop_ro("is_standalone_directive", &OMPExecutableDirective::IsStandaloneDirective);
}
} // namespace pasta
