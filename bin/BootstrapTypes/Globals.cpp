/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Globals.h"

std::unordered_map<std::string, std::vector<std::string>> gEnumerators;

// Maps class names to counter/nth getter methods.
std::unordered_map<std::string, std::vector<IteratorSpec>> gIterators;

const std::vector<llvm::StringRef> kAllClassNames{
  "OMPDeclarativeDirectiveDecl",
  "OMPDeclarativeDirectiveValueDecl",
  "ExceptionSpecification",
#define PASTA_BEGIN_CLANG_WRAPPER(name, id) PASTA_STR(name) ,
#include "Generated.h"
};

const std::vector<ClassExtends> kExtends{
#define PASTA_PUBLIC_BASE_CLASS(name, id, base_name, base_id) \
    {PASTA_STR(name), PASTA_STR(base_name)},
#include "Generated.h"
};

std::vector<std::string> gDeclNames;
std::vector<std::string> gStmtNames;
std::vector<std::string> gTypeNames;
std::vector<std::string> gAttrNames;

// All methods (class name, method name).
const std::set<std::pair<std::string, std::string>> gMethodNames{
#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) {#cls, #meth},
#include "Generated.h"
};

const std::unordered_map<std::string, std::string> kCxxMethodRenames{

  // Things to disable.
  {"asOpaquePtr", ""},

  // These are all getters that we want to disable, normally with `get` prefix.
  {"TypePtr", ""},
  {"TypePtrOrNull", ""},
  {"AsOpaquePtr", ""},
  {"UnqualifiedType", ""},

  // These are all getters, normally with `get` prefix.
  {"TypeClass", "Kind"},
  {"TypeClassName", "KindName"},
  {"StmtClass", "Kind"},
  {"StmtClassName", "KindName"},

  {"TypeSourceInfo", "Type"},
  {"TypeInfo", "Type"},

  // Things to fixup.
  {"AdjustedType", "ResolvedType"},
  {"DeducedType", "ResolvedType"},
  {"DecayedType", "ResolvedType"},

  // Things to rename, most of these are singular and `CxxName` manages the
  // plural forms.
  {"SourceLocation", "Token"},
  {"SourceRange", "Tokens"},
  {"Vbase", "VirtualBase"},
  {"VBase", "VirtualBase"},
  {"Ctor", "Constructor"},
  {"Dtor", "Destructor"},
  {"Stmt", "Statement"},
  {"Cond", "Condition"},
  {"Ret", "Return"},
  {"Expr", "Expression"},
  {"Assoc", "Association"},
  {"Init", "Initializer"},
  {"Idx", "Index"},
  {"Location", "Token"},
  {"clauselists", "Clauses"},  // `clang::OMPRequiresDecl::clauselists`
  {"Ivar", "InstanceVariable"},
  {"Arg", "Argument"},
  {"Attr", "Attribute"},
  {"Redecl", "Redeclaration"},
  {"Impl", "Implementation"},
  {"Decl", "Declaration"},
  {"Def", "Definition"},
  {"Anon", "Anonymous"},
  {"Var", "Variable"},
  {"Loc", "Location"},
  {"Asm", "Assembly"},
  {"MSAsm", "MSAssembly"},
  {"Str", "String"},
  {"Ident", "Identifier"},
  {"Ref", "Reference"},
  {"Orig", "Original"},
  {"Priv", "Private"},
  {"Pub", "Public"},
  {"Calc", "Calculate"},
  {"Par", "Parallel"},
  {"Dist", "Distance"},
  {"Iter", "Iteration"},
  {"Inc", "Increment"},
  {"Dict", "Dictionary"},
  {"Msg", "Message"},
  {"Char", "Character"},
  {"Bool", "Boolean"},
  {"Op", "Operation"},
  {"Ptr", "Pointer"},
  {"Mem", "Memory"},
  {"Parens", "Parentheses"},
  {"Paren", "Parenthesis"},
  {"Quals", "Qualifiers"},
  {"Qual", "Qualified"},
  {"Qualifieds", "Qualifiers"},
  {"Unqual", "Unqualified"},
  {"Elt", "Element"},
  {"RVVEltType", "RVVElementType"},
  {"SveEltType", "SveElementType"},
  {"noload_decls", "AlreadyLoadedDeclarations"},
  {"Noload_decls", "AlreadyLoadedDeclarations"},
  {"Param", "Parameter"},
  {"Params", "Parameters"},
  {"Brac", "Brace"},
  {"RBrac", "RightBrace"},
  {"LBrac", "LeftBrace"},
  {"NameAsString", "Name"},  // getNameAsString -> getName
  {"Val", "Value"},
  {"Val1", "Value1"},
  {"Val2", "Value2"},
  {"TInfo", "TypeInfo"},
  {"Cmd", "Command"},
  {"TST", "TemplateSpecializationType"},
  {"KW", "Keyword"},
  {"Addr", "Address"},
  {"Imp", "Implicit"},

  {"ColonLocFirst", "FirstColonToken"},
  {"ColonLocSecond", "SecondColonToken"},
  {"ArrayElementTypeNoTypeQualified", "ArrayElementTypeWithoutQualifiers"},
  {"SwitchCaseList", "FirstSwitchCase"},
  {"FindFirstNamedDataMember", "FirstNamedDataMember"},
  {"OuterLocStart", "FirstOuterToken"},
  {"InnerLocStart", "FirstInnerToken"},
  {"RightLoc", "RBracketToken"},
  {"LeftLoc", "LBracketToken"},
};

