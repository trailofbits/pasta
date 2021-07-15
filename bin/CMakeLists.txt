# Copyright (c) 2021 Trail of Bits, Inc., all rights reserved.

if(BOOTSTRAP_MACROS)
    add_subdirectory(BootstrapMacros)
endif()

if(BOOTSTRAP_TYPES)
    add_subdirectory(BootstrapTypes)
endif()

add_subdirectory(DumpAST)
