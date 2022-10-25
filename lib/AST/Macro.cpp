/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include "Macro.h"

#include <cassert>

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

}  // namespace

// Clone this token into the AST.
MacroTokenImpl *MacroTokenImpl::Clone(ASTImpl &ast,
                                      MacroNodeImpl *new_parent) const {
  TokenImpl ast_tok = ast.tokens[token_offset];
  size_t new_offset = ast.tokens.size();
  ast.tokens.emplace_back(std::move(ast_tok));

  MacroTokenImpl *clone = &(ast.root_macro_node.tokens.emplace_back());
  clone->token_offset = static_cast<uint32_t>(new_offset);
  assert(clone->token_offset == new_offset);
  clone->parent = new_parent;
  clone->kind_flags.kind = kind_flags.kind;
  clone->kind_flags.is_ignored_comma = kind_flags.is_ignored_comma;

  ast.preprocessed_code.push_back('\n');
  ast.num_lines += 1u;
  return clone;
}

MacroNodeKind MacroDirectiveImpl::Kind(void) const {
  if (defined_macro) {
    return MacroNodeKind::kDefine;
  } else if (included_file) {
    return MacroNodeKind::kInclude;
  } else {
    return MacroNodeKind::kDirective;
  }
}

namespace {

static void NoOnTokenCB(unsigned, MacroTokenImpl *, MacroTokenImpl *) {}
static void NoOnNodeCB(unsigned, MacroNodeImpl *, MacroNodeImpl *) {}

template <typename TokenCB, typename NodeCB>
static void CloneNodeList(ASTImpl &ast,
                          const MacroNodeImpl *old_parent,
                          const std::vector<Node> &old_nodes,
                          MacroNodeImpl *new_parent,
                          std::vector<Node> &new_nodes,
                          TokenCB on_token,
                          NodeCB on_node) {
  auto i = 0u;
  for (const Node &node : old_nodes) {
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
      assert(std::holds_alternative<MacroNodeImpl *>(tok->parent));
      assert(std::get<MacroNodeImpl *>(tok->parent) == old_parent);
      MacroTokenImpl *cloned_tok = tok->Clone(ast, new_parent);
      assert(tok->token_offset < cloned_tok->token_offset);
      new_nodes.emplace_back(cloned_tok);

      on_token(i, tok, cloned_tok);

    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
      MacroNodeImpl *sub_node = std::get<MacroNodeImpl *>(node);
      assert(std::holds_alternative<MacroNodeImpl *>(sub_node->parent));
      assert(std::get<MacroNodeImpl *>(sub_node->parent) == old_parent);
      auto cloned_node = sub_node->Clone(ast, new_parent);
      new_nodes.emplace_back(cloned_node);

      on_node(i, sub_node, cloned_node);
    }
    ++i;
  }
}

}  // namespace

MacroNodeImpl *MacroDirectiveImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroDirectiveImpl *clone = &(ast.root_macro_node.directives.emplace_back());
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

  return clone;
}

MacroNodeImpl *MacroArgumentImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroArgumentImpl *clone = &(ast.root_macro_node.arguments.emplace_back());
  clone->cloned_from = this;
  if (auto expansion = dynamic_cast<MacroExpansionImpl *>(new_parent)) {
    clone->index = static_cast<unsigned>(expansion->arguments.size());
    clone->is_prearg_expansion = expansion->is_prearg_expansion;
  } else {
    assert(false);
    clone->index = index;
    clone->is_prearg_expansion = is_prearg_expansion;
  }
  clone->parent = new_parent;

  CloneNodeList(ast, this, nodes, clone, clone->nodes, NoOnTokenCB,
                NoOnNodeCB);

  return clone;
}

MacroNodeImpl *MacroSubstitutionImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroSubstitutionImpl *clone =
      &(ast.root_macro_node.substitutions.emplace_back());
  clone->cloned_from = this;
  clone->parent = new_parent;

  CloneNodeList(ast, this, nodes, clone, clone->nodes, NoOnTokenCB, NoOnNodeCB);
  CloneNodeList(ast, this, use_nodes, clone, clone->use_nodes, NoOnTokenCB,
                NoOnNodeCB);

  return clone;
}

