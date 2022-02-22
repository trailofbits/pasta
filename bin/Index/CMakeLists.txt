# Copyright (c) 2021 Trail of Bits, Inc., all rights reserved.

add_executable(index-files
    "Main.cpp"
)

target_link_libraries(index-files PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)
