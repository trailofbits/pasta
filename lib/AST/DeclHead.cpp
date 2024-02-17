/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 */

#include <pasta/AST/DeclHead.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/Attr.h>
#include <clang/AST/RecordLayout.h>
#pragma clang diagnostic pop

#include "AST.h"
#include "Builder.h"

namespace pasta {

#ifndef PASTA_IN_BOOTSTRAP

namespace {

static ::pasta::DeclCategory ClassifyDecl(const clang::Decl *decl) {
  if (!decl) {
    return ::pasta::DeclCategory::kUnknown;
  }

  if (clang::isa<clang::NamespaceDecl>(decl) ||
      clang::isa<clang::NamespaceAliasDecl>(decl) ||
      clang::isa<clang::UsingDirectiveDecl>(decl)) {
    return ::pasta::DeclCategory::kNamespace;
  }

  if (clang::isa<clang::ConceptDecl>(decl)) {
    return ::pasta::DeclCategory::kConcept;

  }

  if (auto tpl_decl = clang::dyn_cast<clang::TemplateDecl>(decl)) {
    if (clang::isa<clang::TemplateTemplateParmDecl>(decl)) {
      return ::pasta::DeclCategory::kTemplateTypeParameter;
    }
    return ClassifyDecl(tpl_decl->getTemplatedDecl());
  }

  if (clang::isa<clang::TypeDecl>(decl)) {
    if (clang::isa<clang::TagDecl>(decl)) {
      if (clang::isa<clang::EnumDecl>(decl)) {
        return ::pasta::DeclCategory::kEnumeration;
      }

      if (auto record_decl = clang::dyn_cast<clang::RecordDecl>(decl)) {
        switch (record_decl->getTagKind()) {
          case clang::TTK_Struct:
            return ::pasta::DeclCategory::kStructure;
          case clang::TTK_Interface:
            return ::pasta::DeclCategory::kInterface;
          case clang::TTK_Union:
            return ::pasta::DeclCategory::kUnion;
          case clang::TTK_Class:
            return ::pasta::DeclCategory::kClass;
          case clang::TTK_Enum:
            return ::pasta::DeclCategory::kEnumeration;
        }
      }
      assert(false);
      return ::pasta::DeclCategory::kStructure;
    }

    if (clang::isa<clang::TemplateTypeParmDecl>(decl)) {
      return ::pasta::DeclCategory::kTemplateTypeParameter;
    }

    if (clang::isa<clang::TypedefNameDecl>(decl)) {
      return ::pasta::DeclCategory::kTypeAlias;
    }

    if (clang::isa<clang::UnresolvedUsingTypenameDecl>(decl)) {
      return ::pasta::DeclCategory::kTypeAlias;
    }

    assert(false);
    return ::pasta::DeclCategory::kTypeAlias;

  }

  if (auto method_decl_objc = clang::dyn_cast<clang::ObjCMethodDecl>(decl)) {
    if (method_decl_objc->isInstanceMethod()) {
      return ::pasta::DeclCategory::kInstanceMethod;
    }  
    return ::pasta::DeclCategory::kClassMethod;
  }

  if (clang::isa<clang::LabelDecl>(decl)) {
    return ::pasta::DeclCategory::kLabel;
  }

  if (auto using_decl = clang::dyn_cast<clang::UsingDecl>(decl)) {
    auto ret = ::pasta::DeclCategory::kUnknown;
    for (auto shadow : using_decl->shadows()) {
      if (auto used_decl = shadow->getTargetDecl()) {
        if (used_decl != using_decl) {
          ret = ClassifyDecl(used_decl);
          if (ret != ::pasta::DeclCategory::kUnknown) {
            return ret;
          }
        }
      }
    }
    return ::pasta::DeclCategory::kUnknown;
  }

  if (auto using_pack = clang::dyn_cast<clang::UsingPackDecl>(decl)) {
    for (auto used_decl : using_pack->expansions()) {
      return ClassifyDecl(used_decl);
    }
    return ::pasta::DeclCategory::kUnknown;
  }

  if (auto using_shadow = clang::dyn_cast<clang::UsingShadowDecl>(decl)) {
    if (auto used_decl = using_shadow->getTargetDecl()) {
      if (used_decl != decl) {
        return ClassifyDecl(used_decl);
      }
    }
    return ::pasta::DeclCategory::kUnknown;
  }

  if (clang::isa<clang::ValueDecl>(decl)) {
    if (clang::isa<clang::BindingDecl>(decl)) {
      return ::pasta::DeclCategory::kLocalVariable;
    }

    if (clang::isa<clang::EnumConstantDecl>(decl)) {
      return ::pasta::DeclCategory::kEnumerator;
    }

    if (clang::isa<clang::IndirectFieldDecl>(decl)) {
      return ::pasta::DeclCategory::kInstanceMember;
    }

    if (clang::isa<clang::FieldDecl>(decl)) {
      return ::pasta::DeclCategory::kInstanceMember;
    }

    if (clang::isa<clang::FunctionDecl>(decl)) {
      if (auto method_decl_cxx = clang::dyn_cast<clang::CXXMethodDecl>(decl)) {
        if (method_decl_cxx->isInstance()) {
          return ::pasta::DeclCategory::kInstanceMethod;
        }
        return ::pasta::DeclCategory::kClassMethod;
      }
      return ::pasta::DeclCategory::kFunction;
    }

    if (auto var_decl = clang::dyn_cast<clang::VarDecl>(decl)) {
      if (clang::isa<clang::ParmVarDecl>(decl)) {
        return ::pasta::DeclCategory::kParameterVariable;
      }

      if (auto iparam = clang::dyn_cast<clang::ImplicitParamDecl>(decl)) {
        switch (iparam->getParameterKind()) {
          case clang::ImplicitParamDecl::ObjCSelf:
          case clang::ImplicitParamDecl::CXXThis:
            return ::pasta::DeclCategory::kThis;
          default:
            return ::pasta::DeclCategory::kParameterVariable;
        }
      }

      if (var_decl->isLocalVarDecl()) {
        if (var_decl->hasGlobalStorage()) {
          return ::pasta::DeclCategory::kGlobalVariable;
        }
        return ::pasta::DeclCategory::kLocalVariable;
      }

      auto dc = var_decl->getDeclContext();
      if (dc->isFileContext() || dc->isExternCContext() ||
          dc->isNamespace() || dc->isExternCXXContext()) {
        return ::pasta::DeclCategory::kGlobalVariable;
      }

      if (dc->isRecord()) {
        return ::pasta::DeclCategory::kClassMember;
      }
      return ::pasta::DeclCategory::kUnknown;

    }

    if (clang::isa<clang::NonTypeTemplateParmDecl>(decl)) {
      return ::pasta::DeclCategory::kTemplateValueParameter;
    }

    if (clang::isa<clang::TemplateTypeParmDecl>(decl)) {
      return ::pasta::DeclCategory::kTemplateTypeParameter;
    }

    if (clang::isa<clang::TemplateTemplateParmDecl>(decl)) {
      return ::pasta::DeclCategory::kTemplateTypeParameter;
    }
  }

  return ::pasta::DeclCategory::kUnknown;
}

static bool IsImplicitImpl(clang::Decl *decl) {
  if (decl->isImplicit()) {
    return true;
  }

  auto dc_decl = clang::dyn_cast_or_null<clang::Decl>(
      decl->getLexicalDeclContext());
  if (!dc_decl || dc_decl == decl ||
      llvm::isa<clang::TranslationUnitDecl>(dc_decl)) {
    return false;
  }

  return IsImplicitImpl(dc_decl);
}

// CXXRecord layout is only valid if the definition is complete and it is
// not templated. If either case is true return null.
static const clang::ASTRecordLayout *GetRecordLayout(const clang::RecordDecl *decl) {
  auto def = decl->getDefinition();
  if (def && !def->isInvalidDecl() && def->isCompleteDefinition()
      && !def->isTemplated()) {
    return &(def->getASTContext().getASTRecordLayout(def));
  }
  return nullptr;
}

}  // namespace

std::optional<::pasta::Decl> Decl::From(const DeclContext &dc) {
  auto decl = clang::Decl::castFromDeclContext(dc.u.DeclContext);
  if (!decl) {
    return std::nullopt;
  }

  return DeclBuilder::Create<pasta::Decl>(dc.ast, decl);
}

::pasta::DeclCategory Decl::Category(void) const noexcept {
  return ClassifyDecl(u.Decl);
}

// Manually implemented to handle things like field declarations inside of
// implicitly-defined record declarations.
bool Decl::IsImplicit(void) const {
  return IsImplicitImpl(const_cast<clang::Decl *>(u.Decl));
}

// Range of the tokens for the specific.
::pasta::TokenRange CXXBaseSpecifier::Tokens(void) const noexcept {
  return ast->TokenRangeFrom(spec->getSourceRange());
}

// Token of the the base type name. Doesn't include the qualifiers.
::pasta::Token CXXBaseSpecifier::BaseTypeToken(void) const noexcept {
  return ast->TokenAt(spec->getBaseTypeLoc());
}

// Is this a virtual base (using virtual inheritance)?
bool CXXBaseSpecifier::IsVirtual(void) const noexcept {
  return spec->isVirtual();
}

// Kind of the base type. This is either `TagTypeKind::kStruct` or
// `TagTypeKind::kClass`.
TagTypeKind CXXBaseSpecifier::BaseKind(void) const noexcept {
  if (spec->isBaseOfClass()) {
    return TagTypeKind::kClass;
  }
  return TagTypeKind::kStruct;
}

// Is this specifier a pack expansion?
bool CXXBaseSpecifier::IsPackExpansion(void) const noexcept {
  return spec->isPackExpansion();
}

// Returns `true` if the constructors from the base class are explicitly
// inherited in the derived class with a `using` declaration.
bool CXXBaseSpecifier::ConstructorsAreInherited(void) const noexcept {
  return spec->getInheritConstructors();
}

// For a pack expansion, determine the location of the ellipsis.
std::optional<Token> CXXBaseSpecifier::EllipsisToken(void) const noexcept {
  if (auto tok = ast->TokenAt(spec->getEllipsisLoc())) {
    return tok;
  }
  return std::nullopt;
}

// Returns the access specifier for this base specifier.
//
// This is the actual base specifier as used for semantic analysis, so
// the result can never be `AccessSpecifier::kNone`. To retrieve the access
// specifier as written in the source code, use `LexicalAccessSpecifier`.
::pasta::AccessSpecifier
CXXBaseSpecifier::SemanticAccessSpecifier(void) const noexcept {
  return static_cast<::pasta::AccessSpecifier>(spec->getAccessSpecifier());
}

// Retrieves the access specifier as written in the source code
// (which may mean that no access specifier was explicitly written).
//
// Use `SemanticAccessSpecifier` to retrieve the access specifier for use in
// semantic analysis.
::pasta::AccessSpecifier
CXXBaseSpecifier::LexicalAccessSpecifier(void) const noexcept {
  return static_cast<::pasta::AccessSpecifier>(
      spec->getAccessSpecifierAsWritten());
}

// Retrieves the type of the base class.
//
// This type will always be an unqualified class type.
::pasta::Type CXXBaseSpecifier::BaseType(void) const noexcept {

  // NOTE(pag): `spec->getType()` can sometimes crash when computing the
  //            unqualified base type.
  auto tsi = spec->getTypeSourceInfo();
  return TypeBuilder::Build(ast, tsi->getType()).UnqualifiedType();
}

// Return the kind of the stored template argument.
TemplateArgumentKind TemplateArgument::Kind(void) const noexcept {
  return static_cast<TemplateArgumentKind>(arg->getKind());
}

// Whether this template argument is dependent on a template
// parameter such that its result can change from one instantiation to
// another.
bool TemplateArgument::IsDependent(void) const noexcept {
  return arg->isDependent();
}

// Whether this template argument is dependent on a template parameter.
bool TemplateArgument::IsInstantiationDependent(void) const noexcept {
  return arg->isInstantiationDependent();
}

// Whether this template argument contains an unexpanded parameter pack.
bool TemplateArgument::ContainsUnexpandedParameterPack(void) const noexcept {
  return arg->containsUnexpandedParameterPack();
}

// Determine whether this template argument is a pack expansion.
bool TemplateArgument::IsPackExpansion(void) const noexcept {
  return arg->isPackExpansion();
}

// Retrieve the declaration for a declaration non-type template argument.
std::optional<ValueDecl> TemplateArgument::AsDeclaration(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kDeclaration) {
    return DeclBuilder::Create<pasta::ValueDecl>(ast, arg->getAsDecl());
  }
  return std::nullopt;
}

