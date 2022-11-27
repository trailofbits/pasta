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
      assert(dynamic_cast<MacroExpansionImpl *>(new_parent));
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
                               MacroNodeImpl *exp, MacroArgumentImpl *new_arg) {

  std::vector<MacroNodeImpl *> new_nodes;
  std::vector<MacroArgumentImpl *> new_arguments;

  D( bool found = false; )
  for (MacroNodeImpl *old_node : nodes) {
    new_nodes.push_back(old_node);
    if (auto old_arg = dynamic_cast<MacroArgumentImpl *>(old_node)) {
      new_arguments.push_back(old_arg);

    } else if (old_node == exp) {
      new_nodes.push_back(new_arg);
      new_arguments.push_back(new_arg);
      D( found = true; )
    }
  }

  D( assert(found); )

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
      prev_role != TokenRole::kFinalMacroExpansionToken &&
      prev_role != TokenRole::kEndOfInternalMacroEventMarker) {
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
  D( sub->line_added = __LINE__; )
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
  D( new_exp->line_added = __LINE__; )
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

  ReparentNodes(std::move(exp->nodes), new_exp);

  exp->nodes.push_back(new_exp);
//  exp->in_prearg_expansion = false;
  new_exp->is_prearg_expansion = true;
//  new_exp->in_prearg_expansion = false;
  new_exp->parent = exp;
  new_exp->parent_for_prearg = exp;

  return new_exp;
}

//// If we're in macro argument pre-expansion, and if we actually see a token,
//// then we want to fake another expansion. To do so, that means copying in
//// a few extra tokens (the macro use and call). Later, we'll detect that we
//// did this, and then build out the expansion.
//bool PatchedMacroTracker::TryDoPreExpansionSetup(const clang::Token &) {
//  for (MacroExpansionImpl *exp : expansions) {
//    if (exp->in_prearg_expansion) {
//      goto fixup;
//    }
//  }
//
//  return false;
//
//fixup:
//
//  std::vector<MacroNodeImpl *> new_nodes;
//  std::vector<MacroExpansionImpl *> new_expansions;
//
//  for (MacroNodeImpl *old_node : nodes) {
//    if (auto old_exp = dynamic_cast<MacroExpansionImpl *>(old_node)) {
//      if (!old_exp->in_prearg_expansion || old_exp->done_prearg_expansion) {
//        new_expansions.push_back(old_exp);
//        new_nodes.push_back(old_exp);
//
//      } else {
//        D( std::cerr << indent << "Swapping expansion with pre-expansion\n"; )
//
//        MacroExpansionImpl *new_exp = DoPreExpansionSetup(old_exp);
//        assert(new_exp != old_exp);
//        assert(new_exp->is_prearg_expansion);
//        assert(!new_exp->in_prearg_expansion);
//        assert(!old_exp->in_prearg_expansion);
//
//        new_expansions.push_back(new_exp);
//        new_nodes.push_back(new_exp);
//      }
//    } else {
//      new_nodes.push_back(old_node);
//    }
//  }
//
//  nodes = std::move(new_nodes);
//  expansions = std::move(new_expansions);
//  return true;
//}


static MacroTokenImpl *FirstExpansionToken(const Node &node) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return std::get<MacroTokenImpl *>(node);
  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::get<MacroNodeImpl *>(node)->FirstExpansionToken();
  } else {
    return nullptr;
  }
}

//static MacroTokenImpl *FirstUseToken(const Node &node) {
//  if (std::holds_alternative<MacroTokenImpl *>(node)) {
//    return std::get<MacroTokenImpl *>(node);
//  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
//    return std::get<MacroNodeImpl *>(node)->FirstUseToken();
//  } else {
//    return nullptr;
//  }
//}

#ifndef NDEBUG
static bool LastIsNotArgument(MacroExpansionImpl *exp) {
  if (exp->nodes.empty()) {
    return false;
  }

  if (!std::holds_alternative<MacroNodeImpl *>(exp->nodes.back())) {
    return false;
  }

  auto impl = std::get<MacroNodeImpl *>(exp->nodes.back());
  return !!dynamic_cast<MacroArgumentImpl *>(impl);
}

static bool HasArgumentSeparator(MacroExpansionImpl *exp) {
  if (exp->nodes.empty()) {
    return false;
  }

  // TODO(pag): Probably want last expansion token.
  if (auto sep = FirstExpansionToken(exp->nodes.back())) {
    return sep->kind_flags.kind == pasta::TokenKind::kComma ||
           sep->kind_flags.kind == pasta::TokenKind::kLParenthesis;
  }

  return false;
}
#endif

