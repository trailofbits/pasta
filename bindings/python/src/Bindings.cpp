/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include "Bindings.h"

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

namespace pasta {

#define CASE_HOOK(t, suffix) \
    case suffix ## Kind::k ## t: return &typeid(t ## suffix);

#define CASE_DECL_HOOK(t) CASE_HOOK(t, Decl)
#define CASE_TYPE_HOOK(t) CASE_HOOK(t, Type)
#define CASE_ATTR_HOOK(t) CASE_HOOK(t, Attr)
#define CASE_STMT_HOOK(t) \
    case StmtKind::k ## t: return &typeid(t);

static const std::type_info *TypeInfoFromKind(DeclKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_DECL_IMPL(CASE_DECL_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

static const std::type_info *TypeInfoFromKind(StmtKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_STMT_IMPL(CASE_STMT_HOOK, CASE_STMT_HOOK,
                             CASE_STMT_HOOK, CASE_STMT_HOOK,
                             CASE_STMT_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

static const std::type_info *TypeInfoFromKind(TypeKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_TYPE_IMPL(CASE_TYPE_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

static const std::type_info *TypeInfoFromKind(AttrKind kind) {
  switch (kind) {
    PASTA_FOR_EACH_ATTR_IMPL(CASE_ATTR_HOOK, PASTA_IGNORE_ABSTRACT)
  }
  return nullptr;
}

#undef CASE_DECL_HOOK
#undef CASE_STMT_HOOK
#undef CASE_TYPE_HOOK
#undef CASE_ATTR_HOOK

#define DEFINE_HOOK(t, suffix) \
    const std::type_info *TypeInfoFromKind(const t ## suffix *p) { \
      if (auto ti = TypeInfoFromKind(p->Kind())) { \
        return ti; \
      } \
      return &typeid(t ## suffix); \
    }

#define DEFINE_DECL_HOOK(t) DEFINE_HOOK(t, Decl)
#define DEFINE_TYPE_HOOK(t) DEFINE_HOOK(t, Type)
#define DEFINE_ATTR_HOOK(t) DEFINE_HOOK(t, Attr)
#define DEFINE_ABSTRACT_HOOK(t) DEFINE_HOOK(t,)

PASTA_FOR_EACH_DECL_IMPL(DEFINE_DECL_HOOK, DEFINE_ABSTRACT_HOOK)
PASTA_FOR_EACH_STMT_IMPL(DEFINE_ABSTRACT_HOOK, DEFINE_ABSTRACT_HOOK,
                         DEFINE_ABSTRACT_HOOK, DEFINE_ABSTRACT_HOOK,
                         DEFINE_ABSTRACT_HOOK, DEFINE_ABSTRACT_HOOK)
PASTA_FOR_EACH_TYPE_IMPL(DEFINE_TYPE_HOOK, DEFINE_ABSTRACT_HOOK)
PASTA_FOR_EACH_ATTR_IMPL(DEFINE_ATTR_HOOK, DEFINE_ABSTRACT_HOOK)

#undef DEFINE_DECL_HOOK
#undef DEFINE_TYPE_HOOK
#undef DEFINE_ATTR_HOOK
#undef DEFINE_ABSTRACT_HOOK

}  // namespace pasta