ADD_EXECUTABLE(tests 
    AreaCommandTest.cpp
    BufferCommandTest.cpp
    CentroidCommandTest.cpp
    ConvexHullCommandTest.cpp
    DelaunayTriangulationCommandTest.cpp
    EnvelopeCommandTest.cpp
    InteriorPointCommandTest.cpp
    ListCommandTest.cpp
    VoronoiDiagramCommandTest.cpp
)
target_link_libraries(tests 
    geos-cmds
    ${CONAN_LIBS_GEOS} 
    ${CONAN_LIBS_GTEST} 
    ${CONAN_LIBS_GTEST_MAIN}
)

ADD_TEST(NAME "GeosCliTests" COMMAND "tests")
