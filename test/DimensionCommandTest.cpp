#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, dimension_point_test) {
  
  CLI::App app{"GEOS CLI"};  
  DimensionCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "dimension", "-g", "POINT (1 1)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("0\n", outstream.str());

}

TEST(geos_tests, dimension_polygon_test) {
  
  CLI::App app{"GEOS CLI"};  
  DimensionCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "dimension", "-g", "POLYGON ((17.06298828125 49.7998046875, 14.25048828125 44.04296875, 18.24951171875 44.04296875, 13.45947265625 48.1298828125, 17.06298828125 49.7998046875))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("2\n", outstream.str());

}