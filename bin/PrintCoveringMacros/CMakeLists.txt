# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

add_executable(print-covering-macros
    "Main.cpp"
)

target_link_libraries(print-covering-macros PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)
