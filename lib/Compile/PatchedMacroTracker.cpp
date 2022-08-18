/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include "PatchedMacroTracker.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/LangOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/Token.h>
#pragma GCC diagnostic pop

#define D(...) __VA_ARGS__

namespace pasta {

PatchedMacroTracker::PatchedMacroTracker(clang::Preprocessor &pp_,
                                         clang::SourceManager &sm_,
                                         ASTImpl *ast_)
    : pp(pp_),
      sm(sm_),
      ci(*(ast_->ci)),
      lo(ci.getLangOpts()),
      ast(ast_),
      token_data_stream(ast->preprocessed_code),
      backup_token_data_stream(ast->backup_token_data) {
  (void) pp;
  nodes.push_back(&(ast->root_macro_node));
}

void PatchedMacroTracker::Clear(void) {
  assert(!depth);
  assert(nodes.size() == 1u);
  assert(directives.empty());
  assert(expansions.empty());
  depth = 0;
  defines.clear();
  expanded_toks.clear();
}

PatchedMacroTracker::~PatchedMacroTracker(void) {}

void PatchedMacroTracker::MergeTokens(MacroArgumentImpl *node) {

}

void PatchedMacroTracker::MergeTokens(MacroDirectiveImpl *node) {

}

void PatchedMacroTracker::MergeTokens(MacroExpansionImpl *node) {

}

void PatchedMacroTracker::MergeTokens(MacroSubstitutionImpl *node) {

}

void PatchedMacroTracker::MergeTokens(MacroNodeImpl *node) {
  switch (node->Kind()) {
    case MacroNodeKind::kArgument:
    case MacroNodeKind::kDirective:
    case MacroNodeKind::kDefine:
    case MacroNodeKind::kInclude:
    case MacroNodeKind::kExpansion:
    case MacroNodeKind::kSubstitution:
    case MacroNodeKind::kToken:
      assert(false);
      break;
  }
}

void PatchedMacroTracker::CloseUnclosedExpansion(const clang::Token &tok) {
  if (depth || ast->tokens.empty()) {
    return;
  }

  const TokenImpl &prev_tok = ast->tokens.back();
  TokenRole prev_role = prev_tok.Role();

  if (prev_role != TokenRole::kBeginOfMacroExpansionMarker &&
      prev_role != TokenRole::kIntermediateMacroExpansionToken &&
      prev_role != TokenRole::kFinalMacroExpansionToken) {
    return;
  }

  clang::SourceLocation prev_tok_loc = prev_tok.Location();
  if (prev_tok_loc.isFileID()) {
    ast->AppendMarker(prev_tok_loc.getLocWithOffset(prev_tok.data_len),
                      TokenRole::kEndOfMacroExpansionMarker);
  } else {
    ast->AppendMarker(tok.getLocation(),
                      TokenRole::kEndOfMacroExpansionMarker);
  }
}

void PatchedMacroTracker::Push(const clang::Token &tok) {
  if (!depth) {
    CloseUnclosedExpansion(tok);
    ast->AppendMarker(tok.getLocation(),
                      TokenRole::kBeginOfMacroExpansionMarker);
  }
  ++depth;
}

void PatchedMacroTracker::Pop(MacroNodeImpl *node) {
  assert(0 < depth);
  --depth;
}

bool PatchedMacroTracker::TryExtractHeaderName(const clang::Token &tok) {
  if (!tok.is(clang::tok::header_name)) {
    return false;
  }

  clang::SourceLocation open_loc = sm.getFileLoc(tok.getLocation());
  if (!open_loc.isValid()) {
    return false;
  }

  auto [file_id, offset] = sm.getDecomposedLoc(open_loc);
  assert(file_id.isValid());
  auto raw_file_id = file_id.getHashValue();
  auto file_it = ast->id_to_file.find(raw_file_id);
  if (file_it == ast->id_to_file.end()) {
    return false;
  }

  const File &file = file_it->second;
  auto file_token = file.TokenAtOffset(offset);
  if (!file_token) {
    return false;
  }

  MacroSubstitutionImpl *sub =
      &(ast->root_macro_node.substitutions.emplace_back());
  MacroNodeImpl *parent_node = nodes.back();
  sub->parent = parent_node;
  parent_node->nodes.emplace_back(sub);
  nodes.push_back(sub);

  auto end = file_token->Data() == "<" ? ">" : "\"";

  clang::Token nt;
  auto file_tokens = file.Tokens();
  for (size_t i = file_token->Index(), max_i = file_tokens.Size();
       i < max_i; ++i) {
    auto t = file_tokens[i];
    nt.startToken();
    nt.setKind(static_cast<clang::tok::TokenKind>(t.Kind()));
    nt.setLocation(sm.getComposedLoc(file_id, t.Offset()));
    nt.setLength(static_cast<unsigned>(t.Data().size()));
    DoToken(nt, 0);

    if (t.Data() == end) {
      break;
    }
  }

  // Switch to expansion.
  sub->use_nodes.swap(sub->nodes);

  return true;
}

// If we're in macro argument pre-expansion, and if we actually see a token,
// then we want to fake another expansion. To do so, that means copying in
// a few extra tokens (the macro use and call). Later, we'll detect that we
// did this, and then build out the expansion.
void PatchedMacroTracker::TryDoPreExpansionSetup(void) {
  if (expansions.empty()) {
    return;
  }

  assert(!nodes.empty());
  MacroExpansionImpl *exp = expansions.back();
  if (exp != nodes.back() || !exp->in_prearg_expansion || !exp->nodes.empty()) {
    return;
  }

  assert(!exp->use_nodes.empty());
  MacroTokenImpl *ident = nullptr;
  MacroTokenImpl *l_paren = nullptr;
  for (Node &node : exp->use_nodes) {
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      MacroTokenImpl *use_tok = std::get<MacroTokenImpl *>(node);
      if (!ident && use_tok->kind == TokenKind::kIdentifier) {
        ident = use_tok;
      } else if (ident && use_tok->kind == TokenKind::kLParenthesis) {
        l_paren = use_tok;
        break;
      }
    }
  }
  assert(ident != nullptr);
  assert(l_paren != nullptr);

