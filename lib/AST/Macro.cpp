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
#include <clang/Lex/Token.h>
#pragma GCC diagnostic pop

#include "AST.h"
#include "Token.h"

namespace pasta {

MacroNodeKind MacroDirectiveImpl::Kind(void) const {
  return MacroNodeKind::kDirective;
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
  if (std::holds_alternative<size_t>(node)) {
    return MacroNodeKind::kToken;
  } else {
    return std::get<MacroNodeImpl *>(node)->Kind();
  }
}

const void *MacroNode::RawNode(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<size_t>(node)) {
    return &(ast->tokens[std::get<size_t>(node)]);
  } else {
    auto ret = std::get<MacroNodeImpl *>(node);
    assert(ret != nullptr);
    return ret;
  }
}

MacroToken MacroNode::LeftCorner(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<size_t>(node)) {
    return MacroToken(ast, impl);
  } else {
    MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
    if (auto sub = dynamic_cast<MacroSubstitutionImpl *>(node_impl)) {
      assert(!sub->use_nodes.empty());
      return MacroNode(ast, &(sub->use_nodes.front())).LeftCorner();
    } else {
      assert(!node_impl->nodes.empty());
      return MacroNode(ast, &(node_impl->nodes.front())).LeftCorner();
    }
  }
}

MacroToken MacroNode::RightCorner(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  if (std::holds_alternative<size_t>(node)) {
    return MacroToken(ast, impl);
  } else {
    MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
    if (auto sub = dynamic_cast<MacroSubstitutionImpl *>(node_impl)) {
      assert(!sub->use_nodes.empty());
      return MacroNode(ast, &(sub->use_nodes.back())).RightCorner();
    } else {
      assert(!node_impl->nodes.empty());
      return MacroNode(ast, &(node_impl->nodes.back())).RightCorner();
    }
  }
}

MacroToken::~MacroToken(void) {}

TokenKind MacroToken::Kind(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  TokenImpl &token = ast->tokens[std::get<size_t>(node)];
  return static_cast<TokenKind>(token.Kind());
}

// Return the data associated with this token.
std::string_view MacroToken::Data(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  TokenImpl &token = ast->tokens[std::get<size_t>(node)];
  return token.Data(*ast);
}

// Location of the token in a file.
std::optional<FileToken> MacroToken::FileLocation(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  clang::SourceLocation loc = ast->tokens[std::get<size_t>(node)].Location();
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

MacroDirective::~MacroDirective(void) {}

// Return the hash token of the directive.
MacroToken MacroDirective::HashToken(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  assert(!dir_impl->nodes.empty());
  assert(std::holds_alternative<size_t>(dir_impl->nodes.front()));
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
std::optional<MacroToken> MacroDirective::DirectiveName(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroDirectiveImpl *dir_impl = dynamic_cast<MacroDirectiveImpl *>(node_impl);

  if (!std::holds_alternative<size_t>(dir_impl->name_offset)) {
    return std::nullopt;
  }

  return MacroToken(ast, &(dir_impl->name_offset));
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

MacroArgument::~MacroArgument(void) {}

bool MacroArgument::IsVariadic(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  return arg_impl->is_variadic;
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

MacroSubstitution::~MacroSubstitution(void) {}

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

MacroExpansion::~MacroExpansion(void) {}

MacroExpansion MacroExpansion::Containing(
    const MacroArgument &arg) noexcept {
  Node node = *reinterpret_cast<const Node *>(arg.impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroArgumentImpl *arg_impl = dynamic_cast<MacroArgumentImpl *>(node_impl);
  return MacroExpansion(arg.ast, &(arg_impl->parent));
}

// Returns the directive that led to the definition of this expansion.
std::optional<MacroDirective> MacroExpansion::Definition(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);
  if (std::holds_alternative<MacroNodeImpl *>(exp_impl->definition)) {
    return MacroDirective(ast, &(exp_impl->definition));
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

// Returns the list of variadic arguments in the expansion if this was
// a use of a variadic function-like macro. This is a subset of `Arguments()`.
std::vector<MacroArgument>
MacroExpansion::VariadicArguments(void) const noexcept {
  Node node = *reinterpret_cast<const Node *>(impl);
  MacroNodeImpl *node_impl = std::get<MacroNodeImpl *>(node);
  MacroExpansionImpl *exp_impl = dynamic_cast<MacroExpansionImpl *>(node_impl);

  std::vector<MacroArgument> ret;
  for (Node &arg : exp_impl->variadic_arguments) {
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
