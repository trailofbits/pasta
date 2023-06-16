/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterSwitchCase(nb::module_ &m) {
  nb::class_<SwitchCase, Stmt>(m, "SwitchCase")
    .def("__hash__", [](const SwitchCase& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("begin_token", &SwitchCase::BeginToken)
    .def_prop_ro("colon_token", &SwitchCase::ColonToken)
    .def_prop_ro("end_token", &SwitchCase::EndToken)
    .def_prop_ro("keyword_token", &SwitchCase::KeywordToken)
    .def_prop_ro("next_switch_case", &SwitchCase::NextSwitchCase)
    .def_prop_ro("sub_statement", &SwitchCase::SubStatement);
}
} // namespace pasta
