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
#pragma GCC diagnostic pop

// #define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#endif

namespace pasta {

static void ReparentNode(Node &node, MacroNodeImpl *new_parent) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    std::get<MacroTokenImpl *>(node)->parent = new_parent;

  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    auto impl = std::get<MacroNodeImpl *>(node);
    if (dynamic_cast<MacroArgumentImpl *>(impl)) {
      assert(!dynamic_cast<MacroArgumentImpl *>(new_parent));
      assert(dynamic_cast<MacroExpansionImpl *>(new_parent));
    }
    impl->parent = new_parent;
  }
}

static void ReparentNodes(NodeList nodes, MacroNodeImpl *new_parent) {
  for (Node &node : nodes) {
    ReparentNode(node, new_parent);
  }

  new_parent->nodes.insert(new_parent->nodes.end(), nodes.begin(), nodes.end());
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

  D( (void) found; assert(found); )

  nodes.swap(new_nodes);
  arguments.swap(new_arguments);
}

PatchedMacroTracker::PatchedMacroTracker(
    clang::Preprocessor &pp_, clang::SourceManager &sm_, ASTImpl *ast_)
    : pp(pp_),
      sm(sm_),
      ci(*(ast_->ci)),
      lo(ci.getLangOpts()),
      ast(ast_) {
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
}

PatchedMacroTracker::~PatchedMacroTracker(void) {}

void PatchedMacroTracker::Push(const clang::Token &tok) {
  if (!depth) {
    D( std::cerr << indent << "BeginOfMacroExpansionMarker\n"; )
    assert(tok.getLocation().isValid() && tok.getLocation().isFileID());

    parsed_begin_index = ast->macro_tokens.MarkNextTokenAsBeginOfExpansion();
  }
  ++depth;
}

void PatchedMacroTracker::Pop(const clang::Token &tok) {
  assert(0 < depth);
  --depth;
}

// Try to extract the header name and create a substitution for it. In the case
// of an `#include "string"`, the header name is a string literal, which is
// already a complete token. However, with `#include <foo bar>`, there are a
// few tokens, `<`, `foo`, whitespace, `bar`, and `>`, and this needs to be
// substituted with a header_name token.
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
  sub->parsed_begin_index = parsed_begin_index;
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
    D( std::cerr << indent << "HeaderNameToken "
                 << clang::tok::getTokenName(nt.getKind()) << '\n'; )

    if (t.Data().ends_with(end) || nt.is(clang::tok::string_literal)) {
      break;
    }
  }

  // Switch to expansion.
  sub->use_nodes.swap(sub->nodes);

  return true;
}

// Create a partial clone of the initial macro expansion in preparation of
// the argument pre-expansion phase. This means finding and cloning the original
// macro identifier and opening parenthesis, and setting up tracking state.
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
  new_exp->parsed_begin_index = parsed_begin_index;

  if (exp->definition_impl) {
    new_exp->definition = exp->definition_impl;
    new_exp->definition_impl = exp->definition_impl;
    exp->definition_impl->macro_uses.emplace_back(new_exp);
  }

  MacroTokenImpl *new_ident = exp->ident->Clone(*ast, new_exp);
  MacroTokenImpl *new_l_paren = exp->l_paren->Clone(*ast, new_exp);
  assert(exp->ident->token_offset < new_ident->token_offset);
  assert(exp->l_paren->token_offset < new_l_paren->token_offset);
  new_exp->nodes.push_back(new_ident);
  new_exp->nodes.push_back(new_l_paren);
  new_exp->ident = new_ident;
  new_exp->name = new_ident;
  new_exp->l_paren = new_l_paren;

  ReparentNodes(std::move(exp->nodes), new_exp);

  exp->nodes.push_back(new_exp);
  new_exp->is_prearg_expansion = true;
  new_exp->parent = exp;
  new_exp->parent_for_prearg = exp;

  return new_exp;
}

#ifndef NDEBUG
static MacroTokenImpl *FirstExpansionToken(const Node &node) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    return std::get<MacroTokenImpl *>(node);
  }

  if (std::holds_alternative<MacroNodeImpl *>(node)) {
    return std::get<MacroNodeImpl *>(node)->FirstExpansionToken();
  }

  return nullptr;
}

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
    return sep->kind == pasta::TokenKind::kComma ||
           sep->kind == pasta::TokenKind::kLParenthesis;
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

  missing_arg->parsed_begin_index = pre_exp->parsed_begin_index;
  missing_arg->parent = pre_exp;
  missing_arg->is_prearg_expansion = pre_exp->is_prearg_expansion;
  missing_arg->index = static_cast<unsigned>(pre_exp->arguments.size());
  missing_arg->offset = static_cast<unsigned>(pre_exp->nodes.size());
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
        (last_tok->kind != TokenKind::kComma || last_tok->is_ignored_comma)) {
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

static int ParenCount(MacroNodeImpl *arg) {
  int paren_count = 0;
  for (const Node &node : arg->nodes) {
    if (std::holds_alternative<MacroNodeImpl *>(node)) {
      paren_count += ParenCount(std::get<MacroNodeImpl *>(node));
    } else if (std::holds_alternative<MacroTokenImpl *>(node)){
      MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
      if (tok->kind == TokenKind::kLParenthesis) {
        ++paren_count;
      } else if (tok->kind == TokenKind::kRParenthesis) {
        --paren_count;
      }
    }
  }
  return paren_count;
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

  // Figure out if the last thing in this pre-expansion should actually be
  // nested inside of an argument.
  TryWrapLastNodeInArgument(*ast, nodes, arguments, exp, indent);
  return false;
}

// TODO(pag): This might accidentally find the hash inside of a comment.
// TODO(pag): In some cases we can use the last observed hash
std::optional<clang::Token> PatchedMacroTracker::FindDirectiveHash(
    const clang::Token &tok) {

  D( std::cerr << indent << "Trying to add missing directive hash\n"; )

  clang::SourceLocation hash_loc;
  clang::SourceLocation directive_loc = tok.getLocation();
  if (directive_loc.isValid() && directive_loc.isFileID()) {
    bool invalid = false;
    clang::SourceManager &sm = ast->ci->getSourceManager();
    auto [file_id, file_offset] = sm.getDecomposedLoc(directive_loc);
    llvm::StringRef file_data = sm.getBufferData(file_id, &invalid);
    if (invalid) {
      goto backup;
    }

    // Scan backwards through the file buffer from the start of the macro token
    // that was undefined, hoping to find the `#` of the directive. If we find
    // it, then emit an injected token.
    for (int loc_offset = 0; 0 <= file_offset; --loc_offset, --file_offset) {

      // TODO(pag): Make this avoid `#`s inside of block comments, e.g.
      //            # blah /* # hahahah */ ...
      if (file_data[file_offset] == '#' ||
          (file_data[file_offset] == '%' &&
           file_data[file_offset + 1u] == ':')) {
        hash_loc = directive_loc.getLocWithOffset(loc_offset);
        break;
      }
    }
  }

backup:

  if (hash_loc.isInvalid()) {
    hash_loc = skipped_hash.getLocation();
    skipped_hash.startToken();
  }

  // Not quite right, as it might be cause us to re-add another hash. But we
  // really need a `#`.
  if (hash_loc.isInvalid() && last_token.is(clang::tok::hash)) {
    hash_loc = last_token.getLocation();
    last_token.startToken();
  }

  if (hash_loc.isInvalid()) {
    D( std::cerr << indent << "Didn't find directive hash\n"; )
    return std::nullopt;
  }

  clang::Token hash_tok;
  hash_tok.startToken();
  hash_tok.setKind(clang::tok::hash);
  hash_tok.setLocation(hash_loc);

  // We want the token to be added, so this prevents it from being dropped by
  // `DoToken` called from `DoBeginDirective`.
  last_token.startToken();

  return hash_tok;
}

// TODO(pag): Probably should just invoke a raw lexer here?
static bool FixupEofEodToken(const clang::SourceManager &sm,
                             clang::Token &tok_inout) {
  auto invalid = false;
  clang::SourceLocation loc = tok_inout.getLocation();
  const char *data = sm.getCharacterData(loc, &invalid);
  if (invalid || !data || !data[0]) {
    return false;
  }

  bool seen_escape = false;
  bool seen_slash = false;
  bool seen_star = false;
  bool in_comment = false;
  for (int i = 0; ; ++data, ++i) {
    switch (data[0]) {
      case '\0':
        return false;
      case ' ':
      case '\t':
      case '\r':
        seen_star = false;
        seen_slash = false;
        if (in_comment || seen_escape) {
          continue;
        } else {
          return false;
        }
      case '\n':
        seen_star = false;
        seen_slash = false;
        if (in_comment) {
          continue;
        } else if (seen_escape) {
          seen_escape = false;
          continue;
        } else {
          return false;
        }
      case '\\':
        seen_star = false;
        seen_slash = false;
        seen_escape = true;
        continue;
      case ',':
        if (in_comment) {
          seen_star = false;
          continue;
        } else if (seen_slash) {
          return false;
        } else {
          tok_inout.setLocation(loc.getLocWithOffset(i));
          tok_inout.setKind(clang::tok::comma);
          return true;
        }
      case ')':
        if (in_comment) {
          seen_star = false;
          continue;
        } else if (seen_slash) {
          return false;
        } else {
          tok_inout.setLocation(loc.getLocWithOffset(i));
          tok_inout.setKind(clang::tok::r_paren);
          return true;
        }
      case '/':
        if (!in_comment) {
          seen_slash = true;
        } else if (seen_star) {
          seen_star = false;
          in_comment = false;
        }
        continue;
      case '*':
        if (seen_slash) {
          seen_slash = false;
          in_comment = true;
          continue;

        } else if (in_comment) {
          seen_star = true;
          continue;

        } else {
          return false;
        }
      default:
        if (in_comment) {
          continue;
        } else {
          return false;
        }
    }
  }

  return false;
}

// Notify us that we're skipping `tok`.
void PatchedMacroTracker::SkipToken(const clang::Token &, uintptr_t) {}

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
  //
  // NOTE(pag): We check `params.empty()` because the parameter substitution
  //            phase comes after the argument pre-expansion phase, which caches
  //            the expansions. The parameter substitution phase reads the
  //            cached pre-expanded arguments, but Clang's mechanism for
  //            distinguishing a cache hit/miss is that the expansion is non-
  //            empty. So, when there is a false-miss due to an empty argument
  //            pre-expansion, we end up seeing EOF tokens peek through.
  auto force_arg_split = false;
  if (tok.isOneOf(clang::tok::eod, clang::tok::eof) && params.empty()) {
    auto raw_tok_loc = tok_loc.getRawEncoding();
    if (auto real_tok_it = end_of_arg_toks.find(raw_tok_loc);
        real_tok_it != end_of_arg_toks.end()) {
      tok = real_tok_it->second;
      force_arg_split = true;
      D( std::cerr << indent << "(recovering real token "
                   << clang::tok::getTokenName(tok.getKind())
                   << " from map)\n"; )

      // NOTE(pag): Location may be different.
      tok_loc = tok.getLocation();

      // It's possible that the pre-argument expansion did nothing. In that
      // case, we don't want the closing parenthesis, recovered from the EOF,
      // to be injected as a token in the expansion.
      if (!expansions.empty() && nodes.back() == expansions.back() &&
          expansions.back()->done_prearg_expansion &&
          tok.is(clang::tok::r_paren) && expansions.back()->nodes.empty() &&
          expansions.back()->r_paren &&
          ast->macro_tokens.OriginalLocation(expansions.back()->r_paren->token_offset) ==
              tok_loc) {

        D( std::cerr << indent << "(ignoring recovered r_paren; it's the end "
                                  "of an argument pre-expansion)\n"; )
        skip = true;
        tok.setKind(clang::tok::eof);
      }

    } else if (FixupEofEodToken(sm, tok)) {
      D( std::cerr << indent << "(recovering real token "
                   << clang::tok::getTokenName(tok.getKind())
                   << " from data)\n"; )
      end_of_arg_toks.emplace(raw_tok_loc, tok);

      // NOTE(pag): Location may be different.
      tok_loc = tok.getLocation();
      end_of_arg_toks.emplace(tok_loc.getRawEncoding(), tok);
    }
  }

  // Get the token data. With end-of-pragma tokens.
  std::string &tok_data = tok_data_vec[next_tok_data++ % tok_data_vec.size()];
  tok_data.clear();
  if (TryReadRawToken(sm, lo, tok, &tok_data)) {
    SkipLeadingWhitespace(tok, tok_loc, tok_data);
    SkipTrailingWhitespace(tok_data);
  }

  // We want to skip tokens *between* disabled conditional directives, but
  // not *inside* directives.
  if (!directives.empty()) {
    skip = false;
  }

  if (tok.isOneOf(clang::tok::eod, clang::tok::eof)) {
    skip = true;
  }

  // Top level token.
  if (nodes.size() == 1u) {
    assert(!depth);
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

  if (skip) {
    D( std::cerr << indent << "(not adding skipped/top-level/eod/eof token "
                 << clang::tok::getTokenName(tok.getKind()) << " at "
                 << tok.getLocation().getRawEncoding() << ")\n"; )
    SkipToken(tok_, data);
    return;
  }

  // With header names, we don't observe the lexing of the individual tokens.
  auto substituted_header_name = TryExtractHeaderName(tok);

  MacroNodeImpl *parent_node = nodes.back();

  // Add the token to the AST.
  assert(!tok.isOneOf(clang::tok::eod, clang::tok::eof));

  auto mti = static_cast<DerivedTokenIndex>(ast->root_macro_node.tokens.size());
  MacroTokenImpl *tok_node = &(ast->root_macro_node.tokens.emplace_back());
  tok_node->token_offset = ast->macro_tokens.AppendMacroToken(
      tok_data, tok, TokenRole::kIntermediateMacroExpansionToken, mti);

  tok_node->parent = parent_node;
  tok_node->kind = static_cast<TokenKind>(tok.getKind());
  tok_node->is_ignored_comma = tok.getFlag(clang::Token::IgnoredComma);

  // Reparent the last concatenation into the parent, and add the token as
  // the substituion of the last concatenation.
  if (last_concatenation) {
    parent_node->nodes.push_back(last_concatenation);
    last_concatenation->nodes.push_back(tok_node);
    tok_node->parent = last_concatenation;
    last_concatenation->parent = parent_node;
    last_concatenation = nullptr;

  // Add the token to the node.
  } else {
    parent_node->nodes.push_back(tok_node);
  }

  last_token_was_added = true;
  last_token = tok;

  if (tok_.is(clang::tok::identifier) ||
      clang::tok::getKeywordSpelling(tok.getKind())) {
    if (clang::IdentifierInfo *ii = tok.getIdentifierInfo(); 
        ii && ii->hasMacroDefinition()) {
      clang::MacroDefinition def = pp.getMacroDefinition(ii);
      if (clang::MacroInfo *mi = def.getMacroInfo(); mi && mi->isEnabled()) {
        if (auto dir_it = defines.find(mi); dir_it != defines.end()) {
          ast->macro_tokens.MarkAsMacroName(
              tok_node->token_offset, dir_it->second);
        }
      }
    }
  }

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
    if (tok_node->kind != TokenKind::kRawIdentifier &&
        !tok_.isAnnotation() && !exp->ident && tok_.getIdentifierInfo() &&
        tok_.getIdentifierInfo()->hasMacroDefinition()) {
      exp->ident = tok_node;
      exp->name = exp->ident;
    } else if (tok_node->kind == TokenKind::kLParenthesis &&
               exp->ident && !exp->l_paren) {
      exp->l_paren = tok_node;
    }
  }

  // If we're in a macro argument pre-expansion phase, then we need to manually
  // split the arguments inside of the variadic argument section by commas.
  // Clang groups together all of the tokens associated with `...` together
  // into a single argument, even if they are logically many arguments.
  if (!arguments.empty() &&
      (force_arg_split ||
       (tok.is(clang::tok::comma) &&
        !tok.getFlag(clang::Token::IgnoredComma)))) {

    assert(!expansions.empty());
    MacroExpansionImpl *exp = expansions.back();
    MacroArgumentImpl *arg = arguments.back();

    if (parent_node == arg && arg->is_prearg_expansion &&
        exp->defined_macro && exp->defined_macro->isFunctionLike() &&
        exp->defined_macro->isVariadic() &&
        exp->arguments.size() >= exp->defined_macro->getNumParams() &&
        !exp->done_prearg_expansion && 0 >= ParenCount(arg)) {

      if (tok.is(clang::tok::comma)) {
        D( std::cerr << indent << "Injecting EndMacroCallArgument\n"; )
        DoEndMacroCallArgument(tok, 0);
        D( std::cerr << indent << "Injecting BeginMacroCallArgument\n"; )
        DoBeginMacroCallArgument(tok, 0);
      }
    }
  }
}

