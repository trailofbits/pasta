# Copyright (c) 2022 Trail of Bits, Inc., all rights reserved.

add_executable(find-expanded-macros
    "Main.cpp"
)

target_link_libraries(find-expanded-macros PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)