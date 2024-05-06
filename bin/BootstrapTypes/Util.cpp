/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Util.h"
#include <clang/Basic/CharInfo.h>
#include "Globals.h"

#include <algorithm>
#include <string>


#define DECL_STR1(d) #d
#define DECL_STR2(d) DECL_STR1(d)
#define DECL_STR3(d) DECL_STR2(d)

const std::unordered_set<std::string> kConcreteDecls{
#define DECL(d, ...) DECL_STR3(d) "Decl",
#define ABSTRACT_DECL(...)
#include TARGET_CLANG_HEADER(clang/AST/DeclNodes.inc)
};

const std::unordered_set<std::string> kConcreteStmts{
#define STMT(d, ...) DECL_STR3(d),
#define ABSTRACT_STMT(...)
#include TARGET_CLANG_HEADER(clang/AST/StmtNodes.inc)
};

const std::unordered_set<std::string> kConcreteTypes{
  "QualifiedType",  // Our custom one to mirror `clang::QualType`.
#define TYPE(d, base) DECL_STR3(d) "Type",
#define ABSTRACT_TYPE(...)
#include TARGET_CLANG_HEADER(clang/AST/TypeNodes.inc)
};

const std::unordered_set<std::string> kConcreteAttrs{
#define ATTR(d, ...) DECL_STR3(d) "Attr",
#include TARGET_CLANG_HEADER(clang/Basic/AttrList.inc)
};

bool IsConcreteDecl(const std::string &name) {
  return name != "Decl" &&
         name != "OMPDeclarativeDirectiveDecl" &&
         name != "OMPDeclarativeDirectiveValueDecl" &&
         name != "RedeclarableTemplateDecl" &&
         kConcreteDecls.count(name);
}

bool IsConcreteType(const std::string &name) {
  return name != "Type" &&
         name != "TagType" &&
         name != "ReferenceType" &&
         name != "MatrixType" &&
         name != "FunctionType" &&
         name != "DeducedType" &&
         name != "ArrayType" &&
         name != "TypeWithKeyword" &&
         kConcreteTypes.count(name);
}

bool IsConcreteAttr(const std::string &name) {
  return name != "Attr" &&
         name != "TypeAttr" &&
         name != "StmtAttr" &&
         name != "DeclOrStmtAttr" &&
         name != "InheritableAttr" &&
         name != "InheritableParamAttr" &&
         name != "ParameterABIAttr" &&
         name != "HLSLAnnotationAttr" &&
         kConcreteAttrs.count(name);
}

StmtClassification ClassifyStmt(const std::string &name) {
  if (name == "Stmt" ||
      name == "AbstractConditionalOperator" ||
      name == "AsmStmt" ||
      name == "SwitchCase" ||
      name == "ValueStmt" ||
      name == "Expr" ||
      name == "CoroutineSuspendExpr" ||
      name == "ExplicitCastExpr" ||
      name == "FullExpr" ||
      name == "OverloadExpr" ||
      name == "CastExpr" ||
      name == "CXXNamedCastExpr" ||
      name == "OMPExecutableDirective" ||
      name == "OMPLoopDirective" ||
      name == "OMPLoopBasedDirective" ||
      name == "OMPLoopTransformationDirective" ||
      !kConcreteStmts.count(name)) {
    return StmtClassification::kAbstract;
  } else if (name.ends_with("Stmt") || name == "OMPCanonicalLoop") {
    return StmtClassification::kStmt;
  } else if (name.ends_with("Directive")) {
    return StmtClassification::kDirective;
  } else if (name.ends_with("Expr") || name == "ExprWithCleanups") {
    return StmtClassification::kExpr;
  } else if (name.ends_with("Operator")) {
    return StmtClassification::kOperator;
  } else if (name.ends_with("Literal")) {
    return StmtClassification::kLiteral;
  } else {
    assert(false);
    return StmtClassification::kStmt;
  }
}

std::string Capitalize(llvm::StringRef name) {
  return name.substr(0, 1).upper() + name.substr(1).str();
}

static const llvm::StringRef kDec = "Dec";
static const llvm::StringRef kLoc = "Loc";
static const llvm::StringRef kSourceRange = "SourceRange";

