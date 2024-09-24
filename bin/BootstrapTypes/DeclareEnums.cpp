/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

namespace {

static llvm::StringRef enumerator_name;

static std::string RenameEnum(llvm::StringRef name) {
  if (name == "AttrKind") {
    return name.str();
  } else if (name.ends_with("_t")) {
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
         !enumerator_name.starts_with("first") &&
         !enumerator_name.starts_with("last") &&
         !enumerator_name.starts_with("First") &&
         !enumerator_name.starts_with("Last") &&
         !enumerator_name.ends_with("Last") &&
         enumerator_name != "NoStmtClass" &&
         enumerator_name != "NUM_TOKENS" &&
         enumerator_name != "NUM_PP_KEYWORDS" &&
         enumerator_name != "NUM_OBJC_KEYWORDS" &&
         enumerator_name != "NUM_OVERLOADED_OPERATORS";
}

static std::string RenameEnumeratorInternal(const std::string &name) {
  if (enumerator_name == "eof") {
    return "EndOfFile";

  } else if (enumerator_name == "eod") {
    return "EndOfDirective";

  // NOTE(pag): There's also a `C23_noreturn`, so we don't want the names to
  //            collide. The lower case variant corresponds to `[[noreturn]]`
  //            whereas the uppercase variant corresponds to `_Noreturn`.
  } else if (enumerator_name == "C23_Noreturn") {
    return "C23_Noreturn";

  } else if (enumerator_name.ends_with("less")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumeratorInternal(name) + "Less";

  } else if (enumerator_name.ends_with("greater")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 7);
    return RenameEnumeratorInternal(name) + "Greater";

  } else if (enumerator_name.ends_with("equal")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumeratorInternal(name) + "Equal";

  } else if (enumerator_name.ends_with("pipe")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumeratorInternal(name) + "Pipe";

  } else if (enumerator_name.ends_with("colon")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumeratorInternal(name)+ "Colon";

  } else if (enumerator_name.ends_with("plus")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumeratorInternal(name) + "Plus";

  } else if (enumerator_name.ends_with("minus")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumeratorInternal(name) + "Minus";

  } else if (enumerator_name.ends_with("hash")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumeratorInternal(name) + "Hash";

  } else if (enumerator_name.ends_with("amp")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 3);
    return RenameEnumeratorInternal(name) + "Amp";

  } else if (enumerator_name.ends_with("star")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumeratorInternal(name) + "Star";

  } else if (enumerator_name.ends_with("_begin")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 6);
    return RenameEnumeratorInternal(name) + "Begin";

  } else if (enumerator_name.ends_with("_end")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 4);
    return RenameEnumeratorInternal(name) + "End";

  } else if (enumerator_name.ends_with("_size")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 5);
    return RenameEnumeratorInternal(name) + "Size";

  } else if (enumerator_name.ends_with("_alloc")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 6);
    return RenameEnumeratorInternal(name) + "Alloc";

  } else if (enumerator_name.ends_with("_Alignas")) {
    enumerator_name = enumerator_name.substr(0, enumerator_name.size() - 8);
    return RenameEnumeratorInternal(name) + "_Alignas";

  } else if (enumerator_name.starts_with("kw_")) {
    enumerator_name = enumerator_name.substr(3);
    return "Keyword" + RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("pp_") && name == "PPKeywordKind") {
    enumerator_name = enumerator_name.substr(3);
    return RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("objc_") && name == "ObjCKeywordKind") {
    enumerator_name = enumerator_name.substr(5);
    return RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("is_")) {
    enumerator_name = enumerator_name.substr(3);
    return "Is" + RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("has_")) {
    enumerator_name = enumerator_name.substr(4);
    return "Has" + RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("_is_")) {
    enumerator_name = enumerator_name.substr(4);
    return "_Is" + RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("_has_")) {
    enumerator_name = enumerator_name.substr(5);
    return "_Has" + RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("__is_")) {
    enumerator_name = enumerator_name.substr(5);
    return "__Is" + RenameEnumeratorInternal(name);

  } else if (enumerator_name.starts_with("__has_")) {
    enumerator_name = enumerator_name.substr(6);
    return "__Has" + RenameEnumeratorInternal(name);

  // `CxxName` strips things starting with `end`.
  } else if (enumerator_name == "endif") {
    return "Endif";

  } else if (enumerator_name == "Null" && name == "TemplateArgumentKind") {
    return "Empty";
  }

  if (name == "StmtKind" && enumerator_name.ends_with("Class")) {
    return Capitalize(enumerator_name.substr(
        0, enumerator_name.size() - 5));

  } else if (name == "DeclKind" || name == "TypeClass" || name == "TypeKind") {
    return Capitalize(enumerator_name);
  }
  return CxxName(enumerator_name);
}

