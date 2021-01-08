#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, boundary_test) {
  
  CLI::App app{"GEOS CLI"};  
  BoundaryCommand cmd{&app};

  int argc = 4;

  char const *argv[4] = { "geos-cli", "boundary", "-g", "POLYGON((1 1, 1 10, 10 10, 10 1, 1 1))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ(0, outstream.str().rfind("LINESTRING", 0));

}