// Retrieve the type for a type template argument.
std::optional<Type> TemplateArgument::AsType(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kType) {
    return TypeBuilder::Build(ast, arg->getAsType());
  }
  return std::nullopt;
}

std::optional<Type>
TemplateArgument::ParameterTypeForDeclaration(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kDeclaration) {
    return TypeBuilder::Build(ast, arg->getParamTypeForDecl());
  }
  return std::nullopt;
}

std::optional<Type> TemplateArgument::NullPointerType(void) const noexcept {
  if (Kind() == TemplateArgumentKind::kNullPointer) {
    return TypeBuilder::Build(ast, arg->getNullPtrType());
  }
  return std::nullopt;
}

// If this argument is an argument pack, then return the inner arguments.
std::optional<std::vector<TemplateArgument>>
TemplateArgument::PackElements(void) const noexcept {
  if (Kind() != TemplateArgumentKind::kPack) {
    return std::nullopt;
  }

  std::vector<TemplateArgument> nested_args;
  for (const auto &nested_arg : arg->pack_elements()) {
    nested_args.emplace_back(ast, &nested_arg); 
  }

  return nested_args;
}

// Total number of parameters.
unsigned TemplateParameterList::NumParameters(void) const noexcept {
  return params->size();
}

// Minimum number of required parameters needed to be explicitly specified
// by arguments when specializing this template.
unsigned TemplateParameterList::NumRequiredParameters(void) const noexcept {
  return params->getMinRequiredArguments();
}

