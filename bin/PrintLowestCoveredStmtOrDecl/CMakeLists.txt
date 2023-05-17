# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

add_executable(print-lowest-covered-stmt-or-decl
    "Main.cpp"
)

target_link_libraries(print-lowest-covered-stmt-or-decl PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)
