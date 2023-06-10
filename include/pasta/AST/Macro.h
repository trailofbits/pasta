/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#pragma once

#include <compare>
#include <map>
#include <memory>
#include <optional>
#include <string_view>
#include <vector>

namespace pasta {

class AST;
class ASTImpl;
class Decl;
class File;
class FileToken;
class FileTokenRange;
class Macro;
class MacroArgument;
class MacroArgumentImpl;
class MacroArgumentList;
class MacroArgumentListImpl;
class MacroConcatenate;
class MacroDirective;
class MacroDirectiveImpl;
class MacroExpansion;
class MacroExpansionImpl;
class MacroIterator;
class MacroNodeImpl;
class MacroParameterSubstitution;
class MacroRange;
class MacroStringify;
class MacroToken;
class MacroTokenImpl;
class PatchedMacroTracker;
class SkippedTokenRange;
class SkippedTokenRangeImpl;
class Stmt;
class Token;
class TokenContext;
class TokenImpl;

#define PASTA_FOR_EACH_MACRO_IMPL(m, t, d, cd, dd, id, a) \
    a(Macro) \
    t(Token) \
    m(Substitution) \
    m(Expansion) \
    m(Argument) \
    m(Parameter) \
    a(MacroDirective) \
    d(Other) \
    a(ConditionalMacroDirective) \
    cd(If) \
    cd(IfDefined) \
    cd(IfNotDefined) \
    cd(ElseIf) \
    cd(ElseIfDefined) \
    cd(ElseIfNotDefined) \
    cd(Else) \
    cd(EndIf) \
    dd(Define) \
    d(Undefine) \
    d(Pragma) \
    a(IncludeLikeMacroDirective) \
    id(Include) \
    id(IncludeNext) \
    id(IncludeMacros) \
    id(Import) \
    m(ParameterSubstitution) \
    m(Stringify) \
    m(Concatenate) \
    m(VAOpt) \
    m(VAOptArgument)

enum class MacroKind : unsigned char {
#define PASTA_IGNORE(...)
#define PASTA_DECLARE_MACRO_KIND(kind) k ## kind ,
#define PASTA_DECLARE_DIRECTIVE_KIND(kind) k ## kind ## Directive,
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
};

enum class TokenKind : unsigned short;

// Base for all macro nodes.
class Macro {
 protected:
  friend class MacroIterator;
  friend class MacroRange;
  friend class PatchedMacroTracker;
  friend class Token;

  std::shared_ptr<ASTImpl> ast;
  const void *impl;

  inline Macro(std::shared_ptr<ASTImpl> ast_, const void *impl_)
      : ast(std::move(ast_)),
        impl(impl_) {}

 public:
  ~Macro(void);

  inline static std::optional<Macro> From(const TokenContext &) {
    return std::nullopt;
  }

  MacroKind Kind(void) const noexcept;

  std::string_view KindName(void) const noexcept;

  const void *RawMacro(void) const noexcept;

  inline bool operator==(const Macro &that) const noexcept {
    return RawMacro() == that.RawMacro();
  }

  inline bool operator!=(const Macro &that) const noexcept {
    return RawMacro() != that.RawMacro();
  }

  inline bool operator<(const Macro &that) const noexcept {
    return RawMacro() < that.RawMacro();
  }

  // Return the macro node containing this node.
  std::optional<Macro> Parent(void) const noexcept;

  // Children of this macro. If this is a MacroToken then this is empty.
  MacroRange Children(void) const noexcept;

  // Begin and ending usage tokens.
  std::optional<MacroToken> BeginToken(void) const noexcept;
  std::optional<MacroToken> EndToken(void) const noexcept;
};

// A token produced inside of a macro expansion.
class MacroToken final : public Macro {
 protected:
  friend class MacroDirective;
  friend class DefineMacroDirective;
  friend class IncludeLikeMacroDirective;
  friend class PatchedMacroTracker;
  friend class MacroConcatenate;
  friend class MacroParameter;
  friend class MacroParameterSubstitution;
  friend class MacroStringify;
  friend class MacroSubstitution;
  friend class Token;

