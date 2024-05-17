/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include "AST.h"
#include "Printer/Printer.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/DeclVisitor.h>
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtVisitor.h>
#include <clang/AST/TypeLoc.h>
#include <clang/AST/TypeLocVisitor.h>
#include <clang/Lex/Token.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include <algorithm>
#include <set>
#include <span>
#include <tuple>
#include <unordered_set>
#include <iostream>

#include "Util.h"

namespace pasta {
namespace {

// NOTE(pag): There are definitely missing cases in here.
static const TokenKind kLeadingKeywords[] = {
  TokenKind::kKeywordFriend,
  TokenKind::kKeywordConcept,
  TokenKind::kKeywordUnion,
  TokenKind::kKeywordStruct,
  TokenKind::kKeywordEnum,
  TokenKind::kKeywordClass,
  TokenKind::kKeywordTemplate,
  TokenKind::kKeywordTypeof,
  TokenKind::kKeywordTypeofUnqualified,
  TokenKind::kKeyword_Accum,
  TokenKind::kKeyword_Fract,
  TokenKind::kKeyword_Sat,
  TokenKind::kKeyword_Complex,
  TokenKind::kKeyword_Imaginary,
  TokenKind::kKeyword__Thread,
  TokenKind::kKeyword_ThreadLocal,
  TokenKind::kKeywordAuto,
  TokenKind::kKeywordStatic,
  TokenKind::kKeyword__Attribute,
  TokenKind::kKeyword__Declspec,
  TokenKind::kKeyword_ExtInt,
  TokenKind::kKeyword_BitInt,
  TokenKind::kKeywordExtern,
  TokenKind::kKeywordUnsigned,
  TokenKind::kKeywordSigned,
  TokenKind::kKeywordShort,
  TokenKind::kKeywordLong,
  TokenKind::kKeywordVolatile,
  TokenKind::kKeywordInline,
  TokenKind::kKeywordConst,
  TokenKind::kKeywordConstexpr,
  TokenKind::kKeywordConsteval,
  TokenKind::kKeywordConstinit,
  TokenKind::kKeyword_Noreturn,
  TokenKind::kKeyword__Cdecl,
  TokenKind::kKeyword__Stdcall,
  TokenKind::kKeyword__Fastcall,
  TokenKind::kKeyword__Thiscall,
  TokenKind::kKeyword__Regcall,
  TokenKind::kKeyword__Vectorcall,
  TokenKind::kKeyword__Forceinline,
  TokenKind::kKeyword__Kernel,
  TokenKind::kKeyword__Noinline__,
  TokenKind::kKeyword__PrivateExtern__,
  TokenKind::kKeyword__ModulePrivate__,
  TokenKind::kKeyword__Extension__,
  TokenKind::kKeyword__Alignof,
  TokenKind::kKeyword__Null,
  TokenKind::kKeywordRequires,
  TokenKind::kKeywordOperator,
  TokenKind::kKeywordCharacter,
  TokenKind::kKeywordInt,
  TokenKind::kKeywordRegister,
  TokenKind::kKeywordFloat,
  TokenKind::kKeywordDouble,
  TokenKind::kKeyword_Boolean,
  TokenKind::kKeyword_Alignas,
  TokenKind::kKeyword_Alignof,
  TokenKind::kKeyword_Atomic,
  TokenKind::kKeywordAssembly,
  TokenKind::kKeywordMutable,
  TokenKind::kKeywordTypename,
  TokenKind::kKeywordWcharT,
  TokenKind::kKeywordRestrict,
  TokenKind::kKeywordDecltype,
  TokenKind::kKeywordTypeof,
  TokenKind::kKeywordTypeofUnqualified,
  TokenKind::kKeyword_Decimal32,
  TokenKind::kKeyword_Decimal64,
  TokenKind::kKeyword_Decimal128,
  TokenKind::kKeyword__Float128,
  TokenKind::kKeyword__Ibm128,
  TokenKind::kKeyword__Int128,
  TokenKind::kKeyword__Real,
};

// The decl bounds finder exists to find the beginning and ending of
// declarations. A lot of the best information comes from `clang::TypeLoc`s,
// and some from `Stmt`s.
class DeclBoundsFinder : public clang::DeclVisitor<DeclBoundsFinder>,
                         public clang::TypeLocVisitor<DeclBoundsFinder> {
 private:
  ASTImpl &ast;
  const ParsedTokenIterator invalid;

  std::unordered_set<clang::Decl *> seen_decls;

  ParsedTokenIterator lower_bound;
  ParsedTokenIterator upper_bound;

  clang::Decl *attr_decl{nullptr};

 public:

  ParsedTokenIterator ScanForwardForMatching(ParsedTokenIterator tok,
                                             TokenKind close_tok) {
    if (!tok) {
      return invalid;
    }
 
    auto count = 0;

    do {
      assert(tok.IsParsed());

      switch (auto tok_kind = tok.Kind()) {
        case TokenKind::kLParenthesis:
        case TokenKind::kLBrace:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          ++count;
          break;
        case TokenKind::kRParenthesis:
        case TokenKind::kRBrace:
        case TokenKind::kRSquare:
        case TokenKind::kRAngle:
          if (count) {
            --count;
          }
          if (!count) {
            if (tok_kind == close_tok) {
              return tok;
            }
          }
          break;
        default:
          break;
      }
    } while (tok.Next());

    return invalid;
  }

  ParsedTokenIterator ScanBackwardForMatching(ParsedTokenIterator tok,
                                              TokenKind open_tok) {
    if (!tok) {
      return invalid;
    }

    auto count = 0;
    do {
      assert(tok.IsParsed());

      switch (auto tok_kind = tok.Kind()) {
        case TokenKind::kRParenthesis:
        case TokenKind::kRBrace:
        case TokenKind::kRSquare:
        case TokenKind::kRAngle:
          ++count;
          break;
        case TokenKind::kLParenthesis:
        case TokenKind::kLBrace:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          if (count) {
            --count;
          }
          if (!count) {
            if (tok_kind == open_tok) {
              return tok;
            }
          }
          break;
        default:
          break;
      }
    } while (tok.Previous());

    return invalid;
  }

  static TokenKind BalancedKind(TokenKind kind) {
    switch (kind) {
      case TokenKind::kLParenthesis:
        return TokenKind::kRParenthesis;
      case TokenKind::kLBrace:
        return TokenKind::kRBrace;
      case TokenKind::kLSquare:
        return TokenKind::kRSquare;
      case TokenKind::kLAngle:
        return TokenKind::kRAngle;


      case TokenKind::kRParenthesis:
        return TokenKind::kLParenthesis;
      case TokenKind::kRBrace:
        return TokenKind::kLBrace;
      case TokenKind::kRSquare:
        return TokenKind::kLSquare;
      case TokenKind::kRAngle:
        return TokenKind::kLAngle;

      default:
        return kind;
    }
  } 

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  std::pair<ParsedTokenIterator, ParsedTokenIterator> GetMatching(
      ParsedTokenIterator tok) {
  
    auto tok_offset = tok.Offset();
    switch (auto tok_kind = tok.Kind()) {
      case TokenKind::kLParenthesis:
      case TokenKind::kLBrace:
      case TokenKind::kLSquare:
      case TokenKind::kLAngle: {
        auto &matching_offset = ast.matching[tok_offset];
        if (!matching_offset) {
          auto matching_kind = BalancedKind(tok_kind);
          auto matching_tok = ScanForwardForMatching(tok, matching_kind);
          assert(matching_tok.Kind() == matching_kind);

          matching_offset = matching_tok.Offset();
          assert(tok_offset < matching_offset);
          ast.matching.emplace(matching_offset, tok_offset);
          return {tok, matching_tok};

        } else {
          assert(tok_offset < matching_offset);
          auto matching_tok = tok.WithOffset(matching_offset);
          assert(matching_tok);
          return {tok, matching_tok};
        }
      }

      case TokenKind::kRParenthesis:
      case TokenKind::kRBrace:
      case TokenKind::kRSquare:
      case TokenKind::kRAngle: {
        auto &matching_offset = ast.matching[tok_offset];
        if (!matching_offset) {
          auto matching_kind = BalancedKind(tok_kind);
          auto matching_tok = ScanBackwardForMatching(tok, matching_kind);
          assert(matching_tok.Kind() == matching_kind);

          matching_offset = matching_tok.Offset();
          assert(matching_offset < tok_offset);
          ast.matching.emplace(matching_offset, tok_offset);
          return {matching_tok, tok};
        
        } else {
          assert(matching_offset < tok_offset);
          auto matching_tok = tok.WithOffset(matching_offset);
          assert(matching_tok);
          return {matching_tok, tok};
        }
      }
      default:
        return {invalid, invalid};
    }
  }

  ParsedTokenIterator FindEndOfTagAlt(
      clang::TagDecl *decl) {
    auto tok = ast.RawTokenAt(decl->getLocation());
    if (tok.Data() != decl->getNameAsString()) {
      return invalid;
    }

    bool expect_braces __attribute__((unused)) = false;
    auto ret = invalid;
    for (tok.Next(); tok; tok.Next()) {
      switch (tok.Kind()) {
        case TokenKind::kUnknown:
        case TokenKind::kComment:
        case TokenKind::kIdentifier:
        case TokenKind::kKeyword__Attribute:
          continue;
        case TokenKind::kSemi:
          return tok;
        case TokenKind::kLParenthesis:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          tok = GetMatching(tok).second;
          break;
        case TokenKind::kLBrace:
          if (ret) {
            return ret;
          }
          expect_braces = false;
          tok = GetMatching(tok).second;
          ret = tok;
          break;
        case TokenKind::kColon:
        case TokenKind::kKeywordPublic:
        case TokenKind::kKeywordPrivate:
        case TokenKind::kKeywordProtected:
        case TokenKind::kKeywordVirtual:
          expect_braces = true;
          continue;
        default:
          return ret;
      }
    }

    assert(!expect_braces);
    (void) expect_braces;
    return ret;
  }

  // Scans forward starting from `tok`, assumed to be the beginning of
  // a `TagDecl`, and then looks for a closing `}`, a closing `;`, or the
  // last token before an unbalanced paren/bracket/brace.
  //
  // NOTE(pag): This is pretty important for pulling in trailing attributes on
  //            `TagDecl`s. We have logic in `VisitAttribute` that omits tags,
  //            so this helps.
  //
  // TODO(pag): One corner case could be a tag forward declaration, embedded in
  //            a declarator, that has a declarator. E.g. embedding the tag in
  //            a parameter declaration. I'm not sure if attributes on the tag
  //            there bind to the tag or the param, though.
  ParsedTokenIterator FindEndOfTag(
      clang::TagDecl *decl, ParsedTokenIterator tok) {

    if (!tok) {
      return invalid;
    }

    auto can_have_l_brace = decl->isCompleteDefinition();
    auto can_have_semi = !decl->isEmbeddedInDeclarator();
    auto r_brace = invalid;

    // It can be the case that we have an incomplete template specialization,
    // i.e. a specialization from a template pattern, where the pattern is a
    // definition, but the specialization is only a declaration.
    if (!can_have_l_brace) {
      auto brace_range = decl->getBraceRange();
      r_brace = ast.RawTokenAt(brace_range.getEnd());
      if (can_have_semi && r_brace > tok) {
        tok = r_brace;
        if (!tok.Next()) {
          assert(false);
          return r_brace;
        }
      }
    }

    if (!can_have_l_brace && !can_have_semi) {
      return upper_bound;
    }

    // std::cerr << "Scanning: can_have_l_brace=" << can_have_l_brace
    //           << " can_have_semi=" << can_have_semi << " offset="
    //           << tok.Offset() << " decl=((clang::TagDecl*) "
    //           << reinterpret_cast<void *>(decl) << ")\n";

    auto first = true;
    do {
      assert(tok.IsParsed());
      // std::cerr << tok.Offset() << ' ' << tok.Data() << '\n';
      switch (tok.Kind()) {
        case TokenKind::kLBrace:
          if (can_have_l_brace) {
            r_brace = GetMatching(tok).second;
            tok = r_brace;

          // May actually be valid. We might have 
          } else {
            return r_brace;
          }
          if (!can_have_semi) {
            return r_brace;
          }
          break;

        case TokenKind::kLParenthesis:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          tok = GetMatching(tok).second;
          break;

        case TokenKind::kRBrace:
          if (first && can_have_l_brace) {
            return tok;
          }
          [[fallthrough]];
        case TokenKind::kRParenthesis:
        case TokenKind::kRSquare:
        case TokenKind::kRAngle:
          return r_brace;

        case TokenKind::kSemi:
          if (can_have_semi) {
            return tok;
          } else {
            return r_brace;
          }

        default:
          break;
      }

      first = false;
    } while (tok.Next());

    // std::cerr << "out of loop: " << r_brace.Offset() << ' ' << r_brace.Data() << '\n'; 
    return r_brace;
  }

  // Scans forward starting from `tok`, assumed to be the beginning of
  // a `FunctionDecl`, and then looks for a closing `}`, a closing `;`, or the
  // last token before an unbalanced paren/bracket/brace.
  ParsedTokenIterator FindEndOfFunction(clang::FunctionDecl *decl,
                                        ParsedTokenIterator tok) {

    if (!tok) {
      return invalid;
    }

    int64_t nesting = 0;

    do {
      assert(tok.IsParsed());
      switch (tok.Kind()) {
        case TokenKind::kLParenthesis:
        case TokenKind::kLBrace:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          ++nesting;
          break;
        case TokenKind::kRParenthesis:
          --nesting;
          if (0 > nesting) {
            nesting = 0;  // E.g. function returning a function pointer.
          }
          break;
        case TokenKind::kRSquare:
        case TokenKind::kRAngle:
          --nesting;
          assert(0 <= nesting);
          break;
        case TokenKind::kRBrace:
          --nesting;

          // TODO(pag): Check for C++ functions with try/catch bodies.
          if (!nesting) {
            return tok;
          }

          // Should have seen a semicolon first. Might have a declaration within
          // a declarator, e.g. `void foo(struct bar {} param) { body }`. We
          // start from `foo`.
          assert(0 <= nesting);
          break;
        default:
          break;
      }
    } while (tok.Next());

    return tok;
  }

  bool ExpandLeadingKeywords(std::span<const TokenKind> kinds) {
    auto tok = lower_bound;
    if (!tok.Previous()) {
      return false;
    }

    auto found = false;
    auto junk_budget = 0;
    do {
      assert(tok.IsParsed());

      const auto tok_kind = tok.Kind();

      // `"C"` in `extern "C"`.
      if (tok_kind == TokenKind::kStringLiteral ||
          tok_kind == TokenKind::kWideStringLiteral) {
        ++junk_budget;
        continue;
      }

      // Attributes, template argument/parameter lists.
      if (tok_kind == TokenKind::kRParenthesis ||
          tok_kind == TokenKind::kRSquare ||
          tok_kind == TokenKind::kRAngle) {
        if (junk_budget) {
          return found;
        }

        ParsedTokenIterator matched_end = invalid;
        std::tie(tok, matched_end) = GetMatching(tok);
        continue;
      }

      if (std::find(kinds.begin(), kinds.end(), tok_kind) != kinds.end()) {
        lower_bound = tok;
        found = true;
        junk_budget = 0;  // Reset the budget.
        continue;
      }

      break;
    } while (junk_budget < 2 && tok.Previous());

    return found;
  }

  inline bool ExpandLeadingKeyword(TokenKind kind) {
    const TokenKind kinds[] = {kind};
    return ExpandLeadingKeywords(kinds);
  }

  static ParsedTokenIterator PreviousToken(ParsedTokenIterator tok) {
    tok.Previous();
    return tok;
  }

  static ParsedTokenIterator NextToken(ParsedTokenIterator tok) {
    tok.Next();
    return tok;
  }

  // Scans backward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  ParsedTokenIterator FindPrev(
      ParsedTokenIterator tok, TokenKind kind,
      ParsedTokenIterator exclusive_lower_bound) {
    if (!tok) {
      return invalid;
    }

    ParsedTokenIterator dummy = invalid;

    do {
      if (exclusive_lower_bound && exclusive_lower_bound >= tok) {
        return invalid;
      }

      const auto tok_kind = tok.Kind();
      if (tok_kind == kind) {
        return tok;
      }

      switch (tok_kind) {
        case TokenKind::kLBrace:
          return invalid;
        case TokenKind::kLParenthesis:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          break;
        case TokenKind::kRParenthesis:
        case TokenKind::kRBrace:
        case TokenKind::kRSquare:
        case TokenKind::kRAngle:
          std::tie(tok, dummy) = GetMatching(tok);
          if (BalancedKind(tok_kind) == kind) {
            return tok;
          }
          break;

        // NOTE(pag): This is a heuristic for detecting when things go "too far."
        //            If we were searching for `namespace`, then we would have
        //            matched in in the `if` statement above.
        //
        // NOTE(kumarak): We have gone too far and the token bound should end
        //                if it reaches to a `namespace` that isn't preceded by
        //                `using`.
        case TokenKind::kKeywordNamespace:
          if (PreviousToken(tok).Kind() != TokenKind::kKeywordUsing) {
            assert(false);
            return invalid;
          }
          break;

        default:
          break;
      }
    } while (tok.Previous());

    return invalid;
  }

