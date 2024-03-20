/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Printer.h"

#include <cassert>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Stmt.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/Preprocessor.h>
#pragma GCC diagnostic pop

#include "raw_ostream.h"

#include "../AST.h"  // For `ASTImpl`.
#include "../Builder.h"  // For `DeclBuilder`.
#include "../Token.h"  // For `TokenImpl`.

#include "DeclStmtPrinter.h"

namespace pasta {

static void TryLocateAttribute(const clang::Attr *A,
                               PrintedTokenRangeImpl &tokens,
                               size_t old_num_toks) {
  
  TokenKind opener_kind = TokenKind::kUnknown;

  unsigned expected_num_openers = 0u;
  unsigned num_found_openers = 0u;

  switch (A->getSyntax()) {
    
    // Implicit attributes have no source location.
    case clang::AttributeCommonInfo::AS_Implicit:
      return;

    case clang::AttributeCommonInfo::AS_CXX11:
    case clang::AttributeCommonInfo::AS_C23:
      opener_kind = TokenKind::kLSquare;
      expected_num_openers = 2u;
      break;

    case clang::AttributeCommonInfo::AS_GNU:
      opener_kind = TokenKind::kLParenthesis;
      expected_num_openers = 2u;
      break;

    case clang::AttributeCommonInfo::AS_Declspec:
    case clang::AttributeCommonInfo::AS_Microsoft:
      opener_kind = TokenKind::kLParenthesis;
      expected_num_openers = 1u;
      break;

    case clang::AttributeCommonInfo::AS_Keyword:
    case clang::AttributeCommonInfo::AS_Pragma:
    case clang::AttributeCommonInfo::AS_ContextSensitiveKeyword:
    case clang::AttributeCommonInfo::AS_HLSLSemantic:
      break;
  }

  size_t max_i = tokens.tokens.size();
  if (old_num_toks >= max_i) {
    return;
  }

  // Try to find the parsed location of the attribute. This is generally
  // something that is "inside" of the attribute, e.g. `nonnull` in
  // `__attribute__((nonnull))`.
  clang::SourceLocation loc = A->getLocation();
  auto maybe_parsed_tok = tokens.ast->ParsedTokenOffset(loc);
  if (!maybe_parsed_tok) {
    return;
  }

  DerivedTokenIndex parsed_tok = maybe_parsed_tok.value();

  // Go look for the printed attribute keyword token in the most recently
  // printed tokens, storing the discovered keyword token in `attr_tok`. If we
  // find attribute openers (parens, brackets), then keep track of those too.
  PrintedTokenImpl *attr_tok = nullptr;
  PrintedTokenImpl *opener_toks[2u] = {};
  for (size_t i = old_num_toks; i < max_i; ++i) {
    PrintedTokenImpl &tok = tokens.tokens[i];
    TokenKind kind = tok.kind;

    // Look for the keyword.
    switch (kind) {
      case TokenKind::kKeyword__Attribute:
      case TokenKind::kKeyword__Declspec:
      case TokenKind::kKeywordAssembly:
      case TokenKind::kKeyword__Ptr32:
      case TokenKind::kKeyword__Ptr64:
      case TokenKind::kKeyword__Fastcall:
      case TokenKind::kKeyword__Stdcall:
      case TokenKind::kKeyword__Thiscall:
      case TokenKind::kKeyword__Vectorcall:
      case TokenKind::kKeyword__Cdecl:
      case TokenKind::kKeyword__Forceinline:  // Maybe.
      case TokenKind::kKeyword_Nonnull:
      case TokenKind::kKeyword_Nullable:
      case TokenKind::kKeyword_NullUnspecified:
      case TokenKind::kKeyword_NullableResult:
        attr_tok = &tok;
        break;
      default:
        break;
    }

    // We've found all the openers that we expected to find. Now go and see if
    // we can match the actual attribute (e.g. `nonnull` above).
    if (num_found_openers >= expected_num_openers) {
      if (tok.derived_index == kInvalidDerivedTokenIndex &&
          (kind == TokenKind::kIdentifier ||
           kind == TokenKind::kRawIdentifier)) {
        llvm::StringRef data(tok.Data(tokens));

        // TODO(pag): uuid, guid?
        if (data != "__attribute__" && data != "__declspec") {
          loc = A->getLoc();
          tokens.MarkLocation(i, loc);
          break;
        }
      }

    // Look for the openers.
    } else if (kind == opener_kind) {
      opener_toks[num_found_openers++] = &tok;
    }
  }

  if (!attr_tok || !tokens.ast) {
    return;
  }

  // Limiter used to prevent us from going too far once we've matched either
  // a keyword or an opener.
  auto fudge = ~0ull;

  // Try to find the location of `__attribute__`, `__asm`, etc.
  for (; parsed_tok && fudge && (attr_tok || num_found_openers); --parsed_tok) {

    --fudge;

    // Match an opener.
    auto tok_kind = tokens.ast->TokenKind(parsed_tok);
    if (tok_kind == opener_kind && num_found_openers) {
      tokens.MarkLocation(*opener_toks[--num_found_openers], parsed_tok);
      fudge = 32u;
    }

    if (attr_tok && tok_kind == attr_tok->kind) {
      tokens.MarkLocation(*attr_tok, parsed_tok);
      fudge = 32u;
      attr_tok = nullptr;
    }
  }
}

PrintHelper::~PrintHelper(void) {}

bool PrintHelper::handledStmt(clang::Stmt *E, clang::raw_ostream &OS_) {
  assert(&OS_ == &OS);
  (void) OS_;

  StmtPrinter stmtPrinter(OS, nullptr, tokens, policy, 0, "\n",
                          &(tokens.ast_context));
  stmtPrinter.Visit(E);
  return true;
}

bool PrintHelper::handleType(
    const clang::QualType &type, clang::raw_ostream &OS_) {
  assert(&OS_ == &OS);
  (void) OS_;

  TagDefinitionPolicyRAII disable_tags(policy);
  TypePrinter(OS, policy, tokens, 0).print(type, "");
  return true;
}

// Clang's code for printing attributes doesn't escape nested double quotes in
// attributes that contain strings, so we need to figure that out.
void PrintAttribute(raw_string_ostream &Out, const clang::Attr *A,
                    PrintedTokenRangeImpl &tokens,
                    const clang::PrintingPolicy &Policy) {

  if (A->isInherited() && !tokens.ppa->ShouldPrintInheritedAttributes()) {
    return;
  }

  if (A->isImplicit() && !tokens.ppa->ShouldPrintImplicitAttributes()) {
    return;
  }

  tokens.curr_printer_context->Tokenize();
  auto old_num_toks = tokens.tokens.size();

  PrintHelper helper(Out, Policy, tokens);

  {
    TokenPrinterContext ctx(Out, A, tokens);
    clang::Attr::SetPrinterHelper(&helper);
    A->printPretty(Out, Policy);
    clang::Attr::SetPrinterHelper(nullptr);
  }

  tokens.curr_printer_context->Tokenize();
  TryLocateAttribute(A, tokens, old_num_toks);
  return;
}

PrintedToken::~PrintedToken(void) {}

// Find the parsed token from which this printed token was derived.
std::optional<Token> PrintedToken::DerivedLocation(void) const {
  if (!impl || !range->ast ||
      impl->derived_index == kInvalidDerivedTokenIndex ||
      impl->derived_index >= range->ast->parsed_tokens.size()) {
    return std::nullopt;
  }
  return Token(
      std::shared_ptr<ParsedTokenStorage>(
          range->ast, &(range->ast->parsed_tokens)),
      impl->derived_index);
}

// Return the data associated with this token.
std::string_view PrintedToken::Data(void) const {
  if (impl) {
    assert(Index() != kInvalidTokenContextIndex);
    return impl->Data(*range);
  }
  return {};
}

// Kind of this token.
TokenKind PrintedToken::Kind(void) const {
  if (impl) {
    return static_cast<TokenKind>(impl->kind);
  }
  return TokenKind::kUnknown;
}

// Return the index of this token in its token range.
unsigned PrintedToken::Index(void) const {
  if (!range || !impl) {
    return kInvalidDerivedTokenIndex;
  }

  const auto num_tokens = range->tokens.size();
  if (!num_tokens) {
    return kInvalidDerivedTokenIndex;
  }

  auto begin = range->tokens.data();
  auto end = &(begin[num_tokens]);
  if (begin <= impl && impl < end) {
    return static_cast<unsigned>(impl - begin);
  }

  return kInvalidDerivedTokenIndex;
}

// Return this token's context, or a null context.
std::optional<TokenContext> PrintedToken::Context(void) const noexcept {
  if (!impl) {
    return {};
  }

  if (impl->context_index == kInvalidTokenContextIndex) {
    return {};
  }

  if (impl->context_index >= range->contexts.size()) {
    return {};
  }

  std::shared_ptr<const std::vector<TokenContextImpl>> contexts(
      range, &(range->contexts));
  return TokenContext(&(range->contexts[impl->context_index]),
                      std::move(contexts));
}

// Prefix increment operator.
PrintedTokenIterator &PrintedTokenIterator::operator++(void) noexcept {
  ++token.impl;
  return *this;
}

// Postfix increment operator.
PrintedTokenIterator PrintedTokenIterator::operator++(int) noexcept {
  auto ret = *this;
  ++token.impl;
  return ret;
}

// Prefix decrement operator.
PrintedTokenIterator &PrintedTokenIterator::operator--(void) noexcept {
  --token.impl;
  return *this;
}

// Postfix decrement operator.
PrintedTokenIterator PrintedTokenIterator::operator--(int) noexcept {
  auto ret = *this;
  --token.impl;
  return ret;
}

PrintedTokenIterator PrintedTokenIterator::operator-(size_t offset) const noexcept {
  return PrintedTokenIterator(token.range, token.impl - offset);
}

PrintedTokenIterator &PrintedTokenIterator::operator+=(size_t offset) noexcept {
  token.impl += offset;
  return *this;
}

PrintedTokenIterator &PrintedTokenIterator::operator-=(size_t offset) noexcept {
  token.impl -= offset;
  return *this;
}

PrintedToken PrintedTokenIterator::operator[](size_t offset) const noexcept {
  return PrintedToken(token.range, &(token.impl[offset]));
}

ptrdiff_t PrintedTokenIterator::operator-(
    const PrintedTokenIterator &that) const noexcept {
  return token.impl - token.impl;
}

PrintedTokenRangeImpl::~PrintedTokenRangeImpl(void) {}

// If any token context index is invalid, then set it to `index`.
void PrintedTokenRangeImpl::FixupInvalidTokenContexts(TokenContextIndex index) {

  const auto num_contexts = contexts.size();
  for (TokenContextIndex i = 0u; i < num_contexts; ++i) {
    if (i != index) {
      TokenContextImpl &context = contexts[i];
      if (context.parent_index == kInvalidTokenContextIndex) {
        context.parent_index = index;
      }
    }
  }

  for (PrintedTokenImpl &tok : tokens) {
    if (tok.context_index == kInvalidTokenContextIndex) {
      tok.context_index = index;
    }
  }
}

void PrintedTokenRangeImpl::AddTrailingEOF(void) {
  if (tokens.empty() || tokens.back().kind != TokenKind::kEndOfFile) {

    tokens.emplace_back(
        0u  /* data_offset */,
        0u  /* data_len */,
        kInvalidTokenContextIndex,
        TokenKind::kEndOfFile);

    if (!data.empty() && data.back() == ' ') {
      data.back() = '\0';
    } else {
      data.push_back('\0');
    }
  }
}

const TokenContextIndex PrintedTokenRangeImpl::CreateAlias(
    TokenPrinterContext *tokenizer, TokenContextIndex aliasee) {

  if (aliasee == kInvalidTokenContextIndex) {
    return kInvalidTokenContextIndex;
  }

  // If the current thing on the stack is what we're aliasing, then don't alias
  // it.
  if (tokenizer->prev_printer_context &&
      tokenizer->prev_printer_context->context_index == aliasee) {
    return aliasee;
  }

  TokenContextIndex parent_index = kInvalidTokenContextIndex;
  if (tokenizer->prev_printer_context) {
    parent_index = tokenizer->prev_printer_context->context_index;
  }

  // Try to combine identical aliases.
  static_assert(sizeof(void *) == sizeof(uint64_t));
  auto alias_addr = static_cast<uint64_t>(~aliasee);
  alias_addr <<= 32u;
  alias_addr |= parent_index;
  const auto alias_data = reinterpret_cast<const void *>(alias_addr);
  if (auto alias_it = data_to_index.find(alias_data);
      alias_it != data_to_index.end()) {
    return alias_it->second;  // Found an identical usage.
  }

  auto index = static_cast<TokenContextIndex>(contexts.size());
  assert(index == contexts.size());

  if (parent_index != kInvalidTokenContextIndex) {
    assert(parent_index < contexts.size());
    auto parent_depth = contexts[parent_index].depth;
    contexts.emplace_back(
        parent_index,
        parent_depth,
        aliasee);

  } else {
    assert(false);
    contexts.emplace_back(
        kInvalidTokenContextIndex,
        static_cast<uint16_t>(0),
        aliasee);
  }

  data_to_index.emplace(alias_data, index);

  return index;
}

TokenPrinterContext::TokenPrinterContext(
    const TokenPrinterContext &that_, no_alias_tag)
    : out(that_.out),
      prev_printer_context(that_.tokens.curr_printer_context),
      context_index(that_.context_index),
      tokens(that_.tokens) {
  if (prev_printer_context) {
    prev_printer_context->Tokenize();
  }
  tokens.curr_printer_context = this;
}

TokenPrinterContext::TokenPrinterContext(const TokenPrinterContext &that_)
    : out(that_.out),
      prev_printer_context(that_.tokens.curr_printer_context),
      context_index(that_.tokens.CreateAlias(this, that_.context_index)),
      tokens(that_.tokens) {
  if (prev_printer_context) {
    prev_printer_context->Tokenize();
  }
  tokens.curr_printer_context = this;
}

static clang::tok::TokenKind RewriteTokenKind(llvm::StringRef data) {
#define KEYWORD(X,Y) if (data == #X) return clang::tok::kw_ ## X;
#define ALIAS(str, X, mask) if (data == str) return clang::tok::kw_ ## X;
#include <clang/Basic/TokenKinds.def>

  return clang::tok::identifier;
}

void TokenPrinterContext::Tokenize(void) {
  const clang::LangOptions &lo = tokens.ast_context.getLangOpts();

  std::string &token_data = out.str();
  if (token_data.empty()) {
    return;
  }

  clang::Lexer lexer(
      clang::SourceLocation(),
      lo,
      token_data.data(),
      token_data.data(),
      token_data.data() + token_data.size());

  lexer.SetKeepWhitespaceMode(false);
  lexer.SetCommentRetentionState(false);

  clang::Token tok;

  unsigned i = 0u;

  for (auto size = token_data.size(); i < size; ) {
    if (i >= size) {
      break;
    }

    lexer.seek(i, false);

    const auto at_end = lexer.LexFromRawLexer(tok);
    if (tok.is(clang::tok::eof)) {
      break;
    }

    // Try to identify keywords where possible.
    if (tokens.ast && tok.is(clang::tok::raw_identifier)) {
      tokens.ast->orig_source_pp->LookUpIdentifierInfo(tok);
      if (tok.is(clang::tok::identifier)) {
        if (auto ii = tok.getIdentifierInfo()) {
          if (ii->hasMacroDefinition()) {
            tok.setKind(RewriteTokenKind(ii->getName()));
          }
        }
      }
    }

    const auto data_offset = static_cast<TokenDataIndex>(tokens.data.size());
    const auto tok_len = tok.getLength();
    tokens.data.reserve(data_offset + tok_len);
    bool seen_data = false;

    for (auto j = 0u; i < size && j < tok_len; ++i) {
      
      // Skip leading whitespace.
      if (!seen_data) {
        switch (token_data[i]) {
          case ' ':
          case '\n':
          case '\r':
          case '\t':
          case '\0':
          case '\\':
            continue;
          default:
            seen_data = true;
            break;
        }
      }

      ++j;
      tokens.data.push_back(token_data[i]);
    }

    if (seen_data) {
      SkipTrailingWhitespace(tokens.data);
    }

    const auto data_len = tokens.data.size() - data_offset;
    assert(0u < data_len);
    assert(data_len <= tok.getLength());
    tokens.data.push_back(' ');

    // Migrate all kinds to `identifier` now that we've got the data.
    if (tok.is(clang::tok::raw_identifier)) {
      tok.setKind(clang::tok::identifier);
    }

    // NOTE(pag): This can be a good heuristic to detect when qualifier printing
    //            goes into clang and prints template declarations inside of
    //            template argument lists. At the same time, this also ends up
    //            triggering on template template parameters.
    // if (tok.getKind() == clang::tok::kw_template) {
    //   assert(tokens.tokens.empty() ||
    //          (tokens.tokens.back().kind != TokenKind::kLess));
    // }

    // Add the token in.
    tokens.tokens.emplace_back(
        static_cast<TokenDataOffset>(data_offset),
        static_cast<uint32_t>(data_len), context_index,
        static_cast<TokenKind>(tok.getKind()));

    if (at_end) {
      break;
    }
  }

  // Clear out so future streaming just re-fills.
  token_data.clear();
}

void PrintedTokenRangeImpl::TryChangeLastKind(TokenKind old, TokenKind new_) {
  curr_printer_context->Tokenize();
  for (auto size = tokens.size(); size; --size) {
    if (tokens[size - 1u].kind == TokenKind::kUnknown) {
      continue;  // Skip whitespace.
    
    } else if (tokens[size - 1u].kind == old) {
      tokens[size - 1u].kind = new_;
      return;
    }
  }
  
  assert(false);
}

void PrintedTokenRangeImpl::MarkLocation(PrintedTokenImpl &printed,
                                         DerivedTokenIndex parsed) {
  curr_printer_context->Tokenize();
  printed.derived_index = parsed;
}

void PrintedTokenRangeImpl::MarkLocation(
    size_t printed_tok_index, DerivedTokenIndex parsed) {
  curr_printer_context->Tokenize();
  assert(printed_tok_index < tokens.size());
  tokens[printed_tok_index].derived_index = parsed;
}

void PrintedTokenRangeImpl::MarkLocation(
    size_t printed_tok_index, const clang::SourceLocation &loc) {
  curr_printer_context->Tokenize();
  assert(printed_tok_index < tokens.size());

  if (!loc.isValid()) {
    return;
  }

  // Go figure it out from the AST. We need to go through a lot of indirection
  // because the source locations inside of the parsed AST relate to a huge
  // in-memory file where each post-preprocessed token is on its own line.
  if (!ast) {
    return;
  }

  if (auto parsed = ast->ParsedTokenOffset(loc)) {
    tokens[printed_tok_index].derived_index = parsed.value();
  }
}

void TokenPrinterContext::MarkLocation(clang::SourceLocation loc) {
  Tokenize();
  if (auto num_tokens = tokens.tokens.size()) {
    tokens.MarkLocation(num_tokens - 1u, loc);
  }
}

// Mark the last printed token as having the same location as `tok`.
void TokenPrinterContext::MarkLocation(DerivedTokenIndex parsed) {
  Tokenize();
  if (auto num_tokens = tokens.tokens.size()) {
    tokens.MarkLocation(num_tokens - 1u, parsed);
  }
}

TokenPrinterContext::~TokenPrinterContext(void) {
  Tokenize();
  tokens.curr_printer_context = prev_printer_context;
  if (owns_data) {
    tokens.data_to_index.erase(owns_data);
  }
}

// Create an empty range.
PrintedTokenRange PrintedTokenRange::CreateEmpty(const AST &ast) {
  auto &context = ast.impl->tu->getASTContext();
  auto tokens = std::make_shared<PrintedTokenRangeImpl>(context);
  tokens->AddTrailingEOF();
  return PrintedTokenRangeImpl::ToPrintedTokenRange(std::move(tokens));
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(
    const Decl &decl, const PrintingPolicy &pp) {
  return PrintedTokenRange::Create(
      decl.ast, const_cast<clang::Decl *>(decl.u.Decl), pp);
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(
    const Stmt &stmt, const PrintingPolicy &pp) {
  return PrintedTokenRange::Create(
      stmt.ast, const_cast<clang::Stmt *>(stmt.u.Stmt), pp);
}

// More typical APIs when we've got PASTA ASTs.
PrintedTokenRange PrintedTokenRange::Create(
    const Type &type, const PrintingPolicy &pp) {
  auto &ast = type.ast;
  auto &ast_ctx = ast->ci->getASTContext();
  clang::QualType fast_qtype(type.u.Type,
                             type.qualifiers & clang::Qualifiers::FastMask);
  auto self = ast_ctx.getQualifiedType(
      fast_qtype, clang::Qualifiers::fromOpaqueValue(type.qualifiers));

  return PrintedTokenRange::Create(type.ast, self, pp);
}

// Number of tokens in this range.
size_t PrintedTokenRange::Size(void) const noexcept {
  return first < after_last ? static_cast<size_t>(after_last - first) : 0;
}

std::string_view PrintedTokenRange::Data(void) const noexcept {
  if (first >= after_last) {
    return "";
  }

  auto begin_offset = first->data_offset;
  auto end_offset = after_last[-1].data_offset + after_last[-1].data_len;
  std::string_view all_data(impl->data);
  return all_data.substr(begin_offset, end_offset - begin_offset);
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<PrintedToken> PrintedTokenRange::At(size_t index) const noexcept {
  if (auto ptr = &(first[index]); ptr < after_last) {
    return PrintedToken(impl, ptr);
  }
  return std::nullopt;
}

// Unsafe indexed access into the token range.
PrintedToken PrintedTokenRange::operator[](size_t index) const {
  return PrintedToken(impl, &(first[index]));
}

// Create a new printed token range by concatenating two printed token ranges
// together.
std::optional<PrintedTokenRange> PrintedTokenRange::Concatenate(
    const PrintedTokenRange &a, const PrintedTokenRange &b) {
  if (!a && !b) {
    return std::nullopt;
  }

  if (!a) {
    return b;
  }

  if (!b) {
    return a;
  }

  if (&(a.impl->ast_context) != &(b.impl->ast_context)) {
    return std::nullopt;
  }

  if (a.impl->ast.get() != b.impl->ast.get()) {
    return std::nullopt;
  }

  auto new_impl = std::make_shared<PrintedTokenRangeImpl>(a.impl->ast_context);
  new_impl->ast = a.impl->ast;
  new_impl->tokens.reserve(a.impl->tokens.size() + b.impl->tokens.size() + 1u);
  new_impl->contexts.reserve(
      ((a.impl->contexts.size() + b.impl->contexts.size()) * 3u) / 2u);
  new_impl->data = a.impl->data + b.impl->data;

  for (PrintedTokenImpl &new_tok : new_impl->tokens) {
    new_tok.matched_in_align = false;
  }

  std::unordered_multimap<const void *, TokenContextIndex> data_to_context;

  // Top-level context should be the AST.
  if (a.impl->ast) {
    new_impl->contexts.emplace_back(*(new_impl->ast));
    data_to_context.emplace(new_impl->ast.get(), kASTTokenContextIndex);
  }

  std::vector<TokenContextIndex> context_map;
  context_map.assign(a.impl->contexts.size(), kInvalidTokenContextIndex);

  for (auto a_tok = a.first; a_tok < a.after_last; ++a_tok) {
    if (a_tok->kind != TokenKind::kEndOfFile) {
      PrintedTokenImpl &new_tok = new_impl->tokens.emplace_back(*a_tok);
      new_tok.matched_in_align = false;
      new_tok.context_index = MigrateContexts(
          new_tok.context_index, a.impl->contexts, new_impl->contexts,
          data_to_context, context_map);
    }
  }

  context_map.assign(b.impl->contexts.size(), kInvalidTokenContextIndex);

  auto a_data_size = static_cast<TokenDataOffset>(a.impl->data.size());
  for (auto b_tok = b.first; b_tok < b.after_last; ++b_tok) {
    if (b_tok->kind != TokenKind::kEndOfFile) {
      PrintedTokenImpl &new_tok = new_impl->tokens.emplace_back(*b_tok);
      new_tok.matched_in_align = false;
      new_tok.data_offset += a_data_size;
      new_tok.context_index = MigrateContexts(
          new_tok.context_index, b.impl->contexts, new_impl->contexts,
          data_to_context, context_map);
    }
  }

  new_impl->AddTrailingEOF();
  return PrintedTokenRangeImpl::ToPrintedTokenRange(std::move(new_impl));
}

// Tell us if this was a token that was actually parsed.
static bool IsParsedToken(const pasta::Token &tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kFileToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
      return !tok.Data().empty();

    default:
      return false;
  }
}

namespace {

static std::optional<DerivedTokenIndex> LeadingWhitespaceTokenOffset(
    const ParsedTokenStorage &tokens, DerivedTokenIndex offset) {
  std::optional<DerivedTokenIndex> min_found;
  while (offset) {
    switch (tokens.Role(--offset)) {
      case TokenRole::kBeginOfFileMarker:
      case TokenRole::kEndOfFileMarker:
      case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kMacroDirectiveMarker:
        return min_found;
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
        assert(false);
        continue;
      case TokenRole::kFinalMacroExpansionToken:
      case TokenRole::kFileToken:
        break;
      case TokenRole::kInvalid:
      case TokenRole::kBeginOfMacroExpansionMarker:
        continue;
    }

    switch (tokens.Kind(offset)) {
      case TokenKind::kUnknown:
      case TokenKind::kComment:
        min_found = offset;
        continue;
      default:
        return min_found;
    }
  }

  return min_found;
}


static std::optional<DerivedTokenIndex> TrailingWhitespaceTokenOffset(
    const ParsedTokenStorage &tokens, DerivedTokenIndex offset) {
  std::optional<DerivedTokenIndex> min_found;
  auto size = tokens.size();
  while ((offset + 1u) < size) {
    switch (tokens.Role(++offset)) {
      case TokenRole::kBeginOfFileMarker:
      case TokenRole::kEndOfFileMarker:
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kEndOfMacroExpansionMarker:
      case TokenRole::kMacroDirectiveMarker:
        return min_found;
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
        assert(false);
        continue;
      case TokenRole::kFinalMacroExpansionToken:
      case TokenRole::kFileToken:
        break;
      case TokenRole::kInvalid:
        continue;
    }

    switch (tokens.Kind(offset)) {
      case TokenKind::kUnknown:
      case TokenKind::kComment:
        min_found = offset;
        continue;
      default:
        return min_found;
    }
  }

  return min_found;
}

}  // namespace

// Create a new printed token range from `wants_ws` and `has_ws`, where
// `wants_ws` and `has_ws` share derived token locations, and we want to
// import whitespace from `has_ws` into places where it's missing in
// `wants_ws`, but without chaning `wants_ws`.
PrintedTokenRange PrintedTokenRange::AdoptWhitespace(
    const PrintedTokenRange &wants_ws, const PrintedTokenRange &has_ws) {
  
  if (!wants_ws.impl->ast || !has_ws.impl->ast ||
      &(wants_ws.impl->ast_context) != &(has_ws.impl->ast_context)) {
    return wants_ws;
  }

  const ParsedTokenStorage &parsed_tokens = has_ws.impl->ast->parsed_tokens;

  // Create a map of token indices to offsets of the earlier whitespace/comment
  // preceding that token index, where there are no intermediate things that
  // shouldn't be injected.
  std::unordered_map<DerivedTokenIndex, DerivedTokenIndex> leading_ws;
  std::unordered_map<DerivedTokenIndex, DerivedTokenIndex> trailing_ws;

  auto first = true;
  for (const auto &has_ws_tok : has_ws.impl->tokens) {
    if (has_ws_tok.derived_index == kInvalidDerivedTokenIndex) {
      continue;
    }

    if (has_ws_tok.kind == TokenKind::kComment ||
        has_ws_tok.kind == TokenKind::kUnknown) {
      continue;
    }

    auto offset = TrailingWhitespaceTokenOffset(
        parsed_tokens, has_ws_tok.derived_index);
    if (offset) {
      trailing_ws.emplace(has_ws_tok.derived_index, offset.value());
    }

    if (first) {
      first = false;
      continue;
    }

    offset = LeadingWhitespaceTokenOffset(
        parsed_tokens, has_ws_tok.derived_index);
    if (offset) {
      leading_ws.emplace(has_ws_tok.derived_index, offset.value());
    }
  }

  // We won't succeed at injecting any leading whitespace because we don't know
  // of any.
  if (leading_ws.empty() && trailing_ws.empty()) {
    return wants_ws;
  }

  auto new_impl = std::make_shared<PrintedTokenRangeImpl>(
      has_ws.impl->ast->ci->getASTContext());
  new_impl->ast = has_ws.impl->ast;
  new_impl->tokens.reserve(std::max(wants_ws.Size(), has_ws.Size()) + 1u);
  new_impl->data.reserve(
      std::max(wants_ws.Data().size(), has_ws.Data().size()) + 1u);

  std::unordered_multimap<const void *, TokenContextIndex> data_to_context;

  // Top-level context should be the AST.
  if (new_impl->ast) {
    new_impl->contexts.emplace_back(*(new_impl->ast));
    data_to_context.emplace(new_impl->ast.get(), kASTTokenContextIndex);
  }

  std::vector<TokenContextIndex> context_map;
  context_map.assign(
      wants_ws.impl->contexts.size() + has_ws.impl->contexts.size(),
      kInvalidTokenContextIndex);

  // Get the first leading whitespace.
  for (const auto &has_ws_tok : has_ws.impl->tokens) {
    if (has_ws_tok.kind != TokenKind::kComment &&
        has_ws_tok.kind != TokenKind::kUnknown) {
      break;
    }

    if (has_ws_tok.derived_index == kInvalidDerivedTokenIndex) {
      break;
    }

    auto new_context_index = MigrateContexts(
        has_ws_tok.context_index, has_ws.impl->contexts,
        new_impl->contexts, data_to_context, context_map);

    auto data = has_ws_tok.Data(*(has_ws.impl));
    auto &new_tok = new_impl->tokens.emplace_back(
        static_cast<uint32_t>(new_impl->data.size()),
        static_cast<uint32_t>(data.size()),
        new_context_index, has_ws_tok.kind);
    new_tok.derived_index = has_ws_tok.derived_index;
    new_impl->data.insert(new_impl->data.end(), data.begin(), data.end());
  }

  auto add_ws_tok = [&] (auto new_context_index, auto ws_offset) {
    switch (parsed_tokens.Role(ws_offset)) {
      case TokenRole::kFileToken:
      case TokenRole::kFinalMacroExpansionToken:
        break;
      default:
        return;
    }

    // TODO(pag): Double check what the last non-whitespace token kind was,
    //            e.g. a `,` or `;` or a `)` or a `}` means we should look
    //            at the context parent.
    auto ci = new_impl->tokens.empty() ? new_context_index :
              new_impl->tokens.back().context_index;

    auto data = parsed_tokens.Data(ws_offset);
    auto &new_tok = new_impl->tokens.emplace_back(
        static_cast<uint32_t>(new_impl->data.size()),
        static_cast<uint32_t>(data.size()),
        ci, parsed_tokens.Kind(ws_offset));
    new_tok.derived_index = ws_offset;
    new_impl->data.insert(new_impl->data.end(), data.begin(), data.end());
  };

  // Now bring in the normal tokens.
  for (const auto &wants_ws_tok : wants_ws.impl->tokens) {
    
    // Strip existing whitespace to make comparison logic easier.
    if (wants_ws_tok.kind == TokenKind::kComment ||
        wants_ws_tok.kind == TokenKind::kUnknown ||
        wants_ws_tok.kind == TokenKind::kEndOfFile) {
      continue;
    }

    auto new_context_index = MigrateContexts(
        wants_ws_tok.context_index, wants_ws.impl->contexts,
        new_impl->contexts, data_to_context, context_map);

    // Add in the leading whitespace/comments.
    auto it = leading_ws.find(wants_ws_tok.derived_index);
    if (it != leading_ws.end()) {
      
      for (auto ws_offset = it->second; ws_offset < wants_ws_tok.derived_index;
           ++ws_offset) {
        add_ws_tok(new_context_index, ws_offset);
      }
    
    } else if (new_impl->tokens.empty()) {

    } else if (it = trailing_ws.find(new_impl->tokens.back().derived_index);
               it != trailing_ws.end()) {
      for (auto ws_offset = new_impl->tokens.back().derived_index + 1u;
           ws_offset <= it->second; ++ws_offset) {
        add_ws_tok(new_context_index, ws_offset);
      }
    }

    // Add in the original token.
    auto data = wants_ws_tok.Data(*(wants_ws.impl));
    auto &new_tok = new_impl->tokens.emplace_back(
        static_cast<uint32_t>(new_impl->data.size()),
        static_cast<uint32_t>(data.size()), new_context_index,
        wants_ws_tok.kind);
    new_tok.derived_index = wants_ws_tok.derived_index;
    new_impl->data.insert(new_impl->data.end(), data.begin(), data.end());
  }

  new_impl->AddTrailingEOF();
  return PrintedTokenRangeImpl::ToPrintedTokenRange(std::move(new_impl));
}

// Create a new printed token range, where the token data is taken from `a`.
// The only token contexts in an adopted range are AST contexts. The only tokens
// in a printed token range are file tokens and complete macro expansion tokens.
PrintedTokenRange PrintedTokenRange::Adopt(const TokenRange &a) {
  
  auto new_impl = std::make_shared<PrintedTokenRangeImpl>(
      a.storage->ast->ci->getASTContext());
  new_impl->ast = std::shared_ptr<ASTImpl>(a.storage, a.storage->ast);
  new_impl->tokens.reserve(a.Size() + 1u);
  new_impl->contexts.emplace_back(*(new_impl->ast));  // AST context.

  for (Token tok : a) {
    if (!IsParsedToken(tok)) {
      continue;
    }

    std::string_view data = tok.Data();
    PrintedTokenImpl &new_tok = new_impl->tokens.emplace_back(
        static_cast<TokenDataOffset>(new_impl->data.size()),
        static_cast<uint32_t>(data.size()),
        kASTTokenContextIndex,
        tok.Kind());

    new_tok.derived_index = static_cast<DerivedTokenIndex>(tok.Index());
    new_impl->data.insert(new_impl->data.end(), data.begin(), data.end());
  }

  new_impl->AddTrailingEOF();
  return PrintedTokenRangeImpl::ToPrintedTokenRange(std::move(new_impl));
}

// Create a copy of `a`.
PrintedTokenRange PrintedTokenRange::Copy(const PrintedTokenRange &a) {
  return PrintedTokenRangeImpl::ToPrintedTokenRange(
      std::make_shared<PrintedTokenRangeImpl>(*a.impl));
}

// Dump token provenance information.
void PrintedTokenRange::DumpProvenanceInformation(void) {
  for (auto tok = first; tok < after_last; ++tok) {
    tok->derived_index = kInvalidDerivedTokenIndex;
  }
}

PrintingPolicy::~PrintingPolicy(void) {}

bool PrintingPolicy::ShouldPrintTagBodies(void) const {
  return true;
}

// These defaults are shared between `PrintingPolicy` and
// `PrintingPolicyAdaptor`.
static constexpr bool kShouldPrintInheritedAttributes = false;
static constexpr bool kShouldPrintImplicitAttributes = false;
static constexpr bool kShouldPrintConstantExpressionsInTypes = true;
static constexpr bool kShouldPrintOriginalTypeOfAdjustedType = true;
static constexpr bool kShouldPrintOriginalTypeOfDecayedType = true;
static constexpr bool kShouldPrintTemplate = true;
static constexpr bool kShouldPrintSpecialization = false;

bool PrintingPolicy::ShouldPrintInheritedAttributes(void) const {
  return kShouldPrintInheritedAttributes;
}

bool PrintingPolicy::ShouldPrintImplicitAttributes(void) const {
  return kShouldPrintImplicitAttributes;
}

bool PrintingPolicy::ShouldPrintConstantExpressionsInTypes(void) const {
  return kShouldPrintConstantExpressionsInTypes;
}

bool PrintingPolicy::ShouldPrintOriginalTypeOfAdjustedType(void) const {
  return kShouldPrintOriginalTypeOfAdjustedType;
}

bool PrintingPolicy::ShouldPrintOriginalTypeOfDecayedType(void) const {
  return kShouldPrintOriginalTypeOfDecayedType;
}

bool PrintingPolicy::ShouldPrintTemplate(const TemplateDecl &) const {
  return kShouldPrintTemplate;
}

bool PrintingPolicy::ShouldPrintTemplate(
    const ClassTemplatePartialSpecializationDecl &) const {
  return kShouldPrintTemplate;
}

bool PrintingPolicy::ShouldPrintTemplate(
    const VarTemplatePartialSpecializationDecl &) const {
  return kShouldPrintTemplate;
}

bool PrintingPolicy::ShouldPrintSpecialization(
    const ClassTemplateDecl &, const ClassTemplateSpecializationDecl &) const {
  return kShouldPrintSpecialization;
}

bool PrintingPolicy::ShouldPrintSpecialization(const FunctionTemplateDecl &,
                                               const FunctionDecl &) const {
  return kShouldPrintSpecialization;
}

bool PrintingPolicy::ShouldPrintSpecialization(
    const VarTemplateDecl &, const VarTemplateSpecializationDecl &) const {
  return kShouldPrintSpecialization;
}

ProxyPrintingPolicy::~ProxyPrintingPolicy(void) {}

bool ProxyPrintingPolicy::ShouldPrintTagBodies(void) const {
  return next.ShouldPrintTagBodies();
}

bool ProxyPrintingPolicy::ShouldPrintInheritedAttributes(void) const {
  return next.ShouldPrintInheritedAttributes();
}

bool ProxyPrintingPolicy::ShouldPrintImplicitAttributes(void) const {
  return next.ShouldPrintImplicitAttributes();
}

bool ProxyPrintingPolicy::ShouldPrintConstantExpressionsInTypes(void) const {
  return next.ShouldPrintConstantExpressionsInTypes();
}

bool ProxyPrintingPolicy::ShouldPrintOriginalTypeOfAdjustedType(void) const {
  return next.ShouldPrintOriginalTypeOfAdjustedType();
}

bool ProxyPrintingPolicy::ShouldPrintOriginalTypeOfDecayedType(void) const {
  return next.ShouldPrintOriginalTypeOfDecayedType();
}

bool ProxyPrintingPolicy::ShouldPrintTemplate(const TemplateDecl &tpl) const {
  return next.ShouldPrintTemplate(tpl);
}

bool ProxyPrintingPolicy::ShouldPrintTemplate(
    const ClassTemplatePartialSpecializationDecl &tpl) const {
  return next.ShouldPrintTemplate(tpl);
}

bool ProxyPrintingPolicy::ShouldPrintTemplate(
    const VarTemplatePartialSpecializationDecl &tpl) const {
  return next.ShouldPrintTemplate(tpl);
}

bool ProxyPrintingPolicy::ShouldPrintSpecialization(
    const ClassTemplateDecl &tpl,
    const ClassTemplateSpecializationDecl &spec) const {
  return next.ShouldPrintSpecialization(tpl, spec);
}

bool ProxyPrintingPolicy::ShouldPrintSpecialization(
  const VarTemplateDecl &tpl, const VarTemplateSpecializationDecl &spec) const {
  return next.ShouldPrintSpecialization(tpl, spec);
}

bool ProxyPrintingPolicy::ShouldPrintSpecialization(
  const FunctionTemplateDecl &tpl, const FunctionDecl &spec) const {
  return next.ShouldPrintSpecialization(tpl, spec);
}

bool PrintingPolicyAdaptor::ShouldPrintInheritedAttributes(void) const {
  return pp ? pp->ShouldPrintInheritedAttributes() : kShouldPrintInheritedAttributes;
}

bool PrintingPolicyAdaptor::ShouldPrintImplicitAttributes(void) const {
  return pp ? pp->ShouldPrintImplicitAttributes() : kShouldPrintImplicitAttributes;
}

bool PrintingPolicyAdaptor::ShouldPrintConstantExpressionsInTypes(void) const {
  return pp ? pp->ShouldPrintConstantExpressionsInTypes() : kShouldPrintConstantExpressionsInTypes;
}

bool PrintingPolicyAdaptor::ShouldPrintOriginalTypeOfAdjustedType(void) const {
  return pp ? pp->ShouldPrintOriginalTypeOfAdjustedType() : kShouldPrintOriginalTypeOfAdjustedType;
}

bool PrintingPolicyAdaptor::ShouldPrintOriginalTypeOfDecayedType(void) const {
  return pp ? pp->ShouldPrintOriginalTypeOfDecayedType() : kShouldPrintOriginalTypeOfDecayedType;
}

bool PrintingPolicyAdaptor::ShouldPrintTemplate(
    clang::TemplateDecl *tpl) const {

#ifndef PASTA_IN_BOOTSTRAP
  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<TemplateDecl>(ast, tpl);
    return pp->ShouldPrintTemplate(wrapped_tpl);
  }
#endif

  if (!decl_to_print) {
    return kShouldPrintTemplate;
  }

  if (tpl == decl_to_print) {
    return true;
  }

  // Make sure we're not asking to print a specialization of `tpl`.
  if (auto cspec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl_to_print)) {
    return cspec->getSpecializedTemplate()->getCanonicalDecl() != tpl->getCanonicalDecl();
  }

  if (auto vspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(decl_to_print)) {
    return vspec->getSpecializedTemplate()->getCanonicalDecl() != tpl->getCanonicalDecl();
  }

  if (auto fspec = clang::dyn_cast<clang::FunctionDecl>(decl_to_print)) {
    if (fspec->isTemplateInstantiation()) {
      return fspec->getPrimaryTemplate()->getCanonicalDecl() != tpl->getCanonicalDecl();
    }
  }

  return true;
}

bool PrintingPolicyAdaptor::ShouldPrintTemplate(
    clang::ClassTemplatePartialSpecializationDecl *tpl) const {

#ifndef PASTA_IN_BOOTSTRAP
  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<ClassTemplatePartialSpecializationDecl>(ast, tpl);
    return pp->ShouldPrintTemplate(wrapped_tpl);
  }
#endif

