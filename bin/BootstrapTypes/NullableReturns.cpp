/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include "Globals.h"

// Methods that may return `nullptr`. `kCanReturnNullptr` is unconditional;
// `kConditionalNullptr` carries a guard expression that is emitted before
// the wrapped call so the wrapper returns `std::nullopt` when the guard
// fails.
// Set of ClassName::MethodName pairs such that the class can return a nullptr,
// and thus `std::optional` probably needs to be used.
std::set<std::pair<std::string, std::string>> kCanReturnNullptr{
  {"AttributedType", "Attribute"},
  {"LoopHintAttr", "Value"},
  {"FunctionDecl", "InstantiatedFromDeclaration"},
  {"DeclContext", "Parent"},
  {"DeclContext", "LexicalParent"},
  {"DeclContext", "LookupParent"},
  {"DeclContext", "InnermostBlockDeclaration"},
  {"DeclContext", "ExternCContext"},
  {"DeclContext", "NonClosureAncestor"},
  {"DeclContext", "EnclosingNamespaceContext"},
  {"DeclContext", "OuterLexicalRecordContext"},
  {"FunctionDecl", "DescribedFunctionTemplate"},
  {"FunctionDecl", "MemberSpecializationInfo"},
  {"FunctionDecl", "InstantiatedFromMemberFunction"},
  {"FunctionDecl", "TemplateInstantiationPattern"},
  {"FunctionDecl", "PrimaryTemplate"},
  {"FunctionDecl", "TemplateSpecializationInfo"},
  {"FunctionDecl", "TemplateSpecializationArguments"},
  {"FunctionDecl", "TemplateSpecializationArgumentsAsWritten"},
  {"TagDecl", "Definition"},
  {"EnumDecl", "TemplateInstantiationPattern"},
  {"EnumDecl", "InstantiatedFromMemberEnum"},
  {"RecordDecl", "FindFirstNamedDataMember"},
  {"TypedefNameDecl", "AnonymousDeclarationWithTypedefName"},
  {"Decl", "OwningModuleForLinkage"},
  {"VarDecl", "ActingDefinition"},
  {"VarDecl", "Definition"},
  {"VarDecl", "AnyInitializer"},
  {"VarDecl", "Initializer"},
  {"VarDecl", "InitializingDeclaration"},
  {"VarDecl", "EvaluatedStatement"},
  {"VarDecl", "evaluateValue"},
  {"VarDecl", "evaluateValueImpl"},
  {"VarDecl", "EvaluatedValue"},
  {"VarDecl", "TemplateInstantiationPattern"},
  {"VarDecl", "InstantiatedFromStaticDataMember"},
  {"VarDecl", "DescribedVariableTemplate"},
  {"VarDecl", "MemberSpecializationInfo"},
  {"ParmVarDecl", "DefaultArgument"},
  {"ParmVarDecl", "UninstantiatedDefaultArgument"},
  {"FunctionDecl", "Body"},
  {"FunctionDecl", "DependentSpecializationInfo"},
  {"TypeAliasDecl", "DescribedAliasTemplate"},
  {"ConstructorUsingShadowDecl", "NominatedBaseClassShadowDeclaration"},
  {"ConstructorUsingShadowDecl", "ConstructedBaseClassShadowDeclaration"},
  {"EnumConstantDecl", "InitializerExpression"},
  {"FieldDecl", "BitWidth"},
  {"FieldDecl", "InClassInitializer"},
  {"DeclStmt", "SingleDeclaration"},
  {"FunctionDecl", "TemplateInstantiationPattern"},  // TODO(pag): contains assert.
  {"Decl", "ParentFunctionOrMethod"},
  {"Decl", "AsFunction"},
  {"Decl", "DescribedTemplate"},
  {"Decl", "DescribedTemplateParams"},
  {"Decl", "DescribedTemplateParameters"},
  {"Type", "ContainedAutoType"},
  {"Type", "ContainedDeducedType"},
  {"Type", "PointeeCXXRecordDeclaration"},
  {"Type", "PointeeOrArrayElementType"},
  {"Type", "PointeeType"},
  {"Type", "RVVElementType"},
  {"Type", "SveElementType"},
  {"FunctionDecl", "Definition"},
  {"ReturnStmt", "NRVOCandidate"},
  {"Expr", "BestDynamicClassType"},
  {"TagDecl", "TypedefNameForAnonymousDeclaration"},
  {"Expr", "SourceBitField"},
  {"CastExpr", "ConversionFunction"},
  {"IfStmt", "ConditionVariable"},
  {"IfStmt", "ConditionVariableDeclarationStatement"},
  {"IfStmt", "Initializer"},
  {"IfStmt", "Else"},
  {"SwitchStmt", "ConditionVariable"},
  {"SwitchStmt", "ConditionVariableDeclarationStatement"},
  {"WhileStmt", "ConditionVariable"},
  {"WhileStmt", "ConditionVariableDeclarationStatement"},
  {"ForStmt", "Condition"},
  {"ForStmt", "ConditionVariable"},
  {"ForStmt", "ConditionVariableDeclarationStatement"},
  {"ForStmt", "Increment"},
  {"ForStmt", "Initializer"},
  {"InitListExpr", "InitializedFieldInUnion"},
  {"InitListExpr", "SemanticForm"},
  {"InitListExpr", "SyntacticForm"},
  {"IndirectFieldDecl", "VariableDeclaration"},
  {"CallExpr", "DirectCallee"},
  {"CXXRecordDecl", "IsLocalClass"},
  {"CXXRecordDecl", "TemplateInstantiationPattern"},
  {"CXXRecordDecl", "LambdaCallOperator"},
  {"CXXRecordDecl", "InstantiatedFromMemberClass"},
  {"CXXRecordDecl", "GenericLambdaTemplateParameterList"},
  {"CXXRecordDecl", "Destructor"},
  {"CXXRecordDecl", "DescribedClassTemplate"},
  {"CXXRecordDecl", "DependentLambdaCallOperator"},
  {"CXXRecordDecl", "Definition"},
  {"RecordDecl", "Definition"},
  {"LambdaExpr", "TrailingRequiresClause"},
  {"LambdaExpr", "TemplateParameterList"},
  {"LambdaExpr", "DependentCallOperator"},
  {"SwitchStmt", "FirstSwitchCase"},
  {"SwitchStmt", "Initializer"},
  {"SwitchCase", "NextSwitchCase"},
  {"Decl", "NextDeclarationInContext"},
  {"Decl", "PreviousDeclaration"},
  {"Decl", "NextDeclaration"},
  {"Decl", "NonClosureContext"},
  {"Expr", "ReferencedDeclarationOfCallee"},
  {"DeclaratorDecl", "TrailingRequiresClause"},
  {"CaseStmt", "RHS"},
  {"InitListExpr", "ArrayFiller"},
  {"UnaryExprOrTypeTraitExpr", "ArgumentExpression"},
  {"UnaryExprOrTypeTraitExpr", "ArgumentType"},
  {"ReturnStmt", "RetValue"},
  {"ReturnStmt", "ReturnValue"},
  {"ValueStmt", "ExpressionStatement"},
  {"CompoundStmt", "StatementExpressionResult"},
  {"CallExpr", "CalleeDeclaration"},
  {"CXXRecordDecl", "Bases"},
  {"CXXRecordDecl", "VirtualBases"},
  {"CXXRecordDecl", "Friends"},
  {"CXXRecordDecl", "MostRecentNonInjectedDeclaration"},
  {"MaterializeTemporaryExpr", "ExtendingDeclaration"},
  {"MaterializeTemporaryExpr", "LifetimeExtendedTemporaryDeclaration"},
  {"CXXDestructorDecl", "OperatorDelete"},
  {"CXXDestructorDecl", "OperatorDeleteThisArgument"},
  {"CXXTypeidExpr", "ExpressionOperand"},
  {"CXXTypeidExpr", "IsMostDerived"},
  {"UsingShadowDecl", "NextUsingShadowDeclaration"},
  {"FriendDecl", "FriendDeclaration"},
  {"CXXCatchStmt", "ExceptionDeclaration"},
  {"CXXMemberCallExpr", "MethodDeclaration"},
  {"CXXThrowExpr", "SubExpression"},
  {"CXXNewExpr", "ConstructExpression"},
  {"CXXNewExpr", "Initializer"},
  {"CXXDependentScopeMemberExpr", "FirstQualifierFoundInScope"},
  {"BlockDecl", "BlockManglingContextDeclaration"},
  {"IndirectGotoStmt", "ConstantTarget"},
  {"Decl", "FunctionType"},
  {"ObjCInterfaceDecl", "SuperClass"},
  {"ObjCInterfaceDecl", "SuperClassTInfo"},
  {"ObjCInterfaceDecl", "SuperClassTypeInfo"},
  {"ObjCInterfaceDecl", "SuperClassType"},
  {"Type", "ArrayElementTypeNoTypeQualified"},
  {"Type", "ArrayElementTypeWithoutQualifiers"},
  {"ObjCObjectType", "SuperClassType"},
  {"FunctionProtoType", "ExceptionSpecDeclaration"},
  {"FunctionProtoType", "ExceptionSpecTemplate"},
  {"FunctionProtoType", "NoexceptExpression"},
  {"ConstantArrayType", "SizeExpression"},
  {"TypeDecl", "TypeForDeclaration"},
  {"FieldDecl", "CapturedVLAType"},
  {"ElaboratedType", "OwnedTagDeclaration"},
  {"DeclaratorDecl", "TypeSourceInfo"},
  {"Decl", "PreviousDeclaration"},
  {"TypeAliasTemplateDecl", "PreviousDeclaration"},
  {"VarTemplateDecl", "PreviousDeclaration"},
  {"ClassTemplateDecl", "PreviousDeclaration"},
  {"FunctionTemplateDecl", "PreviousDeclaration"},
  {"CXXRecordDecl", "PreviousDeclaration"},
  {"EnumDecl", "PreviousDeclaration"},
  {"RecordDecl", "PreviousDeclaration"},
  {"RecordDecl", "FirstNamedDataMember"},
  {"Expr", "AsBuiltinConstantDeclarationReference"},
  {"CXXMethodDecl", "ThisObjectType"},
  {"CXXMethodDecl", "ThisType"},
  {"TemplateSpecializationType", "AliasedType"},
  {"DeducedType", "ResolvedType"},
  {"AutoType", "TypeConstraintConcept"},
  {"CXXRecordDecl", "HasInitializerMethod"},
  {"TemplateTypeParmDecl", "DefaultArgument"},
  {"FunctionProtoType", "CanThrow"},
  {"FunctionProtoType", "IsNothrow"},
  {"TemplateTypeParmDecl", "DefaultArgumentInfo"},
  {"TemplateTypeParmType", "Declaration"},
  {"Type", "StripObjCKindOfType"},
  {"NonTypeTemplateParmDecl", "PlaceholderTypeConstraint"},
  {"NonTypeTemplateParmDecl", "NumExpansionTypes"},
  {"CXXDependentScopeMemberExpr", "Base"},
  {"OverloadExpr", "NamingClass"},
  {"UnresolvedLookupExpr", "NamingClass"},
  {"ClassTemplateSpecializationDecl", "TypeAsWritten"},
  {"Expr", "Type"},
  {"FriendDecl", "FriendType"},
  {"CXXPseudoDestructorExpr", "ScopeType"},
  {"TypeAliasTemplateDecl", "InstantiatedFromMemberTemplate"},
  {"RedeclarableTemplateDecl", "InstantiatedFromMemberTemplate"},
  {"VarTemplateDecl", "InstantiatedFromMemberTemplate"},
  {"ClassTemplateDecl", "InstantiatedFromMemberTemplate"},
  {"FunctionTemplateDecl", "InstantiatedFromMemberTemplate"},
  {"ClassTemplatePartialSpecializationDecl", "InstantiatedFromMemberTemplate"},
  {"NonTypeTemplateParmDecl", "DefaultArgument"},
  {"Type", "StripObjCKindOfType"},
  {"NonTypeTemplateParmDecl", "NumExpansionTypes"},
  {"Decl","DefiningAttribute"},
  {"CallExpr","UnusedResultAttribute"},
  {"Decl", "ExternalSourceSymbolAttribute"},
  {"AlignedAttr", "AlignmentType"},
  {"AlignedAttr", "AlignmentExpression"},
  {"EnumDecl", "PromotionType"},
  {"AssumeAlignedAttr", "Offset"},
  {"GCCAsmStmt", "ClobberStringLiteral"},
  {"GCCAsmStmt", "InputConstraintLiteral"},
  {"GCCAsmStmt", "OutputConstraintLiteral"},
  {"GCCAsmStmt", "InputExpression"},
  {"GCCAsmStmt", "OutputExpression"},
  {"GCCAsmStmt", "LabelExpression"},
  {"ValueDecl", "PotentiallyDecomposedVariableDeclaration"},
  {"TranslationUnitDecl", "AnonymousNamespace"},
  {"Decl", "DeclarationContext"},
  {"Decl", "LexicalDeclarationContext"},
  {"NamespaceDecl", "AnonymousNamespace"},
  {"EnumDecl", "Definition"},
  {"RecordDecl", "Definition"},
  {"CXXRecordDecl", "Definition"},
  {"ObjCInterfaceDecl", "Definition"},
  {"ObjCProtocolDecl", "Definition"},
  {"StaticAssertDecl", "Message"},
  {"VarTemplatePartialSpecializationDecl", "InstantiatedFromMember"},
  {"ClassTemplatePartialSpecializationDecl", "InstantiatedFromMember"},
  {"CXXCatchStmt", "CaughtType"},
  {"UnaryTransformType", "Desugar"},
  {"UnaryTransformType", "UnderlyingType"},
  {"UnaryTransformType", "BaseType"},
  {"VarTemplateSpecializationDecl", "TypeAsWritten"},
  {"PointerAttr", "DereferencedType"},
  {"PointerAttr", "DereferencedTypeToken"},
  {"OwnerAttr", "DereferencedType"},
  {"OwnerAttr", "DereferencedTypeToken"},
  {"TemplateDecl", "TemplatedDeclaration"},
  {"CXXNewExpr", "OperatorNew"},
  {"CXXNewExpr", "OperatorDelete"},
  {"CXXDeleteExpr", "OperatorNew"},
  {"CXXDeleteExpr", "OperatorDelete"},
  {"CXXDefaultArgExpr", "RewrittenExpression"},
  {"CXXDeleteExpr", "DestroyedType"},
  {"CXXFoldExpr", "Callee"},
  {"CXXFoldExpr", "Initializer"},
  {"CXXFoldExpr", "RHS"},
  {"CXXFoldExpr", "LHS"},
  {"CXXForRangeStmt", "Initializer"},
  {"CXXForRangeStmt", "Increment"},
  {"CXXForRangeStmt", "BeginStatement"},
  {"CXXForRangeStmt", "EndStatement"},
  {"CXXForRangeStmt", "Condition"},
  {"CXXDeductionGuideDecl", "CorrespondingConstructor"},
  {"PredefinedExpr", "FunctionName"},
  {"OpaqueValueExpr", "SourceExpression"},
  {"DependentSizedArrayType", "SizeExpression"},
  {"CXXRecordDecl", "LambdaStaticInvoker"},
  {"CoroutineBodyStmt", "ResultDeclaration"},
  {"BindingDecl", "Binding"},
  {"BindingDecl", "HoldingVariable"},
  {"CoreturnStmt", "Operand"},
  {"CoroutineBodyStmt", "ReturnStatementOnAllocFailure"},

//  {"FunctionProtoType", "EllipsisToken"},
//  {"FunctionDecl", "EllipsisToken"},
//  {"FunctionDecl", "PointOfInstantiation"},
//  {"VarDecl", "PointOfInstantiation"},
//  {"DeclaratorDecl", "TypeSpecEndToken"},
//  {"DeclaratorDecl", "TypeSpecStartToken"},
//  {"Decl", "BeginToken"},
//  {"Decl", "EndToken"},
};

