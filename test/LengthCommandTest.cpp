#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, length_test) {
  
  CLI::App app{"GEOS CLI"};  
  LengthCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "length", "-g", "LINESTRING(1 1, 10 10)"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("12.7279\n", outstream.str());

}