  // Scans backward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  ParsedTokenIterator FindPrev(
      clang::SourceLocation loc, TokenKind kind,
      ParsedTokenIterator exclusive_lower_bound) {
    return FindPrev(ast.RawTokenAt(loc), kind, exclusive_lower_bound);
  }

  // Scans forward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  ParsedTokenIterator FindNext(
      ParsedTokenIterator tok, TokenKind kind,
      ParsedTokenIterator exclusive_upper_bound,
      bool err_on_namespace=true) {
    if (!tok) {
      return invalid;
    }

    ParsedTokenIterator dummy = invalid;

    do {
      if (exclusive_upper_bound && tok >= exclusive_upper_bound) {
        return invalid;
      }

      const auto tok_kind = tok.Kind();
      if (tok_kind == kind) {
        return tok;
      }

      switch (tok_kind) {
        // The nesting does not work if the token it is looking for is one
        // of `l_paren`, `l_brace` or `l_square`. Check if the token it is
        // looking for is one of them and return early.
        case TokenKind::kLParenthesis:
        case TokenKind::kLBrace:
        case TokenKind::kLSquare:
        case TokenKind::kLAngle:
          std::tie(dummy, tok) = GetMatching(tok);
          if (BalancedKind(tok_kind) == kind) {
            return tok;
          }
          break;

        case TokenKind::kRBrace:
          return invalid;

        case TokenKind::kRParenthesis:
        case TokenKind::kRSquare:
        case TokenKind::kRAngle:
          break;

        // NOTE(pag): This is a heuristic for detecting when things go "too
        //            far." If we were searching for `namespace`, then we would
        //            have matched in in the `if` statement above.
        //
        // NOTE(kumarak): We have gone too far and the token bound should end
        //                if it reaches to a `namespace` that isn't preceded by
        //                `using`.
        case TokenKind::kKeywordNamespace:
          if (PreviousToken(tok).Kind() != TokenKind::kKeywordUsing) {
            assert(!err_on_namespace);
            return invalid;
          }
          break;

        // NOTE(pag): This is a similar heuristic to above for detecting when
        //            things go too far. Here we look for `extern template` or
        //            `extern "C"`.
        case TokenKind::kKeywordExtern:
          switch (NextToken(tok).Kind()) {
            case TokenKind::kKeywordTemplate:
            case TokenKind::kStringLiteral:
              assert(!err_on_namespace);
              return invalid;
            default:
              break;
          }
          break;

        default:
          break;
      }

    } while (tok.Next());

    return invalid;
  }

  // Scans forward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  ParsedTokenIterator FindNext(
      clang::SourceLocation loc, TokenKind kind,
      ParsedTokenIterator exclusive_upper_bound,
      bool err_on_namespace=true) {
    return FindNext(ast.RawTokenAt(loc), kind, exclusive_upper_bound,
                    err_on_namespace);
  }

  void Expand(ParsedTokenIterator tok) {
    // Clang supports the following:
    //
    //    #pragma attribute push(__attribute__((....)), apply_to = (...))
    //    ...
    //
    // In this case, we don't want to let the locations of any of these
    // attributes influence the locations of the declarations enclosed by
    // this pragma.
    if (!tok.IsInPragmaDirective()) {

      if (!lower_bound || tok < lower_bound) {
        lower_bound = tok;
      }

      if (!upper_bound || tok > upper_bound) {
        upper_bound = tok;
      }
    }
  }

  inline void Expand(clang::SourceLocation loc) {
    if (loc.isValid()) {
      Expand(ast.RawTokenAt(loc));
    }
  }

  inline void Expand(clang::SourceRange range, clang::SourceLocation loc={}) {
#ifndef NDEBUG
    if (range.getBegin().isValid() && range.getEnd().isValid()) {
      assert(range.getBegin().getRawEncoding() <= range.getEnd().getRawEncoding());
      if (loc.isValid()) {
        assert(range.getBegin().getRawEncoding() <= loc.getRawEncoding());
        assert(loc.getRawEncoding() <= range.getEnd().getRawEncoding());
      }
    }
#endif
    Expand(range.getBegin());
    Expand(range.getEnd());
    
    (void) loc;
  }

  inline void Expand(clang::SourceLocation begin, clang::SourceLocation end, clang::SourceLocation loc={}) {
#ifndef NDEBUG
    if (begin.isValid() && end.isValid()) {
      assert(begin.getRawEncoding() <= end.getRawEncoding());
      if (loc.isValid()) {
        assert(begin.getRawEncoding() <= loc.getRawEncoding());
        assert(loc.getRawEncoding() <= end.getRawEncoding());
      }
    }
#endif
    Expand(begin);
    Expand(end);

    (void) loc;
  }

  void UncheckedVisit(clang::Decl *decl) {
    ParsedTokenIterator tok = ast.RawTokenAt(decl->getLocation());
    if (!tok) {
      return;
    }

    lower_bound = upper_bound = tok;

    if (decl->hasAttrs()) {
      for (clang::Attr *attr : decl->getAttrs()) {
        VisitAttribute(attr);
      }
    }

    this->DeclVisitor::Visit(decl);
  }

 public:

  clang::Decl *curr_decl{nullptr};

  void Visit(clang::Decl *orig_decl) {
    auto decl = orig_decl->RemappedDecl;

    if (!seen_decls.emplace(decl).second) {
      return;
    }

    const auto prev_decl = curr_decl;
    const auto prev_attr_decl = attr_decl;
    const auto prev_lower_bound = lower_bound;
    const auto prev_upper_bound = upper_bound;

    curr_decl = decl;
    attr_decl = decl;

    UncheckedVisit(decl);

    curr_decl = prev_decl;
    attr_decl = prev_attr_decl;

    // Reset in case we are visiting a nested decl, e.g. by way of type source
    // info. Can happen when calculating the bounds of a function whose
    // parameter or return type declarators contain another declaration.
    Expand(prev_lower_bound);
    Expand(prev_upper_bound);
  }

  void VisitBaseDecl(clang::Decl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());
  }

  void MaybeExpandToTrailingSemi(clang::Decl *decl) {
    if (!clang::isa<clang::FunctionDecl, clang::FunctionTemplateDecl>(decl)) {
      ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
    }
  }

  void VisitFriendDecl(clang::FriendDecl *decl) {
    Expand(decl->getFriendLoc());

    if (auto friended_decl = decl->getFriendDecl()) {
      if (!clang::isa<clang::CXXMethodDecl>(friended_decl)) {
        Visit(friended_decl);
        MaybeExpandToTrailingSemi(friended_decl);

      // Friend methods cannot be friend definitions.
      } else {
        ExpandToTrailingToken(decl->getFriendLoc(), TokenKind::kSemi);
      }
    }
  }

  void VisitFriendTemplateDecl(clang::FriendTemplateDecl *decl) {
    Expand(decl->getFriendLoc());
    
    if (auto TPL = decl->getTemplateParameterList(0u)) {
      Expand(TPL->getTemplateLoc());
    }

    if (auto friended_decl = decl->getFriendDecl()) {
      if (!clang::isa<clang::CXXMethodDecl>(friended_decl)) {
        Visit(friended_decl);
        MaybeExpandToTrailingSemi(friended_decl);

      // Friend methods cannot be friend definitions.
      } else {
        ExpandToTrailingToken(decl->getFriendLoc(), TokenKind::kSemi);
      }
    }
  }

  void VisitDecl(clang::Decl *decl) {
    VisitBaseDecl(decl);
    MaybeExpandToTrailingSemi(decl);
  }

  void VisitExpr(clang::Expr *expr) {
    switch (expr->getStmtClass()) {
      case clang::Stmt::CallExprClass: {
        auto begin = expr->getBeginLoc();
        auto end = expr->getEndLoc();
        if (begin > end) {
          Expand(end, begin);
        } else {
          Expand(begin, end);
        }
        break;
      }
      default:
        Expand(expr->getSourceRange());
        break;
    }
  }

  void VisitObjCTypeParamDecl(clang::ObjCTypeParamDecl *decl) {
    VisitBaseDecl(decl);
  }

  void VisitTemplateParamObjectDecl(clang::TemplateParamObjectDecl *decl) {
    VisitBaseDecl(decl);
  }

  // NOTE(pag): `->getLocation()` isn't necessarily contained inside of
  //            `->getSourceRange()`.
  void VisitTemplateTemplateParmDecl(clang::TemplateTemplateParmDecl *decl) {
    Expand(decl->getSourceRange());
    Expand(decl->getLocation());
  }

  void VisitTemplateTypeParmDecl(clang::TemplateTypeParmDecl *decl) {
    Expand(decl->getSourceRange());
    Expand(decl->getLocation());
  }

  void VisitFunctionTemplateDecl(clang::FunctionTemplateDecl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());
    if (auto tdl = decl->getTemplatedDecl()) {
      Visit(tdl);
    }
  }

  void VisitCXXDeductionGuideDecl(clang::CXXDeductionGuideDecl *) {
    // TODO(pag): Do something?
  }

  static bool IsLambdaMethod(clang::FunctionDecl *decl) {
    auto meth = clang::dyn_cast<clang::CXXMethodDecl>(decl);
    if (!meth) {
      return false;
    }

    return meth->getParent()->isLambda() &&
           meth->getOverloadedOperator() == clang::OO_Call;
  }

  static bool IsMethodInLambda(clang::FunctionDecl *decl) {
    auto meth = clang::dyn_cast<clang::CXXMethodDecl>(decl);
    if (!meth) {
      return false;
    }

    auto parent = meth->getParent();
    return parent && parent->isLambda();
  }

  static bool IsImplicitMethodInLambda(clang::FunctionDecl *decl) {
    return IsMethodInLambda(decl) && decl->isImplicit();
  }

  // NOTE(pag): In the case of lamdas, the `->getLocation()` can be
  //            the capture clause, but the source range is more closely
  //            related to the body.
  static clang::SourceLocation CheckLocation(clang::FunctionDecl *decl) {
    if (IsMethodInLambda(decl)) {
      return {};
    } else {
      return decl->getLocation();
    }
  }

  void VisitFunctionDecl(clang::FunctionDecl *decl) {
    // If method is lambda classes are implicit, don't visit
    // them to get the bounds, return early.
    if (IsImplicitMethodInLambda(decl)) {
      return;
    }
    VisitCommonFunction(decl);

    // If this is a lambda, then don't actually include the capture clause.
    if (IsLambdaMethod(decl)) {
      if (lower_bound.Kind() == pasta::TokenKind::kLSquare) {
        lower_bound = GetMatching(lower_bound).second;
        lower_bound.Next();
      }
    
    // E.g. lambda static invoker (`__invoke`), or conversion operators.
    } else if (IsMethodInLambda(decl)) {
      auto method = clang::dyn_cast<clang::CXXMethodDecl>(decl);
      auto record = method->getParent();
      auto lambda_func = record->getLambdaCallOperator();
      assert(decl != lambda_func);
      lower_bound = invalid;
      upper_bound = invalid;
      VisitFunctionDecl(lambda_func);
      assert(lower_bound.Kind() != pasta::TokenKind::kLSquare);
    }
  }

  static bool IsTemplateSpecializationExplicit(clang::FunctionDecl *decl) {
    return decl && decl->getTemplateSpecializationKind() == clang::TSK_ExplicitSpecialization;
  }

  void VisitCommonFunction(clang::FunctionDecl *decl) {

    ParsedTokenIterator tok = ast.RawTokenAt(decl->getLocation());

    auto missing_body = false;
    clang::FunctionDecl *pattern = nullptr;

    // Try to find the pattern for this function.
    if (decl->isTemplateInstantiation() ||
        IsTemplateSpecializationExplicit(decl)) {
      auto maybe_pattern = decl->getTemplateInstantiationPattern(true);
      if (maybe_pattern && decl->getLocation() == maybe_pattern->getLocation()) {
        pattern = maybe_pattern;
      } else if (IsTemplateSpecializationExplicit(decl)) {
        maybe_pattern = decl->getTemplateInstantiationPattern(false);
        if (maybe_pattern && decl->getLocation() == maybe_pattern->getLocation()) {
          pattern = maybe_pattern;
        }
      }
    }

    // Template specilization can be explcit or implicit. Check if the FunctionDecl
    // is one of them, match the pattern location with the decl source location
    // and expand the bounds to source range accordingly or set flag if body is
    // missing.
    if (pattern) {
      pattern = clang::dyn_cast<clang::FunctionDecl>(pattern->RemappedDecl);

      if (pattern->doesThisDeclarationHaveABody()) {

        // Clang might not instantiate the body of unreferenced methods.
        missing_body = !decl->doesThisDeclarationHaveABody();

        if (auto pattern_tpl = pattern->getDescribedFunctionTemplate()) {
          assert(pattern_tpl->getTemplatedDecl() == pattern);
          Expand(pattern_tpl->getSourceRange(), CheckLocation(pattern));
        } else {
          Expand(pattern->getSourceRange(), CheckLocation(pattern));
        }

      // The template pattern may have skipped body during partial instantiation
      // and body is not set. In that case get the end of the Function token and
      // expand till the `end_tok`.
      } else if (pattern->hasSkippedBody()) {
        if (auto end_tok = FindEndOfFunction(decl, tok);
            end_tok > upper_bound) {
          Expand(end_tok);
        }
      } else {
        Expand(pattern->getSourceRange(), CheckLocation(pattern));
        ExpandToTrailingToken(tok, TokenKind::kSemi);
      }
    }

    // If we've got a pattern, use it for finding the prototype, and then
    // replicate its proto info to the decl, as we might do proto lookups on
    // the decl independent of pattern calculation.
    const ASTImpl::FunctionProto *proto = nullptr;
    if (pattern) {
      proto = FunctionProtoFor(pattern);
      ast.func_proto.emplace(decl, *proto);
    } else {
      proto = FunctionProtoFor(decl);
    }

    // If it looks like a typedef/variable form, then try to expand a bit into
    // the previous tokens. This helps the `VisitDeclaratorDecl` logic work
    // better.
    if (proto && proto->has_variable_form && !proto->l_paren) {
      auto prev_tok = PreviousToken(tok);
      while (prev_tok) {
        switch (prev_tok.Kind()) {
          case TokenKind::kIdentifier:
            Expand(prev_tok);
            prev_tok = invalid;
            break;
          case TokenKind::kCaret:
          case TokenKind::kCaretcaret:
          case TokenKind::kStar:
          case TokenKind::kAmp:
          case TokenKind::kAmpAmp:
          case TokenKind::kLParenthesis:
            Expand(prev_tok);
            prev_tok = PreviousToken(tok);
            break;
          default:
            prev_tok = invalid;
            break;
        }
      }
    }

    // If this is a constructor / destructor, then try to expand to include
    // all nested class/namespace specifiers.
    if (decl->isOutOfLine() &&
        (clang::isa<clang::CXXConstructorDecl>(decl) ||
         clang::isa<clang::CXXDestructorDecl>(decl))) {
      auto prev = PreviousToken(lower_bound);
      while (prev.Kind() == TokenKind::kColonColon) {
        lower_bound = prev;
        lower_bound.Previous();  // Name or `>`
        if (lower_bound.Kind() == TokenKind::kRAngle) {
          lower_bound = GetMatching(lower_bound).first;
          lower_bound.Previous();  // Name.
        }
        prev = PreviousToken(lower_bound);
      }
    }

    VisitDeclaratorDecl(decl);

    const clang::FunctionDecl *def = nullptr;
    auto body = decl->getBody(def);
    if (def == decl) {
      Expand(body->getSourceRange());

    } else if (decl->isExplicitlyDefaulted() || decl->isDeletedAsWritten() ||
               decl->isPureVirtual() || decl->hasDefiningAttr()) {
      ExpandToTrailingToken(tok, TokenKind::kSemi);

    // In-class declaration of an out-of-line-defined method.
    } else if (def && def->isOutOfLine() && !decl->isOutOfLine() &&
               clang::isa<clang::CXXMethodDecl>(decl)) {
      ExpandToTrailingToken(tok, TokenKind::kSemi);

    } else if (decl->hasSkippedBody() || decl->willHaveBody()) {
      if (auto end_tok = FindEndOfFunction(decl, tok);
          end_tok > upper_bound) {
        Expand(end_tok);
      }

    } else if (!decl->doesThisDeclarationHaveABody() && !missing_body) {
      ExpandToTrailingToken(tok, TokenKind::kSemi);
    }

    if (!proto) {
      return;
    }

    if (!proto->l_paren) {
      return;
    }

#ifndef NDEBUG
    if (IsMethodInLambda(decl)) {
      assert(lower_bound.Offset() <= proto->l_paren);
    } else {
      assert(lower_bound.Offset() < proto->l_paren);
    }
#endif

    Expand(ast.RawTokenAt(proto->r_paren));
  }

  void VisitAttribute(const clang::Attr *attr) {
    return;
  }

  // Expand to handle things like: `static const char *` or
  // `inline static constexpr`. This will generally also go and find things
  // like leading attributes, `extern`, etc.
  void FixpointFindLeadingKeywords(void) {
    for (auto changed = true; changed; ) {
      changed = ExpandLeadingKeywords(kLeadingKeywords);

      auto prev_tok = lower_bound;
      if (!prev_tok.Previous()) {
        break;
      }

      switch (prev_tok.Kind()) {

        // If the previous token is a `]` or a `)`, then go find the matching one.
        // This helps us expand past leading attributes when we fail to find them.
        case TokenKind::kRParenthesis:
        case TokenKind::kRSquare:
          // NOTE(pag): This may fail if `prev_tok` is a macro token, e.g. the
          //            `)` of a macro function call.
          if (auto matching_tok = GetMatching(prev_tok).first) {
            lower_bound = matching_tok;
            changed = true;
          }
          break;

        // Expand into the declarator/specifier.
        case TokenKind::kLParenthesis:  // Function type.
        case TokenKind::kStar:  // Pointer type.
        case TokenKind::kAmp:  // Reference type.
        case TokenKind::kAmpAmp:  // R-value reference type.
        case TokenKind::kIdentifier:  // Normal type.
        case TokenKind::kColonColon:  // Qualfied name / namespace specifier.
          lower_bound = prev_tok;
          changed = true; 
          continue;

        default:
          break;
      }
    }
  }

  void VisitDeclaratorDecl(clang::DeclaratorDecl *) {
    if (lower_bound) {
      FixpointFindLeadingKeywords();
    }
  }

  void VisitVarDecl(clang::VarDecl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());

    if (decl->hasInit()) {
      VisitExpr(decl->getInit());
    }

    // If this is an actual variable decl and not a derived type then go
    // searching for a semicolon.
    ParsedTokenIterator tok = ast.RawTokenAt(decl->getLocation());
    if (!decl->isImplicit() &&
        decl->getKind() == clang::Decl::Kind::Var) {
      ExpandToTrailingToken(tok, TokenKind::kSemi);
    }

    // If it's an array then we need to expand to include the `[]`, but those
    // are only known in the `TypeLoc`.
    if (clang::TypeSourceInfo *tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        // If the variable is an argument pack with syntax set as prefix,
        // the source range may point to the start of the pack. In such case
        // expand from the pack sytax to the source location of variable.
        auto [begin, end] = tl.getBeginLoc() > tl.getEndLoc() ?
                            std::make_tuple(tl.getEndLoc(), tl.getBeginLoc()) :
                            std::make_tuple(tl.getBeginLoc(), tl.getEndLoc());
        Expand(begin, end);
      }
    }

    VisitDeclaratorDecl(decl);
  }

  std::pair<ParsedTokenIterator, ParsedTokenIterator> SourceRangeTokens(
      clang::SourceRange range) {
    return {ast.RawTokenAt(range.getBegin()), ast.RawTokenAt(range.getEnd())};
  }

  // Get or create location information about the syntactic function prototype
  // for `func`.
  const ASTImpl::FunctionProto *FunctionProtoFor(clang::FunctionDecl *func) {
    if (auto it = ast.func_proto.find(func); it != ast.func_proto.end()) {
      return std::addressof(it->second);
    }

    ASTImpl::FunctionProto &proto = ast.func_proto[func];

    // Just always fail.
    if (clang::isa<clang::CXXDeductionGuideDecl>(func) ||
        func->isImplicit()) {
      return &proto;
    }

    // Try to detect something like `foo_t func;` forward declarations. These
    // are present in the linux kernel. When this happens, we'll usually observe
    // a `TypedefNameType` wrapping around a `FunctionProtoType`, rather than
    // directly seeing a `FunctionProtoType`. The typedef type will be present
    // on function definitions as well, where the prototypes are fully spelled
    // out, but we want to know if this specific `func` represents the variable
    // form.
    proto.has_variable_form =
        !func->isThisDeclarationADefinition() &&
        !clang::isa<clang::FunctionProtoType>(func->getType().getTypePtr());

    auto [params_begin, params_end] =
        SourceRangeTokens(func->getParametersSourceRange());

    unsigned num_params = func->getNumParams();

    // Lambda methods with zero arguments might not have parameter lists.
    if (!num_params && !params_begin && !params_end && IsLambdaMethod(func)) {
      return &proto;
    }

    // If there's an ellipsis loc, then that will have influenced the parameter
    // source range, but we should never trust it, as the ellipsis location is
    // taken from the function type itself, which is subject to deduplication,
    // and thus may point to some other place.
    auto has_ellipsis = func->getEllipsisLoc().isValid();

    // NOTE(kumarak): If the function parameters are ellipsis, can't rely on the
    //                source range of parameters. The parameters can only be ellipsis
    //                that may have wrong params_begin & params_end. Invalidate both
    //                and depend entirely on the location of function name token.
    //                e.g:
    //                  false_type __call_helper(...)
    //
    if (has_ellipsis) {
      params_begin = invalid;
      params_end = invalid;
    }

    // Get the range of the parameter list. We might need to convert these to be
    // sane.
    //
    // NOTE(pag): We use `ExpandToLeadingToken` instead of `params_begin[-1]`
    //            because we might have a macro there, e.g. `__unused` in
    //
    //                  __unused const char *msg
    //
    //            in `_os_log_verify_format_str` from XNU.
    if (params_begin && params_begin.Kind() != TokenKind::kLParenthesis) {
      params_begin = FindPrev(params_begin, TokenKind::kLParenthesis, invalid);
    }

    if (params_end && params_end.Kind() != TokenKind::kRParenthesis) {
      auto ub = invalid;
      if (proto.has_variable_form) {
        ub = FindNext(params_end, TokenKind::kSemi, invalid, false);
      }
      params_end = FindNext(params_end, TokenKind::kRParenthesis, ub);
    }

    if (params_begin && !params_end) {
      std::tie(params_begin, params_end) = GetMatching(params_begin);
    } else if (params_end && !params_begin) {
      std::tie(params_begin, params_end) = GetMatching(params_end);
    }

    // This happens with the following code extracted from cURL:
    //
    //    struct Curl_easy {};
    //    void Curl_infof(struct Curl_easy *, const char *fmt, ...);
    //    void Curl_failf(struct Curl_easy *, const char *fmt, ...);
    //
    // The general issue ends up being the `...`, which is stored in the
    // `FunctionProtoType`, which is subject to type-based deduplication.
    if (params_end < params_begin) {
      params_begin = invalid;
      params_end = invalid;
    }

    auto func_name_tok = ast.RawTokenAt(func->getLocation());
    if (func_name_tok) {
      if (!params_begin || params_begin < func_name_tok) {
        auto next_semicolon = FindNext(
            func_name_tok, TokenKind::kSemi, invalid, false);
        params_begin = FindNext(func_name_tok, TokenKind::kLParenthesis,
                                invalid, false);

        // Watch out for `foo_t foo; int bar() {}`, that we don't find
        // `(` from `bar` and associate it with `foo`.
        if (next_semicolon < params_begin) {
          proto.has_variable_form = true;
          params_begin = invalid;
        }
      }
    }

    // NOTE(pag): In the XNU kernel, we've observed cases where the parameter
    //            source range is completely crazy, where the closing paren
    //            for `_os_log_verify_format_str` ends up being the closing
    //            paren for `panic`.
    //
    // NOTE(pag): In V8, we've observed cases where `params_end < params_begin`.
    ParsedTokenIterator nearer_params_end = invalid;
    std::tie(params_begin, nearer_params_end) = GetMatching(params_begin);
    if (nearer_params_end < params_end ||
        params_end < params_begin ||
        !params_end) {
      params_end = nearer_params_end;
    }

    if (!params_begin != !params_end) {
      assert(proto.has_variable_form);
      params_begin = invalid;
      params_end = invalid;
    }

    proto.l_paren = params_begin.Offset();
    proto.r_paren = params_end.Offset();

    assert(proto.l_paren <= proto.r_paren);

    // The ellipsis can be on its own after a comma, or directly after
    // the variable, e.g. `a, ...` vs. `a...`.

    if (auto ellipsis_tok = params_end; ellipsis_tok.Previous()) {
      ellipsis_tok = FindPrev(ellipsis_tok, TokenKind::kEllipsis, params_begin);
      if (ellipsis_tok > params_begin) {
        proto.ellipsis = ellipsis_tok.Offset();
        has_ellipsis = true;
      }
    }

    auto begin_tok = params_begin;
    auto next_begin_tok = params_begin;
    auto end_tok = params_begin;

    // Function prototype can have multiple ellipsis tokens and we don't have
    // ways to track nesting of `<` & `>` tokens. To identify the parameters
    // token boundaries, we need to accomodate the presence of multiple ellipsis
    // tokens.
    // e.g:
    //      void __make_fmatrix_impl(index_sequence<_Is...>, index_sequence<_Js...>, _Ls... __ls)
    //

    // getFunctionScopeIndex uses ParameterIndex bit to get the index and
    // it is not reliable. Traverse through the parameters using its indices.
    for (unsigned i = 0; i < num_params; i++) {
      clang::ParmVarDecl *param = func->getParamDecl(i);
      ASTImpl::BoundingTokens &param_proto = ast.bounds[param];
      proto.params.emplace_back(&param_proto);

      if (end_tok >= params_end) {
        continue;  // Also handles `invalid` case.
      }

      begin_tok = next_begin_tok;
      if (!begin_tok.Next()) {  // Skip the `(` or the `,`.
        break;
      }

      if ((i + 1) == num_params) {

        // The ellipsis can be on its own after a comma, or directly after
        // the variable, e.g. `a, ...` vs. `a...`.
        if (has_ellipsis) {
          auto ellipsis_tok = FindNext(
              begin_tok, TokenKind::kEllipsis, invalid);
          if (ellipsis_tok < params_end) {
            end_tok = ellipsis_tok;
          } else {
            // fallback of the ellipsis is not there in the last parameter
            end_tok = params_end;
          }
        } else {
          end_tok = params_end;
        }
      } else {
        auto comma_tok = FindNext(begin_tok, TokenKind::kComma, params_end);
        if (!comma_tok) {
          end_tok = params_end;
        
        // If it finds the comma token and it is within the params_end bound.
        } else if (comma_tok < params_end) {
          end_tok = comma_tok;
          next_begin_tok = comma_tok;
        
        } else {
          // Expect this case only if the function parameters have
          // ellipsis; If it falls here and `has_ellipsis` is false,
          // something is wrong.
          assert(has_ellipsis);
          end_tok = params_end;
        }
      }

      if (begin_tok < end_tok) {
        param_proto.first = begin_tok.Offset();
        param_proto.second = end_tok.Offset() - 1u;
      }
    }

    return &proto;
  }

  // TODO(pag): Handle parameters from the canonical decl being injected into
  //            out-of-line methods on class templates.
  void VisitParmVarDecl(clang::ParmVarDecl *decl) {

    if (decl->isImplicit()) {
      return;
    }

    auto dc = decl->getDeclContext();

    if (auto func = clang::dyn_cast<clang::FunctionDecl>(dc)) {

      // The parameter might be explicit, but the function can be implicit.
      // Happens in the case of lambda static invokers, which are normal functions
      // taking the same arguments as the lambda call operator, then constructing
      // the lambda object from the the arguments, and invoking the call operator.
      if (func->isImplicit()) {
        return;
      }

      // Note: If the ParamVarDecl is from the implicitly defaulted FunctionDecl
      //       then the corresponding token does not exist. No need to look for
      //       token bounds in that case; Return early with the default
      //       initialization of `lower_bounds` and `upper_bounds`
      if (func->isDefaulted() ||
          clang::isa<clang::CXXDeductionGuideDecl>(func)) {
        return;
      }

      const ASTImpl::FunctionProto *proto = FunctionProtoFor(func);
      if (!proto) {
        return;
      }

      unsigned param_index = decl->getFunctionScopeIndex();
      if (param_index >= proto->params.size()) {
        assert(func->isFunctionTemplateSpecialization());
        return;
      }

      // This just ends up re-reading the bounds back out of the AST.
      const ASTImpl::BoundingTokens *param_proto = proto->params[param_index];
      lower_bound = ast.RawTokenAt(param_proto->first);
      upper_bound = ast.RawTokenAt(param_proto->second);

    } else if (auto reb = clang::dyn_cast<clang::RequiresExprBodyDecl>(dc)) {
      if (reb->isImplicit()) {
        return;
      }
    }
  }

  ParsedTokenIterator ExpandToLeadingToken(ParsedTokenIterator name_tok,
                                           TokenKind kind) {
    
    auto found_tok = FindPrev(name_tok, kind, invalid);
    if (found_tok <= name_tok) {
      Expand(found_tok);
      return found_tok;
    } else {
      Expand(name_tok);
      return name_tok;
    }
  }

  void ExpandToLeadingToken(clang::SourceLocation loc, TokenKind kind) {
    ExpandToLeadingToken(ast.RawTokenAt(loc), kind);
  }

  void ExpandToTrailingToken(ParsedTokenIterator name_tok, TokenKind kind) {
    auto found_tok = FindNext(name_tok, kind, invalid);
    if (found_tok >= name_tok) {
      Expand(found_tok);
    } else {
      Expand(name_tok);
    }
  }

  void ExpandToTrailingToken(clang::SourceLocation loc, TokenKind kind) {
    ExpandToTrailingToken(ast.RawTokenAt(loc), kind);
  }

  void VisitNamespaceDecl(clang::NamespaceDecl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());

    // TODO(pag): Might not be right.
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordNamespace);
  }

  void VisitLinkageSpecDecl(clang::LinkageSpecDecl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());

    // TODO(pag): Might not be right.
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordExtern);
  }

  void VisitExternCContextDecl(clang::ExternCContextDecl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());

    // TODO(pag): Might not be right.
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordExtern);
  }

  void VisitExportDecl(clang::ExportDecl *decl) {
    Expand(decl->getSourceRange(), decl->getLocation());
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordExport);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
  }

  void VisitNamespaceAliasDecl(clang::NamespaceAliasDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange(), decl->getLocation());
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordNamespace);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
  }

  void VisitBaseUsingDecl(clang::BaseUsingDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange(), decl->getLocation());
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordUsing);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
  }
  void VisitUsingPackDecl(clang::UsingPackDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange(), decl->getLocation());
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordUsing);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
  }
  void VisitUsingDirectiveDecl(clang::UsingDirectiveDecl *decl) {
//    VisitNamedDecl(decl);
//    Expand(decl->getSourceRange(), decl->getLocation());

    ExpandToLeadingToken(decl->getUsingLoc(), TokenKind::kKeywordUsing);
    ExpandToLeadingToken(decl->getNamespaceKeyLocation(), TokenKind::kKeywordUsing);
    assert(lower_bound.Kind() == TokenKind::kKeywordUsing);

    ExpandToTrailingToken(lower_bound, TokenKind::kSemi);
    assert(upper_bound.Kind() == TokenKind::kSemi);
  }

  void VisitUsingShadowDecl(clang::UsingShadowDecl *decl) {
    VisitNamedDecl(decl);
    Expand(decl->getSourceRange(), decl->getLocation());
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordUsing);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
  }

  void VisitTypedefNameDecl(clang::TypedefNameDecl *decl) {
    VisitTypeDecl(decl);
    Expand(decl->getSourceRange(), decl->getLocation());
    if (auto tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
  }

  void VisitTypeAliasDecl(clang::TypeAliasDecl *decl) {
    VisitTypedefNameDecl(decl);
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordUsing);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);

    // Happens in `int-ll64.h` in Linux kernel. This is used to suppress
    // the `-ansi` flag with things like `unsigned long long`.
    ExpandLeadingKeyword(TokenKind::kKeyword__Extension__);
  }

  void VisitTypedefDecl(clang::TypedefDecl *decl) {
    VisitTypedefNameDecl(decl);
    ExpandToLeadingToken(decl->getLocation(), TokenKind::kKeywordTypedef);
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);

    // Happens in `int-ll64.h` in Linux kernel. This is used to suppress
    // the `-ansi` flag with things like `unsigned long long`.
    ExpandLeadingKeyword(TokenKind::kKeyword__Extension__);
  }

  inline static TokenKind IntroducerTokenKind(clang::TagDecl::TagKind tk) {
    switch (tk) {
      case clang::TagTypeKind::Struct:
        return TokenKind::kKeywordStruct;
      case clang::TagTypeKind::Interface:
        return TokenKind::kKeyword__Interface;
      case clang::TagTypeKind::Union:
        return TokenKind::kKeywordUnion;
      case clang::TagTypeKind::Class:
        return TokenKind::kKeywordClass;
      case clang::TagTypeKind::Enum:
        return TokenKind::kKeywordEnum;
      default:
        return {};
    }
  }

  void VisitTagDecl(clang::TagDecl *decl) {

    // Implicit classes are for things like C++ lambdas, and builtin structures
    // for things like variadic argument storage.
    if (!decl->isImplicit()) {
      auto introducer_kind = IntroducerTokenKind(decl->getTagKind());
      if (introducer_kind != TokenKind{}) {

        auto name_loc = ast.RawTokenAt(decl->getLocation());
        auto introducer_loc = ExpandToLeadingToken(name_loc, introducer_kind);

        if (lower_bound && introducer_loc) {
          if (lower_bound < introducer_loc && decl->isEmbeddedInDeclarator()) {
            lower_bound = introducer_loc;
          }
        } else if (introducer_loc) {
          lower_bound = introducer_loc;
        }
      }
    }

    Expand(decl->getSourceRange(), decl->getLocation());

    auto tag_end = FindEndOfTag(decl, lower_bound);
    if (!tag_end) {
      tag_end = FindEndOfTagAlt(decl);
    }

    assert(!lower_bound || tag_end);
    if (!upper_bound || upper_bound <= tag_end) {
      upper_bound = tag_end;
    }

    FixpointFindLeadingKeywords();
  }

  void VisitTemplateDecl(clang::TemplateDecl *decl) {
    VisitNamedDecl(decl);
    if (auto templated_decl = decl->getTemplatedDecl()) {
      this->Visit(templated_decl);
    }

    if (clang::isa<clang::VarTemplateDecl>(decl) ||
        clang::isa<clang::ClassTemplateDecl>(decl)) {
      ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
    }
  }

  void VisitClassTemplateSpecializationDecl(
      clang::ClassTemplateSpecializationDecl *decl) {

    // One annoying thing with clang is that often the `decl->getLocation()`
    // be for a canonical decl, but the rest of the info will be for the
    // definition, so go through and try to fix up the location of this decl.

    if (decl->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
      Expand(decl->getTemplateKeywordLoc());
      Expand(decl->getExternLoc());
    }

    VisitCXXRecordDecl(decl);
  }

  void VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
    if (decl->isLambda()) {
      UncheckedVisit(decl->getLambdaCallOperator());
      return;

    } else if (decl->isImplicit()) {
      return;
    }

    VisitRecordDecl(decl);
  }

  void VisitVarTemplateSpecializationDecl(
      clang::VarTemplateSpecializationDecl *decl) {
    VisitVarDecl(decl);

    if (decl->getSpecializationKind() == clang::TSK_ExplicitSpecialization) {
      Expand(decl->getTemplateKeywordLoc());
      ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
    }
  }

  void VisitEnumConstantDecl(clang::EnumConstantDecl *decl) {
    VisitValueDecl(decl);

    if (auto expr = decl->getInitExpr()) {
      Expand(expr->getSourceRange());
    }
  }

  void VisitFieldDecl(clang::FieldDecl *decl) {
    if (auto init = decl->getInClassInitializer()) {
      Expand(init->getSourceRange());
    }
    if (auto bf = decl->getBitWidth()) {
      Expand(bf->getSourceRange());
    }
    if (auto tsi = decl->getTypeSourceInfo()) {
      if (auto tl = tsi->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
    ExpandToTrailingToken(decl->getLocation(), TokenKind::kSemi);
    VisitDeclaratorDecl(decl);
  }

  void VisitTypeLoc(clang::TypeLoc loc) {
    if (auto next_loc = loc.getNextTypeLoc()) {
      this->TypeLocVisitor::Visit(next_loc);
    }
  }

  void VisitAutoTypeLoc(clang::AutoTypeLoc loc) {
    Expand(loc.getNameLoc());
    if (loc.isDecltypeAuto()) {
      Expand(loc.getRParenLoc());
    }
  }

  void VisitDecltypeTypeLoc(clang::DecltypeTypeLoc loc) {
    Expand(loc.getDecltypeLoc());
    Expand(loc.getRParenLoc());
  }

  // NOTE(pag): Don't enter the referenced expression.
  void VisitTypeOfExprTypeLoc(clang::TypeOfExprTypeLoc loc) {
    Expand(loc.getTypeofLoc());
    Expand(loc.getLParenLoc());
    Expand(loc.getRParenLoc());
  }

  // NOTE(pag): Don't enter the referenced type.
  void VisitTypeOfTypeLoc(clang::TypeOfTypeLoc loc) {
    Expand(loc.getTypeofLoc());
    Expand(loc.getLParenLoc());
    Expand(loc.getRParenLoc());
  }

  void VisitBuiltinTypeLoc(clang::BuiltinTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
  }

  void VisitTypedefTypeLoc(clang::TypedefTypeLoc loc) {
    Expand(loc.getNameLoc());
  }

  void VisitAdjustedTypeLoc(clang::AdjustedTypeLoc loc) {
    if (auto ol = loc.getOriginalLoc()) {
      this->TypeLocVisitor::Visit(ol);
    }
  }

  void VisitMacroQualifiedTypeLoc(clang::MacroQualifiedTypeLoc loc) {
    Expand(loc.getExpansionLoc());
    if (auto il = loc.getInnerLoc()) {
      this->TypeLocVisitor::Visit(il);
    }
  }

  void VisitDecayedTypeLoc(clang::DecayedTypeLoc loc) {
    if (auto ol = loc.getOriginalLoc()) {
      this->TypeLocVisitor::Visit(ol);
    }
  }

  void VisitElaboratedTypeLoc(clang::ElaboratedTypeLoc loc) {
    Expand(loc.getElaboratedKeywordLoc());
    if (auto qual_loc = loc.getQualifierLoc()) {
      VisitNestedNameSpecifierLoc(qual_loc);
    }
    if (auto named_loc = loc.getNamedTypeLoc()) {
      this->TypeLocVisitor::Visit(named_loc);
    }
  }

  void VisitAttributedTypeLoc(clang::AttributedTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    VisitAttribute(loc.getAttr());
    if (auto ml = loc.getModifiedLoc()) {
      this->TypeLocVisitor::Visit(ml);
    }
  }

  void VisitTagTypeLoc(clang::TagTypeLoc loc) {
    Expand(loc.getNameLoc());
  }

  void VisitEnumTypeLoc(clang::EnumTypeLoc loc) {
    return VisitTagTypeLoc(loc);
  }

  void VisitRecordTypeLoc(clang::RecordTypeLoc loc) {
    return VisitTagTypeLoc(loc);
  }

  void VisitPointerTypeLoc(clang::PointerTypeLoc loc) {
    Expand(loc.getStarLoc());
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
  }

  void VisitMemberPointerTypeLoc(clang::MemberPointerTypeLoc loc) {
    if (auto type_info = loc.getClassTInfo()) {
      if (auto tl = type_info->getTypeLoc()) {
        this->TypeLocVisitor::Visit(tl);
      }
    }
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitReferenceTypeLoc(clang::ReferenceTypeLoc loc) {
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitLValueReferenceTypeLoc(clang::LValueReferenceTypeLoc loc) {
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitRValueReferenceTypeLoc(clang::RValueReferenceTypeLoc loc) {
    if (auto pl = loc.getPointeeLoc()) {
      this->TypeLocVisitor::Visit(pl);
    }
    Expand(loc.getSigilLoc());
  }

  void VisitArrayTypeLoc(clang::ArrayTypeLoc loc) {
    if (clang::Expr *size_expr = loc.getSizeExpr()) {
      Expand(size_expr->getSourceRange());
    }
    if (auto el = loc.getElementLoc()) {
      this->TypeLocVisitor::Visit(el);
    }
    Expand(loc.getBracketsRange());
  }

  void VisitConstantArrayTypeLoc(clang::ConstantArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }

  void VisitIncompleteArrayTypeLoc(clang::IncompleteArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }

  void VisitVariableArrayTypeLoc(clang::VariableArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }

  void VisitParenTypeLoc(clang::ParenTypeLoc loc) {
    if (auto il = loc.getInnerLoc()) {
      this->TypeLocVisitor::Visit(il);
    }
    Expand(loc.getLocalSourceRange());
  }

  void VisitInjectedClassNameTypeLoc(clang::InjectedClassNameTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
  }

  void VisitDependentNameTypeLoc(clang::DependentNameTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    if (auto qual_loc = loc.getQualifierLoc()) {
      VisitNestedNameSpecifierLoc(qual_loc);
    }
  }

  void VisitDependentTemplateSpecializationTypeLoc(
      clang::DependentTemplateSpecializationTypeLoc loc) {
    Expand(loc.getLocalSourceRange());
    Expand(loc.getTemplateNameLoc());
    Expand(loc.getLAngleLoc());
    Expand(loc.getRAngleLoc());

    if (auto qual_loc = loc.getQualifierLoc()) {
      VisitNestedNameSpecifierLoc(qual_loc);
    }
  }

  void VisitTemplateSpecializationTypeLoc(
      clang::TemplateSpecializationTypeLoc loc) {

    Expand(loc.getLocalSourceRange());
    Expand(loc.getTemplateNameLoc());
    Expand(loc.getLAngleLoc());
    Expand(loc.getRAngleLoc());
  }

  void VisitBlockPointerTypeLoc(clang::BlockPointerTypeLoc loc) {
    Expand(loc.getCaretLoc());
    this->TypeLocVisitor::Visit(loc.getPointeeLoc());
  }

  void VisitNestedNameSpecifierLoc(clang::NestedNameSpecifierLoc loc) {

    Expand(loc.getBeginLoc());

    if (auto type_loc = loc.getTypeLoc()) {
      this->TypeLocVisitor::Visit(type_loc);
    }
  }

  DeclBoundsFinder(ASTImpl &ast_)
      : ast(ast_),
        invalid(ast.InvalidRawToken()),
        lower_bound(invalid),
        upper_bound(invalid) {}

  ASTImpl::BoundingTokens GetBounds(clang::Decl *decl) {
    Visit(decl);
    if (!lower_bound) {
      return {};  // Probably a builtin.
    }

    for (auto t = lower_bound; t && t <= upper_bound; t.Next()) {
      switch (t.Kind()) {
        case TokenKind::kLParenthesis:
        case TokenKind::kLSquare:
        case TokenKind::kLBrace:
        case TokenKind::kLAngle: {
          auto [new_begin, new_end] = GetMatching(t);
          if (new_begin < lower_bound) {
            lower_bound = new_begin;
          }
          if (upper_bound < new_end) {
            upper_bound = new_end;
            t = new_end;
          }
          break;
        }
        default:
          break;
      }
    }

    switch (lower_bound.Role()) {
      case TokenRole::kInvalid:
      case TokenRole::kBeginOfFileMarker:
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kEndOfFileMarker:
      case TokenRole::kEndOfMacroExpansionMarker:
        lower_bound.Next();
        break;
      default:
        break;
    }

    switch (upper_bound.Role()) {
      case TokenRole::kInvalid:
      case TokenRole::kBeginOfFileMarker:
      case TokenRole::kBeginOfMacroExpansionMarker:
      case TokenRole::kEndOfFileMarker:
      case TokenRole::kEndOfMacroExpansionMarker:
        upper_bound.Previous();
        break;
      default:
        break;
    }

    if (!lower_bound) {
      lower_bound = upper_bound;
    }

    if (!lower_bound.IsParsed()) {
      lower_bound.Next();
    }

    if (!upper_bound) {
      upper_bound = lower_bound;
    }

    if (!upper_bound.IsParsed()) {
      upper_bound.Previous();
    }

    assert(lower_bound.IsParsed());
    assert(upper_bound.IsParsed());
    assert(lower_bound <= upper_bound);
    return {lower_bound.Offset(), upper_bound.Offset()};
  }
};

}  // namespace

// Try to return the inclusive bounds of a given declaration in terms of
// parsed tokens. This doesn't not try to expand the range to the ending
// of macro expansions.
ASTImpl::BoundingTokens ASTImpl::DeclBounds(clang::Decl *decl) {
  decl = decl->RemappedDecl;

  auto [it, added] = bounds.try_emplace(decl, 0u, 0u);
  if (!added) {
    return it->second;
  }

  if (decl->isImplicit()) {
    if (auto func = clang::dyn_cast<clang::FunctionDecl>(decl)) {
      if (func->getBuiltinID()) {
        return it->second;
      }
    }
  }

  // Handle this off-the-bat; it doesn't really conform to any other thing.
  if (clang::isa<clang::TranslationUnitDecl>(decl)) {
    it->second.first = 0u;
    it->second.second = parsed_tokens.size() - 1u;
    return it->second;
  }

  it->second = DeclBoundsFinder(*this).GetBounds(decl);
  return it->second;
}

TokenRange ASTImpl::DeclTokenRange(const clang::Decl *decl_,
                                   std::unique_lock<std::mutex> locker) {
  auto decl = const_cast<clang::Decl *>(decl_);
  auto [first, last] = DeclBounds(decl);
  if (last && first <= last) {
    return TokenRange(this->shared_from_this(), first, last + 1u);
  }

  return TokenRange(
      std::shared_ptr<ParsedTokenStorage>(shared_from_this(), &invalid_tokens),
      0u, 0u);
}

// Return a token range for the bounds of a declaration.
TokenRange ASTImpl::DeclTokenRange(const clang::Decl *decl_) {
  return DeclTokenRange(decl_, std::unique_lock<std::mutex>(bounds_mutex));
}

DerivedTokenIndex ASTImpl::MatchingIndex(DerivedTokenIndex offset) {
  DeclBoundsFinder finder(*this);
  ParsedTokenIterator loc(&parsed_tokens, offset);
  auto [begin, end] = finder.GetMatching(loc);
  if (begin.Offset() == offset) {
    return end.Offset();
  } else {
    return begin.Offset();
  }
}

}  // namespace pasta
