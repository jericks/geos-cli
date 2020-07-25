cmake_minimum_required(VERSION 2.8.12)
project(geos-cli)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(geos-cmds STATIC src/Commands.cpp 
    src/Command.cpp 
    src/BufferCommand.cpp 
    src/CentroidCommand.cpp 
    src/ConvexHullCommand.cpp
    src/EnvelopeCommand.cpp
)

add_executable(geos-cli src/App.cpp)
target_link_libraries(geos-cli ${CONAN_LIBS_GEOS})
target_link_libraries(geos-cli geos-cmds)

enable_testing()
add_subdirectory(test)