  MacroExpansionImpl *new_exp =
      &(ast->root_macro_node.expansions.emplace_back());

  // Make this the active expansion.
  expansions.pop_back();
  nodes.pop_back();
  expansions.push_back(new_exp);
  nodes.push_back(new_exp);

  if (std::holds_alternative<MacroNodeImpl *>(exp->definition)) {
    MacroDirectiveImpl *def = reinterpret_cast<MacroDirectiveImpl *>(
        std::get<MacroNodeImpl *>(exp->definition));
    new_exp->definition = def;
    def->macro_uses.emplace_back(new_exp);
  }

  exp->nodes.push_back(new_exp);
  exp->in_prearg_expansion = false;
  new_exp->is_prearg_expansion = true;
  new_exp->in_prearg_expansion = false;
  new_exp->parent = exp;

  TokenImpl ident_tok = ast->tokens[ident->token_offset];
  TokenImpl l_paren_tok = ast->tokens[l_paren->token_offset];

  auto new_offset = ast->tokens.size();
  ast->tokens.emplace_back(std::move(ident_tok));
  ast->tokens.emplace_back(std::move(l_paren_tok));

  MacroTokenImpl *new_ident = &(ast->root_macro_node.tokens.emplace_back());
  new_ident->token_offset = static_cast<uint32_t>(new_offset);
  new_ident->parent = new_exp;
  new_ident->kind = ident->kind;
  new_exp->nodes.push_back(new_ident);

  MacroTokenImpl *new_l_paren = &(ast->root_macro_node.tokens.emplace_back());
  new_l_paren->token_offset = static_cast<uint32_t>(new_offset + 1u);
  new_l_paren->parent = new_exp;
  new_l_paren->kind = l_paren->kind;
  new_exp->nodes.push_back(new_l_paren);

  token_data_stream << '\n' << '\n';
  token_data_stream.flush();
  ast->num_lines += 2u;
}

// Add a token in.
void PatchedMacroTracker::DoToken(const clang::Token &tok, uintptr_t) {
  last_token = tok;

  if (skip_count || 1u == nodes.size() || tok.is(clang::tok::eod) ||
      tok.is(clang::tok::eof)) {
    last_token_was_added = false;

    CloseUnclosedExpansion(tok);
    return;
  }

  // NOTE(pag): This might change `nodes.back()`.
  TryDoPreExpansionSetup();

  // With header names, we don't observe the lexing of the individual tokens.
  auto substituted_header_name = TryExtractHeaderName(tok);

  // Get the token data, and add the data to the AST's backup region, and a
  // empty newline to the normal token data, so that the 1:1 mapping between
  // line numbers in parsed source locations and tokens recorded matches up.
  tok_data.clear();
  auto offset = ast->backup_token_data.size();
  if (::pasta::TryReadRawToken(sm, lo, tok, &tok_data)) {
    backup_token_data_stream << tok_data;
    backup_token_data_stream.flush();
  }
  token_data_stream << '\n';
  token_data_stream.flush();
  ast->num_lines++;

  MacroNodeImpl *parent_node = nodes.back();

  // Add the token to the AST.
  size_t tok_index = ast->tokens.size();
  ast->AppendBackupToken(tok, offset, tok_data.size(),
                         TokenRole::kIntermediateMacroExpansionToken);

  TokenImpl &added_tok = ast->tokens.back();
  MacroTokenImpl *tok_node = &(ast->root_macro_node.tokens.emplace_back());
  tok_node->token_offset = static_cast<uint32_t>(tok_index);
  tok_node->parent = parent_node;

  // Clear out the kind, so that it looks `unknown` from the perspective of
  // `ASTImpl::AlignTokens`. We add it back in later after token alignment
  // via `ASTImpl::LinkMacroTokenContexts`.
  tok_node->kind = static_cast<TokenKind>(added_tok.Kind());
  added_tok.kind = 0;

  // Add the token to the node.
  parent_node->nodes.push_back(tok_node);
  last_token_was_added = true;

  // Close the substitution.
  if (substituted_header_name) {
    nodes.pop_back();
  }
}