// Maps return types from the macros file to their replacements in the
// output code.
std::unordered_map<std::string, std::string> gRetTypeMap{
  {"(bool)", "bool"},
  {"(clang::SourceLocation)", "::pasta::Token"},
  {"(clang::SourceRange)", "::pasta::TokenRange"},
  {"(clang::QualType)", "::pasta::Type"},
  {"(clang::Type::TypeClass)", "::pasta::TypeKind"},
  {"(clang::Stmt::StmtClass)", "::pasta::StmtKind"},
  {"(llvm::StringRef)", "std::string_view"},
  {"(const char *)", "std::string_view"},
  {"(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>)", "std::string"},
  {"(std::basic_string<char, std::char_traits<char>, std::allocator<char>>)", "std::string"},
  {"(std::string)", "std::string"},
  {"(unsigned int)", "uint32_t"},
  {"(long)", "int64_t"},
  {"(unsigned long)", "uint64_t"},
  {"(long long)", "int64_t"},
  {"(unsigned long long)", "uint64_t"},
  {"(float)", "float"},
  {"(double)", "double"},
  {"(clang::ExprDependenceScope::ExprDependence)", "::pasta::ExprDependence"},
  {"(const clang::DeclContext *)", "::pasta::DeclContext"},
  {"(const clang::StringLiteral *)", "::pasta::StringLiteral"},
//  {"(clang::Decl::FriendObjectKind)", "::pasta::FriendObjectKind"},
//  {"(clang::Decl::ModuleOwnershipKind)", "::pasta::ModuleOwnershipKind"},
//  {"(clang::CallExpr::ADLCallKind)", "::pasta::ADLCallKind"},
//  {"(clang::APValue::ValueKind)", "::pasta::APValueKind"},
//  {"(clang::ConstantExpr::ResultStorageKind)", "::pasta::ResultStorageKind"},
//  {"(clang::LinkageSpecDecl::LanguageIDs)", "::pasta::LanguageIDs"},
//  {"(clang::ObjCMethodDecl::ImplementationControl)", "::pasta::ImplementationControl"},
//  {"(clang::ObjCPropertyDecl::PropertyControl)", "::pasta::PropertyControl"},
//  {"(clang::ObjCPropertyDecl::SetterKind)", "::pasta::SetterKind"},
  {"(clang::Decl::Kind)", "enum ::pasta::DeclKind"},
  {"(clang::attr::Kind)", "enum ::pasta::AttrKind"},
//  {"(clang::ImplicitParamDecl::ImplicitParamKind)", "::pasta::ImplicitParamKind"},
//  {"(clang::RecordDecl::ArgPassingKind)", "::pasta::ArgPassingKind"},
//  {"(clang::UnaryTransformType::UTTKind)", "::pasta::UTTKind"},
//  {"(clang::ArrayType::ArraySizeModifier)", "::pasta::ArraySizeModifier"},
//  {"(clang::VectorType::VectorKind)", "::pasta::VectorKind"},
//  {"(clang::TypeDependenceScope::TypeDependence)", "::pasta::TypeDependence"},
//  {"(clang::CXXConstructExpr::ConstructionKind)", "::pasta::ConstructionKind"},
//  {"(clang::CXXNewExpr::InitializationStyle)", "::pasta::InitializationStyle"},
//  {"(clang::Qualifiers::ObjCLifetime)", "::pasta::ObjCLifetime"},
//  {"(clang::Type::ScalarTypeKind)", "::pasta::ScalarTypeKind"},
//  {"(clang::QualType::PrimitiveCopyKind)", "::pasta::PrimitiveCopyKind"},
//  {"(clang::QualType::PrimitiveDefaultInitializeKind)", "::pasta::PrimitiveDefaultInitializeKind"},

  {"(llvm::Optional<const clang::Expr *>)", "std::optional<::pasta::Expr>"},
  {"(llvm::Optional<unsigned int>)", "std::optional<unsigned>"},
  {"(llvm::Optional<clang::NullabilityKind>)", "std::optional<::pasta::NullabilityKind>"},
  {"(llvm::Optional<llvm::ArrayRef<clang::QualType>>)", "std::optional<std::vector<::pasta::Type>>"},
  {"(std::optional<const clang::Stmt *>)", "std::optional<::pasta::Stmt>"},
  {"(std::optional<const clang::Expr *>)", "std::optional<::pasta::Expr>"},
  {"(std::optional<unsigned int>)", "std::optional<unsigned>"},
  {"(std::optional<clang::NullabilityKind>)", "std::optional<::pasta::NullabilityKind>"},
  {"(std::optional<llvm::ArrayRef<clang::QualType>>)", "std::optional<std::vector<::pasta::Type>>"},
  {"(std::optional<clang::Visibility>)", "std::optional<::pasta::Visibility>"},

  {"(llvm::ArrayRef<clang::QualType>)", "std::vector<::pasta::Type>"},

  // TODO(pag): Better C++ support.
  // {"(llvm::iterator_range<clang::CXXCtorInitializer *const *>)", "std::vector<pasta::CXXCtorInitializer>"},

  {"(llvm::iterator_range<clang::DeclContext::decl_iterator>)", "std::vector<::pasta::Decl>"},
  {"(llvm::iterator_range<clang::Decl::redecl_iterator>)", "std::vector<::pasta::Decl>"},
  {"(llvm::iterator_range<clang::Decl *const *>)", "std::vector<::pasta::Decl>"},
  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCMethodDecl, &clang::ObjCMethodDecl::isClassMethod>>)",
   "std::vector<::pasta::ObjCMethodDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCPropertyDecl, &clang::ObjCPropertyDecl::isClassProperty>>)",
   "std::vector<::pasta::ObjCPropertyDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCMethodDecl, &clang::ObjCMethodDecl::isInstanceMethod>>)",
   "std::vector<::pasta::ObjCMethodDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCPropertyDecl, &clang::ObjCPropertyDecl::isInstanceProperty>>)",
   "std::vector<::pasta::ObjCPropertyDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCMethodDecl>>)",
   "std::vector<::pasta::ObjCMethodDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCPropertyDecl>>)",
   "std::vector<::pasta::ObjCPropertyDecl>"},
  {"(llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::FunctionTemplateSpecializationInfo, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::FunctionTemplateSpecializationInfo>, clang::FunctionDecl>>)",
   "std::vector<::pasta::FunctionDecl>"},

  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCPropertyImplDecl>>)",
   "std::vector<::pasta::ObjCPropertyImplDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCIvarDecl>>)",
   "std::vector<::pasta::ObjCIvarDecl>"},
  {"(llvm::iterator_range<clang::ObjCProtocolDecl *const *>)",
   "std::vector<::pasta::ObjCProtocolDecl>"},
  {"(llvm::ArrayRef<clang::ParmVarDecl *>)",
   "std::vector<::pasta::ParmVarDecl>"},
  {"(llvm::ArrayRef<clang::DesignatedInitExpr::Designator>)",
   "std::vector<::pasta::Designator>"},
  {"(llvm::ArrayRef<clang::NamedDecl *>)",
   "std::vector<::pasta::NamedDecl>"},
  {"(llvm::ArrayRef<clang::ImplicitParamDecl *>)",
   "std::vector<::pasta::ImplicitParamDecl>"},
  {"(llvm::ArrayRef<clang::BindingDecl *>)",
   "std::vector<::pasta::BindingDecl>"},
  {"(llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::VarTemplateSpecializationDecl, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::VarTemplateSpecializationDecl>, clang::VarTemplateSpecializationDecl>>)",
   "std::vector<::pasta::VarTemplateSpecializationDecl>"},
  {"(llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::ClassTemplateSpecializationDecl, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::ClassTemplateSpecializationDecl>, clang::ClassTemplateSpecializationDecl>>)",
   "std::vector<::pasta::ClassTemplateSpecializationDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::EnumConstantDecl>>)",
   "std::vector<::pasta::EnumConstantDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::FieldDecl>>)",
   "std::vector<::pasta::FieldDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::CXXConstructorDecl>>)",
   "std::vector<::pasta::CXXConstructorDecl>"},
  {"(llvm::iterator_range<clang::CXXRecordDecl::friend_iterator>)",
   "std::vector<::pasta::FriendDecl>"},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::CXXMethodDecl>>)",
   "std::vector<::pasta::CXXMethodDecl>"},
  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isKnownCategory>>)",
   "std::vector<::pasta::ObjCCategoryDecl>"},
  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isKnownExtension>>)",
   "std::vector<::pasta::ObjCCategoryDecl>"},
  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isVisibleCategory>>)",
   "std::vector<::pasta::ObjCCategoryDecl>"},
  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isVisibleExtension>>)",
   "std::vector<::pasta::ObjCCategoryDecl>"},

  {"(llvm::iterator_range<clang::UsingDecl::shadow_iterator>)",
   "std::vector<::pasta::UsingShadowDecl>"},
  {"(llvm::iterator_range<clang::BaseUsingDecl::shadow_iterator>)",
   "std::vector<::pasta::UsingShadowDecl>"},

  {"(llvm::iterator_range<const clang::CXXMethodDecl *const *>)",
   "std::vector<::pasta::CXXMethodDecl>"},

  {"(llvm::iterator_range<const clang::SourceLocation *>)",
   "std::vector<::pasta::Token>"},

  {"(const llvm::SmallVector<clang::Attr *, 4> &)",
   "std::vector<::pasta::Attr>"},