static std::string CxxNameImpl(llvm::StringRef name) {

  // Disable these.
  if (name == "asOpaquePtr" ||
      name.ends_with("_back") ||
      name.ends_with("_front") ||
      name.ends_with("_begin") ||
      name.ends_with("_end") ||
      name.ends_with("_rbegin") ||
      name.ends_with("_rend") ||
      name.starts_with("begin") ||
      name.starts_with("end") ||
      name.starts_with("rbegin") ||
      name.starts_with("rend")) {
    return "";

  } else if (name.starts_with("get") && !name.starts_with("gets")) {
    return CxxNameImpl(name.substr(3));

  } else if (name.starts_with("has") && !name.starts_with("hash")) {
    return "Has" + CxxNameImpl(name.substr(3));

  } else if (name.starts_with("is")) {
    return "Is" + CxxNameImpl(name.substr(2));

  // Begin/end iterators.
  } else if (name.ends_with("_begin") || name.ends_with("_end") ||
             name.ends_with("_size") || name.ends_with("_empty") ||
             name.ends_with("_rbegin") || name.ends_with("_rend") ||
             name.starts_with("begin_") || name.starts_with("end_") ||
             name.starts_with("rbegin_") || name.starts_with("rend_")) {
    return "";

  // Setters, ignore them.
  } else if (name.starts_with("set") && !name.starts_with("sets")) {
    return "";

  } else if (name.ends_with(kDec)) {
    return CxxNameImpl(name.substr(0, name.size() - kDec.size()).str()) + "Decrement";

  } else if (name.ends_with(kLoc)) {
    return CxxNameImpl(name.substr(0, name.size() - kLoc.size()).str()) + "Token";

  } else if (name.ends_with(kSourceRange) && kSourceRange.size() < name.size()) {
    return CxxNameImpl(name.substr(0, name.size() - kSourceRange.size()).str()) + "Tokens";

  } else if (auto name_it = kCxxMethodRenames.find(name.str());
             name_it != kCxxMethodRenames.end()) {
    return name_it->second;

  } else if (name.empty()) {
    return "";

  } else if (name[0] == '_') {
    return "_" + CxxNameImpl(name.substr(1));

  } else if (name.ends_with("_")) {
    return CxxNameImpl(name.substr(0, name.size() - 1u)) + "_";

  } else if (std::islower(name.front())) {
    return CxxNameImpl(Capitalize(name));

  // Recursively apply on all capitalized sub-components.
  } else {
    auto num_upper = 1u;
    auto seen_us = false;
    for (auto i = 1u; i < name.size(); ++i) {
      if (name[i] == '_') {
        if (!seen_us) {
          ++num_upper;
          seen_us = true;
        }
      } else if (std::isupper(name[i]) && !std::isupper(name[i - 1u])) {
        ++num_upper;
        seen_us = false;
      } else {
        seen_us = false;
      }
    }

    if (2u <= num_upper) {
      std::stringstream name_ss;
      std::stringstream ss;
      ss << name[0];
      for (auto i = 1u; i < name.size(); ++i) {
        if (std::isupper(name[i])) {
          if (auto sub_name = ss.str(); 1u < sub_name.size()) {
            name_ss << CxxNameImpl(sub_name);
            std::stringstream().swap(ss);
          }
        } else if (name[i] == '_') {
          name_ss << CxxNameImpl(ss.str());
          std::stringstream().swap(ss);
        }

        if (name[i] != '_') {
          ss << name[i];
        }
      }
      name_ss << CxxNameImpl(ss.str());

      return name_ss.str();

    } else {
      if (1u < name.size() && name.ends_with("s")) {
        return CxxNameImpl(name.substr(0u, name.size() - 1u)) + "s";
      } else {
        return name.str();
      }
    }
  }
}

std::string CxxName(llvm::StringRef name_) {
  if (name_ == "C2x_noreturn") {
    return "C2xnoreturn";
  } else if (name_ == "C2x_Noreturn") {
    return "C2xNoreturn";
  }

  auto name = CxxNameImpl(name_);

  if (name == "LParen") {
    return "LParenToken";
  } else if (name == "RParen") {
    return "RParenToken";
  } else if (name == "LBracket") {
    return "LBracketToken";
  } else if (name == "RBracket") {
    return "RBracketToken";
  } else if (name == "LBrace") {
    return "LBraceToken";
  } else if (name == "RBrace") {
    return "RBraceToken";
  } else if (name == "ChildrenExpression") {
    return "Children";
  }
  return name;
}

