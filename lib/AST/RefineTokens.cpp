/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include "AST.h"

#include <cassert>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

#define PASTA_DEBUG_REFINE 0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
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
#pragma clang diagnostic pop

namespace pasta {
namespace {

// RAII tracker for making sure we save the old value of some variable, then
// reset or set it to a new value, then restore it to its prior state later.
template <typename T>
class SaveResetRestore {
 public:
  inline SaveResetRestore(T &ref_, T new_val={})
      : ref(&ref_),
        saved_val(ref_) {
    ref_ = new_val;
  }
  inline ~SaveResetRestore(void) {
    *ref = saved_val;
  }
  T * const ref;
  const T saved_val;
};

// RAII tracker for making sure we keep proper track of certain reference
// (really depth) counters.
class ReferenceCount {
 public:
  inline ReferenceCount(unsigned &ref_)
      : ref(&ref_) {
    ++ref_;
  }
  inline ~ReferenceCount(void) {
    --*ref;
  }
  unsigned * const ref;
};

// RAII tracker for making sure we record when we enter and exit an entity.
class EnterExitEntity {
 public:
  template <class Base, class Derived, class TypeClass, class LocalData>
  inline EnterExitEntity(
      std::vector<const void *> &entity_stack_,
      const clang::ConcreteTypeLoc<Base, Derived, TypeClass, LocalData> &loc)
      : entity_stack(entity_stack_),
        pushed_entity(loc.getTypePtr()) {
    if (pushed_entity) {
      entity_stack.push_back(pushed_entity);
    }
  }

  inline EnterExitEntity(std::vector<const void *> &entity_stack_,
                         const clang::TypeLoc &)
      : entity_stack(entity_stack_),
        pushed_entity(nullptr) {}

  inline EnterExitEntity(std::vector<const void *> &entity_stack_,
                         const void *entity)
      : entity_stack(entity_stack_),
        pushed_entity(entity) {
    if (entity) {
      entity_stack.push_back(pushed_entity);
    }
  }

  inline ~EnterExitEntity(void) {
    if (pushed_entity) {
      entity_stack.pop_back();
    }
  }

  std::vector<const void *> &entity_stack;
  const void *pushed_entity;
};

// Return the declaration associated with a type.
static clang::Decl *TypeToDecl(const clang::Type *type_) {
  auto type = const_cast<clang::Type *>(type_);

  clang::NamedDecl *decl_out = nullptr;
  if (type->isIncompleteType(&decl_out) && decl_out) {
    return decl_out;
  }

  if (auto tag_type = type->getAs<clang::TagType>(); tag_type) {
    return tag_type->getDecl();
  } else if (auto record_decl = type->getAsCXXRecordDecl(); record_decl) {
    return record_decl;
  } else if (auto typedef_type = clang::dyn_cast<clang::TypedefType>(type);
             typedef_type) {
    return typedef_type->getDecl();

  } else if (auto adjusted_type = clang::dyn_cast<clang::AdjustedType>(type);
             adjusted_type) {
    if (auto [atype, _] = adjusted_type->getAdjustedType().split().asPair();
        atype && atype != type) {
      return TypeToDecl(atype);
    }
  } else if (auto macro_qual_type = clang::dyn_cast<clang::MacroQualifiedType>(type);
             macro_qual_type) {
    if (auto [mtype, _] = macro_qual_type->getUnderlyingType().split().asPair();
        mtype && mtype != type) {
      return TypeToDecl(mtype);
    }
  } else if (auto elaborated_type = clang::dyn_cast<clang::ElaboratedType>(type);
             elaborated_type) {
    if (auto [etype, _] = elaborated_type->getNamedType().split().asPair();
        etype && etype != type) {
      return TypeToDecl(etype);
    }
  } else if (auto sub_type = clang::dyn_cast<clang::SubstTemplateTypeParmType>(type);
             sub_type) {
    if (auto [stype, _] = sub_type->getReplacementType().split().asPair();
        stype && stype != type) {
      return TypeToDecl(stype);
    }
  } else if (auto spec_type = clang::dyn_cast<clang::TemplateSpecializationType>(type);
             spec_type) {
    if (auto [stype, _] = spec_type->desugar().split().asPair();
        stype && stype != type) {
      return TypeToDecl(stype);
    }
  } else if (auto unresolved_type = clang::dyn_cast<clang::UnresolvedUsingType>(type);
             unresolved_type) {
    return unresolved_type->getDecl();
  }
  return nullptr;
}

// Returns `true` if a `MemberExpr` uses an implicit `this` pointer.
static bool IsImplicitThis(clang::MemberExpr *expr) {
  if (auto base = expr->getBase(); base) {
    if (base->isImplicitCXXThis()) {
      return true;

    // For example, accessing into an anonymous union/struct.
    } else if (auto member_expr = clang::dyn_cast<clang::MemberExpr>(base);
               member_expr) {
      return IsImplicitThis(member_expr);
    }
  }

  return false;
}

}  // namespace

// The main indexer, implemented as a bunch of visitors that descend through
// the AST and annotate/record information about source locations, relationships
// therebetween, and cross-references between source locations and declarations.
//
// NOTE(pag): This doesn't traverse the entire AST. Instead, it focuses on so-
//            called top-level declarations.
class TokenContextAssigner : public clang::DeclVisitor<TokenContextAssigner>,
                            public clang::StmtVisitor<TokenContextAssigner>,
                            public clang::TypeLocVisitor<TokenContextAssigner> {
 private:
  ASTImpl &ast;

  std::unordered_set<clang::Decl *> seen_decls;

  std::unordered_map<const void *, TokenContextImpl *> entity_to_context;

  // The most recent enclosing decl/stmt/type.
  std::vector<const void *> entity_stack;

  // The most recent enclosing method being indexed.
  clang::CXXMethodDecl *current_method{nullptr};

  // The enclosing `switch` statement.
  clang::SwitchStmt *current_switch{nullptr};

  // The ending of the enclosing switch/for/do..while/while statement, for
  // adding cross-references to `continue` and `break` statements.
  clang::SourceLocation current_continue_target;
  clang::SourceLocation current_break_target;

  // Current list of redecls being filled in.
  std::vector<clang::Decl *> redecls;

  // How many statements deep are we? We use this sometimes to avoid vising
  // things like functions that are declared inside of statements.
  unsigned decl_depth{0};

  // How many statements deep are we? We use this sometimes to avoid vising
  // things like functions that are declared inside of statements.
  unsigned statement_depth{0};

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  TokenImpl *ScanForMatching(TokenImpl *tok, int64_t increment) {

    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());
    auto count = 0;

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      switch (tok->kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          ++count;
          break;
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          --count;
          break;
        default:
          continue;
      }

      if (!count) {
        return tok;
      }
    }

