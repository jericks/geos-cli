#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, voronoi_test) {
  
  CLI::App app{"GEOS CLI"};  
  VoronoiDiagramCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = { "geos-cli", "voronoidiagram", "-g", "MULTIPOINT ((-53.979858979818516 -70.33735880193296), (63.835508810294016 35.31802926793449), (48.5389085690133 -23.614423069809703), (67.25245886702766 -44.07914094501147), (-45.446181860439914 11.257960381463633))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ(0, outstream.str().rfind("GEOMETRYCOLLECTION", 0));

}