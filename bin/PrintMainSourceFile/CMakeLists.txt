# Copyright (c) 2021 Trail of Bits, Inc., all rights reserved.

add_executable(print-main-source-file
    "Main.cpp"
)

target_link_libraries(print-main-source-file PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)
