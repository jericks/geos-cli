#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, iswithindistance_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsWithinDistanceCommand cmd{&app};

  int argc = 8;
  char const *argv[8] = {"geos-cli", "iswithindistance", "-g", "POINT(5 5)", "-o", "POINT (2 2)", "-d", "5" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}

TEST(geos_tests, iswithindistance_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsWithinDistanceCommand cmd{&app};

  int argc = 8;
  char const *argv[8] = {"geos-cli", "iswithindistance", "-g", "POINT(5 5)", "-o", "POINT (2 2)", "-d", "1" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}