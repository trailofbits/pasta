/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/make_iterator.h>
#include <nanobind/stl/filesystem.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <pasta/AST/Forward.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>

#include "Result.h"

namespace pasta {
namespace detail {
template <typename... Args>
struct overload_cast_const_impl {
  template <typename Return, typename Class>
  constexpr auto operator()(Return (Class::*pmf)(Args...) const, std::false_type = {}) const noexcept
      -> decltype(pmf) {
      return pmf;
  }
};
} // namespace detail

template <typename... Args>
static constexpr detail::overload_cast_const_impl<Args...> overload_cast_const{};

void RegisterArgumentVector(nanobind::module_ &);
void RegisterCompileCommand(nanobind::module_ &);
void RegisterFileSystem(nanobind::module_ &);
void RegisterFileManager(nanobind::module_ &);
void RegisterCompileJob(nanobind::module_ &);
void RegisterCompiler(nanobind::module_ &);
void RegisterToken(nanobind::module_ &);
void RegisterMacro(nanobind::module_ &);
void RegisterPrinter(nanobind::module_ &);
void RegisterAST(nanobind::module_ &);

const std::type_info *TypeInfoFromKind(DeclKind kind);
const std::type_info *TypeInfoFromKind(StmtKind kind);
const std::type_info *TypeInfoFromKind(TypeKind kind);
const std::type_info *TypeInfoFromKind(AttrKind kind);
const std::type_info *TypeInfoFromKind(MacroKind kind);

} // namespace pasta
namespace nanobind::detail {

#define DECLARE_HOOK(t, suffix) \
    template <> \
    struct type_hook<::pasta::t ## suffix> { \
      inline static const std::type_info *get(const ::pasta::t ## suffix *p) { \
        return ::pasta::TypeInfoFromKind(p->Kind()); \
      } \
    };

#define FOR_EACH_MACRO_CLASS(m) \
    m(Macro, ) \
    m(MacroToken, ) \
    m(MacroDirective, ) \
    m(ConditionalMacroDirective, ) \
    m(IfMacroDirective, ) \
    m(IfDefinedMacroDirective, ) \
    m(IfNotDefinedMacroDirective, ) \
    m(ElseIfMacroDirective, ) \
    m(ElseIfDefinedMacroDirective, ) \
    m(ElseIfNotDefinedMacroDirective, ) \
    m(ElseMacroDirective, ) \
    m(EndIfMacroDirective, ) \
    m(DefineMacroDirective, ) \
    m(UndefineMacroDirective, ) \
    m(PragmaMacroDirective, ) \
    m(IncludeLikeMacroDirective, ) \
    m(IncludeMacroDirective, ) \
    m(IncludeNextMacroDirective, ) \
    m(IncludeMacrosMacroDirective, ) \
    m(ImportMacroDirective, ) \
    m(MacroParameter, ) \
    m(MacroArgument, ) \
    m(MacroSubstitution, ) \
    m(MacroParameterSubstitution, ) \
    m(MacroExpansion, ) \
    m(MacroStringify, ) \
    m(MacroConcatenate, ) \
    m(MacroVAOpt, ) \
    m(MacroVAOptArgument, )

FOR_EACH_MACRO_CLASS(DECLARE_HOOK)

#define DECLARE_DECL_HOOK(t) DECLARE_HOOK(t, Decl)
#define DECLARE_TYPE_HOOK(t) DECLARE_HOOK(t, Type)
#define DECLARE_ATTR_HOOK(t) DECLARE_HOOK(t, Attr)
#define DECLARE_ABSTRACT_HOOK(t) DECLARE_HOOK(t,)

PASTA_FOR_EACH_DECL_IMPL(DECLARE_DECL_HOOK, DECLARE_ABSTRACT_HOOK)
PASTA_FOR_EACH_STMT_IMPL(DECLARE_ABSTRACT_HOOK, DECLARE_ABSTRACT_HOOK,
                         DECLARE_ABSTRACT_HOOK, DECLARE_ABSTRACT_HOOK,
                         DECLARE_ABSTRACT_HOOK, DECLARE_ABSTRACT_HOOK)
PASTA_FOR_EACH_TYPE_IMPL(DECLARE_TYPE_HOOK, DECLARE_ABSTRACT_HOOK)
PASTA_FOR_EACH_ATTR_IMPL(DECLARE_ATTR_HOOK, DECLARE_ABSTRACT_HOOK)

#undef DECLARE_DECL_HOOK
#undef DECLARE_TYPE_HOOK
#undef DECLARE_ATTR_HOOK
#undef DECLARE_ABSTRACT_HOOK
#undef FOR_EACH_MACRO_CLASS

} // namespace nanobind::detail
