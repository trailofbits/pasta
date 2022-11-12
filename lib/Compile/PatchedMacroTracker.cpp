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

//#define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#endif

namespace pasta {

static void ReparentNode(Node &node, MacroNodeImpl *new_parent) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    std::get<MacroTokenImpl *>(node)->parent = new_parent;

  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    auto impl = std::get<MacroNodeImpl *>(node);
    if (auto arg = dynamic_cast<MacroArgumentImpl *>(impl)) {
      assert(!dynamic_cast<MacroArgumentImpl *>(new_parent));
    }
    impl->parent = new_parent;
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

// Inject `new_arg` after `exp` inside of `nodes` and `arguments`.
static void InjectArgumentNode(std::vector<MacroNodeImpl *> &nodes,
                               std::vector<MacroArgumentImpl *> &arguments,
                               MacroNodeImpl *exp,
                               MacroArgumentImpl *new_arg) {

  std::vector<MacroNodeImpl *> new_nodes;
  std::vector<MacroArgumentImpl *> new_arguments;

  for (MacroNodeImpl *old_node : nodes) {
    new_nodes.push_back(old_node);
    if (auto old_arg = dynamic_cast<MacroArgumentImpl *>(old_node)) {
      new_arguments.push_back(old_arg);

    } else if (old_node == exp) {
      new_nodes.push_back(new_arg);
      new_arguments.push_back(new_arg);
    }
  }

  nodes.swap(new_nodes);
  arguments.swap(new_arguments);
}

PatchedMacroTracker::PatchedMacroTracker(
    clang::Preprocessor &pp_, clang::SourceManager &sm_, ASTImpl *ast_)
    : pp(pp_),
      sm(sm_),
      ci(*(ast_->ci)),
      lo(ci.getLangOpts()),
      ast(ast_),
      token_data_stream(ast->preprocessed_code),
      backup_token_data_stream(ast->backup_token_data) {
  (void) pp;
  (void) suppress_indent;
  (void) indent;
  nodes.push_back(&(ast->root_macro_node));
  tok_data_vec.resize(16);
}

void PatchedMacroTracker::Clear(void) {
  assert(!depth);
  assert(nodes.size() == 1u);
  assert(directives.empty());
  assert(expansions.empty());
  depth = 0;
  defines.clear();
  file_token_refs.clear();
  macro_token_refs.clear();
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
    case MacroNodeKind::kInvalid:
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
      prev_role != TokenRole::kInitialMacroUseToken &&
      prev_role != TokenRole::kIntermediateMacroExpansionToken &&
      prev_role != TokenRole::kFinalMacroExpansionToken) {
    return;
  }

  ast->AppendMarker({}, TokenRole::kEndOfMacroExpansionMarker);
  D( std::cerr << indent << "EndOfMacroExpansionMarker\n"; )

  FixupDerivedLocations();
}

void PatchedMacroTracker::Push(const clang::Token &tok) {
  if (!depth) {
    CloseUnclosedExpansion(tok);
    start_of_macro_index = static_cast<DerivedTokenIndex>(ast->tokens.size());
    assert(start_of_macro_index == ast->tokens.size());
    D( std::cerr << indent << "BeginOfMacroExpansionMarker\n"; )
    assert(tok.getLocation().isValid() && tok.getLocation().isFileID());
    ast->AppendMarker(tok.getLocation(),
                      TokenRole::kBeginOfMacroExpansionMarker);
  }
  ++depth;
}

void PatchedMacroTracker::Pop(const clang::Token &tok) {
  assert(0 < depth);
  if (!--depth) {
    CloseUnclosedExpansion(tok);
  }
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
  AddToParentNode(sub);  // Adds to `parent_node`.
  nodes.push_back(sub);

  auto end = file_token->Data()[0] == '<' ? '>' : '"';

  clang::Token nt;
  auto file_tokens = file.Tokens();
  for (size_t i = file_token->Index(), max_i = file_tokens.Size();
       i < max_i; ++i) {
    FileToken t = file_tokens[i];
    nt.startToken();
    nt.setKind(static_cast<clang::tok::TokenKind>(t.Kind()));
    nt.setLocation(sm.getComposedLoc(file_id, t.Offset()));
    nt.setLength(static_cast<unsigned>(t.Data().size()));
    DoToken(nt, 0);
    D( std::cerr << indent << "HeaderNameToken " << clang::tok::getTokenName(nt.getKind()) << '\n'; )

    if (t.Data().ends_with(end) || nt.is(clang::tok::string_literal)) {
      break;
    }
  }

  // Switch to expansion.
  sub->use_nodes.swap(sub->nodes);

  return true;
}

MacroExpansionImpl *PatchedMacroTracker::DoPreExpansionSetup(
    MacroExpansionImpl *exp) {

  assert(!exp->use_nodes.empty());
  assert(exp->ident != nullptr);
  assert(exp->l_paren != nullptr);

  // Create a new expansion.
  MacroExpansionImpl *new_exp =
      &(ast->root_macro_node.expansions.emplace_back());
  new_exp->defined_macro = exp->defined_macro;

  if (std::holds_alternative<MacroNodeImpl *>(exp->definition)) {
    MacroDirectiveImpl *def = dynamic_cast<MacroDirectiveImpl *>(
        std::get<MacroNodeImpl *>(exp->definition));
    new_exp->definition = def;
    def->macro_uses.emplace_back(new_exp);
  }

  MacroTokenImpl *new_ident = exp->ident->Clone(*ast, new_exp);
  MacroTokenImpl *new_l_paren = exp->l_paren->Clone(*ast, new_exp);
  assert(exp->ident->token_offset < new_ident->token_offset);
  assert(exp->l_paren->token_offset < new_l_paren->token_offset);
  new_exp->nodes.push_back(new_ident);
  new_exp->nodes.push_back(new_l_paren);
  new_exp->ident = new_ident;
  new_exp->l_paren = new_l_paren;

//  MacroArgumentImpl *first_arg =
//      &(ast->root_macro_node.arguments.emplace_back());
//  first_arg->parent = new_exp;
//  first_arg->is_prearg_expansion = true;
//  new_exp->nodes.push_back(first_arg);
//  new_exp->arguments.push_back(first_arg);
//
//  ReparentNodes(std::move(exp->nodes), first_arg);
  ReparentNodes(std::move(exp->nodes), new_exp);

  exp->nodes.push_back(new_exp);
  exp->in_prearg_expansion = false;
  new_exp->is_prearg_expansion = true;
  new_exp->in_prearg_expansion = false;
  new_exp->parent = exp;
  new_exp->parent_for_prearg = exp;

  return new_exp;
}

// If we're in macro argument pre-expansion, and if we actually see a token,
// then we want to fake another expansion. To do so, that means copying in
// a few extra tokens (the macro use and call). Later, we'll detect that we
// did this, and then build out the expansion.
void PatchedMacroTracker::TryDoPreExpansionSetup(const clang::Token &tok) {
  for (MacroExpansionImpl *exp : expansions) {
    if (exp->in_prearg_expansion) {
      goto fixup;
    }
  }

  return;

fixup:

  std::vector<MacroNodeImpl *> new_nodes;
  std::vector<MacroExpansionImpl *> new_expansions;
//  std::vector<MacroArgumentImpl *> new_arguments;

  for (MacroNodeImpl *old_node : nodes) {
//    if (auto old_arg = dynamic_cast<MacroArgumentImpl *>(old_node)) {
//      new_arguments.push_back(old_arg);
//      new_nodes.push_back(old_node);
//
//    } else
    if (auto old_exp = dynamic_cast<MacroExpansionImpl *>(old_node)) {
      if (!old_exp->in_prearg_expansion) {
        new_expansions.push_back(old_exp);
        new_nodes.push_back(old_exp);
      } else {

        D( std::cerr << indent << "TryDoPreExpansionSetup\n"; )

        MacroExpansionImpl *new_exp = DoPreExpansionSetup(old_exp);
        assert(new_exp != old_exp);
        assert(new_exp->is_prearg_expansion);
        assert(!new_exp->in_prearg_expansion);
        assert(!old_exp->in_prearg_expansion);

        new_expansions.push_back(new_exp);
        new_nodes.push_back(new_exp);

//        assert(!new_exp->arguments.empty());
//        MacroArgumentImpl *new_arg = dynamic_cast<MacroArgumentImpl *>(
//            std::get<MacroNodeImpl *>(new_exp->arguments.front()));
//        new_arguments.push_back(new_arg);
//        new_nodes.push_back(new_arg);
      }
    } else {
      new_nodes.push_back(old_node);
    }
  }

  nodes = std::move(new_nodes);
  expansions = std::move(new_expansions);
//  arguments = std::move(new_arguments);
}

static MacroTokenImpl *FirstUseToken(const Node &node) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return std::get<MacroTokenImpl *>(node);
  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::get<MacroNodeImpl *>(node)->FirstUseToken();
  } else {
    return nullptr;
  }
}