void ASTImpl::LinkMacroTokenContexts(void) {
  root_macro_node.token_nodes.reserve(root_macro_node.tokens.size());

  auto i = 0u;
  for (MacroTokenImpl &mt : root_macro_node.tokens) {
    TokenImpl &tok = tokens[mt.token_offset];

#ifndef NDEBUG
    switch (tok.Role()) {
      case TokenRole::kIntermediateMacroExpansionToken:
      case TokenRole::kFinalMacroExpansionToken:
        break;
      default:
        assert(false);
        continue;  // Skip it. `TokenImpl::Context` isn't expecting this.
    }
#endif

    root_macro_node.token_nodes.emplace_back(&mt);
    tok.kind = static_cast<TokenKindBase>(mt.kind);
    mt.token_context = tok.context_index;
    tok.context_index = i;
    ++i;
  }
}

void PatchedMacroTracker::DoBeginSkippedArea(
    const clang::Token &tok, uintptr_t data) {
  ++skip_count;
  DoBeginDirective(tok, data);
  directives.back()->is_skipped = true;
}

void PatchedMacroTracker::DoBeginDirective(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);
  MacroDirectiveImpl *directive =
      &(ast->root_macro_node.directives.emplace_back());
  nodes.back()->nodes.emplace_back(directive);
  directive->parent = nodes.back();
  nodes.push_back(directive);
  directives.push_back(directive);
  DoToken(tok, data);
}

// Mark this as being a directive with a name.
void PatchedMacroTracker::DoSetNamedDirective(const clang::Token &, uintptr_t) {
  assert(!directives.empty());
  assert(nodes.back() == directives.back());
  MacroDirectiveImpl *directive = directives.back();
  if (!skip_count) {
    if (std::holds_alternative<MacroTokenImpl *>(directive->nodes.back())) {
      directive->directive_name = directive->nodes.back();
    } else {
      assert(false);
    }
  }
}

static void ReparentNode(Node &node, MacroNodeImpl *new_parent) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    std::get<MacroTokenImpl *>(node)->parent = new_parent;

  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    std::get<MacroNodeImpl *>(node)->parent = new_parent;
  }
}

static void ReparentNodes(std::vector<Node> nodes, MacroNodeImpl *new_parent) {
  for (Node &node : nodes) {
    ReparentNode(node, new_parent);
  }

  new_parent->nodes.insert(new_parent->nodes.end(),
                           nodes.begin(),
                           nodes.end());
  nodes.clear();
}

void PatchedMacroTracker::DoEndNonDirective(const clang::Token &, uintptr_t) {
  assert(!directives.empty());
  assert(nodes.back() == directives.back());
  last_directive = directives.back();
  nodes.pop_back();
  directives.pop_back();

  MacroNodeImpl *parent_node = nodes.back();

  // Remove it from the parent, and move all child nodes up to the parent.
  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) ==
         last_directive);
  parent_node->nodes.pop_back();
  ReparentNodes(std::move(last_directive->nodes), parent_node);
  Pop(parent_node);
  last_directive = nullptr;
}

void PatchedMacroTracker::DoEndDirective(
    const clang::Token &tok, uintptr_t data) {
  assert(!directives.empty());
  assert(nodes.back() == directives.back());
  last_directive = directives.back();
  nodes.pop_back();
  directives.pop_back();
  MacroNodeImpl *parent_node = nodes.back();
  if (!last_directive->is_skipped) {
    Pop(last_directive);
    return;
  }

  --skip_count;

  // If it was skipped, then remove it from the parent. Don't copy any of the
  // tokens in. Inside of skipped regions, we end up seeing partial tokens
  // that we don't want to include, like `#define` but nothing after.
  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) ==
         last_directive);
  parent_node->nodes.pop_back();
  last_directive = nullptr;
  Pop(parent_node);
}