    return nullptr;
  }

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next balanced paren, brace, or square.
  std::pair<TokenImpl *, TokenImpl *> GetMatching(TokenImpl *tok) {
    if (tok) {
      switch (tok->kind) {
        case clang::tok::l_paren:
        case clang::tok::l_brace:
        case clang::tok::l_square:
          return {tok, ScanForMatching(tok, 1)};
        case clang::tok::r_paren:
        case clang::tok::r_brace:
        case clang::tok::r_square:
          return {ScanForMatching(tok, -1), tok};
        default:
          return {};
      }
    } else {
      return {};
    }
  }

  // Scans forward or backward, starting at `loc` and tries to identify the
  // next balanced paren, brace, or square.
  std::pair<TokenImpl *, TokenImpl *> GetMatching(clang::SourceLocation loc) {
    return GetMatching(ast.RawTokenAt(loc));
  }

  std::pair<TokenImpl *, TokenImpl *> GetMatching(clang::SourceRange range) {
    TokenImpl *begin = ast.RawTokenAt(range.getBegin());
    TokenImpl *end = ast.RawTokenAt(range.getEnd());

    clang::tok::TokenKind open_kind = clang::tok::unknown;
    clang::tok::TokenKind close_kind = clang::tok::unknown;

    if (begin) {
      if (begin->kind == clang::tok::l_paren) {
        close_kind = clang::tok::r_paren;
      } else if (begin->kind == clang::tok::l_brace) {
        close_kind = clang::tok::r_brace;
      } else if (begin->kind == clang::tok::l_square) {
        close_kind = clang::tok::r_square;
      } else {
        begin = nullptr;
      }
    }

    if (end) {
      if (end->kind == clang::tok::r_paren) {
        open_kind = clang::tok::l_paren;
      } else if (end->kind == clang::tok::r_brace) {
        open_kind = clang::tok::l_brace;
      } else if (end->kind == clang::tok::r_square) {
        open_kind = clang::tok::l_square;
      } else {
        end = nullptr;
      }
    }

    if (begin && end) {
      if (begin->kind == open_kind && end->kind == close_kind) {
        return {begin, end};
      } else {
        return {};
      }
    } else if (begin) {
      end = ScanForMatching(begin, 1);
    } else if (end) {
      begin = ScanForMatching(end, -1);
    }

    if (begin && end) {
      return {begin, end};
    }

    return {};
  }

  // Scans forward or backward, starting at `loc` and tries to identify the
  // next balanced paren, brace, or square.
  TokenImpl *ScanForMatching(clang::SourceLocation loc, int64_t increment) {
    if (auto tok = ast.RawTokenAt(loc)) {
      return ScanForMatching(tok, increment);
    } else {
      return nullptr;
    }
  }

  // Scans forward or backward, starting at `tok` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(
      TokenImpl *tok, clang::tok::TokenKind kind, int64_t increment) {

    auto first_tok = &(ast.tokens.front());
    auto last_tok = &(ast.tokens.back());

    for (; first_tok <= tok && tok <= last_tok; tok = &(tok[increment])) {
      if (tok->kind == kind) {
        return tok;
      }
    }

    return nullptr;
  }

  // Scans forward or backward, starting at `loc` and tries to identify the
  // next token with kind `kind`.
  TokenImpl *FindNext(clang::SourceLocation loc,
                      clang::tok::TokenKind kind, int64_t increment) {

    if (auto tok = ast.RawTokenAt(loc)) {
      return FindNext(tok, kind, increment);
    } else {
      return nullptr;
    }
  }

  // Add a cross-reference to the current entity.
  void AssignContext(TokenImpl *tok) {
    auto ent_begin = entity_stack.rbegin();
    auto ent_it = ent_begin;
    auto ent_end = entity_stack.rend();
    auto top_entity = entity_stack.back();

    entity_to_context.clear();

    bool has_contexts = false;
    auto num_found = 0u;
    auto i = 0u;
    // Descend the token contexts that we already know about.
    for (auto index = tok->context_index;
         index != kInvalidTokenContextIndex;
         index = ast.contexts[index].parent_index) {
      TokenContextImpl &context = ast.contexts[index];
      const void *context_data = context.Aliasee(ast.contexts)->data;
      auto found_it = std::find(ent_it, ent_end, context_data);
      if (found_it != ent_end) {
        if (found_it == ent_begin || context_data == top_entity) {
          return;  // We've found the top entity on the stack, assume refined.
        }
        ++num_found;

//        if (found_it == ent_begin) {
//
//          // The entity associated with this context is also the top entity on
//          // our stack; there's nothing to do, we can't refine this token any
//          // further.
//          if (!i) {
//            return;
//
//          // What's on top of the entity stack is nested inside of the token
//          // context. Probably we need an alias.
//          } else {
//
//          }
//        }


        entity_to_context.emplace(context_data, &context);
        ent_it = found_it;
      }
      has_contexts = true;
      ++i;
    }

    // Nothing to do.
    if (num_found == i) {
      return;
    }

#if PASTA_DEBUG_REFINE
    std::cerr
        << tok->Data(ast) << " c:" << std::hex << tok->context_index
        << " l:" << tok->opaque_source_loc << std::dec << " "
        << entity_to_context.size() << '/' << num_found << '/' << i
        << '/' << entity_stack.size() << '\n';
#endif

    assert(!has_contexts || num_found);
  }

  // Add a cross-reference to the current entity.
  void AssignContext(clang::SourceLocation loc) {
    if (auto tok = ast.RawTokenAt(loc)) {
      AssignContext(tok);
    }
  }

 public:
  TokenContextAssigner(ASTImpl &ast_)
      : ast(ast_) {}

  // Return the vector of all redeclarations of `decl`. For this, we walk up to
  // the function, find its redeclarations, then for each one, get the
  // corresponding parameter.
  const std::vector<clang::Decl *> &FillRedeclsImpl(clang::ParmVarDecl *decl);

  // Return the vector of all redeclarations of `decl`.
  const std::vector<clang::Decl *> &FillRedeclsImpl(clang::Decl *decl);


  // Return the vector of all redeclarations of `decl`.
  template <typename T>
  inline const std::vector<T *> &FillRedecls(T *decl) {
    return reinterpret_cast<const std::vector<T *> &>(FillRedeclsImpl(decl));
  }

  void VisitTranslationUnitDecl(clang::TranslationUnitDecl *decl);
  void VisitNamespaceDecl(clang::NamespaceDecl *decl);
  void VisitExternCContextDecl(clang::ExternCContextDecl *decl);

  void VisitTemplateArgument(const clang::TemplateArgument &arg);

  void VisitBlockDecl(clang::BlockDecl *decl);
  void VisitObjCMethodDecl(clang::ObjCMethodDecl *decl);
  void VisitCXXMethodDecl(clang::CXXMethodDecl *decl);
  void VisitFunctionDecl(clang::FunctionDecl *decl);
  void VisitCommonFunctionDecl(clang::FunctionDecl *decl,
                               clang::FunctionDecl *first_decl);
  void VisitVarDecl(clang::VarDecl *decl);
  void VisitParmVarDecl(clang::ParmVarDecl *decl);
  void VisitNamespaceAliasDecl(clang::NamespaceAliasDecl *decl);
  void VisitTypedefDecl(clang::TypedefDecl *decl);
  void VisitTypeAliasDecl(clang::TypeAliasDecl *decl);
  void VisitObjCTypeParamDecl(clang::ObjCTypeParamDecl *decl);
  void VisitTypedefNameDecl(clang::TypedefNameDecl *decl);
  void VisitTagDecl(clang::TagDecl *decl);
  void VisitCXXRecordDecl(clang::CXXRecordDecl *decl);
  void VisitClassTemplateSpecializationDecl(
      clang::ClassTemplateSpecializationDecl *decl);
  void VisitClassTemplatePartialSpecializationDecl(
      clang::ClassTemplatePartialSpecializationDecl *decl);
  void VisitEnumConstantDecl(clang::EnumConstantDecl *decl);
  void VisitFieldDecl(clang::FieldDecl *decl);

  void VisitTemplateDecl(clang::TemplateDecl *decl);
  void VisitFunctionTemplateDecl(clang::FunctionTemplateDecl *decl);
  void VisitClassTemplateDecl(clang::ClassTemplateDecl *decl);
  void VisitVarTemplateDecl(clang::VarTemplateDecl *decl);
  void VisitLabelDecl(clang::LabelDecl *decl);

  void VisitTemplateArgumentLoc(const clang::TemplateArgumentLoc &loc);

  void VisitTypeLoc(clang::TypeLoc loc);
  void VisitBuiltinTypeLoc(clang::BuiltinTypeLoc loc);
  void VisitTypedefTypeLoc(clang::TypedefTypeLoc loc);
  void VisitAdjustedTypeLoc(clang::AdjustedTypeLoc loc);
  void VisitMacroQualifiedTypeLoc(clang::MacroQualifiedTypeLoc loc);
  void VisitDecayedTypeLoc(clang::DecayedTypeLoc loc);
  void VisitElaboratedTypeLoc(clang::ElaboratedTypeLoc loc);
  void VisitAttributedTypeLoc(clang::AttributedTypeLoc loc);

  void VisitTagTypeLoc(clang::TagTypeLoc loc);

  void VisitEnumTypeLoc(clang::EnumTypeLoc loc) {
    return VisitTagTypeLoc(loc);
  }
  void VisitRecordTypeLoc(clang::RecordTypeLoc loc) {
    return VisitTagTypeLoc(loc);
  }

  void VisitFunctionTypeLoc(clang::FunctionTypeLoc loc);
  void VisitFunctionProtoTypeLoc(clang::FunctionProtoTypeLoc loc) {
    VisitFunctionTypeLoc(loc);
  }
  void VisitFunctionNoProtoTypeLoc(clang::FunctionNoProtoTypeLoc loc) {
    VisitFunctionTypeLoc(loc);
  }
  void VisitPointerTypeLoc(clang::PointerTypeLoc loc);
  void VisitMemberPointerTypeLoc(clang::MemberPointerTypeLoc loc);
  void VisitReferenceTypeLoc(clang::ReferenceTypeLoc loc);
  void VisitLValueReferenceTypeLoc(clang::LValueReferenceTypeLoc loc);
  void VisitRValueReferenceTypeLoc(clang::RValueReferenceTypeLoc loc);
  void VisitArrayTypeLoc(clang::ArrayTypeLoc loc);
  void VisitConstantArrayTypeLoc(clang::ConstantArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }
  void VisitIncompleteArrayTypeLoc(clang::IncompleteArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }
  void VisitVariableArrayTypeLoc(clang::VariableArrayTypeLoc loc) {
    return VisitArrayTypeLoc(loc);
  }
  void VisitParenTypeLoc(clang::ParenTypeLoc loc);
  void VisitInjectedClassNameTypeLoc(clang::InjectedClassNameTypeLoc loc);
  void VisitDependentNameTypeLoc(clang::DependentNameTypeLoc loc);
  void VisitDependentTemplateSpecializationTypeLoc(
      clang::DependentTemplateSpecializationTypeLoc loc);

  void VisitTemplateSpecializationTypeLoc(
      clang::TemplateSpecializationTypeLoc loc);
  void VisitBlockPointerTypeLoc(clang::BlockPointerTypeLoc loc);

  void VisitDeclStmt(clang::DeclStmt *stmt);
  void VisitCompoundStmt(clang::CompoundStmt *stmt);


  void VisitCommonControlFlowStmt(
      clang::Stmt *stmt,
      clang::SourceLocation kw_loc,
      TokenImpl *rparen_tok=nullptr);

  void VisitCommonControlFlowStmt(
      clang::Stmt *stmt,
      clang::SourceLocation kw_loc,
      clang::SourceLocation rparen_loc=clang::SourceLocation());

  void VisitCommonCompoundStmt(clang::CompoundStmt *stmt);

  void VisitNestedNameSpecifier(
      clang::Stmt *stmt, clang::NestedNameSpecifier *qualifier,
      clang::SourceLocation error_loc=clang::SourceLocation());
  void VisitNestedNameSpecifierLoc(clang::NestedNameSpecifierLoc loc);

  void VisitCXXOperatorCallExpr(clang::CXXOperatorCallExpr *expr);
  void VisitCXXConstructExpr(clang::CXXConstructExpr *expr);
  void VisitCallExpr(clang::CallExpr *expr);
  void VisitCommonCallExpr(clang::CallExpr *expr, clang::Decl *called_decl);
  void VisitCUDAKernelCallExpr(clang::CUDAKernelCallExpr *expr) {
    VisitCallExpr(expr);
  }
  void VisitCXXMemberCallExpr(clang::CXXMemberCallExpr *expr);

  void VisitSwitchStmt(clang::SwitchStmt *stmt);
  void VisitIfStmt(clang::IfStmt *stmt);
  void VisitDoStmt(clang::DoStmt *stmt);
  void VisitWhileStmt(clang::WhileStmt *stmt);
  void VisitForStmt(clang::ForStmt *stmt);
  void VisitReturnStmt(clang::ReturnStmt *stmt);
  void VisitBreakStmt(clang::BreakStmt *stmt);
  void VisitContinueStmt(clang::ContinueStmt *stmt);
  void VisitCaseStmt(clang::CaseStmt *stmt);
  void VisitDefaultStmt(clang::DefaultStmt *stmt);
  void VisitLabelStmt(clang::LabelStmt *stmt);
  void VisitGotoStmt(clang::GotoStmt *stmt);
  void VisitNullStmt(clang::NullStmt *stmt);

  void VisitParenExpr(clang::ParenExpr *expr);
  void VisitParenListExpr(clang::ParenListExpr *expr);
  void VisitStmtExpr(clang::StmtExpr *expr);
  void VisitDesignatedInitExpr(clang::DesignatedInitExpr *expr);
  void VisitDesignatedInitUpdateExpr(clang::DesignatedInitUpdateExpr *expr);
  void VisitInitListExpr(clang::InitListExpr *expr);

  void VisitUnaryOperator(clang::UnaryOperator *expr);
  void VisitBinaryOperator(clang::BinaryOperator *expr);
  void VisitConditionalOperator(clang::ConditionalOperator *expr);

  void VisitDeclRefExpr(clang::DeclRefExpr *expr);
  void VisitMemberExpr(clang::MemberExpr *expr);
  void VisitCXXDependentScopeMemberExpr(clang::CXXDependentScopeMemberExpr *expr);

  void VisitImplicitCastExpr(clang::ImplicitCastExpr *expr);
  void VisitExplicitCastExpr(clang::ExplicitCastExpr *expr);
  void VisitCStyleCastExpr(clang::CStyleCastExpr *expr);
  void VisitCXXFunctionalCastExpr(clang::CXXFunctionalCastExpr *expr);
  void VisitCXXNamedCastExpr(clang::CXXNamedCastExpr *expr);

  void VisitCXXNewExpr(clang::CXXNewExpr *expr);
  void VisitCXXDeleteExpr(clang::CXXDeleteExpr *expr);
  void VisitCXXThisExpr(clang::CXXThisExpr *expr);
  void VisitCXXThrowExpr(clang::CXXThrowExpr *expr);
  void VisitCXXNoexceptExpr(clang::CXXNoexceptExpr *expr);
  void VisitCXXNullPtrLiteralExpr(clang::CXXNullPtrLiteralExpr *expr);
  void VisitCXXPseudoDestructorExpr(clang::CXXPseudoDestructorExpr *expr);
  void VisitCXXScalarValueInitExpr(clang::CXXScalarValueInitExpr *expr);
  void VisitCXXStdInitializerListExpr(clang::CXXStdInitializerListExpr *expr);
  void VisitCXXTypeidExpr(clang::CXXTypeidExpr *expr);
  void VisitCXXUuidofExpr(clang::CXXUuidofExpr *expr);

  void VisitMaterializeTemporaryExpr(clang::MaterializeTemporaryExpr *expr);
  void VisitCXXBindTemporaryExpr(clang::CXXBindTemporaryExpr *expr);
  void VisitExprWithCleanups(clang::ExprWithCleanups *expr);

  void VisitIntegerLiteral(clang::IntegerLiteral *expr);
  void VisitVAArgExpr(clang::VAArgExpr *expr);

  void VisitAddrLabelExpr(clang::AddrLabelExpr *expr);
  void VisitSubstNonTypeTemplateParmExpr(
      clang::SubstNonTypeTemplateParmExpr *expr);

  void VisitChooseExpr(clang::ChooseExpr *expr);
  void VisitBlockExpr(clang::BlockExpr *expr);
  void VisitLambdaExpr(clang::LambdaExpr *expr);

  void VisitArrayInitLoopExpr(clang::ArrayInitLoopExpr *expr);
  void VisitArrayInitIndexExpr(clang::ArrayInitIndexExpr *expr);
  void VisitImplicitValueInitExpr(clang::ImplicitValueInitExpr *expr);

  void VisitArraySubscriptExpr(clang::ArraySubscriptExpr *expr);
  void VisitArrayTypeTraitExpr(clang::ArrayTypeTraitExpr *expr);
  void VisitOffsetOfExpr(clang::OffsetOfExpr *expr);

  void VisitAtomicExpr(clang::AtomicExpr *expr);
  void VisitCompoundLiteralExpr(clang::CompoundLiteralExpr *expr);

  void VisitCoroutineSuspendExpr(clang::CoroutineSuspendExpr *expr);
  void VisitCoawaitExpr(clang::CoawaitExpr *expr);
  void VisitCoyieldExpr(clang::CoyieldExpr *expr);
  void VisitDependentCoawaitExpr(clang::DependentCoawaitExpr *expr);

  void VisitCXXBoolLiteralExpr(clang::CXXBoolLiteralExpr *expr);
  void VisitCXXTemporaryObjectExpr(clang::CXXTemporaryObjectExpr *expr);
  void VisitCXXDefaultArgExpr(clang::CXXDefaultArgExpr *expr);
};

// Return the vector of all redeclarations of `decl`. For this, we walk up to
// the function, find its redeclarations, then for each one, get the
// corresponding parameter.
const std::vector<clang::Decl *> &TokenContextAssigner::FillRedeclsImpl(
    clang::ParmVarDecl *decl) {
  redecls.clear();
  const auto param_index = decl->getFunctionScopeIndex();
  auto func_decl = clang::dyn_cast_or_null<clang::FunctionDecl>(
      clang::Decl::castFromDeclContext(decl->getDeclContext()));
  redecls.push_back(decl);
  for (auto func_redecl : func_decl->redecls()) {
    assert(param_index < func_redecl->getNumParams());
    const auto redecl = func_redecl->getParamDecl(param_index);
    if (redecl != decl) {
      redecls.push_back(redecl);
    }
  }
  return redecls;
}

// Return the vector of all redeclarations of `decl`.
const std::vector<clang::Decl *> &TokenContextAssigner::FillRedeclsImpl(
    clang::Decl *decl) {
  redecls.clear();
  for (auto redecl : decl->redecls()) {
    redecls.push_back(redecl);
  }
  assert(redecls.front() == decl);
  return redecls;
}

void TokenContextAssigner::VisitTemplateArgument(
    const clang::TemplateArgument &arg) {
  // TODO(pag): Handle this.
  (void) arg;
}

void TokenContextAssigner::VisitTemplateArgumentLoc(
    const clang::TemplateArgumentLoc &loc) {
  const auto &arg = loc.getArgument();
  VisitTemplateArgument(arg);

  switch (arg.getKind()) {
    case clang::TemplateArgument::Null:
      break;
    case clang::TemplateArgument::Type: {
      if (auto type_info = loc.getTypeSourceInfo()) {
        this->TypeLocVisitor::Visit(type_info->getTypeLoc());
      }
      break;
    }
    case clang::TemplateArgument::Declaration: {
      if (auto expr = loc.getSourceDeclExpression()) {
        this->StmtVisitor::Visit(expr);
      }
      break;
    }
    case clang::TemplateArgument::NullPtr: {
      if (auto expr = loc.getSourceNullPtrExpression()) {
        this->StmtVisitor::Visit(expr);
      }
      break;
    }
    case clang::TemplateArgument::Integral: {
      if (auto expr = loc.getSourceIntegralExpression()) {
        this->StmtVisitor::Visit(expr);
      }
      break;
    }
    case clang::TemplateArgument::Template:
    case clang::TemplateArgument::TemplateExpansion: {
      if (auto qual_loc = loc.getTemplateQualifierLoc()) {
        if (auto type_loc = qual_loc.getTypeLoc()) {
          this->TypeLocVisitor::Visit(type_loc);
        }
      }
      break;
    }
    case clang::TemplateArgument::Expression: {
      if (auto expr = loc.getSourceExpression()) {
        this->StmtVisitor::Visit(expr);
      }
      break;
    }
    case clang::TemplateArgument::Pack:
      // TODO(pag): Handle this.
      break;
  }
}

