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
    .def_property_readonly("BlockMissingReturnType", &BlockDecl::BlockMissingReturnType)
    .def_property_readonly("CanAvoidCopyToHeap", &BlockDecl::CanAvoidCopyToHeap)
    .def_property_readonly("CapturesCXXThis", &BlockDecl::CapturesCXXThis)
    .def_property_readonly("DoesNotEscape", &BlockDecl::DoesNotEscape)
    .def_property_readonly("BlockManglingContextDeclaration", &BlockDecl::BlockManglingContextDeclaration)
    .def_property_readonly("BlockManglingNumber", &BlockDecl::BlockManglingNumber)
    .def_property_readonly("CaretToken", &BlockDecl::CaretToken)
    .def_property_readonly("CompoundBody", &BlockDecl::CompoundBody)
    .def_property_readonly("NumCaptures", &BlockDecl::NumCaptures)
    .def_property_readonly("NumParameters", &BlockDecl::NumParameters)
    .def_property_readonly("SignatureAsWritten", &BlockDecl::SignatureAsWritten)
    .def_property_readonly("HasCaptures", &BlockDecl::HasCaptures)
    .def_property_readonly("IsConversionFromLambda", &BlockDecl::IsConversionFromLambda)
    .def_property_readonly("IsVariadic", &BlockDecl::IsVariadic)
    .def_property_readonly("Parameters", &BlockDecl::Parameters);
}
} // namespace pasta
