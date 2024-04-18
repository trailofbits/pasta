/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include "Macro.h"

#include <cassert>
#include <functional>
#include <map>
#include <queue>
#include <string_view>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTContext.h>
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/TokenKinds.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Lexer.h>
#include <clang/Lex/MacroInfo.h>
#include <clang/Lex/Token.h>
#pragma GCC diagnostic pop

// NOTE(pag): `include/pasta/Stmt.h` has a method called `D` on an OMP class.
#if 0
#include <pasta/Util/File.h>
#include <iostream>
#define DD(...) __VA_ARGS__
#else
#define DD(...)
#endif

#include "AST.h"
#include "Token.h"

namespace pasta {
namespace {

static MacroTokenImpl *FirstUseTokenImpl(const std::vector<Node> &nodes) {
  if (nodes.empty()) {
    return nullptr;
  }

  for (const Node &node : nodes) {
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      return std::get<MacroTokenImpl *>(node);
    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
      MacroNodeImpl *sub_node = std::get<MacroNodeImpl *>(node);
      if (auto ret = sub_node->FirstUseToken()) {
        return ret;
      }
    }
  }

  return nullptr;
}

static MacroTokenImpl *FirstExpansionTokenImpl(const std::vector<Node> &nodes) {
  if (nodes.empty()) {
    return nullptr;
  }

  for (const Node &node : nodes) {
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      return std::get<MacroTokenImpl *>(node);
    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
      MacroNodeImpl *sub_node = std::get<MacroNodeImpl *>(node);
      if (auto ret = sub_node->FirstExpansionToken()) {
        return ret;
      }
    }
  }

  return nullptr;
}


static const Node *FirstTokenImpl(const std::vector<Node> &nodes) {
  if (nodes.empty()) {
    return nullptr;
  }

  for (const Node &node : nodes) {
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      return &node;

    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
      MacroNodeImpl *sub_node = std::get<MacroNodeImpl *>(node);
      if (auto ret = sub_node->FirstToken()) {
        return ret;
      }
    }
  }

  return nullptr;
}

static const Node *LastTokenImpl(const Node &node) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return &node;

  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    MacroNodeImpl *sub_node = std::get<MacroNodeImpl *>(node);
    if (auto ret = sub_node->LastToken()) {
      return ret;
    }
  }

  return nullptr;
}

static const Node *LastTokenImpl(const std::vector<Node> &nodes) {
  if (nodes.empty()) {
    return nullptr;
  }

  for (auto it = nodes.rbegin(), end = nodes.rend(); it != end; ++it) {
    if (auto node = LastTokenImpl(*it)) {
      return node;
    }
  }

  return nullptr;
}

}  // namespace

// Clone this token into the AST.
MacroTokenImpl *MacroTokenImpl::Clone(ASTImpl &ast,
                                      MacroNodeImpl *new_parent) const {
  auto clone_offset = static_cast<DerivedTokenIndex>(
      ast.root_macro_node.tokens.size());

  MacroTokenImpl *clone = &(ast.root_macro_node.tokens.emplace_back());
  clone->token_offset = ast.macro_tokens.CloneMacroToken(
      token_offset, clone_offset);
  clone->parent = new_parent;
  clone->kind = kind;
  clone->is_ignored_comma = is_ignored_comma;
  return clone;
}

MacroNodeImpl *MacroDirectiveImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroDirectiveImpl *clone = &(ast.root_macro_node.directives.emplace_back());
  clone->parsed_left_corner = ast.parsed_tokens.size();
  clone->cloned_from = this;
  clone->defined_macro = defined_macro;
  clone->included_file = included_file;
  clone->kind = kind;
  clone->is_skipped = is_skipped;
  clone->parent = new_parent;

  CloneNodeList(
      ast, this, nodes, clone, clone->nodes,
      [=] (unsigned i, MacroTokenImpl *tok, MacroTokenImpl *cloned_tok) {
        if (std::holds_alternative<MacroTokenImpl *>(directive_name) &&
            std::get<MacroTokenImpl *>(directive_name) == tok) {
          clone->directive_name = cloned_tok;
        }

        if (std::holds_alternative<MacroTokenImpl *>(macro_name) &&
            std::get<MacroTokenImpl *>(macro_name) == tok) {
          clone->macro_name = cloned_tok;
        }
      },
      NoOnNodeCB);

  clone->parsed_right_corner = ast.parsed_tokens.size();

  return clone;
}

MacroNodeImpl *MacroArgumentImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  assert(!has_been_cloned);
  has_been_cloned = true;

  MacroArgumentImpl *clone = &(ast.root_macro_node.arguments.emplace_back());
  clone->parsed_left_corner = ast.parsed_tokens.size();
  clone->cloned_from = this;
  if (auto expansion = dynamic_cast<MacroExpansionImpl *>(new_parent)) {
    clone->index = static_cast<unsigned>(expansion->arguments.size());
    clone->offset = static_cast<unsigned>(expansion->nodes.size());
    clone->is_prearg_expansion = expansion->is_prearg_expansion;
    expansion->arguments.emplace_back(clone);
  } else {
    assert(false);
    clone->index = index;
    clone->offset = offset;
    clone->is_prearg_expansion = is_prearg_expansion;
  }
  clone->parent = new_parent;

  CloneNodeList(ast, this, nodes, clone, clone->nodes, NoOnTokenCB,
                NoOnNodeCB);

  clone->parsed_right_corner = ast.parsed_tokens.size();
  return clone;
}