#define DECL_VISITOR(cls, ...) \
    void TokenContextAssigner::Visit ## cls(clang::cls *decl) { \
      ReferenceCount depth_tracker(decl_depth); \
      if (!seen_decls.count(decl)) { \
        const auto redecls = FillRedecls(decl); \
        for (auto redecl : redecls) { \
          seen_decls.insert(redecl); \
        } \
        for (auto redecl : redecls) { \
          EnterExitEntity entity_tracker(entity_stack, redecl); \
          __VA_ARGS__ \
        } \
      } \
    }

DECL_VISITOR(TranslationUnitDecl, {
  for (auto child_decl : redecl->decls()) {
    this->DeclVisitor::Visit(child_decl);
  }
})

DECL_VISITOR(NamespaceDecl, {
  for (auto child_decl : redecl->decls()) {
    this->DeclVisitor::Visit(child_decl);
  }

//  if (auto [begin_tok, end_tok] = GetMatching(redecl->getRBraceLoc());
//      begin_tok && begin_tok->kind == clang::tok::l_brace &&
//      end_tok && end_tok->kind == clang::tok::r_brace) {
//    AssignContext(begin_tok);
//    AssignContext(end_tok);
//  }
})

DECL_VISITOR(ExternCContextDecl, {
  for (auto child_decl : redecl->decls()) {
    this->DeclVisitor::Visit(child_decl);
  }
})

DECL_VISITOR(ObjCMethodDecl, {
  if (redecl->hasBody()) {
    this->StmtVisitor::Visit(redecl->getBody());
  }
})

DECL_VISITOR(CXXMethodDecl, {
  auto record = decl->getParent();
  auto decl_for_this = current_method;

  // If we're in a lambda function, then `this` typically refers to the captured
  // lambda.
  if (record->isLambda() && !current_method) {

    // It's possible that this is a generic lambda, and thus considered as a
    // top-level entity, and this not actually indexed via the containing
    // method.
    auto dc = record->getDeclContext();
    while (dc) {
      if (auto dc_decl = clang::Decl::castFromDeclContext(dc); dc_decl) {
        decl_for_this = clang::dyn_cast<clang::CXXMethodDecl>(dc_decl);
        if (decl_for_this) {
          // Lambda in a lambda.
          if (current_method->getParent()->isLambda()) {
            dc = current_method->getParent()->getDeclContext();
            decl_for_this = nullptr;

          // Lambda in a non-lambda method.
          } else {
            break;
          }

        // Not a lambda, keep going up.
        } else {
          dc = dc_decl->getDeclContext();
        }
      } else {
        break;
      }
    }
  }

  SaveResetRestore<clang::CXXMethodDecl *> save_restore(
      current_method, decl_for_this);
  VisitCommonFunctionDecl(redecl, decl);
})

// Visit the function decl node and update the identifier name type. It
// also checks for the function body and update the {l/r}braces to the
// function specific braces.
DECL_VISITOR(FunctionDecl, {
  VisitCommonFunctionDecl(redecl, decl);
})

