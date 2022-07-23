#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, offsetcurve_test) {
  
  CLI::App app{"GEOS CLI"};  
  OffsetCurveCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "offsetcurve", "-g", "LINESTRING(1 2, 10 30)", "-d", "2" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ(0, outstream.str().rfind("LINESTRING", 0));

}