// Mark tokens as being part of macros.
void ASTImpl::MarkMacroTokens(void) {
  for (const MacroTokenImpl &mt : root_macro_node.tokens) {
    // TokenImpl &tok = tokens[mt.token_offset];
    Node parent = mt.parent;
    while (std::holds_alternative<MacroNodeImpl *>(parent)) {
      auto parent_node = std::get<MacroNodeImpl *>(parent);
      switch (parent_node->kind) {
        case MacroKind::kPragmaDirective:
          macro_tokens.MarkTokenAsInPragmaDirective(mt.token_offset);
          parent = std::monostate{};  // Break out of loop.
          break;
        default:
          parent = parent_node->parent;
          break;
      }
    }
  }
}

void ASTImpl::LinkMacroTokenContexts(void) {
  root_macro_node.token_nodes.reserve(root_macro_node.tokens.size());

  for (MacroTokenImpl &mt : root_macro_node.tokens) {
    assert(mt.token_offset == root_macro_node.token_nodes.size());
    root_macro_node.token_nodes.emplace_back(&mt);
  }
}

#define FOR_EACH_PP_KEYWORD(m) \
    m(if, MacroKind::kIfDirective) \
    m(ifdef, MacroKind::kIfDefinedDirective) \
    m(ifndef, MacroKind::kIfNotDefinedDirective) \
    m(elif, MacroKind::kElseIfDirective) \
    m(elifdef, MacroKind::kElseIfDefinedDirective) \
    m(elifndef, MacroKind::kElseIfNotDefinedDirective) \
    m(else, MacroKind::kElseDirective) \
    m(endif, MacroKind::kEndIfDirective) \
    m(import, MacroKind::kImportDirective) \
    m(include, MacroKind::kIncludeDirective) \
    m(include_next, MacroKind::kIncludeNextDirective) \
    m(__include_macros, MacroKind::kIncludeMacrosDirective) \
    m(define, MacroKind::kDefineDirective) \
    m(undef, MacroKind::kUndefineDirective) \
    m(pragma, MacroKind::kPragmaDirective) \
    m(__public_macro, MacroKind::kOtherDirective) \
    m(__private_macro, MacroKind::kOtherDirective)

#define KIND_FROM_NAME(kw, pasta_kind) \
    if (ident == #kw) { \
      out_kind = clang::tok::pp_ ## kw; \
      return pasta_kind; \
    }

MacroKind KindFromName(llvm::StringRef ident,
                       clang::tok::PPKeywordKind &out_kind) {
  FOR_EACH_PP_KEYWORD(KIND_FROM_NAME)

  for (auto i = 1; i < clang::tok::NUM_PP_KEYWORDS; ++i) {
    auto kw_kind = static_cast<clang::tok::PPKeywordKind>(i);
    auto kw = clang::tok::getPPKeywordSpelling(kw_kind);
    if (ident == kw) {
      out_kind = kw_kind;
      return MacroKind::kOtherDirective;
    }
  }

  out_kind = clang::tok::pp_not_keyword;
  return MacroKind::kToken;
}

struct BoolRAII {
  bool &val;
  inline BoolRAII(bool &val_)
      : val(val_) {
    val = true;
  }
  inline ~BoolRAII(void) {
    val = false;
  }
};

// Try to upgrade the file token associated with `loc` to have the preprocessor
// keyword kind `kw_kind`. This is generally kind of sketchy.
static void TryUpgradeFileTokenKind(ASTImpl &ast, clang::SourceLocation loc,
                                    clang::tok::PPKeywordKind kw_kind) {
  if (auto ftok = ast.FileTokenAt(loc)) {
    if (ftok->PreProcessorKeywordKind() !=
        static_cast<PPKeywordKind>(kw_kind)) {
      auto raw_file = const_cast<FileImpl *>(
          reinterpret_cast<const FileImpl *>(ftok->RawFile()));
      auto raw_ftok = const_cast<FileTokenImpl *>(
          reinterpret_cast<const FileTokenImpl *>(ftok->RawFileToken()));

      std::unique_lock<std::mutex> locker(raw_file->tokens_lock);
      raw_ftok->kind.extended.alt_kind = static_cast<uint16_t>(kw_kind);
      raw_ftok->kind.extended.is_pp_kw = static_cast<uint16_t>(true);
    }
  }
}

