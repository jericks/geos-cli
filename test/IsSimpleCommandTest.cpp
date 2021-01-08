#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, issimple_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsSimpleCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "issimple", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}

TEST(geos_tests, issimple_false_test) {
  
  CLI::App app{"GEOS CLI"};  
  IsSimpleCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = {"geos-cli", "issimple", "-g", "LINESTRING (8.14208984375 48.0419921875, 10.60302734375 51.6015625, 11.56982421875 47.91015625, 8.36181640625 50.72265625)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("false\n", outstream.str());

}