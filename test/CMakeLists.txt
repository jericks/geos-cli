ADD_EXECUTABLE(tests 
    AreaCommandTest.cpp
    BoundaryCommandTest.cpp
    BufferCommandTest.cpp
    CentroidCommandTest.cpp
    ContainsCommandTest.cpp
    ConvexHullCommandTest.cpp
    DelaunayTriangulationCommandTest.cpp
    EnvelopeCommandTest.cpp
    InteriorPointCommandTest.cpp
    IntersectsCommandTest.cpp
    ListCommandTest.cpp
    VoronoiDiagramCommandTest.cpp
    WithinCommandTest.cpp
)
target_link_libraries(tests 
    geos-cmds
    ${CONAN_LIBS_GEOS} 
    ${CONAN_LIBS_GTEST} 
    ${CONAN_LIBS_GTEST_MAIN}
)

ADD_TEST(NAME "GeosCliTests" COMMAND "tests")