// This is a strange event, because it starts in one place, and where it ends
// could be the signalling of an unskipped area.
void PatchedMacroTracker::DoBeginSkippedArea(
    const clang::Token &tok_, uintptr_t data) {

  clang::Token tok = tok_;
  if (skipped_area_recursive_lock) {
    return;
  }

  BoolRAII locker(skipped_area_recursive_lock);

  // We're entering into the skipped area. Eventually we will come across a
  // token, such as `if`, `ifdef`, `ifndef` that will bring us deeper, or
  // `elif`, `elifdef`, `elifndef`, or `else` that may or may not be skipped,
  // but should be recorded, or `endif` that pulls us out of a skipped area.
  if (tok.is(clang::tok::hash)) {
    last_token = tok;

    if (last_directive) {
      switch (last_directive->kind) {
        case MacroKind::kIfDirective:
        case MacroKind::kIfDefinedDirective:
        case MacroKind::kIfNotDefinedDirective:
        case MacroKind::kElseIfDirective:
        case MacroKind::kElseIfDefinedDirective:
        case MacroKind::kElseIfNotDefinedDirective:
        case MacroKind::kElseDirective:
        case MacroKind::kEndIfDirective:
          last_directive->is_skipped = true;
          break;
        default:
          assert(false);
          return;
      }
    }

    if (!cond_skip_depth) {
      D( std::cerr << indent << "Initializing skip depth = 1 (case 2)\n"; )
      cond_skip_depth = 1;
    }
    suppress_indent = true;

  // We're nested inside of a skipped region, and this is logically a
  // macro directive that we need to record. It may be a conditional directive
  // that should alter the condition depth level.
  } else if (tok.isOneOf(clang::tok::identifier, clang::tok::raw_identifier,
                         clang::tok::kw_if, clang::tok::kw_else)) {

    assert(cond_skip_depth >= 0);
    if (!cond_skip_depth) {
      D( std::cerr << indent << "Initializing skip depth = 1 (case 3)\n"; )
      cond_skip_depth = 1;
    }

    std::string &ident = tok_data_vec[next_tok_data++ % tok_data_vec.size()];
    ident.clear();

    auto tok_loc = tok.getLocation();
    if (TryReadRawToken(sm, lo, tok, &ident)) {
      SkipLeadingWhitespace(tok, tok_loc, ident);
      SkipTrailingWhitespace(ident);
    }

    clang::tok::PPKeywordKind kw_kind = clang::tok::pp_not_keyword;
    MacroKind kind = KindFromName(ident, kw_kind);
    switch (kind) {
      case MacroKind::kIfDirective:
      case MacroKind::kIfDefinedDirective:
      case MacroKind::kIfNotDefinedDirective:
        D( std::cerr << indent << "Incrementing skip depth (if-like directive)\n"; )
        ++cond_skip_depth;
        break;
      case MacroKind::kElseIfDirective:
        // See if we should reset the skip depth, because we might evaluate the
        // next condition differently.
        //
        // Elif is the only event that has a non-trivial body form. The other
        // elif-like events all end up having some kind of trivial true/false
        // evaluation, that makes us not want to alter the skip depth here.
        if (1 == cond_skip_depth) {
          D( std::cerr << indent << "Resetting skip depth for top-level elif\n"; )
          cond_skip_depth = 0;
        }
        break;
      case MacroKind::kEndIfDirective:
      case MacroKind::kElseIfDefinedDirective:
      case MacroKind::kElseIfNotDefinedDirective:
      case MacroKind::kElseDirective:
        D( std::cerr << indent << "Decrementing skip depth\n"; )
        --cond_skip_depth;
        break;
      case MacroKind::kOtherDirective:
      default:
        break;
      case MacroKind::kToken:
        D( std::cerr << indent << "??? Not a macro directive: '"
                     << ident << "'\n"; )
        suppress_indent = true;
        return;
    }

    // Upgrade the file token in-place.
    TryUpgradeFileTokenKind(*ast, tok_loc, kw_kind);

    std::optional<clang::Token> hash_tok = FindDirectiveHash(tok);
    if (!hash_tok) {
      assert(false);
      suppress_indent = true;
      D( std::cerr << indent << "??? Didn't find directive hash for '"
                   << ident << "'\n"; )
      return;
    }

    tok.setKind(clang::tok::raw_identifier);
    D( std::cerr << indent << "Adding skipped directive '"
                 << ident << "' hash_loc="
                 << hash_tok->getLocation().getRawEncoding()
                 << " depth=" << depth << " cond_skip_depth="
                 << cond_skip_depth << '\n'; )
    DoBeginDirective(*hash_tok, data);
    DoToken(tok, 0);
    DoSetNamedDirective(*hash_tok, 0);
    directives.back()->kind = kind;
    directives.back()->is_skipped = true;

    // If it's not a conditional directive, then end it. If the
    // `cond_skip_depth` is positive, then we'll rely on `DoToken` to
    // Call back into `DoBeginSkippedArea`.
    switch (kind) {
      case MacroKind::kIfDirective:
      case MacroKind::kIfDefinedDirective:
      case MacroKind::kIfNotDefinedDirective:
      case MacroKind::kElseIfDirective:
      case MacroKind::kElseIfDefinedDirective:
      case MacroKind::kElseIfNotDefinedDirective:
      case MacroKind::kElseDirective:
      case MacroKind::kEndIfDirective:
        break;
      case MacroKind::kToken:  // Not a directive.
        assert(false);
        break;
      default:
        D( std::cerr << indent << "EndDirective <inferred>\n"; )
        DoEndDirective(tok, data);
        suppress_indent = true;
        break;
    }

  // Something like `# 1` inside of a disabled region.
  } else if (tok.isOneOf(clang::tok::numeric_constant,
                         clang::tok::string_literal)) {
    std::optional<clang::Token> hash_tok = FindDirectiveHash(tok);
    if (!hash_tok) {
      assert(false);
      suppress_indent = true;
      D( std::cerr << indent << "??? Didn't find directive hash for other directive kind\n"; )
      return;
    }

    DoBeginDirective(*hash_tok, data);
    DoToken(tok, 0);
    directives.back()->kind = MacroKind::kOtherDirective;
    directives.back()->is_skipped = true;
    D( std::cerr << indent << "EndDirective <inferred>\n"; )
    DoEndDirective(tok, data);
    suppress_indent = true;
  }
}

