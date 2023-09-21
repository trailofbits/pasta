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

void RegisterCXXDeductionGuideDecl(nb::module_ &m) {
  nb::class_<CXXDeductionGuideDecl, FunctionDecl>(m, "CXXDeductionGuideDecl")
    .def("__hash__", [](const CXXDeductionGuideDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("corresponding_constructor", &CXXDeductionGuideDecl::CorrespondingConstructor)
    .def_prop_ro("deduced_template", &CXXDeductionGuideDecl::DeducedTemplate)
    .def_prop_ro("deduction_candidate_kind", &CXXDeductionGuideDecl::DeductionCandidateKind)
    .def_prop_ro("is_explicit", &CXXDeductionGuideDecl::IsExplicit);
}
} // namespace pasta
