#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, union_test) {
  
  CLI::App app{"GEOS CLI"};  
  UnionCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "union",  "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POLYGON ((5 5, 5 15, 15 15, 15 5, 5 5))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ(0, outstream.str().rfind("POLYGON", 0));

}