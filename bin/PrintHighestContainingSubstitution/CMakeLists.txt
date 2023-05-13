# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

add_executable(print-highest-containing-substitution
    "Main.cpp"
)

target_link_libraries(print-highest-containing-substitution PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)