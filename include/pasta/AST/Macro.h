/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include <memory>
#include <optional>
#include <string_view>
#include <vector>

namespace pasta {

class AST;
class ASTImpl;
class File;
class FileToken;
class FileTokenRange;
class MacroExpansionArgument;
class MacroArgumentImpl;
class MacroArgumentList;
class MacroArgumentListImpl;
class MacroDirective;
class MacroDirectiveImpl;
class MacroExpansion;
class MacroExpansionImpl;
class MacroNode;
class MacroNodeImpl;
class MacroNodeIterator;
class MacroNodeRange;
class MacroToken;
class MacroTokenImpl;
class PatchedMacroTracker;
class SkippedTokenRange;
class SkippedTokenRangeImpl;
class Token;
class TokenImpl;

#define PASTA_FOR_EACH_MACRO_DIRECTIVE_KIND(pp) \
    pp(OtherDirective) \
    pp(IfDirective) \
    pp(IfDefinedDirective) \
    pp(IfNotDefinedDirective) \
    pp(ElseIfDirective) \
    pp(ElseIfDefinedDirective) \
    pp(ElseIfNotDefinedDirective) \
    pp(ElseDirective) \
    pp(EndIfDirective) \
    pp(DefineDirective) \
    pp(UndefineDirective) \
    pp(PragmaDirective) \
    pp(IncludeDirective) \
    pp(IncludeNextDirective) \
    pp(IncludeMacrosDirective) \
    pp(ImportDirective)

#define PASTA_FOR_EACH_MACRO_NODE_KIND(pp) \
    pp(Invalid) \
    pp(Token) \
    pp(Expansion) \
    pp(Substitution) \
    PASTA_FOR_EACH_MACRO_DIRECTIVE_KIND(pp) \
    pp(Argument) \
    pp(Parameter)

enum class MacroNodeKind : unsigned char {
#define PASTA_DECLARE_MACRO_NODE_KIND(kind) k ## kind ,
  PASTA_FOR_EACH_MACRO_NODE_KIND(PASTA_DECLARE_MACRO_NODE_KIND)
#undef PASTA_DECLARE_MACRO_NODE_KIND
};

enum class TokenKind : unsigned short;

// Base for all macro nodes.
class MacroNode {
 protected:
  friend class MacroNodeIterator;
  friend class MacroNodeRange;
  friend class PatchedMacroTracker;
  friend class Token;

  std::shared_ptr<ASTImpl> ast;
  const void *impl;

  inline MacroNode(std::shared_ptr<ASTImpl> ast_, const void *impl_)
      : ast(std::move(ast_)),
        impl(impl_) {}

 public:
  ~MacroNode(void);

  MacroNodeKind Kind(void) const noexcept;

  const void *RawNode(void) const noexcept;

  inline auto operator<=>(const MacroNode &that) const noexcept
      -> decltype(RawNode() <=> RawNode()) {
    return RawNode() <=> that.RawNode();
  }

  // Return the macro node containing this node.
  std::optional<MacroNode> Parent(void) const noexcept;

  // Begin and ending usage tokens.
  std::optional<MacroToken> BeginToken(void) const noexcept;
  std::optional<MacroToken> EndToken(void) const noexcept;
};

// A token produced inside of a macro expansion.
class MacroToken final : public MacroNode {
 protected:
  friend class MacroDirective;
  friend class DefineMacroDirective;
  friend class IncludeMacroDirective;
  friend class PatchedMacroTracker;
  friend class MacroDefinitionParameter;
  friend class Token;

  using MacroNode::MacroNode;

 public:
  MacroToken(const MacroToken &) = default;
  MacroToken(MacroToken &&) noexcept = default;
  MacroToken &operator=(const MacroToken &) = default;
  MacroToken &operator=(MacroToken &&) noexcept = default;

  inline static std::optional<MacroToken> From(const MacroNode &node) {
    if (node.Kind() == MacroNodeKind::kToken) {
      return reinterpret_cast<const MacroToken &>(node);
    } else {
      return std::nullopt;
    }
  }

  enum TokenKind TokenKind(void) const noexcept;
  std::string_view TokenKindName(void) const noexcept;

  // Return the data associated with this token.
  std::string_view Data(void) const noexcept;

  // Location of the token in a file.
  std::optional<FileToken> FileLocation(void) const noexcept;

  // Location of the token as parsed.
  std::optional<Token> ParsedLocation(void) const noexcept;
};

static_assert(sizeof(MacroToken) == sizeof(MacroNode));

// A directive.
class MacroDirective : public MacroNode {
 protected:
  friend class MacroExpansion;