// Inject a missing argument. This wraps `pre_exp->nodes.back()` in an
// argument node, then fixes up `nodes` and `arguments`.
static void InjectArgument(ASTImpl &ast, std::vector<MacroNodeImpl *> &nodes,
                           std::vector<MacroArgumentImpl *> &arguments,
                           MacroExpansionImpl *pre_exp) {
  assert(!pre_exp->done_prearg_expansion);
  assert(!pre_exp->is_cancelled);
  assert(pre_exp->use_nodes.empty());

  MacroArgumentImpl *missing_arg =
      &(ast.root_macro_node.arguments.emplace_back());
  D( missing_arg->line_added = __LINE__; )

  assert(!LastIsNotArgument(pre_exp));

  Node just_added_node = std::move(pre_exp->nodes.back());
  pre_exp->nodes.pop_back();
  ReparentNode(just_added_node, missing_arg);

  assert(HasArgumentSeparator(pre_exp));

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
      assert(false);  // Probably not needed?
      D( std::cerr << indent << "^ Adding missing argument for token\n"; )
      InjectArgument(ast, nodes, arguments, pre_exp);
    }

  } else if (std::holds_alternative<MacroNodeImpl *>(pre_exp->nodes.back())) {
    auto last_node = std::get<MacroNodeImpl *>(pre_exp->nodes.back());
    auto last_arg = dynamic_cast<MacroArgumentImpl *>(last_node);
    if (!last_arg) {
      assert(false);  // Probably not needed?
      D( std::cerr << indent << "^ Adding missing argument for node\n"; )
      InjectArgument(ast, nodes, arguments, pre_exp);

    } else {
      D( std::cerr << indent << "^ Last node was already an argument\n"; )
      assert(std::get<MacroNodeImpl *>(last_arg->parent) == pre_exp);
    }
  }
}

