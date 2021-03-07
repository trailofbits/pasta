/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <llvm/ADT/StringRef.h>

#include <pasta/Util/Compiler.h>

#include "BootstrapConfig.h"

namespace {

static const llvm::StringRef kAllClassNames[] = {
#define PASTA_BEGIN_CLANG_WRAPPER(name, id) PASTA_STR(name) ,
#include "Generated.h"
};

static std::vector<std::string> gDeclNames;
static std::vector<std::string> gTypeNames;

static const struct {std::string derived; std::string base; } kExtends[] = {
#define PASTA_PUBLIC_BASE_CLASS(name, id, base_name, base_id) \
    {PASTA_STR(name), PASTA_STR(base_name)},
#include "Generated.h"
};

static const std::unordered_map<std::string, std::string> kCxxMethodRenames{
  {"SourceRange", "TokenRange"},
  {"Vbases", "VBases"},
  {"vbases", "VirtualBases"},
  {"NumVbases", "NumVBases"},
  {"Ctors", "Constructors"},
  {"ctors", "Constructors"},
  {"Dtors", "Destructors"},
  {"dtors", "Destructors"},
  {"Location", "Token"},
  {"clauselists", "Clauses"},  // `clang::OMPRequiresDecl::clauselists`
  {"Inits", "Initializers"},
  {"Ivars", "InstanceVariables"},
};

// Maps return types from the macros file to their replacements in the
// output code.
static std::unordered_map<std::string, std::string> kRetTypeMap{
  {"(bool)", "bool"},
  {"(clang::SourceLocation)", "std::optional<::pasta::Token>"},
  {"(llvm::StringRef)", "std::string_view"},
  {"(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>)", "std::string"},
  {"(unsigned int)", "uint32_t"},
  {"(unsigned long)", "uint64_t"},
};

// Maps return types from the macros file to how they should be returned
// in the generated Decl.cpp file.
static std::unordered_map<std::string, std::string> gRetTypeToValMap{
  {"(bool)",
   "  return val;\n"},

  {"(clang::SourceLocation)",
   "  return ast->TokenAt(val);\n"},

  {"(llvm::StringRef)",
   "  if (auto size = val.size()) {\n"
   "    return std::string_view(val.data(), size);\n"
   "  } else {\n"
   "    return std::string_view();\n"
   "  }\n"},

  {"(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>)",
   "  return val;\n"},

  {"(unsigned int)",
   "  return val;\n"},

  {"(unsigned long)",
   "  return val;\n"},
};

// Prefixes on enumerators to strip.
static llvm::StringRef kEnumPrefixesToStrip[] = {
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
};

// Set of ClassName::MethodName pairs such that the class can return a nullptr,
// and thus `std::optional` probably needs to be used.
static std::set<std::pair<std::string, std::string>> kCanReturnNullptr{};

std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;

std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;

static std::string Capitalize(llvm::StringRef name) {
  return name.substr(0, 1).upper() + name.substr(1).str();
}

static std::string CxxName(llvm::StringRef name) {
  if (name == "getKind" || name == "getDeclKindName") {
    return "";  // We have our own `DeclKind`.

  } else if (name == "getFriendDecl") {
    return "FindFriendDecl";

  } else if (name.startswith("get")) {
    return CxxName(name.substr(3));

  // Begin/end iterators.
  } else if (name.endswith("_begin") || name.endswith("_end") ||
             name.endswith("_size") || name.endswith("_empty") ||
             name.endswith("_rbegin") || name.endswith("_rend")) {
    return "";

  // Setters, ignore them.
  } else if (name.startswith("set")) {
    return "";

  } else if (name.endswith("Loc")) {
    return name.substr(0, name.size() - 3).str() + "Token";

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

static void DeclareCppMethods(std::ostream &os, const std::string &class_name) {
#define PASTA_INSTANCE_METHOD_0(cls, id, meth, rt) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        auto &new_rt = kRetTypeMap[PASTA_STR(rt)]; \
        if (!new_rt.empty()) { \
          if (kCanReturnNullptr.count(std::make_pair(class_name, meth_name))) { \
            os << "  std::optional<" << new_rt << "> " << meth_name << "(void) const;\n"; \
          } else { \
            os << "  " << new_rt << ' ' << meth_name << "(void) const;\n"; \
          } \
        } else { \
          os << "  // " << meth_name << "\n"; \
        } \
      } \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth, rt, p0) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(PASTA_SPLAT rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth, rt, p0, p1) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(PASTA_SPLAT rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth, rt, p0, p1, p2) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(PASTA_SPLAT rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth, rt, p0, p1, p2, p3) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(PASTA_SPLAT rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(PASTA_SPLAT rt) << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << ": " << PASTA_STR(PASTA_SPLAT rt) << "\n"; \
      } \
    }
#include "Generated.h"
}

