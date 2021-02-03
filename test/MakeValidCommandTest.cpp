#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, makevalid_test) {
  
  CLI::App app{"GEOS CLI"};  
  MakeValidCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = { "geos-cli", "makevalid", "-g", "MULTIPOLYGON(((91 50,79 22,51 10,23 22,11 50,23 78,51 90,79 78,91 50)),((91 100,79 72,51 60,23 72,11 100,23 128,51 140,79 128,91 100)),((91 150,79 122,51 110,23 122,11 150,23 178,51 190,79 178,91 150)),((141 50,129 22,101 10,73 22,61 50,73 78,101 90,129 78,141 50)),((141 100,129 72,101 60,73 72,61 100,73 128,101 140,129 128,141 100)),((141 150,129 122,101 110,73 122,61 150,73 178,101 190,129 178,141 150)))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);
  
  ASSERT_EQ(0, outstream.str().rfind("MULTIPOLYGON", 0));

}