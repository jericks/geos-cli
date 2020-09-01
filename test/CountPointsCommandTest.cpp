#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, countpoints_test) {
  
  CLI::App app{"GEOS CLI"};  
  CountPointsCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "countpoints", "-g", "MULTIPOINT(1 1, 1 10, 10 10, 10 1, 1 1)"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("5\n", outstream.str());

}