//// Pre-argument expansion for macros is funny. I think it applies at an
//// argument granularity, rather than an "all arguments" granularity. For
//// example:
////
////      #define ONE ....
////      #define FOO(a, b, c) ...
////      FOO(1, ONE, 2)
////
//// Will trigger pre-expansion on `ONE` in the call to `FOO`, but the arguments
//// `1` and `2` will not trigger any pre-expansion, and so they'll be invisible
//// to us. To mitigate this issue, we go and search for missing things and then
//// try to clone/inject them.
//bool PatchedMacroTracker::ClonePrefixArguments(
//    MacroExpansionImpl *pre_exp,
//    const clang::Token &tok) {
//  MacroExpansionImpl *exp = pre_exp->parent_for_prearg;
//  if (!exp) {
//    D( std::cerr << indent << " not a pre-expansion\n"; )
//    return false;  // Not a pre-argument expansion.
//  }
//
//  // We've ended pre-argument expansion, and now are entering the macro
//  // expansion itself.
//  if (pre_exp->done_prearg_expansion) {
//    assert(!pre_exp->use_nodes.empty());
//    D( std::cerr << indent << " after pre-expansion done\n"; )
//    return false;
//  }
//
//  assert(exp != pre_exp);
//  assert(pre_exp->use_nodes.empty());
//  assert(!exp->use_nodes.empty());
//  assert(pre_exp->nodes.size() >= 2);  // name, (
//
//  // Figure out if the last thing in this pre-expansion should actually be
//  // nested inside of an argument.
//  if (2u < pre_exp->nodes.size()) {
//    TryWrapLastNodeInArgument(*ast, nodes, arguments, pre_exp, indent);
//  }
//
//  return true;
//////  D( std::cerr << indent << "* Starting Nth pre-arg expansion argument\n"; )
//////
//////  MacroExpansionImpl *exp = expansions.back();
////
////
////  clang::SourceLocation tok_loc = tok.getLocation();
////  assert(tok_loc.isValid());
////
////  std::vector<const Node *> nodes_to_clone;
////
////  // Find the index of `tok` inside of the macro use. This is the upper bound
////  // on doing any cloning.
////  auto num_skipped = 0u;
////  std::optional<unsigned> last_sep;
////  auto matched = false;
////  auto i = pre_exp->nodes.size();
////  for (auto max_i = exp->use_nodes.size(); i < max_i; ++i) {
////    const Node &node = exp->use_nodes[i];
////    MacroTokenImpl *use_tok = FirstUseToken(node);
////    if (!use_tok) {
////      D( std::cerr << indent << " no token at " << num_skipped << '\n'; )
////      ++num_skipped;
////      continue;
////    }
////
////    const TokenImpl &parsed_tok = ast->tokens[use_tok->token_offset];
////    D( std::cerr
////          << indent
////          << "! exp_node[" << i << "] = " << parsed_tok.Data(*ast) << " "
////          << parsed_tok.opaque_source_loc << " "
////          << tok.getLocation().getRawEncoding() << '\n'; )
////
////    if (tok_loc == parsed_tok.Location()) {
////      matched = true;
////      break;
////    }
////
////    switch (use_tok->kind_flags.kind) {
////      case pasta::TokenKind::kLParenthesis:
////        if (num_skipped == 2) {
////          last_sep = num_skipped;
////        }
////        break;
////      case pasta::TokenKind::kComma:
////        if (2 < num_skipped && !use_tok->kind_flags.is_ignored_comma) {
////          last_sep = num_skipped;
////        }
////        break;
////      default:
////        break;
////    }
////
////    ++num_skipped;
////  }
////
////  // We didn't find `tok` anywhere, so just ignore this.
////  if (!matched) {
////    D( std::cerr << indent << "token not in expansion\n"; )
////    return false;
////  }
////
////  // Pull off the last thing on the pre-expansion node if it doesn't have any
////  // tokens in it.
////  MacroNodeImpl *trailing_empty_node = nullptr;
////  if (!pre_exp->nodes.empty() && !FirstUseToken(pre_exp->nodes.back())) {
////    D( std::cerr << indent << "(pulling off trailing empty)\n"; )
////    trailing_empty_node = std::get<MacroNodeImpl *>(pre_exp->nodes.back());
////    pre_exp->nodes.pop_back();
////
////    // If it's an argument, then we want to remove it from the arugmnet list
////    // so that injected prefix argument nodes get the correct indices.
////    if (dynamic_cast<MacroArgumentImpl *>(trailing_empty_node) &&
////        !pre_exp->arguments.empty() &&
////        (std::get<MacroNodeImpl *>(pre_exp->arguments.back()) ==
////            trailing_empty_node)) {
////      pre_exp->arguments.pop_back();
////    }
////  }
////
////  // Clone the nodes between `i` and `j`.
////  for (auto j = pre_exp->nodes.size(); j < i; ++j) {
////    const Node &node = exp->use_nodes[j];
////
////    if (std::holds_alternative<MacroTokenImpl *>(node)) {
////
////      // NOTE(pag): Clang patches doing all pre-arg expansions should obviate
////      //            the need for this.
////      assert(false);
////
////      MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
////      MacroTokenImpl *tok_clone = tok->Clone(*ast, pre_exp);
////      assert(tok->token_offset < tok_clone->token_offset);
////      D( TokenImpl &ast_tok = ast->tokens[tok->token_offset]; )
////      D( std::cerr << indent << " j=" << j << " adding missing token "
////                   << ast_tok.opaque_source_loc << ' '
////                   << ast_tok.Data(*ast) << '\n'; )
////      pre_exp->nodes.emplace_back(tok_clone);
////
////    } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
////
////      // NOTE(pag): Clang patches doing all pre-arg expansions should obviate
////      //            the need for this.
////      assert(false);
////
////      assert(!LastIsNotArgument(pre_exp));
////      MacroNodeImpl *cloned_node =
////          std::get<MacroNodeImpl *>(node)->Clone(*ast, pre_exp);
////
////      D(
////        MacroTokenImpl *cloned_lc = FirstUseToken(cloned_node);
////        std::cerr << indent << " j=" << j << " adding missing node";
////        if (cloned_lc) {
////          TokenImpl &ast_tok = ast->tokens[cloned_lc->token_offset];
////          std::cerr << ' ' << ast_tok.opaque_source_loc << ' '
////                    << ast_tok.Data(*ast);
////        }
////        std::cerr << '\n';
////      )
////
////      pre_exp->nodes.emplace_back(cloned_node);
////
////    } else {
////      assert(false);
////    }
////  }
////
////  if (trailing_empty_node) {
////    D( std::cerr << indent << " re-adding empty argument/expansion\n"; )
////    pre_exp->nodes.emplace_back(trailing_empty_node);
////
////    // If it was an argument, then re-add it. The argument index might have
////    // changed.
////    if (auto trailing_arg = dynamic_cast<MacroArgumentImpl *>(
////            trailing_empty_node)) {
////      trailing_arg->index = static_cast<unsigned>(pre_exp->arguments.size());
////      pre_exp->arguments.push_back(trailing_arg);
////    }
////  }
////
////  return true;
//}

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
      assert(tok.Role() == TokenRole::kEndOfMacroExpansionMarker ||
             tok.Role() == TokenRole::kEndOfInternalMacroEventMarker);
      continue;
    }

    // If we have a file token, then we could be in a define or other directive,
    // in the first tokens of a use of a macro, or in the pre-expansion phase
    // of a macro.
    if (loc.isFileID()) {
      switch (tok.Role()) {
        case TokenRole::kBeginOfMacroExpansionMarker:
        case TokenRole::kEndOfMacroExpansionMarker:
        case TokenRole::kEndOfInternalMacroEventMarker:
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

  nodes.back()->nodes.emplace_back(std::move(node));

  if (!exp || exp->is_cancelled || exp->done_prearg_expansion ||
      !exp->use_nodes.empty()  /* it has switched to expanding */) {
    return true;
  }

//  assert(!exp->in_prearg_expansion);

  // Figure out if the last thing in this pre-expansion should actually be
  // nested inside of an argument.
  TryWrapLastNodeInArgument(*ast, nodes, arguments, exp, indent);

//  // Figure out if we need to wrap `node` in a `MacroArgumentImpl`.
//  if (exp && exp->use_nodes.empty() && !exp->is_cancelled) {
//    if (std::holds_alternative<MacroNodeImpl *>(node)) {
//      auto child = std::get<MacroNodeImpl *>(node);
//      if (!dynamic_cast<MacroArgumentImpl *>(child)) {
//        D( std::cerr << indent << "injecting argument from just-added node\n"; )
//        InjectArgument(*ast, nodes, arguments, exp);
//        return true;
//      }
//#ifndef NDEBUG
//    } else if (std::holds_alternative<MacroTokenImpl *>(node)) {
//      auto child = std::get<MacroTokenImpl *>(node);
//      TokenImpl tok = ast->tokens[child->token_offset];
//      switch (tok.Kind()) {
//        case clang::tok::identifier:
//        case clang::tok::raw_identifier:
//          assert(nodes.back()->nodes.empty());
//          break;
//        case clang::tok::l_paren:
//        case clang::tok::r_paren:
//        case clang::tok::comma:
//          break;
//        default:
//          assert(false);
//          InjectArgument(*ast, nodes, arguments, exp);
//          return true;
//      }
//    } else {
//      assert(false);
//#endif
//    }
//  }
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

  clang::Token tok = tok_;
  clang::SourceLocation tok_loc = tok.getLocation();

  // When we're skipping tokens, we still want to record stuff for
  // conditional directives.
  //
  // NOTE(pag): `macro_skip_count` tells us if we're inside of a cancelled
  //            macro. `cond_skip_depth` tells us if we're inside of section
  //            of code disabled by a conditional directive.
  auto skip = macro_skip_count || cond_skip_depth || 1u == nodes.size();

  // Pre-argument expansion of macro arguments will show the comma separators
  // and closing parens as `eof` tokens, so want to fix that up here.
//  auto force_arg_split = false;
  if (tok.isOneOf(clang::tok::eod, clang::tok::eof)) {
    auto raw_tok_loc = tok_loc.getRawEncoding();
    if (auto real_tok_it = end_of_arg_toks.find(raw_tok_loc);
        real_tok_it != end_of_arg_toks.end()) {
      tok = real_tok_it->second;
//      force_arg_split = true;
      D( std::cerr << indent << "(recovering real token "
                   << clang::tok::getTokenName(real_tok_it->second.getKind())
                   << ")\n"; )
    }
  }

  // Get the token data, and add the data to the AST's backup region, and a
  // empty newline to the normal token data, so that the 1:1 mapping between
  // line numbers in parsed source locations and tokens recorded matches up.
  std::string &tok_data = tok_data_vec[next_tok_data++ % tok_data_vec.size()];
  tok_data.clear();
  if (TryReadRawToken(sm, lo, tok, &tok_data)) {
    SkipLeadingWhitspace(tok, tok_loc, tok_data);
  }

  // We want to skip tokens *between* disabled conditional directives, but
  // not *inside* directives.
  if (!directives.empty()) {
    skip = false;
  }

  if (nodes.size() == 1u && tok.isOneOf(clang::tok::eod, clang::tok::eof)) {
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

    D( std::cerr << indent << "(not adding repeat token "
                 << clang::tok::getTokenName(tok.getKind()) << ")\n"; )
    return;  // It's a repeat?
  }

  CloseUnclosedExpansion(tok);

  if (skip) {
    D( std::cerr << indent << "(not adding skipped/top-level/eod/eof token "
                 << clang::tok::getTokenName(tok.getKind()) << ")\n"; )
    return;
  }

//  // NOTE(pag): This might change `nodes.back()`.
//  TryDoPreExpansionSetup(tok);
//
//  // The pre-expansion may have been triggered part-way through the argument
//  // list of `last_old_exp`, so we may need to copy/clone some arguments over.
//  if (!expansions.empty() && nodes.back() == expansions.back()) {
//    for (auto i = expansions.size(); i-- >= 1u; ) {
//      MacroExpansionImpl *exp = expansions[i];
//
//      // If we're inside of an expansion, and we're done doing that expansion's
//      // pre-argument expansion, then we don't want to go up the stack of pre-
//      // argument expansions for prefix argument cloning, because we will have
//      // already done that when we entered into this expansion in the first
//      // place.
//      if (!exp->use_nodes.empty()) {
//        assert(exp->done_prearg_expansion);
//        break;
//      }
//
//      D( std::cerr << indent << "ClonePrefixArguments(i=" << i
//                   << ") in_pre_exp=" << exp->in_prearg_expansion
//                   << " is_pre_exp=" << exp->is_prearg_expansion
//                   << " done_pre_exp="  << exp->done_prearg_expansion
//                   << '\n'; )
//      if (ClonePrefixArguments(exp, tok)) {
//        break;
//      }
//    }
//  }

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
  if (tok.isOneOf(clang::tok::eod, clang::tok::eof)) {
    tok.setLocation(clang::SourceLocation());
    role = TokenRole::kEndOfInternalMacroEventMarker;
    D( std::cerr << indent << "EndOfInternalMacroEventMarker\n"; )

  } else if (tok_loc.isValid() && tok_loc.isFileID()) {
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
    if (tok_node->kind_flags.kind == TokenKind::kIdentifier && !exp->ident &&
        tok_.getIdentifierInfo() &&
        tok_.getIdentifierInfo()->hasMacroDefinition()) {
      exp->ident = tok_node;

    } else if (tok_node->kind_flags.kind == TokenKind::kLParenthesis &&
               exp->ident && !exp->l_paren) {
      exp->l_paren = tok_node;
    }

//    // If we're in a pre-expansion, and we just added a token, but not into an
//    // argument, then we need to add the argument for this node.
//    if (exp->is_prearg_expansion && !exp->done_prearg_expansion &&
//        (!tok.is(clang::tok::comma) ||
//         tok.getFlag(clang::Token::IgnoredComma))) {
//
//      D( std::cerr << indent << " * Reparenting token into missing argument\n"; )
//      assert(nodes.back() == exp);
//      InjectArgument(*ast, nodes, arguments, exp);
//
//      parent_node = nodes.back();
//      assert(parent_node == arguments.back());
//    }
  }

//  // If we're in a macro argument pre-expansion phase, then we need to manually
//  // split the arguments by commas.
//  if (!arguments.empty() &&
//      (force_arg_split ||
//       (tok.is(clang::tok::comma) &&
//        !tok.getFlag(clang::Token::IgnoredComma)))) {
//
//    end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);
//
//    assert(!expansions.empty());
//    MacroExpansionImpl *exp = expansions.back();
//    MacroArgumentImpl *arg = arguments.back();
//
//    if (parent_node == arg && arg->is_prearg_expansion &&
//        !exp->done_prearg_expansion && 0 >= ParenCount(arg)) {
//
//      // Move the comma out of the argument and into to the expansion.
//      assert(!arg->nodes.empty());
//      Node comma = std::move(arg->nodes.back());
//
//      // Keep track of argument separators.
//      end_of_arg_toks.emplace(tok_loc.getRawEncoding(), tok);
//
//      D( std::cerr
//             << indent << "* Splitting pre-arg data at comma/r_paren "
//             << ast->tokens[std::get<MacroTokenImpl *>(comma)->token_offset].opaque_source_loc
//             << '\n'; )
//
//      arg->nodes.pop_back();
//      arguments.pop_back();
//      nodes.pop_back();
//
//      // NOTE(pag): Might also be an r_paren.
//      ReparentNode(comma, exp);
//      exp->nodes.emplace_back(std::move(comma));
//    }
//  }
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
      case TokenRole::kEndOfInternalMacroEventMarker:
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
  D( directive->line_added = __LINE__; )
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
  last_token.startToken();
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
  last_token.startToken();
}

void PatchedMacroTracker::DoBeginMacroExpansion(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);  // TODO(pag): Which token to pop?

  MacroExpansionImpl *expansion =
      &(ast->root_macro_node.expansions.emplace_back());
  D( expansion->line_added = __LINE__; )

  // NOTE(pag): This inspects `expansions.back()` to see if we need to wrap
  //            this expansion in an argument to the parent expansion.
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

// NOTE(pag): `tok` in pre-argument areas is just the macro name.
void PatchedMacroTracker::DoBeginMacroCallArgument(
    const clang::Token &tok, uintptr_t) {
  last_token.startToken();
  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
    return;

  } else if (expansion->is_prearg_expansion) {
    assert(!expansion->done_prearg_expansion);

  // Keep track of argument separators.
  } else {
//    assert(!expansion->in_prearg_expansion);
    end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);
  }

  assert(!LastIsNotArgument(expansion));
  assert(HasArgumentSeparator(expansion));

  MacroArgumentImpl *argument =
      &(ast->root_macro_node.arguments.emplace_back());
  D( argument->line_added = __LINE__; )
  argument->index = static_cast<unsigned>(expansion->arguments.size());
  argument->offset = static_cast<unsigned>(expansion->nodes.size());
  argument->parent = expansion;  // Checked by `AddToParent`.
  argument->is_prearg_expansion = expansion->is_prearg_expansion;

  AddToParentNode(argument);  // Adds to `expansion`.
  assert(nodes.back() == expansion);
  argument->parent = nodes.back();
  expansion->arguments.emplace_back(argument);
  nodes.push_back(argument);
  arguments.push_back(argument);
  assert(expansion->arguments.size() == (argument->index + 1u));
}

