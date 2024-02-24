/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <iterator>
#include <memory>
#include <optional>
#include <string_view>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

namespace pasta {

class AST;
class ASTImpl;
class Attr;
class CXXBaseSpecifier;
class DefineMacroDirective;
class Designator;
class FileToken;
class FileTokenRange;
class FunctionDecl;
class Macro;
class MacroSubstitution;
class MacroToken;
class ParsedTokenStorage;
class PrintedToken;
class PrintedTokenRange;
class PrintedTokenRangeImpl;
class TemplateArgument;
class TemplateParameterList;
class TokenIterator;
class TokenPrinterContext;
class TokenRange;

// X-macro for repeated operations on TokenRole values
#define PASTA_FOR_EACH_TOKEN_ROLE(m) \
    m(Invalid) \
    m(BeginOfFileMarker) \
    m(FileToken) \
    m(EndOfFileMarker) \
    m(BeginOfMacroExpansionMarker) \
    m(InitialMacroUseToken) \
    m(IntermediateMacroExpansionToken) \
    m(FinalMacroExpansionToken) \
    m(EmptyOrSpecialMacroToken) \
    m(EndOfMacroExpansionMarker)

enum class TokenKind : unsigned short;

// Different token roles.
//
// NOTE(pag): `kEmptyOrSpecialMacroToken` signals something like a macro
//            expansion that expands to nothing, or the retention of a `#pragma`
//            directive into the parsed toekns.
enum class TokenRole : unsigned char {
#define PASTA_DEFINE_ROLE_ENUMERATOR(role) k ## role ,
  PASTA_FOR_EACH_TOKEN_ROLE(PASTA_DEFINE_ROLE_ENUMERATOR)
#undef PASTA_DEFINE_ROLE_ENUMERATOR
};

// Vector of all token roles for iteration.
extern const std::vector<TokenRole> gTokenRoles;

// Returns the name of the specified TokenRole as a string.
std::string_view TokenRoleName(TokenRole role);

bool IsIdentifierTokenKind(TokenKind) noexcept;
const char *KeywordSpellingOrNull(TokenKind) noexcept;

using DerivedToken = std::variant<std::monostate, MacroToken, FileToken>;

// Represents a token that has been pre-processed and parsed.
class Token {
 private:
  friend class AST;
  friend class ASTImpl;
  friend class CXXBaseSpecifier;
  friend class FunctionDecl;
  friend class MacroToken;
  friend class PrintedToken;
  friend class PrintedTokenRange;
  friend class TokenContext;
  friend class TokenIterator;
  friend class TokenPrinterContext;
  friend class TokenRange;

  std::shared_ptr<ParsedTokenStorage> storage;
  unsigned offset;

  Token(void) = delete;

  explicit Token(std::shared_ptr<ASTImpl> ast_);

  inline explicit Token(std::shared_ptr<ParsedTokenStorage> storage_,
                        unsigned offset_=0u)
      : storage(std::move(storage_)),
        offset(offset_) {}

 public:
  ~Token(void);

  Token(const Token &) = default;
  Token(Token &&) noexcept = default;
  Token &operator=(const Token &) = default;
  Token &operator=(Token &&) noexcept = default;

  const void *RawToken(void) const noexcept;

  // Find the token from which this token was derived. This is a single-hop
  // operation.
  DerivedToken DerivedLocation(void) const;

  // Location of the token in a file. This will try to track the token back to
  // any file token, so it's really a multi-step process, unlike
  // `DerivedLocation`.
  std::optional<FileToken> FileLocation(void) const;

  // Location of the token in a macro expansion.
  std::optional<MacroToken> MacroLocation(void) const;

  // Return the data associated with this token.
  std::string_view Data(void) const;

  // Index of this token in the AST's token list.
  inline unsigned Index(void) const {
    return offset;
  }

  // Kind of this token.
  TokenKind Kind(void) const noexcept;

  // Return the role of this token.
  TokenRole Role(void) const noexcept;

  // Return the printable kind of this token.
  const char *KindName(void) const noexcept;

  // Returns whether or no this token is valid.
  //
  // PASTA supports "nullable" tokens because it's impossible to ensure that
  // all Clang AST nodes have source locations, and it would be rather "spammy"
  // for every AST node to have to use `std::optional<Token>`. In places
  // where PASTA is in control, it uses the more verbose `std::optional<Token>`,
  // communicating absence with `std::nullopt` and that presence guarantees
  // "non-nullness."
  //
  // In general, a "null" token is still entirely usable. All of its methods
  // will work. 
  operator bool(void) const noexcept;

  inline uint64_t Hash(void) const noexcept {
    return std::hash<const void *>{}(RawToken());
  }

  inline bool operator==(const Token &that) const noexcept {
    return storage == that.storage && offset == that.offset;
  }

