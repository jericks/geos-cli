#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, interiorpoint_test) {
  
  CLI::App app{"GEOS CLI"};  
  InteriorPointCommand cmd{&app};

  int argc = 4;
  char const *argv[4] = { "geos-cli", "interiorpoint", "-g", "POLYGON ((-122.39662170410156 47.584168193691696, -122.39542007446289 47.57826273896928, -122.38065719604491 47.58173661653957, -122.37825393676758 47.57166173655188, -122.3938751220703 47.568766297532925, -122.39044189453124 47.56343827149225, -122.36469268798828 47.57050358015324, -122.37258911132812 47.594703722902004, -122.39662170410156 47.584168193691696))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ(0, outstream.str().rfind("POINT", 0));

}