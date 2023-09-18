/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include "Bindings.h"

#include <pasta/AST/AST.h>

namespace pasta {

#define CASE_HOOK(t, suffix) \
    case suffix ## Kind::k ## t: return &typeid(t ## suffix);

#define CASE_DECL_HOOK(t) CASE_HOOK(t, Decl)
#define CASE_TYPE_HOOK(t) CASE_HOOK(t, Type)
#define CASE_ATTR_HOOK(t) CASE_HOOK(t, Attr)
#define CASE_STMT_HOOK(t) \
    case StmtKind::k ## t: return &typeid(t);

const std::type_info *TypeInfoFromKind(DeclKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_DECL_IMPL(CASE_DECL_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

const std::type_info *TypeInfoFromKind(StmtKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_STMT_IMPL(CASE_STMT_HOOK, CASE_STMT_HOOK,
                             CASE_STMT_HOOK, CASE_STMT_HOOK,
                             CASE_STMT_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

const std::type_info *TypeInfoFromKind(TypeKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_TYPE_IMPL(CASE_TYPE_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

const std::type_info *TypeInfoFromKind(AttrKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_ATTR_IMPL(CASE_ATTR_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

#undef CASE_DECL_HOOK
#undef CASE_STMT_HOOK
#undef CASE_TYPE_HOOK
#undef CASE_ATTR_HOOK

const std::type_info *TypeInfoFromKind(MacroKind kind) {
  switch (kind) {
#define PASTA_IGNORE(...)
#define PASTA_DECLARE_MACRO_KIND(t) \
    case MacroKind::k ## t: return &typeid(Macro ## t);
#define PASTA_DECLARE_DIRECTIVE_KIND(t) \
    case MacroKind::k ## t ## Directive: return &typeid(t ## MacroDirective);

  PASTA_FOR_EACH_MACRO_IMPL(PASTA_DECLARE_MACRO_KIND,
                            PASTA_DECLARE_MACRO_KIND,
                            PASTA_DECLARE_DIRECTIVE_KIND,
                            PASTA_DECLARE_DIRECTIVE_KIND,
                            PASTA_DECLARE_DIRECTIVE_KIND,
                            PASTA_DECLARE_DIRECTIVE_KIND,
                            PASTA_IGNORE)
#undef PASTA_DECLARE_MACRO_KIND
#undef PASTA_DECLARE_DIRECTIVE_KIND
#undef PASTA_IGNORE
  }
  return nullptr;
}

}  // namespace pasta