MacroNodeImpl *MacroParameterImpl::Clone(ASTImpl &, MacroNodeImpl *) const {
  assert(false);
  return nullptr;
}

MacroNodeImpl *MacroSubstitutionImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroSubstitutionImpl *clone =
      &(ast.root_macro_node.substitutions.emplace_back());
  clone->parsed_left_corner = ast.parsed_tokens.size();

  clone->cloned_from = this;
  clone->parent = new_parent;

  CloneNodeList(ast, this, nodes, clone, clone->nodes, NoOnTokenCB, NoOnNodeCB);
  CloneNodeList(ast, this, use_nodes, clone, clone->use_nodes, NoOnTokenCB,
                NoOnNodeCB);

  clone->parsed_right_corner = ast.parsed_tokens.size();
  return clone;
}

MacroNodeImpl *MacroParameterSubstitutionImpl::Clone(
    ASTImpl &, MacroNodeImpl *) const {
  abort();
  return nullptr;
}

MacroNodeImpl *MacroVAOptImpl::Clone(ASTImpl &, MacroNodeImpl *) const {
  abort();
  return nullptr;
}

MacroNodeImpl *MacroVAOptArgumentImpl::Clone(ASTImpl &, MacroNodeImpl *) const {
  abort();
  return nullptr;
}

// Copy tokens from the body of the macro that come before the token with
// location `end_loc`.
void MacroExpansionImpl::CopyFromBody(
    ASTImpl &ast, MacroNodeImpl *curr, OpaqueSourceLoc end_loc) {
  if (!definition_impl || !has_body) {
    return;
  }

  auto &amt = ast.macro_tokens;
  auto max = definition_impl->nodes.size();
  auto orig_next_body_token_to_copy = next_body_token_to_copy;

  if (const Node *last_node = LastTokenImpl(body)) {
    MacroTokenImpl *last_tok = std::get<MacroTokenImpl *>(*last_node);
    OpaqueSourceLoc last_loc
        = amt.OriginalLocation(last_tok->token_offset).getRawEncoding();

    DD( std::cerr << "Last added to body: "
                 << amt.Data(last_tok->token_offset)
                 << '\n'; )

    while (next_body_token_to_copy < max) {
      DD( std::cerr << next_body_token_to_copy << '\t'; )
      const Node &node = definition_impl->nodes[next_body_token_to_copy++];
      const Node *last_def_node = LastTokenImpl(node);
      if (!last_def_node) {
        DD( std::cerr << "Skipping:\n"; )
        continue;
      }

      MacroTokenImpl *last_def_tok = std::get<MacroTokenImpl *>(*last_def_node);
      OpaqueSourceLoc last_def_loc
          = amt.OriginalLocation(last_def_tok->token_offset).getRawEncoding();

      DD( std::cerr << "Attempting 1: "
                   << amt.Data(last_def_tok->token_offset)
                   << ' ' << last_def_loc << " ?= " << last_loc << '\n'; )

      if (last_def_loc == end_loc) {
        DD( std::cerr << "Early exit at boundary: " << last_def_loc << '\n'; )
        next_body_token_to_copy -= 1u;
        break;
      }

      if (last_loc == last_def_loc) {
        DD( std::cerr << "Aligned at 1: " << last_def_loc << '\n'; )
        break;   // Aligned to the end of the last added thing.
      }
    }
  }

  NodeList &curr_nodes = curr == this ? body : curr->nodes;

  // Now that we're aligned, start copying the missing things.
  while (next_body_token_to_copy < max) {
    DD( std::cerr << next_body_token_to_copy << '\t'; )

    const Node &node = definition_impl->nodes[next_body_token_to_copy++];
    const Node *last_def_node = LastTokenImpl(node);
    if (!last_def_node) {
      DD( std::cerr << "Injecting 1: (unknown)\n"; )
      CloneNode(ast, definition_impl, node, 0u, curr,
                curr_nodes, NoOnTokenCB, NoOnNodeCB);
      has_interesting_body = true;
      continue;
    }

    MacroTokenImpl *last_def_tok = std::get<MacroTokenImpl *>(*last_def_node);
    OpaqueSourceLoc last_def_loc
        = amt.OriginalLocation(last_def_tok->token_offset).getRawEncoding();

    DD( std::cerr << "Attempting 2: " << amt.Data(last_def_tok->token_offset)
                 << " " << last_def_loc << " ?= " << end_loc
                 << '\n'; )

    if (last_def_loc != end_loc) {
      DD( std::cerr << "Injecting 2: " << amt.Data(last_def_tok->token_offset)
                   << '\n'; )

      CloneNode(ast, definition_impl, node, 0u, curr,
                curr_nodes, NoOnTokenCB, NoOnNodeCB);
      has_interesting_body = true;
      continue;
    }

    DD( std::cerr << "Aligned at boundary: " << end_loc << '\n'; )
    break;  // Aligned.
  }

  // If a change was made, then leave off a token so that next time we
  // can align again.
  if (orig_next_body_token_to_copy < next_body_token_to_copy) {
    next_body_token_to_copy -= 1u;
  }
}

