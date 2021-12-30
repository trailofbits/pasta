/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Globals.h"

std::unordered_map<std::string, std::vector<std::string>> gEnumerators;

// Maps class names to counter/nth getter methods.
std::unordered_map<std::string, std::vector<IteratorSpec>> gIterators;

const std::vector<llvm::StringRef> kAllClassNames{
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

  // Things to fixup.
  {"AdjustedType", "ResolvedType"},
  {"DeducedType", "ResolvedType"},
  {"DecayedType", "ResolvedType"},

  // Things to rename, most of these are singular and `CxxName` manages the
  // plural forms.
  {"SourceLocation", "Token"},
  {"SourceRange", "TokenRange"},
  {"Vbase", "VirtualBase"},
  {"VBase", "VirtualBase"},
  {"Ctor", "Constructor"},
  {"Dtor", "Destructor"},
  {"Stmt", "Statement"},
  {"Cond", "Condition"},
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
  {"Qual", "Qualified"},
  {"Unqual", "Unqualified"},
  {"noload_decls", "AlreadyLoadedDeclarations"},
  {"Noload_decls", "AlreadyLoadedDeclarations"},
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
  {"(unsigned int)", "uint32_t"},
  {"(long)", "int64_t"},
  {"(unsigned long)", "uint64_t"},
  {"(long long)", "int64_t"},
  {"(unsigned long long)", "uint64_t"},
  {"(const clang::DeclContext *)", "::pasta::DeclContext"},
  {"(clang::Decl::FriendObjectKind)", "::pasta::FriendObjectKind"},
  {"(clang::Decl::ModuleOwnershipKind)", "::pasta::ModuleOwnershipKind"},
  {"(clang::CallExpr::ADLCallKind)", "::pasta::ADLCallKind"},
  {"(clang::APValue::ValueKind)", "::pasta::APValueKind"},
  {"(clang::ConstantExpr::ResultStorageKind)", "::pasta::ResultStorageKind"},
  {"(clang::LinkageSpecDecl::LanguageIDs)", "::pasta::LanguageIDs"},
  {"(clang::ObjCMethodDecl::ImplementationControl)", "::pasta::ImplementationControl"},
  {"(clang::ObjCPropertyDecl::PropertyControl)", "::pasta::PropertyControl"},
  {"(clang::ObjCPropertyDecl::SetterKind)", "::pasta::SetterKind"},
  {"(clang::Decl::Kind)", "::pasta::DeclKind"},
  {"(clang::ImplicitParamDecl::ImplicitParamKind)", "::pasta::ImplicitParamKind"},
  {"(clang::RecordDecl::ArgPassingKind)", "::pasta::ArgPassingKind"},
  {"(clang::UnaryTransformType::UTTKind)", "::pasta::UTTKind"},
  {"(clang::ArrayType::ArraySizeModifier)", "::pasta::ArraySizeModifier"},
  {"(clang::VectorType::VectorKind)", "::pasta::VectorKind"},
  {"(clang::TypeDependenceScope::TypeDependence)", "::pasta::TypeDependence"},
  {"(clang::CXXConstructExpr::ConstructionKind)", "::pasta::ConstructionKind"},
  {"(clang::CXXNewExpr::InitializationStyle)", "::pasta::InitializationStyle"},
  {"(clang::Qualifiers::ObjCLifetime)", "::pasta::ObjCLifetime"},
  {"(clang::Type::ScalarTypeKind)", "::pasta::ScalarTypeKind"},
  {"(clang::QualType::PrimitiveCopyKind)", "::pasta::PrimitiveCopyKind"},
  {"(clang::QualType::PrimitiveDefaultInitializeKind)", "::pasta::PrimitiveDefaultInitializeKind"},
  {"(clang::attr::Kind)", "::pasta::AttributeKind"},

  {"(llvm::Optional<const clang::Expr *>)", "std::optional<::pasta::Expr>"},
  {"(llvm::Optional<unsigned int>)", "std::optional<unsigned>"},
  {"(llvm::Optional<clang::NullabilityKind>)", "std::optional<::pasta::NullabilityKind>"},

  {"(llvm::ArrayRef<clang::QualType>)", "std::vector<::pasta::Type>"},
  {"(llvm::Optional<llvm::ArrayRef<clang::QualType>>)", "std::optional<std::vector<::pasta::Type>>"},

  {"(llvm::iterator_range<clang::DeclContext::decl_iterator>)", "std::vector<::pasta::Decl>"},
  {"(llvm::iterator_range<clang::Decl::redecl_iterator>)", "std::vector<::pasta::Decl>"},
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

  {"(llvm::iterator_range<const clang::SourceLocation *>)",
   "std::vector<::pasta::Token>"},

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
   "std::vector<::pasta::Expr>"}
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
   "  return static_cast<::pasta::TypeKind>(val);\n"},

  {"(clang::Stmt::StmtClass)",
   "  return static_cast<::pasta::StmtKind>(val);\n"},

  {"(clang::attr::Kind)",
   "  return static_cast<::pasta::AttributeKind>(val);\n"},

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

  {"(bool)",
   "  return val;\n"},

  {"(const clang::DeclContext *)",
   "  if (val) {\n"
   "    return ::pasta::DeclContext(ast, val);\n"
   "  }\n"},

  {"(clang::Decl::FriendObjectKind)",
   "  return static_cast<::pasta::FriendObjectKind>(val);\n"},

  {"(clang::Decl::ModuleOwnershipKind)",
   "  return static_cast<::pasta::ModuleOwnershipKind>(val);\n"},

  {"(clang::CallExpr::ADLCallKind)",
   "  return static_cast<::pasta::ADLCallKind>(val);\n"},

  {"(clang::APValue::ValueKind)",
   "  return static_cast<::pasta::APValueKind>(val);\n"},

  {"(clang::ConstantExpr::ResultStorageKind)",
   "  return static_cast<::pasta::ResultStorageKind>(val);\n"},

  {"(clang::LinkageSpecDecl::LanguageIDs)",
   "  return static_cast<::pasta::LanguageIDs>(val);\n"},

  {"(clang::ObjCMethodDecl::ImplementationControl)",
   "  return static_cast<::pasta::ImplementationControl>(val);\n"},

  {"(clang::ObjCPropertyDecl::PropertyControl)",
   "  return static_cast<::pasta::PropertyControl>(val);\n"},

  {"(clang::ObjCPropertyDecl::SetterKind)",
   "  return static_cast<::pasta::SetterKind>(val);\n"},

  {"(clang::Decl::Kind)",
   "  return static_cast<::pasta::DeclKind>(val);\n"},

  {"(clang::ImplicitParamDecl::ImplicitParamKind)",
   "  return static_cast<::pasta::ImplicitParamKind>(val);\n"},

  {"(clang::RecordDecl::ArgPassingKind)",
   "  return static_cast<::pasta::ArgPassingKind>(val);\n"},

  {"(clang::UnaryTransformType::UTTKind)",
   "  return static_cast<::pasta::UTTKind>(val);\n"},

  {"(clang::ArrayType::ArraySizeModifier)",
   "  return static_cast<::pasta::ArraySizeModifier>(val);\n"},

  {"(clang::VectorType::VectorKind)",
   "  return static_cast<::pasta::VectorKind>(val);\n"},

  {"(clang::TypeDependenceScope::TypeDependence)",
   "  return static_cast<::pasta::TypeDependence>(val);\n"},

  {"(clang::CXXConstructExpr::ConstructionKind)",
   "  return static_cast<::pasta::ConstructionKind>(val);\n"},

  {"(clang::CXXNewExpr::InitializationStyle)",
   "  return static_cast<::pasta::InitializationStyle>(val);\n"},

  {"(clang::Qualifiers::ObjCLifetime)",
   "  return static_cast<::pasta::ObjCLifetime>(val);\n"},
  {"(clang::Type::ScalarTypeKind)",
   "  return static_cast<::pasta::ScalarTypeKind>(val);\n"},
  {"(clang::QualType::PrimitiveCopyKind)",
   "  return static_cast<::pasta::PrimitiveCopyKind>(val);\n"},
  {"(clang::QualType::PrimitiveDefaultInitializeKind)",
   "  return static_cast<::pasta::PrimitiveDefaultInitializeKind>(val);\n"},

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

  {"(llvm::ArrayRef<clang::QualType>)",
    "  std::vector<::pasta::Type> ret;\n"
    "  for (auto qual_type : val) {\n"
    "    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));\n"
    "  }\n" \
    "  return ret;\n"},

  {"(llvm::Optional<llvm::ArrayRef<clang::QualType>>)",
   "  if (!val.hasValue()) {\n"
   "    return std::nullopt;\n"
   "  }\n"
   "  std::vector<::pasta::Type> ret;\n"
   "  for (auto qual_type : val.getValue()) {\n"
   "    ret.emplace_back(TypeBuilder::Create<::pasta::Type>(ast, qual_type));\n"
   "  }\n" \
   "  return ret;\n"},