void PatchedMacroTracker::DoBeginMacroExpansion(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);  // TODO(pag): Which token to pop?
  MacroExpansionImpl *expansion =
      &(ast->root_macro_node.expansions.emplace_back());
  nodes.back()->nodes.emplace_back(expansion);
  expansion->parent = nodes.back();
  nodes.push_back(expansion);
  expansions.push_back(expansion);
  DoToken(tok, data);

  // Link up the expansion with the definition. `data` might be zero in the
  // case of `_Pragma`.
  clang::MacroInfo *mi = reinterpret_cast<clang::MacroInfo *>(data);
  if (auto it = defines.find(mi); it != defines.end()) {
    if (MacroDirectiveImpl *def = it->second) {
      assert(def->kind == MacroDirectiveKind::kDefine);
      assert(def->defined_macro == mi);
      def->macro_uses.push_back(expansion);
      expansion->definition = def;
    }
  }
}

void PatchedMacroTracker::DoBeginMacroCallArgument(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  if (expansion->is_cancelled) {
    assert(0 < skip_count);
    return;
  }

  MacroArgumentImpl *argument =
      &(ast->root_macro_node.arguments.emplace_back());
  argument->is_variadic = expansion->is_variadic;
  argument->index = static_cast<unsigned>(expansion->arguments.size());
  argument->parent = expansion;

  expansion->nodes.emplace_back(argument);
  expansion->arguments.emplace_back(argument);
  if (argument->is_variadic) {
    expansion->variadic_arguments.emplace_back(argument);
  }
  nodes.push_back(argument);
  arguments.push_back(argument);
}

void PatchedMacroTracker::DoEndMacroCallArgument(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  if (expansion->is_cancelled) {
    assert(0 < skip_count);
    assert(arguments.empty() || nodes.back() != arguments.back());
    return;
  }

  assert(!arguments.empty());
  assert(nodes.back() == arguments.back());
  MacroArgumentImpl *argument = arguments.back();
  arguments.pop_back();
  nodes.pop_back();
  assert(nodes.back() == expansions.back());
  assert(std::holds_alternative<MacroNodeImpl *>(argument->parent));
  assert(nodes.back() == std::get<MacroNodeImpl *>(argument->parent));

  // Pop off the `,` or the `)` from the argument, and add it to the
  // expansion.
  if (!argument->nodes.empty()) {
    MacroNodeImpl *parent_node = std::get<MacroNodeImpl *>(argument->parent);
    assert(parent_node->Kind() == MacroNodeKind::kExpansion);
    ReparentNode(argument->nodes.back(), parent_node);
    parent_node->nodes.push_back(std::move(argument->nodes.back()));
    argument->nodes.pop_back();
  }
}

void PatchedMacroTracker::DoBeginVariadicCallArgumentList(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(!expansion->is_variadic);
  expansion->is_variadic = true;

  if (expansion->is_cancelled) {
    assert(0 < skip_count);
  }
}

void PatchedMacroTracker::DoBeginPreArgumentExpansion(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(!expansion->in_prearg_expansion);
  expansion->in_prearg_expansion = true;

  if (expansion->is_cancelled) {
    assert(0 < skip_count);
    return;
  }
}

void PatchedMacroTracker::DoEndPreArgumentExpansion(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();

  if (expansion->is_cancelled) {
    assert(0 < skip_count);
    return;
  }

  // This node is a pre-argument expansion invented expansion, so we need to
  // inject in a closing parenthesis to complete it.
  if (expansion->is_prearg_expansion) {
    assert(!expansion->nodes.empty());
    expansion->nodes.swap(expansion->use_nodes);

    MacroExpansionImpl *parent_exp = reinterpret_cast<MacroExpansionImpl *>(
        std::get<MacroNodeImpl *>(expansion->parent));
    assert(!parent_exp->use_nodes.empty());

    MacroTokenImpl *r_paren = nullptr;
    for (auto it = parent_exp->use_nodes.rbegin(),
              it_end = parent_exp->use_nodes.rend();
         it != it_end; ++it) {
      Node &node = *it;
      if (std::holds_alternative<MacroTokenImpl *>(node)) {
        MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
        if (tok->kind == TokenKind::kRParenthesis) {
          r_paren = tok;
          break;
        }
      }
    }

    assert(r_paren != nullptr);
    TokenImpl r_paren_tok = ast->tokens[r_paren->token_offset];

    auto new_offset = ast->tokens.size();
    ast->tokens.emplace_back(std::move(r_paren_tok));

    MacroTokenImpl *new_r_paren = &(ast->root_macro_node.tokens.emplace_back());
    new_r_paren->token_offset = static_cast<uint32_t>(new_offset);
    new_r_paren->parent = expansion;
    new_r_paren->kind = r_paren->kind;
    expansion->use_nodes.push_back(new_r_paren);

    token_data_stream << '\n';
    token_data_stream.flush();
    ast->num_lines += 1u;

  // This node was marked for pre-argument expansion, but we're still in that
  // state so it meant that nothing really happened.
  } else if (expansion->in_prearg_expansion) {
    assert(expansion->nodes.empty());
    expansion->in_prearg_expansion = false;

  } else {
    assert(false);
  }
}