#define DECL_VARIANT(a, b) \
    {"(llvm::PointerUnion<clang::" #a " *, clang::" #b " *>)", \
     "std::variant<std::monostate, ::pasta::" #a ", ::pasta::" #b ">"}

  DECL_VARIANT(ClassTemplateDecl, ClassTemplatePartialSpecializationDecl),
  DECL_VARIANT(VarTemplateDecl, VarTemplatePartialSpecializationDecl),
  DECL_VARIANT(BlockDecl, CompoundLiteralExpr),

  {"(llvm::iterator_range<clang::ConstStmtIterator>)",
   "std::vector<::pasta::Stmt>"},

  {"(llvm::iterator_range<clang::Stmt::CastIterator<clang::Expr, const clang::Expr *const, const clang::Stmt *const>>)",
   "std::vector<::pasta::Expr>"},

  {"(llvm::iterator_range<clang::Stmt::CastIterator<clang::AddrLabelExpr, const clang::AddrLabelExpr *const, const clang::Stmt *const>>)",
   "std::vector<::pasta::AddrLabelExpr>"},

  {"(llvm::ArrayRef<const clang::Stmt *>)",
   "std::vector<::pasta::Stmt>"},

  {"(llvm::ArrayRef<clang::Stmt *>)",
   "std::vector<::pasta::Stmt>"},

  {"(llvm::ArrayRef<const clang::Expr *>)",
   "std::vector<::pasta::Expr>"},

  {"(llvm::ArrayRef<clang::Expr *>)",
   "std::vector<::pasta::Expr>"},

  {"(llvm::ArrayRef<llvm::StringRef>)",
   "std::vector<std::string_view>"},

  {"(llvm::ArrayRef<clang::SourceRange>)",
   "std::vector<::pasta::TokenRange>"},

  {"(llvm::ArrayRef<clang::SourceLocation>)",
   "std::vector<::pasta::Token>"},

  {"(llvm::iterator_range<const clang::Expr *const *>)",
   "std::vector<::pasta::Expr>"},

  {"(llvm::iterator_range<const clang::CXXBaseSpecifier *>)",
   "std::vector<::pasta::CXXBaseSpecifier>"},

  {"(clang::BuiltinType::Kind)", "::pasta::BuiltinTypeKind"},

  {"(const llvm::APSInt &)", "llvm::APSInt"},
  {"(llvm::APSInt)", "llvm::APSInt"},
  {"(const llvm::APInt &)", "llvm::APInt"},
  {"(llvm::APInt)", "llvm::APInt"},

  {"(const clang::TemplateParameterList *)", "::pasta::TemplateParameterList"},
  {"(clang::TemplateParameterList *)", "::pasta::TemplateParameterList"},
  {"(clang::TypeSourceInfo *)", "::pasta::Type"},
  {"(const clang::TypeSourceInfo *)", "::pasta::Type"},

  {"(llvm::ArrayRef<clang::TemplateArgument>)", "std::vector<::pasta::TemplateArgument>"},
  {"(const clang::TemplateArgumentList &)", "std::vector<::pasta::TemplateArgument>"},

  {"(const clang::DesignatedInitExpr::Designator *)", "std::optional<::pasta::Designator>"},

  {"(llvm::ArrayRef<const clang::Attr *>)", "std::vector<::pasta::Attr>"},
  {"(llvm::iterator_range<clang::Attr *const *>)", "std::vector<::pasta::Attr>"},
  {"(const clang::Attr *)", "::pasta::Attr"},
  {"(clang::ParameterABI)", "::pasta::ParameterABI"},
};

