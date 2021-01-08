#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, get_test_1) {
  
  CLI::App app{"GEOS CLI"};  
  GetCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = { "geos-cli", "get", "-g", "MULTIPOINT (1 1, 5 5, 10 10)", "-i", "1"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ("POINT (1.0000000000000000 1.0000000000000000)\n", outstream.str());

}

TEST(geos_tests, get_test_2) {
  
  CLI::App app{"GEOS CLI"};  
  GetCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = { "geos-cli", "get", "-g", "MULTIPOINT (1 1, 5 5, 10 10)", "-i", "2"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ("POINT (5.0000000000000000 5.0000000000000000)\n", outstream.str());

}

TEST(geos_tests, get_test_3) {
  
  CLI::App app{"GEOS CLI"};  
  GetCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = { "geos-cli", "get", "-g", "MULTIPOINT (1 1, 5 5, 10 10)", "-i", "3"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ("POINT (10.0000000000000000 10.0000000000000000)\n", outstream.str());

}

TEST(geos_tests, get_test_0) {
  
  CLI::App app{"GEOS CLI"};  
  GetCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = { "geos-cli", "get", "-g", "MULTIPOINT (1 1, 5 5, 10 10)", "-i", "0"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ("", outstream.str());

}

TEST(geos_tests, get_test_4) {
  
  CLI::App app{"GEOS CLI"};  
  GetCommand cmd{&app};

  int argc = 6;
  char const *argv[6] = { "geos-cli", "get", "-g", "MULTIPOINT (1 1, 5 5, 10 10)", "-i", "4"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ("", outstream.str());

}