  using MacroNode::MacroNode;

 public:
  static std::optional<MacroDirective> From(const MacroNode &node) noexcept;

  // Return the hash token of the directive.
  MacroToken Hash(void) const noexcept;

  // The name of this directive, if any. Some GCC-specific macros don't have
  // names. Directive names are macro tokens because the name may be a result
  // of some other expansion, e.g. `_Pragma("...")` expanding into
  // `#pragma ...`.
  std::optional<MacroToken> Name(void) const noexcept;

  MacroNodeRange Nodes(void) const noexcept;
};

static_assert(sizeof(MacroDirective) == sizeof(MacroNode));

// An parameter in a macro.
class MacroDefinitionParameter final : public MacroNode {
 protected:
  friend class DefineMacroDirective;

  using MacroNode::MacroNode;

 public:
  inline static std::optional<MacroDefinitionParameter> From(const MacroNode &node) {
    if (node.Kind() == MacroNodeKind::kParameter) {
      return reinterpret_cast<const MacroDefinitionParameter &>(node);
    } else {
      return std::nullopt;
    }
  }

  // E.g. `...` in `args...`, or just `...`.
  std::optional<MacroToken> VariadicDots(void) const noexcept;

  // The name of the macro parameter, if any.
  std::optional<MacroToken> Name(void) const noexcept;

  // The index of this parameter.
  unsigned Index(void) const noexcept;

  MacroNodeRange Nodes(void) const noexcept;
};

// A macro definition directive.
class DefineMacroDirective final : public MacroDirective {
 protected:
  friend class MacroExpansion;

  using MacroDirective::MacroDirective;

 public:
  static std::optional<DefineMacroDirective> From(const MacroNode &node);

  // The name of this macro.
  MacroToken Name(void) const noexcept;

  // Uses of this macro.
  MacroNodeRange Uses(void) const noexcept;

  // Body of the defined macro.
  MacroNodeRange Body(void) const noexcept;

  // Number of explicit, i.e. not variadic, parameters.
  unsigned NumExplicitParameters(void) const noexcept;

  // Does this definition accept a variable number of arguments?
  bool IsVariadic(void) const noexcept;

  // Is this a function-like macro? If so, then it could take zero-or-more
  // arguments when used.
  bool IsFunctionLike(void) const noexcept;

  // Parameters of this macro definition.
  MacroNodeRange Parameters(void) const noexcept;
};

static_assert(sizeof(MacroDefinitionParameter) == sizeof(MacroNode));

static_assert(sizeof(DefineMacroDirective) == sizeof(MacroNode));

// Represents the inclusion of a file.
class IncludeMacroDirective final : public MacroDirective {
 protected:
  friend class MacroExpansion;

  using MacroDirective::MacroDirective;

 public:
  static std::optional<IncludeMacroDirective> From(const MacroNode &node);

  File IncludedFile(void) const noexcept;
};

// An argument in a macro. This may be one token, or multiple tokens, as macro
// arguments are subject to pre-expansion.
class MacroExpansionArgument final : public MacroNode {
 protected:
  friend class MacroExpansion;

  using MacroNode::MacroNode;

 public:
  inline static std::optional<MacroExpansionArgument> From(const MacroNode &node) {
    if (node.Kind() == MacroNodeKind::kArgument) {
      return reinterpret_cast<const MacroExpansionArgument &>(node);
    } else {
      return std::nullopt;
    }
  }

  bool IsVariadic(void) const noexcept;

  unsigned Index(void) const noexcept;

  MacroNodeRange Nodes(void) const noexcept;
};

static_assert(sizeof(MacroExpansionArgument) == sizeof(MacroNode));

// A substitution.
class MacroSubstitution : public MacroNode {
 protected:
  using MacroNode::MacroNode;

 public:
  inline static std::optional<MacroSubstitution> From(const MacroNode &node) {
    switch (node.Kind()) {
      case MacroNodeKind::kSubstitution:
      case MacroNodeKind::kExpansion:
        return reinterpret_cast<const MacroSubstitution &>(node);
      default:
        return std::nullopt;
    }
  }

  MacroNodeRange UsageNodes(void) const noexcept;
  MacroNodeRange SubstitutionNodes(void) const noexcept;
};

static_assert(sizeof(MacroSubstitution) == sizeof(MacroNode));

// The expansion of a macro.
class MacroExpansion final : public MacroSubstitution {
 protected:
  using MacroSubstitution::MacroSubstitution;

 public:
  inline static std::optional<MacroExpansion> From(const MacroNode &node) {
    if (node.Kind() == MacroNodeKind::kExpansion) {
      return reinterpret_cast<const MacroExpansion &>(node);
    } else {
      return std::nullopt;
    }
  }

