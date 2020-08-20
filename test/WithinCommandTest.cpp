#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, within_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  WithinCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "within", "-g", "POLYGON ((1 1, 1 10, 10 10, 10 1, 1 1))", "-o", "POINT (2 2)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}

TEST(geos_tests, within_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  WithinCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "within", "-g", "POINT (2 2)", "-o", "POLYGON ((1 1, 1 10, 10 10, 10 1, 1 1))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}