// Get the depth of this template parameter list in the set of
// template parameter lists.
//
// The first template parameter list in a declaration will have depth `0`,
// the second template parameter list will have depth `1`, etc.
unsigned TemplateParameterList::Depth(void) const noexcept {
  return params->getDepth();
}

// Returns `true` if this parameter list contains an unexpanded template
// parameter pack.
bool TemplateParameterList::HasUnexpandedParameterPack(void) const noexcept {
  return params->containsUnexpandedParameterPack();
}

// Returns `true` if this parameter list contains a parameter pack.
bool TemplateParameterList::HasParameterPack(void) const noexcept {
  return params->hasParameterPack();
}

// The constraint-expression of the associated requires-clause.
std::optional<::pasta::Expr>
TemplateParameterList::RequiresClause(void) const noexcept {
  if (auto expr = params->getRequiresClause()) {
    return StmtBuilder::Create<::pasta::Expr>(ast, expr);
  }
  return std::nullopt;
}

::pasta::Token TemplateParameterList::TemplateKeywordToken(void) const noexcept {
  return ast->TokenAt(params->getTemplateLoc());
}

::pasta::Token TemplateParameterList::LeftAngleToken(void) const noexcept {
  return ast->TokenAt(params->getLAngleLoc());
}

::pasta::Token TemplateParameterList::RightAngleToken(void) const noexcept {
  return ast->TokenAt(params->getRAngleLoc());
}