// Adds mappings that translate between clang enumeration types and PASTA
// enumeration types.
static void MapEnumRetTypes(void) {

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    do { \
      std::string rv("  return static_cast<::pasta::"); \
      rv += Capitalize(PASTA_STR(enum_name)); \
      rv += ">(static_cast<" PASTA_STR(PASTA_SPLAT underlying_type) ">(val));\n"; \
      gRetTypeToValMap.emplace("(clang::" PASTA_STR(enum_name) ")", rv); \
      kRetTypeMap.emplace("(clang::" PASTA_STR(enum_name) ")", \
                          Capitalize(PASTA_STR(enum_name))); \
    } while (0);

#define PASTA_DECLARE_CLASS_NAMED_ENUM(class_name, class_id, enum_name, underlying_type) \
    do { \
      std::string rv("  return static_cast<::pasta::"); \
      rv += Capitalize(PASTA_STR(enum_name)); \
      rv += ">(static_cast<" PASTA_STR(PASTA_SPLAT underlying_type) ">(val));\n"; \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", rv); \
      kRetTypeMap.emplace("(clang::" PASTA_STR(enum_name) ")", \
                          Capitalize(PASTA_STR(enum_name))); \
    } while (0);

#include "Generated.h"
}

// Adds mappings that translate between pointers to clang Decl types and PASTA
// Decl types.
static void MapDeclRetTypes(void) {
  for (const auto &name : gDeclNames) {
    std::stringstream ss;
    ss << "(clang::" << name << " *)";
    kRetTypeMap.emplace(ss.str(), "::pasta::" + name);

    std::stringstream rvs;
    rvs
        << "  if (val) {\n"
        << "    return DeclBuilder::Create<::pasta::" << name << ">(ast, val);\n"
        << "  }\n";
    gRetTypeToValMap[ss.str()] = rvs.str();

    std::stringstream ss2;
    ss2 << "(const clang::" << name << " *)";

    kRetTypeMap.emplace(ss2.str(), "::pasta::" + name);

    std::stringstream crvs;
    crvs
        << "  if (val) {\n"
        << "    return DeclBuilder::Create<::pasta::" << name << ">(ast, val);\n"
        << "  }\n";
    gRetTypeToValMap[ss2.str()] = crvs.str();
  }
}

// Declare PASTA versions of every clang enumeration type from our macro file.
static void DeclareEnums(std::ostream &os) {
  llvm::StringRef enumerator_name;

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    os << "enum class " << Capitalize(PASTA_STR(enum_name)) \
       << " : " << PASTA_STR(PASTA_SPLAT underlying_type) << " {\n";

#define PASTA_NAMED_ENUMERATOR(enumerator_name_, underlying_type, val) \
    enumerator_name = #enumerator_name_; \
    for (auto prefix : kEnumPrefixesToStrip) { \
      if (enumerator_name.startswith(prefix)) { \
        enumerator_name = enumerator_name.substr(prefix.size()); \
        break; \
      } \
    } \
    if (!enumerator_name.empty() && \
        !enumerator_name.startswith("first") && \
        !enumerator_name.startswith("last")) { \
      os << "  k" << Capitalize(enumerator_name) << " = " \
         << PASTA_STR(PASTA_SPLAT val) << ",\n"; \
    }

#define PASTA_END_NAMED_ENUM(enum_name) \
    os << "};\n\n";

#include "Generated.h"
}

// Generate `include/pasta/AST/Forward.h`.
static void GenerateForwardH(void) {
  std::ofstream os(kASTForwardHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n"
      << "#include <memory>\n"
      << "#include <optional>\n"
      << "#include <string>\n"
      << "#include <string_view>\n\n"
      << "#include \"Token.h\"\n\n"
      << "namespace clang {\n";

  for (const auto &name : kAllClassNames) {
    os << "class " << name.str() << ";\n";
  }

  os
      << "}  // namespace clang\n"
      << "namespace pasta {\n"
      << "class AST;\n"
      << "class ASTImpl;\n"
      << "class DeclBuilder;\n"
      << "class TypeBuilder;\n\n"
      << "enum class DeclKind : unsigned {\n";

  for (const auto &name_ : gDeclNames) {
    llvm::StringRef name(name_);
    if (name != "Decl") {
      assert(name.endswith("Decl"));
      os << "  k" << name.substr(0, name.size() - 4).str() << ",\n";
    }
  }

  os
      << "};\n\n"
      << "enum class TypeKind : unsigned {\n";

  for (const auto &name_ : gTypeNames) {
    llvm::StringRef name(name_);
    if (name != "Type") {
      os << "  k" << name.substr(0, name.size() - 4).str() << ",\n";
    }
  }

  os
      << "};\n\n";

  // Declare all of the enums.
  DeclareEnums(os);

  // Forward declare them all.
  for (const auto &name : kAllClassNames) {
    os << "class " << name.str() << ";\n";
  }

  os
      << "}  // namespace pasta\n";
}

// Generate `include/pasta/AST/Decl.h`.
static void GenerateDeclH(void) {
  std::ofstream os(kASTDeclHeader);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#pragma once\n\n"
      << "#include \"Forward.h\"\n\n"
      << "namespace pasta {\n"
      << "class DeclContext {\n"
      << " public:\n"
      << "  DeclContext(std::shared_ptr<ASTImpl> ast_, const clang::DeclContext *) {}\n"
      << "};\n\n";

  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    llvm::StringRef name_ref(name);
    if (name == "DeclContext") {
      continue;
    }

    os
        << "class " << name;

    auto sep = " : ";
    for (const auto &parent_class : gBaseClasses[name]) {
      if (parent_class != "DeclContext") {
        os << sep << "public " << parent_class;
        sep = ", ";
      }
    }

    os
        << " {\n"
        << " public:\n"
        << "  ~" << name << "(void) = default;\n"
        << "  " << name << "(const " << name << " &) = default;\n"
        << "  " << name << "(" << name << " &&) noexcept = default;\n"
        << "  " << name << " &operator=(const " << name << " &) = default;\n"
        << "  " << name << " &operator=(" << name << " &&) noexcept = default;\n\n";

//    // Permits down-casting.
//    for (const auto &base_name : gTransitiveBaseClasses[name]) {
//      if (base_name != "DeclContext") {
//        os << "  static std::optional<" << name << "> From(const "
//           << base_name << " &);\n";
//      }
//    }

    DeclareCppMethods(os, name);

    // The top level `Decl` class has all the content.
    if (name == "Decl") {
      os
          << "  inline DeclKind Kind(void) const {\n"
          << "    return kind;\n"
          << "  }\n\n"
          << "  std::string_view KindName(void) const;\n\n"
          << "  inline bool operator==(const Decl &that) const noexcept {\n"
          << "    return u.opaque == that.u.opaque;\n"
          << "  }\n"
          << " protected:\n"
          << "  std::shared_ptr<ASTImpl> ast;\n"
          << "  union {\n";

      for (const auto &name : gDeclNames) {
        os << "    const ::clang::" << name << " *" << name << ";\n";
      }

      os
          << "    const void *opaque;\n"
          << "  } u;\n"
          << "  DeclKind kind;\n\n"
          << "  inline explicit Decl(std::shared_ptr<ASTImpl> ast_,\n"
          << "                       const ::clang::Decl *decl_,\n"
          << "                       DeclKind kind_)\n"
          << "      : ast(std::move(ast_)),\n"
          << "        kind(kind_) {\n"
          << "    u.Decl = decl_;\n"
          << "  }\n\n";
    }

    os
        << " private:\n"
        << "  " << name << "(void) = delete;\n\n"
        << "  friend class DeclBuilder;\n"
        << "  friend class AST;\n"
        << "  friend class ASTImpl;\n\n"
        << " protected:\n"
        << "  explicit " << name << "(\n"
        << "      std::shared_ptr<ASTImpl> ast_,\n"
        << "      const ::clang::" << name << " *decl_);\n"
        << "};\n\n";

    // Requiring that all derivations have the same size as the base class
    // will let us do fun sketchy things.
    if (name != "Decl" && name_ref.endswith("Decl")) {
      os << "static_assert(sizeof(Decl) == sizeof(" << name << "));\n\n";

    // Require all `Type` derivations to have the same size as `Type`.
    } else if (name != "Type" && name_ref.endswith("Type")) {
      os << "static_assert(sizeof(Type) == sizeof(" << name << "));\n\n";
    }
  }

  os
      << "}  // namespace pasta\n";
}

static void DefineCppMethods(std::ostream &os, const std::string &class_name) {
#define PASTA_INSTANCE_METHOD_0(cls, id, meth, rt) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        auto &rt_type = kRetTypeMap[PASTA_STR(rt)]; \
        auto &rt_val = gRetTypeToValMap[PASTA_STR(rt)]; \
        llvm::StringRef rt_ref(PASTA_STR(rt)); \
        if (!rt_type.empty() && !rt_val.empty()) { \
          const auto can_ret_null = kCanReturnNullptr.count(\
              std::make_pair(class_name, meth_name)); \
          if (can_ret_null) { \
            os << "std::optional<" << rt_type << ">"; \
          } else { \
            os << rt_type; \
          } \
          os << " " << class_name << "::" << meth_name << "(void) const {\n" \
             << "  auto val = u." << class_name << "->" << PASTA_STR(meth) << "();\n" \
             << rt_val; \
          if (rt_ref.endswith(" *)")) { \
            if (can_ret_null) { \
              os << "  return std::nullopt;\n"; \
            } else { \
              os << "  assert(false && \"" << class_name << "::" \
                 << meth_name << " can return nullptr!\");\n" \
                 << "  __builtin_unreachable();\n"; \
            } \
          } \
          os << "}\n\n"; \
        } else { \
          os << "  // " << meth_name << "\n"; \
        } \
      } \
    }