  if (!decl_to_print) {
    return kShouldPrintTemplate;
  }

  if (tpl == decl_to_print) {
    return true;
  }

  if (auto cspec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl_to_print)) {
    auto inst = cspec->getSpecializedTemplateOrPartial();
    if (auto cpspec = inst.dyn_cast<clang::ClassTemplatePartialSpecializationDecl *>()) {
      return cpspec->getCanonicalDecl() != tpl->getCanonicalDecl();
    }
  }

  return true;
}

bool PrintingPolicyAdaptor::ShouldPrintTemplate(
    clang::VarTemplatePartialSpecializationDecl *tpl) const {

#ifndef PASTA_IN_BOOTSTRAP
  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<VarTemplatePartialSpecializationDecl>(ast, tpl);
    return pp->ShouldPrintTemplate(wrapped_tpl);
  }
#endif

  if (!decl_to_print) {
    return kShouldPrintTemplate;
  }

  if (tpl == decl_to_print) {
    return true;
  }

  if (auto cspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(decl_to_print)) {
    auto inst = cspec->getSpecializedTemplateOrPartial();
    if (auto cpspec = inst.dyn_cast<clang::VarTemplatePartialSpecializationDecl *>()) {
      return cpspec->getCanonicalDecl() != tpl->getCanonicalDecl();
    }
  }

  return true;
}

