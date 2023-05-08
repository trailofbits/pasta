/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterBlockDecl(py::module_ &m) {
  py::class_<BlockDecl, Decl>(m, "BlockDecl")
    .def("__hash__", [](const BlockDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const BlockDecl& a, const BlockDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("block_missing_return_type", &BlockDecl::BlockMissingReturnType)
    .def_property_readonly("can_avoid_copy_to_heap", &BlockDecl::CanAvoidCopyToHeap)
    .def_property_readonly("captures_cxx_this", &BlockDecl::CapturesCXXThis)
    .def_property_readonly("does_not_escape", &BlockDecl::DoesNotEscape)
    .def_property_readonly("block_mangling_context_declaration", &BlockDecl::BlockManglingContextDeclaration)
    .def_property_readonly("block_mangling_number", &BlockDecl::BlockManglingNumber)
    .def_property_readonly("caret_token", &BlockDecl::CaretToken)
    .def_property_readonly("compound_body", &BlockDecl::CompoundBody)
    .def_property_readonly("num_captures", &BlockDecl::NumCaptures)
    .def_property_readonly("num_parameters", &BlockDecl::NumParameters)
    .def_property_readonly("signature_as_written", &BlockDecl::SignatureAsWritten)
    .def_property_readonly("has_captures", &BlockDecl::HasCaptures)
    .def_property_readonly("is_conversion_from_lambda", &BlockDecl::IsConversionFromLambda)
    .def_property_readonly("is_variadic", &BlockDecl::IsVariadic)
    .def_property_readonly("parameters", &BlockDecl::Parameters);
}
} // namespace pasta