::pasta::TokenRange TemplateParameterList::Tokens(void) const noexcept {
  return ast->TokenRangeFrom(params->getSourceRange());
}

std::vector<::pasta::NamedDecl>
TemplateParameterList::Parameters(void) const noexcept {
  std::vector<::pasta::NamedDecl> ret;
  for (clang::NamedDecl *param : *params) {
    ret.emplace_back(DeclBuilder::Create<pasta::NamedDecl>(ast, param));
  }
  return ret;
}

std::optional<uint64_t> RecordDecl::Size(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->getSize().getQuantity();
  }
  return std::nullopt;
}

std::optional<uint64_t> RecordDecl::Alignment(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->getAlignment().getQuantity();
  }
  return std::nullopt;
}

std::optional<uint64_t> RecordDecl::SizeWithoutTrailingPadding(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->getDataSize().getQuantity();
  }
  return std::nullopt;
}

std::optional<uint64_t> CXXRecordDecl::SizeWithoutVirtualBases(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->getNonVirtualSize().getQuantity();
  }
  return std::nullopt;
}

std::optional<CXXRecordDecl> CXXRecordDecl::PrimaryBase(void) const noexcept {
  auto layout = GetRecordLayout(u.RecordDecl);
  if (!layout) {
    return std::nullopt;
  }

  const clang::CXXRecordDecl *base = layout->getPrimaryBase();
  if (!base) {
    return std::nullopt;
  }

  return DeclBuilder::Create<pasta::CXXRecordDecl>(ast, base);
}

