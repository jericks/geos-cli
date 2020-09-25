#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, coordinates_test) {
  
  CLI::App app{"GEOS CLI"};  
  CoordinatesCommand cmd{&app};

  int argc = 4;

  char const *argv[4] = { "geos-cli", "coordinates", "-g", "POLYGON ((1 1, 1 10, 10 10, 10 1, 1 1))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ("MULTIPOINT (1.0000000000000000 1.0000000000000000, 1.0000000000000000 10.0000000000000000, 10.0000000000000000 10.0000000000000000, 10.0000000000000000 1.0000000000000000, 1.0000000000000000 1.0000000000000000)\n", outstream.str());

}