static std::string RenameEnumerator(const std::string &name) {
  auto ret = RenameEnumeratorInternal(name);

  // `kRBraceToken` -> `kRBrace`.
  if (name == "TokenKind") {
    if (ret == "RBraceToken") {
      return "RBrace";

    } else if (ret == "LBraceToken") {
      return "LBrace";

    } else if (ret == "Hashat") {
      return "HashAt";
    }
  }
  return ret;
}

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    static void DeclareEnum_ ## enum_name(std::ostream &os, std::ostream &os_py) { \
      auto enum_name_str = RenameEnum(PASTA_STR(enum_name)); \
      auto &enumerators = gEnumerators[enum_name_str]; \
      gRetTypeMap.emplace( \
          "(clang::" PASTA_STR(enum_name) ")", \
          "enum " + enum_name_str); \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(enum_name) ")", \
          "  return static_cast<::pasta::" + enum_name_str + ">(val);\n"); \
      os << "enum class " << enum_name_str \
         << " : " << PASTA_STR(PASTA_SPLAT underlying_type) << " {\n"; \
      os_py << "  nb::enum_<pasta::" << enum_name_str << ">(m, \"" << enum_name_str << "\")";

#define PASTA_BEGIN_CLASS_NAMED_ENUM(class_name, enum_name, underlying_type) \
    static void DeclareEnum_ ## class_name ## _ ## enum_name(std::ostream &os, std::ostream &os_py) { \
      auto enum_name_str = RenameEnum(PASTA_STR(class_name) PASTA_STR(enum_name)); \
      auto &enumerators = gEnumerators[enum_name_str]; \
      gRetTypeMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", \
          "enum " + enum_name_str); \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", \
          "  return static_cast<::pasta::" + enum_name_str + ">(val);\n"); \
      os << "enum class " << enum_name_str \
         << " : " << PASTA_STR(PASTA_SPLAT underlying_type) << " {\n"; \
      os_py << "  nb::enum_<pasta::" << enum_name_str << ">(m, \"" << enum_name_str << "\")";

#define PASTA_NAMED_ENUMERATOR(enumerator_name_, underlying_type, val) \
      enumerator_name = #enumerator_name_; \
      for (auto prefix : kEnumPrefixesToStrip) { \
        if (enumerator_name.starts_with(prefix)) { \
          enumerator_name = enumerator_name.substr(prefix.size()); \
          break; \
        } \
      } \
      if (AcceptEnumerator(enum_name_str)) { \
        auto enumerator_str = RenameEnumerator(enum_name_str); \
        os << "  k" << enumerator_str << " = " \
           << PASTA_STR(PASTA_SPLAT val) << ",\n"; \
        auto upper_snake_case = CapitalCaseToSnakeCase(enumerator_str); \
        ToUppercase(upper_snake_case); \
        os_py << "\n    .value(\"" << upper_snake_case << "\", pasta::" \
              << enum_name_str << "::k" << enumerator_str << ")"; \
        enumerators.emplace_back(std::move(enumerator_str)); \
      }

#define PASTA_CLASS_ENUMERATOR PASTA_NAMED_ENUMERATOR

#define PASTA_END_NAMED_ENUM(enum_name) \
      if (enum_name_str == "TypeKind") { \
        os << "  kQualified  // Manually added.\n"; \
        os_py << "\n    .value(\"QUALIFIED\", pasta::TypeKind::kQualified)"; \
      } else if (enum_name_str == "TokenKind") { \
        os << "  kLAngle,  // Manually added.\n" \
           << "  kRAngle  // Manually added.\n"; \
        os_py << "\n    .value(\"L_ANGLE\", pasta::TokenKind::kLAngle)" \
              << "\n    .value(\"R_ANGLE\", pasta::TokenKind::kRAngle)"; \
      } \
      os << "};\n\n"; \
      os_py << ";\n\n"; \
    }

#define PASTA_END_CLASS_NAMED_ENUM(class_name, enum_name) \
    PASTA_END_NAMED_ENUM(enum_name)

#include "Generated.h"

}  // namespace

// Declare PASTA versions of every clang enumeration type from our macro file.
void DeclareEnums(std::ostream &os, std::ostream &os_py) {

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    DeclareEnum_ ## enum_name(os, os_py);

#define PASTA_BEGIN_CLASS_NAMED_ENUM(class_name, enum_name, underlying_type) \
    DeclareEnum_ ## class_name ## _ ## enum_name(os, os_py);

#include "Generated.h"
}
