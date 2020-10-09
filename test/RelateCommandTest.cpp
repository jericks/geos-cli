#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, relate_matrix_test) {
  
  CLI::App app{"GEOS CLI"};  
  RelateCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = {"geos-cli", "relate", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POINT(5 5)" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("0F2FF1FF2\n", outstream.str());

}

TEST(geos_tests, relate_true_test) {
  
  CLI::App app{"GEOS CLI"};  
  RelateCommand cmd{&app};

  int argc = 8;
  char const *argv[8] = {"geos-cli", "relate", "-g", "POLYGON ((0 0, 0 10, 10 10, 10 0, 0 0))", "-o", "POINT(5 5)", "-m", "0F2FF1FF2" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ("true\n", outstream.str());

}