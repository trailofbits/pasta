/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

namespace {

static llvm::StringRef enumerator_name;

static std::string RenameEnum(llvm::StringRef name) {
  if (name.endswith("_t")) {
    return RenameEnum(name.substr(0, name.size() - 2));
  } else if (name == "Nonce_ObjCInterface") {
    return "NonceObjCInterface";
  } else if (name == "StmtStmtClass") {
    return "StmtKind";
  } else if (name == "TypeTypeClass") {
    return "TypeKind";
  } else if (name == "ValueKind") {
    return "APValueKind";
  } else if (name == "TemplateArgumentArgKind") {
    return "TemplateArgumentKind";
  } else {
    return Capitalize(name);
  }
}

static bool AcceptEnumerator(const std::string &name) {
  return !enumerator_name.empty() &&
         !enumerator_name.startswith("first") &&
         !enumerator_name.startswith("last") &&
         !enumerator_name.startswith("First") &&
         !enumerator_name.startswith("Last") &&
         !enumerator_name.endswith("Last") &&
         enumerator_name != "NoStmtClass" &&
         enumerator_name != "NUM_TOKENS" &&
         enumerator_name != "NUM_PP_KEYWORDS" &&
         enumerator_name != "NUM_OBJC_KEYWORDS" &&
         enumerator_name != "NUM_OVERLOADED_OPERATORS";
}

static std::string RenameEnumerator(const std::string &name) {
  if (enumerator_name == "eof") {
    return "EndOfFile";

  } else if (enumerator_name == "eod") {
    return "EndOfDirective";

  } else if (enumerator_name.endswith("less")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumerator(name) + "Less";

  } else if (enumerator_name.endswith("greater")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 7);
    return RenameEnumerator(name) + "Greater";

  } else if (enumerator_name.endswith("equal")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumerator(name) + "Equal";

  } else if (enumerator_name.endswith("pipe")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumerator(name) + "Pipe";

  } else if (enumerator_name.endswith("colon")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumerator(name)+ "Colon";

  } else if (enumerator_name.endswith("plus")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumerator(name) + "Plus";

  } else if (enumerator_name.endswith("minus")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumerator(name) + "Minus";

  } else if (enumerator_name.endswith("hash")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumerator(name) + "Hash";

  } else if (enumerator_name.endswith("amp")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 3);
    return RenameEnumerator(name) + "Amp";

  } else if (enumerator_name.endswith("star")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumerator(name) + "Star";

  } else if (enumerator_name.endswith("_begin")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 6);
    return RenameEnumerator(name) + "Begin";

  } else if (enumerator_name.endswith("_end")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumerator(name) + "End";

  } else if (enumerator_name.startswith("kw_")) {
    enumerator_name = enumerator_name.substr(3);
    return "Keyword" + RenameEnumerator(name);

  } else if (enumerator_name.startswith("pp_") && name == "PPKeywordKind") {
    enumerator_name = enumerator_name.substr(3);
    return RenameEnumerator(name);

  } else if (enumerator_name.startswith("objc_") && name == "ObjCKeywordKind") {
    enumerator_name = enumerator_name.substr(5);
    return RenameEnumerator(name);

  } else if (enumerator_name.startswith("is_")) {
    enumerator_name = enumerator_name.substr(3);
    return "Is" + RenameEnumerator(name);

  } else if (enumerator_name.startswith("has_")) {
    enumerator_name = enumerator_name.substr(4);
    return "Has" + RenameEnumerator(name);

  } else if (enumerator_name.startswith("_is_")) {
    enumerator_name = enumerator_name.substr(4);
    return "_Is" + RenameEnumerator(name);

  } else if (enumerator_name.startswith("_has_")) {
    enumerator_name = enumerator_name.substr(5);
    return "_Has" + RenameEnumerator(name);

  } else if (enumerator_name.startswith("__is_")) {
    enumerator_name = enumerator_name.substr(5);
    return "__Is" + RenameEnumerator(name);

  } else if (enumerator_name.startswith("__has_")) {
    enumerator_name = enumerator_name.substr(6);
    return "__Has" + RenameEnumerator(name);

  // `CxxName` strips things starting with `end`.
  } else if (enumerator_name == "endif") {
    return "Endif";

  } else if (enumerator_name == "Null" && name == "TemplateArgumentKind") {
    return "Empty";
  }

  if (name == "StmtKind" && enumerator_name.endswith("Class")) {
    return Capitalize(enumerator_name.substr(
        0, enumerator_name.size() - 5));

  } else if (name == "DeclKind" || name == "TypeClass" || name == "TypeKind") {
    return Capitalize(enumerator_name);
  }
  return CxxName(enumerator_name);
}

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    static void DeclareEnum_ ## enum_name(std::ostream &os) { \
      auto enum_name_str = RenameEnum(PASTA_STR(enum_name)); \
      auto &enumerators = gEnumerators[enum_name_str]; \
      gRetTypeMap.emplace( \
          "(clang::" PASTA_STR(enum_name) ")", \
          "enum " + enum_name_str); \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(enum_name) ")", \
          "  return static_cast<::pasta::" + enum_name_str + ">(val);\n"); \
      os << "enum class " << enum_name_str \
         << " : " << PASTA_STR(PASTA_SPLAT underlying_type) << " {\n";

#define PASTA_BEGIN_CLASS_NAMED_ENUM(class_name, enum_name, underlying_type) \
    static void DeclareEnum_ ## class_name ## _ ## enum_name(std::ostream &os) { \
      auto enum_name_str = RenameEnum(PASTA_STR(class_name) PASTA_STR(enum_name)); \
      auto &enumerators = gEnumerators[enum_name_str]; \
      gRetTypeMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", \
          "enum " + enum_name_str); \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", \
          "  return static_cast<::pasta::" + enum_name_str + ">(val);\n"); \
      os << "enum class " << enum_name_str \
         << " : " << PASTA_STR(PASTA_SPLAT underlying_type) << " {\n";


#define PASTA_NAMED_ENUMERATOR(enumerator_name_, underlying_type, val) \
      enumerator_name = #enumerator_name_; \
      for (auto prefix : kEnumPrefixesToStrip) { \
        if (enumerator_name.startswith(prefix)) { \
          enumerator_name = enumerator_name.substr(prefix.size()); \
          break; \
        } \
      } \
      if (AcceptEnumerator(enum_name_str)) { \
        auto enumerator_str = RenameEnumerator(enum_name_str); \
        os << "  k" << enumerator_str << " = " \
           << PASTA_STR(PASTA_SPLAT val) << ",\n"; \
        enumerators.emplace_back(std::move(enumerator_str)); \
      }

#define PASTA_CLASS_ENUMERATOR PASTA_NAMED_ENUMERATOR

#define PASTA_END_NAMED_ENUM(enum_name) \
      os << "};\n\n"; \
    }

#define PASTA_END_CLASS_NAMED_ENUM(class_name, enum_name) \
    PASTA_END_NAMED_ENUM(enum_name)

#include "Generated.h"

}  // namespace

// Declare PASTA versions of every clang enumeration type from our macro file.
void DeclareEnums(std::ostream &os) {

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    DeclareEnum_ ## enum_name(os);

#define PASTA_BEGIN_CLASS_NAMED_ENUM(class_name, enum_name, underlying_type) \
    DeclareEnum_ ## class_name ## _ ## enum_name(os);

#include "Generated.h"
}