// Maps return types from the macros file to how they should be returned
// in the generated Decl.cpp file.
std::unordered_map<std::string, std::string> gRetTypeToValMap{
  {"(bool)",
   "  return val;\n"},

  {"(clang::SourceLocation)",
   "  return ast->TokenAt(val);\n"},

  {"(clang::SourceRange)",
   "  return ast->TokenRangeFrom(val);\n"},

  {"(clang::QualType)",
   "  return TypeBuilder::Build(ast, val);\n"},

  {"(clang::Type::TypeClass)",
   "  return static_cast<enum ::pasta::TypeKind>(val);\n"},

  {"(clang::Stmt::StmtClass)",
   "  return static_cast<enum ::pasta::StmtKind>(val);\n"},

  {"(clang::attr::Kind)",
   "  return static_cast<enum ::pasta::AttrKind>(val);\n"},

  {"(llvm::StringRef)",
   "  if (auto size = val.size()) {\n"
   "    return std::string_view(val.data(), size);\n"
   "  } else {\n"
   "    return std::string_view();\n"
   "  }\n"},

  {"(const char *)",
   "  if (val) {\n"
   "    return std::string_view(val);\n"
   "  } else {\n"
   "    return std::string_view();\n"
   "  }\n"},

  {"(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>)",
   "  return val;\n"},

  {"(std::basic_string<char, std::char_traits<char>, std::allocator<char>>)",
   "  return val;\n"},

   {"(std::string)",
    "  return val;\n"},

  {"(unsigned int)",
   "  return val;\n"},

  {"(long)",
   "  return val;\n"},

  {"(long long)",
   "  return val;\n"},

  {"(unsigned long)",
   "  return val;\n"},

  {"(unsigned long long)",
   "  return val;\n"},

  {"(float)",
   "  return val;\n"},

  {"(double)",
   "  return val;\n"},

  {"(clang::ExprDependenceScope::ExprDependence)",
   "  return static_cast<::pasta::ExprDependence>(val);\n"},

  {"(const clang::StringLiteral *)",
   "  return StmtBuilder::Create<::pasta::StringLiteral>(ast, val.getValue());\n"},

  {"(const clang::DeclContext *)",
   "  if (val) {\n"
   "    return ::pasta::DeclContext(ast, val);\n"
   "  }\n"},

//  {"(clang::Decl::FriendObjectKind)",
//   "  return static_cast<::pasta::FriendObjectKind>(val);\n"},
//
//  {"(clang::Decl::ModuleOwnershipKind)",
//   "  return static_cast<::pasta::ModuleOwnershipKind>(val);\n"},
//
//  {"(clang::CallExpr::ADLCallKind)",
//   "  return static_cast<::pasta::ADLCallKind>(val);\n"},
//
//  {"(clang::APValue::ValueKind)",
//   "  return static_cast<::pasta::APValueKind>(val);\n"},
//
//  {"(clang::ConstantExpr::ResultStorageKind)",
//   "  return static_cast<::pasta::ResultStorageKind>(val);\n"},
//
//  {"(clang::LinkageSpecDecl::LanguageIDs)",
//   "  return static_cast<::pasta::LanguageIDs>(val);\n"},
//
//  {"(clang::ObjCMethodDecl::ImplementationControl)",
//   "  return static_cast<::pasta::ImplementationControl>(val);\n"},
//
//  {"(clang::ObjCPropertyDecl::PropertyControl)",
//   "  return static_cast<::pasta::PropertyControl>(val);\n"},
//
//  {"(clang::ObjCPropertyDecl::SetterKind)",
//   "  return static_cast<::pasta::SetterKind>(val);\n"},
//
  {"(clang::Decl::Kind)",
   "  return static_cast<enum ::pasta::DeclKind>(val);\n"},

  {"(clang::ParameterABI)",
   "  return static_cast<enum ::pasta::ParameterABI>(val);\n"},

//  {"(clang::ImplicitParamDecl::ImplicitParamKind)",
//   "  return static_cast<::pasta::ImplicitParamKind>(val);\n"},
//
//  {"(clang::RecordDecl::ArgPassingKind)",
//   "  return static_cast<::pasta::ArgPassingKind>(val);\n"},
//
//  {"(clang::UnaryTransformType::UTTKind)",
//   "  return static_cast<::pasta::UTTKind>(val);\n"},
//
//  {"(clang::ArrayType::ArraySizeModifier)",
//   "  return static_cast<::pasta::ArraySizeModifier>(val);\n"},
//
//  {"(clang::VectorType::VectorKind)",
//   "  return static_cast<::pasta::VectorKind>(val);\n"},
//
//  {"(clang::TypeDependenceScope::TypeDependence)",
//   "  return static_cast<::pasta::TypeDependence>(val);\n"},
//
//  {"(clang::CXXConstructExpr::ConstructionKind)",
//   "  return static_cast<::pasta::ConstructionKind>(val);\n"},
//
//  {"(clang::CXXNewExpr::InitializationStyle)",
//   "  return static_cast<::pasta::InitializationStyle>(val);\n"},
//
//  {"(clang::Qualifiers::ObjCLifetime)",
//   "  return static_cast<::pasta::ObjCLifetime>(val);\n"},
//  {"(clang::Type::ScalarTypeKind)",
//   "  return static_cast<::pasta::ScalarTypeKind>(val);\n"},
//  {"(clang::QualType::PrimitiveCopyKind)",
//   "  return static_cast<::pasta::PrimitiveCopyKind>(val);\n"},
//  {"(clang::QualType::PrimitiveDefaultInitializeKind)",
//   "  return static_cast<::pasta::PrimitiveDefaultInitializeKind>(val);\n"},

  {"(llvm::Optional<const clang::Expr *>)",
   "  if (val.hasValue()) {\n"
   "    return StmtBuilder::Create<::pasta::Expr>(ast, val.getValue());\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(llvm::Optional<unsigned int>)",
   "  if (val.hasValue()) {\n"
   "    return val.getValue();\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(llvm::Optional<clang::NullabilityKind>)",
   "  if (val.hasValue()) {\n"
   "    return static_cast<::pasta::NullabilityKind>(val.getValue());\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(llvm::Optional<llvm::ArrayRef<clang::QualType>>)",
   "  if (!val.hasValue()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  std::vector<::pasta::Type> ret;\n"
   "  for (auto qual_type : val.getValue()) {\n"
   "    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));\n"
   "  }\n" \
   "  return ret;\n"},

  {"(std::optional<const clang::Stmt *>)",
   "  if (val.has_value()) {\n"
   "    return StmtBuilder::Create<::pasta::Stmt>(ast, val.value());\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(std::optional<const clang::Expr *>)",
   "  if (val.has_value()) {\n"
   "    return StmtBuilder::Create<::pasta::Expr>(ast, val.value());\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(std::optional<unsigned int>)",
   "  if (val.has_value()) {\n"
   "    return val.value();\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(std::optional<clang::NullabilityKind>)",
   "  if (val.has_value()) {\n"
   "    return static_cast<::pasta::NullabilityKind>(val.value());\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(std::optional<llvm::ArrayRef<clang::QualType>>)",
   "  if (!val.has_value()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  std::vector<::pasta::Type> ret;\n"
   "  for (auto qual_type : val.value()) {\n"
   "    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));\n"
   "  }\n" \
   "  return ret;\n"},

  {"(std::optional<clang::Visibility>)",
   "  if (!val) {\n"
   "    return std::nullopt;\n"
   "  } else {\n"
   "    return static_cast<::pasta::Visibility>(val.value());\n"
   "  }\n"},

  {"(llvm::ArrayRef<clang::QualType>)",
   "  std::vector<::pasta::Type> ret;\n"
   "  for (auto qual_type : val) {\n"
   "    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));\n"
   "  }\n" \
   "  return ret;\n"},

#define DECL_ITERATOR_IMPL(cls) \
    "  std::vector<::pasta::" #cls "> ret;\n" \
    "  for (auto decl_ptr : val) {\n" \
    "    if (decl_ptr) {\n" \
    "      ret.emplace_back(DeclBuilder::Create<::pasta::" #cls ">(ast, decl_ptr));\n" \
    "    }\n" \
    "  }\n" \
    "  return ret;\n"

  {"(llvm::iterator_range<clang::DeclContext::decl_iterator>)",
   DECL_ITERATOR_IMPL(Decl)},

  {"(llvm::iterator_range<clang::Decl::redecl_iterator>)",
   DECL_ITERATOR_IMPL(Decl)},

  {"(llvm::iterator_range<clang::Decl *const *>)",
   DECL_ITERATOR_IMPL(Decl)},

  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCMethodDecl, &clang::ObjCMethodDecl::isClassMethod>>)",
   DECL_ITERATOR_IMPL(ObjCMethodDecl)},

  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCPropertyDecl, &clang::ObjCPropertyDecl::isClassProperty>>)",
   DECL_ITERATOR_IMPL(ObjCPropertyDecl)},

  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCMethodDecl, &clang::ObjCMethodDecl::isInstanceMethod>>)",
   DECL_ITERATOR_IMPL(ObjCMethodDecl)},

  {"(llvm::iterator_range<clang::DeclContext::filtered_decl_iterator<clang::ObjCPropertyDecl, &clang::ObjCPropertyDecl::isInstanceProperty>>)",
   DECL_ITERATOR_IMPL(ObjCPropertyDecl)},

  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCMethodDecl>>)",
   DECL_ITERATOR_IMPL(ObjCMethodDecl)},

  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCPropertyDecl>>)",
   DECL_ITERATOR_IMPL(ObjCPropertyDecl)},

  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCPropertyImplDecl>>)",
   DECL_ITERATOR_IMPL(ObjCPropertyImplDecl)},

  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::ObjCIvarDecl>>)",
   DECL_ITERATOR_IMPL(ObjCIvarDecl)},

  {"(llvm::iterator_range<clang::ObjCProtocolDecl *const *>)",
   DECL_ITERATOR_IMPL(ObjCProtocolDecl)},

  {"(llvm::ArrayRef<clang::ParmVarDecl *>)",
   DECL_ITERATOR_IMPL(ParmVarDecl)},

  {"(llvm::ArrayRef<clang::DesignatedInitExpr::Designator>)",
   "  std::vector<::pasta::Designator> ret;\n"
   "  for (const auto &d : val) {\n"
   "    ret.emplace_back(ast, &d);\n"
   "  }\n"
   "  return ret;\n"},

  {"(llvm::ArrayRef<clang::NamedDecl *>)",
   DECL_ITERATOR_IMPL(NamedDecl)},

  {"(llvm::ArrayRef<clang::ImplicitParamDecl *>)",
   DECL_ITERATOR_IMPL(ImplicitParamDecl)},

  {"(llvm::ArrayRef<clang::BindingDecl *>)",
   DECL_ITERATOR_IMPL(BindingDecl)},

  {"(llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::VarTemplateSpecializationDecl, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::VarTemplateSpecializationDecl>, clang::VarTemplateSpecializationDecl>>)",
   DECL_ITERATOR_IMPL(VarTemplateSpecializationDecl)},

  {"(llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::FunctionTemplateSpecializationInfo, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::FunctionTemplateSpecializationInfo>, clang::FunctionDecl>>)",
   DECL_ITERATOR_IMPL(FunctionDecl)},

  {"(llvm::iterator_range<clang::RedeclarableTemplateDecl::SpecIterator<clang::ClassTemplateSpecializationDecl, clang::RedeclarableTemplateDecl::SpecEntryTraits<clang::ClassTemplateSpecializationDecl>, clang::ClassTemplateSpecializationDecl>>)",
   DECL_ITERATOR_IMPL(ClassTemplateSpecializationDecl)},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::EnumConstantDecl>>)",
   DECL_ITERATOR_IMPL(EnumConstantDecl)},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::FieldDecl>>)",
   DECL_ITERATOR_IMPL(FieldDecl)},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::CXXConstructorDecl>>)",
   DECL_ITERATOR_IMPL(CXXConstructorDecl)},
  {"(llvm::iterator_range<clang::CXXRecordDecl::friend_iterator>)",
   DECL_ITERATOR_IMPL(FriendDecl)},
  {"(llvm::iterator_range<clang::DeclContext::specific_decl_iterator<clang::CXXMethodDecl>>)",
   DECL_ITERATOR_IMPL(CXXMethodDecl)},

  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isKnownCategory>>)",
   DECL_ITERATOR_IMPL(ObjCCategoryDecl)},

  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isKnownExtension>>)",
   DECL_ITERATOR_IMPL(ObjCCategoryDecl)},

  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isVisibleCategory>>)",
   DECL_ITERATOR_IMPL(ObjCCategoryDecl)},

  {"(llvm::iterator_range<clang::ObjCInterfaceDecl::filtered_category_iterator<&clang::ObjCInterfaceDecl::isVisibleExtension>>)",
   DECL_ITERATOR_IMPL(ObjCCategoryDecl)},

  {"(llvm::iterator_range<clang::UsingDecl::shadow_iterator>)",
   DECL_ITERATOR_IMPL(UsingShadowDecl)},

  {"(llvm::iterator_range<clang::BaseUsingDecl::shadow_iterator>)",
   DECL_ITERATOR_IMPL(UsingShadowDecl)},

  {"(llvm::iterator_range<const clang::CXXMethodDecl *const *>)",
   DECL_ITERATOR_IMPL(CXXMethodDecl)},

  {"(llvm::iterator_range<const clang::SourceLocation *>)",
   "  std::vector<::pasta::Token> ret;\n"
   "  for (auto loc : val) {\n"
   "    if (auto tok = ast->TokenAt(loc); tok) {\n"
   "      ret.emplace_back(std::move(tok));\n"
   "    }\n"
   "  }\n"
   "  return ret;\n"},