bool PrintingPolicyAdaptor::ShouldPrintSpecialization(
    clang::ClassTemplateDecl *tpl,
    clang::ClassTemplateSpecializationDecl *spec) const {

#ifndef PASTA_IN_BOOTSTRAP
  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<ClassTemplateDecl>(ast, tpl);
    auto wrapped_spec = DeclBuilder::Create<ClassTemplateSpecializationDecl>(ast, spec);
    return pp->ShouldPrintSpecialization(wrapped_tpl, wrapped_spec);
  }
#endif

  return spec == decl_to_print ? true : kShouldPrintSpecialization;
}

bool PrintingPolicyAdaptor::ShouldPrintSpecialization(
    clang::VarTemplateDecl *tpl,
    clang::VarTemplateSpecializationDecl *spec) const {

#ifndef PASTA_IN_BOOTSTRAP
  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<VarTemplateDecl>(ast, tpl);
    auto wrapped_spec = DeclBuilder::Create<VarTemplateSpecializationDecl>(ast, spec);
    return pp->ShouldPrintSpecialization(wrapped_tpl, wrapped_spec);
  }
#endif

  return spec == decl_to_print ? true : kShouldPrintSpecialization;
}

bool PrintingPolicyAdaptor::ShouldPrintSpecialization(
    clang::FunctionTemplateDecl *tpl, clang::FunctionDecl *spec) const {

#ifndef PASTA_IN_BOOTSTRAP
  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<FunctionTemplateDecl>(ast, tpl);
    auto wrapped_spec = DeclBuilder::Create<FunctionDecl>(ast, spec);
    return pp->ShouldPrintSpecialization(wrapped_tpl, wrapped_spec);
  }
#endif

  return spec == decl_to_print ? true : kShouldPrintSpecialization;
}

}  // namespace pasta
