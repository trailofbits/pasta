/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <pasta/AST/Printer.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/PrettyPrinter.h>
#include <clang/AST/TypeLoc.h>
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

#include <cassert>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#include "../AST.h"

namespace clang {
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class Decl;
class FunctionDecl;
class FunctionTemplateDecl;
class LangOptions;
class SourceLocation;
class SourceManager;
class Stmt;
class Type;
class TypeLoc;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;

namespace tok {
enum TokenKind : unsigned short;
}  // namespace tok
}  // namespace clang
namespace pasta {

class ASTImpl;
class raw_string_ostream;
class PrintingPolicyAdaptor;

class PrintedTokenImpl final {
 public:
  // Offset and length of this token's data. If `data_offset` is positive, then
  // the data is located in `ast->preprocessed_code`, otherwise it's located in
  // `ast->backup_code`.
  TokenDataOffset data_offset{0u};

  // The Linux kernel has some *massive* comments, e.g. comments in
  // `tools/include/uapi/linux/bpf.h`.
  uint32_t data_len{0u};

  // Index of the token context in `PrintedTokenRangeImpl::contexts`.
  //
  // If this is a `TokenImpl` in a `ASTImpl`, then this represents the index of
  // a `MacroTokenImpl` in `ASTImpl::root_macro_node.token_nodes`.
  //
  // TODO(pag): Split `PrintedTokenImpl` off into its own thing.
  TokenContextIndex context_index{kInvalidTokenContextIndex};

  // Index of a token in `ASTImpl::parsed_tokens`.
  DerivedTokenIndex derived_index{kInvalidDerivedTokenIndex};

  // Kind of this token.
  TokenKind kind{TokenKind::kUnknown};

  // NOTE(pag): Printed tokens are not just superficially used. They are
  //            critical to how PASTA maps tokens back into the AST's nodes.
  //            This mapping is enacted by `AST::AlignTokens`, and the
  //            algorithm is computationally complex, and also sketchy. Some of
  //            it relies on O(n^2) algorithms, and so to minimize `n`, we want
  //            to be able to say "we've matched this thing to something" so
  //            that we don't need to repeatedly check it.
  bool matched_in_align{false};

  inline PrintedTokenImpl(TokenDataOffset data_offset_, uint32_t data_len_,
                          TokenContextIndex context_index_,
                          TokenKind kind_)
      : data_offset(data_offset_),
        data_len(data_len_),
        context_index(context_index_),
        kind(kind_),
        matched_in_align(false) {}

  inline std::string_view Data(const PrintedTokenRangeImpl &range) const;
};

// The range of data contained in a token.
class PrintedTokenRangeImpl {
 public:

  // The AST context. This is nifty to have because generally `clang::Stmt`s
  // don't know about the context.
  //
  // NOTE(pag): If `ast` is non-null, then this is safe to use for the lifetime
  //            of this range. Otherwise, it's only safe to use during the
  //            process of printing.
  clang::ASTContext &ast_context;

  //
  // NOTE(pag): May be null if we're printing a "raw" pointer, that possibly
  //            was not produced via PASTA.
  std::shared_ptr<ASTImpl> ast;

  std::vector<PrintedTokenImpl> tokens;

  // The `data_offset` of the `TokenImpl` base of `PrintedTokenImpl` in `tokens`
  // points into this string.
  std::string data;

  // All allocated token contexts live here. The `TokenImpl::context_index` of
  // a `PrintedTokenImpl` points into `contexts`.
  //
  // NOTE(pag): The first context in this list holds a raw data pointer to the
  //            `ASTImpl` containing `contexts` (if this is derived from an AST).
  //            This is so that we can get the `Decl`s, `Stmt`s, and `Type`s
  //            referenced by a token context. This is safe because a
  //            `TokenContext` has a shared pointer to a vector of contexts
  //            (this vector), where that shared pointer aliases the `ASTImpl`s
  //            lifetime.
  std::vector<TokenContextImpl> contexts;

  // Maps something, e.g. a `clang::Decl *`, `clang::Stmt *`, `clang::Type *`,
  // etc. to the "owning" context for that thing. There can be multiple open
  // contexts for a given thing; the first one is always the owning one, and
  // the rest are aliasing ones.
  std::unordered_map<const void *, TokenContextIndex> data_to_index;

  // Maps types to type locations.
  std::unordered_map<const clang::Type *, clang::TypeLoc> type_to_type_loc;

  // The current top of the token printer context stack. The structure of the
  // token printing context stack is induced via the call stack, which happens
  // when we recursively print different AST entities.
  TokenPrinterContext *curr_printer_context{nullptr};