// Inject a missing argument. This wraps `pre_exp->nodes.back()` in an
// argument node, then fixes up `nodes` and `arguments`.
static void InjectArgument(ASTImpl &ast, std::vector<MacroNodeImpl *> &nodes,
                           std::vector<MacroArgumentImpl *> &arguments,
                           MacroExpansionImpl *pre_exp) {
  MacroArgumentImpl *missing_arg =
      &(ast.root_macro_node.arguments.emplace_back());

  Node just_added_node = std::move(pre_exp->nodes.back());
  pre_exp->nodes.pop_back();
  ReparentNode(just_added_node, missing_arg);

  missing_arg->parent = pre_exp;
  missing_arg->is_prearg_expansion = pre_exp->is_prearg_expansion;
  missing_arg->index = static_cast<unsigned>(pre_exp->arguments.size());
  missing_arg->nodes.emplace_back(std::move(just_added_node));
  pre_exp->arguments.push_back(missing_arg);
  pre_exp->nodes.emplace_back(missing_arg);

  InjectArgumentNode(nodes, arguments, pre_exp, missing_arg);
}

// Inspect the last node in a pre-expanded macro, and try to wrap it in an
// argument node.
static void TryWrapLastNodeInArgument(
    ASTImpl &ast, std::vector<MacroNodeImpl *> &nodes,
    std::vector<MacroArgumentImpl *> &arguments,
    MacroExpansionImpl *pre_exp, const std::string &indent) {
  if (std::holds_alternative<MacroTokenImpl *>(pre_exp->nodes.back())) {
    auto last_tok = std::get<MacroTokenImpl *>(pre_exp->nodes.back());
    if (last_tok != pre_exp->ident &&
        last_tok != pre_exp->l_paren &&
        (last_tok->kind_flags.kind != TokenKind::kComma ||
         last_tok->kind_flags.is_ignored_comma)) {
      D( std::cerr << indent << "^ Adding missing argument for token\n"; )
      InjectArgument(ast, nodes, arguments, pre_exp);
    }

  } else if (std::holds_alternative<MacroNodeImpl *>(pre_exp->nodes.back())) {
    auto last_node = std::get<MacroNodeImpl *>(pre_exp->nodes.back());
    auto last_arg = dynamic_cast<MacroArgumentImpl *>(last_node);
    if (!last_arg) {
      D( std::cerr << indent << "^ Adding missing argument for node\n"; )
      InjectArgument(ast, nodes, arguments, pre_exp);

    } else {
      assert(last_arg->is_prearg_expansion);
      assert(std::get<MacroNodeImpl *>(last_arg->parent) == pre_exp);
    }
  }
}

// Pre-argument expansion for macros is funny. I think it applies at an
// argument granularity, rather than an "all arguments" granularity. For
// example:
//
//      #define ONE ....
//      #define FOO(a, b, c) ...
//      FOO(1, ONE, 2)
//
// Will trigger pre-expansion on `ONE` in the call to `FOO`, but the arguments
// `1` and `2` will not trigger any pre-expansion, and so they'll be invisible
// to us. To mitigate this issue, we go and search for missing things and then
// try to clone/inject them.
bool PatchedMacroTracker::ClonePrefixArguments(
    MacroExpansionImpl *pre_exp,
    const clang::Token &tok) {
  MacroExpansionImpl *exp = pre_exp->parent_for_prearg;
  if (!exp) {
    D( std::cerr << indent << " not a pre-expansion\n"; )
    return false;  // Not a pre-argument expansion.
  }

  // We've ended pre-argument expansion, and now are entering the macro
  // expansion itself.
  if (!pre_exp->use_nodes.empty()) {
    D( std::cerr << indent << " after pre-expansion done\n"; )
    return false;
  }

  assert(exp != pre_exp);
  assert(!exp->use_nodes.empty());
  assert(pre_exp->nodes.size() >= 2);  // name, (

  // Figure out if the last thing in this pre-expansion should actually be
  // nested inside of an argument.
  TryWrapLastNodeInArgument(*ast, nodes, arguments, pre_exp, indent);

//  D( std::cerr << indent << "* Starting Nth pre-arg expansion argument\n"; )
//
//  MacroExpansionImpl *exp = expansions.back();


  clang::SourceLocation tok_loc = tok.getLocation();
  assert(tok_loc.isValid());

  std::vector<const Node *> nodes_to_clone;

  // Find the index of the last matched thing.
  auto num_skipped = 0u;
  std::optional<unsigned> last_sep;
  auto matched = false;
  for (const Node &node : exp->use_nodes) {
    MacroTokenImpl *use_tok = FirstUseToken(node);
    if (!use_tok) {
      D( std::cerr << indent << " no token at " << num_skipped << '\n'; )
      ++num_skipped;
      continue;
    }

    const TokenImpl &parsed_tok = ast->tokens[use_tok->token_offset];
    D( std::cerr
          << indent
          << "! PRE_EXP: " << num_skipped << ' ' << parsed_tok.Data(*ast) << " "
          << parsed_tok.opaque_source_loc << " "
          << tok.getLocation().getRawEncoding() << '\n'; )

    if (tok_loc == parsed_tok.Location()) {
      matched = true;
      break;
    }

    ++num_skipped;

    switch (use_tok->kind_flags.kind) {
      case pasta::TokenKind::kLParenthesis:
        if (num_skipped == 2) {
          last_sep = num_skipped;
        }
        break;
      case pasta::TokenKind::kComma:
        if (2 < num_skipped && !use_tok->kind_flags.is_ignored_comma) {
          last_sep = num_skipped;
        }
        break;
      default:
        break;
    }
  }

  if (!matched) {
    D( std::cerr << indent << " no matched\n"; )
    return false;
  }

  // Pull off the last thing on the pre-expansion node if it doesn't have any
  // tokens in it.
  std::optional<Node> trailing_empty_node;
  if (!pre_exp->nodes.empty() && !FirstUseToken(pre_exp->nodes.back())) {
    D( std::cerr << indent << "- has trailing empty\n"; )
    trailing_empty_node.emplace(pre_exp->nodes.back());
    pre_exp->nodes.pop_back();
  }

  // Align on the left corners.
  auto max_i = std::min<size_t>(
      std::min(exp->use_nodes.size(), pre_exp->nodes.size()),
      num_skipped);

  // NOTE(pag): Start at `1` to skip over the macro name; it might itself
  //            be an expansion, and fail a later heuristic against matching
  //            against argument nodes.
  auto i = 1u;  // pre_exp
  auto j = 1u;  // exp

  D(
      std::cerr << indent << "Scanning: max_i=" << max_i;
      if (last_sep) {
        std::cerr << " last_sep=" << last_sep.value();
      }
      std::cerr << '\n';
  )
  for (; i < max_i && j < max_i; ) {
    Node i_node = pre_exp->nodes[i];
    Node j_node = exp->use_nodes[j];

    // E.g. an argument already cloned from the pre-expansion.
    if (std::holds_alternative<MacroNodeImpl *>(j_node) &&
        std::holds_alternative<MacroNodeImpl *>(i_node)) {
      auto curr_impl = std::get<MacroNodeImpl *>(i_node);
      auto prev_impl = std::get<MacroNodeImpl *>(j_node);
      if (curr_impl->cloned_from == prev_impl) {
        ++i;
        ++j;
        continue;
      }
    }

    MacroTokenImpl *curr_tok = FirstUseToken(i_node);
    MacroTokenImpl *prev_tok = FirstUseToken(j_node);

    if (!curr_tok) {
      assert(false);
      ++i;
      continue;
    }

    if (!prev_tok) {
      assert(false);
      ++j;
      continue;
    }

    const TokenImpl &i_tok = ast->tokens[curr_tok->token_offset];
    const TokenImpl &j_tok = ast->tokens[prev_tok->token_offset];
    D( std::cerr
          << indent
          << "- i=" << i << " j=" << j << " i_data=" << i_tok.Data(*ast)
          << " j_data=" << j_tok.Data(*ast) << '\n'; )

    const auto curr_loc = i_tok.opaque_source_loc;
    const auto prev_loc = j_tok.opaque_source_loc;
    if (curr_loc == prev_loc) {
      ++i;
      ++j;
      continue;
    }

    D( std::cerr << indent << "* i=" << i << " j="
                 << j << " num_skipped=" << num_skipped << '\n'
                 << indent << "  i_loc=" << i_tok.opaque_source_loc << "\n"
                 << indent << "  j_loc=" << j_tok.opaque_source_loc << "\n"; )
    break;
  }

  // Close out the last argument before injecting anything. This might close
  // out other things.
  if (!trailing_empty_node && !arguments.empty() &&
      arguments.back()->is_prearg_expansion &&
      std::get<MacroNodeImpl *>(arguments.back()->parent) == pre_exp) {
    D( std::cerr << indent << " closing last argument\n"; )
    MacroArgumentImpl *last_arg = arguments.back();
    Node last_arg_node(last_arg);
    assert(std::holds_alternative<MacroNodeImpl *>(last_arg->parent));
    assert(pre_exp == std::get<MacroNodeImpl *>(last_arg->parent));

    MacroNodeImpl *last_node = nullptr;
    std::vector<MacroNodeImpl *> popped_nodes;

    while (nodes.back() != last_arg) {
      last_node = nodes.back();
      assert(last_node != pre_exp);
      assert(last_node != exp);
      popped_nodes.emplace_back(last_node);
      nodes.pop_back();
    }

    // Pop off the argument.
    assert(nodes.back() == last_arg);
    nodes.pop_back();
    arguments.pop_back();
    assert(nodes.back() == pre_exp);

    // Something extra was added to the last argument; we need to take it
    // out.
    if (last_node) {
      assert(!last_arg->nodes.empty());
      assert(std::holds_alternative<MacroNodeImpl *>(last_arg->nodes.back()));
      assert(std::get<MacroNodeImpl *>(last_arg->nodes.back()) == last_node);

      D( std::cerr << indent
                   << " - converting extra argument node for trailer\n"; );
      Node node_for_next_arg = std::move(last_arg->nodes.back());
      last_arg->nodes.pop_back();
      ReparentNode(node_for_next_arg, pre_exp);

      assert(nodes.back() == pre_exp);

      // Add to the pre-expansion. If it isn't wrapped in an argument, then
      // call `InjectArgument` to wrap it.
      if (!AddToParentNode(std::move(node_for_next_arg))) {
        D( std::cerr << indent << "^ Adding missing argument for token\n"; )
        InjectArgument(*ast, nodes, arguments, pre_exp);
      }

      // Add any others back in.
      for (MacroNodeImpl *popped_node : popped_nodes) {
        nodes.push_back(popped_node);
      }

      // Now pop it off and let it get re-added later, because we need to
      // possibly inject things before it.
      trailing_empty_node.emplace(pre_exp->nodes.back());
      pre_exp->nodes.pop_back();
    }
  }

  // Fill what was missing.
  for (; j < num_skipped; ++j) {
    const Node &node = exp->use_nodes[j];
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
      MacroTokenImpl *tok_clone = tok->Clone(*ast, pre_exp);
      assert(tok->token_offset < tok_clone->token_offset);
      D( TokenImpl &ast_tok = ast->tokens[tok->token_offset]; )
      D( std::cerr << indent << " adding missing token "
                   << ast_tok.opaque_source_loc << ' '
                   << ast_tok.Data(*ast) << '\n'; )
      pre_exp->nodes.emplace_back(tok_clone);

    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
      MacroNodeImpl *cloned_node =
          std::get<MacroNodeImpl *>(node)->Clone(*ast, pre_exp);

      D(
        MacroTokenImpl *cloned_lc = FirstUseToken(cloned_node);
        std::cerr << indent << " adding missing node";
        if (cloned_lc) {
          TokenImpl &ast_tok = ast->tokens[cloned_lc->token_offset];
          std::cerr << ' ' << ast_tok.opaque_source_loc << ' '
                    << ast_tok.Data(*ast);
        }
        std::cerr << '\n';
      )

      if (auto cloned_arg = dynamic_cast<MacroArgumentImpl *>(cloned_node)) {
        pre_exp->arguments.emplace_back(cloned_arg);
      }

      pre_exp->nodes.emplace_back(cloned_node);

    } else {
      assert(false);
    }
  }

  if (trailing_empty_node) {
    D( std::cerr << indent << " re-adding empty argument/expansion\n"; )
    pre_exp->nodes.emplace_back(std::move(trailing_empty_node.value()));
  }

  return true;
}