#define DECL_VARIANT_IMPL(a, a_builder, b, b_builder) \
    {"(llvm::PointerUnion<clang::" #a " *, clang::" #b " *>)", \
     "  std::variant<std::monostate, ::pasta::" #a ", ::pasta::" #b "> ret;\n" \
     "  if (val) {\n" \
     "    if (auto a_ptr = val.dyn_cast<clang::" #a " *>()) {\n" \
     "      ret = " #a_builder "::Create<::pasta::" #a ">(ast, a_ptr);\n" \
     "    } else if (auto b_ptr = val.dyn_cast<clang::" #b " *>()) {\n" \
     "      ret = " #b_builder "::Create<::pasta::" #b ">(ast, b_ptr);\n" \
     "    } else {\n" \
     "      ret = {};\n" \
     "    }\n" \
     "  } else {\n" \
     "    ret = {};\n" \
     "  }\n" \
     "  return ret;\n"}

  DECL_VARIANT_IMPL(ClassTemplateDecl, DeclBuilder, ClassTemplatePartialSpecializationDecl, DeclBuilder),
  DECL_VARIANT_IMPL(VarTemplateDecl, DeclBuilder, VarTemplatePartialSpecializationDecl, DeclBuilder),
  DECL_VARIANT_IMPL(BlockDecl, DeclBuilder, CompoundLiteralExpr, StmtBuilder),