  using Macro::Macro;

 public:
  MacroToken(const MacroToken &) = default;
  MacroToken(MacroToken &&) noexcept = default;
  MacroToken &operator=(const MacroToken &) = default;
  MacroToken &operator=(MacroToken &&) noexcept = default;

  inline static std::optional<MacroToken> From(const Macro &node) {
    if (node.Kind() == MacroKind::kToken) {
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
  Token ParsedLocation(void) const noexcept;
};

static_assert(sizeof(MacroToken) == sizeof(Macro));

// A directive.
class MacroDirective : public Macro {
 protected:
  friend class MacroExpansion;

  using Macro::Macro;

 public:
  static std::optional<MacroDirective> From(const Macro &node) noexcept;

  // Return the hash token of the directive.
  MacroToken Hash(void) const noexcept;

  // The name of this directive, if any. Some GCC-specific macros don't have
  // names. Directive names are macro tokens because the name may be a result
  // of some other expansion, e.g. `_Pragma("...")` expanding into
  // `#pragma ...`.
  std::optional<MacroToken> DirectiveName(void) const noexcept;
};

static_assert(sizeof(MacroDirective) == sizeof(Macro));

// Represents the inclusion of a file.
class IncludeLikeMacroDirective : public MacroDirective {
 protected:
  friend class MacroExpansion;

  using MacroDirective::MacroDirective;

 public:
  static std::optional<IncludeLikeMacroDirective> From(const Macro &node);

  std::optional<File> IncludedFile(void) const noexcept;
};

// Represents a conditional directive.
class ConditionalMacroDirective : public MacroDirective {
 protected:
  friend class MacroExpansion;

  using MacroDirective::MacroDirective;

 public:
  static std::optional<ConditionalMacroDirective> From(
      const Macro &node) noexcept;
  // TODO(pag):
  //    1) Add `std::optional<bool>` for condition evaluation.
  //    2) Add Previous and Next conditions at the same level.
};

#define PASTA_IGNORE(...)
#define PASTA_MAKE_DIRECTIVE(kind) \
    PASTA_MAKE_DIRECTIVE_BASE(kind, MacroDirective)

#define PASTA_MAKE_INCLUDE_DIRECTIVE(kind) \
    PASTA_MAKE_DIRECTIVE_BASE(kind, IncludeLikeMacroDirective)

#define PASTA_MAKE_COND_DIRECTIVE(kind) \
    PASTA_MAKE_DIRECTIVE_BASE(kind, ConditionalMacroDirective)

#define PASTA_MAKE_DIRECTIVE_BASE(kind, base) \
    class kind ## MacroDirective : public base { \
      friend class MacroExpansion; \
      using base::base; \
      inline static std::optional<kind ## MacroDirective> \
      From(const Macro &node) noexcept { \
        if (node.Kind() != MacroKind::k ## kind ## Directive) { \
          return std::nullopt; \
        } \
        return reinterpret_cast<const kind ## MacroDirective &>(node); \
      } \
    }; \
    static_assert(sizeof(kind ## MacroDirective) == sizeof(Macro));

PASTA_FOR_EACH_MACRO_IMPL(PASTA_IGNORE,
                          PASTA_IGNORE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_COND_DIRECTIVE,
                          PASTA_IGNORE,
                          PASTA_MAKE_INCLUDE_DIRECTIVE,
                          PASTA_IGNORE)
#undef PASTA_IGNORE
#undef PASTA_MAKE_DIRECTIVE
#undef PASTA_MAKE_INCLUDE_DIRECTIVE
#undef PASTA_MAKE_DIRECTIVE_BASE

// An parameter in a macro.
class MacroParameter final : public Macro {
 protected:
  friend class DefineMacroDirective;
  friend class MacroParameterSubstitution;

  using Macro::Macro;

 public:
  inline static std::optional<MacroParameter> From(const Macro &node) {
    if (node.Kind() == MacroKind::kParameter) {
      return reinterpret_cast<const MacroParameter &>(node);
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
};

// A macro definition directive.
class DefineMacroDirective final : public MacroDirective {
 protected:
  friend class MacroExpansion;
  friend class Token;

  using MacroDirective::MacroDirective;

 public:
  static std::optional<DefineMacroDirective> From(const Macro &node);

  // The name of this macro. This is optional because the define itself may
  // be in a conditionally disabled region.
  std::optional<MacroToken> Name(void) const noexcept;

  // Uses of this macro.
  MacroRange Uses(void) const noexcept;

  // Body of the defined macro.
  MacroRange Body(void) const noexcept;

  // Number of explicit, i.e. not variadic, parameters.
  unsigned NumExplicitParameters(void) const noexcept;

  // Does this definition accept a variable number of arguments?
  bool IsVariadic(void) const noexcept;

  // Is this a function-like macro? If so, then it could take zero-or-more
  // arguments when used.
  bool IsFunctionLike(void) const noexcept;

  // Parameters of this macro definition.
  MacroRange Parameters(void) const noexcept;
};

static_assert(sizeof(MacroParameter) == sizeof(Macro));

static_assert(sizeof(DefineMacroDirective) == sizeof(Macro));

// An argument in a macro. This may be one token, or multiple tokens, as macro
// arguments are subject to pre-expansion.
class MacroArgument final : public Macro {
 protected:
  friend class MacroExpansion;

  using Macro::Macro;

 public:
  inline static std::optional<MacroArgument> From(const Macro &node) {
    if (node.Kind() == MacroKind::kArgument) {
      return reinterpret_cast<const MacroArgument &>(node);
    } else {
      return std::nullopt;
    }
  }

  bool IsVariadic(void) const noexcept;

  unsigned Index(void) const noexcept;
};

static_assert(sizeof(MacroArgument) == sizeof(Macro));

// A substitution.
class MacroSubstitution : public Macro {
 protected:
  using Macro::Macro;

 public:
  inline static std::optional<MacroSubstitution> From(const Macro &node) {
    switch (node.Kind()) {
      case MacroKind::kSubstitution:
      case MacroKind::kExpansion:
      case MacroKind::kParameterSubstitution:
      case MacroKind::kStringify:
      case MacroKind::kConcatenate:
        return reinterpret_cast<const MacroSubstitution &>(node);
      default:
        return std::nullopt;
    }
  }

  MacroRange ReplacementChildren(void) const noexcept;

  // Returns the first fully substituted token in this substitution, if any.
  std::optional<Token> FirstFullySubstitutedToken(void) const noexcept;

  // Returns the last fully substituted token in this substitution, if any.
  std::optional<Token> LastFullySubstitutedToken(void) const noexcept;

  // Returns the Stmt in the AST that was parsed from the tokens this macro
  // substitution expanded to, if any.
  std::optional<Stmt> CoveredStmt(void) const noexcept;

  // Returns the Decl in the AST that was parsed from the tokens this macro
  // substitution expanded to, if any.
  std::optional<Decl> CoveredDecl(void) const noexcept;

  // Returns the name of the substituted macro if any. If this substitution
  // comes from a stringification or token-pasting macro, then return the
  // operator that triggered the operation instead.
  std::optional<MacroToken> NameOrOperator(void) const noexcept;
};

static_assert(sizeof(MacroSubstitution) == sizeof(Macro));

class MacroParameterSubstitution final : public MacroSubstitution {
 protected:
  using MacroSubstitution::MacroSubstitution;

 public:
  inline static std::optional<MacroParameterSubstitution> From(const Macro &node) {
    if (node.Kind() == MacroKind::kParameterSubstitution) {
      return reinterpret_cast<const MacroParameterSubstitution &>(node);
    } else {
      return std::nullopt;
    }
  }

  MacroParameter Parameter(void) const noexcept;

  MacroToken ParameterUse(void) const noexcept;
};

// The expansion of a macro.
class MacroExpansion final : public MacroSubstitution {
 protected:
  using MacroSubstitution::MacroSubstitution;

 public:
  inline static std::optional<MacroExpansion> From(const Macro &node) {
    if (node.Kind() == MacroKind::kExpansion) {
      return reinterpret_cast<const MacroExpansion &>(node);
    } else {
      return std::nullopt;
    }
  }

  // The body of the macro, prior to expansion. If anything interesting
  // had to happen in the body, e.g. parameter substitution, token pasting,
  // then that will
  // be present here.
  MacroRange IntermediateChildren(void) const noexcept;

  static MacroExpansion Containing(const MacroArgument &) noexcept;

  // Returns the directive that led to the definition of this expansion.
  std::optional<DefineMacroDirective> Definition(void) const noexcept;

  // Returns the list of arguments in the expansion if this was a use of a
  // function-like macro.
  std::vector<MacroArgument> Arguments(void) const noexcept;

  // Is this the argument pre-expansion phase of this expansion?
  bool IsArgumentPreExpansion(void) const noexcept;

  // Return the "second" (if any) version of this expansion, where the
  // arguments to this macro are subjected to pre-expansion prior to
  // substituting the use of the macro with its body.
  std::optional<MacroExpansion> ArgumentPreExpansion(void) const noexcept;

  // Maps each of the macro's parameters to a vector of Stmts that their
  // substitutions align with in the given statement
  std::map<MacroParameter, std::vector<pasta::Stmt>>
  AlignedParameterSubstitutions(const pasta::Stmt &stmt) const noexcept;

  // Maps each of the macro's parameters to the number of times it is used in
  // the expansion
  std::map<MacroParameter, unsigned>
  ParameterUseCounts(void) const noexcept;
};

static_assert(sizeof(MacroExpansion) == sizeof(Macro));

class MacroStringify final : public MacroSubstitution {
 protected:
  using MacroSubstitution::MacroSubstitution;

 public:
  inline static std::optional<MacroStringify> From(const Macro &node) {
    switch (node.Kind()) {
      case MacroKind::kStringify:
        return reinterpret_cast<const MacroStringify &>(node);
      default:
        return std::nullopt;
    }
  }

  MacroToken StringifiedToken(void) const noexcept;
};

static_assert(sizeof(MacroStringify) == sizeof(Macro));

class MacroConcatenate final : public MacroSubstitution {
 protected:
  using MacroSubstitution::MacroSubstitution;

 public:
  inline static std::optional<MacroConcatenate> From(const Macro &node) {
    switch (node.Kind()) {
      case MacroKind::kConcatenate:
        return reinterpret_cast<const MacroConcatenate &>(node);
      default:
        return std::nullopt;
    }
  }

  MacroToken PastedToken(void) const noexcept;
};

static_assert(sizeof(MacroConcatenate) == sizeof(Macro));

class MacroVAOpt final : public Macro {
 protected:
  using Macro::Macro;

 public:
  inline static std::optional<MacroVAOpt> From(const Macro &node) {
    switch (node.Kind()) {
      case MacroKind::kVAOpt:
        return reinterpret_cast<const MacroVAOpt &>(node);
      default:
        return std::nullopt;
    }
  }

  // Were the contents elided? This is basically asking if there were variadic
  // arguments to the macro.
  bool ContentsAreElided(void) const noexcept;
};

static_assert(sizeof(MacroVAOpt) == sizeof(Macro));

class MacroVAOptArgument final : public Macro {
 protected:
  using Macro::Macro;

 public:
  inline static std::optional<MacroVAOptArgument> From(const Macro &node) {
    switch (node.Kind()) {
      case MacroKind::kVAOptArgument:
        return reinterpret_cast<const MacroVAOptArgument &>(node);
      default:
        return std::nullopt;
    }
  }
};

static_assert(sizeof(MacroVAOptArgument) == sizeof(Macro));

// A bi-directional, random-access iterator over macro nodes.
class MacroIterator {
 private:
  friend class MacroRange;

  Macro node;

  MacroIterator(void) = delete;

  inline explicit MacroIterator(const std::shared_ptr<ASTImpl> &ast_,
                                     const void *it_)
      : node(ast_, it_) {}

 public:
  typedef Macro value_type;
  typedef ptrdiff_t difference_type;
  typedef const Macro *pointer;
  typedef const Macro &reference;
  typedef std::random_access_iterator_tag iterator_category;

  MacroIterator(const MacroIterator &) = default;
  MacroIterator(MacroIterator &&) noexcept = default;
  MacroIterator &operator=(const MacroIterator &) = default;
  MacroIterator &operator=(MacroIterator &&) noexcept = default;

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Macro &operator*(void) const & noexcept {
    return node;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Macro *operator->(void) const & noexcept {
    return &node;
  }

  MacroIterator &operator++(void) noexcept;
  MacroIterator operator++(int) noexcept;
  MacroIterator &operator--(void) noexcept;
  MacroIterator operator--(int) noexcept;
  MacroIterator operator+(size_t offset) const noexcept;
  MacroIterator operator-(size_t offset) const noexcept;
  MacroIterator &operator+=(size_t offset) noexcept;
  MacroIterator &operator-=(size_t offset) noexcept;
  Macro operator[](size_t offset) const noexcept;
  ptrdiff_t operator-(const MacroIterator &that) const noexcept;

  inline bool operator!=(const MacroIterator &that) const noexcept {
    return node.impl != that.node.impl;
  }

  inline bool operator==(const MacroIterator &that) const noexcept {
    return node.impl == that.node.impl;
  }

  inline bool operator<=(const MacroIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) <=
           reinterpret_cast<uintptr_t>(that.node.impl);
  }

  inline bool operator>=(const MacroIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) >=
           reinterpret_cast<uintptr_t>(that.node.impl);
  }

  inline bool operator<(const MacroIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) <
           reinterpret_cast<uintptr_t>(that.node.impl);
  }

  inline bool operator>(const MacroIterator &that) const noexcept {
    return reinterpret_cast<uintptr_t>(node.impl) >
           reinterpret_cast<uintptr_t>(that.node.impl);
  }
};

// Range of macro tokens.
class MacroRange {
 private:
  friend class AST;
  friend class ASTImpl;
  friend class Macro;
  friend class MacroParameter;
  friend class MacroArgument;
  friend class MacroExpansion;
  friend class MacroSubstitution;
  friend class MacroDirective;
  friend class DefineMacroDirective;
  friend class IncludeLikeMacroDirective;
  friend class MacroToken;

  std::shared_ptr<ASTImpl> ast;
  const void *first;
  const void *after_last;

  MacroRange(void) = delete;

  inline explicit MacroRange(std::shared_ptr<ASTImpl> ast_)
      : ast(std::move(ast_)),
        first(nullptr),
        after_last(nullptr) {}

  inline MacroRange(std::shared_ptr<ASTImpl> ast_, const void *first_,
                        const void *after_last_)
      : ast(std::move(ast_)),
        first(first_),
        after_last(after_last_) {}

 public:
  MacroRange(const MacroRange &) = default;
  MacroRange(MacroRange &&) noexcept = default;
  MacroRange &operator=(const MacroRange &) = default;
  MacroRange &operator=(MacroRange &&) noexcept = default;

  inline MacroIterator begin(void) const noexcept {
    return MacroIterator(ast, first);
  }

  inline MacroIterator end(void) const noexcept {
    return MacroIterator(ast, after_last);
  }

  inline size_t size(void) const noexcept {
    return Size();
  }

  inline bool empty(void) const noexcept {
    return !Size();
  }

  // Returns a copy of the first macro in this range.
  inline std::optional<Macro> Front(void) const noexcept {
    return empty() ? std::nullopt : std::optional(*begin());
  }

  // Returns a copy of the last macro in this range.
  inline std::optional<Macro> Back(void) const noexcept {
    return empty() ? std::nullopt : std::optional(*(end() - 1));
  }

  // Number of nodes in this range.
  size_t Size(void) const noexcept;

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<Macro> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  Macro operator[](size_t index) const;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first && after_last;
  }
};

}  // namespace pasta
