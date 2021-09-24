# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

add_executable(bootstrap-types
    "Generated.h"
    "DefineDefaultMacros.h"
    "UndefineDefaultMacros.h"
    "Main.cpp"

    "DeclareCppMethods.cpp"
    "DeclareEnums.cpp"
    "DefineCppMethods.cpp"
    "GenerateDeclCpp.cpp"
    "GenerateDeclH.cpp"
    "GenerateForwardH.cpp"
    "GenerateTypeCpp.cpp"
    "GenerateTypeH.cpp"
    "Globals.cpp"
    "Globals.h"
    "MapDeclRetTypes.cpp"
    "MapEnumRetTypes.cpp"
    "MapTypeRetTypes.cpp"
    "Util.cpp"
    "Util.h"
)

target_link_libraries(bootstrap-types PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
    pasta_bootstrap_config
)

if(CMAKE_CXX_COMPILER_ID IN_LIST GNULIKE_COMPILER_LIST)
    target_compile_options(bootstrap-types PUBLIC -O0 -g0)
endif()