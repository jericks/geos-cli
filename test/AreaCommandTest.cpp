#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, area_test) {
  
  CLI::App app{"GEOS CLI"};  
  AreaCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "area", "-g", "POLYGON((1 1, 1 10, 10 10, 10 1, 1 1))"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("81\n", outstream.str());

}