std::map<std::pair<std::string, std::string>, std::string> kConditionalNullptr{
  {{"VarDecl", "HasFlexibleArrayInitializer"},
   "  if (!self.hasInit()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  auto *init_list = clang::dyn_cast<clang::InitListExpr>(\n"
   "      self.getInit()->IgnoreParens());\n"
   "  if (!init_list || !init_list->getNumInits()) {\n"
   "    return false;\n"
   "  }\n"},
  {{"AlignedAttr", "AlignmentType"},
   "  if (self.isAlignmentExpr()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"AlignedAttr", "AlignmentExpression"},
   "  if (!self.isAlignmentExpr()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"AlignedAttr", "Alignment"},
   "  if (self.isAlignmentDependent()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXPseudoDestructorExpr", "ScopeType"},
   "  if (!self.getScopeTypeInfo()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"FriendDecl", "FriendType"},
   "  if (!self.getFriendType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"ClassTemplateSpecializationDecl", "TypeAsWritten"},
   "  if (!self.getTypeAsWritten()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXDependentScopeMemberExpr", "Base"},
   "  if (self.isImplicitAccess()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"NonTypeTemplateParmDecl", "NumExpansionTypes"},
   "  if (!self.isExpandedParameterPack()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"NonTypeTemplateParmDecl", "ExpansionTypes"},
   "  if (!u.NonTypeTemplateParmDecl->isExpandedParameterPack()) {\n"
   "    return ret;\n"  // Vector from derived iterator.
   "  }\n"},
  {{"FunctionProtoType", "CanThrow"},
   "  switch (self.getExceptionSpecType()) {\n"
   "    case clang::EST_Unparsed:\n"
   "    case clang::EST_Unevaluated:\n"
   "    case clang::EST_Uninstantiated:\n"
   "      return std::nullopt;\n"
   "    default: break;\n"
   "  }\n"},
  {{"FunctionProtoType", "IsNothrow"},
   "  switch (self.getExceptionSpecType()) {\n"
   "    case clang::EST_Unparsed:\n"
   "    case clang::EST_Unevaluated:\n"
   "    case clang::EST_Uninstantiated:\n"
   "      return std::nullopt;\n"
   "    default: break;\n"
   "  }\n"},
  {{"TemplateTypeParmDecl", "DefaultArgument"},
   "  if (!self.getDefaultArgumentInfo()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"TemplateSpecializationType", "AliasedType"},
   "  if (!self.isTypeAlias()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXMethodDecl", "ThisObjectType"},
   "  if (!self.isInstance()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXMethodDecl", "ThisType"},
   "  if (!self.isInstance()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"InitListExpr", "IsTransparent"},
   "  if (!self.isSemanticForm()) {\n"
   "    return std::nullopt;\n"
   "  } else if (self.isGLValue()) {\n"
   "    if (self.getNumInits() != 1) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  {{"ParmVarDecl", "DefaultArgument"},
   "  if (HasUninstantiatedDefaultArgument() ||\n"
   "      HasUnparsedDefaultArgument()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"ParmVarDecl", "UninstantiatedDefaultArgument"},
   "  if (!HasUninstantiatedDefaultArgument()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"DeclStmt", "SingleDeclaration"},
   "  if (!IsSingleDeclaration()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"FunctionDecl", "IsReservedGlobalPlacementOperator"},
   "  decltype(auto) dname = self.getDeclName();\n"
   "  if (dname.getNameKind() != clang::DeclarationName::CXXOperatorName) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  auto oo = dname.getCXXOverloadedOperator();\n"
   "  if (oo == clang::OO_New || oo == clang::OO_Delete ||\n"
   "      oo == clang::OO_Array_New || oo == clang::OO_Array_Delete) {\n"
   "    return self.isReservedGlobalPlacementOperator();\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"FunctionDecl", "IsMSExternInline"},
   "  if (!self.isInlined()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return self.isMSExternInline();\n"
   "  }\n"},
  {{"FunctionDecl", "DoesDeclarationForceExternallyVisibleDefinition"},
   "  if (self.doesThisDeclarationHaveABody()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return self.doesDeclarationForceExternallyVisibleDefinition();\n"
   "  }\n"},
  {{"FunctionDecl", "IsInlineDefinitionExternallyVisible"},
   "  if (!self.doesThisDeclarationHaveABody() &&\n"
   "      !self.willHaveBody() && !self.hasAttr<clang::AliasAttr>()) {\n"
   "    return std::nullopt;\n"
   "  } else if (!self.isInlined()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  clang::ASTContext &ac = self.getASTContext();\n"
   "  if (ac.getLangOpts().GNUInline || self.hasAttr<clang::GNUInlineAttr>()) {\n"
   "    return self.isInlineDefinitionExternallyVisible();\n"
   "  } else if (ac.getLangOpts().CPlusPlus) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return self.isInlineDefinitionExternallyVisible();\n"
   "  }\n"},
  {{"FieldDecl", "BitWidth"},
   "  if (!self.isBitField()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Expr", "IsKnownToHaveBooleanValue"},
   "  if (self.getType().isNull()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Expr", "IsReadIfDiscardedInCPlusPlus11"},
   "  if (self.getType().isNull()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Expr", "IsCXX11ConstantExpression"},
   "  if (self.getType().isNull() || self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  auto &ac = ast->ci->getASTContext();\n"
   "  if (!ac.getLangOpts().CPlusPlus) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return self.isCXX11ConstantExpr(ac);\n"
   "  }\n"},
  {{"Expr", "IsIntegerConstantExpression"},
   "  if (self.getType().isNull() || self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    auto &ac = ast->ci->getASTContext();\n"
   "    return self.isIntegerConstantExpr(ac);\n"
   "  }\n"},
  {{"Expr", "IsCXX98IntegralConstantExpression"},
   "  if (self.getType().isNull() || self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    auto &ac = ast->ci->getASTContext();\n"
   "    return self.isCXX98IntegralConstantExpr(ac);\n"
   "  }\n"},
  {{"Expr", "IsEvaluatable"},
   "  if (self.getType().isNull() || self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    auto &ac = ast->ci->getASTContext();\n"
   "    return self.isEvaluatable(ac);\n"
   "  }\n"},
  {{"Expr", "EvaluateKnownConstInt"},
   "  if (self.getType().isNull() || self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    auto &ac = ast->ci->getASTContext();\n"
   "    return self.EvaluateKnownConstInt(ac);\n"
   "  }\n"},
  {{"Expr", "EvaluateKnownConstIntCheckOverflow"},
   "  if (self.getType().isNull() || self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    auto &ac = ast->ci->getASTContext();\n"
   "    return self.EvaluateKnownConstIntCheckOverflow(ac);\n"
   "  }\n"},
  {{"Expr", "ObjCProperty"},
   "  if (!self.isLValue() || self.getObjectKind() != clang::OK_ObjCProperty) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CastExpr", "TargetUnionField"},
   "  if (self.getCastKind() != clang::CK_ToUnion) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"IndirectFieldDecl", "AnonymousField"},
   "  if (self.chain().size() < 2) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"IndirectFieldDecl", "VariableDeclaration"},
   "  if (self.chain().size() < 2) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"CXXRecordDecl", "TemplateInstantiationPattern"},
   "  if (!clang::isTemplateInstantiation(self.getTemplateSpecializationKind())) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"UnaryExprOrTypeTraitExpr", "ArgumentExpression"},
   "  if (self.isArgumentType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"UnaryExprOrTypeTraitExpr", "ArgumentType"},
   "  if (!self.isArgumentType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"AtomicExpr", "OrderFail"},
   "  if (self.getNumSubExprs() <= 3 /* ORDER_FAIL */) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"AtomicExpr", "Weak"},
   "  if (self.getNumSubExprs() <= 5 /* WEAK */) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"AtomicExpr", "Value1"},
   "  if (self.getOp() != clang::AtomicExpr::AO__c11_atomic_init &&\n"
   "      self.getOp() != clang::AtomicExpr::AO__opencl_atomic_init &&\n"
   "      self.getNumSubExprs() <= 2 /* VAL1 */) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"AtomicExpr", "Value2"},
   "  if (self.getOp() != clang::AtomicExpr::AO__atomic_exchange &&\n"
   "      self.getNumSubExprs() <= 4 /* VAL2 */) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"AtomicExpr", "Scope"},
   "  if (self.getOp() < clang::AtomicExpr::AO__opencl_atomic_load ||\n"
   "      self.getOp() > clang::AtomicExpr::AO__opencl_atomic_fetch_max) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