MacroNodeImpl *MacroExpansionImpl::Clone(
    ASTImpl &ast, MacroNodeImpl *new_parent) const {

  MacroExpansionImpl *clone =
      &(ast.root_macro_node.expansions.emplace_back());
  clone->cloned_from = this;
  clone->parent = new_parent;
  clone->definition = definition;
  clone->defined_macro = defined_macro;
  if (auto new_parent_exp = dynamic_cast<MacroExpansionImpl *>(new_parent)) {
    if (parent_for_prearg) {
      clone->parent_for_prearg = new_parent_exp;
    }
  } else {
    assert(!parent_for_prearg);
  }

  clone->is_cancelled = is_cancelled;
  clone->in_prearg_expansion = in_prearg_expansion;
  clone->is_prearg_expansion = is_prearg_expansion;

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

  return clone;
}

MacroNodeImpl *RootMacroNode::Clone(ASTImpl &, MacroNodeImpl *) const {
  abort();
  __builtin_unreachable();
}

MacroTokenImpl *MacroNodeImpl::FirstUseToken(void) const {
  return FirstUseTokenImpl(nodes);
}

MacroTokenImpl *MacroSubstitutionImpl::FirstUseToken(void) const {
  if (!use_nodes.empty()) {
    return FirstUseTokenImpl(use_nodes);
  } else {
    return FirstUseTokenImpl(nodes);  // An in-progress node.
  }
}


MacroTokenImpl *MacroNodeImpl::FirstExpansionToken(void) const {
  return FirstExpansionTokenImpl(nodes);
}

MacroTokenImpl *MacroSubstitutionImpl::FirstExpansionToken(void) const {
  if (!nodes.empty()) {
    return FirstExpansionTokenImpl(nodes);
  } else {
    return FirstExpansionTokenImpl(use_nodes);
  }
}

MacroNodeKind MacroSubstitutionImpl::Kind(void) const {
  return MacroNodeKind::kSubstitution;
}

MacroNodeKind MacroExpansionImpl::Kind(void) const {
  return MacroNodeKind::kExpansion;
}

MacroNodeKind MacroArgumentImpl::Kind(void) const {
  return MacroNodeKind::kArgument;
}

MacroNodeKind RootMacroNode::Kind(void) const {
  abort();
  __builtin_unreachable();
}

MacroNode::~MacroNode(void) {}

MacroNodeKind MacroNode::Kind(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return MacroNodeKind::kToken;
  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::get<MacroNodeImpl *>(node)->Kind();
  } else {
    assert(false);
    return MacroNodeKind::kInvalid;
  }
}

const void *MacroNode::RawNode(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return &(ast->tokens[std::get<MacroTokenImpl *>(node)->token_offset]);
  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    auto ret = std::get<MacroNodeImpl *>(node);
    assert(ret != nullptr);
    return ret;
  } else {
    return nullptr;
  }
}

// Return the macro node containing this node.
std::optional<MacroNode> MacroNode::Parent(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return MacroNode(ast, &(std::get<MacroTokenImpl *>(node)->parent));
  }

  if (!std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::nullopt;
  }

  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  if (!std::holds_alternative<MacroNodeImpl *>(node_impl->parent)) {
    return std::nullopt;
  }

  MacroNodeImpl *parent_node_impl = std::get<MacroNodeImpl *>(node_impl->parent);
  if (dynamic_cast<RootMacroNode *>(parent_node_impl)) {
    return std::nullopt;
  }

  return MacroNode(ast, &(node_impl->parent));
}

enum TokenKind MacroToken::TokenKind(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  TokenImpl &token =
      ast->tokens[std::get<MacroTokenImpl *>(node)->token_offset];
  return static_cast<enum TokenKind>(token.Kind());
}

