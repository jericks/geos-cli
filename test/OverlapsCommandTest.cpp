#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, overlaps_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  OverlapsCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "overlaps", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POLYGON ((2 2, 2 14, 14 14, 14 2, 2 2))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}

TEST(geos_tests, overlaps_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  OverlapsCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "overlaps", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POINT (15 15)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}