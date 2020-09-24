#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, symdifference_test) {
  
  CLI::App app{"GEOS CLI"};  
  SymDifferenceCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "symdifference",  "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POLYGON ((5 5, 5 20, 20 20, 20 5, 5 5))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ(0, outstream.str().rfind("MULTIPOLYGON", 0));

}