static int ParenCount(MacroNodeImpl *arg) {
  int paren_count = 0;
  for (const Node &node : arg->nodes) {
    if (std::holds_alternative<MacroNodeImpl *>(node)) {
      paren_count += ParenCount(std::get<MacroNodeImpl *>(node));
    } else if (std::holds_alternative<MacroTokenImpl *>(node)){
      MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
      if (tok->kind_flags.kind == TokenKind::kLParenthesis) {
        ++paren_count;
      } else if (tok->kind_flags.kind == TokenKind::kRParenthesis) {
        --paren_count;
      }
    }
  }
  return paren_count;
}

// Change the stored raw location if this is a macro token, so that it
// points to where it originated from.
void PatchedMacroTracker::FixupDerivedLocations(void) {

  auto from_map = [=] (
      const std::unordered_map<OpaqueSourceLoc, DerivedTokenIndex> &map,
      TokenImpl &tok, DerivedTokenIndex tok_index, std::string_view tok_data,
      OpaqueSourceLoc loc) {
    auto it = map.find(loc);
    if (it == map.end()) {
      return false;
    }

    // Sanity check that we're mapping a derived token to the original token
    // that shares the same data.
    DerivedTokenIndex orig_tok_index = it->second;
    assert(orig_tok_index < tok_index);
    const TokenImpl &orig_tok = ast->tokens[orig_tok_index];
    if (orig_tok.Data(*ast) != tok_data) {
      return false;
    }

    assert(!!orig_tok_index);
    tok.derived_index = orig_tok_index;
    return true;
  };

  macro_token_refs.clear();

  DerivedTokenIndex max_i = static_cast<DerivedTokenIndex>(ast->tokens.size());
  for (DerivedTokenIndex tok_index = start_of_macro_index;
       tok_index < max_i; ++tok_index) {

    last_fixed_index = tok_index;

    TokenImpl &tok = ast->tokens[tok_index];
    assert(tok.HasMacroRole());

    const std::string_view data = tok.Data(*ast);
    const clang::SourceLocation loc = tok.Location();
    const OpaqueSourceLoc raw_loc = loc.getRawEncoding();

//     std::cerr << "role=" << int(tok.Role()) << " file=" << loc.isFileID() << " raw_loc=" << raw_loc << " -> tok_index=" << tok_index << '\n';

    if (!loc.isValid()) {
      assert(tok.Role() == TokenRole::kEndOfMacroExpansionMarker);
      continue;
    }

    // If we have a file token, then we could be in a define or other directive,
    // in the first tokens of a use of a macro, or in the pre-expansion phase
    // of a macro.
    if (loc.isFileID()) {
      switch (tok.Role()) {
        case TokenRole::kBeginOfMacroExpansionMarker:
        case TokenRole::kEndOfMacroExpansionMarker:
          continue;
        default:
          if (!from_map(file_token_refs, tok, tok_index, data, raw_loc)) {
//            std::cerr << "  A mapping raw_loc=" << raw_loc << " to index=" << tok_index << " -> " << tok.derived_index  << '\n';
            file_token_refs[raw_loc] = tok_index;
          } else {
//            std::cerr << "  B Didn't map index=" << tok_index << " -> " << tok.derived_index  << "; not sure\n";
          }
          assert(tok.Location().isFileID());
          continue;
      }
    }

    if (!loc.isMacroID()) {
      assert(false);  // Doesn't make sense.
      continue;
    }

    // For some pre-expansions, we need to copy the expanded tokens, so we want
    // to link back to those.
    if (from_map(macro_token_refs, tok, tok_index, data, raw_loc)) {
      macro_token_refs[raw_loc] = tok_index;
//      std::cerr << "  C mapping raw_loc=" << raw_loc << " to index=" << tok_index << " -> " << tok.derived_index << '\n';
      continue;
    }

    // Try to go one level up in the macro expansion to find the token's
    // ancestry.
    const clang::SourceLocation next_loc = sm.getImmediateSpellingLoc(loc);
    if (!next_loc.isValid()) {
//      std::cerr << "  D Didn't map index=" << tok_index<< " -> " << tok.derived_index  << "; invalid next loc\n";
      continue;
    }

    const OpaqueSourceLoc next_raw_loc = next_loc.getRawEncoding();
    if (from_map(file_token_refs, tok, tok_index, data, next_raw_loc) ||
        from_map(macro_token_refs, tok, tok_index, data, next_raw_loc)) {
      macro_token_refs[raw_loc] = tok_index;
//      std::cerr << "  E mapping raw_loc=" << raw_loc << " to index=" << tok_index<< " -> " << tok.derived_index  << '\n';
      continue;
    }


//    std::cerr << "  F Didn't map index=" << tok_index << " -> " << tok.derived_index  << '\n';
  }
}

