#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, crosses_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  CrossesCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "crosses", "-g", "LINESTRING (1 10, 10 1)", "-o", "LINESTRING (20 30, 20 14)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}

TEST(geos_tests, crosses_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  CrossesCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "crosses", "-g", "LINESTRING (1 1, 10 10)", "-o", "LINESTRING (1 10, 10 1)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}