MacroNodeImpl *MacroExpansionImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroExpansionImpl *clone =
      &(ast.root_macro_node.expansions.emplace_back());
  clone->parsed_left_corner = ast.parsed_tokens.size();
  clone->cloned_from = this;
  clone->parent = new_parent;
  clone->definition = definition;
  clone->definition_impl = definition_impl;
  clone->defined_macro = defined_macro;
  if (auto new_parent_exp = dynamic_cast<MacroExpansionImpl *>(new_parent)) {
    if (parent_for_prearg) {
      clone->parent_for_prearg = new_parent_exp;
    }
  } else {
    assert(!parent_for_prearg);
  }

  clone->is_cancelled = is_cancelled;
  clone->is_prearg_expansion = is_prearg_expansion;

  CloneNodeList(ast, this, body, clone, clone->body, NoOnTokenCB,
                NoOnNodeCB);

  CloneNodeList(ast, this, nodes, clone, clone->nodes, NoOnTokenCB,
                NoOnNodeCB);

  unsigned arg_num = 0u;

  CloneNodeList(
      ast, this, use_nodes, clone, clone->use_nodes,
      [=, &arg_num] (unsigned i, MacroTokenImpl *tok,
                     MacroTokenImpl *cloned_tok) {
        if (ident == tok) {
          clone->ident = cloned_tok;
        }

        if (l_paren == tok) {
          clone->l_paren = cloned_tok;
        }

        if (r_paren == tok) {
          clone->r_paren = cloned_tok;
          clone->r_paren_index = i;
        }

        if (arg_num < arguments.size() &&
            std::holds_alternative<MacroTokenImpl *>(arguments[arg_num]) &&
            std::get<MacroTokenImpl *>(arguments[arg_num]) == tok) {
          clone->arguments.emplace_back(cloned_tok);
          ++arg_num;
        }
      },
      [=, &arg_num] (unsigned i, MacroNodeImpl *node,
          MacroNodeImpl *cloned_node) {

        if (ident == node->FirstExpansionToken()) {
          clone->ident = cloned_node->FirstExpansionToken();
        }

        if (l_paren == node->FirstExpansionToken()) {
          clone->l_paren = cloned_node->FirstExpansionToken();
        }

        if (r_paren == node->FirstExpansionToken()) {
          clone->r_paren = cloned_node->FirstExpansionToken();
          clone->r_paren_index = i;
        }

        if (arg_num < arguments.size() &&
            std::holds_alternative<MacroNodeImpl *>(arguments[arg_num]) &&
            std::get<MacroNodeImpl *>(arguments[arg_num]) == node) {
          clone->arguments.emplace_back(cloned_node);
          ++arg_num;
        }
      });

  clone->parsed_right_corner = ast.parsed_tokens.size();
  return clone;
}

MacroNodeImpl *RootMacroNode::Clone(ASTImpl &, MacroNodeImpl *) const {
  abort();
  __builtin_unreachable();
}

const Node *MacroNodeImpl::FirstToken(void) const {
  return FirstTokenImpl(nodes);
}

const Node *MacroSubstitutionImpl::FirstToken(void) const {
  if (auto tok = FirstTokenImpl(use_nodes)) {
    return tok;
  }
  return FirstTokenImpl(nodes);
}

const Node *MacroNodeImpl::LastToken(void) const {
  return LastTokenImpl(nodes);
}

const Node *MacroSubstitutionImpl::LastToken(void) const {
  if (auto tok = LastTokenImpl(use_nodes)) {
    return tok;
  }
  return LastTokenImpl(nodes);
}

MacroTokenImpl *MacroNodeImpl::FirstUseToken(void) const {
  return FirstUseTokenImpl(nodes);
}

MacroTokenImpl *MacroSubstitutionImpl::FirstUseToken(void) const {
  if (!use_nodes.empty()) {
    return FirstUseTokenImpl(use_nodes);
  }
  return FirstUseTokenImpl(nodes);  // An in-progress node.
}


MacroTokenImpl *MacroNodeImpl::FirstExpansionToken(void) const {
  return FirstExpansionTokenImpl(nodes);
}

MacroTokenImpl *MacroSubstitutionImpl::FirstExpansionToken(void) const {
  if (!nodes.empty()) {
    return FirstExpansionTokenImpl(nodes);
  }
  return FirstExpansionTokenImpl(use_nodes);
}

Macro::~Macro(void) {}

// Return the parsed token range bounded by marker tokens of the complete
// expansion range for `macro`.
TokenRange Macro::CompleteExpansionRange(const Macro &macro) {
  Node node = *reinterpret_cast<const Node *>(macro.impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return Macro::CompleteExpansionRange(macro.Parent().value());
  }

  auto begin_offset = std::get<MacroNodeImpl *>(node)->parsed_begin_index;
  assert(begin_offset != ~0u);

  auto end_offset_it = macro.ast->matching.find(begin_offset);
  if (end_offset_it == macro.ast->matching.end()) {
    assert(false);
    return TokenRange(macro.ast);
  }

  return TokenRange(
      std::shared_ptr<ParsedTokenStorage>(
          macro.ast, &(macro.ast->parsed_tokens)),
      begin_offset, end_offset_it->second + 1u);
}

