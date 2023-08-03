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

namespace pasta {

static void TryLocateAttribute(const clang::Attr *A,
                               PrintedTokenRangeImpl &tokens,
                               size_t old_num_toks) {
  clang::tok::TokenKind kind_to_find = clang::tok::unknown;
  unsigned num_to_find = 0u;
  unsigned num_found = 0u;
  switch (A->getSyntax()) {
    case clang::AttributeCommonInfo::AS_CXX11:
    case clang::AttributeCommonInfo::AS_C2x:
      kind_to_find = clang::tok::l_square;
      num_to_find = 2u;
      break;

    case clang::AttributeCommonInfo::AS_GNU:
      kind_to_find = clang::tok::l_paren;
      num_to_find = 2u;
      break;
    case clang::AttributeCommonInfo::AS_Declspec:
    case clang::AttributeCommonInfo::AS_Microsoft:
      kind_to_find = clang::tok::l_paren;
      num_to_find = 1u;
      break;

    case clang::AttributeCommonInfo::AS_Keyword:
    case clang::AttributeCommonInfo::AS_Pragma:
    case clang::AttributeCommonInfo::AS_ContextSensitiveKeyword:
    case clang::AttributeCommonInfo::AS_HLSLSemantic:
      num_to_find = 0u;
      break;
  }

  size_t max_i = tokens.tokens.size();
  if (old_num_toks >= max_i) {
    return;
  }

  clang::SourceLocation loc = A->getLocation();
  PrintedTokenImpl *attr_tok = nullptr;

  for (size_t i = old_num_toks; i < max_i; ++i) {
    PrintedTokenImpl &tok = tokens.tokens[i];
    clang::tok::TokenKind kind = tok.Kind();

    switch (kind) {
      case clang::tok::kw___attribute:
      case clang::tok::kw___declspec:
      case clang::tok::kw_asm:
      case clang::tok::kw___ptr32:
      case clang::tok::kw___ptr64:
      case clang::tok::kw___fastcall:
      case clang::tok::kw___stdcall:
      case clang::tok::kw___thiscall:
      case clang::tok::kw___vectorcall:
      case clang::tok::kw___cdecl:
      case clang::tok::kw___forceinline:  // Maybe.
      case clang::tok::kw__Nonnull:
      case clang::tok::kw__Nullable:
      case clang::tok::kw__Null_unspecified:
      case clang::tok::kw__Nullable_result:
        attr_tok = &tok;
        break;
      default:
        break;
    }

    if (num_found >= num_to_find) {
      if (!tok.opaque_source_loc &&
          (kind == clang::tok::identifier ||
           kind == clang::tok::raw_identifier)) {
        llvm::StringRef data(tok.Data(tokens));

        // TODO(pag): uuid, guid?
        if (data != "__attribute__" &&
            data != "__declspec") {
          loc = A->getLoc();
          tokens.MarkLocation(i, loc);
          break;
        }
      }
    } else {
      if (kind == kind_to_find) {
        ++num_found;
      }
    }
  }

  if (!attr_tok || !tokens.ast) {
    return;
  }

  const TokenImpl *parsed_tok = tokens.ast->RawTokenAt(loc);
  if (!parsed_tok) {
    return;
  }

  const TokenImpl *first_parsed_tok = tokens.ast->tokens.data();
  const TokenImpl *min_parsed_tok =
      std::max(first_parsed_tok, &(parsed_tok[-32]));

  // Try to find the location of `__attribute__`, `__asm`, etc.
  for (; min_parsed_tok < parsed_tok; --parsed_tok) {
    if (parsed_tok->Kind() == attr_tok->Kind()) {
      attr_tok->opaque_source_loc = parsed_tok->opaque_source_loc;
      break;
    }
  }
}

// Undo raw newlines and other things in strings.
static void ReEscapeOutput(raw_string_ostream &Out, std::string a) {
  for (char c : a) {
    switch (c) {
      case '\n':
        Out << "\\n";
        break;
      case '\r':
        Out << "\\r";
        break;
      case '\t':
        Out << "\\t";
        break;
      default:
        Out << c;
        break;
    }
  }
}

// Clang's code for printing attributes doesn't escape nested double quotes in
// attributes that contain strings, so we need to figure that out.
void PrintAttribute(raw_string_ostream &Out, const clang::Attr *A,
                    PrintedTokenRangeImpl &tokens,
                    const clang::PrintingPolicy &Policy) {
  std::string a;
  std::string new_a;
  {
    llvm::raw_string_ostream os(a);
    A->printPretty(os, Policy);
    os.flush();
  }

  tokens.curr_printer_context->Tokenize();
  const size_t old_num_toks = tokens.tokens.size();

  // Fast path: no embedded strings.
  const char *start = a.c_str();
  const char *first_quote = strchr(start, '"');
  if (!first_quote || first_quote[0] != '"') {
    TokenPrinterContext ctx(Out, A, tokens);
    ReEscapeOutput(Out, std::move(a));
    Out.flush();

    tokens.curr_printer_context->Tokenize();
    TryLocateAttribute(A, tokens, old_num_toks);
    return;
  }

  auto end = &(start[a.size()]);
  auto second_quote = strchr(&(first_quote[1]), '"');
  assert(second_quote && second_quote[0] == '"');
  auto third_quote = strchr(&(second_quote[1]), '"');

  // If there is no third quote, then assume no nesting. This is a dumb
  // hack to handle things like `asm("label")`.
  if (!third_quote || third_quote[0] != '"') {
    TokenPrinterContext ctx(Out, A, tokens);
    ReEscapeOutput(Out, std::move(a));
    Out.flush();

    tokens.curr_printer_context->Tokenize();
    TryLocateAttribute(A, tokens, old_num_toks);
    return;
  }

  // TODO(pag): This won't handle doubly/triply nested quotes. Just single
  //            nested quotes.
  new_a.reserve(a.size());
  while (second_quote && strchr(&(second_quote[1]), '"')) {
    new_a.insert(new_a.end(), start, second_quote);
    new_a.push_back('\\');
    new_a.push_back('"');
    start = &(second_quote[1]);
    second_quote = strchr(&(start[1]), '"');
  }

  if (second_quote) {
    new_a.insert(new_a.end(), second_quote, end);

  } else if (start) {
    new_a.insert(new_a.end(), start, end);
  }

  TokenPrinterContext ctx(Out, A, tokens);
  ReEscapeOutput(Out, std::move(new_a));
  Out.flush();

  tokens.curr_printer_context->Tokenize();
  TryLocateAttribute(A, tokens, old_num_toks);
}

PrintedToken::~PrintedToken(void) {}

// Find the parsed token from which this printed token was derived.
std::optional<Token> PrintedToken::DerivedLocation(void) const {
  if (!impl || !range->ast ||
      impl->derived_index == kInvalidDerivedTokenIndex ||
      impl->derived_index >= range->ast->tokens.size()) {
    return std::nullopt;

  } else {
    return Token(range->ast, &(range->ast->tokens[impl->derived_index]));
  }
}

// Return the data associated with this token.
std::string_view PrintedToken::Data(void) const {
  if (impl) {
    return impl->Data(*range);
  } else {
    return {};
  }
}

// Kind of this token.
TokenKind PrintedToken::Kind(void) const {
  if (impl) {
    return static_cast<TokenKind>(impl->Kind());
  } else {
    return TokenKind::kUnknown;
  }
}

// Number of leading new lines (before any indentation spaces).
unsigned PrintedToken::NumLeadingNewLines(void) const {
  return impl->num_leading_new_lines;
}

// Number of leading spaces (after any leading new lines).
unsigned PrintedToken::NumleadingSpaces(void) const {
  return impl->num_leading_spaces;
}

// Return the index of this token in its token range.
unsigned PrintedToken::Index(void) const {
  if (!range) {
    return ~0u;
  }
  const auto num_tokens = range->tokens.size();
  if (!num_tokens) {
    return ~0u;
  }

  auto begin = range->tokens.data();
  auto end = &(begin[num_tokens]);
  if (begin <= impl && impl < end) {
    return static_cast<unsigned>(impl - begin);
  } else {
    return ~0u;
  }
}

// Return this token's context, or a null context.
std::optional<TokenContext> PrintedToken::Context(void) const noexcept {
  if (!impl) {
    return {};
  } else if (impl->context_index == kInvalidTokenContextIndex) {
    return {};
  } else if (impl->context_index >= range->contexts.size()) {
    return {};
  } else {
    std::shared_ptr<const std::vector<TokenContextImpl>> contexts(
        range, &(range->contexts));
    return TokenContext(&(range->contexts[impl->context_index]),
                        std::move(contexts));
  }
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

namespace {

static std::tuple<unsigned, unsigned, unsigned> SkipWhitespace(
    const std::string &data, unsigned i) {
  unsigned num_leading_spaces = 0;
  unsigned num_leading_lines = 0;

  for (const auto size = data.size(); i < size; ++i) {
    switch (data[i]) {
      case '\t':
        num_leading_spaces += 4;
        continue;
      case ' ':
        num_leading_spaces += 1;
        continue;
      case '\r':
        continue;
      case '\n':
        num_leading_spaces = 0;
        num_leading_lines += 1;
        break;
      case '\\':
        return {num_leading_lines, num_leading_spaces, i};
      default:
        return {num_leading_lines, num_leading_spaces, i};
    }
  }
  return {num_leading_lines, num_leading_spaces, i};
}

}  // namespace

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

void TokenPrinterContext::Tokenize(void) {
  const clang::LangOptions &lo = tokens.ast_context.getLangOpts();

  std::string &token_data = out.str();
  if (token_data.empty()) {
    return;
  }

  clang::Lexer lexer(
      clang::SourceLocation(),
      lo,
      &(token_data[0]),
      &(token_data[0]),
      &(token_data[0]) + token_data.size());

  lexer.SetKeepWhitespaceMode(false);
  lexer.SetCommentRetentionState(false);

  clang::Token tok;

  unsigned num_nl = 0u;
  unsigned num_sp = 0u;
  unsigned i = 0u;

  for (auto size = token_data.size(); i < size; ) {
    unsigned last_i = i;
    std::tie(num_nl, num_sp, i) = SkipWhitespace(token_data, i);
    if (i >= size) {
      break;
    }

    lexer.seek(last_i, false);
    last_i = i;

    const auto at_end = lexer.LexFromRawLexer(tok);
    if (tok.is(clang::tok::eof)) {
      break;
    } else if (tok.isOneOf(clang::tok::semi, clang::tok::comma)) {
      num_nl = 0;
      num_sp = 0;
    }

    // Try to identify keywords where possible.
    if (tokens.ast && tok.is(clang::tok::raw_identifier)) {
      clang::Token saved_tok = tok;
      tokens.ast->orig_source_pp->LookUpIdentifierInfo(tok);
      if (!clang::tok::getKeywordSpelling(tok.getKind())) {
        tok = saved_tok;
      }
    }

    const auto data_offset = static_cast<TokenDataIndex>(tokens.data.size());
    assert(0ll <= static_cast<TokenDataOffset>(data_offset));
    uint32_t data_len = 0u;
    tokens.data.reserve(data_offset + tok.getLength());
    for (last_i = i, i += tok.getLength(); last_i < i && token_data[last_i];
        ++last_i) {
      tokens.data.push_back(token_data[last_i]);
      ++data_len;
      assert(static_cast<uint32_t>(data_len & TokenImpl::kTokenSizeMask) != 0u);
    }
    tokens.data.push_back('\0');  // Make sure all tokens end up NUL-terminated.

    // Add the token in.
    tokens.tokens.emplace_back(
        static_cast<TokenDataOffset>(data_offset),
        static_cast<uint32_t>(data_len),
        context_index, num_nl, num_sp, tok.getKind());

    // Reset so that if there is no whitespace afte the last token, then we
    // don't randomly add in trailing whitespace.
    num_nl = 0;
    num_sp = 0;

    if (at_end) {
      break;
    }
  }

  // Clear out so future streaming just re-fills.
  token_data.clear();

  // We only track spaces before a token, but there might be trailing whitespace
  // after a token that needs to get picked up by the next call to `Tokenize`,
  // so re-introduce the whitespace here.
  for (i = 0u; i < num_nl; ++i) {
    token_data.push_back('\n');
  }

  for (i = 0u; i < num_sp; ++i) {
    token_data.push_back(' ');
  }
}

void PrintedTokenRangeImpl::MarkLocation(
    size_t tok_index, const TokenImpl &tok) {
  tokens[tok_index].opaque_source_loc = tok.opaque_source_loc;
}

void PrintedTokenRangeImpl::MarkLocation(size_t tok_index,
                                         const clang::SourceLocation &loc) {
  if (!loc.isValid()) {
    return;
  }

  // Go figure it out from the AST. We need to go through a lot of indirection
  // because the source locations inside of the parsed AST relate to a huge
  // in-memory file where each post-preprocessed token is on its own line.
  if (ast) {
    if (const TokenImpl *raw_tok = ast->RawTokenAt(loc)) {
      MarkLocation(tok_index, *raw_tok);
    }

  // We don't have an `ASTImpl`, so we'll assume that `loc` is a "real" source
  // location and not our weird indirect kind.
  } else {
    tokens[tok_index].opaque_source_loc = loc.getRawEncoding();
  }
}

void TokenPrinterContext::MarkLocation(clang::SourceLocation loc) {
  Tokenize();
  if (auto num_tokens = tokens.tokens.size()) {
    tokens.MarkLocation(num_tokens - 1u, loc);
  }
}

// Mark the last printed token as having the same location as `tok`.
void TokenPrinterContext::MarkLocation(const TokenImpl &tok) {
  Tokenize();
  if (auto num_tokens = tokens.tokens.size()) {
    tokens.MarkLocation(num_tokens - 1u, tok);
  }
}

TokenPrinterContext::~TokenPrinterContext(void) {
  Tokenize();
  tokens.curr_printer_context = prev_printer_context;
  if (owns_data) {
    tokens.data_to_index.erase(owns_data);
  }
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

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<PrintedToken> PrintedTokenRange::At(size_t index) const noexcept {
  if (auto ptr = &(first[index]); ptr < after_last) {
    return PrintedToken(impl, ptr);
  } else {
    return std::nullopt;
  }
}

// Unsafe indexed access into the token range.
PrintedToken PrintedTokenRange::operator[](size_t index) const {
  return PrintedToken(impl, &(first[index]));
}

//namespace {
//
//static void Remap(
//    std::vector<TokenContextImpl> &new_contexts,
//    const std::vector<TokenContextImpl> &old_contexts,
//    std::unordered_map<const void *, TokenContextIndex> &new_data_to_index,
//    std::unordered_map<TokenContextIndex, TokenContextIndex> &index_remap) {
//
//}
//
//}  // namespace

// Create a new printed token range by concatenating two printed token ranges
// together.
std::optional<PrintedTokenRange> PrintedTokenRange::Concatenate(
    const PrintedTokenRange &a, const PrintedTokenRange &b) {
  if (!a && !b) {
    return std::nullopt;
  } else if (!a) {
    return b;
  } else if (!b) {
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
    data_to_context.emplace(new_impl->ast.get(), 0u  /* AST context index */);
  }

  std::vector<TokenContextIndex> context_map;
  context_map.assign(a.impl->contexts.size(), kInvalidTokenContextIndex);

  for (auto a_tok = a.first; a_tok < a.after_last; ++a_tok) {
    if (a_tok->Kind() == clang::tok::eof) {
      continue;
    }
    PrintedTokenImpl &new_tok = new_impl->tokens.emplace_back(*a_tok);
    new_tok.matched_in_align = false;
    new_tok.context_index = MigrateContexts(
        new_tok.context_index, a.impl->contexts, new_impl->contexts,
        data_to_context, context_map);
  }

  context_map.assign(b.impl->contexts.size(), kInvalidTokenContextIndex);

  auto a_data_size = static_cast<TokenDataOffset>(a.impl->data.size());
  for (auto b_tok = b.first; b_tok < b.after_last; ++b_tok) {
    if (b_tok->Kind() == clang::tok::eof) {
      continue;
    }

    PrintedTokenImpl &new_tok = new_impl->tokens.emplace_back(*b_tok);
    new_tok.matched_in_align = false;
    new_tok.data_offset += a_data_size;
    new_tok.context_index = MigrateContexts(
        new_tok.context_index, b.impl->contexts, new_impl->contexts,
        data_to_context, context_map);
  }

  new_impl->tokens.emplace_back(
      0u, 0u, kInvalidTokenContextIndex, 0u, 0u, clang::tok::eof);

  PrintedTokenImpl *first_tok = new_impl->tokens.data();
  PrintedTokenImpl *after_last_tok = &(first_tok[new_impl->tokens.size() - 1u]);

  return PrintedTokenRange(std::move(new_impl), first_tok, after_last_tok);
}

PrintingPolicy::~PrintingPolicy(void) {}

bool PrintingPolicy::ShouldPrintTemplate(const TemplateDecl &) const {
  return true;
}

bool PrintingPolicy::ShouldPrintTemplate(
    const ClassTemplatePartialSpecializationDecl &) const {
  return true;
}

bool PrintingPolicy::ShouldPrintTemplate(
    const VarTemplatePartialSpecializationDecl &) const {
  return true;
}

bool PrintingPolicy::ShouldPrintSpecialization(
    const ClassTemplateDecl &, const ClassTemplateSpecializationDecl &) const {
  return false;
}

bool PrintingPolicy::ShouldPrintSpecialization(const FunctionTemplateDecl &,
                                               const FunctionDecl &) const {
  return false;
}

bool PrintingPolicy::ShouldPrintSpecialization(
    const VarTemplateDecl &, const VarTemplateSpecializationDecl &) const {
  return false;
}

ProxyPrintingPolicy::~ProxyPrintingPolicy(void) {}

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

bool PrintingPolicyAdaptor::ShouldPrintTemplate(
    clang::TemplateDecl *tpl) const {

  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<TemplateDecl>(ast, tpl);
    return pp->ShouldPrintTemplate(wrapped_tpl);
  }

  if (!decl_to_print) {
    return true;
  }

  if (tpl == decl_to_print) {
    return true;
  }

  // Make sure we're not asking to print a specialization of `tpl`.
  if (auto cspec = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl_to_print)) {
    return cspec->getSpecializedTemplate()->getCanonicalDecl() != tpl->getCanonicalDecl();
  
  } else if (auto vspec = clang::dyn_cast<clang::VarTemplateSpecializationDecl>(decl_to_print)) {
    return vspec->getSpecializedTemplate()->getCanonicalDecl() != tpl->getCanonicalDecl();
  
  } else if (auto fspec = clang::dyn_cast<clang::FunctionDecl>(decl_to_print)) {
    if (fspec->isTemplateInstantiation()) {
      return fspec->getPrimaryTemplate()->getCanonicalDecl() != tpl->getCanonicalDecl();
    }
  }

  return true;
}

bool PrintingPolicyAdaptor::ShouldPrintTemplate(
    clang::ClassTemplatePartialSpecializationDecl *tpl) const {

  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<ClassTemplatePartialSpecializationDecl>(ast, tpl);
    return pp->ShouldPrintTemplate(wrapped_tpl);
  }

