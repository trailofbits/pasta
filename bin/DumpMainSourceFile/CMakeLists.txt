# Copyright (c) 2021 Trail of Bits, Inc., all rights reserved.

add_executable(dump-file
    "Main.cpp"
)

target_link_libraries(dump-file PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)