#define SELF_IS_DEFINITION \
    "  if (!self.getDefinition()) {\n" \
    "    return std::nullopt;\n" \
    "  }\n"

#define SELF_IS_LAMBDA \
    "  if (!self.isLambda()) {\n" \
    "    return std::nullopt;\n" \
    "  }\n"

#define SELF_HAS_DECLCONTEXT \
    "  if (!self.getDeclContext()) {\n" \
    "    return std::nullopt;\n" \
    "  }\n"

  {{"CXXRecordDecl", "NumBases"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NumVirtualBases"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "Bases"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "VirtualBases"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "Methods"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "GenericLambdaTemplateParameterList"},
   "  if (!self.isGenericLambda()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "LambdaCallOperator"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "LambdaManglingNumber"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "HasKnownLambdaInternalLinkage"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "LambdaIsDefaultConstructibleAndAssignable"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "LambdaCaptureDefault"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "LambdaContextDeclaration"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "LambdaExplicitTemplateParameters"},
   "  if (!self.getGenericLambdaTemplateParameterList()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "LambdaTypeInfo"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "LambdaType"},
   SELF_IS_LAMBDA},
  {{"CXXRecordDecl", "ODRHash"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasInitializerMethod"},
   SELF_IS_DEFINITION},
  {{"EnumDecl", "ODRHash"},
   "  auto def = const_cast<clang::EnumDecl *>(self.getDefinition());\n"
   "  if (!def) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return def->getODRHash();\n"
   "  }\n"},
  {{"FunctionDecl", "ODRHash"},
   "  auto def = const_cast<clang::FunctionDecl *>(self.getDefinition());\n"
   "  if (!def) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return def->getODRHash();\n"
   "  }\n"},
  {{"CXXRecordDecl", "MSInheritanceModel"},
   "  if (!self.getAttr<clang::MSInheritanceAttr>()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "NullFieldOffsetIsZero"},
   "  if (!self.getAttr<clang::MSInheritanceAttr>()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "CalculateInheritanceModel"},
   "  if (!self.getAttr<clang::MSInheritanceAttr>()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "AllowConstDefaultInitializer"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "DefaultedCopyConstructorIsDeleted"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "DefaultedDefaultConstructorIsConstexpr"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "DefaultedDestructorIsConstexpr"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "DefaultedDestructorIsDeleted"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "DefaultedMoveConstructorIsDeleted"},
   SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasAnyDependentBases"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasConstexprDefaultConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasConstexprDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasConstexprNonCopyMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasCopyAssignmentWithConstParameter"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasCopyConstructorWithConstParameter"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasDefaultConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasDefinition"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasDirectFields"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasFriends"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasInClassInitializer"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasInheritedAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasInheritedConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasIrrelevantDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasKnownLambdaInternalLinkage"}, SELF_IS_LAMBDA SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasMemberName"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasMutableFields"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonLiteralTypeFieldsOrBases"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialCopyAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialCopyConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialCopyConstructorForCall"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialDefaultConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialDestructorForCall"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasNonTrivialMoveConstructorForCall"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasPrivateFields"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasProtectedFields"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasSimpleCopyAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasSimpleCopyConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasSimpleDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasSimpleMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasSimpleMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialCopyAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialCopyConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialCopyConstructorForCall"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialDefaultConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialDestructorForCall"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasTrivialMoveConstructorForCall"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUninitializedReferenceMember"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredCopyAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredCopyConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserDeclaredMoveOperation"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasUserProvidedDefaultConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "HasVariantMembers"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "Friends"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "ImplicitCopyAssignmentHasConstParameter"},SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "ImplicitCopyConstructorHasConstParameter"},SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsAbstract"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsAggregate"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsStructural"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsLiteral"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsAnyDestructorNoReturn"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsCLike"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsCXX11StandardLayout"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsCurrentInstantiation"}, SELF_IS_DEFINITION},
//  {{"CXXRecordDecl", "IsDependentLambda"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsDynamicClass"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsEffectivelyFinal"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsEmpty"}, SELF_IS_DEFINITION},
  //{{"CXXRecordDecl", "IsGenericLambda"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsInterfaceLike"},
   SELF_IS_DEFINITION
   "  if (clang::isa<clang::ClassTemplatePartialSpecializationDecl>(self)) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  if (self.isInterface()){\n"
   "    return false;\n"
   "  }\n"
   "  if (self.getNumBases() > 0) {\n"
   "    auto base_spec = *self.bases_begin();\n"
   "    if (auto base = base_spec.getType()->getAsCXXRecordDecl(); !base) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  //{{"CXXRecordDecl", "IsLambda"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsLiteral"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsLocalClass"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsPOD"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsParsingBaseSpecifiers"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsPolymorphic"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsProvablyNotDerivedFrom"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsStandardLayout"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsStructural"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsTrivial"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsTriviallyCopyable"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "IsVirtuallyDerivedFrom"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "MayBeAbstract"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "MayBeDynamicClass"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "MayBeNonDynamicClass"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsImplicitCopyAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsImplicitCopyConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsImplicitDefaultConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsImplicitDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsImplicitMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsImplicitMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsOverloadResolutionForCopyAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsOverloadResolutionForCopyConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsOverloadResolutionForDestructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsOverloadResolutionForMoveAssignment"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "NeedsOverloadResolutionForMoveConstructor"}, SELF_IS_DEFINITION},
  {{"CXXRecordDecl", "DeviceLambdaManglingNumber"},
   "  if (!self.isLambda()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "LambdaIndexInContext"},
   "  if (!self.isLambda()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"NamedDecl", "ObjCFStringFormattingFamily"},
   "  if (!self.getIdentifier()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"FunctionDecl", "DoesDeclarationForceExternallyVisibleDefinition"},
   "  if (self.doesThisDeclarationHaveABody()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"CXXConstructorDecl", "TargetConstructor"},
   "  if (!self.isDelegatingConstructor()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"CXXTypeidExpr", "ExpressionOperand"},
   "  if (self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXTypeidExpr", "IsMostDerived"},
   "  if (self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"FunctionDecl", "DoesDeclarationForceExternallyVisibleDefinition"},
   "  if (self.doesThisDeclarationHaveABody()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"SizeOfPackExpr", "PartialArguments"},
   "  if (!self.isPartiallySubstituted()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"SizeOfPackExpr", "PackLength"},
   "  if (self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"StringLiteral", "ContainsNonAscii"},
   "  if (self.getCharByteWidth() > 1) {\n"
   "     return std::nullopt;\n"
   "  }\n"},
  {{"StringLiteral", "ContainsNonAsciiOrNull"},
   "  if (self.getCharByteWidth() > 1) {\n"
   "     return std::nullopt;\n"
   "  }\n"},
  {{"StringLiteral", "String"},
   "  if (self.getCharByteWidth() > 1) {\n"
   "     return std::nullopt;\n"
   "  }\n"},
  {{"CXXUuidofExpr", "ExpressionOperand"},
   "  if (self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXDefaultInitExpr", "Expression"},
   "  if (!self.getField()->getInClassInitializer()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"TypeTraitExpr", "Value"},
   "  if (self.isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"VarDecl", "HasICEInitializer"},
   "  if (auto init = self.getInit(); !init || init->isValueDependent()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"Type", "ScalarTypeKind"},
   "  if (!self.isScalarType()) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    const clang::Type *t = self.getCanonicalTypeInternal().getTypePtr();\n"
   "    if (const clang::EnumType *et = clang::dyn_cast<clang::EnumType>(t)) {\n"
   "      if (!et->getDecl()->isComplete()) {\n"
   "        return std::nullopt;\n"
   "      }\n"
   "    }\n"
   "  }\n"},
  {{"Type", "SveElementType"},
   "  if (!self.isRVVVLSBuiltinType()) {\n"  // isSveVLSBuiltinType
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Type", "RVVElementType"},
   "  if (!self.isRVVVLSBuiltinType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Type", "IsObjCARCImplicitlyUnretainedType"},
   "  if (!self.isObjCLifetimeType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {{"Type", "IsAggregateType"},
   "  if (auto klass = self.getAsCXXRecordDecl()) {\n"
   "    if (!klass->getDefinition()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  
  {{"Type", "IsPODType"},
   "  if (auto klass = self.getAsCXXRecordDecl()) {\n"
   "    if (!klass->getDefinition()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},

  {{"Type", "IsCXX11PODType"},
   "  if (auto klass = self.getAsCXXRecordDecl()) {\n"
   "    if (!klass->getDefinition()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  
  {{"Type", "IsCXX98PODType"},
   "  if (auto klass = self.getAsCXXRecordDecl()) {\n"
   "    if (!klass->getDefinition()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},

  {{"Type", "IsStructuralType"},
   "  if (auto klass = self.getAsCXXRecordDecl()) {\n"
   "    if (!klass->getDefinition()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  {{"Type", "IsConstantSizeType"},
   "  if (self.isIncompleteType() || self.isDependentType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Type", "IsLiteralType"},
   "  if (self.isDependentType()) {\n"
   "    return false;\n"
   "  } else {\n"
   "    auto &c = ast->ci->getASTContext();\n"
   "    if (c.getLangOpts().CPlusPlus14 && self.isVoidType()) {\n"
   "      return true;\n"
   "    } else if (self.isVariableArrayType()) {\n"
   "      return false;\n"
   "    } else if (!self.getBaseElementTypeUnsafe()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  {{"Type", "IsStandardLayoutType"},
   "  if (self.isDependentType()) {\n"
   "    return false;\n"
   "  } else if (!self.getBaseElementTypeUnsafe()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Type", "IsCXX11PODType"},
   "  const clang::Type *t = self.getTypePtr();\n"
   "  if (t->isDependentType()) {\n"
   "    return false;\n"
   "  } else if (self.hasNonTrivialObjCLifetime()) {\n"
   "    return false;\n"
   "  } else if (!t->getBaseElementTypeUnsafe()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"UnaryExprOrTypeTraitExpr", "ArgumentTypeInfo"},
   "  if (!self.isArgumentType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"UnaryExprOrTypeTraitExpr", "ArgumentType"},
   "  if (!self.isArgumentType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"EnumDecl", "IntegerTypeSourceInfo"},
   "  if (!self.getIntegerTypeSourceInfo()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"EnumDecl", "IntegerType"},
   "  if (self.getIntegerType().isNull()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"ValueDecl", "PotentiallyDecomposedVariableDeclaration"},
   "  if (!clang::isa<clang::VarDecl>(&self) &&\n"
   "      !clang::isa<clang::BindingDecl>(&self)) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Decl", "ExternalSourceSymbolAttribute"},
   SELF_HAS_DECLCONTEXT},
  {{"Decl", "IsInLocalScopeForInstantiation"},
   SELF_HAS_DECLCONTEXT},
  {{"Decl", "NonTransparentDeclarationContext"},
   SELF_HAS_DECLCONTEXT},
  {{"Expr", "BestDynamicClassType"},
   "  const clang::Expr *E = self.getBestDynamicClassTypeExpr();\n"
   "  clang::QualType DerivedType = E->getType();\n"
   "  if (const clang::PointerType *PTy = DerivedType->getAs<clang::PointerType>()) {\n"
   "    DerivedType = PTy->getPointeeType();\n"
   "  }\n"
   "  if (DerivedType->isDependentType()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  const clang::RecordType *Ty = DerivedType->getAs<clang::RecordType>();\n"
   "  if (!Ty) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  clang::Decl *D = Ty->getDecl();\n"
   "  if (!clang::isa<clang::CXXRecordDecl>(D)) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Decl", "MaxAlignment"},
   "  clang::specific_attr_iterator<clang::AlignedAttr> I(self.attr_begin()), E(self.attr_end());\n"
   "  for (; I != E; ++I) {\n"
   "    if (I->isAlignmentDependent()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},

