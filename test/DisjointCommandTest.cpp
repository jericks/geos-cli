#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, disjoint_test) {
  
  CLI::App app{"GEOS CLI"};  
  DisjointCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "disjoint", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "LINESTRING (15 15, 20 20)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}