void PatchedMacroTracker::DoSwitchToExpansion(const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());

  if (expansion->is_cancelled) {
    assert(0 < skip_count);
    expansion->nodes.clear();
  } else {
    expansion->nodes.swap(expansion->use_nodes);
  }
}

void PatchedMacroTracker::DoPrepareToCancelExpansion(const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());
  assert(!expansion->is_cancelled);
  expansion->is_cancelled = true;
  ++skip_count;
}

void PatchedMacroTracker::DoCancelExpansion(const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  Pop(expansion);
  assert(nodes.back() == expansion);
  nodes.pop_back();
  expansions.pop_back();

  MacroNodeImpl *parent_node = nodes.back();
  if (expansion->is_prearg_expansion) {
    parent_node = std::get<MacroNodeImpl *>(expansion->parent);
  } else {
    assert(parent_node == std::get<MacroNodeImpl *>(expansion->parent));
  }

  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) == expansion);
  parent_node->nodes.pop_back();

  assert(expansion->use_nodes.empty());
  if (expansion->is_cancelled) {
    assert(0 < skip_count);
    --skip_count;
  } else {
    assert(!expansion->is_cancelled);
    expansion->is_cancelled = true;
  }
}

void PatchedMacroTracker::DoEndMacroExpansion(
    const clang::Token &tok, uintptr_t data) {
  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  assert(!expansion->is_cancelled);
  Pop(expansion);
  assert(nodes.back() == expansion);
  nodes.pop_back();
  expansions.pop_back();

  MacroNodeImpl *parent_node = nodes.back();
  if (expansion->is_prearg_expansion) {
    parent_node = std::get<MacroNodeImpl *>(expansion->parent);
  } else {
    assert(parent_node == std::get<MacroNodeImpl *>(expansion->parent));
  }

  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) == expansion);

  if (expansion->is_cancelled) {
    assert(expansion->use_nodes.empty());
    parent_node->nodes.pop_back();
    ReparentNodes(std::move(expansion->nodes), parent_node);
  }
}

void PatchedMacroTracker::DoBeginSubstitution(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);
  MacroSubstitutionImpl *expansion =
      &(ast->root_macro_node.substitutions.emplace_back());
  nodes.back()->nodes.emplace_back(expansion);
  expansion->parent = nodes.back();
  nodes.push_back(expansion);
  substitutions.push_back(expansion);
  DoToken(tok, data);
}

void PatchedMacroTracker::DoBeginDelayedSubstitution(
    const clang::Token &tok, uintptr_t data) {

  if (!depth) {
    Push(last_token);  // Will add a marker token.

    // Swap the marker and this token.
    if (last_token_was_added) {
      auto num_tokens = ast->tokens.size();
      std::swap(ast->tokens[num_tokens - 2u], ast->tokens[num_tokens - 1u]);
    }
  } else {
    Push(last_token);
  }

  MacroSubstitutionImpl *expansion =
      &(ast->root_macro_node.substitutions.emplace_back());

  MacroNodeImpl * const parent_node = nodes.back();
  expansion->parent = parent_node;

  if (last_token_was_added) {
    assert(!parent_node->nodes.empty());
    ReparentNode(parent_node->nodes.back(), expansion);
    expansion->nodes.push_back(std::move(parent_node->nodes.back()));
    parent_node->nodes.pop_back();
  }

  parent_node->nodes.emplace_back(expansion);

  nodes.push_back(expansion);
  substitutions.push_back(expansion);

  if (!last_token_was_added) {
    DoToken(tok, data);
  }
}

void PatchedMacroTracker::DoSwitchToSubstitution(
    const clang::Token &, uintptr_t) {
  assert(!substitutions.empty());
  assert(nodes.back() == substitutions.back());
  MacroSubstitutionImpl *expansion = substitutions.back();
  assert(expansion->use_nodes.empty());
  expansion->nodes.swap(expansion->use_nodes);
}

