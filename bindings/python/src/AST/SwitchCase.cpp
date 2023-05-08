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

void RegisterSwitchCase(py::module_ &m) {
  py::class_<SwitchCase, Stmt>(m, "SwitchCase")
    .def("__hash__", [](const SwitchCase& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const SwitchCase& a, const SwitchCase& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &SwitchCase::BeginToken)
    .def_property_readonly("colon_token", &SwitchCase::ColonToken)
    .def_property_readonly("end_token", &SwitchCase::EndToken)
    .def_property_readonly("keyword_token", &SwitchCase::KeywordToken)
    .def_property_readonly("next_switch_case", &SwitchCase::NextSwitchCase)
    .def_property_readonly("sub_statement", &SwitchCase::SubStatement);
}
} // namespace pasta
