/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Token.h"

#include <cassert>
#include <limits>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/TokenKinds.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Token.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Printer/Printer.h"

namespace pasta {
namespace {

// Try to use the kind of the token to get its representation.
static bool ReadRawTokenByKind(clang::SourceManager &source_manager,
                               clang::Token tok, std::string *out) {
  llvm::StringRef backup;
  switch (const auto tok_kind = tok.getKind()) {
    case clang::tok::eof:
    case clang::tok::code_completion:
      return false;

    case clang::tok::identifier: {
      if (const auto ident_info = tok.getIdentifierInfo()) {
        backup = ident_info->getName();
      }
      break;
    }

    case clang::tok::raw_identifier:
      backup = tok.getRawIdentifier();
      break;

    case clang::tok::numeric_constant:
    case clang::tok::char_constant:
    case clang::tok::wide_char_constant:
    case clang::tok::utf8_char_constant:
    case clang::tok::utf16_char_constant:
    case clang::tok::utf32_char_constant:
    case clang::tok::string_literal:
    case clang::tok::wide_string_literal:
    case clang::tok::header_name:
    case clang::tok::utf8_string_literal:
    case clang::tok::utf16_string_literal:
    case clang::tok::utf32_string_literal:
      assert(tok.isLiteral());
      backup = llvm::StringRef(tok.getLiteralData(), tok.getLength());
      break;

#define PUNCTUATOR(case_label, rep) \
    case clang::tok::case_label: \
      backup = clang::tok::getPunctuatorSpelling(tok_kind); \
      break;

#define KEYWORD(case_label, feature) \
    case clang::tok::kw_ ## case_label: \
      backup = clang::tok::getKeywordSpelling(tok_kind); \
      break;

// TODO(pag): Deal with Objective-C @ keywords.

#include <clang/Basic/TokenKinds.def>

    case clang::tok::comment:
    case clang::tok::unknown:
    default:
      break;
  }

  if (!backup.empty()) {
    out->assign(backup.data(), backup.size());
    return true;
  }

  return false;
}

// Read the data of the token into the passed in string pointer. This tries
// to find the backing character data for the token, and fill it in that way.
static bool ReadRawTokenData(clang::SourceManager &source_manager,
                             const clang::LangOptions &lang_opts,
                             const clang::Token &tok,
                             const clang::SourceLocation begin_loc,
                             std::string *out) {

  const auto begin = source_manager.getDecomposedLoc(begin_loc);
  if (begin.first.isInvalid()) {
    return false;
  }

  auto invalid = false;
  const auto data = source_manager.getCharacterData(begin_loc, &invalid);
  if (invalid) {
    return false;
  }

  unsigned len = 0;
  if (tok.is(clang::tok::unknown)) {
    len = tok.getLength();
    out->reserve(len);

    for (auto i = 0U; i < len; ++i) {
      switch (data[i]) {
        case '\t':
        case ' ':
        case '\n':
        case '\\':
          out->push_back(data[i]);
          break;
        case '\r':
          break;

        // TODO(pag): This is kind of an error condition.
        default:
          len = i;
          break;
      }
    }

    return !out->empty();

  } else {
    len = clang::Lexer::MeasureTokenLength(begin_loc, source_manager,
                                           lang_opts);
  }

  if (!len) {
    return false;
  }

  // We'll try to get only valid UTF-8 characters, and printable ASCII
  // characters.
  //
  // TODO(pag): This may be overkill, but the lifetimes of the backing buffers
  //            for things like macro expansions is not clear to me, so this
  //            is a reasonable way to go about detecting unusual token data
  //            that may have been corrupted/reused.
  auto can_be_ident = true;

  // We can't allow `NUL` characters into our tokens as we'll be using them
  // to split tokens.
  for (auto i = 0U; i < len; ++i) {
    if (!data[i]) {
      len = i;
      break;
    }
  }

  if (!len) {
    return false;
  }

  out->assign(data, len);

  // Also try to catch errors when reading out identifiers or keywords.
  //
  // TODO(pag): We can't apply this to keywords as it very frequently triggers
  //            in macro definitions, where keyword tokens can contain line
  //            continuations and whitespace.
  if (!can_be_ident && tok.isAnyIdentifier()) {
    // ...
  }

  return true;
}

} // namespace

// Location of the token in a file.
std::optional<FileToken> Token::FileLocation(void) const {
  if (!impl) {
    return std::nullopt;
  }

  clang::SourceLocation loc = impl->Location();
  if (loc.isInvalid() || loc.isMacroID()) {
    return std::nullopt;
  }

  const clang::SourceManager &sm = ast->ci->getSourceManager();
  const auto [file_id, file_offset] = sm.getDecomposedLoc(loc);
  auto file_it = ast->id_to_file.find(file_id.getHashValue());
  if (file_it == ast->id_to_file.end()) {
    return std::nullopt;
  }

  return file_it->second.TokenAtOffset(file_offset);
}

// Kind of this token.
clang::tok::TokenKind Token::Kind(void) const {
  return impl ? impl->kind : clang::tok::unknown;
}

std::string_view TokenImpl::Data(const ASTImpl &ast) const noexcept {
  if (data_len) {
    if (0 <= data_offset) {
      return std::string_view(ast.preprocessed_code).substr(
          static_cast<uint32_t>(data_offset), data_len);
    } else {
      return std::string_view(ast.backup_token_data).substr(
          static_cast<uint32_t>(-data_offset), data_len);
    }
  } else {
    return {};
  }
}

std::string_view TokenImpl::Data(
    const PrintedTokenRangeImpl &range) const noexcept {
  if (data_len) {
    return std::string_view(range.data).substr(
        static_cast<uint32_t>(data_offset), data_len);
  } else {
    return {};
  }
}

// Return the data associated with this token.
std::string_view Token::Data(void) const {
  if (!impl) {
    return {};
  } else {
    return impl->Data(*ast);
  }
}

// Index of this token in the AST's token list.
uint64_t Token::Index(void) const {
  if (impl) {
    return static_cast<uint64_t>(impl - ast->tokens.data());
  } else {
    return std::numeric_limits<uint64_t>::max();
  }
}

// Prefix increment operator.
TokenIterator &TokenIterator::operator++(void) noexcept {
  ++token.impl;
  return *this;
}

// Postfix increment operator.
TokenIterator TokenIterator::operator++(int) noexcept {
  auto ret = *this;
  ++token.impl;
  return ret;
}

// Prefix decrement operator.
TokenIterator &TokenIterator::operator--(void) noexcept {
  --token.impl;
  return *this;
}

// Postfix decrement operator.
TokenIterator TokenIterator::operator--(int) noexcept {
  auto ret = *this;
  --token.impl;
  return ret;
}

TokenIterator TokenIterator::operator-(size_t offset) const noexcept {
  return TokenIterator(token.ast, token.impl - offset);
}

TokenIterator &TokenIterator::operator+=(size_t offset) noexcept {
  token.impl += offset;
  return *this;
}

TokenIterator &TokenIterator::operator-=(size_t offset) noexcept {
  token.impl -= offset;
  return *this;
}

Token TokenIterator::operator[](size_t offset) const noexcept {
  return Token(token.ast, &(token.impl[offset]));
}

ptrdiff_t TokenIterator::operator-(const TokenIterator &that) const noexcept {
  return token.impl - token.impl;
}

// Number of tokens in this range.
size_t TokenRange::Size(void) const noexcept {
  return static_cast<size_t>(after_last - first);
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<Token> TokenRange::At(size_t index) const noexcept {
  auto size = static_cast<size_t>(after_last - first);
  if (index < size) {
    return Token(ast, &(first[index]));
  } else {
    return std::nullopt;
  }
}

// Unsafe indexed access into the token range.
Token TokenRange::operator[](size_t index) const {
  return Token(ast, &(first[index]));
}

bool TryReadRawToken(clang::SourceManager &source_manager,
                     const clang::LangOptions &lang_opts,
                     const clang::Token &tok, std::string *out) {
  out->clear();

  // This could be our sentinel EOF that we add at the end of all tokens, or
  // it could be one of our special macro-expansion EOFs.
  if (tok.is(clang::tok::eof)) {
    return true;

  // Annotations are things like `#pragma`s.
  } else if (tok.isAnnotation()) {

  // A token that has trigraphs or digraphs is one that needs to be cleaned up.
  // The identifier info or literal data info of a token is the post-cleaning
  // representation. If the token therefore never needed cleaning, then we can
  // get its representation via some internal lookup.
  } else if (!tok.needsCleaning()) {
    clang::IdentifierInfo *ident_info = nullptr;

    if (tok.is(clang::tok::raw_identifier)) {
      const auto raw_ident = tok.getRawIdentifier();
      out->assign(raw_ident.data(), raw_ident.size());
      return true;

    } else if (tok.is(clang::tok::identifier) &&
               nullptr != (ident_info = tok.getIdentifierInfo())) {

      out->assign(ident_info->getNameStart(), ident_info->getLength());
      return true;

    } else if (tok.isLiteral() && tok.getLiteralData()) {
      out->assign(tok.getLiteralData(), tok.getLength());
      return true;
    }
  }

  const auto orig_tok_begin = tok.getLocation();
  const auto tok_begin = source_manager.getSpellingLoc(orig_tok_begin);

  // Try to find the token's representation using its location.
  if (tok_begin.isValid()) {
    if (ReadRawTokenData(source_manager, lang_opts, tok, tok_begin, out)) {
      return true;
    }

    bool is_invalid = false;
    const clang::SourceRange token_range(tok_begin);

    auto spelling = clang::Lexer::getSourceText(
        clang::CharSourceRange::getTokenRange(token_range),
        source_manager, lang_opts, &is_invalid);

    if (!is_invalid && !spelling.empty()) {
      out->assign(spelling.data(), spelling.size());
      return true;
    }
  }

  // If all else fails, try to get the representation of the token using
  // its kind.
  return ReadRawTokenByKind(source_manager, tok, out);
}

Token::~Token(void) {}

} // namespace pasta