// Common code for functions/methods.
void TokenContextAssigner::VisitCommonFunctionDecl(
    clang::FunctionDecl *decl, clang::FunctionDecl *first_decl) {

  if (auto tpl_args = decl->getTemplateSpecializationArgs()) {
    for (const clang::TemplateArgument &arg : tpl_args->asArray()) {
      VisitTemplateArgument(arg);
    }
  }

  auto type_info = decl->getTypeSourceInfo();
  if (type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  const auto name_info = decl->getNameInfo();
  if (auto name_tok = ast.RawTokenAt(name_info.getLoc());
      name_tok && name_tok->kind == clang::tok::identifier) {
    AssignContext(name_tok);
  }

  switch (decl->getDeclName().getNameKind()) {
    case clang::DeclarationName::Identifier:
    case clang::DeclarationName::ObjCZeroArgSelector:
    case clang::DeclarationName::ObjCOneArgSelector:
    case clang::DeclarationName::ObjCMultiArgSelector:
      break;
    case clang::DeclarationName::CXXConstructorName:
    case clang::DeclarationName::CXXDestructorName:
    case clang::DeclarationName::CXXConversionFunctionName:
      if (type_info != name_info.getNamedTypeInfo()) {
        type_info = name_info.getNamedTypeInfo();
        if (type_info) {
          this->TypeLocVisitor::Visit(type_info->getTypeLoc());
        }
      }
      break;
    case clang::DeclarationName::CXXDeductionGuideName:
    case clang::DeclarationName::CXXOperatorName:
    case clang::DeclarationName::CXXLiteralOperatorName:
    case clang::DeclarationName::CXXUsingDirective:
      break;
  }

  // Try to annotate the `~` of a destructor as such.
  if (auto destructor_decl = clang::dyn_cast<clang::CXXDestructorDecl>(decl)) {
    if (auto tilde_tok =
            FindNext(destructor_decl->getBeginLoc(), clang::tok::tilde, -1)) {
      AssignContext(tilde_tok);
    }
  }

  if (decl != first_decl) {
    return;
  }

  // Visit the parameters of the canonical decl. This will scoop in the
  // parameters of the redeclarations of the function.
  for (auto param_decl : decl->parameters()) {
    VisitParmVarDecl(param_decl);

    // TODO(pag): Find and annotate the commas? How to avoid things like
    //            function pointer-typed parameters?
  }

  // Visit the function body, if any.
  const clang::FunctionDecl *def_decl = nullptr;
  if (clang::Stmt *stmt = decl->getBody(def_decl); def_decl && stmt) {

    // Look for the initializer list.
    if (auto constructor_decl = clang::dyn_cast<clang::CXXConstructorDecl>(def_decl);
        constructor_decl) {

      for (clang::CXXCtorInitializer *init : constructor_decl->inits()) {

        // If we can associate this with a field, then try to annotate the
        // field identifier appropriately, and add a cross-reference.
        if (clang::FieldDecl *field_decl = init->getAnyMember()) {
          EnterExitEntity entity_tracker(entity_stack, field_decl);

          if (auto name_tok = ast.RawTokenAt(init->getMemberLocation());
              name_tok && name_tok->kind == clang::tok::identifier) {
            AssignContext(name_tok);
          }

          if (auto init_expr = init->getInit(); init_expr) {
            this->StmtVisitor::Visit(init_expr);
          }

          AssignContext(init->getLParenLoc());
          AssignContext(init->getRParenLoc());
        }
      }
    }

    this->StmtVisitor::Visit(stmt);

    if (auto compound_stmt = clang::dyn_cast<clang::CompoundStmt>(stmt);
        compound_stmt) {
      VisitCommonCompoundStmt(compound_stmt);

    // E.g. a try..catch statement that is inside of the initializers of
    // a c++ constructor.
    } else if (auto try_stmt = clang::dyn_cast<clang::CXXTryStmt>(stmt);
               try_stmt) {
      // TODO(pag): ...

    } else {
      // TODO(pag): ...
    }
  }
}

// Visit the namespace alias decl node and update the identifier token id.
void TokenContextAssigner::VisitNamespaceAliasDecl(
    clang::NamespaceAliasDecl *) {}

DECL_VISITOR(ParmVarDecl, {
  if (auto type_info = redecl->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (auto expr = redecl->getInit(); expr) {
    // TODO(pag): Assign a token kind to the `=`.
    this->StmtVisitor::Visit(expr);
  }
})

// Visit the variable decl node and set the type specifier token id's.
DECL_VISITOR(VarDecl, {
  if (redecl->hasInit()) {
    // TODO(pag): Assignment `=` operator?
    this->StmtVisitor::Visit(redecl->getInit());
  }

  if (auto type_info = redecl->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  // TODO(pag): Address this old comment.
  //
  // NOTE(pag): In the case of constructor calls in variable declarations,
  //            e.g. `Foo bar(...);`, `bar` will first be renamed to an
  //            instance method identifier name (through the above visitors)
  //            and here we'll replace it with the correct token.
})

DECL_VISITOR(TypedefNameDecl, {
  if (auto type_info = redecl->getTypeSourceInfo()) {
    if (auto type_loc = type_info->getTypeLoc()) {
      this->TypeLocVisitor::Visit(type_loc);
    }
  }

  // TODO(pag): Add a "maybe visitor" for decls in here?
})

void TokenContextAssigner::VisitTypedefDecl(clang::TypedefDecl *decl) {
  VisitTypedefNameDecl(decl);
}

DECL_VISITOR(TypeAliasDecl, {
  if (auto type_info = redecl->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }
})

void TokenContextAssigner::VisitObjCTypeParamDecl(
    clang::ObjCTypeParamDecl *) {
  // TODO(pag): Do this.
}

void TokenContextAssigner::VisitCXXRecordDecl(clang::CXXRecordDecl *decl) {
  VisitTagDecl(decl);
}

void TokenContextAssigner::VisitClassTemplateSpecializationDecl(
    clang::ClassTemplateSpecializationDecl *decl) {
  VisitCXXRecordDecl(decl);
}

// NOTE(pag): Not interested in partial specializations, as by definition, they
//            are not fully instantiated.
void TokenContextAssigner::VisitClassTemplatePartialSpecializationDecl(
    clang::ClassTemplatePartialSpecializationDecl *) {}

// Visits the declaration node of struct/union/class/enum and update the
// identifier token id's.
DECL_VISITOR(TagDecl, {
  for (auto child_decl : redecl->decls()) {
    this->DeclVisitor::Visit(child_decl);
  }

  if (auto [begin_tok, end_tok] = GetMatching(redecl->getBraceRange());
      begin_tok && begin_tok->kind == clang::tok::l_brace &&
      end_tok && end_tok->kind == clang::tok::r_brace) {
    AssignContext(begin_tok);
    AssignContext(end_tok);
  }

  if (auto cxx_record_decl = clang::dyn_cast<clang::CXXRecordDecl>(redecl);
      cxx_record_decl) {

    if (auto spec_decl = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(cxx_record_decl);
        spec_decl) {
      const auto &tpl_args = spec_decl->getTemplateArgs();
      for (const clang::TemplateArgument &arg : tpl_args.asArray()) {
        VisitTemplateArgument(arg);
      }
    }

    // TODO(pag): Look for `:` and `,` separating bases.
    // TODO(pag): Add info about base relationships?
    if (cxx_record_decl == cxx_record_decl->getDefinition()) {
      for (auto base : cxx_record_decl->bases()) {
        if (auto type_info = base.getTypeSourceInfo()) {
          this->TypeLocVisitor::Visit(type_info->getTypeLoc());
        }
      }
    }
  }
})

// Visit the enum constant declaration node and set the identifier
// token id's
DECL_VISITOR(EnumConstantDecl, {
  if (auto expr = redecl->getInitExpr()) {
    // TODO(pag): Find `=`.
    this->StmtVisitor::Visit(expr);
  }
})

// Visit the field declaration node of tag type (struct/class/union)
DECL_VISITOR(FieldDecl, {
  // TODO(pag): Capture offset, size, and alignment.

  if (auto type_info = redecl->getTypeSourceInfo()) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (auto bit_width = redecl->getBitWidth(); bit_width) {
    // TODO(pag): Add token kind for the `:`.
    this->StmtVisitor::Visit(bit_width);
  }

  if (auto expr = redecl->getInClassInitializer(); expr) {
    // TODO(pag): Add token kinds to the `{` and `}`, or the `=`.
    this->StmtVisitor::Visit(expr);
  }
})

DECL_VISITOR(BlockDecl, {
  AssignContext(redecl->getCaretLocation());

  // TODO(pag): Redecls of a block decl?
  for (auto param_var : redecl->parameters()) {
    this->DeclVisitor::Visit(param_var);
  }

  // NOTE(pag): `hasCaptures` returns `true` if `this` is catpured, but that
  //            is separately tracked from the array of captures.
  if (decl->getNumCaptures()) {
    for (const auto &capture : redecl->captures()) {

      // TODO(pag,ppalka): Are variables captured represented in the
      //                   `handleDeclOccurrence`?

      if (capture.hasCopyExpr()) {
        this->StmtVisitor::Visit(capture.getCopyExpr());
      }
    }
  }

  if (auto type_info = redecl->getSignatureAsWritten()) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (const auto body = redecl->getBody(); body) {
    this->StmtVisitor::Visit(body);

    if (auto compound_stmt = clang::dyn_cast<clang::CompoundStmt>(body);
        compound_stmt) {
      VisitCommonCompoundStmt(compound_stmt);
    }
  }
})

DECL_VISITOR(LabelDecl, {
  if (decl->isGnuLocal()) {  // __label__ ...;
    // TODO(pag): Handle this.
  } else if (decl->isMSAsmLabel()) {
    // TODO(pag): Handle this.
  }
});

#define STMT_VISITOR(cls, ...) \
    void TokenContextAssigner::Visit ## cls(clang::cls *stmt) { \
      ReferenceCount depth_tracker(statement_depth); \
      EnterExitEntity entity_tracker(entity_stack, stmt); \
      __VA_ARGS__ \
    }

#define EXPR_VISITOR(cls, ...) \
    void TokenContextAssigner::Visit ## cls(clang::cls *expr) { \
      ReferenceCount depth_tracker(statement_depth); \
      EnterExitEntity entity_tracker(entity_stack, expr); \
      __VA_ARGS__ \
    }

void TokenContextAssigner::VisitTemplateDecl(clang::TemplateDecl *) {}
void TokenContextAssigner::VisitFunctionTemplateDecl(clang::FunctionTemplateDecl *) {}
void TokenContextAssigner::VisitClassTemplateDecl(clang::ClassTemplateDecl *decl) {}
void TokenContextAssigner::VisitVarTemplateDecl(clang::VarTemplateDecl *decl) {}

STMT_VISITOR(DeclStmt, {
  for (auto decl : stmt->decls()) {
    this->DeclVisitor::Visit(decl);
  }
})

STMT_VISITOR(CompoundStmt, {
  for (auto child_stmt : stmt->children()) {
    this->StmtVisitor::Visit(child_stmt);
  }
  VisitCommonCompoundStmt(stmt);
})

void TokenContextAssigner::VisitCommonCompoundStmt(clang::CompoundStmt *stmt) {
  clang::SourceRange braces(stmt->getLBracLoc(), stmt->getRBracLoc());
  if (auto [begin_tok, end_tok] = GetMatching(braces);
      begin_tok && begin_tok->kind == clang::tok::l_brace &&
      end_tok && end_tok->kind == clang::tok::r_brace) {
    AssignContext(begin_tok);
    AssignContext(end_tok);
  }
}

void TokenContextAssigner::VisitNestedNameSpecifierLoc(
    clang::NestedNameSpecifierLoc loc) {

  if (auto qualifier = loc.getNestedNameSpecifier(); qualifier) {
    VisitNestedNameSpecifier(nullptr, qualifier, loc.getBeginLoc());
  }
  if (auto type_loc = loc.getTypeLoc(); type_loc) {
    this->TypeLocVisitor::Visit(type_loc);
  }
}

void TokenContextAssigner::VisitNestedNameSpecifier(
    clang::Stmt *stmt, clang::NestedNameSpecifier *qualifier,
    clang::SourceLocation error_loc) {
  for (; qualifier; qualifier = qualifier->getPrefix()) {
    clang::Decl *decl = qualifier->getAsRecordDecl();

    switch (qualifier->getKind()) {
      case clang::NestedNameSpecifier::Identifier: {
        break;
      }
      case clang::NestedNameSpecifier::Namespace:
        decl = qualifier->getAsNamespace();
        break;
      case clang::NestedNameSpecifier::NamespaceAlias:
        decl = qualifier->getAsNamespaceAlias();
        break;
      case clang::NestedNameSpecifier::Global:
        break;

      case clang::NestedNameSpecifier::Super:
      case clang::NestedNameSpecifier::TypeSpec:
      case clang::NestedNameSpecifier::TypeSpecWithTemplate:
        if (auto type_decl = TypeToDecl(qualifier->getAsType()); type_decl) {
          decl = type_decl;
        }
        break;

      default:
        break;
    }
  }
}

// Visit the Operator expression and update the token id's based on
// the contextual information.
EXPR_VISITOR(CXXOperatorCallExpr, {
  this->StmtVisitor::Visit(expr->getCallee());

  for (auto arg : expr->arguments()) {
    this->StmtVisitor::Visit(arg);
    // TODO(pag): Annotate the commas, if any.
  }

  clang::tok::TokenKind tok_kind = clang::tok::unknown;
  clang::tok::TokenKind open_tok_kind = clang::tok::unknown;

  switch (expr->getOperator()) {
    case clang::OO_New:
      tok_kind = clang::tok::kw_new;
      break;
    case clang::OO_Delete:
      tok_kind = clang::tok::kw_delete;
      break;
    case clang::OO_Array_New:
      tok_kind = clang::tok::kw_new;
      break;
    case clang::OO_Array_Delete:
      tok_kind = clang::tok::kw_delete;
      break;
    case clang::OO_Plus:
      if (expr->isInfixBinaryOp()) {
        tok_kind = clang::tok::plus;
      } else {
        tok_kind = clang::tok::plus;
      }
      break;
    case clang::OO_Minus:
      if (expr->isInfixBinaryOp()) {
        tok_kind = clang::tok::minus;
      } else {
        tok_kind = clang::tok::minus;
      }
      break;
    case clang::OO_Star:
      if (expr->isInfixBinaryOp()) {
        tok_kind = clang::tok::star;
      } else {
        tok_kind = clang::tok::star;
      }
      break;
    case clang::OO_Slash:
      tok_kind = clang::tok::slash;
      break;
    case clang::OO_Percent:
      tok_kind = clang::tok::percent;
      break;
    case clang::OO_Caret:
      tok_kind = clang::tok::caret;
      break;
    case clang::OO_Amp:
      tok_kind = clang::tok::amp;
      break;
    case clang::OO_Pipe:
      tok_kind = clang::tok::pipe;
      break;
    case clang::OO_Tilde:
      tok_kind = clang::tok::tilde;
      break;
    case clang::OO_Exclaim:
      tok_kind = clang::tok::exclaim;
      break;
    case clang::OO_Equal:
      tok_kind = clang::tok::equal;
      break;
    case clang::OO_Less:
      tok_kind = clang::tok::less;
      break;
    case clang::OO_Greater:
      tok_kind = clang::tok::greater;
      break;
    case clang::OO_PlusEqual:
      tok_kind = clang::tok::plusequal;
      break;
    case clang::OO_MinusEqual:
      tok_kind = clang::tok::minusequal;
      break;
    case clang::OO_StarEqual:
      tok_kind = clang::tok::starequal;
      break;
    case clang::OO_SlashEqual:
      tok_kind = clang::tok::slashequal;
      break;
    case clang::OO_PercentEqual:
      tok_kind = clang::tok::percentequal;
      break;
    case clang::OO_CaretEqual:
      tok_kind = clang::tok::caretequal;
      break;
    case clang::OO_AmpEqual:
      tok_kind = clang::tok::ampequal;
      break;
    case clang::OO_PipeEqual:
      tok_kind = clang::tok::pipeequal;
      break;
    case clang::OO_LessLess:
      tok_kind = clang::tok::lessless;
      break;
    case clang::OO_GreaterGreater:
      tok_kind = clang::tok::greatergreater;
      break;
    case clang::OO_LessLessEqual:
      tok_kind = clang::tok::lesslessequal;
      break;
    case clang::OO_GreaterGreaterEqual:
      tok_kind = clang::tok::greatergreaterequal;
      break;
    case clang::OO_EqualEqual:
      tok_kind = clang::tok::equalequal;
      break;
    case clang::OO_ExclaimEqual:
      tok_kind = clang::tok::exclaimequal;
      break;
    case clang::OO_LessEqual:
      tok_kind = clang::tok::lessequal;
      break;
    case clang::OO_GreaterEqual:
      tok_kind = clang::tok::greaterequal;
      break;
    case clang::OO_Spaceship:
      tok_kind = clang::tok::spaceship;
      break;
    case clang::OO_AmpAmp:
      tok_kind = clang::tok::ampamp;
      break;
    case clang::OO_PipePipe:
      tok_kind = clang::tok::pipepipe;
      break;
    case clang::OO_PlusPlus:
      if (expr->isInfixBinaryOp()) {
        tok_kind = clang::tok::plusplus;
      } else {
        tok_kind = clang::tok::plusplus;
      }
      break;
    case clang::OO_MinusMinus:
      if (expr->isInfixBinaryOp()) {
        tok_kind = clang::tok::minusminus;
      } else {
        tok_kind = clang::tok::minusminus;
      }
      break;

    case clang::OO_Comma:
      tok_kind = clang::tok::comma;
      break;

    case clang::OO_ArrowStar:
      tok_kind = clang::tok::arrowstar;
      break;

    case clang::OO_Arrow:
      tok_kind = clang::tok::arrow;
      break;

    case clang::OO_Call:
      tok_kind = clang::tok::r_paren;
      open_tok_kind = clang::tok::l_paren;
      break;

    case clang::OO_Subscript:
      tok_kind = clang::tok::r_square;
      open_tok_kind = clang::tok::l_square;
      break;

    case clang::OO_Conditional:
      // TODO(pag): Find `:`.
      tok_kind = clang::tok::question;
      break;

    case clang::OO_Coawait:
      tok_kind = clang::tok::kw_co_await;
      break;

    default:
      break;
  }

  EnterExitEntity entity_tracker(entity_stack, expr->getCalleeDecl());

  if (auto op_tok = ast.RawTokenAt(expr->getOperatorLoc());
      op_tok && op_tok->kind == tok_kind &&
      tok_kind != clang::tok::unknown) {

    AssignContext(op_tok);
    if (open_tok_kind != clang::tok::unknown) {
      if (auto open_tok = ScanForMatching(op_tok, -1);
          open_tok->kind == open_tok_kind) {
        AssignContext(open_tok);
      }
    }
  }
})

void TokenContextAssigner::VisitCommonCallExpr(clang::CallExpr *expr,
                                              clang::Decl *called_decl) {
  if (auto [lparen_tok, rparen_tok] = GetMatching(expr->getRParenLoc());
      lparen_tok && lparen_tok->kind == clang::tok::l_paren &&
      rparen_tok && rparen_tok->kind == clang::tok::r_paren) {
    EnterExitEntity entity_tracker(entity_stack, called_decl);
    AssignContext(lparen_tok);
    AssignContext(rparen_tok);
  }
}

EXPR_VISITOR(CallExpr, {

  for (auto arg : expr->children()) {
    this->StmtVisitor::Visit(arg);
    // TODO(pag): Comma.
  }

  this->StmtVisitor::Visit(expr->getCallee());
  VisitCommonCallExpr(expr, expr->getCalleeDecl());
})

EXPR_VISITOR(CXXMemberCallExpr,  {
  for (auto arg : expr->children()) {
    this->StmtVisitor::Visit(arg);
    // TODO(pag): Comma.
  }

  this->StmtVisitor::Visit(expr->getImplicitObjectArgument());
  this->StmtVisitor::Visit(expr->getCallee());

  if (auto method_decl = expr->getMethodDecl(); method_decl) {
    VisitCommonCallExpr(expr, method_decl);
  } else {
    VisitCommonCallExpr(expr, expr->getCalleeDecl());
  }
})

EXPR_VISITOR(CXXConstructExpr, {

  for (auto arg : expr->children()) {
    this->StmtVisitor::Visit(arg);
    // TODO(pag): Comma.
  }

  auto decl = expr->getConstructor();
  const auto orig_decl = decl;
  clang::Decl *xref_target = decl;

  // Try to resolve the targeted constructor.
  if (decl) {
    while (decl->isInheritingConstructor() ||
           decl->isDelegatingConstructor()) {
      if (decl->isInheritingConstructor()) {
        const auto inherited = decl->getInheritedConstructor();
        if (auto next_decl = inherited.getConstructor(); next_decl) {
          decl = next_decl;
        } else {
          break;
        }
      } else {
        if (auto delegated = decl->getTargetConstructor(); delegated) {
          decl = delegated;
        }
      }
    }

    // If the resolved constructor is implicit, then cross-reference the
    // parens/braces to the record itself.
    //
    // TODO(pag): Better understand `isUserProvided` and if it is what we
    //            want to be checking.
    if (decl->isImplicit() || !decl->isUserProvided()) {
      xref_target = orig_decl->getParent();
    } else {
      xref_target = decl;
    }
  }

  EnterExitEntity entity_tracker(entity_stack, xref_target);

  auto range = expr->getParenOrBraceRange();
  if (auto [lparen_tok, rparen_tok] = GetMatching(range);
      lparen_tok && rparen_tok) {
    AssignContext(lparen_tok);
    AssignContext(rparen_tok);
  }

  // TODO(pag): Add special kind of cross-reference when we're coming from an
  //            implicit cast / materialize of a temporary.
})

void TokenContextAssigner::VisitCommonControlFlowStmt(
      clang::Stmt *,
      clang::SourceLocation kw_loc,
      TokenImpl *rparen_tok_) {
  AssignContext(kw_loc);
  if (auto [lparen_tok, rparen_tok] = GetMatching(rparen_tok_);
      lparen_tok && lparen_tok->kind == clang::tok::l_paren &&
      rparen_tok && rparen_tok->kind == clang::tok::r_paren) {
    AssignContext(lparen_tok);
    AssignContext(rparen_tok);
  }
}

void TokenContextAssigner::VisitCommonControlFlowStmt(
      clang::Stmt *stmt,
      clang::SourceLocation kw_loc,
      clang::SourceLocation rparen_loc) {
  return VisitCommonControlFlowStmt(stmt, kw_loc, ast.RawTokenAt(rparen_loc));
}

STMT_VISITOR(IfStmt, {

  if (auto init = stmt->getInit()) {
    this->StmtVisitor::Visit(init);
    // TODO(pag): Apply a token kind to the `;`.
  }

  this->StmtVisitor::Visit(stmt->getCond());
  this->StmtVisitor::Visit(stmt->getThen());

  VisitCommonControlFlowStmt(stmt, stmt->getIfLoc(), stmt->getRParenLoc());

  if (auto then_stmt = clang::dyn_cast<clang::CompoundStmt>(stmt->getThen())) {
    VisitCommonCompoundStmt(then_stmt);
  }

  if (auto else_stmt = stmt->getElse(); else_stmt) {
    AssignContext(stmt->getElseLoc());
    this->StmtVisitor::Visit(else_stmt);
  }
})

// Visit the switch/case stmt node and update the token id's for
// keyword tokens and {l/r} braces.
STMT_VISITOR(SwitchStmt, {
  SaveResetRestore<clang::SwitchStmt *> save_switch(current_switch);
  SaveResetRestore<clang::SourceLocation> save_break(current_break_target);

  current_switch = stmt;
  current_break_target = stmt->getSourceRange().getEnd();

  if (auto init = stmt->getInit(); init) {
    this->StmtVisitor::Visit(init);
    // TODO(pag): Apply a token kind to the `;`.
  }

  this->StmtVisitor::Visit(stmt->getCond());
  this->StmtVisitorBase::Visit(stmt->getBody());
  VisitCommonControlFlowStmt(stmt, stmt->getSwitchLoc(), stmt->getRParenLoc());
})

STMT_VISITOR(DoStmt, {
  SaveResetRestore<clang::SourceLocation> save_break(current_break_target);
  SaveResetRestore<clang::SourceLocation> save_continue(current_continue_target);

  current_break_target = stmt->getSourceRange().getEnd();
  current_continue_target = current_break_target;

  this->StmtVisitor::Visit(stmt->getBody());
  this->StmtVisitor::Visit(stmt->getCond());
  AssignContext(stmt->getDoLoc());
  VisitCommonControlFlowStmt(stmt, stmt->getWhileLoc(), stmt->getRParenLoc());
})

// Visit the while stmt node and update the token id's for
// keyword tokens and {l/r} braces.
STMT_VISITOR(WhileStmt, {
  SaveResetRestore<clang::SourceLocation> save_break(current_break_target);
  SaveResetRestore<clang::SourceLocation> save_continue(current_continue_target);

  current_break_target = stmt->getSourceRange().getEnd();
  current_continue_target = current_break_target;

  this->StmtVisitor::Visit(stmt->getCond());
  this->StmtVisitor::Visit(stmt->getBody());
  VisitCommonControlFlowStmt(stmt, stmt->getWhileLoc(), stmt->getRParenLoc());
})

STMT_VISITOR(ForStmt, {
  SaveResetRestore<clang::SourceLocation> save_break(current_break_target);
  SaveResetRestore<clang::SourceLocation> save_continue(current_continue_target);

  current_break_target = stmt->getSourceRange().getEnd();
  current_continue_target = current_break_target;

  // TODO(pag): Semicolons.

  if (auto init_stmt = stmt->getInit(); init_stmt) {
    this->StmtVisitor::Visit(init_stmt);

    if (auto semi_tok = FindNext(init_stmt->getEndLoc(), clang::tok::semi, 1)) {
      AssignContext(semi_tok);
    }
  }

  if (auto cond_stmt = stmt->getCond(); cond_stmt) {
    if (auto semi_tok = FindNext(cond_stmt->getBeginLoc(), clang::tok::semi, -1)) {
      AssignContext(semi_tok);
    }

    this->StmtVisitor::Visit(cond_stmt);

    if (auto semi_tok = FindNext(cond_stmt->getEndLoc(), clang::tok::semi, 1)) {
      AssignContext(semi_tok);
    }
  }

  if (auto inc_stmt = stmt->getInc(); inc_stmt) {
    if (auto semi_tok = FindNext(inc_stmt->getBeginLoc(), clang::tok::semi, -1)) {
      AssignContext(semi_tok);
    }
    this->StmtVisitor::Visit(inc_stmt);
  }

  const auto body_stmt = stmt->getBody();
  if (body_stmt) {
    this->StmtVisitor::Visit(body_stmt);
  }

  VisitCommonControlFlowStmt(stmt, stmt->getForLoc(), stmt->getRParenLoc());
})

STMT_VISITOR(ReturnStmt, {
  AssignContext(stmt->getReturnLoc());
  if (auto expr = stmt->getRetValue(); expr) {
    this->StmtVisitor::Visit(expr);
    if (auto semi_tok = FindNext(expr->getEndLoc(), clang::tok::semi, 1)) {
      AssignContext(semi_tok);
    }
  } else {
    if (auto semi_tok = FindNext(stmt->getReturnLoc(), clang::tok::semi, 1)) {
      AssignContext(semi_tok);
    }
  }

})

STMT_VISITOR(BreakStmt, {
  AssignContext(stmt->getBreakLoc());  // current_break_target
})

STMT_VISITOR(ContinueStmt, {
  AssignContext(stmt->getContinueLoc());  // current_continue_target
})

STMT_VISITOR(CaseStmt, {
  AssignContext(stmt->getCaseLoc());  // current_switch->getSwitchLoc()
  AssignContext(stmt->getColonLoc());

  if (auto lhs_expr = stmt->getLHS(); lhs_expr) {
    this->StmtVisitor::Visit(lhs_expr);
  }

  if (auto rhs_expr = stmt->getRHS(); rhs_expr) {
    AssignContext(stmt->getEllipsisLoc());
    this->StmtVisitor::Visit(rhs_expr);
  }

  if (auto sub_stmt = stmt->getSubStmt(); sub_stmt) {
    this->StmtVisitor::Visit(sub_stmt);
  }
})

STMT_VISITOR(DefaultStmt, {
  AssignContext(stmt->getDefaultLoc());  // current_switch->getSwitchLoc()
  AssignContext(stmt->getColonLoc());

  if (auto sub_stmt = stmt->getSubStmt(); sub_stmt) {
    this->StmtVisitor::Visit(sub_stmt);
  }
})

STMT_VISITOR(LabelStmt, {
  this->DeclVisitor::Visit(stmt->getDecl());
  AssignContext(stmt->getIdentLoc());

  if (auto colon_tok = FindNext(stmt->getIdentLoc(), clang::tok::colon, 1)) {
    AssignContext(colon_tok);
  }

  if (auto sub_stmt = stmt->getSubStmt(); sub_stmt) {
    this->StmtVisitor::Visit(sub_stmt);
  }
})

STMT_VISITOR(GotoStmt, {
  AssignContext(stmt->getGotoLoc());
  if (auto label = stmt->getLabel()) {
    EnterExitEntity entity_tracker(entity_stack, label);
    AssignContext(stmt->getLabelLoc());
  } else {
    AssignContext(stmt->getLabelLoc());
  }

  if (auto semi_tok = FindNext(stmt->getLabelLoc(), clang::tok::semi, 1)) {
    AssignContext(semi_tok);
  }
})

STMT_VISITOR(NullStmt, {
  AssignContext(stmt->getSemiLoc());
})

EXPR_VISITOR(ParenExpr, {
  this->StmtVisitor::Visit(expr->getSubExpr());

  const auto lparen_loc = expr->getBeginLoc();
  const auto rparen_loc = expr->getEndLoc();
  clang::SourceRange paren_range(lparen_loc, rparen_loc);
  if (auto [lparen_tok, rparen_tok] = GetMatching(paren_range);
      lparen_tok && lparen_tok->kind == clang::tok::l_paren &&
      rparen_tok && rparen_tok->kind == clang::tok::r_paren) {
    AssignContext(lparen_tok);
    AssignContext(rparen_tok);
  }
})

EXPR_VISITOR(ParenListExpr, {
  // TODO(pag): Commas.
  for (auto sub_expr : expr->children()) {
    this->StmtVisitor::Visit(sub_expr);
  }

  auto lparen_loc = expr->getLParenLoc();
  auto rparen_loc = expr->getRParenLoc();
  clang::SourceRange paren_range(lparen_loc, rparen_loc);
  if (auto [lparen_tok, rparen_tok] = GetMatching(paren_range);
      lparen_tok && lparen_tok->kind == clang::tok::l_paren &&
      rparen_tok && rparen_tok->kind == clang::tok::r_paren) {
    AssignContext(lparen_tok);
    AssignContext(rparen_tok);
  }
})

EXPR_VISITOR(StmtExpr, {
  this->StmtVisitor::Visit(expr->getSubStmt());

  auto lparen_loc = expr->getLParenLoc();
  auto rparen_loc = expr->getRParenLoc();
  clang::SourceRange paren_range(lparen_loc, rparen_loc);
  if (auto [lparen_tok, rparen_tok] = GetMatching(paren_range);
      lparen_tok && lparen_tok->kind == clang::tok::l_paren &&
      rparen_tok && rparen_tok->kind == clang::tok::r_paren) {
    AssignContext(lparen_tok);
    AssignContext(rparen_tok);
  }
})

EXPR_VISITOR(DesignatedInitExpr, {

  auto handle_squares = [this] (clang::DesignatedInitExpr::Designator *designator) {
    auto lsquare_loc = designator->getLBracketLoc();
    auto rsquare_loc = designator->getRBracketLoc();
    clang::SourceRange square_range(lsquare_loc, rsquare_loc);
    if (auto [open_tok, close_tok] = GetMatching(square_range);
        open_tok && open_tok->kind == clang::tok::l_square &&
        close_tok && close_tok->kind == clang::tok::r_square) {
      AssignContext(open_tok);
      AssignContext(close_tok);
    }
  };

  for (auto i = 0u, max_i = expr->size(); i < max_i; ++i) {
    const auto designator = expr->getDesignator(i);
    if (designator->isArrayDesignator()) {
      this->StmtVisitor::Visit(expr->getArrayIndex(*designator));
      handle_squares(designator);

    } else if (designator->isArrayRangeDesignator()) {
      this->StmtVisitor::Visit(expr->getArrayRangeStart(*designator));
      this->StmtVisitor::Visit(expr->getArrayRangeEnd(*designator));
      AssignContext(designator->getEllipsisLoc());
      handle_squares(designator);

    } else if (designator->isFieldDesignator()) {
      AssignContext(designator->getDotLoc());

      if (auto field_tok = ast.RawTokenAt(designator->getFieldLoc());
          field_tok && field_tok->kind == clang::tok::identifier) {
        EnterExitEntity entity_tracker(entity_stack, designator->getField());
        AssignContext(field_tok);
      }
    }
  }

  if (auto init_expr = expr->getInit(); init_expr) {
    this->StmtVisitor::Visit(init_expr);
  }

  AssignContext(expr->getEqualOrColonLoc());
})

void TokenContextAssigner::VisitDesignatedInitUpdateExpr(
    clang::DesignatedInitUpdateExpr *expr) {

  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }
}