#define PASTA_INSTANCE_METHOD_1(cls, id, meth, rt, p0) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_2(cls, id, meth, rt, p0, p1) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_3(cls, id, meth, rt, p0, p1, p2) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_4(cls, id, meth, rt, p0, p1, p2, p3) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_5(cls, id, meth, rt, p0, p1, p2, p3, p4) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }

#define PASTA_INSTANCE_METHOD_6(cls, id, meth, rt, p0, p1, p2, p3, p4, p5) \
    if (class_name == PASTA_STR(cls)) { \
      if (const auto meth_name = CxxName(PASTA_STR(meth)); !meth_name.empty()) { \
        os << "  // " << meth_name << "\n"; \
      } \
    }
#include "Generated.h"
}

// Generate `lib/AST/Decl.cpp`.
static void GenerateDeclCpp(void) {
  std::ofstream os(kASTDeclCpp);

  os
      << "/*\n"
      << " * Copyright (c) 2021 Trail of Bits, Inc.\n"
      << " */\n\n"
      << "// This file is auto-generated.\n\n"
      << "#include <pasta/AST/Decl.h>\n\n"
      << "#pragma clang diagnostic push\n"
      << "#pragma clang diagnostic ignored \"-Wimplicit-int-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wsign-conversion\"\n"
      << "#pragma clang diagnostic ignored \"-Wshorten-64-to-32\"\n"
      << "#include <clang/AST/Decl.h>\n"
      << "#include <clang/AST/DeclCXX.h>\n"
      << "#include <clang/AST/DeclFriend.h>\n"
      << "#include <clang/AST/DeclObjC.h>\n"
      << "#include <clang/AST/DeclOpenMP.h>\n"
      << "#include <clang/AST/DeclTemplate.h>\n"
      << "#pragma clang diagnostic pop\n\n"
      << "#include \"AST.h\"\n\n"
      << "namespace pasta {\n\n"
      << "class DeclBuilder {\n"
      << " public:\n"
      << "  template <typename T, typename D>\n"
      << "  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *decl_) {\n"
      << "    return T(std::move(ast_), decl_);\n"
      << "  }\n"
      << "};\n\n"
      << "namespace {\n"
      << "// Return the PASTA `DeclKind` for a Clang `Decl`.\n"
      << "static DeclKind KindOfDecl(const clang::Decl *decl) {\n"
      << "  switch (decl->getKind()) {\n"
      << "#define ABSTRACT_DECL(DECL)\n"
      << "#define DECL(DERIVED, BASE) \\\n"
      << "    case clang::Decl::DERIVED: \\\n"
      << "      return DeclKind::k ## DERIVED;\n"
      << "#include <clang/AST/DeclNodes.inc>\n"
      << "  }\n"
      << "  __builtin_unreachable();\n"
      << "}\n\n"
      << "static const std::string_view kKindNames[] = {\n";

  for (const auto &name_ : gDeclNames) {
    llvm::StringRef name(name_);
    if (name != "Decl") {
      assert(name.endswith("Decl"));
      name = name.substr(0, name.size() - 4);
      os << "  \"" << name.str() << "\",\n";
    }
  }

  os
      << "};\n"
      << "}  // namespace\n\n"
      << "std::string_view Decl::KindName(void) const {\n"
      << "  return kKindNames[static_cast<unsigned>(kind)];\n"
      << "}\n\n";


  // Define them all.
  for (const auto &name : gTopologicallyOrderedDecls) {
    if (name == "DeclContext") {
      continue;
    }

    os
        << name << "::" << name << "(\n"
        << "    std::shared_ptr<ASTImpl> ast_,\n"
        << "    const ::clang::" << name << " *decl_)";

    // Dispatch to our hand-written constructor that takes the `DeclKind`.
    if (name == "Decl") {
      os << "\n    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}\n";

    // Dispatch to the base class constructor(s).
    } else {
      auto sep = "\n    : ";
      const auto &base_classes = gBaseClasses[name];
      auto prefix = base_classes.size() == 1u ? "std::move(" : "";
      auto suffix = base_classes.size() == 1u ? ")" : "";
      for (const auto &parent_class : base_classes) {
        if (parent_class != "DeclContext") {
          os << sep << parent_class << "(" << prefix << "ast_" << suffix
             << ", decl_)";
          sep = ",\n      ";
        }
      }
      os << " {}\n\n";
    }

    DefineCppMethods(os, name);
  }

  os
      << "}  // namespace pasta\n";
}

}  // namespace