#define STMT_ITERATOR_IMPL(cls) \
    "  std::vector<::pasta::" #cls "> ret;\n" \
    "  for (auto stmt_ptr : val) {\n" \
    "    if (stmt_ptr) {\n" \
    "      ret.emplace_back(StmtBuilder::Create<::pasta::" #cls ">(ast, stmt_ptr));\n" \
    "    }\n" \
    "  }\n" \
    "  return ret;\n"

  {"(llvm::iterator_range<clang::ConstStmtIterator>)",
   STMT_ITERATOR_IMPL(Stmt)},

  {"(llvm::iterator_range<clang::Stmt::CastIterator<clang::Expr, const clang::Expr *const, const clang::Stmt *const>>)",
   STMT_ITERATOR_IMPL(Expr)},

  {"(llvm::iterator_range<clang::Stmt::CastIterator<clang::AddrLabelExpr, const clang::AddrLabelExpr *const, const clang::Stmt *const>>)",
   STMT_ITERATOR_IMPL(AddrLabelExpr)},

  {"(llvm::ArrayRef<const clang::Stmt *>)",
   STMT_ITERATOR_IMPL(Stmt)},

  {"(llvm::ArrayRef<clang::Stmt *>)",
   STMT_ITERATOR_IMPL(Stmt)},

  {"(llvm::ArrayRef<const clang::Expr *>)",
   STMT_ITERATOR_IMPL(Expr)},

  {"(llvm::ArrayRef<clang::Expr *>)",
   STMT_ITERATOR_IMPL(Expr)},

  {"(llvm::ArrayRef<llvm::StringRef>)",
   "  std::vector<std::string_view> ret;\n"
   "  for (auto sr : val) {\n"
   "    std::string_view sv(sr.data(), sr.size());\n"
   "    ret.emplace_back(std::move(sv));\n"
   "  }\n"
   "  return ret;\n"},

  {"(llvm::ArrayRef<clang::SourceRange>)",
   "  std::vector<::pasta::TokenRange> ret;\n"
   "  for (auto sr : val) {\n"
   "    ret.emplace_back(ast->TokenRangeFrom(sr));\n"
   "  }\n"
   "  return ret;\n"},

  {"(llvm::ArrayRef<clang::SourceLocation>)",
   "  std::vector<::pasta::Token> ret;\n"
   "  for (auto sl : val) {\n"
   "    ret.emplace_back(ast->TokenAt(sl));\n"
   "  }\n"
   "  return ret;\n"},

  {"(llvm::iterator_range<const clang::Expr *const *>)",
   STMT_ITERATOR_IMPL(Expr)},

  {"(llvm::iterator_range<const clang::CXXBaseSpecifier *>)",
   "  std::vector<::pasta::CXXBaseSpecifier> ret;\n"
   "  for (const auto &bs : val) {\n"
   "    ret.emplace_back(ast, bs);\n"
   "  }\n"
   "  return ret;\n"},

  {"(clang::BuiltinType::Kind)",
   "  return static_cast<::pasta::BuiltinTypeKind>(val);\n"},

  {"(const llvm::APSInt &)",
   "  return val;\n"},

  {"(llvm::APSInt)",
   "  return val;\n"},

  {"(const llvm::APInt &)",
   "  return val;\n"},

  {"(llvm::APInt)",
   "  return val;\n"},

  {"(const clang::TemplateParameterList *)",
   "  return ::pasta::TemplateParameterList(ast, val);\n"},

  {"(clang::TemplateParameterList *)",
   "  return ::pasta::TemplateParameterList(ast, val);\n"},

  {"(clang::TypeSourceInfo *)",
   "  return TypeBuilder::Build(ast, val->getType());\n"},

  {"(const clang::TypeSourceInfo *)",
   "  return TypeBuilder::Build(ast, val->getType());\n"},

  {"(llvm::ArrayRef<clang::TemplateArgument>)",
   "  std::vector<::pasta::TemplateArgument> ret;\n"
   "  for (const auto &arg : val) {\n"
   "    ret.emplace_back(ast, arg);\n"
   "  }\n"
   "  return ret;\n"},

  {"(const clang::TemplateArgumentList &)",
   "  std::vector<::pasta::TemplateArgument> ret;\n"
   "  for (auto i = 0u, max_i = val.size(); i < max_i; ++i) {\n"
   "    const auto &arg = val[i];\n"
   "    ret.emplace_back(ast, arg);\n"
   "  }\n"
   "  return ret;\n"},

  {"(const clang::DesignatedInitExpr::Designator *)",
   "  if (val) {\n"
   "    return DeclBuilder::Create<::pasta::Designator>(ast, val);\n"
   "  }\n"},

  {"(llvm::ArrayRef<const clang::Attr *>)",
   "  std::vector<::pasta::Attr> ret;\n"
   "  for (auto attr_ptr : val) {\n"
   "    if (attr_ptr) {\n"
   "      ret.emplace_back(AttrBuilder::Create<::pasta::Attr>(ast, attr_ptr));\n"
   "    }\n"
   "  }\n"
   "  return ret;\n"},

  {"(llvm::iterator_range<clang::Attr *const *>)",
   "  std::vector<::pasta::Attr> ret;\n"
   "  for (auto attr_ptr : val) {\n"
   "    if (attr_ptr) {\n"
   "      ret.emplace_back(AttrBuilder::Create<::pasta::Attr>(ast, attr_ptr));\n"
   "    }\n"
   "  }\n"
   "  return ret;\n"},

  {"(const clang::Attr *)",
   "  if (val) {\n"
   "    return ::pasta::Attr(ast, val);\n"
   "  }\n"},

  {"(const llvm::SmallVector<clang::Attr *, 4> &)",
   "  std::vector<::pasta::Attr> ret;\n"
   "  for (auto attr_ptr : val) {\n"
   "    if (attr_ptr) {\n"
   "      ret.emplace_back(AttrBuilder::Create<::pasta::Attr>(ast, attr_ptr));\n"
   "    }\n"
   "  }\n"
   "  return ret;\n"},
};

