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

void RegisterSwitchCase(nb::module_ &m) {
  nb::class_<SwitchCase, Stmt>(m, "SwitchCase")
    .def_prop_ro("begin_token", &SwitchCase::BeginToken)
    .def_prop_ro("colon_token", &SwitchCase::ColonToken)
    .def_prop_ro("end_token", &SwitchCase::EndToken)
    .def_prop_ro("keyword_token", &SwitchCase::KeywordToken)
    .def_prop_ro("next_switch_case", &SwitchCase::NextSwitchCase)
    .def_prop_ro("sub_statement", &SwitchCase::SubStatement);
}
} // namespace pasta