// NOTE(pag): `tok` in pre-argument areas is just the macro name.
void PatchedMacroTracker::DoEndMacroCallArgument(
    const clang::Token &tok, uintptr_t) {

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

  if (expansion->is_prearg_expansion) {
    assert(!expansion->done_prearg_expansion);
    assert(argument->is_prearg_expansion);

  } else {
//    assert(!expansion->in_prearg_expansion);
    assert(!argument->is_prearg_expansion);

    // Keep track of argument separators.
    //
    // NOTE(pag): `tok` is the `l_paren` of the macro call argument list.
    end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);
  }

  arguments.pop_back();
  nodes.pop_back();
  assert(nodes.back() == expansions.back());
  assert(std::holds_alternative<MacroNodeImpl *>(argument->parent));
  assert(nodes.back() == std::get<MacroNodeImpl *>(argument->parent));

  // Pop off the `,` or the `)` from the argument, and add it to the
  // expansion.
  if (argument->nodes.empty()) {
    assert(false);
  }
  MacroNodeImpl *parent_node = std::get<MacroNodeImpl *>(argument->parent);
  assert(parent_node->Kind() == MacroNodeKind::kExpansion);

//  // During argument collection, Clang will replace the end-of-argument
//  // separators (i.e. `comma`, `r_paren`) with `eof` tokens. We keep track of
//  // these tokens with `this->end_of_arg_toks`, because during pre-argument
//  // expansion, we observe the tokens as `eof`s, and rewrite them to their
//  // original forms.
//  //
//  // For whatever reason, Clang sometimes converts unexpected things to the
//  // `eof`s. Those things aren't actually the logical end of argument token,
//  // but are somehow proximate. This manifests in the following use:
//  //
//  //    #define printf_to_stdout(a, ...)  printf(a __VA_OPT__(,) __VA_ARGS__)
//  //    #define exp(a,b) ,
//  //    #define annoying(comma) "a" exp comma "b"
//  //    int main() {
//  //      printf_to_stdout(annoying((,)));
//  //    }
//  //
//  // For some reason in the above, we see the same `r_paren` show up twice,
//  // rather than a `comma` and then an `r_paren`.
//  if (expansion->is_prearg_expansion) {
//    assert(expansion->parent_for_prearg != nullptr);
//    MacroExpansionImpl *orig_expansion = expansion->parent_for_prearg;
//    MacroArgumentImpl *orig_argument = dynamic_cast<MacroArgumentImpl *>(
//        std::get<MacroNodeImpl *>(orig_expansion->arguments[argument->index]));
//
//    assert(orig_argument->index == argument->index);
//    assert(orig_argument->offset > orig_argument->index);
//    assert(orig_argument->offset < orig_expansion->use_nodes.size());
//    Node orig_sep = orig_expansion->use_nodes[orig_argument->offset + 1u];
//    if (std::holds_alternative<MacroTokenImpl *>(orig_sep)) {
//      MacroTokenImpl orig_sep_tok = *std::get<MacroTokenImpl *>(orig_sep);
//
//      if ((argument->index + 1u) == orig_expansion->arguments.size()) {
//        assert(orig_sep_tok.kind_flags.kind == TokenKind::kRParenthesis);
//      } else {
//        assert(orig_sep_tok.kind_flags.kind == TokenKind::kComma);
//        assert(!orig_sep_tok.kind_flags.is_ignored_comma);
//      }
//
//      D(
//          if (static_cast<TokenKind>(last_token.getKind()) !=
//              orig_sep_tok.kind_flags.kind) {
//            std::cerr << indent << "Last token "
//                << clang::tok::getTokenName(last_token.getKind())
//                << " was incorrect sep kind "
//                << clang::tok::getTokenName(
//                      static_cast<clang::tok::TokenKind>(
//                          orig_sep_tok.kind_flags.kind))
//                << '\n';
//          }
//      )
//
//      ast->tokens.pop_back();
//      ast->num_lines--;
//      assert(ast->preprocessed_code.back() == '\n');
//      ast->preprocessed_code.pop_back();
//      ast->root_macro_node.tokens.pop_back();
//
//      MacroTokenImpl *sep_tok_copy = orig_sep_tok.Clone(*ast, parent_node);
//      parent_node->nodes.emplace_back(sep_tok_copy);
//
//    } else {
//      assert(false);
//      goto assume_existing_sep_is_good;
//    }
//
//  // We're not in a pre-expansion, so we can trust that the last added token
//  // to the argument is actually the separator between this argument and the
//  // next argument.
//  } else {
//    assert(!argument->is_prearg_expansion);
//
//  assume_existing_sep_is_good:
    ReparentNode(argument->nodes.back(), parent_node);
    parent_node->nodes.push_back(std::move(argument->nodes.back()));
