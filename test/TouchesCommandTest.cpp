#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, touches_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  TouchesCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "touches", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POLYGON ((20 20, 20 30, 30 30, 30 20, 20 20))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}

TEST(geos_tests, touches_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  TouchesCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "touches", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POLYGON ((10 10, 10 14, 14 14, 14 10, 10 10))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}