void PatchedMacroTracker::DoBeginDirective(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);
  assert(directives.empty());
  MacroDirectiveImpl *directive =
      &(ast->root_macro_node.directives.emplace_back());
  D( directive->line_added = __LINE__; )
  AddToParentNode(directive);
  directive->parsed_begin_index = parsed_begin_index;
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
//  if (cond_skip_depth) {
//    D( std::cerr << indent << "Skipping SetNamedDirective\n"; )
//    return;
//  }

  if (!std::holds_alternative<MacroTokenImpl *>(directive->nodes.back())) {
    assert(false);
    return;
  }

  auto name_tok = std::get<MacroTokenImpl *>(directive->nodes.back());
  if (name_tok->kind != TokenKind::kIdentifier &&
      name_tok->kind != TokenKind::kRawIdentifier &&
      name_tok->kind != TokenKind::kKeywordIf &&
      name_tok->kind != TokenKind::kKeywordElse) {
    assert(false);
    return;
  }

  clang::tok::PPKeywordKind kw_kind = clang::tok::pp_not_keyword;
  DerivedTokenIndex kw_offset = name_tok->token_offset;
  std::string_view data = ast->macro_tokens.Data(kw_offset);

  directive->kind = KindFromName(data, kw_kind);
  if (directive->kind != MacroKind::kToken) {
    directive->directive_name = directive->nodes.back();
    directive->collected_missing_tokens_on_eod = data == "warning" ||
                                                 data == "error";
    D( std::cerr << indent << "DirectiveName=" << data << '\n'; )

    // Upgrade the file token in-place.
    name_tok->kind = TokenKind::kRawIdentifier;
    ast->macro_tokens.SetKind(kw_offset, TokenKind::kRawIdentifier);
    TryUpgradeFileTokenKind(*ast, ast->macro_tokens.OriginalLocation(kw_offset),
                            kw_kind);
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

static void Expand(std::ostream &os, const ASTImpl &ast,
                   Node node, const char *&sep,
                   clang::SourceLocation &last_loc,
                   std::vector<DerivedTokenIndex> &unexpanded_macros) {
  if (std::holds_alternative<MacroTokenImpl *>(node)) {
    auto tok = std::get<MacroTokenImpl *>(node);
    auto tok_offset = tok->token_offset;
    // const TokenImpl &real_tok = ast.tokens[tok_offset];
    last_loc = ast.macro_tokens.OriginalLocation(tok_offset);
    auto data = ast.macro_tokens.Data(tok_offset);
    if (!data.empty()) {
      last_loc = last_loc.getLocWithOffset(static_cast<int>(data.size()));
      os << sep << data;
      sep = " ";

      // Something like `#pragma clang deprecated (ATOMIC_VAR_INIT)`.
      if (ast.macro_tokens.MacroName(tok_offset)) {
        unexpanded_macros.push_back(tok_offset);
      }
    }

  } else if (std::holds_alternative<MacroNodeImpl *>(node)) {
    auto sub = std::get<MacroNodeImpl *>(node);
    for (const Node &sub_node : sub->nodes) {
      Expand(os, ast, sub_node, sep, last_loc, unexpanded_macros);
    }
  }
}

void PatchedMacroTracker::DoEndDirective(
    const clang::Token &tok, uintptr_t data) {

  // It can be the case that there's an empty `#` directive, or something like
  // `# /* comment */`. We observe this in the SQLite codebase near the
  // `utf8_to_utf16` function in `shell.c`. We'll try to recover by scanning
  // backwards, and look for the `#` at the beginning of the line, then
  // fake a directive for that.
  if (directives.empty()) {
    suppress_indent = true;
    std::optional<clang::Token> hash_tok = FindDirectiveHash(tok);
    if (!hash_tok) {
      assert(false);
      return;
    }

    D( std::cerr << indent << "Adding empty directive in DoEndDirective\n"; )
    DoBeginDirective(*hash_tok, data);
    DoToken(tok, 0);
    directives.back()->kind = MacroKind::kOtherDirective;
    directives.back()->is_skipped = 0 < cond_skip_depth;
  }

  assert(!directives.empty());
  assert(nodes.back() == directives.back());
  assert(!directives.back()->nodes.empty());

  last_directive = directives.back();

  auto dir_for_node = last_directive;
  bool emitted_marker = false;
  std::stringstream ss;
  const char *sep = "";
  clang::SourceLocation last_loc;
  std::vector<DerivedTokenIndex> unexpanded_macros;

  if (last_directive->kind == MacroKind::kPragmaDirective) {

    // We need to emit the pragma tokens as a line in the parsed tokens.
    // Pragmas are important for things like adjusting structure packing. One
    // thing that's tricky about doing this is that we need to expand macros
    // within the pragmas.
    Expand(ss, *ast, last_directive, sep, last_loc, unexpanded_macros);
    D( std::cerr << indent << "Got pragma: " << ss.str() << '\n'; )

    std::string pragma_data = ss.str();
    
    // A pragma might reference a macro name which doesn't actually exist. We'll
    // try to rewrite it into a compatible pragma.
    auto is_deprecated = pragma_data.find(" deprecated ") != std::string::npos;
    auto is_poisoned = pragma_data.find(" poison ") != std::string::npos;
    auto is_system_header = pragma_data.find(" system_header") != std::string::npos;
    auto is_once = pragma_data.find(" once") != std::string::npos;
    if (!is_deprecated && !is_poisoned && !is_system_header && !is_once) {
      assert(unexpanded_macros.empty());

      emitted_marker = true;
      ast->parsed_tokens.AppendInternalToken(
          pragma_data, last_loc, TokenRole::kMacroDirectiveMarker,
          true  /* is_in_pragma */);
    }

  // If this was a `#warning` or `#error` then try to collect the string
  // literals. Those were missing.
  //
  // TODO(pag): Patch Clang to make them not missing.
  } else if (last_directive->collected_missing_tokens_on_eod &&
             std::holds_alternative<MacroTokenImpl *>(
                 last_directive->directive_name)) {

    last_directive->collected_missing_tokens_on_eod = false;

    D( std::cerr << indent
                 << " - Trying to add missing warning/error message\n"; )

    MacroTokenImpl *dir_name_mtok =
        std::get<MacroTokenImpl *>(last_directive->directive_name);
    DerivedTokenIndex dir_name_offset = dir_name_mtok->token_offset;

    clang::SourceLocation dir_name_loc 
        = ast->macro_tokens.OriginalLocation(dir_name_offset);

    if (!dir_name_loc.isValid() || !dir_name_loc.isFileID()) {
      D( std::cerr << indent << " - Bad directive location\n"; )
      goto done;
    }

    auto dir_name_data = ast->macro_tokens.Data(dir_name_offset);
    clang::SourceLocation after_directive_loc =
        dir_name_loc.getLocWithOffset(static_cast<int>(dir_name_data.size()));

    std::vector<clang::Token> literals;
    literals.emplace_back();

    while (!pp.getRawToken(after_directive_loc, literals.back(), true)) {
      clang::Token &literal = literals.back();
      after_directive_loc = literal.getEndLoc();
      if (literal.isOneOf(clang::tok::string_literal,
                          clang::tok::wide_string_literal)) {

        D( std::cerr << indent << " - Lexed a string literal!\n"; )
        literals.emplace_back();

      } else if (literal.isOneOf(clang::tok::eof, clang::tok::eod) ||
                 literal.isAtStartOfLine()) {
        D( std::cerr << indent << " - Lexed EOF/EOD\n"; )
        break;

      } else if (literal.is(clang::tok::unknown)) {
        D( std::cerr << indent << " - Has whitespace\n"; )
        literal.startToken();

      } else {
        D( std::cerr << indent << " - Has non-whitespace, non-string\n"; )
        goto done;
      }
    }

    literals.pop_back();
    for (const clang::Token &literal : literals) {
      DoToken(literal, data);
    }
  }

done:
  nodes.pop_back();
  directives.pop_back();
  last_token.startToken();

  if (!emitted_marker) {
    Expand(ss, *ast, last_directive, sep, last_loc, unexpanded_macros);
    ast->parsed_tokens.AppendInternalToken(
        "", last_loc, TokenRole::kMacroDirectiveMarker,
        false  /* is_in_pragma */);
  }

  auto marker_offset = static_cast<DerivedTokenIndex>(
      ast->parsed_tokens.size() - 1u);
  assert(ast->parsed_tokens.Role(marker_offset) ==
         TokenRole::kMacroDirectiveMarker);
  ast->macro_directives.emplace(marker_offset, dir_for_node);
  dir_for_node->marker_token_offset = marker_offset;

  Pop(tok);
}

void PatchedMacroTracker::DoBeginMacroExpansion(
    const clang::Token &tok, uintptr_t data) {
  Push(tok);  // TODO(pag): Which token to pop?
  assert(!cond_skip_depth);

  MacroExpansionImpl *expansion =
      &(ast->root_macro_node.expansions.emplace_back());
  D( expansion->line_added = __LINE__; )

  // NOTE(pag): This inspects `expansions.back()` to see if we need to wrap
  //            this expansion in an argument to the parent expansion.
  AddToParentNode(expansion);

  expansion->parsed_begin_index = parsed_begin_index;
  expansion->parent = nodes.back();
  nodes.push_back(expansion);
  expansions.push_back(expansion);

  auto tok_index = ast->macro_tokens.size();
  DoToken(tok, data);

  assert(expansion->ident != nullptr);

  (void) tok_index;
  assert(expansion->ident->token_offset == tok_index);

  // Link up the expansion with the definition. `data` might be zero in the
  // case of `_Pragma`.
  clang::MacroInfo *mi = reinterpret_cast<clang::MacroInfo *>(data);
  expansion->defined_macro = mi;
  if (expansion->ident) {
    if (auto it = defines.find(mi); it != defines.end()) {
      if (MacroDirectiveImpl *def = it->second) {
        assert(def->kind == MacroKind::kDefineDirective);
        assert(def->defined_macro == mi);
        def->macro_uses.push_back(expansion);
        expansion->definition = def;
        expansion->definition_impl = def;

        ast->macro_tokens.MarkAsMacroName(expansion->ident->token_offset, def);
      }
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
    end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);
  }

  assert(!LastIsNotArgument(expansion));
  assert(HasArgumentSeparator(expansion));

  MacroArgumentImpl *argument =
      &(ast->root_macro_node.arguments.emplace_back());
  D( argument->line_added = __LINE__; )

  argument->parsed_begin_index = parsed_begin_index;
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
  assert(!argument->nodes.empty());

  // Pop off the `,` or the `)` from the argument, and add it to the
  // expansion.
  MacroNodeImpl *parent_node = std::get<MacroNodeImpl *>(argument->parent);
  assert(parent_node->kind == MacroKind::kExpansion);

  ReparentNode(argument->nodes.back(), parent_node);
  parent_node->nodes.push_back(std::move(argument->nodes.back()));
  argument->nodes.pop_back();
}

void PatchedMacroTracker::DoEndMacroCallArgumentList(
    const clang::Token &tok, uintptr_t data) {
  if (!arguments.empty() && nodes.back() == arguments.back()) {
    assert(tok.isOneOf(clang::tok::eof, clang::tok::r_paren));
    D( std::cerr << indent << "?? Missing DoEndMacroCallArgument\n"; )
    DoEndMacroCallArgument(tok, data);
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
  last_token.startToken();

  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(!expansion->is_prearg_expansion);

#ifndef NDEBUG
  clang::MacroInfo *macro_info = reinterpret_cast<clang::MacroInfo *>(data);
  assert(expansion->defined_macro == macro_info);
#endif

  if (expansion->is_cancelled) {
    assert(0 < macro_skip_count);
    return;
  }

  D( std::cerr << indent << "Swapping expansion with pre-expansion\n"; )

  MacroExpansionImpl *new_exp = DoPreExpansionSetup(expansion);
  assert(new_exp != expansion);
  assert(new_exp->is_prearg_expansion);

  nodes.back() = new_exp;
  expansions.back() = new_exp;
}

void PatchedMacroTracker::DoEndPreArgumentExpansion(
    const clang::Token &, uintptr_t) {

  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();

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
  assert(arguments.empty() || nodes.back() != arguments.back());

  // Go get the `r_paren` at the end of the expansion nodes list.
  if (std::holds_alternative<MacroTokenImpl *>(r_paren_node) &&
      (std::get<MacroTokenImpl *>(r_paren_node)->kind ==
          TokenKind::kRParenthesis)) {
    expansion->r_paren = std::get<MacroTokenImpl *>(r_paren_node);
    expansion->r_paren_index = static_cast<unsigned>(
        expansion->nodes.size() - 1u);
  }

  // If there were no arguments in the argument pre-expansion phase, e.g.
  // a call like `VARIADIC()` to a macro like `#define VARIADIC(args...)`
  // then we need to clone the original `r_paren`, because we won't have seen
  // it as the `eof` token at the end of the last argument token.
  if (!expansion->r_paren) {

    assert(expansion->arguments.empty());

    if (!parent_exp->arguments.empty()) {
      assert(parent_exp->arguments.size() == 1u);
      auto parent_arg = dynamic_cast<MacroArgumentImpl *>(
          std::get<MacroNodeImpl *>(parent_exp->arguments.back()));

      // Eliminate the empty argument in the initial expansion.
      if (parent_arg && parent_arg->nodes.empty() &&
          parent_exp->r_paren_index &&
          (parent_exp->r_paren_index + 1u) == parent_exp->nodes.size()) {

        parent_exp->arguments.pop_back();
        parent_exp->nodes[parent_exp->r_paren_index - 1u] =
            std::move(parent_exp->nodes[parent_exp->r_paren_index]);
        parent_exp->nodes.pop_back();
        --parent_exp->r_paren_index;

      // Make an empty dummy argument.
      } else {
        MacroArgumentImpl *missing_arg =
            &(ast->root_macro_node.arguments.emplace_back());
        D( missing_arg->line_added = __LINE__; )

        assert(!LastIsNotArgument(expansion));
        assert(HasArgumentSeparator(expansion));

        missing_arg->parsed_begin_index = parsed_begin_index;
        missing_arg->parent = expansion;
        missing_arg->is_prearg_expansion = true;
        missing_arg->index = static_cast<unsigned>(expansion->arguments.size());
        missing_arg->offset = static_cast<unsigned>(expansion->nodes.size());
        expansion->arguments.push_back(missing_arg);
        expansion->nodes.emplace_back(missing_arg);
      }
    }

    expansion->r_paren_index = static_cast<unsigned>(expansion->nodes.size());
    expansion->r_paren = parent_exp->r_paren->Clone(*ast, expansion);
    expansion->nodes.emplace_back(expansion->r_paren);
  }

  // We should now be looking at the expansion.
  assert(nodes.back() == expansion);
  if (expansion->is_cancelled) {
    assert(0 < cond_skip_depth);
    expansion->done_prearg_expansion = true;
    return;
  }

  assert(expansion->r_paren != nullptr);
  assert(parent_exp->r_paren->token_offset < expansion->r_paren->token_offset);

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
  assert(!expansion->is_prearg_expansion);

  if (auto mi = reinterpret_cast<clang::MacroInfo *>(data)) {
    assert(mi == expansion->defined_macro);
    (void) mi;
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
  auto &use_nodes = expansion->use_nodes;
  assert(!use_nodes.empty());
  assert(std::holds_alternative<MacroTokenImpl *>(use_nodes.back()));
  assert(std::get<MacroTokenImpl *>(use_nodes.back())->kind ==
         TokenKind::kRParenthesis);

  expansion->r_paren = std::get<MacroTokenImpl *>(use_nodes.back());
  expansion->r_paren_index = static_cast<unsigned>(use_nodes.size() - 1u);

  // Keep track of argument separators.
  DerivedTokenIndex r_paren_offset = expansion->r_paren->token_offset;
  
  clang::Token tok;
  tok.startToken();
  tok.setKind(clang::tok::r_paren);
  tok.setLength(1);
  tok.setLocation(ast->macro_tokens.OriginalLocation(r_paren_offset));
  end_of_arg_toks.emplace(tok.getLocation().getRawEncoding(), tok);
}

void PatchedMacroTracker::DoPrepareToCancelExpansion(
    const clang::Token &, uintptr_t) {

  assert(!expansions.empty());
  assert(nodes.back() == expansions.back());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->use_nodes.empty());
  assert(!expansion->is_cancelled);
  expansion->is_cancelled = true;
}

void PatchedMacroTracker::DoCancelExpansion(const clang::Token &tok,
                                            uintptr_t data) {
  DoEndMacroExpansion(tok, data);
}

void PatchedMacroTracker::DoEndMacroExpansion(
    const clang::Token &tok, uintptr_t data) {

  // assert(parsed_start_of_macro_index < ast->macro_tokens.size());

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

    // It's possible that we're inside of an argument. This can happen in the
    // following evil case:
    //
    //      #define PP_EAT(...)
    //      #define L_PAREN (
    //      #define EVIL(l_paren) PP_EAT l_paren
    //      EVIL(L_PAREN) whatever_here )
    //
    // In this case, the nesting isn't actually a tree, which is problematic.
    // We see the event that should be closing `EVIL`, while simultaneously
    // being inside of the argument expandion of `PP_EAT`.
    if (nodes.back() != expansion) {
      D( std::cerr
           << indent << "!! Non-tree nested macro expansion of "
           << ast->macro_tokens.Data(expansion->ident->token_offset)
           << " inside of "
           << ast->macro_tokens.Data(deferred_expansion->ident->token_offset)
           << '\n'; )

      std::vector<MacroNodeImpl *> new_nodes;
      for (auto node : nodes) {
        if (node != deferred_expansion) {
          new_nodes.emplace_back(node);
        }
      }

      nodes.swap(new_nodes);
      expansions.pop_back();
      expansions.pop_back();
      expansions.push_back(expansion);

      Pop(tok);
      return;
    }

    expansions.pop_back();
    nodes.pop_back();

#ifndef NDEBUG
    deferred_expansion->defferal_status = MacroExpansionImpl::kDeferredParent;
    expansion->defferal_status = MacroExpansionImpl::kDeferredChild;
#endif

    std::swap(expansion, deferred_expansion);

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

  // In the following case, `deferred_expansion` will be cancelled:
  //
  //    #define PRAGMA _Pragma
  //    #define MACRO(arg) ...
  //    MACRO(PRAGMA("foo"))
  if (!deferred_expansion->is_cancelled) {
    // TODO(pag): I don't recall what this checks. But it breaks with the
    //            following example:
    //
    //    #define A B )(
    //    #define B C( 
    //    #define C() D
    //    #define D(x) x
    //    int main() {
    //      return A 2);
    //    }
    //
    // assert(deferred_expansion->nodes.size() == 1u);
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
  //       /  \                                         .
  //     {B}   E      <-- actually being closed
  //         /  \                                       .
  //       {A}  DE    <-- previous `expansions.back()`
  //           /  \                                     .
  //         {}    ident(FOO_2)
  //
  // In this case, NP has to be moved along with E, because E was NP's pre-
  // argument expansion, we want:
  //
  //        DE
  //       /  \                                         .
  //     {}   NP
  //         /  \                                       .
  //        {B}  E
  //            / \                                     .
  //          {A}  ident(FOO_2)
  if (expansion->is_prearg_expansion) {
    D( std::cerr << indent << "Deferral in argument pre-expansion\n"; )
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

    ReparentNodes(std::move(deferred_expansion->nodes), expansion);

    deferred_expansion->nodes.push_back(parent_node);

  // Otherwise, in the normal case, what we want is:
  //
  //       NP
  //      /  \                                .
  //    {B}  DE
  //        /  \                              .
  //      {}    E
  //           / \                            .
  //         {A}  ident(FOO_2)
  //
  // * NOTE: the `E` will be swapped into `use_nodes` later.
  } else {

#if D(1 + ) 0
    if (expansion->nodes.size() == 1) {

      std::cerr << indent << "Normal deferral\n";

    // We have a `dprintk`-like situation. We have come across a macro close
    // for `dprintk`, but the expansion of `printk` has already begun, so we
    // want to leave the expansion of `printk`, which is `deffered_expansion`
    // where it is, with no reorganization, but pretend that it is at the top
    // of our expansions stack.
    //
    //      #define printk(fmt, ...) /* something */
    //      #define dprintk if (debug) printk
    } else {
      std::cerr << indent << "!! Deferral with other nodes!\n";
    }
#endif

    parent_node->nodes.pop_back();  // Remove `E`
    parent_node->nodes.push_back(deferred_expansion);  // Add `DE`.
    deferred_expansion->parent = parent_node;
    expansion->parent = deferred_expansion;

    expansion->nodes.pop_back();
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
  expansion->parsed_begin_index = parsed_begin_index;
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
  Push(last_token);

  MacroSubstitutionImpl *expansion =
      &(ast->root_macro_node.substitutions.emplace_back());
  D( expansion->line_added = __LINE__; )

  MacroNodeImpl * const parent_node = nodes.back();

  expansion->parsed_begin_index = parsed_begin_index;
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

  // Find the name, e.g. `defined`.
  if (!expansion->nodes.empty() &&
      std::holds_alternative<MacroTokenImpl *>(expansion->nodes.back())) {
    MacroTokenImpl *ident = std::get<MacroTokenImpl *>(
        expansion->nodes.back());
    if (ident->IsIdentifierLike()) {
      expansion->name = expansion->nodes.back();
    }
  }

  assert(std::holds_alternative<MacroTokenImpl *>(expansion->name));
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

void PatchedMacroTracker::DoBeginConcatenation(
    const clang::Token &tok, uintptr_t data) {

  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  if (expansion->has_body && !expansion->done_processing_body) {
    expansion->has_interesting_body = true;
  }

  assert(!last_concatenation);
  Push(tok);
  MacroSubstitutionImpl *concat =
      &(ast->root_macro_node.substitutions.emplace_back());
  D( concat->line_added = __LINE__; )

  concat->parsed_begin_index = parsed_begin_index;
  concat->kind = MacroKind::kConcatenate;
  concat->parent = nodes.back();
  nodes.push_back(concat);
  substitutions.push_back(concat);
  DoToken(tok, data);

  // NOTE(pag): We *DO NOT* call `AddToParentNode` so that we can re-parent
  //            this sub-tree whenever we read the next token. The order of
  //            events that we will observe will go roughly like this:
  //
  //                BeginConcatenation
  //                  ConcatenationOperatorToken
  //                  ConcatenationAccumulationToken
  //                EndConcatenation
  //                TokenFromTokenLexer
  //
  //            Where the `TokenFromTokenLexer` represents the result of
  //            concatenation. However, we might also see a macro expansion
  //            there.
}

void PatchedMacroTracker::DoConcatenationOperatorToken(
    const clang::Token &tok, uintptr_t data) {
  DoToken(tok, data);
}

void PatchedMacroTracker::DoConcatenationAccumulationToken(
    const clang::Token &tok, uintptr_t data) {
  DoToken(tok, data);
}

void PatchedMacroTracker::DoEndConcatenation(
    const clang::Token &tok, uintptr_t data) {
  assert(!substitutions.empty());
  assert(nodes.back() == substitutions.back());
  assert(!last_concatenation);
  last_concatenation = substitutions.back();
  assert(last_concatenation->kind == MacroKind::kConcatenate);
  assert(!last_concatenation->nodes.empty());

  // NOTE(bpappas): Since token concatenation is a binary operation between two
  //                tokens, we expect there to be at least three nodes: the left
  //                token, the concatenation operator, and the right token.
  assert(last_concatenation->nodes.size() >= 3);
  assert(last_concatenation->use_nodes.empty());
  last_concatenation->name = *(last_concatenation->nodes.begin() + 1);
  last_concatenation->nodes.swap(last_concatenation->use_nodes);
  Pop(tok);
  nodes.pop_back();
  substitutions.pop_back();
}

void PatchedMacroTracker::DoBeforeParameterSubstitutions(
    const clang::Token &tok, uintptr_t data) {
  assert(0 < depth);
  assert(!expansions.empty());
  MacroExpansionImpl *expansion = expansions.back();
  expansion->has_body = true;

  // Calculate the starting position from which we need to clone nodes from
  // the macro body to fill the gaps.
  if (expansion->definition_impl) {
    expansion->next_body_token_to_copy =
        expansion->definition_impl->body_offset;
  }

  // Reset because this phase shouldn't be influenced by repeat tokens coming
  // from the argument pre-expansion phase.
  last_token.startToken();
}

void PatchedMacroTracker::DoAfterParameterSubstitutions(
    const clang::Token &, uintptr_t) {
  assert(0 < depth);
  assert(!expansions.empty());
  assert(expansions.back()->has_body);

  MacroExpansionImpl *expansion = expansions.back();
  expansion->done_processing_body = true;

  // Fill the trailing tokens.
  expansion->CopyFromBody(*ast, expansion, ~OpaqueSourceLoc());

  // Reset because this phase shouldn't influence repeat tokens coming
  // from the final expansion phase.
  last_token.startToken();
}

// This is an out-of-band signal. The way Clang does parameter substitution
// is by first doing argument pre-expansion, then iterating over the macro body
// tokens in `clang::TokenLexer::ExpandFunctionArguments`, and collecting the
// expanded substituted tokens into an array. When it comes across macro
// parameters, it injects in the corresponding (expanded) argument tokens.
//
// NOTE(pag): In the case of `__VA_ARGS__`, Clang does not inject the results of
//            argument pre-expansion, but the original arguments. This can
//            in anomolous-seeming expansions that have no uses.
void PatchedMacroTracker::DoBeforeMacroParameterUse(
    const clang::Token &tok_, uintptr_t num_tokens) {
  assert(0 < depth);
  assert(0u < num_tokens);  // There should always be an `EOF`.
  assert(!expansions.empty());
  assert(params.empty());
  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->has_body);

  expansion->has_interesting_body = true;

  MacroParameterSubstitutionImpl *param = &(
      ast->root_macro_node.parameter_substitutions.emplace_back());

  MacroNodeImpl *parent = nodes.back();

  const clang::Token *tok = &tok_;
  clang::Token ident = tok[num_tokens - 1u];
  assert(ident.isAnyIdentifier() ||
         clang::tok::getKeywordSpelling(ident.getKind()));

  // Parameter uses can have leading whitespace following line continuations.
  clang::SourceLocation ident_loc = ident.getLocation();
  std::string &ident_data = tok_data_vec[next_tok_data++ % tok_data_vec.size()];
  ident_data.clear();
  if (TryReadRawToken(sm, lo, ident, &ident_data)) {
    SkipLeadingWhitespace(ident, ident_loc, ident_data);
    SkipTrailingWhitespace(ident_data);
  }

  // Fill the preceding tokens.
  expansion->CopyFromBody(*ast, parent, ident_loc.getRawEncoding());

  // Then put our new node in.
  param->parsed_begin_index = parsed_begin_index;
  param->parent = parent;

  if (parent == expansion) {
    expansion->body.emplace_back(param);
  } else {
    nodes.back()->nodes.emplace_back(param);
  }

  if (clang::IdentifierInfo *ii = ident.getIdentifierInfo();
      ii && expansion->defined_macro) {
    param->number = expansion->defined_macro->getParameterNum(ii);
  }

  if (-1 < param->number && expansion->definition_impl) {
    auto param_num = static_cast<unsigned>(param->number);
    if (param_num < expansion->definition_impl->parameters.size()) {
      param->param_in_definition =
          expansion->definition_impl->parameters[param_num];
    }
  }

  assert(param->number != -1);
  assert(std::holds_alternative<MacroNodeImpl *>(param->param_in_definition));

  nodes.push_back(param);
  params.push_back(param);

  DoToken(ident, 0);

  assert(!param->nodes.empty());
  assert(param->use_nodes.empty());
  param->nodes.swap(param->use_nodes);

  param->prev_tok_index = static_cast<int>(num_tokens) - 2;
  assert(-1 <= param->prev_tok_index);

  if (0 <= param->prev_tok_index) {
    param->prev_tok = tok[param->prev_tok_index];
    param->prev_tok_loc = param->prev_tok.getLocation().getRawEncoding();
  }
}

void PatchedMacroTracker::DoAfterMacroParameterUse(
    const clang::Token &tok_, uintptr_t num_tokens) {
  assert(0 < depth);
  assert(!expansions.empty());
  assert(!params.empty());
  assert(nodes.back() == params.back());

  MacroParameterSubstitutionImpl *param = params.back();

  assert(param->nodes.empty());
  assert(!param->use_nodes.empty());
  assert(-1 <= param->prev_tok_index);
  assert(std::holds_alternative<MacroNodeImpl *>(param->param_in_definition));
  param->name = param->use_nodes.front();

  const clang::Token *tok = &tok_;

  if (0 <= param->prev_tok_index) {

    // Some tokens were deleted during the substitution of this parameter's
    // tokens.
    if (param->prev_tok_index > static_cast<int>(num_tokens)) {
      D( std::cerr << indent << "! failed to align parameter (1)\n"; )
      param->failed = true;
      assert(false);

    // A possible alignment failure.
    } else if (tok[param->prev_tok_index].getLocation().getRawEncoding() !=
               param->prev_tok_loc) {

      // In the case of `..., ##__VA_ARGS__`, the `##` is removed, and so we
      // need to adjust out index so that we don't accidentally go and skip
      // the first substituted in for the argument.
      if (param->prev_tok.is(clang::tok::hashhash) &&
          0 < param->prev_tok_index) {
        param->prev_tok_index -= 1;

      } else {
        D( std::cerr << indent << "! failed to align parameter (2)\n"; )
        param->failed = true;
        assert(false);
      }
    }
  }

  if (!param->failed) {

    // Collect the argument tokens, and then map the locations of the parameters
    // to the parameter and the location in the `Parameter::argument_toks` of
    // the token.
    for (auto i = static_cast<unsigned>(param->prev_tok_index + 1);
         i < num_tokens && !tok[i].is(clang::tok::eof); ++i) {
      DoToken(tok[i], 0);
    }
  }

  params.pop_back();
  nodes.pop_back();

  D( std::cerr << indent << "* parameter is replaced with "
               << param->nodes.size() << " tokens\n"; )
}

void PatchedMacroTracker::DoBeforeVAOpt(
    const clang::Token &tok_, uintptr_t num_tokens) {
  assert(0 < depth);
  assert(!vaopt_arg);
  assert(2u <= num_tokens);  // There should always be an `EOF`.
  assert(!expansions.empty());
  assert(!vaopt);

  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->has_body);

  expansion->has_interesting_body = true;

  vaopt = &(ast->root_macro_node.vaopts.emplace_back());

  MacroNodeImpl *parent = nodes.back();
  const clang::Token *tok = &tok_;
  assert(tok[num_tokens - 1u].is(clang::tok::l_paren));
  assert(tok[num_tokens - 2u].is(clang::tok::identifier));

  // Fill the preceding tokens.
  expansion->CopyFromBody(
      *ast, parent, tok[num_tokens - 2u].getLocation().getRawEncoding());

  // Now add our new node in.
  vaopt->parsed_begin_index = parsed_begin_index;
  vaopt->parent = parent;

  if (parent == expansion) {
    expansion->body.emplace_back(vaopt);
  } else {
    nodes.back()->nodes.emplace_back(vaopt);
  }

  // NOTE(pag): `getNumParams` includes a single entry for the variadic
  //            parameter.
  if (expansion->defined_macro &&
      expansion->arguments.size() >= expansion->defined_macro->getNumParams()) {
    vaopt->is_elided = false;
  }

  nodes.push_back(vaopt);

  DoToken(tok[num_tokens - 2u], 0);
  DoToken(tok[num_tokens - 1u], 0);

  // Add the VAOpt argument in.
  vaopt_arg =
      &(ast->root_macro_node.vaopt_arguments.emplace_back());

  vaopt_arg->parsed_begin_index = parsed_begin_index;
  vaopt_arg->parent = vaopt;
  vaopt->nodes.push_back(vaopt_arg);

  nodes.push_back(vaopt_arg);
}

void PatchedMacroTracker::DoAfterVAOpt(
    const clang::Token &tok_, uintptr_t num_tokens) {
  assert(0 < depth);
  assert(vaopt != nullptr);
  assert(vaopt_arg != nullptr);
  assert(1u <= num_tokens);
  assert(nodes.back() == vaopt_arg);
  assert(!expansions.empty());

  MacroExpansionImpl *expansion = expansions.back();

  // The last token on the list is this `__VA_OPT__`s closing parenthesis.
  const clang::Token *tok = &tok_;
  assert(tok[num_tokens - 1u].is(clang::tok::r_paren));

  // Fill the preceding tokens.
  expansion->CopyFromBody(
      *ast, vaopt_arg, tok[num_tokens - 1u].getLocation().getRawEncoding());

  // Pop off the `vaopt_arg`.
  nodes.pop_back();
  vaopt_arg = nullptr;

  assert(!nodes.empty());
  assert(nodes.back() == vaopt);

  DoToken(tok[num_tokens - 1u], 0);

  nodes.pop_back();
  vaopt = nullptr;
}

void PatchedMacroTracker::DoBeforeStringify(
    const clang::Token &tok_, uintptr_t num_tokens) {
  assert(0 < depth);
  assert(1u <= num_tokens);  // There should always be an `EOF`.
  assert(!expansions.empty());

  MacroExpansionImpl *expansion = expansions.back();
  assert(expansion->has_body);

  MacroSubstitutionImpl *str =
      &(ast->root_macro_node.substitutions.emplace_back());

  str->parsed_begin_index = parsed_begin_index;
  str->kind = MacroKind::kStringify;

  expansion->has_interesting_body = true;

  MacroNodeImpl *parent = nodes.back();

  const clang::Token *tok = &tok_;
  assert(tok[num_tokens - 1u].isOneOf(clang::tok::hash, clang::tok::hashat));

  // Fill the preceding tokens.
  expansion->CopyFromBody(
      *ast, parent, tok[num_tokens - 1u].getLocation().getRawEncoding());

  // Now add our new node in.
  str->parent = parent;
  if (parent == expansion) {
    expansion->body.emplace_back(str);
  } else {
    nodes.back()->nodes.emplace_back(str);
  }

  nodes.push_back(str);
  stringifies.push_back(str);

  DoToken(tok[num_tokens - 1u], 0);  // Put the `#` into `expansion`.
}

void PatchedMacroTracker::DoAfterStringify(
    const clang::Token &tok_, uintptr_t num_tokens) {
  assert(0 < depth);
  assert(0 < num_tokens);  // There should always be an `EOF`.
  assert(!expansions.empty());
  assert(!stringifies.empty());
  assert(stringifies.back() == nodes.back());

  MacroSubstitutionImpl *str = stringifies.back();
  assert(str->kind == MacroKind::kStringify);

  assert(str->use_nodes.empty());
  str->name = str->nodes.front();
  str->nodes.swap(str->use_nodes);

  const clang::Token *tok = &tok_;
  if (tok[num_tokens - 1u].isOneOf(clang::tok::char_constant,
                                   clang::tok::wide_char_constant,
                                   clang::tok::utf8_char_constant,
                                   clang::tok::utf16_char_constant,
                                   clang::tok::utf32_char_constant,
                                   clang::tok::string_literal,
                                   clang::tok::wide_string_literal,
                                   clang::tok::header_name,
                                   clang::tok::utf8_string_literal,
                                   clang::tok::utf16_string_literal,
                                   clang::tok::utf32_string_literal)) {
    DoToken(tok[num_tokens - 1u], 0);
  }

  stringifies.pop_back();
  nodes.pop_back();
}

namespace detail {
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, CurTokenLexer, std::unique_ptr<clang::TokenLexer>);
#define REF_CurTokenLexer(pp) (pp.*PASTA_ACCESS_MEMBER(clang, Preprocessor, CurTokenLexer))

PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, TokenLexer, IsReinject, bool);
#define PTR_IsReinject(ctl) (ctl->*PASTA_ACCESS_MEMBER(clang, TokenLexer, IsReinject))

//PASTA_BYPASS_CONST_MEMBER_FUNCTION_ACCESS(clang, PreprocessorLexer, getConditionalStackDepth, unsigned);
//PASTA_BYPASS_MEMBER_FUNCTION_ACCESS(clang, PreprocessorLexer, peekConditionalLevel, clang::PPConditionalInfo &);
//#define PTR_getConditionalStackDepth(ctl) (ctl->*PASTA_ACCESS_MEMBER(clang, PreprocessorLexer, getConditionalStackDepth))()
//#define PTR_peekConditionalLevel(ctl) (ctl->*PASTA_ACCESS_MEMBER(clang, PreprocessorLexer, peekConditionalLevel))()

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
    case EndMacroCallArgumentList:
      DoEndMacroCallArgumentList(tok, data);
      break;
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

    // We don't expect these because they should only be raised during parsing,
    // and the patched macro tracker is attached to a different preprocessor.
    case SplitToken: assert(false); break;
    case LAngleToken: assert(false); break;
    case RAngleToken: assert(false); break;

    case BeginConcatenation: DoBeginConcatenation(tok, data); break;
    case ConcatenationOperatorToken: DoConcatenationOperatorToken(tok, data); break;
    case ConcatenationAccumulationToken: DoConcatenationAccumulationToken(tok, data); break;
    case EndConcatenation: DoEndConcatenation(tok, data); break;

    case BeforeParameterSubstitutions: DoBeforeParameterSubstitutions(tok, data); break;
    case AfterParameterSubstitutions: DoAfterParameterSubstitutions(tok, data); break;
    case BeforeVAOpt: DoBeforeVAOpt(tok, data); break;
    case AfterVAOpt: DoAfterVAOpt(tok, data); break;
    case BeforeStringify: DoBeforeStringify(tok, data); break;
    case AfterStringify: DoAfterStringify(tok, data); break;
    case BeforeMacroParameterUse: DoBeforeMacroParameterUse(tok, data); break;
    case AfterMacroParameterUse: DoAfterMacroParameterUse(tok, data); break;
    case BeforeRemoveCommas: break;
    case AfterRemoveCommas: break;
    case BeforeConcatenation: break;
    case AfterConcatenation: break;
    case SkippedVAOptToken: break;
  }

  last_event = kind;

#if D(1 -) 0
  switch (kind) {
    case EndDirective:
    case EndNonDirective:
    case EndMacroExpansion:
    case EndMacroCallArgumentList:
    case EndMacroCallArgument:
    case EndVariadicCallArgumentList:
    case EndSubstitution:
    case EndPreArgumentExpansion:
    case EndConcatenation:
    case CancelExpansion:
    case AfterParameterSubstitutions:
    case AfterVAOpt:
    case AfterStringify:
    case AfterMacroParameterUse:
    case AfterRemoveCommas:
//    case AfterConcatenation:
//        --depth;
      if (!suppress_indent) {
        indent.resize(indent.size() - 2);
      }
      suppress_indent = false;
      break;
    default:
      break;
  }

  std::cerr << indent;

  switch (kind) {
    case TokenFromLexer: std::cerr << "TokenFromLexer(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case TokenFromTokenLexer: std::cerr << "TokenFromTokenLexer(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case TokenFromCachingLexer: std::cerr << "TokenFromCachingLexer(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case TokenFromAfterModuleImportLexer: std::cerr << "TokenFromAfterModuleImportLexer(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case SkippedVAOptToken: std::cerr << "SkippedVAOptToken(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case ConcatenationOperatorToken: std::cerr << "ConcatenationOperatorToken(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case ConcatenationAccumulationToken: std::cerr << "ConcatenationAccumulationToken(" << ast->macro_tokens.size() << "; depth=" << depth << "; macro_skip_count=" << macro_skip_count << "; cond_skip_depth=" << cond_skip_depth << "; loc=" << tok.getLocation().getRawEncoding() << ")"; break;
    case SplitToken: std::cerr << "SplitToken"; break;
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
    case BeginConcatenation: std::cerr << "BeginConcatenation"; break;
    case EndConcatenation: std::cerr << "EndConcatenation"; break;
    case BeforeParameterSubstitutions: std::cerr << "BeforeParameterSubstitutions"; break;
    case AfterParameterSubstitutions: std::cerr << "AfterParameterSubstitutions"; break;
    case BeforeVAOpt: std::cerr << "BeforeVAOpt"; break;
    case AfterVAOpt: std::cerr << "AfterVAOpt"; break;
    case BeforeStringify: std::cerr << "BeforeStringify"; break;
    case AfterStringify: std::cerr << "AfterStringify"; break;
    case BeforeMacroParameterUse: std::cerr << "BeforeMacroParameterUse"; break;
    case AfterMacroParameterUse: std::cerr << "AfterMacroParameterUse"; break;
    case BeforeRemoveCommas: std::cerr << "BeforeRemoveCommas"; break;
    case AfterRemoveCommas: std::cerr << "AfterRemoveCommas"; break;
    case BeforeConcatenation: std::cerr << "BeforeConcatenation"; break;
    case AfterConcatenation: std::cerr << "AfterConcatenation"; break;
    case LAngleToken: std::cerr << "LAngleToken"; break;
    case RAngleToken: std::cerr << "RAngleToken"; break;
  }

  // NOTE(pag): For the `Before*` and `After*` events, the token argument
  //            represents the first thing in a possibly empty list, so it
  //            might not be valid.
  if (reinterpret_cast<uintptr_t>(&tok) &&
      tok.getKind() < clang::tok::NUM_TOKENS) {
    std::cerr
        << ' ' << clang::tok::getTokenName(tok.getKind())
        << " loc=" << tok.getLocation().getRawEncoding();
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
  }

  // TODO(pag): `BeforeConcatenation` and `AfterConcatenation` don't properly
  //            balance in all cases.

  switch (kind) {
    case BeginDirective:
    case BeginSkippedArea:
    case BeginMacroExpansion:
    case BeginMacroCallArgumentList:
    case BeginMacroCallArgument:
    case BeginVariadicCallArgumentList:
    case BeginSubstitution:
    case BeginDelayedSubstitution:
    case BeginPreArgumentExpansion:
    case BeginConcatenation:
    case BeforeParameterSubstitutions:
    case BeforeVAOpt:
    case BeforeStringify:
    case BeforeMacroParameterUse:
    case BeforeRemoveCommas:
//    case BeforeConcatenation:
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
      clang::OptionalFileEntryRef file_ref,
      llvm::StringRef /* search_path */,
      llvm::StringRef /* relative_path */,
      const clang::Module * /* imported */,
      clang::SrcMgr::CharacteristicKind /* file_type */) {

  assert(last_directive != nullptr);
  switch (include_tok.getIdentifierInfo()->getPPKeywordID()) {
    case clang::tok::pp_include:
      assert(last_directive->kind == MacroKind::kOtherDirective ||
             last_directive->kind == MacroKind::kIncludeDirective);
      last_directive->kind = MacroKind::kIncludeDirective;
      break;
    case clang::tok::pp_include_next:
      assert(last_directive->kind == MacroKind::kOtherDirective ||
             last_directive->kind == MacroKind::kIncludeNextDirective);
      last_directive->kind = MacroKind::kIncludeNextDirective;
      break;
    case clang::tok::pp_import:
      assert(last_directive->kind == MacroKind::kOtherDirective ||
             last_directive->kind == MacroKind::kImportDirective);
      last_directive->kind = MacroKind::kImportDirective;
      break;
    case clang::tok::pp___include_macros:
      assert(last_directive->kind == MacroKind::kOtherDirective ||
             last_directive->kind == MacroKind::kIncludeMacrosDirective);
      last_directive->kind = MacroKind::kIncludeMacrosDirective;
      break;
    default:
      assert(false);
      D( std::cerr << " ???\n"; )
      return;
  }

  // Get the file associated with the include. We need to do a bit of work to
  // get it when the file is actually ignored. Experimentation shows that using
  // `getOrCreateFileID` with `file_type` does the wrong thing.
  if (file_ref.has_value() && !last_directive->included_file) {
    const clang::FileEntry &fe = file_ref->getFileEntry();
    clang::SourceLocation loc = sm.translateFileLineCol(&fe, 1, 1);
    if (loc.isValid() && loc.isFileID()) {
      auto [fid, offset] = sm.getDecomposedLoc(loc);
      D( std::cerr << indent << "Including file id " << fid.getHashValue()
                   << '\n'; )
      if (auto it = ast->id_to_file.find(fid.getHashValue());
          it != ast->id_to_file.end()) {
        last_directive->included_file.emplace(it->second);
        D( std::cerr << indent << "Including file "
                     << last_directive->included_file->Path().generic_string()
                     << '\n'; )
      }
    }
  }

  D( std::cerr << indent << "InclusionDirective\n"; )
}

// Each time we enter a source file, try to keep track of it.
void PatchedMacroTracker::FileChanged(
    clang::SourceLocation loc, clang::PPCallbacks::FileChangeReason reason,
    clang::SrcMgr::CharacteristicKind file_type, clang::FileID file_id) {

  // Save off the Clang's current state of the `__COUNTER__` macro back to
  // be associated with the last `__COUNTER__` value associated with that
  // file hash.
  next_counter_value[last_counter_id] = pp.getCounterValue();

  D( std::cerr << "last_counter_id=" << last_counter_id << " last __COUNTER__="
               << pp.getCounterValue() << '\n';)
  last_counter_id = 0;

  if (!loc.isValid()) {
    loc = sm.getComposedLoc(file_id, 0u);
  }

  // Figure out the next value for `__COUNTER__` to use for the current file.
  std::optional<File> file;
  unsigned offset = 0u;
  if (loc.isValid() && loc.isFileID()) {
    std::tie(file_id, offset) = sm.getDecomposedLoc(loc);
    if (auto it = ast->id_to_file.find(file_id.getHashValue());
        it != ast->id_to_file.end()) {
      file.emplace(it->second);
      if (auto maybe_hash = file->DataHash()) {
        last_counter_id = static_cast<unsigned>(maybe_hash.value()) << 9u;
        next_counter_value.emplace(last_counter_id, last_counter_id);
      }
    }
  }

  // Tell Clang where to resume with `__COUNTER__`.
  pp.setCounterValue(next_counter_value[last_counter_id]);

  D( std::cerr << "NEXT last_counter_id=" << last_counter_id
               << " last __COUNTER__=" << pp.getCounterValue() << '\n';)

  if (clang::PPCallbacks::FileChangeReason::EnterFile == reason &&
      loc.isValid() && last_directive &&
      (last_directive->kind == MacroKind::kIncludeDirective ||
       last_directive->kind == MacroKind::kIncludeNextDirective ||
       last_directive->kind == MacroKind::kIncludeMacrosDirective ||
       last_directive->kind == MacroKind::kImportDirective)) {

    last_directive->included_file = std::move(file);
    includes.push_back(last_directive);
    D( std::cerr << indent << "BeginOfFileMarker\n"; )

    ast->parsed_tokens.AppendMarkerToken(loc, TokenRole::kBeginOfFileMarker);

  // Transition from predefins to the main file.
  } else if (clang::PPCallbacks::FileChangeReason::ExitFile == reason &&
             file_id == pp.getPredefinesFileID()) {

    ast->parsed_tokens.AppendMarkerToken(
        sm.getComposedLoc(sm.getMainFileID(), 0),
        TokenRole::kBeginOfFileMarker);
    D( std::cerr << indent << "BeginOfFileMarker\n"; )

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
    ast->parsed_tokens.AppendMarkerToken(sm.getLocForEndOfFile(file_id),
                                         TokenRole::kEndOfFileMarker);
  }

  D( std::cerr << indent << "FileChanged reason=" << int(reason)
               << " file_type=" << int(file_type)
               << " file_id=" << file_id.getHashValue() << '\n'; )
}

// Called when we leave the main file.
void PatchedMacroTracker::EndOfMainFile(void) {
  D( std::cerr << indent << "EndOfMainFile\n"; )
  ast->macro_tokens.Finalize();
  clang::SourceLocation loc = sm.getLocForEndOfFile(sm.getMainFileID());
  ast->parsed_tokens.AppendMarkerToken(loc, TokenRole::kEndOfFileMarker);
  ast->parsed_tokens.Finalize();
}

// Callback invoked when a `#ident` or `#sccs` directive is read. These are
// supposedly related to System V and don't really get used widely.
void PatchedMacroTracker::Ident(clang::SourceLocation, clang::StringRef) {
  D( std::cerr << indent << "Ident\n"; )
}

// Callback invoked when start reading any pragma directive.
void PatchedMacroTracker::PragmaDirective(
    clang::SourceLocation loc, clang::PragmaIntroducerKind introducer) {

  D( std::cerr << indent << "Pragma\n"; )

  assert(!directives.empty());
  MacroDirectiveImpl *directive = directives.back();
  assert(directive->kind == MacroKind::kOtherDirective ||
         directive->kind == MacroKind::kPragmaDirective);

  switch (introducer) {
    case clang::PragmaIntroducerKind::PIK_HashPragma:
    case clang::PragmaIntroducerKind::PIK__Pragma:  // C99.
    case clang::PragmaIntroducerKind::PIK___pragma:  // Microsoft.
      directive->kind = MacroKind::kPragmaDirective;
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
                             ConditionValueKind cvk) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kIfDirective);
    last_directive->kind = MacroKind::kIfDirective;

    // Clang doesn't really do this.
    assert(ConditionValueKind::CVK_NotEvaluated != cvk);

    last_directive->is_skipped = ConditionValueKind::CVK_NotEvaluated == cvk ||
                                 ConditionValueKind::CVK_False == cvk;
    if (last_directive->is_skipped && !cond_skip_depth) {
      cond_skip_depth = 1;
      D( std::cerr << indent << "Initializing skip depth = 1 (case 1)\n"; )
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

  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kElseIfDirective);
    last_directive->kind = MacroKind::kElseIfDirective;
    last_directive->is_skipped = ConditionValueKind::CVK_NotEvaluated == cvk ||
                                 ConditionValueKind::CVK_False == cvk;

    if (last_directive->is_skipped) {
      assert(1 >= cond_skip_depth);
      cond_skip_depth = 1;
      D( std::cerr << indent << "Elif not taken, setting skip count = 1\n"; )
    }
  }
  D( std::cerr << indent << "Elif\n"; )
}

// Hook called whenever an `#ifdef` is seen.
void PatchedMacroTracker::Ifdef(clang::SourceLocation,
                                const clang::Token & /* macro_name_tested */,
                                const clang::MacroDefinition &) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kIfDefinedDirective);
    last_directive->kind = MacroKind::kIfDefinedDirective;
  }
  D( std::cerr << indent << "Ifdef\n"; )
}

