#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, type_test) {
  
  CLI::App app{"GEOS CLI"};  
  TypeCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "type", "-g", "POLYGON((1 1, 1 10, 10 10, 10 1, 1 1))"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("Polygon\n", outstream.str());

}