// Add something to the end of `nodes.back()->nodes`.
//
// Returns `true` if adding to the parent node ended up wrapping this thing
// in an argument.
bool PatchedMacroTracker::AddToParentNode(Node node) {
  MacroExpansionImpl *exp = dynamic_cast<MacroExpansionImpl *>(nodes.back());

  nodes.back()->nodes.push_back(node);

  // Figure out if we need to wrap `node` in a `MacroArgumentImpl`.
  if (exp && exp->use_nodes.empty() && !exp->is_cancelled) {
    if (std::holds_alternative<MacroNodeImpl *>(node)) {
      auto child = std::get<MacroNodeImpl *>(node);
      if (!dynamic_cast<MacroArgumentImpl *>(child)) {
        InjectArgument(*ast, nodes, arguments, exp);
        return true;
      }
#ifndef NDEBUG
    } else if (std::holds_alternative<MacroTokenImpl *>(node)) {
      auto child = std::get<MacroTokenImpl *>(node);
      TokenImpl tok = ast->tokens[child->token_offset];
      switch (tok.Kind()) {
        case clang::tok::identifier:
        case clang::tok::raw_identifier:
          assert(nodes.back()->nodes.empty());
          break;
        case clang::tok::l_paren:
        case clang::tok::r_paren:
        case clang::tok::comma:
          break;
        default:
          assert(false);
          InjectArgument(*ast, nodes, arguments, exp);
          return true;
      }
    } else {
      assert(false);
#endif
    }
  }
  return false;
}

std::optional<clang::Token> PatchedMacroTracker::FindDirectiveHash(
    const clang::Token &tok) {

  clang::SourceLocation directive_loc = tok.getLocation();
  if (directive_loc.isInvalid() || !directive_loc.isFileID()) {
    return std::nullopt;
  }

  D( std::cerr << indent << "Trying to add missing directive hash\n"; )

  bool invalid = false;
  clang::SourceManager &sm = ast->ci->getSourceManager();
  auto [file_id, file_offset] = sm.getDecomposedLoc(directive_loc);
  llvm::StringRef file_data = sm.getBufferData(file_id, &invalid);
  if (invalid) {
    return std::nullopt;
  }

  llvm::StringRef kw = file_data.substr(file_offset);
  if (!(kw.startswith_insensitive("if") ||
        kw.startswith_insensitive("ifdef") ||
        kw.startswith_insensitive("ifndef") ||
        kw.startswith_insensitive("elif") ||
        kw.startswith_insensitive("elifdef") ||
        kw.startswith_insensitive("elifndef") ||
        kw.startswith_insensitive("else") ||
        kw.startswith_insensitive("endif"))) {
    D( std::cerr << indent << "Not adding hash; wrong keyword\n"; )
    return std::nullopt;
  }

  // Scan backwards through the file buffer from the start of the macro token
  // that was undefined, hoping to find the `#` of the directive. If we find
  // it, then emit an injected token.
  clang::SourceLocation hash_loc;
  for (int loc_offset = 0; file_offset; --loc_offset) {
    if (file_data[file_offset--] == '#') {
      hash_loc = directive_loc.getLocWithOffset(loc_offset);
      break;
    }
  }

  clang::Token hash_tok;
  hash_tok.startToken();
  hash_tok.setKind(clang::tok::hash);
  hash_tok.setLocation(hash_loc);

  if (hash_loc.isInvalid()) {
    if (skipped_hash.getLocation().isValid()) {
      hash_tok = std::move(skipped_hash);
      skipped_hash.startToken();
    } else {
      D( std::cerr << indent << "Didn't find directive hash\n"; )
      return std::nullopt;
    }
  }

  return hash_tok;
}

// Add a token in.
//
// NOTE(pag): This might change `nodes.back()`.
void PatchedMacroTracker::DoToken(const clang::Token &tok_, uintptr_t data) {

  // Get the token data, and add the data to the AST's backup region, and a
  // empty newline to the normal token data, so that the 1:1 mapping between
  // line numbers in parsed source locations and tokens recorded matches up.
  clang::Token tok = tok_;
  clang::SourceLocation tok_loc = tok.getLocation();
  std::string &tok_data = tok_data_vec[next_tok_data++ % tok_data_vec.size()];
  tok_data.clear();
  if (TryReadRawToken(sm, lo, tok, &tok_data)) {
    SkipLeadingWhitspace(tok, tok_loc, tok_data);
  }

  // When we're skipping tokens, we still want to record stuff for
  // conditional directives.
  auto skip = macro_skip_count || cond_skip_depth || 1u == nodes.size();

  // We want to skip tokens *between* disabled conditional directives, but
  // not *inside* directives.
  if (!directives.empty()) {
    skip = false;
  }

  if (tok.isOneOf(clang::tok::eod, clang::tok::eof)) {
    skip = true;
  }

  last_token_was_added = false;

  skipped_hash.startToken();
  if (tok_loc == last_token.getLocation() &&
      tok.getKind() == last_token.getKind() &&
      tok.isAnnotation() == last_token.isAnnotation() &&
      tok.isAnyIdentifier() == last_token.isAnyIdentifier() &&
      tok.getFlags() == last_token.getFlags()) {

    if (tok.is(clang::tok::hash)) {
      skipped_hash = tok;
    }

    D( std::cerr << indent << "(not adding repeat token " << clang::tok::getTokenName(tok.getKind()) << ")\n"; )
    return;  // It's a repeat?
  }

  // NOTE(pag): `skip_count` tells us if we're inside of a cancelled macro.
  if (skip) {
    auto raw_tok_loc = tok_loc.getRawEncoding();
    auto real_tok_it = end_of_arg_toks.find(raw_tok_loc);
    if (real_tok_it != end_of_arg_toks.end()) {
      D( std::cerr << indent << "(recovering real token " << clang::tok::getTokenName(real_tok_it->second.getKind()) << ")\n"; )
      clang::Token real_tok = real_tok_it->second;
      end_of_arg_toks.erase(raw_tok_loc);  // Prevent infinite recursion.
      DoToken(real_tok, data);
      end_of_arg_toks[raw_tok_loc] = real_tok;
      return;
    }

    D( std::cerr << indent << "(not adding skipped/top-level/eod/eof token " << clang::tok::getTokenName(tok.getKind()) << ")\n"; )
    CloseUnclosedExpansion(tok);
    return;
  }

  // NOTE(pag): This might change `nodes.back()`.
  TryDoPreExpansionSetup(tok);

  // The pre-expansion may have been triggered part-way through the argument
  // list of `last_old_exp`, so we may need to copy/clone some arguments over.
  if (!expansions.empty() && nodes.back() == expansions.back()) {
    for (auto i = expansions.size(); i >= 1u; ) {
      if (ClonePrefixArguments(expansions[--i], tok)) {
        break;
      }
    }
  }

  // With header names, we don't observe the lexing of the individual tokens.
  auto substituted_header_name = TryExtractHeaderName(tok);

  const auto offset = ast->backup_token_data.size();
  backup_token_data_stream << tok_data;
  backup_token_data_stream.flush();
  token_data_stream << '\n';
  token_data_stream.flush();
  ast->num_lines++;

  MacroNodeImpl *parent_node = nodes.back();

  // Add the token to the AST.
  size_t tok_index = ast->tokens.size();

  auto role = TokenRole::kIntermediateMacroExpansionToken;
  if (tok_loc.isValid() && tok_loc.isFileID()) {
    role = TokenRole::kInitialMacroUseToken;
  }
  ast->AppendBackupToken(tok, offset, tok_data.size(), role);

  TokenImpl &added_tok = ast->tokens.back();
  MacroTokenImpl *tok_node = &(ast->root_macro_node.tokens.emplace_back());
  tok_node->token_offset = static_cast<uint32_t>(tok_index);
  assert(tok_node->token_offset == tok_index);
  tok_node->parent = parent_node;

  // Clear out the kind, so that it looks `unknown` from the perspective of
  // `ASTImpl::AlignTokens`. We add it back in later after token alignment
  // via `ASTImpl::LinkMacroTokenContexts`.
  tok_node->kind_flags.kind = static_cast<TokenKind>(added_tok.Kind());
  tok_node->kind_flags.is_ignored_comma =
      tok.getFlag(clang::Token::IgnoredComma);
  added_tok.kind = 0;

  // Add the token to the node.
  parent_node->nodes.push_back(tok_node);
  last_token_was_added = true;
  last_token = tok;

  // Close the substitution.
  if (substituted_header_name) {
    nodes.pop_back();
  }

  // Go try and find the macro identifier and opening parenthesis for this node.
  // Pre-argument expansion happens on the argument nodes after they have been
  // lexed, but before the macro is entered. So it's a token lexer that operates
  // "independent" of the macro call context. We want to simulate the appearance
  // of the macro call so we go and find the `ident(` of the original expansion.
  if (!expansions.empty() && parent_node == expansions.back()) {
    MacroExpansionImpl *exp = expansions.back();
    if (tok_node->kind_flags.kind == TokenKind::kIdentifier && !exp->ident) {
      exp->ident = tok_node;

    } else if (tok_node->kind_flags.kind == TokenKind::kLParenthesis &&
               exp->ident && !exp->l_paren) {
      exp->l_paren = tok_node;
    }

    // If we're in a pre-expansion, and we just added a token, but not into an
    // argument, then we need to add the argument for this node.
    if (exp->is_prearg_expansion && !exp->done_prearg_expansion &&
        (!tok.is(clang::tok::comma) ||
         tok.getFlag(clang::Token::IgnoredComma))) {

      D( std::cerr << indent << " * Reparenting token into missing argument\n"; )
      InjectArgument(*ast, nodes, arguments, exp);

      parent_node = nodes.back();
    }
  }

  // If we're in a macro argument pre-expansion phase, then we need to manually
  // split the arguments by commas.
  if (tok.is(clang::tok::comma) && !tok.getFlag(clang::Token::IgnoredComma) &&
      !arguments.empty()) {

    assert(!expansions.empty());
    MacroExpansionImpl *exp = expansions.back();
    MacroArgumentImpl *arg = arguments.back();

    if (parent_node == arg && arg->is_prearg_expansion &&
        !exp->done_prearg_expansion && !ParenCount(arg)) {

      // Move the comma out of the argument and into to the expansion.
      assert(!arg->nodes.empty());
      Node comma = std::move(arg->nodes.back());

      // Keep track of argument separators.
      end_of_arg_toks.emplace(tok_loc.getRawEncoding(), tok);

      D( std::cerr
             << indent << "* Splitting pre-arg data at comma "
             << ast->tokens[std::get<MacroTokenImpl *>(comma)->token_offset].opaque_source_loc
             << '\n'; )

      arg->nodes.pop_back();
      ReparentNode(comma, exp);
      exp->nodes.emplace_back(std::move(comma));

      MacroArgumentImpl *new_arg =
          &(ast->root_macro_node.arguments.emplace_back());
      new_arg->is_prearg_expansion = true;
      new_arg->index = arg->index + 1u;
      new_arg->parent = exp;
      exp->arguments.push_back(new_arg);

      // Add the new argument into the expansion, and change the active node
      // and argument.
      exp->nodes.push_back(new_arg);
      arguments.back() = new_arg;
      nodes.back() = new_arg;

      ClonePrefixArguments(exp, tok);
    }
  }
}

