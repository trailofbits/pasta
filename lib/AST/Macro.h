/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/Macro.h>

#include <deque>
#include <variant>

#include <pasta/Util/File.h>

namespace clang {
class MacroInfo;
}  // namespace clang
namespace pasta {

using Node = std::variant<std::monostate, MacroNodeImpl *, MacroTokenImpl *>;

class ASTImpl;
class MacroTokenImpl;

class MacroNodeImpl {
 public:
  MacroNodeImpl(void) = delete;
  inline explicit MacroNodeImpl(MacroKind kind_)
      : kind(kind_) {}

  virtual ~MacroNodeImpl(void) = default;
  virtual MacroTokenImpl *FirstUseToken(void) const;
  virtual MacroTokenImpl *FirstExpansionToken(void) const;
  virtual const Node *FirstToken(void) const;
  virtual const Node *LastToken(void) const;
  virtual MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const = 0;

  Node parent;
  std::vector<Node> nodes;

  // Kind of this Node.
  MacroKind kind;

  const MacroNodeImpl *cloned_from{nullptr};
#ifndef NDEBUG
  unsigned line_added{0u};
#endif
};

struct TokenKindAndFlags {
  TokenKind kind;
  bool is_ignored_comma;
};

class MacroTokenImpl final {
 public:
  Node parent;

  // Offset of `TokenImpl` in `ASTImpl::tokens`.
  uint32_t token_offset;

  union {
    // The actual context of this token.
    uint32_t token_context{0};

    // The actual kind of this token.
    TokenKindAndFlags kind_flags;
  };

  // Clone this token into the AST.
  MacroTokenImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const;
};

class MacroDirectiveImpl final : public MacroNodeImpl {
 public:
  inline MacroDirectiveImpl(void)
      : MacroNodeImpl(MacroKind::kOtherDirective) {}

  virtual ~MacroDirectiveImpl(void) = default;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  // The info for the macro that was defined by this directive.
  const clang::MacroInfo *defined_macro{nullptr};

  // Token for the name of the defined macro, assuming this directive is a
  // `#define`.
  Node macro_name;

  // The uses of this macro definition, assuming this directive is a
  // `#define`.
  std::vector<Node> macro_uses;

  // Parameters of this macro definition, assuming this directive is a
  // `#define`.
  std::vector<Node> parameters;

  // Token for the directive name. E.g. `define` in a `#define`, or `pragma`
  // in `#pragma`.
  Node directive_name;

  // File that was included by this directive, assuming this was a
  // `#include`-like directive.
  std::optional<File> included_file;

  // Offset/index of the first body token if the defined macro, assuming this
  // directive is a `#define`.
  unsigned body_offset{0u};

  // Whether or not this represents a skipped region of code, e.g. `#if 0`.
  bool is_skipped{false};
};

class MacroArgumentImpl final : public MacroNodeImpl {
 public:
  inline MacroArgumentImpl(void)
      : MacroNodeImpl(MacroKind::kArgument) {}

  virtual ~MacroArgumentImpl(void) = default;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  // Index of this argument in the macro call argument list. If there are five
  // arguments, then the first index is 0, second is 1, etc.
  unsigned index{0u};

  // Offset of this argument in the (parent) macro call `use_nodes`s list. This
  // is like a self-pointer, telling us where to find this node in the parent's
  // node list.
  unsigned offset{0u};

  // Was this argument part of a macro argument pre-expansion phase?
  bool is_prearg_expansion{false};

  // Don't allow us to clone an argument more than once. If this happens then
  // that suggests a bug in the pre-argument expansion code related to
  // injecting prefixes.
  mutable bool has_been_cloned{false};
};

class MacroParameterImpl final : public MacroNodeImpl {
 public:
  inline MacroParameterImpl(void)
      : MacroNodeImpl(MacroKind::kParameter) {}

  virtual ~MacroParameterImpl(void) = default;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  std::vector<Node> uses;

  unsigned index{0u};
  bool has_name{false};
  bool is_variadic{false};
};

class MacroSubstitutionImpl : public MacroNodeImpl {
 public:
  inline MacroSubstitutionImpl(void)
      : MacroNodeImpl(MacroKind::kSubstitution) {}

  virtual ~MacroSubstitutionImpl(void) = default;
  MacroTokenImpl *FirstUseToken(void) const final;
  MacroTokenImpl *FirstExpansionToken(void) const final;
  const Node *FirstToken(void) const final;
  const Node *LastToken(void) const final;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const override;

  std::vector<Node> use_nodes;
};

class MacroExpansionImpl final : public MacroSubstitutionImpl {
 public:
  inline MacroExpansionImpl(void) {
    kind = MacroKind::kExpansion;
  }

  virtual ~MacroExpansionImpl(void) = default;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  std::vector<Node> arguments;
  Node definition;

  // The info for the macro that was defined by this directive.
  const clang::MacroInfo *defined_macro{nullptr};

  // If `this` is a pre-argument expansion, then `parent_for_prearg` is the
  // original expansion from which `ident`, `l_paren`, and `r_paren` are
  // derived.
  MacroExpansionImpl *parent_for_prearg{nullptr};

  MacroTokenImpl *ident{nullptr};
  MacroTokenImpl *l_paren{nullptr};
  MacroTokenImpl *r_paren{nullptr};

  // We need to know the `r_paren` index so that we can possibly clone stuff
  // following the `r_paren` into a pre-argument expansion. This will happen
  // in cases like `FOO(...)(...)`, where we want to copy the `(...)` into the
  // pre-argument expansion.
  unsigned r_paren_index{0u};

  bool is_cancelled{false};
  bool is_prearg_expansion{false};
  bool done_prearg_expansion{false};

#ifndef NDEBUG
  enum {
    kNotDeferred,
    kDeferredParent,
    kDeferredChild
  } defferal_status{kNotDeferred};
#endif
};

// The `nodes` of a `RootMacroNode` are the top-level macro nodes, e.g. top-
// level directives, and top-level expansions.
class RootMacroNode final : public MacroNodeImpl {
 public:
  RootMacroNode(void)
      : MacroNodeImpl(MacroKind::kOtherDirective) {}

  virtual ~RootMacroNode(void) = default;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  std::deque<MacroDirectiveImpl> directives;
  std::deque<MacroExpansionImpl> expansions;
  std::deque<MacroArgumentImpl> arguments;
  std::deque<MacroParameterImpl> parameters;
  std::deque<MacroSubstitutionImpl> substitutions;
  std::deque<MacroTokenImpl> tokens;
  std::vector<Node> token_nodes;
};

}  // namespace pasta