// Hook called whenever an `#ifndef` is seen.
void PatchedMacroTracker::Ifndef(clang::SourceLocation,
                                 const clang::Token & /* macro_name_tested */,
                                 const clang::MacroDefinition &) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kIfNotDefinedDirective);
    last_directive->kind = MacroKind::kIfNotDefinedDirective;
  }
  D( std::cerr << indent << "Ifndef\n"; )
}

// Hook called whenever an `#elifdef` branch is taken.
void PatchedMacroTracker::Elifdef(clang::SourceLocation, const clang::Token &,
                                  const clang::MacroDefinition &) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kElseIfDefinedDirective);
    last_directive->kind = MacroKind::kElseIfDefinedDirective;
    last_directive->is_skipped = false;

    D( std::cerr << indent << "Elifdef taken cond_skip_depth="
                 << cond_skip_depth << " setting to 0\n"; )
    assert(1 >= cond_skip_depth);
    cond_skip_depth = 0;
  }
  D( std::cerr << indent << "Elifdef\n"; )
}

// Hook called whenever an `#elifdef` is skipped.
void PatchedMacroTracker::Elifdef(clang::SourceLocation, clang::SourceRange,
                                  clang::SourceLocation) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kElseIfDefinedDirective);
    last_directive->kind = MacroKind::kElseIfDefinedDirective;

    D( std::cerr << indent << "Elifdef not taken cond_skip_depth="
                 << cond_skip_depth << "\n"; )
    if (!cond_skip_depth) {
      D( std::cerr << indent << "Setting cond_skip_depth = 1 (elifdef)\n"; )
      cond_skip_depth = 1;
    }

