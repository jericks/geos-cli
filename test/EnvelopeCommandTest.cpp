#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, envelope_test) {
  
  CLI::App app{"GEOS CLI"};  
  EnvelopeCommand cmd{&app};

  int argc = 4;

  char const *argv[4] = { "geos-cli", "envelope", "-g", "MULTIPOINT ((12.27256417862947 12.73833434783841), (13.737894633461437 7.658802439672621), (6.857126638942733 8.821305316892328), (9.260874914207697 13.087320259444919), (8.017822881853032 7.492806794533148))" };

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  cmd.execute(instream, outstream);

  ASSERT_EQ(0, outstream.str().rfind("POLYGON", 0));

}