  // Adapts a printing policy, taken from the user, or applies a "default"
  // policy. The policy focuses primarily on how to handle templates and their
  // specializations/instantiations.
  PrintingPolicyAdaptor *ppa{nullptr};

  // Should whitespace be injected?
  bool inject_whitespace{false};

  inline PrintedTokenRangeImpl(clang::ASTContext &ast_context_)
      : ast_context(ast_context_) {}

  inline PrintedTokenRangeImpl(const PrintedTokenRangeImpl &that)
      : ast_context(that.ast_context),
        ast(that.ast),
        tokens(that.tokens),
        data(that.data),
        contexts(that.contexts) {}

  ~PrintedTokenRangeImpl(void);

  template <typename T>
  const TokenContextIndex CreateContext(
      TokenPrinterContext *tokenizer, const T *data);

  const TokenContextIndex CreateAlias(
      TokenPrinterContext *tokenizer, TokenContextIndex aliasee);

  template <typename ...Kinds>
  bool LastTokenIsOneOf(Kinds... kinds);

  void TryChangeLastKind(TokenKind old, TokenKind new_);
  void TryRemoveTrailingComma(void);

  void MarkLocation(PrintedTokenImpl &, DerivedTokenIndex tok_index);
  void MarkLocation(size_t tok_index, DerivedTokenIndex tok);
  void MarkLocation(size_t tok_index, const clang::SourceLocation &loc);

  // Try to align parsed tokens with printed tokens. See `AlignTokens.cpp`.
  std::optional<std::string> AlignTokens(
      PrintedTokenRangeImpl &printed_range,
      TokenContextIndex decl_context_id,
      bool recovery_mode);

  // If any token context index is invalid, then set it to `index`.
  void FixupInvalidTokenContexts(TokenContextIndex index);

  void AddTrailingEOF(void);

  // Append a decl into the range.
  void Append(clang::Decl *decl, raw_string_ostream &out,
              const PrintingPolicy &high_pp);

  inline static PrintedTokenRange ToPrintedTokenRange(
      std::shared_ptr<PrintedTokenRangeImpl> self) {
    PrintedTokenImpl *first_tok = self->tokens.data();
    PrintedTokenImpl *after_last_tok = &(first_tok[self->tokens.size() - 1u]);
    return PrintedTokenRange(std::move(self), first_tok, after_last_tok);
  }
};

std::string_view PrintedTokenImpl::Data(
    const PrintedTokenRangeImpl &range) const {
  std::string_view data(range.data);
  return data.substr(data_offset, data_len);
}

class PrintingPolicyAdaptor final {
 private:
  std::shared_ptr<ASTImpl> ast;
  const PrintingPolicy *pp{nullptr};
  clang::Decl *decl_to_print{nullptr};

 public:
  inline PrintingPolicyAdaptor(clang::Decl *decl_to_print_=nullptr)
      : decl_to_print(decl_to_print_) {}

  inline PrintingPolicyAdaptor(const std::shared_ptr<ASTImpl> &ast_,
                               const PrintingPolicy &pp_,
                               clang::Decl *decl_to_print_=nullptr)
      : ast(ast_),
        pp(&pp_),
        decl_to_print(decl_to_print_) {}

  bool ShouldPrintInheritedAttributes(void) const;
  bool ShouldPrintImplicitAttributes(void) const;

  bool ShouldPrintConstantExpressionsInTypes(void) const;
  bool ShouldPrintOriginalTypeOfAdjustedType(void) const;
  bool ShouldPrintOriginalTypeOfDecayedType(void) const;

  bool ShouldPrintTemplate(clang::TemplateDecl *) const;

  bool ShouldPrintTemplate(
      clang::ClassTemplatePartialSpecializationDecl *) const;

  bool ShouldPrintTemplate(
      clang::VarTemplatePartialSpecializationDecl *) const;
  
  bool ShouldPrintSpecialization(
      clang::ClassTemplateDecl *,
      clang::ClassTemplateSpecializationDecl *) const;
  
  bool ShouldPrintSpecialization(
      clang::VarTemplateDecl *,
      clang::VarTemplateSpecializationDecl *) const;
  
  bool ShouldPrintSpecialization(clang::FunctionTemplateDecl *,
                                 clang::FunctionDecl *) const;

  bool ShouldPrintDeducedTypes(void) const;
};

/// A utility class that uses RAII to save and restore the value of a variable.
template<typename T>
struct SaveAndRestore {
  SaveAndRestore(T &X)
      : X(X),
        OldValue(X) {}

  SaveAndRestore(T &X, const T &NewValue)
      : X(X),
        OldValue(X) {
    X = NewValue;
  }
  ~SaveAndRestore() {
    X = OldValue;
  }
  T get() {
    return OldValue;
  }