#define DECL_ITERATOR_IMPL(cls) \
    "  std::vector<::pasta::" #cls "> ret;\n" \
    "  for (auto decl_ptr : val) {\n" \
    "    ret.emplace_back(DeclBuilder::Create<::pasta::" #cls ">(ast, decl_ptr));\n" \
    "  }\n" \
    "  return ret;\n"

  {"(llvm::iterator_range<clang::DeclContext::decl_iterator>)",
   DECL_ITERATOR_IMPL(Decl)},

  {"(llvm::iterator_range<clang::Decl::redecl_iterator>)",
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
    "    ret.emplace_back(StmtBuilder::Create<::pasta::" #cls ">(ast, stmt_ptr));\n" \
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
    STMT_ITERATOR_IMPL(Expr)}
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
};

// Set of ClassName::MethodName pairs such that the class can return a nullptr,
// and thus `std::optional` probably needs to be used.
std::set<std::pair<std::string, std::string>> kCanReturnNullptr{};

std::unordered_map<std::string, uint32_t> gClassIDs;
std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;
std::vector<std::string> gTopologicallyOrderedStmts;
std::vector<std::string> gTopologicallyOrderedTypes;

std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;


#define PASTA_BEGIN_CLANG_WRAPPER(cls, id) \
  const std::string kClassName_ ## id(PASTA_STR(cls));

#include "Generated.h"
