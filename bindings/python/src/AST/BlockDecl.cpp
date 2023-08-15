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

void RegisterBlockDecl(nb::module_ &m) {
  nb::class_<BlockDecl, Decl>(m, "BlockDecl")
    .def("__hash__", [](const BlockDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("block_missing_return_type", &BlockDecl::BlockMissingReturnType)
    .def_prop_ro("can_avoid_copy_to_heap", &BlockDecl::CanAvoidCopyToHeap)
    .def_prop_ro("captures_cxx_this", &BlockDecl::CapturesCXXThis)
    .def_prop_ro("does_not_escape", &BlockDecl::DoesNotEscape)
    .def_prop_ro("block_mangling_context_declaration", &BlockDecl::BlockManglingContextDeclaration)
    .def_prop_ro("block_mangling_number", &BlockDecl::BlockManglingNumber)
    .def_prop_ro("caret_token", &BlockDecl::CaretToken)
    .def_prop_ro("compound_body", &BlockDecl::CompoundBody)
    .def_prop_ro("num_captures", &BlockDecl::NumCaptures)
    .def_prop_ro("num_parameters", &BlockDecl::NumParameters)
    .def_prop_ro("signature_as_written", &BlockDecl::SignatureAsWritten)
    .def_prop_ro("has_captures", &BlockDecl::HasCaptures)
    .def_prop_ro("is_conversion_from_lambda", &BlockDecl::IsConversionFromLambda)
    .def_prop_ro("is_variadic", &BlockDecl::IsVariadic)
    .def_prop_ro("parameters", &BlockDecl::Parameters);
}
} // namespace pasta
