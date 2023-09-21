/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Util/Compiler.h>
#include <string>
#include <string_view>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbitfield-enum-conversion"
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/ASTConsumer.h>
#include <clang/Basic/Builtins.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticIDs.h>
#include <clang/Basic/DiagnosticSema.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Lex/PPCallbacks.h>
#include <clang/Lex/Preprocessor.h>
#include <clang/Lex/PreprocessorOptions.h>
#include <clang/Parse/Parser.h>
#include <clang/Sema/Sema.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/TargetParser/Host.h>
#pragma GCC diagnostic pop

#include "Compiler.h"
#include "../AST/AST.h"

namespace pasta {
namespace detail {

PASTA_BYPASS_MEMBER_OBJECT_ACCESS(clang, Preprocessor, BuiltinInfo,
                                  std::unique_ptr<clang::Builtin::Context>);

using namespace clang;
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(Builtin, Context, TSRecords, llvm::ArrayRef<clang::Builtin::Info>);
PASTA_BYPASS_MEMBER_OBJECT_ACCESS(Builtin, Context, AuxTSRecords, llvm::ArrayRef<clang::Builtin::Info>);
}  // namespace detail

namespace {

static constexpr const char *kNoFeatures = nullptr;
static constexpr auto kNoHeaderName =
    clang::HeaderDesc(clang::HeaderDesc::NO_HEADER);

static constexpr clang::Builtin::Info kXNUBuiltins[] = {
  {"__builtin_tmo_type_get_alignment", "zv*", "nU",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_tmo_type_get_size", "zv*", "nU",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_strip", "v*v*i", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_blend_discriminator", "zv*i", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_sign_constant", "v*v*iv*", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_sign_unauthenticated", "v*v*iv*", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_sign_generic_data", "zv*v*", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_auth_and_resign", "v*v*iv*iv*", "tn",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_auth", "v*v*iv*", "tn",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_ptrauth_string_discriminator", "zcC*", "nc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_virtual_member_address", "v*v*v*", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_load_member_function_pointer", "v*v*v*", "tnc",
   kNoFeatures, kNoHeaderName, clang::LanguageID::ALL_LANGUAGES},

  {"__builtin_coro_param", "bv*v*", "n",
   kNoFeatures, kNoHeaderName, clang::LanguageID::OCL_PIPE},
};

static constexpr clang::Builtin::Info kX86Builtins[] = {

#define TARGET_BUILTIN(id, type, attrs, features) \
  {#id, type, attrs, features, kNoHeaderName, \
   clang::LanguageID::ALL_LANGUAGES},

#include "BuiltinsX86.h"
};

static constexpr clang::Builtin::Info kPPCBuiltins[] = {

#define TARGET_BUILTIN(id, type, attrs, features) \
  {#id, type, attrs, features, kNoHeaderName, \
   clang::LanguageID::ALL_LANGUAGES},

#include "BuiltinsPPC.h"
};

}  // namespace

// Create a custom builtin context for the preprocessor, that has extensions.
void AddCustomBuiltinsToPreprocessor(ASTImpl &ast, clang::Preprocessor &pp) {

  // Intialize the target-specific builtins.
  clang::Builtin::Context &orig_context = pp.getBuiltinInfo();
  orig_context.initializeBuiltins(pp.getIdentifierTable(), pp.getLangOpts());

  const clang::TargetInfo &target = pp.getTargetInfo();
  const llvm::Triple &triple = target.getTriple();
  clang::IdentifierTable &table = pp.getIdentifierTable();

  auto &ts_records =
      orig_context.*PASTA_ACCESS_MEMBER(Builtin, Context, TSRecords);
  auto &aux_ts_records =
      orig_context.*PASTA_ACCESS_MEMBER(Builtin, Context, AuxTSRecords);

  // Create the shadow built-ins if we haven't yet.
  if (ast.target_specific_records.empty()) {

    for (const clang::Builtin::Info &ts_record : ts_records) {
      ast.target_specific_records.emplace_back(ts_record);
    }

    for (const clang::Builtin::Info &aux_ts_record : aux_ts_records) {
      ast.aux_target_specific_records.emplace_back(aux_ts_record);
    }

    // Extend the target-specific records with missing architecture-specific
    // records
    if (triple.isX86()) {
      for (const clang::Builtin::Info &info : kX86Builtins) {
        if (table.find(info.Name) == table.end()) {
          ast.target_specific_records.emplace_back(info);
        }
      }
    } else if (triple.isPPC()) {
      for (const clang::Builtin::Info &info : kPPCBuiltins) {
        if (table.find(info.Name) == table.end()) {
          ast.target_specific_records.emplace_back(info);
        }
      }
    }

    // Add in AppleClang-specific XNU builtins.
    if (triple.isOSDarwin()) {
      for (const clang::Builtin::Info &info : kXNUBuiltins) {
        if (table.find(info.Name) == table.end()) {
          ast.target_specific_records.emplace_back(info);
        }
      }
    }
  }

  // Register target-specific built-ins.
  auto i = 0u;
  auto num_orig_records = ts_records.size();
  for (const clang::Builtin::Info &info : ast.target_specific_records) {
    if (i >= num_orig_records ||
        (table.find(info.Name) != table.end() &&
            table.get(info.Name).getBuiltinID() != clang::Builtin::NotBuiltin)) {
      table.get(info.Name).setBuiltinID(i + clang::Builtin::FirstTSBuiltin);
    }
    ++i;
  }

  // Register target-specific built-ins for AuxTarget.
  for (const clang::Builtin::Info &info : ast.aux_target_specific_records) {
    if (table.find(info.Name) != table.end()) {
      if (table.get(info.Name).getBuiltinID() != clang::Builtin::NotBuiltin) {
        table.get(info.Name).setBuiltinID(i + clang::Builtin::FirstTSBuiltin);
      }
    }
    ++i;
  }

  // Set the new context into the preprocessor.
  orig_context.*PASTA_ACCESS_MEMBER(Builtin, Context, TSRecords) =
      ast.target_specific_records;

  orig_context.*PASTA_ACCESS_MEMBER(Builtin, Context, AuxTSRecords) =
      ast.aux_target_specific_records;
}

}  // namespace pasta