  if (!decl_to_print) {
    return true;
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

  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<VarTemplatePartialSpecializationDecl>(ast, tpl);
    return pp->ShouldPrintTemplate(wrapped_tpl);
  }

  if (!decl_to_print) {
    return true;
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

  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<ClassTemplateDecl>(ast, tpl);
    auto wrapped_spec = DeclBuilder::Create<ClassTemplateSpecializationDecl>(ast, spec);
    return pp->ShouldPrintSpecialization(wrapped_tpl, wrapped_spec);
  }

  return spec == decl_to_print;
}

bool PrintingPolicyAdaptor::ShouldPrintSpecialization(
    clang::VarTemplateDecl *tpl,
    clang::VarTemplateSpecializationDecl *spec) const {

  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<VarTemplateDecl>(ast, tpl);
    auto wrapped_spec = DeclBuilder::Create<VarTemplateSpecializationDecl>(ast, spec);
    return pp->ShouldPrintSpecialization(wrapped_tpl, wrapped_spec);
  }

  return spec == decl_to_print;
}

bool PrintingPolicyAdaptor::ShouldPrintSpecialization(
    clang::FunctionTemplateDecl *tpl, clang::FunctionDecl *spec) const {

  if (pp) {
    auto wrapped_tpl = DeclBuilder::Create<FunctionTemplateDecl>(ast, tpl);
    auto wrapped_spec = DeclBuilder::Create<FunctionDecl>(ast, spec);
    return pp->ShouldPrintSpecialization(wrapped_tpl, wrapped_spec);
  }

  return spec == decl_to_print;
}

}  // namespace pasta