void ASTImpl::LinkMacroTokenContexts(void) {
  root_macro_node.token_nodes.reserve(root_macro_node.tokens.size());

  auto i = 0u;
  for (MacroTokenImpl &mt : root_macro_node.tokens) {
    TokenImpl &tok = tokens[mt.token_offset];

#ifndef NDEBUG
    switch (tok.Role()) {
      case TokenRole::kInitialMacroUseToken:
      case TokenRole::kIntermediateMacroExpansionToken:
      case TokenRole::kFinalMacroExpansionToken:
        break;
      default:
        assert(false);
        continue;  // Skip it. `TokenImpl::Context` isn't expecting this.
    }
#endif

    root_macro_node.token_nodes.emplace_back(&mt);
    tok.kind = static_cast<TokenKindBase>(mt.kind_flags.kind);
    mt.token_context = tok.context_index;
    tok.context_index = i;
    ++i;
  }
}

// This is a strange event, because it starts in one place, and where it ends
// could be the signalling of an unskipped area.
void PatchedMacroTracker::DoBeginSkippedArea(
    const clang::Token &tok, uintptr_t data) {

  // We're entering into the skipped area. Eventually we will come across a
  // token, such as `if`, `ifdef`, `ifndef` that will bring us deeper, or
  // `elif`, `elifdef`, `elifndef`, or `else` that may or may not be skipped,
  // but should be recorded, or `endif` that pulls us out of a skipped area.
  if (tok.is(clang::tok::hash)) {
    if (last_directive) {
      switch (last_directive->kind) {
        case MacroDirectiveKind::kIf:
        case MacroDirectiveKind::kIfDefined:
        case MacroDirectiveKind::kIfNotDefined:
        case MacroDirectiveKind::kElseIf:
        case MacroDirectiveKind::kElseIfDefined:
        case MacroDirectiveKind::kElseIfNotDefined:
        case MacroDirectiveKind::kElse:
        case MacroDirectiveKind::kEndIf:
          last_directive->is_skipped = true;
          break;
        default:
          assert(false);
          return;
      }
    }

    if (!cond_skip_depth) {
      cond_skip_depth = 1;
    }
    suppress_indent = true;

  // We're nested inside of a skipped region, and this is logically a
  // conditional macro directive that we need to record.
  } else if (tok.is(clang::tok::raw_identifier)) {

    assert(cond_skip_depth >= 0);
    if (!cond_skip_depth) {
      cond_skip_depth = 1;
    }

    MacroDirectiveKind kind = MacroDirectiveKind::kOther;
    llvm::StringRef ident = tok.getRawIdentifier();

    if (ident == "if") {
      ++cond_skip_depth;
      kind = MacroDirectiveKind::kIf;
    } else if (ident == "ifdef") {
      ++cond_skip_depth;
      kind = MacroDirectiveKind::kIfDefined;
    } else if (ident == "ifndef") {
      ++cond_skip_depth;
      kind = MacroDirectiveKind::kIfNotDefined;
    } else if (ident == "elif") {

      // See if we should reset the skip depth, because we might evaluate the
      // next condition differently.
      //
      // Elif is the only event that has a non-trivial body form. The other
      // elif-like events all end up having some kind of trivial true/false
      // evaluation, that makes us not want to alter the skip depth here.
      if (1 == cond_skip_depth && last_directive &&
          last_directive->is_skipped) {
        D( std::cerr << indent << "Resetting skip depth\n"; )
        cond_skip_depth = 0;
      }

      kind = MacroDirectiveKind::kElseIf;
    } else if (ident == "elifdef") {
      kind = MacroDirectiveKind::kElseIfDefined;
    } else if (ident == "elifndef") {
      kind = MacroDirectiveKind::kElseIfNotDefined;
    } else if (ident == "else") {
      kind = MacroDirectiveKind::kElse;
    } else if (ident == "endif") {
      --cond_skip_depth;
      kind = MacroDirectiveKind::kEndIf;
    } else {
      suppress_indent = true;
      D( std::cerr << "Ignoring directive '"
                   << std::string_view(ident.data(), ident.size()) << "'\n"; )
      return;
    }

    auto hash_tok = FindDirectiveHash(tok);
    if (!hash_tok) {
      assert(false);
      suppress_indent = true;
      return;
    }

    D( std::cerr << indent << "Adding skipped directive\n"; )
    DoBeginDirective(*hash_tok, data);
    DoToken(tok, 0);
    DoSetNamedDirective(tok, 0);
    directives.back()->kind = kind;
    directives.back()->is_skipped = true;
  }
}

void PatchedMacroTracker::DoBeginDirective(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);
  MacroDirectiveImpl *directive =
      &(ast->root_macro_node.directives.emplace_back());
  AddToParentNode(directive);
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
  if (!cond_skip_depth) {
    if (std::holds_alternative<MacroTokenImpl *>(directive->nodes.back())) {
      directive->directive_name = directive->nodes.back();
    } else {
      assert(false);
    }
  }
}

void PatchedMacroTracker::DoEndNonDirective(const clang::Token &tok,
                                            uintptr_t) {
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
  Pop(tok);
  last_directive = nullptr;
}

void PatchedMacroTracker::DoEndDirective(
    const clang::Token &tok, uintptr_t data) {
  assert(!directives.empty());
  assert(nodes.back() == directives.back());
  assert(!directives.back()->nodes.empty());
  if (!last_directive ||
      directives.back()->kind == MacroDirectiveKind::kOther /* e.g. define */ ||
      !last_directive->is_skipped  /* It's a conditional */) {
    last_directive = directives.back();
  }
  nodes.pop_back();
  directives.pop_back();
  Pop(tok);
}

void PatchedMacroTracker::DoBeginMacroExpansion(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);  // TODO(pag): Which token to pop?

  MacroExpansionImpl *expansion =
      &(ast->root_macro_node.expansions.emplace_back());
  AddToParentNode(expansion);
  expansion->parent = nodes.back();
  nodes.push_back(expansion);
  expansions.push_back(expansion);
  DoToken(tok, data);

  // Link up the expansion with the definition. `data` might be zero in the
  // case of `_Pragma`.
  clang::MacroInfo *mi = reinterpret_cast<clang::MacroInfo *>(data);
  expansion->defined_macro = mi;
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
    assert(0 < macro_skip_count);
    return;
  }

  MacroArgumentImpl *argument =
      &(ast->root_macro_node.arguments.emplace_back());
  argument->index = static_cast<unsigned>(expansion->arguments.size());
  argument->parent = expansion;

  AddToParentNode(argument);  // Adds to `expansion`.
  expansion->arguments.emplace_back(argument);
  nodes.push_back(argument);
  arguments.push_back(argument);
}

void PatchedMacroTracker::DoEndMacroCallArgument(
    const clang::Token &tok, uintptr_t) {

  // Keep track of argument separators.
  end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);

  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
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
  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
  }
}