std::optional<bool> CXXRecordDecl::HasOwnVirtualFunctionTablePointer(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->hasOwnVFPtr();
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::HasExtendableVirtualFunctionTablePointer(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->hasExtendableVFPtr();
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::HasVirtualBaseTablePointer(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->hasVBPtr();
  }
  return std::nullopt;
}

std::optional<bool> CXXRecordDecl::HasOwnVirtualBaseTablePointer(void) const noexcept {
  if (auto layout = GetRecordLayout(u.RecordDecl)) {
    return layout->hasOwnVBPtr();
  }
  return std::nullopt;
}

std::optional<uint64_t> FieldDecl::OffsetInBits(void) const noexcept {
  if (auto layout = GetRecordLayout(u.FieldDecl->getParent())) {
    return layout->getFieldOffset(u.FieldDecl->getFieldIndex());
  }
  return std::nullopt;
}

// Clang deduplicates function types, and stores the ellipsis in those types.
// that results in the wrong ellipsis location. `ASTImpl::DeclBounds` will run
// the `DeclBoundsFinder` on the function, and try to discover key locations
// in the "prorotype" of the function, updating `ASTImpl::func_proto`. Then,
// we can try to find the true ellipsis token.
::pasta::Token FunctionDecl::EllipsisToken(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  if (self.getEllipsisLoc().isValid()) {
    auto [begin_tok, end_tok] = ast->DeclBounds(&self);
    if (auto it = ast->func_proto.find(&self); it != ast->func_proto.end()) {
      if (!it->second.ellipsis) {
        return ::pasta::Token(ast);
      }
      assert(begin_tok < it->second.ellipsis);
      assert(it->second.ellipsis < end_tok);
      (void) begin_tok;
      return ast->TokenAt(it->second.ellipsis);
    }
  }
  return ::pasta::Token(ast);
}

::pasta::TokenRange FunctionDecl::ParametersTokens(void) const {
  auto &self = *const_cast<clang::FunctionDecl *>(u.FunctionDecl);
  (void) ast->DeclBounds(&self);
  if (auto it = ast->func_proto.find(&self); it != ast->func_proto.end()) {
    ASTImpl::FunctionProto &proto = it->second;
    if (proto.l_paren < proto.r_paren) {
      return ::pasta::TokenRange(ast, proto.l_paren, proto.r_paren);
    }
  }
  return ::pasta::TokenRange(ast);
}

std::vector<::pasta::EnumConstantDecl> EnumDecl::Enumerators(void) const {
  auto &self = *const_cast<clang::EnumDecl *>(u.EnumDecl);
  std::vector<::pasta::EnumConstantDecl> ret;
  if (auto def = self.getDefinition(); !def || &self != def) {
    return ret;
  }

  decltype(auto) val = self.enumerators();
  for (auto decl_ptr : val) {
    if (decl_ptr) {
      ret.emplace_back(DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, decl_ptr));
    }
  }
  return ret;
}

