find_package(Python 3.7 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(py-pasta
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ArgumentVector.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CompileCommand.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/module.cpp")
target_link_libraries(py-pasta PRIVATE pasta)