//    last_directive->is_skipped = true;
  }
  D( std::cerr << indent << "Elifdef\n"; )
}

// Hook called whenever an `#elifndef` branch is taken.
void PatchedMacroTracker::Elifndef(clang::SourceLocation, const clang::Token &,
                                   const clang::MacroDefinition &) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kElseIfNotDefinedDirective);
    last_directive->kind = MacroKind::kElseIfNotDefinedDirective;
    last_directive->is_skipped = false;

    D( std::cerr << indent << "Elifndef taken cond_skip_depth="
                 << cond_skip_depth << " setting to 0\n"; )
    assert(1 >= cond_skip_depth);
    cond_skip_depth = 0;
  }
  D( std::cerr << indent << "Elifndef\n"; )
}

// Hook called whenever an `#elifndef` is skipped.
void PatchedMacroTracker::Elifndef(clang::SourceLocation, clang::SourceRange,
                                   clang::SourceLocation) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kElseIfNotDefinedDirective);
    last_directive->kind = MacroKind::kElseIfNotDefinedDirective;


    D( std::cerr << indent << "Elifdef not taken cond_skip_depth="
                 << cond_skip_depth << "\n"; )
    if (!cond_skip_depth) {
      D( std::cerr << indent << "Setting cond_skip_depth = 1 (elifndef)\n"; )
      cond_skip_depth = 1;
    }
  }
  D( std::cerr << indent << "Elifndef\n"; )
}