std::string_view MacroToken::TokenKindName(void) const noexcept {
  return clang::tok::getTokenName(
      static_cast<clang::tok::TokenKind>(TokenKind()));
}

// Return the data associated with this token.
std::string_view MacroToken::Data(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  TokenImpl &token =
      ast->tokens[std::get<MacroTokenImpl *>(node)->token_offset];
  return token.Data(*ast);
}

// Location of the token in a file.
std::optional<FileToken> MacroToken::FileLocation(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  clang::SourceLocation loc =
      ast->tokens[std::get<MacroTokenImpl *>(node)->token_offset].Location();
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

// Location of the token as parsed.
std::optional<Token> MacroToken::ParsedLocation(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  const TokenImpl &tok =
      ast->tokens[std::get<MacroTokenImpl *>(node)->token_offset];
  if (tok.HasMacroRole()) {
    return Token(ast, &tok);
  } else {
    return std::nullopt;
  }
}

// Return the hash token of the directive.
MacroToken MacroDirective::HashToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  assert(!dir_impl->nodes.empty());
  assert(std::holds_alternative<MacroTokenImpl *>(dir_impl->nodes.front()));
  return MacroToken(ast, &(dir_impl->nodes.front()));
}

// Return the kind of this directive.
MacroDirectiveKind MacroDirective::DirectiveKind(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  return dir_impl->kind;
}

// The name of this directive, if any. Some GCC-specific macros don't have
// names. Directive names are macro tokens because the name may be a result
// of some other expansion, e.g. `_Pragma("...")` expanding into
// `#pragma ...`.
std::optional<MacroToken> MacroDirective::DirectiveToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  if (!std::holds_alternative<MacroTokenImpl *>(dir_impl->directive_name)) {
    return std::nullopt;
  }

  return MacroToken(ast, &(dir_impl->directive_name));
}

MacroNodeRange MacroDirective::Nodes(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (!dir_impl->nodes.empty()) {
    const auto first = dir_impl->nodes.data();
    return MacroNodeRange(
        ast, first, &(first[dir_impl->nodes.size()]));
  } else {
    return MacroNodeRange(ast);
  }
}

MacroToken MacroDefinition::NameToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  assert(std::holds_alternative<MacroTokenImpl *>(dir_impl->macro_name));
  return MacroToken(ast, &(dir_impl->macro_name));
}

// Number of explicit, i.e. not variadic, parameters.
unsigned MacroDefinition::NumExplicitParameters(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (dir_impl->defined_macro) {
    return dir_impl->defined_macro->getNumParams();
  } else {
    assert(false);
    return 0u;
  }
}

// Is this a function-like macro? If so, then it could take zero-or-more
// arguments when used.
bool MacroDefinition::IsFunctionLike(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (dir_impl->defined_macro) {
    return dir_impl->defined_macro->isFunctionLike();
  } else {
    assert(false);
    return 0u;
  }
}

// Does this definition accept a variable number of arguments?
bool MacroDefinition::IsVariadic(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (dir_impl->defined_macro) {
    return dir_impl->defined_macro->isVariadic();
  } else {
    assert(false);
    return false;
  }
}

// Uses of this macro.
MacroNodeRange MacroDefinition::Uses(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  if (!dir_impl->macro_uses.empty()) {
    const auto first = dir_impl->macro_uses.data();
    return MacroNodeRange(
        ast, first, &(first[dir_impl->macro_uses.size()]));
  } else {
    return MacroNodeRange(ast);
  }
}

File MacroFileInclusion::IncludedFile(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);
  assert(dir_impl->included_file.has_value());
  return dir_impl->included_file.value();
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

MacroNodeRange MacroArgument::Nodes(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  if (!arg_impl->nodes.empty()) {
    const auto first = arg_impl->nodes.data();
    return MacroNodeRange(
        ast, first, &(first[arg_impl->nodes.size()]));
  } else {
    return MacroNodeRange(ast);
  }
}