EXPR_VISITOR(InitListExpr, {
  auto lbrace_loc = expr->getLBraceLoc();
  auto rbrace_loc = expr->getRBraceLoc();
  clang::SourceRange brace_range(lbrace_loc, rbrace_loc);
  if (auto [open_tok, close_tok] = GetMatching(brace_range);
      open_tok && open_tok->kind == clang::tok::l_brace &&
      close_tok && close_tok->kind == clang::tok::r_brace) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }

  // TODO(pag): Commas.

  for (auto sub_expr : expr->children()) {
    this->StmtVisitor::Visit(sub_expr);
  }
})

EXPR_VISITOR(UnaryOperator, {
  this->StmtVisitor::Visit(expr->getSubExpr());
  AssignContext(expr->getOperatorLoc());

//  clang::tok::TokenKind op_tok_kind = clang::tok::unknown;
//  switch (expr->getOpcode()) {
//    case clang::UO_PostInc:
//      op_tok_kind = clang::tok::plusplus;
//      break;
//    case clang::UO_PostDec:
//      op_tok_kind = clang::tok::minusminus;
//      break;
//    case clang::UO_PreInc:
//      op_tok_kind = clang::tok::plusplus;
//      break;
//    case clang::UO_PreDec:
//      op_tok_kind = clang::tok::minusminus;
//      break;
//    case clang::UO_AddrOf:
//      op_tok_kind = clang::tok::amp;
//      break;
//    case clang::UO_Deref:
//      op_tok_kind = clang::tok::star;
//      break;
//    case clang::UO_Plus:
//      op_tok_kind = clang::tok::plus;
//      break;
//    case clang::UO_Minus:
//      op_tok_kind = clang::tok::minus;
//      break;
//    case clang::UO_Not:
//      op_tok_kind = clang::tok::tilde;
//      break;
//    case clang::UO_LNot:
//      op_tok_kind = clang::tok::exclaim;
//      break;
//    case clang::UO_Real:
//      op_tok_kind = clang::tok::kw___real;
//      break;
//    case clang::UO_Imag:
//      op_tok_kind = clang::tok::kw___imag;
//      break;
//    case clang::UO_Extension:
//      op_tok_kind = clang::tok::kw___extension__;
//      break;
//    case clang::UO_Coawait:
//      op_tok_kind = clang::tok::kw_co_await;
//      break;
//  }
//  if (auto op_tok = ast.RawTokenAt(expr->getOperatorLoc());
//      op_tok && op_tok->kind == op_tok_kind) {
//    AssignContext(op_tok);
//  }
})