// Return the parsed token range bounded by marker tokens of the complete
// expansion range for `macro`.
TokenRange Macro::ExpansionRange(const Macro &macro) {
  Node node = *reinterpret_cast<const Node *>(macro.impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    auto tok = std::get<MacroTokenImpl *>(node);
    
    // Doesn't map to a specific parsed token.
    if (macro.ast->macro_tokens.Role(tok->token_offset) !=
        TokenRole::kFinalMacroExpansionToken) {
      return TokenRange(macro.ast);
    }

    for (auto parsed_tok : Macro::ExpansionRange(macro.Parent().value())) {
      if (auto mtok = parsed_tok.MacroLocation()) {
        if (mtok->Index() == tok->token_offset) {
          return parsed_tok;
        }
      }
    }

    assert(false);
    return TokenRange(macro.ast);
  }

  auto begin_offset = std::get<MacroNodeImpl *>(node)->parsed_left_corner;
  auto end_offset = std::get<MacroNodeImpl *>(node)->parsed_right_corner;

  if (begin_offset == kInvalidDerivedTokenIndex ||
      end_offset == kInvalidDerivedTokenIndex) {
    assert(false);
    return TokenRange(macro.ast);
  }

  return TokenRange(
      std::shared_ptr<ParsedTokenStorage>(
          macro.ast, &(macro.ast->parsed_tokens)),
      begin_offset, end_offset + 1u);
}

MacroKind Macro::Kind(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return MacroKind::kToken;
  }

  if (std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::get<MacroNodeImpl *>(node)->kind;
  }

  assert(false);
  DD( std::cerr << "Bad macro kind on main file: "
                   << ast->main_source_file.Path().generic_string() << '\n'; )
  abort();
  __builtin_unreachable();
}

namespace {
static const std::string_view kKindNames[] = {
#define PASTA_IGNORE(...)
#define PASTA_DECLARE_MACRO_KIND(kind) "k" #kind ,
#define PASTA_DECLARE_DIRECTIVE_KIND(kind) "k" #kind "Directive" ,
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
}  // namespace

std::string_view Macro::KindName(void) const noexcept {
  return kKindNames[static_cast<size_t>(Kind())];
}

const void *Macro::RawMacro(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    auto ret = std::get<MacroTokenImpl *>(node);
    assert(ret != nullptr);
    return ret;
  }

  if (std::holds_alternative<MacroNodeImpl *>(node)) {
    auto ret = std::get<MacroNodeImpl *>(node);
    assert(ret != nullptr);
    return ret;
  }

  assert(false);
  DD( std::cerr << "Bad macro kind on main file: "
               << ast->main_source_file.Path().generic_string() << '\n'; )
  return nullptr;
}

// Return the macro node containing this node.
std::optional<Macro> Macro::Parent(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return Macro(ast, &(std::get<MacroTokenImpl *>(node)->parent));
  }

  if (!std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::nullopt;
  }

  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  if (!std::holds_alternative<MacroNodeImpl *>(node_impl->parent)) {
    assert(std::holds_alternative<std::monostate>(node_impl->parent));
    assert(dynamic_cast<RootMacroNode *>(node_impl));
    return std::nullopt;
  }

  MacroNodeImpl *parent_node_impl = std::get<MacroNodeImpl *>(node_impl->parent);
  if (dynamic_cast<RootMacroNode *>(parent_node_impl)) {
    return std::nullopt;
  }

  return Macro(ast, &(node_impl->parent));
}

// Children of this macro. If this is a MacroToken then this is empty.
MacroRange Macro::Children(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroNodeImpl *>(node)) {
    MacroNodeImpl *impl = std::get<MacroNodeImpl *>(node);
    MacroSubstitutionImpl *sub_impl =
        dynamic_cast<MacroSubstitutionImpl *>(impl);
    if (sub_impl) {
      const auto first = sub_impl->use_nodes.data();
      return MacroRange(ast, first, &(first[sub_impl->use_nodes.size()]));
    }

    const auto first = impl->nodes.data();
    return MacroRange(ast, first, &(first[impl->nodes.size()]));
  }
  return MacroRange(ast);
}

std::optional<MacroToken> Macro::BeginToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return reinterpret_cast<const MacroToken &>(*this);
  }

  if (std::holds_alternative<MacroNodeImpl *>(node)) {
    if (const Node *tok = std::get<MacroNodeImpl *>(node)->FirstToken()) {
      return MacroToken(ast, tok);
    }
    return std::nullopt;
  }

  assert(false);
  DD( std::cerr << "Bad macro kind on main file: "
                   << ast->main_source_file.Path().generic_string() << '\n'; )
  return std::nullopt;
}

std::optional<MacroToken> Macro::EndToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return reinterpret_cast<const MacroToken &>(*this);
  }

  if (std::holds_alternative<MacroNodeImpl *>(node)) {
    if (const Node *tok = std::get<MacroNodeImpl *>(node)->LastToken()) {
      return MacroToken(ast, tok);
    }
    return std::nullopt;
  }

  assert(false);
  DD( std::cerr << "Bad macro kind on main file: "
                   << ast->main_source_file.Path().generic_string() << '\n'; )
  return std::nullopt;
}

namespace {

inline static DerivedTokenIndex MacroTokenOffset(const void *impl) {
  Node node = *reinterpret_cast<const Node *>(impl);
  return std::get<MacroTokenImpl *>(node)->token_offset;
}

}  // namespace

enum TokenKind MacroToken::TokenKind(void) const noexcept {
  return ast->macro_tokens.Kind(MacroTokenOffset(impl));
}