void PatchedMacroTracker::DoBeginPreArgumentExpansion(
    const clang::Token &, uintptr_t data) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  clang::MacroInfo *macro_info = reinterpret_cast<clang::MacroInfo *>(data);
  MacroExpansionImpl *expansion = expansions.back();
  assert(!expansion->in_prearg_expansion);
  assert(expansion->defined_macro == macro_info);

  expansion->in_prearg_expansion = true;
  (void) macro_info;

  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
    return;
  }
}

void PatchedMacroTracker::DoEndPreArgumentExpansion(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();

  // This node was marked for pre-argument expansion, but we're still in that
  // state so it meant that nothing really happened.
  if (expansion->in_prearg_expansion) {
    assert(nodes.back() == expansions.back());
    assert(expansion->nodes.empty());
    assert(!expansion->is_prearg_expansion);
    expansion->in_prearg_expansion = false;
    return;
  }

  // This node is a pre-argument expansion invented expansion, so we need to
  // inject in a closing parenthesis to complete it. We may also need to inject
  // any arguments that should have preceded the `)` but didn't trigger any
  // pre-expansion.
  assert(expansion->is_prearg_expansion);
  expansion->done_prearg_expansion = true;

  // Possibly add in any trailing missing tokens/nodes in before we inject
  // the trailing `)`. This can happen, e.g. `FOO(1, ONE, 2)` where `ONE`
  // will get pre-expanded, but `2` will not be seen, and so we add it in
  // here as a prefix to the `)`.

  // Get the original use, prior to pre-argument expansion.
  assert(expansion->parent_for_prearg != nullptr);
  MacroExpansionImpl *parent_exp = expansion->parent_for_prearg;
  assert(!parent_exp->use_nodes.empty());

  // Go find the `r_paren` for the parent and record it, as well at the index
  // at which it occurs.
  MacroTokenImpl *r_paren = nullptr;
  unsigned r_paren_index = 0u;
  const size_t num_parent_exp_nodes = parent_exp->use_nodes.size();
  int paren_count = 0;

  for (; r_paren_index < num_parent_exp_nodes; ++r_paren_index) {
    const Node &node = parent_exp->use_nodes[r_paren_index];
    MacroTokenImpl *tok = nullptr;
    if (std::holds_alternative<MacroTokenImpl *>(node)) {
      tok = std::get<MacroTokenImpl *>(node);
    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
      auto impl = std::get<MacroNodeImpl *>(node);
      auto sub_count = ParenCount(impl);
      if (!sub_count) {
        continue;

      // TODO(pag): Probably not quite right.
      } else {
        assert(1 == sub_count);
        tok = impl->FirstExpansionToken();
      }
    } else {
      assert(false);
      continue;
    }

    if (!tok) {
      continue;
    }

    if (tok->kind_flags.kind == TokenKind::kLParenthesis) {
      ++paren_count;
    } else if (tok->kind_flags.kind == TokenKind::kRParenthesis) {
      if (!--paren_count) {
        r_paren = tok;
        break;
      }
    }
  }
  assert(parent_exp->r_paren == nullptr);
  assert(r_paren != nullptr);
  parent_exp->r_paren = r_paren;
  parent_exp->r_paren_index = r_paren_index;

  TokenImpl r_paren_tok = ast->tokens[r_paren->token_offset];

  clang::Token tok;
  tok.startToken();
  tok.setLength(clang::tok::r_paren);
  tok.setLocation(r_paren_tok.Location());
  ClonePrefixArguments(expansion, tok);

  // At this point, we should always have at least one argument in the
  // macro pre-expansion. It may or may not be on the stack, depending on
  // `ClonePrefixArguments`.
  assert(!expansion->arguments.empty());
  if (!arguments.empty() && nodes.back() == arguments.back()) {
    assert(std::get<MacroNodeImpl *>(nodes.back()->parent) == expansion);
    arguments.pop_back();
    nodes.pop_back();
  }

  // We should now be looking at the expansion.
  assert(nodes.back() == expansion);
  if (expansion->is_cancelled) {
    assert(0 < cond_skip_depth);
    return;
  }

  // Add the last node of the pre-argument expansion macro use, which is the
  // cloned `r_paren`.
  expansion->r_paren = r_paren->Clone(*ast, expansion);
  assert(r_paren->token_offset < expansion->r_paren->token_offset);
  expansion->r_paren_index = static_cast<unsigned>(expansion->nodes.size());
  expansion->nodes.emplace_back(expansion->r_paren);

  // Add everything after the `r_paren`. If we have an expansion like
  // `FOO(A, B, C)(X, Y, Z)`, then we technically don't know if `FOO(A, B, C)`
  // will actually expand to a macro or not, but it ends up being very confusing
  // in the graph to have an expansion of `FOO(A, B, C)(X, Y, Z)` lead to an
  // isolated pre-expansion of `FOO(A, B, C)` to `BAR`, and then that turn into
  // an expansion like `BAR(X, Y, Z)`. The `(X, Y, Z)` tokens "disappear" then
  // suddenly "re-appear" in a later sub-tree.
  for (++r_paren_index; r_paren_index < num_parent_exp_nodes;
       ++r_paren_index) {
    D( std::cerr << indent << " > adding post-r_paren trailing token\n"; )
    const Node &trailing_node = parent_exp->nodes[r_paren_index];
    assert(expansion != parent_exp);
    if (std::holds_alternative<MacroTokenImpl *>(trailing_node)) {
      MacroTokenImpl *trailing_tok = std::get<MacroTokenImpl *>(trailing_node);
      MacroTokenImpl *trailing_tok_clone = trailing_tok->Clone(*ast, expansion);
      assert(trailing_tok->token_offset < trailing_tok_clone->token_offset);
      expansion->nodes.emplace_back(trailing_tok_clone);

    } else if (std::holds_alternative<MacroNodeImpl *>(trailing_node)) {
      expansion->nodes.emplace_back(
          std::get<MacroNodeImpl *>(trailing_node)->Clone(*ast, expansion));
    }
  }

  // Swap the nodes to use nodes.
  assert(!expansion->nodes.empty());
  expansion->nodes.swap(expansion->use_nodes);
}

void PatchedMacroTracker::DoSwitchToExpansion(
    const clang::Token &, uintptr_t data) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());
  assert(!expansion->in_prearg_expansion);
  assert(!expansion->is_prearg_expansion);

  if (auto mi = reinterpret_cast<clang::MacroInfo *>(data)) {
    assert(mi == expansion->defined_macro);
  }

  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
    expansion->nodes.clear();
  } else {
    expansion->nodes.swap(expansion->use_nodes);
  }
}

void PatchedMacroTracker::DoPrepareToCancelExpansion(
    const clang::Token &, uintptr_t) {
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());
  assert(!expansion->is_cancelled);
  expansion->is_cancelled = true;
  ++macro_skip_count;
  auto removed = false;

  // Go get rid of the tokens that were added as part of this expansion.
  while (!expansion->nodes.empty()) {
    Node to_remove = std::move(expansion->nodes.back());
    expansion->nodes.pop_back();

    // There's a sub-node. I don't know why, but go pop its tokens off too.
    if (std::holds_alternative<MacroNodeImpl *>(to_remove)) {
      MacroNodeImpl *node_to_remove = std::get<MacroNodeImpl *>(to_remove);

      if (auto sub_exp = dynamic_cast<MacroSubstitutionImpl *>(node_to_remove)) {
        for (Node &sub_node : sub_exp->use_nodes) {
          expansion->nodes.emplace_back(std::move(sub_node));
        }
      }
      for (Node &sub_node : node_to_remove->nodes) {
        expansion->nodes.emplace_back(std::move(sub_node));
      }

      node_to_remove->nodes.clear();

    // Pop this token off. We want to eliminate it from the end of the token
    // list.
    } else if (std::holds_alternative<MacroTokenImpl *>(to_remove)) {
      MacroTokenImpl *tok_to_remove = std::get<MacroTokenImpl *>(to_remove);
      if ((tok_to_remove->token_offset + 1u) == ast->tokens.size()) {
        assert(ast->preprocessed_code.back() == '\n');
        ast->preprocessed_code.pop_back();
        ast->tokens.pop_back();
        ast->num_lines -= 1u;
        removed = true;
        assert(start_of_macro_index < ast->tokens.size());

        assert(tok_to_remove == &(ast->root_macro_node.tokens.back()));
        ast->root_macro_node.tokens.pop_back();

      } else {
        assert(false);
      }
    }
  }

  if (removed) {
    last_token.startToken();
    last_token_was_added = false;
  }
}

void PatchedMacroTracker::DoCancelExpansion(const clang::Token &tok,
                                            uintptr_t) {
  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  Pop(tok);
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
    assert(0 < macro_skip_count);
    --macro_skip_count;
  } else {
    assert(!expansion->is_cancelled);
    expansion->is_cancelled = true;
  }
}

