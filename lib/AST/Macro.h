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

class MacroNodeImpl {
 public:
  virtual ~MacroNodeImpl(void) = default;
  virtual MacroNodeKind Kind(void) const = 0;

  Node parent;
  std::vector<Node> nodes;
};

class MacroTokenImpl final {
 public:
  Node parent;

  // Offset of `TokenImpl` in `ASTImpl::tokens`.
  uint32_t token_offset;

  union {
    // The actual context of this token.
    uint32_t token_context;

    // The actual kind of this token.
    TokenKind kind;
  };
};

class MacroDirectiveImpl final : public MacroNodeImpl {
 public:
  virtual ~MacroDirectiveImpl(void) = default;
  MacroNodeKind Kind(void) const final;

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

  unsigned index{0u};
  bool is_variadic{false};
};

class MacroSubstitutionImpl : public MacroNodeImpl {
 public:
  virtual ~MacroSubstitutionImpl(void) = default;

  MacroNodeKind Kind(void) const override;

  std::vector<Node> use_nodes;
};

class MacroExpansionImpl final : public MacroSubstitutionImpl {
 public:
  virtual ~MacroExpansionImpl(void) = default;

  MacroNodeKind Kind(void) const final;

  std::vector<Node> arguments;
  std::vector<Node> variadic_arguments;
  Node definition;
  bool is_variadic{false};
  bool is_cancelled{false};
  bool in_prearg_expansion{false};
  bool is_prearg_expansion{false};
};

// The `nodes` of a `RootMacroNode` are the top-level macro nodes, e.g. top-
// level directives, and top-level expansions.
class RootMacroNode final : public MacroNodeImpl {
 public:
  virtual ~RootMacroNode(void) = default;

  MacroNodeKind Kind(void) const final;

  std::deque<MacroDirectiveImpl> directives;
  std::deque<MacroExpansionImpl> expansions;
  std::deque<MacroArgumentImpl> arguments;
  std::deque<MacroSubstitutionImpl> substitutions;
  std::deque<MacroTokenImpl> tokens;
  std::vector<Node> token_nodes;
};

}  // namespace pasta