void PatchedMacroTracker::DoEndSubstitution(const clang::Token &, uintptr_t) {
  assert(!substitutions.empty());
  assert(nodes.back() == substitutions.back());
  Pop(nodes.back());
  nodes.pop_back();
  substitutions.pop_back();
}

// PASTA PATCH:
void PatchedMacroTracker::Event(const clang::Token &tok, EventKind kind,
                                uintptr_t data) {
  switch (kind) {
    case TokenFromLexer:
    case TokenFromTokenLexer:
    case TokenFromCachingLexer:
    case TokenFromAfterModuleImportLexer:
      DoToken(tok, data);
      break;
    case BeginSkippedArea: DoBeginSkippedArea(tok, data); break;
    case BeginDirective: DoBeginDirective(tok, data); break;
    case SetNamedDirective: DoSetNamedDirective(tok, data); break;
    case SetUnnamedDirective: break;
    case EndNonDirective: DoEndNonDirective(tok, data); break;
    case EndDirective: DoEndDirective(tok, data); break;
    case BeginMacroExpansion: DoBeginMacroExpansion(tok, data); break;
    case PrepareToCancelExpansion: DoPrepareToCancelExpansion(tok, data); break;
    case CancelExpansion: DoCancelExpansion(tok, data); break;
    case SwitchToExpansion: DoSwitchToExpansion(tok, data); break;
    case BeginPreArgumentExpansion: DoBeginPreArgumentExpansion(tok, data); break;
    case EndPreArgumentExpansion: DoEndPreArgumentExpansion(tok, data); break;
    case EndMacroExpansion: DoEndMacroExpansion(tok, data); break;
    case BeginMacroCallArgument: DoBeginMacroCallArgument(tok, data); break;
    case EndMacroCallArgument: DoEndMacroCallArgument(tok, data); break;
    case BeginMacroCallArgumentList: break;
    case EndMacroCallArgumentList: break;
    case BeginVariadicCallArgumentList:
      DoBeginVariadicCallArgumentList(tok, data);
      break;
    case EndVariadicCallArgumentList: break;
    case BeginSubstitution: DoBeginSubstitution(tok, data); break;
    case BeginDelayedSubstitution:
      DoBeginDelayedSubstitution(tok, data);
      break;
    case SwitchToSubstitution: DoSwitchToSubstitution(tok, data); break;
    case EndSubstitution: DoEndSubstitution(tok, data); break;

    // TODO(pag): Handle these:
    case BeginSplitToken: break;
    case EndSplitToken: break;
  }

  if constexpr (D(1 -) 0) {

    switch (kind) {
      case EndSplitToken:
      case EndDirective:
      case EndNonDirective:
      case EndMacroExpansion:
      case EndMacroCallArgumentList:
      case EndMacroCallArgument:
      case EndVariadicCallArgumentList:
      case EndSubstitution:
      case EndPreArgumentExpansion:
      case CancelExpansion:
//        --depth;
        indent.resize(indent.size() - 2);
        break;
      default:
        break;
    }

    std::cerr << indent;

    switch (kind) {
      case TokenFromLexer: std::cerr << "TokenFromLexer"; break;
      case TokenFromTokenLexer: std::cerr << "TokenFromTokenLexer"; break;
      case TokenFromCachingLexer: std::cerr << "TokenFromCachingLexer"; break;
      case TokenFromAfterModuleImportLexer: std::cerr << "TokenFromAfterModuleImportLexer"; break;
      case BeginSplitToken: std::cerr << "BeginSplitToken"; break;
      case EndSplitToken: std::cerr << "EndSplitToken"; break;
      case BeginDirective: std::cerr << "BeginDirective"; break;
      case BeginSkippedArea: std::cerr << "BeginSkippedArea"; break;
      case SetNamedDirective: std::cerr << "SetNamedDirective"; break;
      case SetUnnamedDirective: std::cerr << "SetUnnamedDirective"; break;
      case EndDirective: std::cerr << "EndDirective"; break;
      case EndNonDirective: std::cerr << "EndNonDirective"; break;
      case BeginMacroExpansion: std::cerr << "BeginMacroExpansion"; break;
      case SwitchToExpansion: std::cerr << "SwitchToExpansion"; break;
      case BeginPreArgumentExpansion: std::cerr << "BeginPreArgumentExpansion"; break;
      case EndPreArgumentExpansion: std::cerr << "EndPreArgumentExpansion"; break;
      case PrepareToCancelExpansion: std::cerr << "PrepareToCancelExpansion"; break;
      case CancelExpansion: std::cerr << "CancelExpansion"; break;
      case EndMacroExpansion: std::cerr << "EndMacroExpansion"; break;
      case BeginMacroCallArgumentList: std::cerr << "BeginMacroCallArgumentList"; break;
      case EndMacroCallArgumentList: std::cerr << "EndMacroCallArgumentList"; break;
      case BeginMacroCallArgument: std::cerr << "BeginMacroCallArgument"; break;
      case EndMacroCallArgument: std::cerr << "EndMacroCallArgument"; break;
      case BeginVariadicCallArgumentList: std::cerr << "BeginVariadicCallArgumentList"; break;
      case EndVariadicCallArgumentList: std::cerr << "EndVariadicCallArgumentList"; break;
      case BeginSubstitution: std::cerr << "BeginSubstitution"; break;
      case BeginDelayedSubstitution: std::cerr << "BeginDelayedSubstitution"; break;
      case SwitchToSubstitution: std::cerr << "SwitchToSubstitution"; break;
      case EndSubstitution: std::cerr << "EndSubstitution"; break;
    }

    std::cerr << ' ' << clang::tok::getTokenName(tok.getKind());

    if (tok.is(clang::tok::identifier)) {
      std::cerr << ' ' << tok.getIdentifierInfo()->getName().str();
    } else if (tok.is(clang::tok::raw_identifier)) {
      std::cerr << ' ' << tok.getRawIdentifier().str();
    }

    switch (kind) {
      case BeginSplitToken:
      case BeginDirective:
      case BeginSkippedArea:
      case BeginMacroExpansion:
      case BeginMacroCallArgumentList:
      case BeginMacroCallArgument:
      case BeginVariadicCallArgumentList:
      case BeginSubstitution:
      case BeginDelayedSubstitution:
      case BeginPreArgumentExpansion:
//        ++depth;
        indent += "  ";
        break;
      default:
        break;
    }

    std::cerr << '\n';
  }
}

