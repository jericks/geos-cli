cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)
project(geos-cli VERSION 0.0.1 LANGUAGES CXX)

# Conan
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(GEOS REQUIRED)
find_package(GTest REQUIRED)
find_package(CLI11 REQUIRED)

# Library
add_library(geos-cmds STATIC 
    src/Commands.cpp 
    src/Command.cpp 
    src/AreaCommand.cpp
    src/BoundaryCommand.cpp 
    src/BufferCommand.cpp 
    src/CentroidCommand.cpp 
    src/ContainsCommand.cpp
    src/ConvexHullCommand.cpp
    src/CoordinatesCommand.cpp
    src/CountCommand.cpp
    src/CountPointsCommand.cpp
    src/CoveredByCommand.cpp
    src/CoversCommand.cpp
    src/CrossesCommand.cpp
    src/DelaunayTriangulationCommand.cpp
    src/DifferenceCommand.cpp
    src/DimensionCommand.cpp
    src/DisjointCommand.cpp
    src/DistanceCommand.cpp
    src/EnvelopeCommand.cpp
    src/GetCommand.cpp
    src/InteriorPointCommand.cpp
    src/IntersectionCommand.cpp
    src/IntersectsCommand.cpp
    src/IsEmptyCommand.cpp
    src/IsRectCommand.cpp
    src/IsSimpleCommand.cpp
    src/IsValidCommand.cpp
    src/IsWithinDistanceCommand.cpp
    src/LengthCommand.cpp
    src/ListCommand.cpp
    src/MakeValidCommand.cpp
    src/OverlapsCommand.cpp
    src/RelateCommand.cpp
    src/SymDifferenceCommand.cpp
    src/TouchesCommand.cpp
    src/TypeCommand.cpp
    src/UnionCommand.cpp
    src/VoronoiDiagramCommand.cpp
    src/WithinCommand.cpp
)
add_library(GeosCli::geos-cmds ALIAS geos-cmds)
target_include_directories(geos-cmds PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_features(geos-cmds PUBLIC cxx_std_11)
target_link_libraries(geos-cmds PRIVATE GEOS::GEOS CLI11::CLI11)

# Application
add_executable(geos-cli src/App.cpp)
target_link_libraries(geos-cli PRIVATE geos-cmds GEOS::GEOS CLI11::CLI11)

# Tests
enable_testing()
add_subdirectory(test)