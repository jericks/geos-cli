cmake_minimum_required(VERSION 2.8.12)
project(geos-cli)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(geos-cmds STATIC src/Commands.cpp 
    src/Command.cpp 
    src/AreaCommand.cpp
    src/BoundaryCommand.cpp 
    src/BufferCommand.cpp 
    src/CentroidCommand.cpp 
    src/ContainsCommand.cpp
    src/ConvexHullCommand.cpp
    src/CountCommand.cpp
    src/CountPointsCommand.cpp
    src/CoveredByCommand.cpp
    src/CoversCommand.cpp
    src/CrossesCommand.cpp
    src/DelaunayTriangulationCommand.cpp
    src/DifferenceCommand.cpp
    src/DisjointCommand.cpp
    src/DistanceCommand.cpp
    src/EnvelopeCommand.cpp
    src/InteriorPointCommand.cpp
    src/IntersectionCommand.cpp
    src/IntersectsCommand.cpp
    src/IsEmptyCommand.cpp
    src/IsValidCommand.cpp
    src/IsWithinDistanceCommand.cpp
    src/LengthCommand.cpp
    src/ListCommand.cpp
    src/TouchesCommand.cpp
    src/VoronoiDiagramCommand.cpp
    src/WithinCommand.cpp
)

add_executable(geos-cli src/App.cpp)
target_link_libraries(geos-cli geos-cmds ${CONAN_LIBS_GEOS})

enable_testing()
add_subdirectory(test)