  inline bool operator<(const Token &that) const noexcept {
    return storage == that.storage && offset < that.offset;
  }
};

// A bi-directional iterator over tokens.
class TokenIterator {
 private:
  Token token;

 public:
  typedef Token value_type;
  typedef const Token *pointer;
  typedef const Token &reference;
  typedef std::bidirectional_iterator_tag iterator_category;

  TokenIterator(const TokenIterator &) = default;
  TokenIterator(TokenIterator &&) noexcept = default;
  TokenIterator &operator=(const TokenIterator &) = default;
  TokenIterator &operator=(TokenIterator &&) noexcept = default;

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token &operator*(void) const & noexcept {
    return token;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token *operator->(void) const & noexcept {
    return &token;
  }

  TokenIterator &operator++(void) noexcept;
  TokenIterator operator++(int) noexcept;
  TokenIterator &operator--(void) noexcept;
  TokenIterator operator--(int) noexcept;

  inline bool operator==(const TokenIterator &that) const noexcept {
    return token == that.token;
  }

  inline bool operator<(const TokenIterator &that) const noexcept {
    return token < that.token;
  }

 private:
  friend class TokenRange;

  TokenIterator(void) = delete;

  inline explicit TokenIterator(
      const std::shared_ptr<ParsedTokenStorage> &storage_, unsigned offset_)
      : token(storage_, offset_) {}
};

// Range of tokens.
class TokenRange {
 private:
  friend class AST;
  friend class ASTImpl;
  friend class CXXBaseSpecifier;
  friend class DeclPrinter;
  friend class FunctionDecl;
  friend class PrintedTokenRange;
  friend class Token;

  std::shared_ptr<ParsedTokenStorage> storage;
  unsigned first;
  unsigned after_last;

  TokenRange(void) = delete;

  explicit TokenRange(std::shared_ptr<ASTImpl> ast_);

  inline explicit TokenRange(std::shared_ptr<ParsedTokenStorage> storage_)
      : storage(std::move(storage_)),
        first(0u),
        after_last(0u) {}


  explicit TokenRange(std::shared_ptr<ASTImpl> ast_,
                      unsigned first_, unsigned after_last_);

  inline explicit TokenRange(std::shared_ptr<ParsedTokenStorage> storage_,
                             unsigned first_, unsigned after_last_)
      : storage(std::move(storage_)),
        first(first_),
        after_last(after_last_) {}

 public:
  TokenRange(const TokenRange &) = default;
  TokenRange(TokenRange &&) noexcept = default;
  TokenRange &operator=(const TokenRange &) = default;
  TokenRange &operator=(TokenRange &&) noexcept = default;

  inline TokenIterator begin(void) const noexcept {
    return TokenIterator(storage, first);
  }

  inline TokenIterator end(void) const noexcept {
    return TokenIterator(storage, after_last);
  }

  // Tries to create a TokenRange from an individual token.
  static TokenRange From(Token tok);

  // Tries to create a TokenRange from the given beginning and ending tokens.
  // Fails if the tokens don't belong to the same AST, or if the beginning token
  // comes after the ending token.
  static std::optional<TokenRange> From(Token begin, Token end);

  inline size_t size(void) const noexcept {
    return after_last - first;
  }

  // Number of tokens in this range.
  inline size_t Size(void) const noexcept {
    return after_last - first;
  }

  inline bool empty(void) const noexcept {
    return first >= after_last;
  }

  // If this range is not empty, returns the first token. Otherwise returns
  // std::nullopt.
  inline std::optional<Token> Front(void) const noexcept {
    if (first >= after_last) {
      return std::nullopt;
    }
    return Token(storage, first);
  }

  // If this range is not empty, returns the last token. Otherwise returns
  // std::nullopt.
  inline std::optional<Token> Back(void) const noexcept {
    if (first >= after_last) {
      return std::nullopt;
    }
    return Token(storage, after_last - 1u);
  }

  // Return the `index`th token in this range. If `index` is too big, then
  // return nothing.
  std::optional<Token> At(size_t index) const noexcept;

  // Unsafe indexed access into the token range.
  Token operator[](size_t index) const;

  // Returns `true` if this range contains a specific token.
  bool Contains(const Token &tok) const noexcept;

  // Returns the list of macros that align with this token range, in the order
  // of most-nested to least. The optional heuristic determines whether or not
  // to try and match macro expansions that contain semicolons.
  std::vector<MacroSubstitution>
  AlignedSubstitutions(bool heuristic) noexcept;

  // Is this token range valid?
  inline operator bool(void) const noexcept {
    return first < after_last;
  }

  // Return the underlying token data.
  std::string_view Data(void) const noexcept;
};

}  // namespace pasta
namespace std {

template <>
struct hash<::pasta::Token> {
  uintptr_t operator()(const ::pasta::Token &tok) const noexcept {
    return tok.Hash();
  }
};

}  // namespace std
