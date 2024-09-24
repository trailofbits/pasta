#
# Copyright (c) 2020, Trail of Bits, Inc.
# 
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable(bootstrap-types
    "Generated.h"
    "DefineDefaultMacros.h"
    "UndefineDefaultMacros.h"
    "Main.cpp"

    "DeclareCppMethods.cpp"
    "DeclareEnums.cpp"
    "DefineCppMethods.cpp"
    "GenerateAttrCpp.cpp"
    "GenerateAttrH.cpp"
    "GenerateDeclCpp.cpp"
    "GenerateDeclH.cpp"
    "GenerateForwardH.cpp"
    "GenerateStmtCpp.cpp"
    "GenerateStmtH.cpp"
    "GenerateTypeCpp.cpp"
    "GenerateTypeH.cpp"
    "Globals.cpp"
    "Globals.h"
    "MapRetTypes.cpp"
    "Util.cpp"
    "Util.h"
)

target_link_libraries(bootstrap-types PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
    pasta_bootstrap_config
)

if(PASTA_BOOTSTRAP_ENABLE_ASSERTIONS)
    target_compile_definitions(bootstrap-types PRIVATE PASTA_USE_ASSERT=1)
endif()