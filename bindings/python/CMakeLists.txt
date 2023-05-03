find_package(Python 3.7 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

add_subdirectory(src/AST)

pybind11_add_module(py-pasta
    "${CMAKE_CURRENT_SOURCE_DIR}/src/AST/AST.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ArgumentVector.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CompileCommand.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/module.cpp"
    ${PASTA_PYTHON_AST_SOURCES})
target_link_libraries(py-pasta PRIVATE pasta)