//  }

  argument->nodes.pop_back();
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
  last_token.startToken();

  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  clang::MacroInfo *macro_info = reinterpret_cast<clang::MacroInfo *>(data);
  MacroExpansionImpl *expansion = expansions.back();
  assert(!expansion->is_prearg_expansion);
  assert(expansion->defined_macro == macro_info);

  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
    return;
  }

//  expansion->in_prearg_expansion = true;

  D( std::cerr << indent << "Swapping expansion with pre-expansion\n"; )

  MacroExpansionImpl *new_exp = DoPreExpansionSetup(expansion);
  assert(new_exp != expansion);
  assert(new_exp->is_prearg_expansion);
//  assert(!new_exp->in_prearg_expansion);
//  assert(!expansion->in_prearg_expansion);

  nodes.back() = new_exp;
  expansions.back() = new_exp;
}

void PatchedMacroTracker::DoEndPreArgumentExpansion(
    const clang::Token &, uintptr_t) {

  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();

//  // This node was marked for pre-argument expansion, but we're still in that
//  // state so it meant that nothing really happened.
//  //
//  // NOTE(pag): Changes in PASTA's patches to Clang should make this
//  //            unnecessary.
//  if (expansion->in_prearg_expansion) {
//    assert(nodes.back() == expansions.back());
//    assert(expansion->nodes.empty());
//    assert(!expansion->is_prearg_expansion);
//    expansion->in_prearg_expansion = false;
//    expansion->done_prearg_expansion = true;
//    return;
//  }

  // This node is a pre-argument expansion invented expansion, so we need to
  // inject in a closing parenthesis to complete it. We may also need to inject
  // any arguments that should have preceded the `)` but didn't trigger any
  // pre-expansion.
  assert(expansion->is_prearg_expansion);
  assert(!expansion->done_prearg_expansion);
  assert(expansion->use_nodes.empty());
  assert(expansion->parent_for_prearg != nullptr);

  // Get the original use, prior to pre-argument expansion.
  MacroExpansionImpl *parent_exp = expansion->parent_for_prearg;
  assert(!parent_exp->use_nodes.empty());
  assert(parent_exp->r_paren != nullptr);

  assert(!expansion->nodes.empty());
  Node r_paren_node = expansion->nodes.back();
  assert(!expansion->arguments.empty());
  assert(arguments.empty() || nodes.back() != arguments.back());

  if (std::holds_alternative<MacroTokenImpl *>(r_paren_node) &&
      (std::get<MacroTokenImpl *>(r_paren_node)->kind_flags.kind ==
          TokenKind::kRParenthesis)) {
    expansion->r_paren = std::get<MacroTokenImpl *>(r_paren_node);
    expansion->r_paren_index = static_cast<unsigned>(
        expansion->nodes.size() - 1u);
//    TokenImpl r_paren_tok = ast->tokens[parent_exp->r_paren->token_offset];
//    clang::Token tok;
//    tok.startToken();
//    tok.setKind(clang::tok::r_paren);
//    tok.setLength(1);
//    tok.setLocation(r_paren_tok.Location());
//
//    // Possibly add in any trailing missing tokens/nodes in before we inject
//    // the trailing `)`. This can happen, e.g. `FOO(1, ONE, 2)` where `ONE`
//    // will get pre-expanded, but `2` will not be seen, and so we add it in
//    // here as a prefix to the `)`.
//    ClonePrefixArguments(expansion, tok);
//    needs_r_paren = true;
  }

//  // At this point, we should always have at least one argument in the
//  // macro pre-expansion. It may or may not be on the stack, depending on
//  // `ClonePrefixArguments`.
//  if (!arguments.empty() && nodes.back() == arguments.back()) {
//    assert(std::get<MacroNodeImpl *>(nodes.back()->parent) == expansion);
//    arguments.pop_back();
//    nodes.pop_back();
//  }

  // We should now be looking at the expansion.
  assert(nodes.back() == expansion);
  if (expansion->is_cancelled) {
    assert(0 < cond_skip_depth);
    expansion->done_prearg_expansion = true;
    return;
  }

  assert(expansion->r_paren != nullptr);
  assert(parent_exp->r_paren->token_offset < expansion->r_paren->token_offset);

//  // Add the last node of the pre-argument expansion macro use, which is the
//  // cloned `r_paren`.
//  expansion->r_paren = parent_exp->r_paren->Clone(*ast, expansion);
//  assert(parent_exp->r_paren->token_offset < expansion->r_paren->token_offset);
//  expansion->r_paren_index = static_cast<unsigned>(expansion->nodes.size());
//  expansion->nodes.emplace_back(expansion->r_paren);

  // Add everything after the `r_paren`. If we have an expansion like
  // `FOO(A, B, C)(X, Y, Z)`, then we technically don't know if `FOO(A, B, C)`
  // will actually expand to a macro or not, but it ends up being very confusing
  // in the graph to have an expansion of `FOO(A, B, C)(X, Y, Z)` lead to an
  // isolated pre-expansion of `FOO(A, B, C)` to `BAR`, and then that turn into
  // an expansion like `BAR(X, Y, Z)`. The `(X, Y, Z)` tokens "disappear" then
  // suddenly "re-appear" in a later sub-tree.
  auto r_paren_index = parent_exp->r_paren_index;
  const size_t num_parent_exp_nodes = parent_exp->use_nodes.size();
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
  expansion->done_prearg_expansion = true;
}