// Callback invoked whenever an inclusion directive of any kind (`#include`,
// `#import`, etc.) has been processed, regardless of whether the inclusion
// will actually result in an inclusion.
void PatchedMacroTracker::InclusionDirective(
    clang::SourceLocation /* hash_loc */, const clang::Token &include_tok,
    llvm::StringRef /* file_name */, bool /* is_angled */,
    clang::CharSourceRange /* file_name_range */,
    const clang::FileEntry * /* file */, llvm::StringRef /* search_path */,
    llvm::StringRef /* relative_path */, const clang::Module * /* imported */,
    clang::SrcMgr::CharacteristicKind /* file_type */) {

  assert(last_directive != nullptr);
  assert(last_directive->kind == MacroDirectiveKind::kOther);
  switch (include_tok.getIdentifierInfo()->getPPKeywordID()) {
    case clang::tok::pp_include:
      last_directive->kind = MacroDirectiveKind::kInclude;
      break;
    case clang::tok::pp_include_next:
      last_directive->kind = MacroDirectiveKind::kIncludeNext;
      break;
    case clang::tok::pp_import:
      last_directive->kind = MacroDirectiveKind::kImport;
      break;
    case clang::tok::pp___include_macros:
      last_directive->kind = MacroDirectiveKind::kIncludeMacros;
      break;
    default: break;
  }

  D( std::cerr << indent << "InclusionDirective\n"; )
}

// Each time we enter a source file, try to keep track of it.
void PatchedMacroTracker::FileChanged(
    clang::SourceLocation loc, clang::PPCallbacks::FileChangeReason reason,
    clang::SrcMgr::CharacteristicKind file_type, clang::FileID file_id) {
  if (clang::PPCallbacks::FileChangeReason::EnterFile == reason &&
      file_id.isValid() && last_directive &&
      (last_directive->kind == MacroDirectiveKind::kInclude ||
       last_directive->kind == MacroDirectiveKind::kIncludeNext ||
       last_directive->kind == MacroDirectiveKind::kIncludeMacros ||
       last_directive->kind == MacroDirectiveKind::kImport)) {

    if (auto it = ast->id_to_file.find(file_id.getHashValue());
        it != ast->id_to_file.end()) {
      last_directive->included_file.emplace(it->second);
    }
  }

  D( std::cerr << indent << "FileChanged\n"; )
}

// Callback invoked when a `#ident` or `#sccs` directive is read.
void PatchedMacroTracker::Ident(clang::SourceLocation, clang::StringRef) {
  D( std::cerr << indent << "Ident\n"; )
}

