/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Globals.h"

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
std::vector<std::string> gTypeNames;

const std::unordered_map<std::string, std::string> kCxxMethodRenames{
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
std::unordered_map<std::string, std::string> kRetTypeMap{
  {"(bool)", "bool"},
  {"(clang::SourceLocation)", "std::optional<::pasta::Token>"},
  {"(llvm::StringRef)", "std::string_view"},
  {"(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>)", "std::string"},
  {"(unsigned int)", "uint32_t"},
  {"(unsigned long)", "uint64_t"},
};

// Maps return types from the macros file to how they should be returned
// in the generated Decl.cpp file.
std::unordered_map<std::string, std::string> gRetTypeToValMap{
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

std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;

std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;
