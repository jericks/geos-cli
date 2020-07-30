ADD_EXECUTABLE(tests 
    BufferCommandTest.cpp
    CentroidCommandTest.cpp
    ConvexHullCommandTest.cpp
    EnvelopeCommandTest.cpp
    InteriorPointCommandTest.cpp
    ListCommandTest.cpp
)
target_link_libraries(tests 
    geos-cmds
    ${CONAN_LIBS_GEOS} 
    ${CONAN_LIBS_GTEST} 
    ${CONAN_LIBS_GTEST_MAIN}
)

ADD_TEST(NAME "GeosCliTests" COMMAND "tests")