void PatchedMacroTracker::DoEndMacroExpansion(
    const clang::Token &tok, uintptr_t data) {

  assert(start_of_macro_index < ast->tokens.size());

  auto num_expansions = expansions.size();
  assert(1u <= num_expansions);
  MacroExpansionImpl *expansion = expansions.back();
  MacroExpansionImpl *deferred_expansion = nullptr;
  assert(!expansion->is_cancelled);

  // It may be the case that we see an end of expansion, but that we're
  // inside of, e.g. an argument list. This can happen because reading the
  // `(` token (by `LexUnexpandedToken` in Clang) for the beginning of the
  // argument list triggered the end of expansion of what expanded to the
  // macro name before the `(`. E.g.
  //
  //      CAT(FOO_, 2)(a, b)
  //
  //  Expands to:
  //
  //      FOO_2(a, b)
  //
  // Where `FOO_2` is a macro. Here, we may only see the end of the expansion of
  // `CAT` as happening just after the begin argument list event, and just
  // before the token event for `(`.
  auto mi = reinterpret_cast<clang::MacroInfo *>(data);
  if (mi && expansion->defined_macro != mi && 2u <= num_expansions) {
    deferred_expansion = expansions[num_expansions - 2u];
    assert(deferred_expansion->defined_macro == mi);
    assert(nodes.back() == expansion);
    expansions.pop_back();
    nodes.pop_back();

#ifndef NDEBUG
    deferred_expansion->defferal_status = MacroExpansionImpl::kDeferredParent;
    expansion->defferal_status = MacroExpansionImpl::kDeferredChild;
#endif

    std::swap(expansion, deferred_expansion);
    assert(!expansion->is_cancelled);

    D( std::cerr << indent << "!!! deferred expansion\n"; )
  }

  Pop(tok);
  assert(nodes.back() == expansion);
  nodes.pop_back();
  expansions.pop_back();

  // Go get the parent. In the case of pre-argument expansions, and in the
  // case of deferred expansions, `nodes.back()` isn't guaranteed to be equal to
  // `expansion->parent`.
  MacroNodeImpl *parent_node = std::get<MacroNodeImpl *>(expansion->parent);
  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) == expansion);

  if (expansion->is_cancelled) {
    assert(expansion->use_nodes.empty());
    parent_node->nodes.pop_back();
    ReparentNodes(std::move(expansion->nodes), parent_node);
  }

  if (!deferred_expansion) {
    return;
  }

  // Expansion is `CAT`, deferred expansion is `FOO_2`. We want the uses nodes
  // of `FOO_2` to be the `CAT`, and the expansion of `CAT` to be the use nodes
  // of `FOO_2`.

  // The only node in `deferred_expansion` is the macro name.
  assert(deferred_expansion->use_nodes.empty());
  assert(deferred_expansion->nodes.size() == 1u);

  // The only node in `expansion->nodes` is `deferred_expansion`.
  assert(std::holds_alternative<MacroNodeImpl *>(expansion->nodes.back()));
  assert(std::get<MacroNodeImpl *>(expansion->nodes.back()) ==
      deferred_expansion);

  assert(parent_node != expansion);
  assert(parent_node != deferred_expansion);
  assert(!parent_node->nodes.empty());
  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) ==
         expansion);

  // What we have:
  //
  //        NP
  //       /  \
  //     {B}   E      <-- actually being closed
  //         /  \
  //       {A}  DE    <-- previous `expansions.back()`
  //           /  \
  //         {}    ident(FOO_2)



  // In this case, NP has to be moved along with E, because E was NP's pre-
  // argument expansion, we want:
  //
  //        DE
  //       /  \
  //     {}   NP
  //         /  \
  //        {B}  E
  //            / \
  //          {A}  ident(FOO_2)
  if (expansion->is_prearg_expansion) {
    assert(expansion->parent_for_prearg == parent_node);
    assert(std::get<MacroNodeImpl *>(expansion->parent) ==
           expansion->parent_for_prearg);

    assert(!expansion->nodes.empty());
    assert(std::holds_alternative<MacroNodeImpl *>(expansion->nodes.back()));
    assert(std::get<MacroNodeImpl *>(expansion->nodes.back()) ==
           deferred_expansion);

    MacroNodeImpl *grand_parent_node = std::get<MacroNodeImpl *>(
        parent_node->parent);
    assert(!grand_parent_node->nodes.empty());
    assert(std::holds_alternative<MacroNodeImpl *>(grand_parent_node->nodes.back()));
    assert(std::get<MacroNodeImpl *>(grand_parent_node->nodes.back()) ==
           parent_node);

    expansion->nodes.pop_back();  // Remove `DE` from `E`.
    grand_parent_node->nodes.pop_back();  // Remove `NP`.

    grand_parent_node->nodes.push_back(deferred_expansion);  // Add `DE`.
    deferred_expansion->parent = grand_parent_node;
    parent_node->parent = deferred_expansion;

    expansion->nodes.clear();
    ReparentNodes(std::move(deferred_expansion->nodes), expansion);

    deferred_expansion->nodes.push_back(parent_node);

  // Othwerwise, in the normal case, what we want is:
  //
  //       NP
  //      /  \
  //    {B}  DE
  //        /  \
  //      {}    E
  //           / \
  //         {A}  ident(FOO_2)
  //
  // * NOTE: the `E` will be swapped into `use_nodes` later.
  } else {
    parent_node->nodes.pop_back();  // Remove `E`
    parent_node->nodes.push_back(deferred_expansion);  // Add `DE`.
    deferred_expansion->parent = parent_node;
    expansion->parent = deferred_expansion;

    expansion->nodes.clear();
    ReparentNodes(std::move(deferred_expansion->nodes), expansion);

    deferred_expansion->nodes.push_back(expansion);
  }

  nodes.push_back(deferred_expansion);
  expansions.push_back(deferred_expansion);
}

void PatchedMacroTracker::DoBeginSubstitution(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);
  MacroSubstitutionImpl *expansion =
      &(ast->root_macro_node.substitutions.emplace_back());
  AddToParentNode(expansion);
  expansion->parent = nodes.back();
  nodes.push_back(expansion);
  substitutions.push_back(expansion);
  DoToken(tok, data);
}