std::vector<::pasta::CXXCtorInitializer> CXXConstructorDecl::Initializers(void) const {
  auto &self = *const_cast<clang::CXXConstructorDecl *>(u.CXXConstructorDecl);
  std::vector<::pasta::CXXCtorInitializer> ret;
  decltype(auto) val = self.inits();
  for (auto init : val) {
    ret.emplace_back(::pasta::CXXCtorInitializer(ast, init));
  }
  return ret;
}

  bool CXXCtorInitializer::IsBaseInitializer(void) const noexcept {
    return initializer->isBaseInitializer();
  }

  bool CXXCtorInitializer::IsMemberInitializer(void) const noexcept {
    return initializer->isMemberInitializer();
  }

  bool CXXCtorInitializer::IsAnyMemberInitializer(void) const noexcept {
    return initializer->isAnyMemberInitializer();
  }

  bool CXXCtorInitializer::IsIndirectMemberInitializer(void) const noexcept {
    return initializer->isIndirectMemberInitializer();
  }

  bool CXXCtorInitializer::IsInClassMemberInitializer(void) const noexcept {
    return initializer->isInClassMemberInitializer();
  }

  bool CXXCtorInitializer::IsDelegatingInitializer(void) const noexcept {
    return initializer->isDelegatingInitializer();
  }

  bool CXXCtorInitializer::IsPackExpansion(void) const noexcept {
    return initializer->isPackExpansion();
  }

  bool CXXCtorInitializer::IsBaseVirtual(void) const noexcept {
    return initializer->isBaseVirtual();
  }

  std::optional<::pasta::FieldDecl> CXXCtorInitializer::Member(void) const noexcept {
    if (auto mem_decl = initializer->getMember()) {
      return DeclBuilder::Create<::pasta::FieldDecl>(ast, mem_decl);
    }
    return std::nullopt;
  }

  std::optional<::pasta::FieldDecl>
  CXXCtorInitializer::AnyMember(void) const noexcept {
    if (auto mem_decl = initializer->getAnyMember()) {
      return DeclBuilder::Create<::pasta::FieldDecl>(ast, mem_decl);
    }
    return std::nullopt;
  }

  std::optional<::pasta::IndirectFieldDecl>
  CXXCtorInitializer::IndirectMember(void) const noexcept {
    if (auto mem_decl = initializer->getIndirectMember()) {
      return DeclBuilder::Create<::pasta::IndirectFieldDecl>(ast, mem_decl);
    }
    return std::nullopt;
  }

  std::optional<::pasta::Stmt> CXXCtorInitializer::Initializer() const noexcept {
    if (auto expr = initializer->getInit()) {
      return StmtBuilder::Create<::pasta::Expr>(ast, expr);
    }
    return std::nullopt;
  }

  ::pasta::Token CXXCtorInitializer::EllipsisToken(void) const noexcept {
    return ast->TokenAt(initializer->getEllipsisLoc());
  }

  ::pasta::Token CXXCtorInitializer::MemberToken(void) const noexcept {
    return ast->TokenAt(initializer->getMemberLocation());
  }

  ::pasta::Token CXXCtorInitializer::LeftAngleToken(void) const noexcept {
    return ast->TokenAt(initializer->getLParenLoc());
  }

  ::pasta::Token CXXCtorInitializer::RightAngleToken(void) const noexcept {
    return ast->TokenAt(initializer->getRParenLoc());
  }
  ::pasta::TokenRange CXXCtorInitializer::Tokens(void) const noexcept {
    return ast->TokenRangeFrom(initializer->getSourceRange());
  }

  std::vector<::pasta::CXXCtorInitializer> ObjCImplementationDecl::Initializers(void) const {
    auto &self = *const_cast<clang::ObjCImplementationDecl *>(u.ObjCImplementationDecl);
    std::vector<::pasta::CXXCtorInitializer> ret;
    decltype(auto) val = self.inits();
    for (auto init : val) {
      ret.emplace_back(::pasta::CXXCtorInitializer(ast, init));
    }
    return ret;
  }

  std::vector<::pasta::NamedDecl> CXXRecordDecl::VisibleConversionFunctions(void) const {
    auto &self = *const_cast<clang::CXXRecordDecl *>(u.CXXRecordDecl);
    if (!self.hasDefinition()) {
      return {};
    }
    decltype(auto) conversion_functions = self.getVisibleConversionFunctions();
    std::vector<::pasta::NamedDecl> ret;
    for (auto cf : conversion_functions) {
      ret.emplace_back(::pasta::NamedDecl(ast, cf));
    }
    return ret;
  }

#endif  // PASTA_IN_BOOTSTRAP

}  // namespace pasta