MacroNodeRange MacroSubstitution::UsageNodes(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroSubstitutionImpl *sub_impl =
      dynamic_cast<MacroSubstitutionImpl *>(node_impl);
  if (!sub_impl->use_nodes.empty()) {
    const auto first = sub_impl->use_nodes.data();
    return MacroNodeRange(
        ast, first, &(first[sub_impl->use_nodes.size()]));
  } else {
    return MacroNodeRange(ast);
  }
}

MacroNodeRange MacroSubstitution::SubstitutionNodes(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroSubstitutionImpl *sub_impl =
      dynamic_cast<MacroSubstitutionImpl *>(node_impl);
  if (!sub_impl->nodes.empty()) {
    const auto first = sub_impl->nodes.data();
    return MacroNodeRange(
        ast, first, &(first[sub_impl->nodes.size()]));
  } else {
    return MacroNodeRange(ast);
  }
}

MacroExpansion MacroExpansion::Containing(
    const MacroArgument &arg) noexcept {
  Node node = *reinterpret_cast<const Node *>(arg.impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  return MacroExpansion(arg.ast, &(arg_impl->parent));
}

// Returns the directive that led to the definition of this expansion.
std::optional<MacroDefinition> MacroExpansion::Definition(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);
  if (std::holds_alternative<MacroNodeImpl *>(exp_impl->definition)) {
    return MacroDefinition(ast, &(exp_impl->definition));
  } else {
    return std::nullopt;
  }
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

// Prefix increment operator.
MacroNodeIterator &MacroNodeIterator::operator++(void) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) + 1;
  return *this;
}

// Postfix increment operator.
MacroNodeIterator MacroNodeIterator::operator++(int) noexcept {
  auto ret = *this;
  node.impl = reinterpret_cast<const Node *>(node.impl) + 1;
  return ret;
}

// Prefix decrement operator.
MacroNodeIterator &MacroNodeIterator::operator--(void) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) - 1;
  return *this;
}

// Postfix decrement operator.
MacroNodeIterator MacroNodeIterator::operator--(int) noexcept {
  auto ret = *this;
  node.impl = reinterpret_cast<const Node *>(node.impl) - 1;
  return ret;
}

MacroNodeIterator MacroNodeIterator::operator-(size_t offset) const noexcept {
  return MacroNodeIterator(
      node.ast, reinterpret_cast<const Node *>(node.impl) - offset);
}

MacroNodeIterator &MacroNodeIterator::operator+=(size_t offset) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) + offset;
  return *this;
}

MacroNodeIterator &MacroNodeIterator::operator-=(size_t offset) noexcept {
  node.impl = reinterpret_cast<const Node *>(node.impl) - offset;
  return *this;
}

MacroNode MacroNodeIterator::operator[](size_t offset) const noexcept {
  auto begin = reinterpret_cast<const Node *>(node.impl);
  return MacroNode(node.ast, &(begin[offset]));
}

ptrdiff_t MacroNodeIterator::operator-(const MacroNodeIterator &that) const noexcept {
  return reinterpret_cast<const Node *>(node.impl) -
         reinterpret_cast<const Node *>(that.node.impl);
}

size_t MacroNodeRange::Size(void) const noexcept {
  return static_cast<size_t>(reinterpret_cast<const Node *>(after_last) -
                             reinterpret_cast<const Node *>(first));
}

// Return the `index`th token in this range. If `index` is too big, then
// return nothing.
std::optional<MacroNode> MacroNodeRange::At(size_t index) const noexcept {
  auto begin = reinterpret_cast<const Node *>(first);
  auto end = reinterpret_cast<const Node *>(after_last);
  if (auto it = &(begin[index]); it < end) {
    return MacroNode(ast, it);
  } else {
    return std::nullopt;
  }
}

// Unsafe indexed access into the token range.
MacroNode MacroNodeRange::operator[](size_t index) const {
  auto begin = reinterpret_cast<const Node *>(first);
  return MacroNode(ast, &(begin[index]));
}

}  // namespace pasta