// A delayed substitution comes after the first substituted token, so we need
// to "steal" that token and re-root it into the substitution, and put the
// substitution into its place.
void PatchedMacroTracker::DoBeginDelayedSubstitution(
    const clang::Token &tok, uintptr_t data) {

  if (!depth) {

    // Swap the marker and this token.
    if (last_token_was_added) {
      TokenImpl popped_tok = std::move(ast->tokens.back());
      ast->tokens.pop_back();

      // TODO(pag): This might break with:
      //
      //    #define FOO BAR
      //    #define BAR(a) int a
      //    FOO(x);
      assert(!popped_tok.HasMacroRole());
      Push(last_token);  // Will add a marker token.
      ast->tokens.push_back(std::move(popped_tok));

      assert(ast->tokens.back().Role() ==
             TokenRole::kBeginOfMacroExpansionMarker);
    } else {
      Push(last_token);
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

  AddToParentNode(expansion);  // Adds to `parent_node`.

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

void PatchedMacroTracker::DoEndSubstitution(
    const clang::Token &tok, uintptr_t) {
  assert(!substitutions.empty());
  assert(nodes.back() == substitutions.back());
  Pop(tok);
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

  last_event = kind;

#if D(1 -) 0
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
    case TokenFromLexer: std::cerr << "TokenFromLexer(" << ast->tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case TokenFromTokenLexer: std::cerr << "TokenFromTokenLexer(" << ast->tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case TokenFromCachingLexer: std::cerr << "TokenFromCachingLexer(" << ast->tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case TokenFromAfterModuleImportLexer: std::cerr << "TokenFromAfterModuleImportLexer(" << ast->tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
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

  std::cerr
      << ' ' << clang::tok::getTokenName(tok.getKind());
//    if (tok.is(clang::tok::comma)) {
//      std::cerr
//          << " StartOfLine=" << tok.getFlag(clang::Token::StartOfLine)
//          << " LeadingSpace=" << tok.getFlag(clang::Token::LeadingSpace)
//          << " DisableExpand=" << tok.getFlag(clang::Token::DisableExpand)
//          << " NeedsCleaning=" << tok.getFlag(clang::Token::NeedsCleaning)
//          << " LeadingEmptyMacro=" << tok.getFlag(clang::Token::LeadingEmptyMacro)
//          << " HasUDSuffix=" << tok.getFlag(clang::Token::HasUDSuffix)
//          << " HasUCN=" << tok.getFlag(clang::Token::HasUCN)
//          << " IgnoredComma=" << tok.getFlag(clang::Token::IgnoredComma)
//          << " StringifiedInMacro=" << tok.getFlag(clang::Token::StringifiedInMacro)
//          << " CommaAfterElided=" << tok.getFlag(clang::Token::CommaAfterElided)
//          << " IsEditorPlaceholder=" << tok.getFlag(clang::Token::IsEditorPlaceholder)
//          << " IsReinjected=" << tok.getFlag(clang::Token::IsReinjected);
//    }

  if (tok.is(clang::tok::identifier)) {
    std::cerr << ' ' << tok.getIdentifierInfo()->getName().str();
  } else if (tok.is(clang::tok::raw_identifier)) {
    std::cerr << ' ' << tok.getRawIdentifier().str();
  } else if (tok.is(clang::tok::string_literal)) {
    std::cerr << ' ' << std::string_view(tok.getLiteralData(), tok.getLength());
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
      if (!suppress_indent) {
        indent += "  ";
      }
      suppress_indent = false;
      break;
    default:
      break;
  }

  std::cerr << '\n';
#endif
}

// Callback invoked whenever an inclusion directive of any kind (`#include`,
// `#import`, etc.) has been processed, regardless of whether the inclusion
// will actually result in an inclusion.
void PatchedMacroTracker::InclusionDirective(
      clang::SourceLocation /* hash_loc */,
      const clang::Token &include_tok,
      llvm::StringRef /* file_name */,
      bool /* is_angled */,
      clang::CharSourceRange /* file_name_range */,
      llvm::Optional<clang::FileEntryRef> /* file */,
      llvm::StringRef /* search_path */,
      llvm::StringRef /* relative_path */,
      const clang::Module * /* imported */,
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
    default:
      D( std::cerr << " ???\n"; )
      break;
  }

  D( std::cerr << indent << "InclusionDirective\n"; )
}

// Each time we enter a source file, try to keep track of it.
void PatchedMacroTracker::FileChanged(
    clang::SourceLocation loc, clang::PPCallbacks::FileChangeReason reason,
    clang::SrcMgr::CharacteristicKind file_type, clang::FileID file_id) {

  if (clang::PPCallbacks::FileChangeReason::EnterFile == reason &&
      loc.isValid() && last_directive &&
      (last_directive->kind == MacroDirectiveKind::kInclude ||
       last_directive->kind == MacroDirectiveKind::kIncludeNext ||
       last_directive->kind == MacroDirectiveKind::kIncludeMacros ||
       last_directive->kind == MacroDirectiveKind::kImport)) {
    unsigned offset = 0u;
    std::tie(file_id, offset) = sm.getDecomposedLoc(loc);
    if (auto it = ast->id_to_file.find(file_id.getHashValue());
        it != ast->id_to_file.end()) {
      last_directive->included_file.emplace(it->second);
    }

    includes.push_back(last_directive);
    D( std::cerr << indent << "BeginOfFileMarker\n"; )

    ast->AppendMarker(loc, TokenRole::kBeginOfFileMarker);

  } else if (clang::PPCallbacks::FileChangeReason::ExitFile == reason &&
             file_id.isValid() && !includes.empty()) {
    D( std::cerr << indent << "EndOfFileMarker\n"; )
    last_directive = includes.back();
    includes.pop_back();
    if (!last_directive->included_file) {
      if (auto it = ast->id_to_file.find(file_id.getHashValue());
          it != ast->id_to_file.end()) {
        last_directive->included_file.emplace(it->second);
      }
    }
    assert(last_directive->included_file.has_value());
    ast->AppendMarker(sm.getLocForEndOfFile(file_id),
                      TokenRole::kEndOfFileMarker);
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
  if (last_directive) {
    assert(last_directive->kind != MacroDirectiveKind::kOther);
    last_directive->is_skipped = true;
  }
  if (cond_skip_depth) {
    assert(0 < cond_skip_depth);
    --cond_skip_depth;
  }
}

// Hook called whenever an `#if` is seen.
//
// NOTE(pag): `condition_range` might point into file locations.
void PatchedMacroTracker::If(clang::SourceLocation,
                             clang::SourceRange /* condition_range */,
                             ConditionValueKind cvk) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kIf);
    last_directive->kind = MacroDirectiveKind::kIf;

    // Clang doesn't really do this.
    assert(ConditionValueKind::CVK_NotEvaluated != cvk);

    last_directive->is_skipped = ConditionValueKind::CVK_NotEvaluated == cvk ||
                                 ConditionValueKind::CVK_False == cvk;
    if (last_directive->is_skipped) {
      assert(!cond_skip_depth);
      cond_skip_depth = 1;
      D( std::cerr << indent << "Incrementing skip count\n"; )
    }
  }
  D( std::cerr << indent << "If\n"; )
}

// Hook called whenever an `#elif` is seen.
//
// NOTE(pag): `condition_range` might point into file locations.
void PatchedMacroTracker::Elif(clang::SourceLocation,
                               clang::SourceRange /* condition_range */,
                               ConditionValueKind cvk,
                               clang::SourceLocation /* if_loc */) {

  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kElseIf);
    last_directive->kind = MacroDirectiveKind::kElseIf;
    last_directive->is_skipped = ConditionValueKind::CVK_NotEvaluated == cvk ||
                                 ConditionValueKind::CVK_False == cvk;

    if (last_directive->is_skipped) {
      assert(1 >= cond_skip_depth);
      cond_skip_depth = 1;
      D( std::cerr << indent << "Setting skip count\n"; )
    }
  }
  D( std::cerr << indent << "Elif\n"; )
}

// Hook called whenever an `#ifdef` is seen.
void PatchedMacroTracker::Ifdef(clang::SourceLocation,
                                const clang::Token & /* macro_name_tested */,
                                const clang::MacroDefinition &) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kIfDefined);
    last_directive->kind = MacroDirectiveKind::kIfDefined;
  }
  D( std::cerr << indent << "Ifdef\n"; )
}

// Hook called whenever an `#ifndef` is seen.
void PatchedMacroTracker::Ifndef(clang::SourceLocation,
                                 const clang::Token & /* macro_name_tested */,
                                 const clang::MacroDefinition &) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kIfNotDefined);
    last_directive->kind = MacroDirectiveKind::kIfNotDefined;
  }
  D( std::cerr << indent << "Ifndef\n"; )
}

// Hook called whenever an `#elifdef` branch is taken.
void PatchedMacroTracker::Elifdef(clang::SourceLocation, const clang::Token &,
                                  const clang::MacroDefinition &) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kElseIfDefined);
    last_directive->kind = MacroDirectiveKind::kElseIfDefined;
    last_directive->is_skipped = false;
    assert(1 >= cond_skip_depth);
    cond_skip_depth = 0;
  }
  D( std::cerr << indent << "Elifdef\n"; )
}

// Hook called whenever an `#elifdef` is skipped.
void PatchedMacroTracker::Elifdef(clang::SourceLocation, clang::SourceRange,
                                  clang::SourceLocation) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kElseIfDefined);
    last_directive->kind = MacroDirectiveKind::kElseIfDefined;
    last_directive->is_skipped = true;
//    assert(!cond_skip_depth);
//    cond_skip_depth = 1;
  }
  D( std::cerr << indent << "Elifdef\n"; )
}

// Hook called whenever an `#elifndef` branch is taken.
void PatchedMacroTracker::Elifndef(clang::SourceLocation, const clang::Token &,
                                   const clang::MacroDefinition &) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kElseIfNotDefined);
    last_directive->kind = MacroDirectiveKind::kElseIfNotDefined;
    last_directive->is_skipped = false;
    assert(1 >= cond_skip_depth);
    cond_skip_depth = 0;
  }
  D( std::cerr << indent << "Elifndef\n"; )
}

// Hook called whenever an `#elifndef` is skipped.
void PatchedMacroTracker::Elifndef(clang::SourceLocation, clang::SourceRange,
                                   clang::SourceLocation) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kElseIfNotDefined);
    last_directive->kind = MacroDirectiveKind::kElseIfNotDefined;
    last_directive->is_skipped = false;
//    assert(!cond_skip_depth);
//    cond_skip_depth = 1;
  }
  D( std::cerr << indent << "Elifndef\n"; )
}

/// Hook called whenever an `#else` is seen.
void PatchedMacroTracker::Else(clang::SourceLocation,
                               clang::SourceLocation /* if_loc */) {
  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kElse);
    last_directive->kind = MacroDirectiveKind::kElse;
  }
  D( std::cerr << indent << "Else\n"; )
}

// Hook called whenever an `#endif` is seen.
void PatchedMacroTracker::Endif(clang::SourceLocation,
                                clang::SourceLocation /* if_loc */) {
  if (cond_skip_depth) {
    --cond_skip_depth;
    assert(0 <= cond_skip_depth);
  }

  if (last_directive && !last_directive->is_skipped) {
    assert(last_directive->kind == MacroDirectiveKind::kOther ||
           last_directive->kind == MacroDirectiveKind::kEndIf);
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
