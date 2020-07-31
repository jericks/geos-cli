#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, buffer_test) {
  
  CLI::App app{"GEOS CLI"};  
  BufferCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "buffer", "-g", "POINT(1 1)", "-d", "2" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  initGEOS(NULL, NULL);
  cmd.execute(instream, outstream);
  finishGEOS();
  
  ASSERT_EQ(0, outstream.str().rfind("POLYGON", 0));

}