enum TokenRole MacroToken::TokenRole(void) const noexcept {
  return ast->macro_tokens.Role(MacroTokenOffset(impl));
}

// Index of this token in the macro token area. Useful for uniquely
// identifying them.
unsigned MacroToken::Index(void) const noexcept {
  return static_cast<unsigned>(MacroTokenOffset(impl));
}

std::string_view MacroToken::TokenKindName(void) const noexcept {
  return clang::tok::getTokenName(
      static_cast<clang::tok::TokenKind>(TokenKind()));
}

// Return the data associated with this token.
std::string_view MacroToken::Data(void) const noexcept {
  return ast->macro_tokens.Data(MacroTokenOffset(impl));
}

// Location of the token in a file.
std::optional<FileToken> MacroToken::FileLocation(void) const noexcept {
  return Token(
      std::shared_ptr<ParsedTokenStorage>(ast, &(ast->macro_tokens)),
      MacroTokenOffset(impl)).FileLocation();
}

// Find the token from which this token was derived.
DerivedToken MacroToken::DerivedLocation(void) const {
  return Token(
      std::shared_ptr<ParsedTokenStorage>(ast, &(ast->macro_tokens)),
      MacroTokenOffset(impl)).DerivedLocation();
}

std::optional<DefineMacroDirective> MacroToken::AssociatedMacro(void) const {
  auto offset = MacroTokenOffset(impl);
  auto &macro_storage = ast->macro_tokens;
  auto it = macro_storage.macro_definition.find(offset);
  if (it == macro_storage.macro_definition.end()) {
    return std::nullopt;
  }

  return DefineMacroDirective(ast, &(it->second));
}

std::optional<MacroDirective> MacroDirective::From(const Macro &node) noexcept {
  switch (node.Kind()) {
#define PASTA_IGNORE(...)
#define PASTA_MAKE_DIRECTIVE(kind) \
    case MacroKind::k ## kind ## Directive:

PASTA_FOR_EACH_MACRO_IMPL(PASTA_IGNORE,
                          PASTA_IGNORE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_IGNORE)
#undef PASTA_IGNORE
#undef PASTA_MAKE_DIRECTIVE
      return reinterpret_cast<const MacroDirective &>(node);
    default:
      return std::nullopt;
  }
}

// Return the hash token of the directive.
MacroToken MacroDirective::Hash(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  assert(!dir_impl->nodes.empty());
  assert(std::holds_alternative<MacroTokenImpl *>(dir_impl->nodes.front()));
  return MacroToken(ast, &(dir_impl->nodes.front()));
}

// The name of this directive, if any. Some GCC-specific macros don't have
// names. Directive names are macro tokens because the name may be a result
// of some other expansion, e.g. `_Pragma("...")` expanding into
// `#pragma ...`.
std::optional<MacroToken> MacroDirective::DirectiveName(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  if (!std::holds_alternative<MacroTokenImpl *>(dir_impl->directive_name)) {
    return std::nullopt;
  }

  return MacroToken(ast, &(dir_impl->directive_name));
}

// Return the macro directive associated with a marker token.
std::optional<Macro> Macro::FromMarkerToken(const Token &tok) noexcept {
  auto &tok_ast = tok.storage->ast;
  if (tok.storage.get() != &(tok_ast->parsed_tokens)) {
    return std::nullopt;
  }

  auto it = tok_ast->marker_offset_to_macro.find(tok.offset);
  if (it == tok_ast->marker_offset_to_macro.end()) {
    return std::nullopt;
  }

  return Macro(std::shared_ptr<ASTImpl>(tok.storage, tok_ast),
               &(it->second));
}

// The location of this directive in the parsed tokens.
Token MacroDirective::ParsedLocation(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  if (dir_impl->marker_token_offset == ~0u) {
    assert(false);
    return Token(ast);
  }

  return Token(std::shared_ptr<ParsedTokenStorage>(ast, &(ast->parsed_tokens)),
               dir_impl->marker_token_offset);
}

// E.g. `...` in `args...`, or just `...`.
std::optional<MacroToken>
MacroParameter::VariadicDots(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroParameterImpl *param_impl = dynamic_cast<MacroParameterImpl *>(node_impl);
  if (param_impl->is_variadic) {
    return MacroToken(ast, &(param_impl->nodes.back()));
  }
  return std::nullopt;
}

// The name of the macro parameter, if any.
std::optional<MacroToken> MacroParameter::Name(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroParameterImpl *param_impl = dynamic_cast<MacroParameterImpl *>(node_impl);
  if (param_impl->has_name) {
    return MacroToken(ast, &(param_impl->nodes.front()));
  }
  return std::nullopt;
}

unsigned MacroParameter::Index(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroParameterImpl *param_impl = dynamic_cast<MacroParameterImpl *>(node_impl);
  return param_impl->index;
}

std::optional<DefineMacroDirective>
DefineMacroDirective::From(const Macro &node) {
  if (node.Kind() == MacroKind::kDefineDirective) {
    return reinterpret_cast<const DefineMacroDirective &>(node);
  }
  return std::nullopt;
}

std::optional<MacroToken> DefineMacroDirective::Name(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (std::holds_alternative<MacroTokenImpl *>(dir_impl->macro_name)) {
    return MacroToken(ast, &(dir_impl->macro_name));
  }
  assert(std::holds_alternative<std::monostate>(dir_impl->macro_name));
  return std::nullopt;
}

