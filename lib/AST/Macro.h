/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/Macro.h>

#include <cassert>
#include <deque>

#include <pasta/Util/File.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Lex/Token.h>
#pragma GCC diagnostic pop

#include "Token.h"

namespace clang {
class MacroInfo;
}  // namespace clang
namespace pasta {

inline static void NoOnTokenCB(unsigned, MacroTokenImpl *, MacroTokenImpl *) {}
inline static void NoOnNodeCB(unsigned, MacroNodeImpl *, MacroNodeImpl *) {}

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
  NodeList nodes;

  // Kind of this Node.
  MacroKind kind;

  const MacroNodeImpl *cloned_from{nullptr};

  // Beginning parsed token index for the *entire* expansion range.
  DerivedTokenIndex parsed_begin_index{~0u};

#ifndef NDEBUG
  unsigned line_added{0u};
#endif
};

class MacroTokenImpl final {
 public:
  Node parent;

  // Offset of the token in `ASTImpl::macro_tokens`.
  uint32_t token_offset;

  // Copy of `TokenImpl::kind`. We often need to do checks on kinds to find
  // various things, e.g. find the identifier for a macro name in a `#define`,
  // or find balanced parentheses.
  TokenKind kind;
  
  // Keeps track of whether or not this is a comma, but it is ignored from
  // the perspective of separating macro arguments.
  bool is_ignored_comma;

  // Clone this token into the AST.
  MacroTokenImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const;

  // Is `kind` identifier like?
  inline bool IsIdentifierLike(void) const noexcept {
    return kind == TokenKind::kIdentifier ||
           kind == TokenKind::kRawIdentifier;
  }
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
  NodeList macro_uses;

  // Parameters of this macro definition, assuming this directive is a
  // `#define`.
  NodeList parameters;

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

  // Is this a warning or error directive? If so, this signals to try to collect
  // missing tokens when we come accross an EOD.
  bool collected_missing_tokens_on_eod{false};

  // Return the offset of the marker token.
  DerivedTokenIndex marker_token_offset{~0u};
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

  NodeList uses;

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

  NodeList use_nodes;
  Node name;
};

class MacroParameterSubstitutionImpl final : public MacroSubstitutionImpl {
 public:
  OpaqueSourceLoc prev_tok_loc{0u};
  clang::Token prev_tok;
  int prev_tok_index{-2};
  bool failed{false};
  int number{-1};
  Node param_in_definition;

  inline MacroParameterSubstitutionImpl(void) {
    kind = MacroKind::kParameterSubstitution;
  }

  virtual ~MacroParameterSubstitutionImpl(void) = default;

  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;
};

class MacroVAOptImpl final : public MacroNodeImpl {
 public:
  bool is_elided{true};

  inline MacroVAOptImpl(void)
      : MacroNodeImpl(MacroKind::kVAOpt) {}

  virtual ~MacroVAOptImpl(void) = default;

  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;
};

class MacroVAOptArgumentImpl final : public MacroNodeImpl {
 public:
  inline MacroVAOptArgumentImpl(void)
      : MacroNodeImpl(MacroKind::kVAOptArgument) {}

  virtual ~MacroVAOptArgumentImpl(void) = default;

  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;
};

class MacroExpansionImpl final : public MacroSubstitutionImpl {
 public:
  inline MacroExpansionImpl(void) {
    kind = MacroKind::kExpansion;
  }

  virtual ~MacroExpansionImpl(void) = default;
  MacroNodeImpl *Clone(ASTImpl &ast, MacroNodeImpl *parent) const final;

  // Copy tokens from the body of the macro that come before the token with
  // location `loc`.
  void CopyFromBody(ASTImpl &ast, MacroNodeImpl *curr, OpaqueSourceLoc loc);

  NodeList arguments;
  Node definition;
  MacroDirectiveImpl *definition_impl{nullptr};

  // Substitutions of the macro body.
  NodeList body;

  bool has_body{false};
  bool done_processing_body{false};
  bool has_interesting_body{false};

  // Index of the next body token to copy.
  unsigned next_body_token_to_copy{0u};

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
  std::deque<MacroVAOptImpl> vaopts;
  std::deque<MacroVAOptArgumentImpl> vaopt_arguments;
  std::deque<MacroParameterSubstitutionImpl> parameter_substitutions;
  std::deque<MacroTokenImpl> tokens;
  NodeList token_nodes;
};


template <typename TokenCB, typename NodeCB>
static void CloneNode(ASTImpl &ast,
                      const MacroNodeImpl *old_parent,
                      const Node &node, unsigned node_index,
                      MacroNodeImpl *new_parent,
                      NodeList &new_nodes,
                      TokenCB on_token,
                      NodeCB on_node) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
    assert(std::holds_alternative<MacroNodeImpl *>(tok->parent));
    assert(std::get<MacroNodeImpl *>(tok->parent) == old_parent);
    MacroTokenImpl *cloned_tok = tok->Clone(ast, new_parent);
    assert(tok->token_offset < cloned_tok->token_offset);
    new_nodes.emplace_back(cloned_tok);

    on_token(node_index, tok, cloned_tok);

  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    MacroNodeImpl *sub_node = std::get<MacroNodeImpl *>(node);
    assert(std::holds_alternative<MacroNodeImpl *>(sub_node->parent));
    assert(std::get<MacroNodeImpl *>(sub_node->parent) == old_parent);
    auto cloned_node = sub_node->Clone(ast, new_parent);
    new_nodes.emplace_back(cloned_node);

    on_node(node_index, sub_node, cloned_node);
  }
}

template <typename TokenCB, typename NodeCB>
static void CloneNodeList(ASTImpl &ast,
                          const MacroNodeImpl *old_parent,
                          const NodeList &old_nodes,
                          MacroNodeImpl *new_parent,
                          NodeList &new_nodes,
                          TokenCB on_token,
                          NodeCB on_node) {
  auto i = 0u;
  for (const Node &node : old_nodes) {
    CloneNode(ast, old_parent, node, i, new_parent, new_nodes,
              on_token, on_node);
    ++i;
  }
}

}  // namespace pasta
