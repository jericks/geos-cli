#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, coveredby_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  CoveredByCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "coveredby", "-g", "POINT(20 20)", "-o", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}

TEST(geos_tests, coveredby_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  CoveredByCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "coveredby", "-g", "POINT (5 5)", "-o", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}