 private:
  T &X;
  T OldValue;
};

class PrintingPolicyAdaptorRAII {
 private:
  PrintingPolicyAdaptor *&ppa_ptr;

 public:

  inline PrintingPolicyAdaptorRAII(PrintedTokenRangeImpl &range,
                                   PrintingPolicyAdaptor &ppa)
      : ppa_ptr(range.ppa) {
    ppa_ptr = &ppa;
  }

  inline ~PrintingPolicyAdaptorRAII(void) {
    ppa_ptr = nullptr;
  }
};

class PrintHelper final : public clang::PrinterHelper {
  raw_string_ostream &OS;
  clang::PrintingPolicy policy;
  PrintedTokenRangeImpl &tokens;

 public:
  virtual ~PrintHelper(void);

  inline explicit PrintHelper(raw_string_ostream &OS_,
                              const clang::PrintingPolicy &policy_,
                              PrintedTokenRangeImpl &tokens_)
      : OS(OS_),
        policy(policy_),
        tokens(tokens_) {}

  bool handledStmt(clang::Stmt *E, clang::raw_ostream &OS) final;
  bool handleType(const clang::QualType &, clang::raw_ostream &OS) final;
};

struct no_alias_tag {};

// Context class for tokenizing what's inside of a particular stream.
class TokenPrinterContext {
 public:
  template <typename T>
  inline TokenPrinterContext(
      raw_string_ostream &out_, const T *data_,
      PrintedTokenRangeImpl &tokens_)
      : out(out_),
        prev_printer_context(tokens_.curr_printer_context),
        context_index(tokens_.CreateContext<T>(this, data_)),
        tokens(tokens_) {
    if (prev_printer_context) {
      prev_printer_context->Tokenize();
    }
    tokens.curr_printer_context = this;
  }
  TokenPrinterContext(const TokenPrinterContext &that_, no_alias_tag);
  TokenPrinterContext(const TokenPrinterContext &that_);

  void Tokenize(void);
  void TokenizeAs(pasta::TokenKind kind);

  // Mark the last printed token as having location `loc`. This helps to
  // correlate things in the actual parsed tokens with printed tokens.
  template <typename ...Kinds>
  bool MarkLocationIfOneOf(clang::SourceLocation loc, Kinds... kinds) {
    if (!tokens.ast) {
      return false;
    }

    auto tok = tokens.ast->ParsedTokenOffset(loc);
    if (!tok) {
      return false;
    }

    return MarkLocationIfOneOf<Kinds...>(tok.value(), kinds...);
  }

  // Mark the last printed token as having location `loc`. This helps to
  // correlate things in the actual parsed tokens with printed tokens.
  template <typename ...Kinds>
  bool MarkLocationIfOneOf(DerivedTokenIndex offset, Kinds... kinds) {
    auto kind = tokens.ast->TokenKind(offset);
    if ((false || ... || (kind == kinds))) {
      MarkLocation(offset);
      return true;
    }
    return false;
  }

  // Mark the last printed token as having location `loc`. This helps to
  // correlate things in the actual parsed tokens with printed tokens.
  void MarkLocation(clang::SourceLocation loc);

  // Mark the last printed token as having the same location as `tok`.
  void MarkLocation(DerivedTokenIndex tok);

  ~TokenPrinterContext(void);

