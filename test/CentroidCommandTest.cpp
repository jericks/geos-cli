#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, centroid_test) {
  
  CLI::App app{"GEOS CLI"};  
  CentroidCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = { "geos-cli", "centroid", "-g", "POINT(1 1)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ(0, outstream.str().rfind("POINT", 0));

}