// Number of explicit, i.e. not variadic, parameters.
unsigned DefineMacroDirective::NumExplicitParameters(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (dir_impl->defined_macro) {

    // NOTE(pag): Clang includes the variadic parameter in `getNumParams()`.
    return dir_impl->defined_macro->getNumParams() - 1u;
  }
  assert(false);
  return 0u;
}

// Is this a function-like macro? If so, then it could take zero-or-more
// arguments when used.
bool DefineMacroDirective::IsFunctionLike(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (dir_impl->defined_macro) {
    return dir_impl->defined_macro->isFunctionLike();
  }
  assert(false);
  return 0u;
}

// Does this definition accept a variable number of arguments?
bool DefineMacroDirective::IsVariadic(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (dir_impl->defined_macro) {
    return dir_impl->defined_macro->isVariadic();
  }
  assert(false);
  return false;
}

// Uses of this macro.
MacroRange DefineMacroDirective::Uses(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (!dir_impl->macro_uses.empty()) {
    const auto first = dir_impl->macro_uses.data();
    return MacroRange(
        ast, first, &(first[dir_impl->macro_uses.size()]));
  }
  return MacroRange(ast);
}

// Body of the defined macro.
MacroRange DefineMacroDirective::Body(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (!dir_impl->nodes.empty()) {
    const auto first = dir_impl->nodes.data();
    const auto num_nodes = dir_impl->nodes.size();
    const auto body_offset = dir_impl->body_offset;
    if (body_offset >= num_nodes) {
      return MacroRange(ast);
    }
    return MacroRange(ast, &(first[body_offset]), &(first[num_nodes]));
  }
  return MacroRange(ast);
}

// Parameters of this macro definition.
MacroRange DefineMacroDirective::Parameters(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (!dir_impl->parameters.empty()) {
    const auto first = dir_impl->parameters.data();
    return MacroRange(
        ast, first, &(first[dir_impl->parameters.size()]));
  }
  return MacroRange(ast);
}

std::optional<IncludeLikeMacroDirective>
IncludeLikeMacroDirective::From(const Macro &node) {
  switch (node.Kind()) {
    case MacroKind::kIncludeDirective:
    case MacroKind::kIncludeNextDirective:
    case MacroKind::kIncludeMacrosDirective:
      return reinterpret_cast<const IncludeLikeMacroDirective &>(node);
    default:
      return std::nullopt;
  }
}

std::optional<ConditionalMacroDirective> ConditionalMacroDirective::From(
    const Macro &node) noexcept {
  switch (node.Kind()) {
    default: return std::nullopt;
#define PASTA_IGNORE(...)
#define PASTA_CMD_CAST(kind) case MacroKind::k ## kind ## Directive:
  PASTA_FOR_EACH_MACRO_IMPL(PASTA_IGNORE,
                            PASTA_IGNORE,
                            PASTA_IGNORE,
                            PASTA_CMD_CAST,
                            PASTA_IGNORE,
                            PASTA_IGNORE,
                            PASTA_IGNORE)
#undef PASTA_CMD_CAST
#undef PASTA_IGNORE
    return reinterpret_cast<const ConditionalMacroDirective &>(node);
  }
}

std::optional<File> IncludeLikeMacroDirective::IncludedFile(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  return dir_impl->included_file;
}

bool MacroArgument::IsVariadic(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(
      std::get<MacroNodeImpl *>(arg_impl->parent));
  if (exp_impl->defined_macro) {
    return exp_impl->defined_macro->getNumParams() <= arg_impl->index;
  }
  return false;
}

unsigned MacroArgument::Index(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  MacroNodeImpl *exp_node = std::get<MacroNodeImpl *>(arg_impl->parent);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(exp_node);
  auto i = 0u;
  for (const Node &arg_node : exp_impl->arguments) {
    if (std::get<MacroNodeImpl *>(arg_node) == node_impl) {
      return i;
    }
    ++i;
  }
  assert(false);
  return ~0u;
}

MacroRange MacroSubstitution::ReplacementChildren(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroSubstitutionImpl *sub_impl =
      dynamic_cast<MacroSubstitutionImpl *>(node_impl);
  if (!sub_impl->nodes.empty()) {
    const auto first = sub_impl->nodes.data();
    return MacroRange(
        ast, first, &(first[sub_impl->nodes.size()]));
  }
  return MacroRange(ast);
}

// Higher-order function for getting the left/right corner of a substitution
// tree. The walk parameter tells us how to traverse the current substitution's
// replacement children of tree to go left/right.
// Returns an optional Token because the top-level substitution may not expand
// to any tokens.
template <typename RangeElemT, typename RangeT>
static std::optional<MacroToken> Corner(
  const RangeT &range,
  std::function<std::optional<RangeElemT>(RangeT)> walk) {
  std::optional<RangeElemT> cur = std::nullopt;
  std::optional<RangeElemT> next = (!range.empty()
                                    ? std::optional(walk(range))
                                    : std::nullopt);
  while (next) {
    // Traverse the next begin/end token (left/right corner)
    cur = std::move(next);
    auto cur_sub = MacroSubstitution::From(*cur);
    auto next_children = (cur_sub
                          ? std::optional(cur_sub->ReplacementChildren())
                          : std::nullopt);
    next = ((next_children && !next_children->empty())
            ? std::optional(walk(*next_children))
            : std::nullopt);
  }
  const std::optional<MacroToken> macro_tok = (cur
                                               ? MacroToken::From(*cur)
                                               : std::nullopt);
  return (macro_tok ? std::optional(macro_tok) : std::nullopt);
}

