#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, isrect_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsRectCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "isrect", "-g", "POINT (1 1)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}

TEST(geos_tests, isrect_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsRectCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "isrect", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}