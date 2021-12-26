/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Util.h"
#include "Globals.h"

std::string Capitalize(llvm::StringRef name) {
  return name.substr(0, 1).upper() + name.substr(1).str();
}

std::string CxxName(llvm::StringRef name) {
  if (name == "getKind" || name == "getDeclKindName") {
    return "";  // We have our own `DeclKind`.

  // Disable these.
  } else if (name == "asOpaquePtr" ||
             name == "getTypePtr" ||
             name == "getTypePtrOrNull" ||
             name == "getAsOpaquePtr" ||
             name == "getUnqualifiedType") {
    return "";

  } else if (name == "getTypeClass") {
    return "Kind";

  } else if (name == "getTypeClassName") {
    return "KindName";

  } else if (name == "getStmtClass") {
    return "Kind";

  } else if (name == "getStmtClassName") {
    return "KindName";

  } else if (name == "getCapturedStmt") {
    return "FindCapturedStmt";

  } else if (name == "getFriendDecl") {
    return "FindFriendDecl";

  } else if (name == "getRawStmt") {
    return "FindRawStmt";

  } else if (name == "getExpr") {
    return "FindExpr";

  } else if (name == "getAdjustedType" ||
             name == "getDeducedType" ||
             name == "getDecayedType") {
    return "ResolvedType";

  } else if (name.startswith("get")) {
    return CxxName(name.substr(3));

  } else if (name.startswith("has")) {
    return "Has" + CxxName(name.substr(3));

  } else if (name.startswith("is")) {
    return "Is" + CxxName(name.substr(2));

  // Begin/end iterators.
  } else if (name.endswith("_begin") || name.endswith("_end") ||
             name.endswith("_size") || name.endswith("_empty") ||
             name.endswith("_rbegin") || name.endswith("_rend")) {
    return "";

  // Setters, ignore them.
  } else if (name.startswith("set")) {
    return "";

  } else if (name.endswith("Loc")) {
    return CxxName(name.substr(0, name.size() - 3).str()) + "Token";

  } else if (auto name_it = kCxxMethodRenames.find(name.str());
             name_it != kCxxMethodRenames.end()) {
    return name_it->second;

  } else if (name.empty()) {
    return "";

  } else if (std::islower(name.front())) {
    return Capitalize(name);

  } else {
    return name.str();
  }
}