// Returns the first fully substituted token in this substitution, if any.
std::optional<MacroToken>
MacroSubstitution::FirstFullySubstitutedToken(void) const noexcept {
  const auto Left = [](MacroRange range) { return *range.begin(); };
  return Corner<Macro, MacroRange>(ReplacementChildren(), Left);
}

// Returns the last fully substituted token in this substitution, if any.
std::optional<MacroToken>
MacroSubstitution::LastFullySubstitutedToken(void) const noexcept {
  const auto Right = [](MacroRange range) { return *(range.end() - 1); };
  return Corner<Macro, MacroRange>(ReplacementChildren(), Right);
}

std::optional<MacroToken> MacroSubstitution::NameOrOperator(void) const noexcept {
  auto node = *reinterpret_cast<const Node *>(impl);
  auto *node_impl = std::get<MacroNodeImpl *>(node);
  auto *sub_impl = dynamic_cast<MacroSubstitutionImpl *>(node_impl);
  if (std::holds_alternative<MacroTokenImpl *>(sub_impl->name)) {
    return MacroToken(ast, &sub_impl->name);
  }
  return std::nullopt;
}

// Walks the given Stmt's subtree and returns the first of its subtrees that
// aligns with the given macro, if any.
std::optional<pasta::Stmt>
AlignedStmtInSubtree(Macro &macro, const pasta::Stmt &stmt) noexcept {
  std::vector<pasta::Stmt> aligned_stmts;
  // Use a BFS to walk the given Stmt's AST.
  std::queue<pasta::Stmt> q;
  q.push(stmt);
  do {
    pasta::Stmt cur = q.front();
    q.pop();

    // Don't match implicit expressions
    if (cur.Kind() != StmtKind::kImplicitCastExpr &&
        cur.Kind() != StmtKind::kImplicitValueInitExpr &&
        cur.AlignsWith(macro)) {
      return cur;
    }

    for (auto &child : cur.Children()) {
      q.push(child);
    }
  } while (!q.empty());
  return std::nullopt;
}

std::vector<std::pair<MacroParameter, std::vector<pasta::Stmt>>>
MacroExpansion::AlignedParameterSubstitutions(
    const pasta::Stmt &stmt) const noexcept {
  std::vector<std::pair<MacroParameter, std::vector<pasta::Stmt>>>
      param_to_uses;
  std::map<MacroParameter, unsigned> param_to_index;
  auto def = Definition();

  if (!def) {
    return param_to_uses;
  }

  unsigned i = 0;
  for (auto macro : def->Parameters()) {
    auto param = MacroParameter::From(macro);
    assert(param);
    param_to_uses.push_back({*param, std::vector<pasta::Stmt>()});
    param_to_index[*param] = i;
    i++;
  }

  // Map each argument to the Stmts it substitutions align with
  for (auto &child : IntermediateChildren()) {
    if (auto sub = MacroParameterSubstitution::From(child)) {
      if (auto aligned_stmt = AlignedStmtInSubtree(*sub, stmt)) {
        auto i = param_to_index[sub->Parameter()];
        param_to_uses[i].second.push_back(*aligned_stmt);
      }
    }
  }

  return param_to_uses;
}

std::map<MacroParameter, unsigned>
MacroExpansion::ParameterUseCounts(void) const noexcept {
  std::map<MacroParameter, unsigned> m;

  auto def = Definition();
  if (!def) {
    return m;
  }

  for (auto macro : def->Parameters()) {
    auto param = MacroParameter::From(macro);
    assert(param);
    m[*param] = 0;
  }

  // Map each argument to the number of times it is substituted into the macro's
  // body
  for (auto &child : IntermediateChildren()) {
    if (auto sub = MacroParameterSubstitution::From(child)) {
      m[sub->Parameter()] += 1;
    }
  }

  return m;
}

MacroParameter MacroParameterSubstitution::Parameter(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroParameterSubstitutionImpl *sub_impl =
      dynamic_cast<MacroParameterSubstitutionImpl *>(node_impl);
  return MacroParameter(ast, &(sub_impl->param_in_definition));
}

MacroToken MacroParameterSubstitution::ParameterUse(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroParameterSubstitutionImpl *sub_impl =
      dynamic_cast<MacroParameterSubstitutionImpl *>(node_impl);
  return MacroToken(ast, &(sub_impl->use_nodes.front()));
}

MacroToken MacroStringify::StringifiedToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroSubstitutionImpl *sub_impl =
      dynamic_cast<MacroSubstitutionImpl *>(node_impl);
  assert(sub_impl->nodes.size() == 1u);
  assert(std::holds_alternative<MacroTokenImpl *>(sub_impl->nodes.front()));
  return MacroToken(ast, &(sub_impl->nodes.front()));
}

MacroToken MacroConcatenate::PastedToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroSubstitutionImpl *sub_impl =
      dynamic_cast<MacroSubstitutionImpl *>(node_impl);
  assert(sub_impl->nodes.size() == 1u);
  assert(std::holds_alternative<MacroTokenImpl *>(sub_impl->nodes.front()));
  return MacroToken(ast, &(sub_impl->nodes.front()));
}

