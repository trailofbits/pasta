/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/AST/Macro.h>

#include <deque>
#include <variant>

namespace clang {
class MacroInfo;
}  // namespace clang
namespace pasta {

using Node = std::variant<std::nullptr_t, MacroNodeImpl *, size_t>;

class MacroNodeImpl {
 public:
  virtual ~MacroNodeImpl(void) = default;
  virtual MacroNodeKind Kind(void) const = 0;

  Node parent{nullptr};
  std::vector<Node> nodes;
};

class MacroDirectiveImpl final : public MacroNodeImpl {
 public:
  virtual ~MacroDirectiveImpl(void) = default;
  MacroNodeKind Kind(void) const final;

  // The uses of this macro.
  std::vector<MacroExpansionImpl *> macro_uses{nullptr};

  // Offset of the token for the directive name.
  Node name_offset;

  // The info for the macro that was defined by this directive.
  const clang::MacroInfo *defined_macro{nullptr};

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
};

class RootMacroNode final : public MacroNodeImpl {
 public:
  virtual ~RootMacroNode(void) = default;

  MacroNodeKind Kind(void) const final;

  std::deque<MacroDirectiveImpl> directives;
  std::deque<MacroExpansionImpl> expansions;
  std::deque<MacroArgumentImpl> arguments;
  std::deque<MacroSubstitutionImpl> substitutions;
};

}  // namespace pasta