void PatchedMacroTracker::DoSwitchToExpansion(
    const clang::Token &, uintptr_t data) {
  last_token.startToken();

  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());
//  assert(!expansion->in_prearg_expansion);
  assert(!expansion->is_prearg_expansion);

  if (auto mi = reinterpret_cast<clang::MacroInfo *>(data)) {
    assert(mi == expansion->defined_macro);
  }

  // Opportunistically mark as done so that we can mark it as false when we
  // begin a pre-arg expansion for real.
  expansion->done_prearg_expansion = true;

  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
    expansion->nodes.clear();
    return;
  }

  expansion->nodes.swap(expansion->use_nodes);

  // If there are no arguments, then there will not be any closing paren.
  if (!expansion->defined_macro->isFunctionLike()) {
    return;
  }

  // Go find the `r_paren` for the expansion and record it, as well at the index
  // at which it occurs.
  MacroTokenImpl *r_paren = nullptr;
  unsigned r_paren_index = 0u;
  const size_t num_use_nodes = expansion->use_nodes.size();
  int paren_count = 0;

  for (; r_paren_index < num_use_nodes; ++r_paren_index) {
    const Node &node = expansion->use_nodes[r_paren_index];
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

  assert(expansion->r_paren == nullptr);
  assert(r_paren != nullptr);
  expansion->r_paren = r_paren;
  expansion->r_paren_index = r_paren_index;

  // Keep track of argument separators.
  TokenImpl r_paren_tok = ast->tokens[r_paren->token_offset];
  clang::Token tok;
  tok.startToken();
  tok.setKind(clang::tok::r_paren);
  tok.setLength(1);
  tok.setLocation(r_paren_tok.Location());
  end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);
}

