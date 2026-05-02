/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include "Globals.h"

// Maps from Clang return-type strings to PASTA wrapper return-type strings
// (`gRetTypeMap`) and to the snippet of code that converts a clang value to
// the PASTA value at the return site (`gRetTypeToValMap`).
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
  {"(llvm::iterator_range<clang::CXXCtorInitializer *const *>)", "std::vector<::pasta::CXXCtorInitializer>"},
  {"(llvm::iterator_range<clang::UnresolvedSetIterator>)", "std::vector<::pasta::NamedDecl>"},

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
   "  if (val.has_value() && val.value()) {\n"
   "    return StmtBuilder::Create<::pasta::Stmt>(ast, val.value());\n"
   "  } else {\n"
   "    return std::nullopt;\n"
   "  }\n"},

  {"(std::optional<const clang::Expr *>)",
   "  if (val.has_value() && val.value()) {\n"
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
   "    return DesignatorBuilder::Create<::pasta::Designator>(ast, val);\n"
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
