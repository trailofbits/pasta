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
  virtual ~MacroNodeImpl(void) = default;
  virtual MacroNodeKind Kind(void) const = 0;
  virtual MacroTokenImpl *FirstUseToken(void) const;
  virtual MacroTokenImpl *FirstExpansionToken(void) const;
  virtual MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const = 0;

  Node parent;
  std::vector<Node> nodes;
  std::vector<Node> skipped_nodes;
  const MacroNodeImpl *cloned_from{nullptr};
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
  virtual ~MacroDirectiveImpl(void) = default;
  MacroNodeKind Kind(void) const final;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  // The uses of this macro.
  std::vector<Node> macro_uses;

  // Token for the directive name.
  Node directive_name;

  // Token for the macro name.
  Node macro_name;

  // The info for the macro that was defined by this directive.
  const clang::MacroInfo *defined_macro{nullptr};

  std::optional<File> included_file;

  MacroDirectiveKind kind{MacroDirectiveKind::kOther};

  // Whether or not this represents a skipped region of code, e.g. `#if 0`.
  bool is_skipped{false};
};

class MacroArgumentImpl final : public MacroNodeImpl {
 public:
  virtual ~MacroArgumentImpl(void) = default;
  MacroNodeKind Kind(void) const final;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  unsigned index{0u};
  bool is_prearg_expansion{false};
};

class MacroSubstitutionImpl : public MacroNodeImpl {
 public:
  virtual ~MacroSubstitutionImpl(void) = default;
  MacroTokenImpl *FirstUseToken(void) const final;
  MacroTokenImpl *FirstExpansionToken(void) const final;
  MacroNodeKind Kind(void) const override;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const override;

  std::vector<Node> use_nodes;
};

class MacroExpansionImpl final : public MacroSubstitutionImpl {
 public:
  virtual ~MacroExpansionImpl(void) = default;
  MacroNodeKind Kind(void) const final;
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
  bool in_prearg_expansion{false};
  bool is_prearg_expansion{false};

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
  virtual ~RootMacroNode(void) = default;
  MacroNodeKind Kind(void) const final;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  std::deque<MacroDirectiveImpl> directives;
  std::deque<MacroExpansionImpl> expansions;
  std::deque<MacroArgumentImpl> arguments;
  std::deque<MacroSubstitutionImpl> substitutions;
  std::deque<MacroTokenImpl> tokens;
  std::vector<Node> token_nodes;
};

}  // namespace pasta