  static MacroExpansion Containing(const MacroExpansionArgument &) noexcept;

  // Returns the directive that led to the definition of this expansion.
  std::optional<DefineMacroDirective> Definition(void) const noexcept;

  // Returns the list of arguments in the expansion if this was a use of a
  // function-like macro.
  std::vector<MacroExpansionArgument> Arguments(void) const noexcept;
};

static_assert(sizeof(MacroExpansion) == sizeof(MacroNode));

// A bi-directional, random-access iterator over macro nodes.
class MacroNodeIterator {
 private:
  friend class MacroNodeRange;

  MacroNode node;

  MacroNodeIterator(void) = delete;

  inline explicit MacroNodeIterator(const std::shared_ptr<ASTImpl> &ast_,
                                     const void *it_)
      : node(ast_, it_) {}

 public:
  typedef MacroNode value_type;
  typedef ptrdiff_t difference_type;
  typedef const MacroNode *pointer;
  typedef const MacroNode &reference;
  typedef std::random_access_iterator_tag iterator_category;

  MacroNodeIterator(const MacroNodeIterator &) = default;
  MacroNodeIterator(MacroNodeIterator &&) noexcept = default;
  MacroNodeIterator &operator=(const MacroNodeIterator &) = default;
  MacroNodeIterator &operator=(MacroNodeIterator &&) noexcept = default;

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const MacroNode &operator*(void) const & noexcept {
    return node;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const MacroNode *operator->(void) const & noexcept {
    return &node;
  }

  MacroNodeIterator &operator++(void) noexcept;
  MacroNodeIterator operator++(int) noexcept;
  MacroNodeIterator &operator--(void) noexcept;
  MacroNodeIterator operator--(int) noexcept;
  MacroNodeIterator operator+(size_t offset) const noexcept;
  MacroNodeIterator operator-(size_t offset) const noexcept;
  MacroNodeIterator &operator+=(size_t offset) noexcept;
  MacroNodeIterator &operator-=(size_t offset) noexcept;
  MacroNode operator[](size_t offset) const noexcept;
  ptrdiff_t operator-(const MacroNodeIterator &that) const noexcept;

  inline bool operator!=(const MacroNodeIterator &that) const noexcept {
    return node.impl != that.node.impl;
  }

  inline bool operator==(const MacroNodeIterator &that) const noexcept {
    return node.impl == that.node.impl;
  }

  inline bool operator<=(const MacroNodeIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) <=
           reinterpret_cast<uintptr_t>(that.node.impl);
  }

  inline bool operator>=(const MacroNodeIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) >=
           reinterpret_cast<uintptr_t>(that.node.impl);
  }

  inline bool operator<(const MacroNodeIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) <
           reinterpret_cast<uintptr_t>(that.node.impl);
  }

  inline bool operator>(const MacroNodeIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) >
           reinterpret_cast<uintptr_t>(that.node.impl);
  }
};

// Range of macro tokens.
class MacroNodeRange {
 private:
  friend class AST;
  friend class ASTImpl;
  friend class MacroDefinitionParameter;
  friend class MacroExpansionArgument;
  friend class MacroExpansion;
  friend class MacroSubstitution;
  friend class MacroDirective;
  friend class DefineMacroDirective;
  friend class IncludeMacroDirective;
  friend class MacroToken;

  std::shared_ptr<ASTImpl> ast;
  const void *first;
  const void *after_last;

  MacroNodeRange(void) = delete;

  inline explicit MacroNodeRange(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        first(nullptr),
        after_last(nullptr) {}

  inline MacroNodeRange(std::shared_ptr<ASTImpl> ast_, const void *first_,
                        const void *after_last_)
      : ast(std::move(ast_)),
        first(first_),
        after_last(after_last_) {}

 public:
  MacroNodeRange(const MacroNodeRange &) = default;
  MacroNodeRange(MacroNodeRange &&) noexcept = default;
  MacroNodeRange &operator=(const MacroNodeRange &) = default;
  MacroNodeRange &operator=(MacroNodeRange &&) noexcept = default;

  inline MacroNodeIterator begin(void) const noexcept {
    return MacroNodeIterator(ast, first);
  }

  inline MacroNodeIterator end(void) const noexcept {
    return MacroNodeIterator(ast, after_last);
  }

  inline size_t size(void) const noexcept {
    return Size();
  }

  inline bool empty(void) const noexcept {
    return !Size();
  }

  // Number of nodes in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<MacroNode> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  MacroNode operator[](size_t index) const;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }
};

}  // namespace pasta