std::string CxxName(llvm::StringRef cls_name, llvm::StringRef meth_name) {
  // Ignore these. Previously we mappend them to `Type`, but that was
  // problematic with shadowing.
  if (meth_name.ends_with("TypeSourceInfo") ||
      meth_name.ends_with("TypeSourceInfos") ||
      meth_name.ends_with("TypeInfo")) {
    return "";
  }

  auto ret = CxxName(meth_name);
  if (ret != "Kind") {
    return ret;
  }

  if (cls_name == "BuiltinType") {
    return CxxName("BuiltinKind");
  
  } else if (cls_name == "CharacterLiteral") {
    return CxxName("LiteralKind");
  
  } else if (cls_name == "StringLiteral") {
    return CxxName("LiteralKind");
  
  } else if (cls_name == "SwiftAsyncAttr") {
    return CxxName("AttrKind");
  
  } else if (cls_name == "TypeOfExprType") {
    return CxxName("TypeKind");
  
  } else if (cls_name == "TypeOfType") {
    return CxxName("TypeKind");
  
  } else if (cls_name == "UnaryExprOrTypeTraitExpr") {
    return CxxName("KeywordKind");

  } else if (cls_name == "ObjCOwnershipAttr") {
    return "OwnershipKind";

  } else if (cls_name == "ObjCGCAttr") {
    return "GarbageCollectionKind";

  } else if (cls_name == "Type" || cls_name == "Stmt") {
    return ret;

  } else if (cls_name == "Attr" || cls_name == "Decl") {
    return "";
  
  } else {
    assert(false);
    return ret;
  }
}

std::string CapitalCaseToSnakeCase(llvm::StringRef name) {
  std::stringstream ss;

  auto i = 0u;
  auto added_sep = false;
  auto last_was_uc = false;
  auto skip = false;
  for (auto c : name) {
    if (skip) {
      skip = false;
      ++i;
      continue;
    }
    if ('_' == c) {
      if (last_was_uc || !i) {
        ss << '_';
      } else {
        ss << "__";
      }
      added_sep = true;
      last_was_uc = true;

    } else if (std::isupper(c)) {
      if (!added_sep && i && (i + 1u) < name.size()) {
        if (std::islower(name[i + 1u])) {
          ss << '_';
          added_sep = true;
        }
      }
      ss << static_cast<char>(std::tolower(c));
      added_sep = false;
      last_was_uc = false;

    } else if (std::isdigit(c)) {

      // Special case `1d`, `2d`, and `3d`.
      if (!added_sep && (i + 2u) < name.size() &&
          (c == '1' || c == '2' || c == '3') &&
           name[i + 1u] == 'd' &&
           std::isupper(name[i + 2u])) {
        ss << '_' << c << 'd' << '_';
        skip = true; // Skip the `d`.
        added_sep = true;

      } else {
        ss << c;
        if (!added_sep && (i + 1u) < name.size()) {
          if (!std::isdigit(name[i + 1u]) && !std::islower(name[i + 1u])) {
            ss << '_';
            added_sep = true;
          }
        }
      }
      last_was_uc = false;

    } else {
      ss << c;

      if (!added_sep && (i + 1u) < name.size()) {
        if (std::isupper(name[i + 1u])) {
          ss << '_';
          added_sep = true;
        }
      }
      last_was_uc = false;
    }
    ++i;
  }
  auto res = ss.str();

  // If it's ending with three underscores, then make it end with two
  // underscores. This is a dumb hack to deal with some special keywords/
  // token kinds that show up in PASTA.
  if (auto s = res.size(); s > 3u) {
    if (res[s - 1u] == '_' && res[s - 2u] == '_' && res[s - 3u] == '_') {
      res.pop_back();
    }
  }

  return res;
}

void ToUppercase(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), clang::toUppercase);
}