// Prefixes on enumerators to strip.
std::vector<llvm::StringRef> kEnumPrefixesToStrip{
    "TK_",
    "OBJC_TQ_",
    "lang_",
    "TLS_",
    "IDNS_",
    "FOK_",
    "AS_",
    "ASMM_",
    "APK_",
    "ak_",
    "MLV_",
    "VCK_",
    "UO_",
    "UETT_",
    "TST_",
    "TSS_",
    "LLVM_BITMASK_LARGEST_ENUMERATOR",  // Hack to eliminate this
    "TU_",
    "TSCS_",
    "UTT_Last",
    "BTT_Last",
    "TT_Last",
    "UTT_",
    "BTT_",
    "TT_",
    "SMF_",
    "SOB_",
    "SSP",  // Stack protector mode, no `_`.
    "SC_",
    "SD_",
    "TTK_",
    "TSK_",
    "TSW_",
    "TSP_",
    "GVA_",
    "GE_",
    "IR_",
    "ICIS_",
    "IDI_",
    "ISK_",
    "CL_",
    "LV_",
    "LCD_",
    "LCK_",
    "LOK_",
    "MT_",
    "CM_",
    "NOUR_",
    "Nonce_",
    "NPCK_",
    "NPC_",
    "OBC_",
    "OIT_",
    "OCL_",
    "OMF_",
    "OBJC_PR_",
    "SFF_",
    "OMPC_ATOMIC_DEFAULT_MEM_ORDER_",
    "OMPC_DEFAULTMAP_MODIFIER_",
    "OMPC_DEFAULTMAP_",
    "OMPC_DEPEND_",
    "OMPC_DEVICE_TYPE_",
    "OMPC_DEVICE_",
    "OMPC_DIST_SCHEDULE_",
    "OMPC_FROM_MODIFIER_",
    "OMPC_LASTPRIVATE_",
    "OMPC_LINEAR_",
    "OMPC_MAP_MODIFIER_",
    "OMPC_MAP_",
    "OMPC_ORDER_",
    "OMPC_REDUCTION_",
    "OMPC_SCHEDULE_MODIFIER_",
    "OMPC_SCHEDULE_",
    "OMPC_TO_MODIFIER_",
    "OO_",
    "Ovl_",
    "AAPCS_",  // Hrmmm.
    "PFC_",
    "PCK_",
    "PPTMK_",
    "PMSST_",
    "PSF_",
    "PCK_",
    "PDIK_",
    "RQ_",
    "RSK_",
    "SFINAE_",
    "SO_",
    "STK_",
    "SelLoc_",
    "SE_",
    "AO__",
    "ATT_",
    "BO_",
    "BS_",
    "CC_",
    "CT_",
    "CR_",
    "CK_",
    "RCK_",
    "CMK_",
    "CSK_",
    "DAK_",
    "DCC_",
    "DK_",
    "DT_",
    "ETK_",
    "EST_",
    "OK_",
    "VK_",
    "ET_",
    "EK_",
    "FPE_",
    "FPM_",
    "ADOF_",
    "AR_",
    "RK_",
    "SYCL_",
    "LH_",
    "NK_",
    "OMPC_",
    "SRCK_",
    "BI_",
    "AO__",
    "OOS_",
    "LDK_",
};

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
  {"CXXForRangeStmt", "Initializer"},
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
  {{"CXXRecordDecl", "IsInterfaceLike"}, SELF_IS_DEFINITION},
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
};

std::unordered_map<std::string, uint32_t> gClassIDs;
std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;
std::vector<std::string> gTopologicallyOrderedStmts;
std::vector<std::string> gTopologicallyOrderedTypes;
std::vector<std::string> gTopologicallyOrderedAttrs;

std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;


#define PASTA_BEGIN_CLANG_WRAPPER(cls, id) \
  const std::string kClassName_ ## id(PASTA_STR(cls));

#include "Generated.h"