/// Hook called whenever an `#else` is seen.
void PatchedMacroTracker::Else(clang::SourceLocation,
                               clang::SourceLocation /* if_loc */) {
  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kElseDirective);
    last_directive->kind = MacroKind::kElseDirective;
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

  if (last_directive) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kEndIfDirective);
    last_directive->kind = MacroKind::kEndIfDirective;
  }
  D( std::cerr << indent << "Endif\n"; )
}

// Hook called whenever a macro definition is seen.
void PatchedMacroTracker::MacroDefined(const clang::Token &name_tok,
                                       const clang::MacroDirective *directive) {
  assert(!cond_skip_depth);

  D( std::cerr << indent << "MacroDefined\n"; )
  if (last_directive == nullptr) {
    return;
  }

  assert(last_directive->kind == MacroKind::kOtherDirective ||
         last_directive->kind == MacroKind::kDefineDirective);
  last_directive->kind = MacroKind::kDefineDirective;

  if (directive) {
    last_directive->defined_macro = directive->getMacroInfo();
    defines[last_directive->defined_macro] = last_directive;
  }

  NodeList new_nodes;

  // Go find the macro name.
  auto i = 0u;  // Skip past `#`, and possibly past the `define`.
  auto max_i = last_directive->nodes.size();
  bool name_found = false;
  for (; i < max_i; ++i) {
    Node &node = last_directive->nodes[i];
    new_nodes.push_back(node);
    if (!std::holds_alternative<MacroTokenImpl *>(node)) {
      continue;
    }

    auto tok_offset = std::get<MacroTokenImpl *>(node)->token_offset;
    auto tok_loc = ast->macro_tokens.OriginalLocation(tok_offset);
    
    // NOTE(pag): Timing of this callback might be an issue.
    assert(tok_loc.isValid());

    if (tok_loc == name_tok.getLocation()) {
      last_directive->macro_name = node;
      name_found = true;
      break;
    }
  }

  assert(name_found);

  if (directive && name_found) {
    last_directive->defined_macro = directive->getMacroInfo();
    defines[last_directive->defined_macro] = last_directive;
    DerivedTokenIndex tok_offset = std::get<MacroTokenImpl *>(
        last_directive->macro_name)->token_offset;

    ast->macro_tokens.MarkAsMacroName(tok_offset, last_directive);
  }

  ++i;  // Skip over the name;

  // Go look for parameters and retroactively introduce them.
  if (last_directive->defined_macro &&
      last_directive->defined_macro->isFunctionLike()) {
    bool found_l_paren = false;
    for (; i < max_i && name_found; ++i) {
      Node &node = last_directive->nodes[i];
      new_nodes.push_back(node);
      if (std::holds_alternative<MacroTokenImpl *>(node)) {
        MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
        if (tok->kind == TokenKind::kLParenthesis) {
          found_l_paren = true;
          break;
        }
      }
    }

    ++i;  // Skip l paren.
    bool found_r_paren = false;
    MacroParameterImpl *last_param = nullptr;

    for (; i < max_i && found_l_paren && !found_r_paren; ++i) {
      Node &node = last_directive->nodes[i];
      new_nodes.push_back(node);
      if (!std::holds_alternative<MacroTokenImpl *>(node)) {
        continue;
      }

      MacroTokenImpl *tok = std::get<MacroTokenImpl *>(node);
      switch (auto tk = tok->kind) {
        case TokenKind::kHash:
        case TokenKind::kHashHash:
          assert(found_r_paren);
          last_param = nullptr;
          break;
        case TokenKind::kRParenthesis:
          last_param = nullptr;
          found_r_paren = true;
          break;
        case TokenKind::kComma:
          last_param = nullptr;
          break;
        case TokenKind::kEllipsis:
          new_nodes.pop_back();
          if (last_param) {
            assert(!last_param->is_variadic);
            last_param->is_variadic = true;
            ReparentNode(node, last_param);
            last_param->nodes.push_back(node);
          } else {
            last_param = &(ast->root_macro_node.parameters.emplace_back());
            last_param->parsed_begin_index = parsed_begin_index;
            last_param->parent = last_directive;
            last_param->is_variadic = true;
            last_param->index = static_cast<unsigned>(
                last_directive->parameters.size());
            last_directive->parameters.emplace_back(last_param);
            ReparentNode(node, last_param);
            last_param->nodes.push_back(node);
            new_nodes.push_back(last_param);
          }
          break;

        identifier_like:
        case TokenKind::kIdentifier:
        case TokenKind::kRawIdentifier: {
          assert(!last_param);
          new_nodes.pop_back();
          last_param = &(ast->root_macro_node.parameters.emplace_back());
          last_param->parsed_begin_index = parsed_begin_index;
          last_param->parent = last_directive;
          last_param->has_name = true;
          last_param->index = static_cast<unsigned>(
              last_directive->parameters.size());
          last_directive->parameters.emplace_back(last_param);
          ReparentNode(node, last_param);
          last_param->nodes.push_back(node);
          new_nodes.push_back(last_param);
          break;
        }
        default:

          // E.g. in the XNU kernel, there is a macro parameter named `default`.
          if (clang::tok::getKeywordSpelling(
                  static_cast<clang::tok::TokenKind>(tk))) {
            goto identifier_like;
          }

          // E.g. could have comment like `args/*comment*/...` perhaps?
          if (last_param) {
            new_nodes.pop_back();
            ReparentNode(node, last_param);
            last_param->nodes.push_back(node);
          }
          break;
      }
    }

    assert(found_r_paren);

    // NOTE(pag): Use `new_nodes` size because it might have fewer nodes than
    //            `last_directive->nodes`, and so `i` won't be aligned.
    last_directive->body_offset = static_cast<unsigned>(new_nodes.size());

    // Add in the rest.
    for (; i < max_i && found_r_paren; ++i) {
      new_nodes.push_back(std::move(last_directive->nodes[i]));
    }

    assert(i == max_i);

    last_directive->nodes = std::move(new_nodes);

  } else {
    last_directive->body_offset = i;
  }

  assert(std::holds_alternative<MacroTokenImpl *>(last_directive->macro_name));
}

// Hook called whenever a macro `#undef` is seen.
//
// NOTE(pag): `directive` can't be trusted.
void PatchedMacroTracker::MacroUndefined(
    const clang::Token &, const clang::MacroDefinition &,
    const clang::MacroDirective *directive) {
  if (last_directive != nullptr) {
    assert(last_directive->kind == MacroKind::kOtherDirective ||
           last_directive->kind == MacroKind::kUndefineDirective);
    last_directive->kind = MacroKind::kUndefineDirective;
    if (directive) {
      defines.erase(directive->getMacroInfo());
    }
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