//  {{"CXXRecordDecl", "DefaultedMoveConstructorIsDeleted"},
//   "  if (self.needsOverloadResolutionForMoveConstructor() ||\n"
//   "      self.needsImplicitMoveConstructor()) {\n"
//   "    return self.defaultedMoveConstructorIsDeleted();\n"
//   "  } else {\n"
//   "    return std::nullopt;\n"
//   "  }\n"},
  {{"GenericSelectionExpr", "ControllingType"},
   "  if (!self.isTypePredicate()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"GenericSelectionExpr", "ControllingExpression"},
   "  if (!self.isExprPredicate()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"GenericSelectionExpr", "ResultExpression"},
   "  if (self.isResultDependent()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"PointerAttr", "DereferencedType"},
   "  if (!self.getDerefTypeLoc()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"OwnerAttr", "DereferencedType"},
   "  if (!self.getDerefTypeLoc()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"NamedDecl", "Visibility"},
   "  if (auto td = clang::dyn_cast<clang::TemplateDecl>(\n"
   "                                 u.NamedDecl)) {\n"
   "    if (!td->getTemplatedDecl()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "    if (!self.isLinkageValid()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
  {{"CXXRecordDecl", "LambdaStaticInvoker"},
   "  if (!self.getLambdaCallOperator()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"UserDefinedLiteral", "CookedLiteral"},
   "  auto op_kind = self.getLiteralOperatorKind();\n"
   "  if (op_kind == clang::UserDefinedLiteral::LiteralOperatorKind::LOK_Template ||\n"
   "      op_kind == clang::UserDefinedLiteral::LiteralOperatorKind::LOK_Raw) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Expr", "IgnoreParenthesisNoopCasts"},
   "  if (auto cast_expr = pasta::CastExpr::From(*this)) {\n"
   "    auto &new_self = *(u.CastExpr);\n"
   "    if (auto sub_expr = new_self.getSubExpr()) {\n"
   "      auto type_ptr = sub_expr->getType().getTypePtr();\n"
   "      if (type_ptr && type_ptr->isDependentType()) {\n"
   "        return std::nullopt;\n"
   "      }\n"
   "    }\n"
   "  }\n"},
  {{"CXXTypeidExpr", "TypeOperand"},
   "  if (!self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXTypeidExpr", "TypeOperandSourceInfo"},
   "  if (!self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXTypeidExpr", "TypeOperandSourceInfo"},
   "  if (!self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXUuidofExpr", "TypeOperand"},
   "  if (!self.isTypeOperand()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXRecordDecl", "IsTriviallyCopyConstructible"},
   "  if (!self.hasDefinition()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"CXXPseudoDestructorExpr", "DestroyedType"},
   "  if (self.getDestroyedType().isNull()) {\n"
   "    return std::nullopt;\n"
   "  }\n"},
  {{"Expr", "HasSideEffects"},
   "  if (auto sel = clang::dyn_cast<clang::GenericSelectionExpr>(&self)) {\n"
   "    if (sel->isResultDependent()) {\n"
   "      return std::nullopt;\n"
   "    }\n"
   "  }\n"},
};