void PatchedMacroTracker::DoPrepareToCancelExpansion(
    const clang::Token &, uintptr_t) {

//  assert(!expansions.empty());
//  assert(nodes.back() == expansions.back());
//  MacroExpansionImpl *expansion = expansions.back();
//  assert(expansion->use_nodes.empty());
//  assert(!expansion->is_cancelled);
//  expansion->was_cancelled = true;

  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());
  assert(!expansion->is_cancelled);
  expansion->is_cancelled = true;
//  ++macro_skip_count;
//  auto removed = false;
//
//  // Go get rid of the tokens that were added as part of this expansion.
//  while (!expansion->nodes.empty()) {
//    Node to_remove = std::move(expansion->nodes.back());
//    expansion->nodes.pop_back();
//
//    // There's a sub-node. I don't know why, but go pop its tokens off too.
//    if (std::holds_alternative<MacroNodeImpl *>(to_remove)) {
//      MacroNodeImpl *node_to_remove = std::get<MacroNodeImpl *>(to_remove);
//
//      if (auto sub_exp = dynamic_cast<MacroSubstitutionImpl *>(node_to_remove)) {
//        for (Node &sub_node : sub_exp->use_nodes) {
//          expansion->nodes.emplace_back(std::move(sub_node));
//        }
//      }
//      for (Node &sub_node : node_to_remove->nodes) {
//        expansion->nodes.emplace_back(std::move(sub_node));
//      }
//
//      node_to_remove->nodes.clear();
//
//    // Pop this token off. We want to eliminate it from the end of the token
//    // list.
//    } else if (std::holds_alternative<MacroTokenImpl *>(to_remove)) {
//      MacroTokenImpl *tok_to_remove = std::get<MacroTokenImpl *>(to_remove);
//      if ((tok_to_remove->token_offset + 1u) == ast->tokens.size()) {
//        assert(ast->preprocessed_code.back() == '\n');
//        ast->preprocessed_code.pop_back();
//        ast->tokens.pop_back();
//        ast->num_lines -= 1u;
//        removed = true;
//        assert(start_of_macro_index < ast->tokens.size());
//
//        assert(tok_to_remove == &(ast->root_macro_node.tokens.back()));
//        ast->root_macro_node.tokens.pop_back();
//
//      } else {
//        assert(false);
//      }
//    }
//  }
//
//  if (removed) {
//    last_token.startToken();
//    last_token_was_added = false;
//  }
}

