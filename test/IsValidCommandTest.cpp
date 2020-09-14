#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, isvalid_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsValidCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "isvalid", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}

TEST(geos_tests, isvalid_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsValidCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "isvalid", "-g", "POLYGON ((17.06298828125 49.7998046875, 14.25048828125 44.04296875, 18.24951171875 44.04296875, 13.45947265625 48.1298828125, 17.06298828125 49.7998046875))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}