// Were the contents elided? This is basically asking if there were variadic
// arguments to the macro.
bool MacroVAOpt::ContentsAreElided(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroVAOptImpl *va_impl = dynamic_cast<MacroVAOptImpl *>(node_impl);
  return va_impl->is_elided;
}

// The body of the macro, prior to expansion.
MacroRange MacroExpansion::IntermediateChildren(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);
  if (exp_impl->has_body && exp_impl->has_interesting_body &&
      !exp_impl->body.empty()) {
    const auto first = exp_impl->body.data();
    return MacroRange(ast, first, &(first[exp_impl->body.size()]));

  }

  if (exp_impl->definition_impl &&
      !exp_impl->definition_impl->nodes.empty()) {
    const auto first = exp_impl->definition_impl->nodes.data();
    const auto num_nodes = exp_impl->definition_impl->nodes.size();
    const auto body_offset = exp_impl->definition_impl->body_offset;
    if (body_offset < num_nodes) {
      return MacroRange(ast, &(first[body_offset]), &(first[num_nodes]));
    }
  }
  return MacroRange(ast);
}

MacroExpansion MacroExpansion::Containing(
    const MacroArgument &arg) noexcept {
  Node node = *reinterpret_cast<const Node *>(arg.impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  return MacroExpansion(arg.ast, &(arg_impl->parent));
}

// Returns the directive that led to the definition of this expansion.
std::optional<DefineMacroDirective> MacroExpansion::Definition(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);
  if (std::holds_alternative<MacroNodeImpl *>(exp_impl->definition)) {
    return DefineMacroDirective(ast, &(exp_impl->definition));
  }
  return std::nullopt;
}

// Returns the list of arguments in the expansion if this was a use of a
// function-like macro.
std::vector<MacroArgument>
MacroExpansion::Arguments(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);

  std::vector<MacroArgument> ret;
  for (Node &arg : exp_impl->arguments) {
    ret.emplace_back(MacroArgument(ast, &arg));
  }

  return ret;
}

// Is this the argument pre-expansion phase of this expansion?
bool MacroExpansion::IsArgumentPreExpansion(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);
  return exp_impl->is_prearg_expansion;
}

// Return the "second" (if any) version of this expansion, where the
// arguments to this macro are subjected to pre-expansion prior to
// substituting the use of the macro with its body.
std::optional<MacroExpansion>
MacroExpansion::ArgumentPreExpansion(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);

  if (exp_impl->nodes.empty()) {
    return std::nullopt;
  }

  Node &pa_node = exp_impl->nodes.front();
  if (!std::holds_alternative<MacroNodeImpl *>(pa_node)) {
    return std::nullopt;
  }

  MacroNodeImpl *pa_node_impl = std::get<MacroNodeImpl *>(pa_node);
  MacroExpansionImpl *pa_exp_impl =
      dynamic_cast<MacroExpansionImpl *>(pa_node_impl);

  if (!pa_exp_impl || pa_exp_impl->parent_for_prearg != exp_impl) {
    return std::nullopt;
  }

  return MacroExpansion(ast, &pa_node);
}

// Prefix increment operator.
MacroIterator &MacroIterator::operator++(void) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) + 1;
  return *this;
}

// Postfix increment operator.
MacroIterator MacroIterator::operator++(int) noexcept {
  auto ret = *this;
  node.impl = reinterpret_cast<const Node *>(node.impl) + 1;
  return ret;
}

// Prefix decrement operator.
MacroIterator &MacroIterator::operator--(void) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) - 1;
  return *this;
}

// Postfix decrement operator.
MacroIterator MacroIterator::operator--(int) noexcept {
  auto ret = *this;
  node.impl = reinterpret_cast<const Node *>(node.impl) - 1;
  return ret;
}

MacroIterator MacroIterator::operator-(size_t offset) const noexcept {
  return MacroIterator(
      node.ast, reinterpret_cast<const Node *>(node.impl) - offset);
}

MacroIterator &MacroIterator::operator+=(size_t offset) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) + offset;
  return *this;
}

MacroIterator &MacroIterator::operator-=(size_t offset) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) - offset;
  return *this;
}

Macro MacroIterator::operator[](size_t offset) const noexcept {
  auto begin = reinterpret_cast<const Node *>(node.impl);
  return Macro(node.ast, &(begin[offset]));
}

ptrdiff_t MacroIterator::operator-(const MacroIterator &that) const noexcept {
  return reinterpret_cast<const Node *>(node.impl) -
         reinterpret_cast<const Node *>(that.node.impl);
}

size_t MacroRange::Size(void) const noexcept {
  return static_cast<size_t>(reinterpret_cast<const Node *>(after_last) -
                             reinterpret_cast<const Node *>(first));
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<Macro> MacroRange::At(size_t index) const noexcept {
  auto begin = reinterpret_cast<const Node *>(first);
  auto end = reinterpret_cast<const Node *>(after_last);
  if (auto it = &(begin[index]); it < end) {
    return Macro(ast, it);
  }
  return std::nullopt;
}

// Unsafe indexed access into the token range.
Macro MacroRange::operator[](size_t index) const {
  auto begin = reinterpret_cast<const Node *>(first);
  return Macro(ast, &(begin[index]));
}

}  // namespace pasta