void PatchedMacroTracker::DoCancelExpansion(const clang::Token &tok,
                                            uintptr_t data) {
  DoEndMacroExpansion(tok, data);

//  assert(!expansions.empty());
//  MacroExpansionImpl *expansion = expansions.back();
//  Pop(tok);
//  assert(nodes.back() == expansion);
//  nodes.pop_back();
//  expansions.pop_back();
//
//  MacroNodeImpl *parent_node = nodes.back();
//  if (expansion->is_prearg_expansion) {
//    parent_node = std::get<MacroNodeImpl *>(expansion->parent);
//  } else {
//    assert(parent_node == std::get<MacroNodeImpl *>(expansion->parent));
//  }
//
//  assert(std::holds_alternative<MacroNodeImpl *>(parent_node->nodes.back()));
//  assert(std::get<MacroNodeImpl *>(parent_node->nodes.back()) == expansion);
//  parent_node->nodes.pop_back();
//
//  assert(expansion->use_nodes.empty());
//  if (expansion->is_cancelled) {
//    assert(0 < macro_skip_count);
//    --macro_skip_count;
//  } else {
//    assert(!expansion->is_cancelled);
//    expansion->is_cancelled = true;
//  }
}

void PatchedMacroTracker::DoEndMacroExpansion(
    const clang::Token &tok, uintptr_t data) {

  assert(start_of_macro_index < ast->tokens.size());

  auto num_expansions = expansions.size();
  assert(1u <= num_expansions);
  MacroExpansionImpl *expansion = expansions.back();
  MacroExpansionImpl *deferred_expansion = nullptr;

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

    D( std::cerr << indent << "!!! deferred expansion\n"; )
  }

//  assert(!expansion->is_cancelled);

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

  // In the following case, `deferred_expansion` will be cancelled:
  //
  //    #define PRAGMA _Pragma
  //    #define MACRO(arg) ...
  //    MACRO(PRAGMA("foo"))
  if (!deferred_expansion->is_cancelled) {
    assert(deferred_expansion->nodes.size() == 1u);
  }

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
  D( expansion->line_added = __LINE__; )
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
    if (last_token.getLocation().isValid() && last_token_was_added) {
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
  D( expansion->line_added = __LINE__; )

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

namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, CurTokenLexer, std::unique_ptr<clang::TokenLexer>);
#define REF_CurTokenLexer(pp) (pp.*PASTA_ACCESS_MEMBER(clang, Preprocessor, CurTokenLexer))

PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TokenLexer, IsReinject, bool);
#define PTR_IsReinject(ctl) (ctl->*PASTA_ACCESS_MEMBER(clang, TokenLexer, IsReinject))

}  // namespace detail

// PASTA PATCH:
void PatchedMacroTracker::Event(const clang::Token &tok, EventKind kind,
                                uintptr_t data) {
  switch (kind) {
    case TokenFromTokenLexer:
      // NOTE(pag): We observe these with tokens expanded from `_Pragma`s during
      //            macro argument pre-expansion. If we have deferred expansion
      //            during this time, e.g. `PRAGMA -> _Pragma` or something like
      //            `_Pragma(MACRO)` then the re-injected tokens will be the
      //            `_Pragma`, `(`, `"expansion of MACRO"`, and `)`. We will see
      //            those tokens so we don't want to get the repeats.
      //
      // TODO(pag): I don't know where else re-injection happens.
      if (clang::TokenLexer *ctl = REF_CurTokenLexer(pp).get()) {
        if (PTR_IsReinject(ctl)) {
          D( std::cerr << indent << "TokenLexer in reinject; ignoring.\n"; )
          return;
        }
      }
      [[clang::fallthrough]];
    case TokenFromLexer:
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