// Callback invoked when start reading any pragma directive.
void PatchedMacroTracker::PragmaDirective(
    clang::SourceLocation loc, clang::PragmaIntroducerKind introducer) {
  assert(!directives.empty());
  MacroDirectiveImpl *directive = directives.back();
  assert(directive->kind == MacroDirectiveKind::kOther);

  switch (introducer) {
    case clang::PragmaIntroducerKind::PIK_HashPragma:
      directive->kind = MacroDirectiveKind::kHashPragma;
      break;
    case clang::PragmaIntroducerKind::PIK__Pragma:
      directive->kind = MacroDirectiveKind::kC99Pragma;
      break;
    case clang::PragmaIntroducerKind::PIK___pragma:
      directive->kind = MacroDirectiveKind::kMicrosoftPragma;
      break;
  }
}

// Hook called when a source range is skipped.
void PatchedMacroTracker::SourceRangeSkipped(
    clang::SourceRange, clang::SourceLocation /* endif_loc */) {
  D( std::cerr << indent << "SourceRangeSkipped\n"; )
}

// Hook called whenever an `#if` is seen.
//
// NOTE(pag): `condition_range` might point into file locations.
void PatchedMacroTracker::If(clang::SourceLocation,
                             clang::SourceRange /* condition_range */,
                             ConditionValueKind) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kIf;
  }
  D( std::cerr << indent << "If\n"; )
}

// Hook called whenever an `#elif` is seen.
//
// NOTE(pag): `condition_range` might point into file locations.
void PatchedMacroTracker::Elif(clang::SourceLocation,
                               clang::SourceRange /* condition_range */,
                               ConditionValueKind,
                               clang::SourceLocation /* if_loc */) {

  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kElseIf;
  }
  D( std::cerr << indent << "Elif\n"; )
}

// Hook called whenever an `#ifdef` is seen.
void PatchedMacroTracker::Ifdef(clang::SourceLocation,
           const clang::Token & /* macro_name_tested */,
           const clang::MacroDefinition &) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kIfDefined;
  }
  D( std::cerr << indent << "Ifdef\n"; )
}

// Hook called whenever an `#ifndef` is seen.
void PatchedMacroTracker::Ifndef(clang::SourceLocation,
                                 const clang::Token & /* macro_name_tested */,
                                 const clang::MacroDefinition &) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kIfNotDefined;
  }
  D( std::cerr << indent << "Ifndef\n"; )
}

/// Hook called whenever an `#else` is seen.
void PatchedMacroTracker::Else(clang::SourceLocation,
                               clang::SourceLocation /* if_loc */) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kElse;
  }
  D( std::cerr << indent << "Else\n"; )
}

// Hook called whenever an `#endif` is seen.
void PatchedMacroTracker::Endif(clang::SourceLocation,
                                clang::SourceLocation /* if_loc */) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kEndIf;
  }
  D( std::cerr << indent << "Endif\n"; )
}

// Hook called whenever a macro definition is seen.
void PatchedMacroTracker::MacroDefined(const clang::Token &name_tok,
                                       const clang::MacroDirective *directive) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kDefine;
    last_directive->defined_macro = directive->getMacroInfo();
    defines[last_directive->defined_macro] = last_directive;

    for (Node &node : last_directive->nodes) {
      if (std::holds_alternative<MacroTokenImpl *>(node)) {
        TokenImpl &tok =
            ast->tokens[std::get<MacroTokenImpl *>(node)->token_offset];
        if (tok.Location() == name_tok.getLocation()) {
          last_directive->macro_name = node;
          break;
        }
      }
    }

    assert(std::holds_alternative<MacroTokenImpl *>(last_directive->macro_name));
  }
  D( std::cerr << indent << "MacroDefined\n"; )
}

// Hook called whenever a macro `#undef` is seen.
//
// NOTE(pag): `directive` can't be trusted.
void PatchedMacroTracker::MacroUndefined(
    const clang::Token &, const clang::MacroDefinition &,
    const clang::MacroDirective *directive) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroDirectiveKind::kOther);
    last_directive->kind = MacroDirectiveKind::kUndefine;
    defines.erase(directive->getMacroInfo());
  }
  D( std::cerr << indent << "MacroUndefined\n"; )
}

// Called by Preprocessor::HandleMacroExpandedIdentifier when a
// macro invocation is found. We want to inject placeholder tokens into
// the parsed range that relates to where the macro is in the original file.
// Thus, we are trying to narrow down on the set of expansions that happen
// at a file level, and not "sub-expansions" inside of other macro expansions.
void PatchedMacroTracker::MacroExpands(const clang::Token &,
                                       const clang::MacroDefinition &,
                                       clang::SourceRange /* use_range */,
                                       const clang::MacroArgs *) {
  D( std::cerr << indent << "MacroExpands\n"; )
}

}  // namespace pasta
