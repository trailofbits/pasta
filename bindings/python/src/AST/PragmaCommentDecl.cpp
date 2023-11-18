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

void RegisterPragmaCommentDecl(nb::module_ &m) {
  nb::class_<PragmaCommentDecl, Decl>(m, "PragmaCommentDecl")
    .def_prop_ro("argument", &PragmaCommentDecl::Argument)
    .def_prop_ro("comment_kind", &PragmaCommentDecl::CommentKind);
}
} // namespace pasta