int main(void) {

  std::unordered_set<std::string> seen;
  seen.insert("DeclContext");

  //gBaseClasses["Decl"].insert("DeclBase");
  //gBaseClasses["DeclContext"].insert("DeclBase");

  for (auto class_name : kAllClassNames) {
    if (class_name.endswith("Decl")) {
      gDeclNames.push_back(class_name.str());

    } else if (class_name.endswith("Type")) {
      gTypeNames.push_back(class_name.str());
    }
  }

  // Build up an adjacency list of parent/child relations.
  for (const auto &[name, base_name] : kExtends) {
    gBaseClasses[name].insert(base_name);
    gDerivedClasses[base_name].insert(name);
  }

  // Topologically order the classes by the parent/child relations.
  for (auto changed = true; changed; ) {
    changed = false;
    for (const auto &name : gDeclNames) {
      if (seen.count(name)) {
        goto skip;
      }

      for (const auto &parent_name : gBaseClasses[name]) {
        if (!seen.count(parent_name)) {
          goto skip;
        }
      }

      gTopologicallyOrderedDecls.push_back(name);
      seen.insert(name);
      changed = true;

    skip:
      continue;
    }
  }

  // Go find the transitive base classes. Rely on the topological order
  // so that we can do it in a single pass.
  for (const auto &base_name : gTopologicallyOrderedDecls) {
    const auto &base_classes = gTransitiveBaseClasses[base_name];

    for (auto &derived_name : gDerivedClasses[base_name]) {
      auto &derived_base_classes = gTransitiveBaseClasses[derived_name];
      derived_base_classes.insert(base_name);
      derived_base_classes.insert(base_classes.begin(), base_classes.end());
    }
  }

  // Go find the transitive derived classes. Rely on the reverse topological
  // order so that we can do it in a single pass.
  for (auto it = gTopologicallyOrderedDecls.rbegin();
       it != gTopologicallyOrderedDecls.rend(); ++it) {
    const auto &derived_name = *it;
    const auto &derived_classes = gTransitiveDerivedClasses[derived_name];

    for (auto &base_name : gBaseClasses[derived_name]) {
      auto &base_derived_classes = gTransitiveDerivedClasses[base_name];
      base_derived_classes.insert(derived_name);
      base_derived_classes.insert(derived_classes.begin(),
                                  derived_classes.end());
    }
  }



  MapEnumRetTypes();
  MapDeclRetTypes();
  GenerateForwardH();
  GenerateDeclH();
  GenerateDeclCpp();

  return EXIT_SUCCESS;
}

