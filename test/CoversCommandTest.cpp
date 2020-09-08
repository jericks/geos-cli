#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, covers_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  CoversCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "covers", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POINT(20 20)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}

TEST(geos_tests, covers_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  CoversCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "covers", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POINT (5 5)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}