EXPR_VISITOR(BinaryOperator, {
  this->StmtVisitor::Visit(expr->getLHS());
  this->StmtVisitor::Visit(expr->getRHS());
  AssignContext(expr->getOperatorLoc());

//  const auto op_loc = expr->getOperatorLoc();
//  if (op_loc.MultiplierData) {
//    rpc::TokenKind curr = token_manager.ClassifyLocation(op_loc);
//    rpc::TokenKind repl = curr;
//    switch (expr->getOpcode()) {
//      case clang::BO_PtrMemD:  // `.*`.
//        curr = rpc::PUNC_PERIODSTAR;
//        repl = rpc::PUNC_PERIODSTAR_OPERATOR_BINARY;
//        break;
//      case clang::BO_PtrMemI:  // `->*`.
//        curr = rpc::PUNC_ARROWSTAR;
//        repl = rpc::PUNC_ARROWSTAR_OPERATOR_BINARY;
//        break;
//      case clang::BO_Mul:
//        curr = rpc::PUNC_STAR;
//        repl = rpc::PUNC_STAR_OPERATOR_BINARY;
//        break;
//      case clang::BO_Div:
//        curr = rpc::PUNC_SLASH;
//        repl = rpc::PUNC_SLASH_OPERATOR_BINARY;
//        break;
//      case clang::BO_Rem:
//        curr = rpc::PUNC_PERCENT;
//        repl = rpc::PUNC_PERCENT_OPERATOR_BINARY;
//        break;
//      case clang::BO_Add:
//        curr = rpc::PUNC_PLUS;
//        repl = rpc::PUNC_PLUS_OPERATOR_BINARY;
//        break;
//      case clang::BO_Sub:
//        curr = rpc::PUNC_MINUS;
//        repl = rpc::PUNC_MINUS_OPERATOR_BINARY;
//        break;
//      case clang::BO_Shl:
//        curr = rpc::PUNC_LESSLESS;
//        repl = rpc::PUNC_LESSLESS_OPERATOR_BINARY;
//        break;
//      case clang::BO_Shr:
//        curr = rpc::PUNC_GREATERGREATER;
//        repl = rpc::PUNC_GREATERGREATER_OPERATOR_BINARY;
//        break;
//      case clang::BO_Cmp:  // `<=>`.
//        curr = rpc::PUNC_SPACESHIP;
//        repl = rpc::PUNC_SPACESHIP_OPERATOR_BINARY;
//        break;
//      case clang::BO_LT:
//        curr = rpc::PUNC_LESS;
//        repl = rpc::PUNC_LESS_OPERATOR_BINARY;
//        break;
//      case clang::BO_GT:
//        curr = rpc::PUNC_GREATER;
//        repl = rpc::PUNC_GREATER_OPERATOR_BINARY;
//        break;
//      case clang::BO_LE:
//        curr = rpc::PUNC_LESSEQUAL;
//        repl = rpc::PUNC_LESSEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_GE:
//        curr = rpc::PUNC_GREATEREQUAL;
//        repl = rpc::PUNC_GREATEREQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_EQ:
//        curr = rpc::PUNC_EQUALEQUAL;
//        repl = rpc::PUNC_EQUALEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_NE:
//        curr = rpc::PUNC_EXCLAIMEQUAL;
//        repl = rpc::PUNC_EXCLAIMEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_And:  // `&`.
//        curr = rpc::PUNC_AMP;
//        repl = rpc::PUNC_AMP_OPERATOR_BINARY;
//        break;
//      case clang::BO_Xor:
//        curr = rpc::PUNC_CARET;
//        repl = rpc::PUNC_CARET_OPERATOR_BINARY;
//        break;
//      case clang::BO_Or:
//        curr = rpc::PUNC_PIPE;
//        repl = rpc::PUNC_PIPE_OPERATOR_BINARY;
//        break;
//      case clang::BO_LAnd:  // `&&`.
//        curr = rpc::PUNC_AMPAMP;
//        repl = rpc::PUNC_AMPAMP_OPERATOR_BINARY;
//        break;
//      case clang::BO_LOr:
//        curr = rpc::PUNC_PIPEPIPE;
//        repl = rpc::PUNC_PIPEPIPE_OPERATOR_BINARY;
//        break;
//      case clang::BO_Assign:
//        curr = rpc::PUNC_EQUAL;
//        repl = rpc::PUNC_EQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_MulAssign:
//        curr = rpc::PUNC_STAREQUAL;
//        repl = rpc::PUNC_STAREQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_DivAssign:
//        curr = rpc::PUNC_SLASHEQUAL;
//        repl = rpc::PUNC_SLASHEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_RemAssign:
//        curr = rpc::PUNC_PERCENTEQUAL;
//        repl = rpc::PUNC_PERCENTEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_AddAssign:
//        curr = rpc::PUNC_PLUSEQUAL;
//        repl = rpc::PUNC_PLUSEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_SubAssign:
//        curr = rpc::PUNC_MINUSEQUAL;
//        repl = rpc::PUNC_MINUSEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_ShlAssign:
//        curr = rpc::PUNC_LESSLESSEQUAL;
//        repl = rpc::PUNC_LESSLESSEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_ShrAssign:
//        curr = rpc::PUNC_GREATERGREATEREQUAL;
//        repl = rpc::PUNC_GREATERGREATEREQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_AndAssign:
//        curr = rpc::PUNC_AMPEQUAL;
//        repl = rpc::PUNC_AMPEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_XorAssign:
//        curr = rpc::PUNC_CARETEQUAL;
//        repl = rpc::PUNC_CARETEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_OrAssign:
//        curr = rpc::PUNC_PIPEEQUAL;
//        repl = rpc::PUNC_PIPEEQUAL_OPERATOR_BINARY;
//        break;
//      case clang::BO_Comma:
//        curr = rpc::PUNC_COMMA;
//        repl = rpc::PUNC_COMMA_OPERATOR_BINARY;
//        break;
//    }
//    token_forest.MapToken(op_loc, curr, repl);
//  }
})

EXPR_VISITOR(ConditionalOperator, {
  this->StmtVisitor::Visit(expr->getCond());
  this->StmtVisitor::Visit(expr->getTrueExpr());
  this->StmtVisitor::Visit(expr->getFalseExpr());
  AssignContext(expr->getQuestionLoc());
  AssignContext(expr->getColonLoc());
})

EXPR_VISITOR(DeclRefExpr, {

  if (expr->hasQualifier()) {
    VisitNestedNameSpecifier(expr, expr->getQualifier());
  }

  if (expr->hasTemplateKWAndArgsInfo()) {
    auto langle_loc = expr->getLAngleLoc();
    auto rangle_loc = expr->getRAngleLoc();
    clang::SourceRange angle_range(langle_loc, rangle_loc);
    if (auto [open_tok, close_tok] = GetMatching(angle_range);
        open_tok && open_tok->kind == clang::tok::less &&
        close_tok && close_tok->kind == clang::tok::greater) {
      AssignContext(open_tok);
      AssignContext(close_tok);
    }

    for (auto arg : expr->template_arguments()) {
      VisitTemplateArgumentLoc(arg);
      // TODO(pag): Handle comma.
    }
  }

  clang::Decl *decl = expr->getFoundDecl();
  if (!decl) {
    decl = expr->getDecl();
  }

  const auto assign_tok = [this] (clang::SourceLocation ident_loc) {
    if (auto ident_tok = ast.RawTokenAt(ident_loc);
        ident_tok && ident_tok->kind == clang::tok::identifier) {
      AssignContext(ident_tok);
    }
  };

  if (decl) {
    EnterExitEntity entity_tracker(entity_stack, decl);
    assign_tok(expr->getNameInfo().getLoc());
    assign_tok(expr->getLocation());
    assign_tok(expr->getExprLoc());
  } else {
    assign_tok(expr->getNameInfo().getLoc());
    assign_tok(expr->getLocation());
    assign_tok(expr->getExprLoc());
  }
})

EXPR_VISITOR(MemberExpr, {
  this->StmtVisitor::Visit(expr->getBase());

  if (expr->hasQualifier()) {
    VisitNestedNameSpecifier(expr, expr->getQualifier());
  }

  clang::Decl *decl = expr->getFoundDecl().getDecl();
  if (!decl) {
    decl = expr->getMemberDecl();
    if (!decl) {
      decl = expr->getSourceBitField();
      if (!decl) {
        decl = expr->getReferencedDeclOfCallee();
      }
    }
  }

  const auto assign_tok = [this] (clang::SourceLocation ident_loc) {
    auto ident_tok = ast.RawTokenAt(ident_loc);
    if (ident_tok && ident_tok->kind == clang::tok::identifier) {
      AssignContext(ident_tok);
    }
  };

  if (!IsImplicitThis(expr)) {
    AssignContext(expr->getOperatorLoc());
  }

  if (decl) {
    EnterExitEntity entity_tracker(entity_stack, decl);
    assign_tok(expr->getMemberNameInfo().getLoc());
    assign_tok(expr->getMemberLoc());
  } else {
    assign_tok(expr->getMemberNameInfo().getLoc());
    assign_tok(expr->getMemberLoc());
  }


  if (expr->hasExplicitTemplateArgs()) {
    auto langle_loc = expr->getLAngleLoc();
    auto rangle_loc = expr->getRAngleLoc();
    clang::SourceRange angle_range(langle_loc, rangle_loc);
    if (auto [open_tok, close_tok] = GetMatching(angle_range);
        open_tok && open_tok->kind == clang::tok::less &&
        close_tok && close_tok->kind == clang::tok::greater) {
      AssignContext(open_tok);
      AssignContext(close_tok);
    }

    for (auto arg : expr->template_arguments()) {
      VisitTemplateArgumentLoc(arg);
      // TODO(pag): Handle comma.
    }
  }
})

EXPR_VISITOR(CXXDependentScopeMemberExpr, {

  if (!expr->isImplicitAccess()) {
    if (auto base = expr->getBase(); base) {
      this->StmtVisitor::Visit(expr->getBase());
    }
  }

  if (expr->hasExplicitTemplateArgs()) {
    auto langle_loc = expr->getLAngleLoc();
    auto rangle_loc = expr->getRAngleLoc();
    clang::SourceRange angle_range(langle_loc, rangle_loc);
    if (auto [open_tok, close_tok] = GetMatching(angle_range);
        open_tok && open_tok->kind == clang::tok::less &&
        close_tok && close_tok->kind == clang::tok::greater) {
      AssignContext(open_tok);
      AssignContext(close_tok);
    }

    for (auto arg : expr->template_arguments()) {
      VisitTemplateArgumentLoc(arg);
      // TODO(pag): Handle comma.
    }
  }
})

EXPR_VISITOR(ImplicitCastExpr, {
  // TODO(pag): Add use of type conversion or constructors, if any.
  //    `-FunctionDecl <line:7:1, line:10:1> line:7:5 main 'int ()'
  //      `-CompoundStmt <col:16, line:10:1>
  //        |-ExprWithCleanups <line:8:5, col:10> 'void'
  //        | `-CallExpr <col:5, col:10> 'void'
  //        |   |-ImplicitCastExpr <col:5> 'void (*)(X)' <FunctionToPointerDecay>
  //        |   | `-DeclRefExpr <col:5> 'void (X)' lvalue Function 0x56446cd22398 'foo' 'void (X)'
  //        |   `-CXXConstructExpr <col:9> 'X' 'void (X &&) noexcept' elidable
  //        |     `-MaterializeTemporaryExpr <col:9> 'X' xvalue
  //        |       `-ImplicitCastExpr <col:9> 'X' <ConstructorConversion>
  //        |         `-CXXConstructExpr <col:9> 'X' 'void (int)'
  //        |           `-IntegerLiteral <col:9> 'int'
  this->StmtVisitor::Visit(expr->getSubExpr());
})

EXPR_VISITOR(ExplicitCastExpr, {
  if (auto info = expr->getTypeInfoAsWritten(); info) {
    this->TypeLocVisitor::Visit(info->getTypeLoc());
  }
  this->StmtVisitor::Visit(expr->getSubExpr());
})