  pasta::raw_string_ostream &out;
  TokenPrinterContext * const prev_printer_context;
  const TokenContextIndex context_index;
  PrintedTokenRangeImpl &tokens;
  const void *owns_data{nullptr};
};

#ifndef NDEBUG
__attribute__((noinline))
extern "C" void CheckNotOnStack(const void *higher, const void *lower);
#endif

template <typename T>
const TokenContextIndex PrintedTokenRangeImpl::CreateContext(
    TokenPrinterContext *tokenizer, const T *data) {

#ifndef NDEBUG
  // Make sure we're not referencing a local variable.
  auto local_var = 1;
  asm volatile (""::"m"(local_var):"memory");
  CheckNotOnStack(data, &local_var);
  asm volatile (""::"m"(local_var):"memory");
#endif

  if (!data) {
    if (tokenizer->prev_printer_context) {
      return tokenizer->prev_printer_context->context_index;
    }
    return kInvalidTokenContextIndex;
  }

  // Reuse the prior context.
  if (tokenizer->prev_printer_context) {
    TokenPrinterContext *prev_printer = tokenizer->prev_printer_context;
    TokenContextIndex prev_index = prev_printer->context_index;
    TokenContextImpl &prev_context = contexts[prev_index];
    if (prev_context.data == data) {
      return prev_index;
    }
  }

  auto dedup = !std::is_same_v<T, char> && !std::is_base_of_v<clang::Type, T>;
  
  // If our parent context is a type, or points to a type, or isn't itself
  // subject to deduplication, then don't deduplicate this one. See
  // Issue #54 (https://github.com/trailofbits/pasta/issues/54).
  if (dedup && tokenizer->prev_printer_context) {
    auto parent_index = tokenizer->prev_printer_context->context_index;
    switch (contexts[parent_index].kind) {
      case TokenContextKind::kString:
      case TokenContextKind::kType:
      case TokenContextKind::kTemplateArgument:
      case TokenContextKind::kTemplateParameterList:
        dedup = false;
        break;
      default:
        if (!data_to_index.count(contexts[parent_index].data)) {
          dedup = false;
        }
        break;
    }
  }

  if (dedup) {
    data = Canonicalize(data);
    if (auto it = data_to_index.find(data); it != data_to_index.end()) {
      return it->second;
    }
  }

  auto index = static_cast<TokenContextIndex>(contexts.size());
  assert(index == contexts.size());

  if (tokenizer->prev_printer_context &&
      tokenizer->prev_printer_context->context_index !=
          kInvalidTokenContextIndex) {
    auto parent_index = tokenizer->prev_printer_context->context_index;
    auto parent_depth = contexts[parent_index].depth;
    contexts.emplace_back(
        parent_index,
        parent_depth,
        data);
  } else {
    contexts.emplace_back(
        kInvalidTokenContextIndex,
        static_cast<uint16_t>(0),
        data);
  }

  tokenizer->owns_data = data;
  if (dedup) {
    data_to_index.emplace(data, index);

    // We want AlignTokens to be able to observe the original decl, if the root
    // decl that we're printing isn't the canonical decl.
    if constexpr (std::is_same_v<T, clang::Decl>) {
      for (clang::Decl *redecl : data->redecls()) {
        data_to_index.emplace(redecl, index);
      }
    }
  }

  return index;
}

template <typename ...Kinds>
bool PrintedTokenRangeImpl::LastTokenIsOneOf(Kinds... kinds) {
  curr_printer_context->Tokenize();
  for (auto size = tokens.size(); size; --size) {
    if (tokens[size - 1u].kind == TokenKind::kUnknown) {
      continue;  // Skip whitespace.
    }
    auto kind = tokens[size - 1u].kind;
    if ((false || ... || (kind == kinds))) {
      return true;
    }
    break;
  }
  return false;
}

class TagDefinitionPolicyRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

 public:
  explicit TagDefinitionPolicyRAII(clang::PrintingPolicy &Policy,
                                   bool new_val=false)
      : Policy(Policy),
        Old(Policy.IncludeTagDefinition) {
    Policy.IncludeTagDefinition = new_val;
  }

  ~TagDefinitionPolicyRAII() {
    Policy.IncludeTagDefinition = Old;
  }
};

/// RAII object that enables printing of the ARC __strong lifetime
/// qualifier.
class IncludeStrongLifetimeRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

 public:
  explicit IncludeStrongLifetimeRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy),
        Old(Policy.SuppressStrongLifetime) {
    if (!Policy.SuppressLifetimeQualifiers)
      Policy.SuppressStrongLifetime = false;
  }

  ~IncludeStrongLifetimeRAII() {
    Policy.SuppressStrongLifetime = Old;
  }
};

class ParamPolicyRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

 public:
  explicit ParamPolicyRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy),
        Old(Policy.SuppressSpecifiers) {
    Policy.SuppressSpecifiers = false;
  }

  ~ParamPolicyRAII() {
    Policy.SuppressSpecifiers = Old;
  }
};

class DefaultTemplateArgsPolicyRAII {
  clang::PrintingPolicy &Policy;
  bool Old;

 public:
  explicit DefaultTemplateArgsPolicyRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy), Old(Policy.SuppressDefaultTemplateArgs) {
    Policy.SuppressDefaultTemplateArgs = false;
  }

  ~DefaultTemplateArgsPolicyRAII() {
    Policy.SuppressDefaultTemplateArgs = Old;
  }
};

class ElaboratedTypePolicyRAII {
  clang::PrintingPolicy &Policy;
  bool SuppressTagKeyword;
  bool SuppressScope;

 public:
  explicit ElaboratedTypePolicyRAII(clang::PrintingPolicy &Policy)
      : Policy(Policy) {
    SuppressTagKeyword = Policy.SuppressTagKeyword;
    SuppressScope = Policy.SuppressScope;
    Policy.SuppressTagKeyword = true;
    Policy.SuppressScope = true;
  }

  ~ElaboratedTypePolicyRAII() {
    Policy.SuppressTagKeyword = SuppressTagKeyword;
    Policy.SuppressScope = SuppressScope;
  }
};

}  // namespace pasta
