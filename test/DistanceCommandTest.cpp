#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, distance_test) {
  
  CLI::App app{"GEOS CLI"};  
  DistanceCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "distance", "-g", "POINT(5 5)", "-o", "POINT (2 2)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("4.24264\n", outstream.str());

}