EXPR_VISITOR(CStyleCastExpr, {
  VisitExplicitCastExpr(expr);

  auto lparen_loc = expr->getLParenLoc();
  auto rparen_loc = expr->getRParenLoc();
  clang::SourceRange paren_range(lparen_loc, rparen_loc);

  if (auto [open_tok, close_tok] = GetMatching(paren_range);
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(CXXFunctionalCastExpr, {
  VisitExplicitCastExpr(expr);

  auto lparen_loc = expr->getLParenLoc();
  auto rparen_loc = expr->getRParenLoc();
  clang::SourceRange paren_range(lparen_loc, rparen_loc);
  if (auto [open_tok, close_tok] = GetMatching(paren_range);
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(CXXNamedCastExpr, {
  VisitExplicitCastExpr(expr);

  auto rparen_loc = expr->getRParenLoc();
  if (auto [open_tok, close_tok] = GetMatching(rparen_loc);
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }

  auto angle_range = expr->getAngleBrackets();
  if (auto [open_tok, close_tok] = GetMatching(angle_range);
      open_tok && open_tok->kind == clang::tok::less &&
      close_tok && close_tok->kind == clang::tok::greater) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(CXXNewExpr, {
  auto annotate = [=] (void) {
    const auto num_placement_args = expr->getNumPlacementArgs();
    if (auto type_info = expr->getAllocatedTypeSourceInfo(); type_info) {
      this->TypeLocVisitor::Visit(type_info->getTypeLoc());
    }

    if (num_placement_args) {
      for (auto i = 0u; i < num_placement_args; ++i) {
        this->StmtVisitor::Visit(expr->getPlacementArg(i));
      }
    }

    if (auto init_expr = expr->getInitializer(); init_expr) {
      this->StmtVisitor::Visit(init_expr);
    }

    if (auto maybe_size = expr->getArraySize(); maybe_size) {
      this->StmtVisitor::Visit(maybe_size.getValue());
    }

    const auto new_tok = FindNext(expr->getBeginLoc(), clang::tok::kw_new, 1);
    if (new_tok) {
      AssignContext(new_tok);
    }

    if (new_tok && num_placement_args) {
      if (auto lparen_tok = FindNext(new_tok, clang::tok::l_paren, 1)) {
        if (auto rparen_tok = ScanForMatching(lparen_tok, 1)) {
          AssignContext(lparen_tok);
          AssignContext(rparen_tok);
        }
      }
    }

    if (expr->isArray()) {
      if (auto rsquare_tok = FindNext(expr->getEndLoc(), clang::tok::r_square, -1)) {
        if (auto lsquare_tok = ScanForMatching(rsquare_tok, -1)) {
          AssignContext(lsquare_tok);
          AssignContext(rsquare_tok);
        }
      }
    }
  };

  if (auto new_decl = expr->getOperatorNew()) {
    EnterExitEntity entity_tracker(entity_stack, new_decl);
    annotate();
  } else {
    annotate();
  }
})

EXPR_VISITOR(CXXDeleteExpr, {
  if (auto arg_expr = expr->getArgument(); arg_expr) {
    this->StmtVisitor::Visit(arg_expr);
  }

  auto annotate = [=] (void) {
    const auto del_tok = FindNext(expr->getBeginLoc(), clang::tok::kw_delete, 1);
    if (del_tok) {
      expr->getOperatorDelete();
      AssignContext(del_tok);

      if (expr->isArrayForm() || expr->isArrayFormAsWritten()) {
        if (auto lsquare_tok = FindNext(del_tok, clang::tok::l_square, 1)) {
          if (auto rsquare_tok = ScanForMatching(lsquare_tok, 1)) {
            AssignContext(lsquare_tok);
            AssignContext(rsquare_tok);
          }
        }
      }
    }
  };

  if (auto del_decl = expr->getOperatorDelete()) {
    EnterExitEntity entity_tracker(entity_stack, del_decl);
    annotate();
  } else {
    annotate();
  }
})

EXPR_VISITOR(CXXThisExpr, {
  if (current_method) {
    EnterExitEntity entity_tracker(entity_stack, current_method->getParent());
    AssignContext(expr->getLocation());
  } else {
    AssignContext(expr->getLocation());
  }
})

EXPR_VISITOR(CXXThrowExpr, {
  AssignContext(expr->getThrowLoc());
  if (auto sub_expr = expr->getSubExpr(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }
})

EXPR_VISITOR(CXXNoexceptExpr, {
  // TODO(pag): `noexcept` keyword?
  if (auto sub_expr = expr->getOperand(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }
})

void TokenContextAssigner::VisitCXXNullPtrLiteralExpr(
    clang::CXXNullPtrLiteralExpr *expr) {
  AssignContext(expr->getLocation());
}

EXPR_VISITOR(CXXPseudoDestructorExpr, {
  this->StmtVisitor::Visit(expr->getBase());

  if (expr->hasQualifier()) {
    VisitNestedNameSpecifier(expr, expr->getQualifier());
  }

  auto visit_type_info = [=] (void) {
    if (auto type_info = expr->getScopeTypeInfo(); type_info) {
      this->TypeLocVisitor::Visit(type_info->getTypeLoc());
    }

    if (auto type_info = expr->getDestroyedTypeInfo(); type_info) {
      this->TypeLocVisitor::Visit(type_info->getTypeLoc());
    }
  };

  AssignContext(expr->getOperatorLoc());
  AssignContext(expr->getColonColonLoc());

  if (auto xref_target = expr->getReferencedDeclOfCallee()) {
    EnterExitEntity entity_tracker(entity_stack, xref_target);
    AssignContext(expr->getTildeLoc());
    visit_type_info();
  } else {
    visit_type_info();
  }
})

EXPR_VISITOR(CXXScalarValueInitExpr, {
  if (auto type_info = expr->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (auto [open_tok, close_tok] = GetMatching(expr->getRParenLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(CXXStdInitializerListExpr, {
  if (auto sub_expr = expr->getSubExpr(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }
})

EXPR_VISITOR(CXXTypeidExpr, {
  if (expr->isTypeOperand()) {
    if (auto type_info = expr->getTypeOperandSourceInfo(); type_info) {
      this->TypeLocVisitor::Visit(type_info->getTypeLoc());
    }

  } else if (auto sub_expr = expr->getExprOperand(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }

  if (auto [open_tok, close_tok] = GetMatching(expr->getEndLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);

    if (auto type_id_tok = FindNext(open_tok, clang::tok::kw_typeid, -1)) {
      AssignContext(type_id_tok);
    }
  }
})

EXPR_VISITOR(CXXUuidofExpr, {
  if (expr->isTypeOperand()) {
    if (auto type_info = expr->getTypeOperandSourceInfo(); type_info) {
      this->TypeLocVisitor::Visit(type_info->getTypeLoc());
    }

  } else if (auto sub_expr = expr->getExprOperand(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }

  if (auto [open_tok, close_tok] = GetMatching(expr->getEndLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);

    if (auto type_id_tok = FindNext(open_tok, clang::tok::kw___uuidof, -1)) {
      AssignContext(type_id_tok);
    }
  }
})

void TokenContextAssigner::VisitMaterializeTemporaryExpr(
    clang::MaterializeTemporaryExpr *expr) {
  if (auto temp_expr = expr->getSubExpr()) {
    this->StmtVisitor::Visit(temp_expr);
  }
}

void TokenContextAssigner::VisitCXXBindTemporaryExpr(
    clang::CXXBindTemporaryExpr *expr) {
  if (auto sub_expr = expr->getSubExpr(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }

  // TODO(pag): Destructor via `getTemporary()`.
}

void TokenContextAssigner::VisitExprWithCleanups(
    clang::ExprWithCleanups *expr) {
  this->StmtVisitor::Visit(expr->getSubExpr());
  // TODO(pag): Destructor / cleanup calls?
}

void TokenContextAssigner::VisitIntegerLiteral(
    clang::IntegerLiteral *expr) {
  AssignContext(expr->getExprLoc());
}

EXPR_VISITOR(VAArgExpr, {
  if (auto type_info = expr->getWrittenTypeInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (auto sub_expr = expr->getSubExpr(); sub_expr) {
    this->StmtVisitor::Visit(sub_expr);
  }

  AssignContext(expr->getBuiltinLoc());
  if (auto [open_tok, close_tok] = GetMatching(expr->getRParenLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(AddrLabelExpr, {
  AssignContext(expr->getAmpAmpLoc());
  if (auto label_decl = expr->getLabel()) {
    EnterExitEntity entity_tracker(entity_stack, label_decl);
    AssignContext(expr->getLabelLoc());
  } else {
    AssignContext(expr->getLabelLoc());
  }
})

void TokenContextAssigner::VisitSubstNonTypeTemplateParmExpr(
    clang::SubstNonTypeTemplateParmExpr *expr) {
  // TODO(pag): Gener
  this->DeclVisitor::Visit(expr->getParameter());
  this->StmtVisitor::Visit(expr->getReplacement());
}

void TokenContextAssigner::VisitChooseExpr(clang::ChooseExpr *expr) {
  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }
}

void TokenContextAssigner::VisitBlockExpr(clang::BlockExpr *expr) {
  this->DeclVisitor::Visit(expr->getBlockDecl());
}

EXPR_VISITOR(LambdaExpr, {

  // If it's not a generic lambda then there are no template decls associated
  // with it, and we can visit it inline.
  if (!expr->isGenericLambda()) {
    SaveResetRestore<unsigned> save_statement_depth(statement_depth);
    SaveResetRestore<clang::CXXMethodDecl *> save_current_method(current_method);

    this->DeclVisitor::Visit(expr->getLambdaClass());
    // this->DeclVisitor::Visit(expr->getCallOperator());  // Maybe redundant.
    // this->StmtVisitor::Visit(expr->getBody());  // Probably redundant...
  }

  // Regardless of if it's a generic lambda, the captures themselves will
  // be context-sensitive, and thus not generic.
  if (expr->capture_size()) {
    for (const auto &capture : expr->captures()) {
      // TODO(pag): Commas.
      if (capture.isExplicit() && capture.capturesVariable()) {
        this->DeclVisitor::Visit(capture.getCapturedVar());
      }

//      // TODO(pag): Maybe move `this` capture logic from `CXXMethodDecl` to
//      //            here.
//      LOG_IF(ERROR, !current_method && capture.capturesThis())
//          << StmtLocation(expr, expr->getExprLoc())
//          << "Lambda captures this pointer but current_method is null";
    }
  }

  for (auto capture_init : expr->capture_inits()) {
    this->StmtVisitor::Visit(capture_init);
  }

  // Get the `[` and `]`.
  if (auto [open_tok, close_tok] = GetMatching(expr->getIntroducerRange());
      open_tok && open_tok->kind == clang::tok::l_square &&
      close_tok && close_tok->kind == clang::tok::r_square) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }

  this->StmtVisitor::Visit(expr->getBody());
})

EXPR_VISITOR(ArrayInitLoopExpr, {
  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }
})

void TokenContextAssigner::VisitArrayInitIndexExpr(
    clang::ArrayInitIndexExpr *) {
  // Not much to do I don't think...
}

void TokenContextAssigner::VisitImplicitValueInitExpr(
    clang::ImplicitValueInitExpr *) {
  // Not much to do I don't think...
}

EXPR_VISITOR(ArraySubscriptExpr, {

  for (auto sub_expr : expr->children()) {
    this->StmtVisitor::Visit(sub_expr);
  }

  if (auto [open_tok, close_tok] = GetMatching(expr->getRBracketLoc());
      open_tok && open_tok->kind == clang::tok::l_square &&
      close_tok && close_tok->kind == clang::tok::r_square) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

static const auto kBadPtr = reinterpret_cast<void *>(static_cast<intptr_t>(-1));

EXPR_VISITOR(ArrayTypeTraitExpr, {

  if (auto dim = expr->getDimensionExpression(); dim && dim != kBadPtr) {
    this->StmtVisitor::Visit(dim);
  }

  if (auto type_info = expr->getQueriedTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (auto kw_tok = ast.RawTokenAt(expr->getBeginLoc());
      kw_tok && clang::tok::getKeywordSpelling(
                    static_cast<clang::tok::TokenKind>(kw_tok->kind))) {
    AssignContext(kw_tok);
  }

  if (auto [open_tok, close_tok] = GetMatching(expr->getEndLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(OffsetOfExpr, {
  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }

  if (auto type_info = expr->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  AssignContext(expr->getOperatorLoc());
  if (auto [open_tok, close_tok] = GetMatching(expr->getEndLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(AtomicExpr, {
  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }

  // TODO(pag): Commas.

  AssignContext(expr->getBuiltinLoc());
  if (auto [open_tok, close_tok] = GetMatching(expr->getEndLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(CompoundLiteralExpr, {
  if (auto type_info = expr->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }

  if (auto init_expr = expr->getInitializer(); init_expr) {
    this->StmtVisitor::Visit(init_expr);
  }

  if (auto [open_tok, close_tok] = GetMatching(expr->getLParenLoc());
      open_tok && open_tok->kind == clang::tok::l_paren &&
      close_tok && close_tok->kind == clang::tok::r_paren) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }
})

EXPR_VISITOR(CoroutineSuspendExpr, {
  AssignContext(expr->getKeywordLoc());
  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }
})

void TokenContextAssigner::VisitCoawaitExpr(clang::CoawaitExpr *expr) {
  VisitCoroutineSuspendExpr(expr);
}

void TokenContextAssigner::VisitCoyieldExpr(clang::CoyieldExpr *expr) {
  VisitCoroutineSuspendExpr(expr);
}

EXPR_VISITOR(DependentCoawaitExpr, {
  AssignContext(expr->getKeywordLoc());
  for (auto sub_expr : expr->children()) {
    if (sub_expr) {
      this->StmtVisitor::Visit(sub_expr);
    }
  }
})

void TokenContextAssigner::VisitCXXBoolLiteralExpr(
    clang::CXXBoolLiteralExpr *expr) {
  AssignContext(expr->getLocation());
}

EXPR_VISITOR(CXXTemporaryObjectExpr, {
  if (auto type_info = expr->getTypeSourceInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }
  VisitCXXConstructExpr(expr);
})

void TokenContextAssigner::VisitCXXDefaultArgExpr(
    clang::CXXDefaultArgExpr *) {
  // TODO(pag): Add xref?
}

#define TYPELOC_VISITOR(cls, ...) \
    void TokenContextAssigner::Visit ## cls(clang::cls loc) { \
      EnterExitEntity entity_tracker(entity_stack, loc); \
      __VA_ARGS__ \
    }

TYPELOC_VISITOR(TagTypeLoc, {
  if (auto decl = loc.getDecl()) {
    if (auto name_tok = ast.RawTokenAt(loc.getNameLoc());
        name_tok && name_tok->kind == clang::tok::identifier) {
      EnterExitEntity entity_tracker(entity_stack, decl);
      AssignContext(name_tok);
    }
  }
})

TYPELOC_VISITOR(FunctionTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getReturnLoc());
  for (auto param : loc.getParams()) {
    if (param) {
      if (auto param_info = param->getTypeSourceInfo(); param_info) {
        this->TypeLocVisitor::Visit(param_info->getTypeLoc());
      }
    }
  }

  // TODO(pag): Is the L/RParen location for the params, or for the
  //            name? I.e. `int (*foo)(params...);`.
  auto lparen_loc = loc.getLParenLoc();
  auto rparen_loc = loc.getRParenLoc();
  (void) lparen_loc;
  (void) rparen_loc;
})

TYPELOC_VISITOR(PointerTypeLoc, {
  AssignContext(loc.getStarLoc());
  this->TypeLocVisitor::Visit(loc.getPointeeLoc());
})

TYPELOC_VISITOR(MemberPointerTypeLoc, {
  if (auto type_info = loc.getClassTInfo(); type_info) {
    this->TypeLocVisitor::Visit(type_info->getTypeLoc());
  }
  // TODO(pag): Find the `::`.
  this->TypeLocVisitor::Visit(loc.getPointeeLoc());
  AssignContext(loc.getSigilLoc());
})

TYPELOC_VISITOR(ReferenceTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getPointeeLoc());
  AssignContext(loc.getSigilLoc());
})

TYPELOC_VISITOR(LValueReferenceTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getPointeeLoc());
  AssignContext(loc.getSigilLoc());
})

TYPELOC_VISITOR(RValueReferenceTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getPointeeLoc());
  AssignContext(loc.getSigilLoc());
})

TYPELOC_VISITOR(ArrayTypeLoc, {
  if (auto size_expr = loc.getSizeExpr(); size_expr) {
    this->StmtVisitor::Visit(size_expr);
  }

  this->TypeLocVisitor::Visit(loc.getElementLoc());
  AssignContext(loc.getLBracketLoc());
  AssignContext(loc.getRBracketLoc());
})

TYPELOC_VISITOR(ParenTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getInnerLoc());
  AssignContext(loc.getLParenLoc());
  AssignContext(loc.getRParenLoc());
})

TYPELOC_VISITOR(InjectedClassNameTypeLoc, {

//  clang::Decl *decl = loc.getDecl();
//  if (!decl) {
//    decl = TypeToDecl(loc.getTypePtr());
//  }
//  rpc::TokenKind name_kind = decl ? ClassifyDecl(decl) :
//                             rpc::IDENTIFIER_NAME_CLASS_CXX;
//
//  auto name_loc = loc.getNameLoc();
//  if (token_forest.MapToken(name_loc, rpc::IDENTIFIER_NAME, name_kind) &&
//      decl) {
//    AssignContext(name_loc, decl);
//  }
})

TYPELOC_VISITOR(DependentNameTypeLoc, {
//  if (auto qual_loc = loc.getQualifierLoc(); qual_loc) {
//    VisitNestedNameSpecifierLoc(qual_loc);
//  }
//
//  clang::Decl *decl = TypeToDecl(loc.getTypePtr());
//
//  auto name_loc = loc.getNameLoc();
//  if (decl &&
//      token_forest.MapToken(name_loc, rpc::IDENTIFIER_NAME,
//                            ClassifyDecl(decl))) {
//    AssignContext(name_loc, decl);
//  }
})

TYPELOC_VISITOR(DependentTemplateSpecializationTypeLoc, {

  for (auto i = 0U, max_i = loc.getNumArgs(); i < max_i; ++i) {
    this->VisitTemplateArgumentLoc(loc.getArgLoc(i));
  }

  if (auto qual_loc = loc.getQualifierLoc(); qual_loc) {
    VisitNestedNameSpecifierLoc(qual_loc);
  }

  AssignContext(loc.getLAngleLoc());
  AssignContext(loc.getRAngleLoc());

  if (auto name_tok = ast.RawTokenAt(loc.getTemplateNameLoc());
      name_tok && name_tok->kind == clang::tok::identifier) {
    if (auto decl = TypeToDecl(loc.getTypePtr())) {
      EnterExitEntity entity_tracker(entity_stack, decl);
      AssignContext(name_tok);
    } else {
      AssignContext(name_tok);
    }
  }
})

TYPELOC_VISITOR(TemplateSpecializationTypeLoc, {

  for (auto i = 0U, max_i = loc.getNumArgs(); i < max_i; ++i) {
    this->VisitTemplateArgumentLoc(loc.getArgLoc(i));
  }

  auto langle_loc = loc.getLAngleLoc();
  auto rangle_loc = loc.getRAngleLoc();
  clang::SourceRange angle_range(langle_loc, rangle_loc);
  if (auto [open_tok, close_tok] = GetMatching(angle_range);
      open_tok && open_tok->kind == clang::tok::less &&
      close_tok && close_tok->kind == clang::tok::greater) {
    AssignContext(open_tok);
    AssignContext(close_tok);
  }

  if (auto name_tok = ast.RawTokenAt(loc.getTemplateNameLoc());
      name_tok && name_tok->kind == clang::tok::identifier) {
    if (auto decl = TypeToDecl(loc.getTypePtr())) {
      EnterExitEntity entity_tracker(entity_stack, decl);
      AssignContext(name_tok);
    } else {
      AssignContext(name_tok);
    }
  }
})

TYPELOC_VISITOR(TypeLoc, {
  if (auto next_loc = loc.getNextTypeLoc(); next_loc) {
    this->TypeLocVisitor::Visit(next_loc);
  }
})

TYPELOC_VISITOR(BuiltinTypeLoc, {
  AssignContext(loc.getBuiltinLoc());
//
//  auto type = loc.getTypePtr();
//  auto &ast_context = top_level_decl->getASTContext();
//  const auto &lang_opts = ast_context.getLangOpts();
//  auto kind = rpc::TYPE_NAME;
//  switch (type->getKind()) {
//    case clang::BuiltinType::Bool:
//      if (lang_opts.Bool) {
//        kind = rpc::TYPE_NAME_BOOL_CXX;
//      } else {
//        kind = rpc::TYPE_NAME_BOOL;
//      }
//      break;
//
//    case clang::BuiltinType::WChar_U:
//      kind = rpc::TYPE_NAME_CHAR_WIDE;
//      break;
//
//    case clang::BuiltinType::Char8:
//      kind = rpc::TYPE_NAME_CHAR_UTF8;
//      break;
//
//    case clang::BuiltinType::Char16:
//      kind = rpc::TYPE_NAME_CHAR_UTF16;
//      break;
//
//    case clang::BuiltinType::Char32:
//      kind = rpc::TYPE_NAME_CHAR_UTF32;
//      break;
//
//    // Normalize these to be based on what the actual type/size ends up being,
//    // and present them in a way that's consistent with stdint.h.
//    case clang::BuiltinType::Char_U:
//    case clang::BuiltinType::UChar:
//    case clang::BuiltinType::UShort:
//    case clang::BuiltinType::UInt:
//    case clang::BuiltinType::ULong:
//    case clang::BuiltinType::ULongLong:
//    case clang::BuiltinType::UInt128: {
//      switch (ast_context.getTypeInfo(type).Width) {
//        case 8:
//          kind = rpc::TYPE_NAME_INT8_UNSIGNED;
//          break;
//        case 16:
//          kind = rpc::TYPE_NAME_INT16_UNSIGNED;
//          break;
//        case 32:
//          kind = rpc::TYPE_NAME_INT32_UNSIGNED;
//          break;
//        case 64:
//          kind = rpc::TYPE_NAME_INT64_UNSIGNED;
//          break;
//        case 128:
//          kind = rpc::TYPE_NAME_INT128_UNSIGNED;
//          break;
//        default:
//          break;
//      }
//      break;
//    }
//
//    // Normalize these to be based on what the actual type/size ends up being,
//    // and present them in a way that's consistent with stdint.h.
//    case clang::BuiltinType::Char_S:
//    case clang::BuiltinType::SChar:
//    case clang::BuiltinType::Short:
//    case clang::BuiltinType::Int:
//    case clang::BuiltinType::Long:
//    case clang::BuiltinType::LongLong:
//    case clang::BuiltinType::Int128: {
//      switch (ast_context.getTypeInfo(type).Width) {
//        case 8:
//          kind = rpc::TYPE_NAME_INT8;
//          break;
//        case 16:
//          kind = rpc::TYPE_NAME_INT16;
//          break;
//        case 32:
//          kind = rpc::TYPE_NAME_INT32;
//          break;
//        case 64:
//          kind = rpc::TYPE_NAME_INT64;
//          break;
//        case 128:
//          kind = rpc::TYPE_NAME_INT128;
//          break;
//        default:
//          break;
//      }
//      break;
//    }
//
//    case clang::BuiltinType::Float:
//    case clang::BuiltinType::Double:
//    case clang::BuiltinType::LongDouble:
//    case clang::BuiltinType::Float16:
//    case clang::BuiltinType::Float128: {
//      switch (ast_context.getTypeInfo(type).Width) {
//        case 16:
//          kind = rpc::TYPE_NAME_FLOAT16;
//          break;
//        case 32:
//          kind = rpc::TYPE_NAME_FLOAT32;
//          break;
//        case 64:
//          kind = rpc::TYPE_NAME_FLOAT64;
//          break;
//        case 80:
//          kind = rpc::TYPE_NAME_FLOAT80;
//          break;
//        case 128:
//          kind = rpc::TYPE_NAME_FLOAT128;
//          break;
//        default:
//          break;
//      }
//      break;
//    }
//
//    case clang::BuiltinType::NullPtr: {
//      kind = rpc::TYPE_NAME_NULLPTR_CXX;
//      break;
//    }
//
//    default:
//      break;
//  }
//
//  auto name_loc = loc.getBuiltinLoc();
//  token_forest.MapToken(name_loc, rpc::IDENTIFIER_NAME, kind,
//                        rpc::TYPE_NAME, kind);
//
//  token_forest.MapRange(loc.getLocalSourceRange());
//  token_forest.MapRange(loc.getSourceRange());
//
//  MultiplierTokenData data = {};
//  if ((token_manager.TryGetFullMultiplierData(
//           loc.getLocalSourceRange().getBegin(), &data) ||
//       token_manager.TryGetFullMultiplierData(
//           loc.getLocalSourceRange().getBegin(), &data)) &&
//      (loc.hasWrittenTypeSpec() || loc.hasWrittenSignSpec() ||
//       loc.hasWrittenWidthSpec())) {
//    auto &tokens = data.token_list->tokens;
//    auto max_i = std::min<uint64_t>(data.token_index + 8, tokens.size());
//    for (auto i = data.token_index; i < max_i; ++i) {
//      const auto tok_loc = tokens[i].getLocation();
//      auto spec_kind = token_manager.ClassifyLocation(tok_loc);
//      auto new_spec_kind = spec_kind;
//      switch (spec_kind) {
//        case rpc::RESERVED_KEYWORD_ATOMIC:
//          new_spec_kind = rpc::TYPE_SPECIFIER_ATOMIC;
//          break;
//        case rpc::RESERVED_KEYWORD_SHORT:
//          new_spec_kind = rpc::TYPE_SPECIFIER_SHORT;
//          break;
//        case rpc::RESERVED_KEYWORD_LONG:
//          new_spec_kind = rpc::TYPE_SPECIFIER_LONG;
//          break;
//        case rpc::RESERVED_KEYWORD_SIGNED:
//          new_spec_kind = rpc::TYPE_SPECIFIER_SIGNED;
//          break;
//        case rpc::RESERVED_KEYWORD_UNSIGNED:
//          new_spec_kind = rpc::TYPE_SPECIFIER_UNSIGNED;
//          break;
//        case rpc::RESERVED_KEYWORD_STRUCT:
//          new_spec_kind = rpc::TYPE_SPECIFIER_STRUCT;
//          break;
//        case rpc::RESERVED_KEYWORD_UNION:
//          new_spec_kind = rpc::TYPE_SPECIFIER_UNION;
//          break;
//        case rpc::RESERVED_KEYWORD_ENUM:
//          new_spec_kind = rpc::TYPE_SPECIFIER_ENUM;
//          break;
//        case rpc::RESERVED_KEYWORD_CLASS:
//          new_spec_kind = rpc::TYPE_SPECIFIER_CLASS_CXX;
//          break;
//        case rpc::RESERVED_KEYWORD_INTERFACE:
//          new_spec_kind = rpc::TYPE_SPECIFIER_STRUCT;
//          break;
//        default:
//          break;
//      }
//
//      if (spec_kind != new_spec_kind) {
//        token_forest.MapToken(tok_loc, spec_kind, new_spec_kind);
//      }
//    }
//  }
})

// Visit the typedef type location nodes and update the identifier token
// id's.
TYPELOC_VISITOR(TypedefTypeLoc, {
  if (auto name_tok = ast.RawTokenAt(loc.getNameLoc());
      name_tok && name_tok->kind == clang::tok::identifier) {
    if (auto decl = TypeToDecl(loc.getTypePtr())) {
      EnterExitEntity entity_tracker(entity_stack, decl);
      AssignContext(name_tok);
    } else {
      AssignContext(name_tok);
    }
  }
})

TYPELOC_VISITOR(AdjustedTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getOriginalLoc());
})

TYPELOC_VISITOR(MacroQualifiedTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getInnerLoc());
})

TYPELOC_VISITOR(DecayedTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getOriginalLoc());
})

TYPELOC_VISITOR(ElaboratedTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getNamedTypeLoc());
})

TYPELOC_VISITOR(AttributedTypeLoc, {
  this->TypeLocVisitor::Visit(loc.getModifiedLoc());
//
//  clang::SourceLocation open_loc;
//  clang::SourceLocation close_loc;
//
//  auto ident_ptr = TryGetTokenIdRef(loc.getAttrNameLoc());
//  if (ident_ptr) {
//    CompareAndSwapTokenKind(ident_ptr, rpc::IDENTIFIER_NAME,
//                            rpc::IDENTIFIER_NAME_ATTR);
//
//    // Try to find the `((` or the `[[` tokens, and assign them.
//    auto parsed_tok = tokenizer.ParsedTokenAt(loc.getAttrNameLoc());
//    if (parsed_tok.IsValid() && parsed_tok.UnsafeUpdateToPrevious()) {
//      if (parsed_tok.BasicTokenKind() == rpc::PUNC_LPAREN) {
//        open_loc = parsed_tok->getLocation();
//        close_loc = tokenizer.ClosingLocationFor(open_loc);
//        if (TryAssignBalancedTypes(open_loc, close_loc,
//                                   rpc::PUNC_LPAREN_ATTR_INNER_GNUC,
//                                   rpc::PUNC_RPAREN_ATTR_INNER_GNUC)) {
//          parsed_tok.UnsafeUpdateToPrevious();
//          open_loc = parsed_tok->getLocation();
//          close_loc = tokenizer.ClosingLocationFor(open_loc);
//          TryAssignBalancedTypes(
//              open_loc, close_loc,rpc::PUNC_LPAREN_ATTR_OUTER_GNUC,
//              rpc::PUNC_RPAREN_ATTR_OUTER_GNUC);
//        }
//      } else if (parsed_tok.BasicTokenKind() == rpc::PUNC_LSQUARE) {
//        open_loc = parsed_tok->getLocation();
//        close_loc = tokenizer.ClosingLocationFor(open_loc);
//        if (TryAssignBalancedTypes(open_loc, close_loc,
//                                   rpc::PUNC_LSQUARE_ATTR_INNER_CXX,
//                                   rpc::PUNC_RSQUARE_ATTR_INNER_CXX)) {
//          parsed_tok.UnsafeUpdateToPrevious();
//          open_loc = parsed_tok->getLocation();
//          close_loc = tokenizer.ClosingLocationFor(open_loc);
//          TryAssignBalancedTypes(
//              open_loc, close_loc,rpc::PUNC_LSQUARE_ATTR_OUTER_CXX,
//              rpc::PUNC_RSQUARE_ATTR_OUTER_CXX);
//        }
//      }
//    }
//  }
//
//  if (loc.hasAttrOperand()) {
//    open_loc = loc.getAttrOperandParensRange().getBegin();
//    close_loc = loc.getAttrOperandParensRange().getEnd();
//    if (tokenizer.FixupMatchingBalancedLocations(open_loc, close_loc)) {
//      TryAssignBalancedTypes(open_loc, close_loc,
//                             rpc::PUNC_LPAREN_ATTR_LIST_ARG,
//                             rpc::PUNC_RPAREN_ATTR_LIST_ARG);
//    }
//  }
//
//  if (loc.hasAttrEnumOperand()) {
//    ident_ptr = TryGetTokenIdRef(loc.getAttrEnumOperandLoc());
//    CheckedCompareAndSwapTokenKind(ident_ptr, rpc::IDENTIFIER_NAME,
//                                   rpc::IDENTIFIER_NAME_ATTR);
//  }
//
//  if (loc.hasAttrExprOperand()) {
//    if (auto expr = loc.getAttrExprOperand()) {
//      this->StmtVisitor::Visit(expr);
//    }
//  }
})

TYPELOC_VISITOR(BlockPointerTypeLoc, {
  AssignContext(loc.getCaretLoc());
})

// Refine the assignment of token contexts using a top-down AST visitor pass.
void ASTImpl::RefineTokens(void) {
  TokenContextAssigner assigner(*this);
  assigner.VisitTranslationUnitDecl(tu);
}

}  // namespace pasta
