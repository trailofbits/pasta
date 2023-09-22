# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

find_package(Python 3.11 COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(src/AST)

nanobind_add_module(pypasta LTO NB_STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/AST/AST.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ArgumentVector.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/AST.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Bindings.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Bindings.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CompileCommand.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CompileJob.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Compiler.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Macro.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Module.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Printer.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Token.cpp"
    ${PASTA_PYTHON_AST_SOURCES})

target_link_libraries(pypasta PRIVATE pasta)