#include <sstream>
#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI/CLI.hpp"
#include "gtest/gtest.h"

TEST(geos_tests, list_test) {
  
  CLI::App app{"GEOS CLI"};  

  Commands commands;
  BufferCommand bufferCommand{&app};
  commands.add(&bufferCommand);
  ListCommand listCommand{&app, &commands};
  commands.add(&listCommand);

  int argc = 2;
  char const *argv[2] = {"geos-cli", "list"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  listCommand.execute(instream, outstream);

  std::string result = outstream.str();
  ASSERT_NE(std::string::npos, result.find("list"));
  ASSERT_NE(std::string::npos, result.find("buffer"));
  ASSERT_EQ(std::string::npos, result.find("notacommand"));
}

TEST(geos_tests, list_description_test) {
  
  CLI::App app{"GEOS CLI"};  

  Commands commands;
  BufferCommand bufferCommand{&app};
  commands.add(&bufferCommand);
  ListCommand listCommand{&app, &commands};
  commands.add(&listCommand);

  int argc = 3;
  char const *argv[3] = {"geos-cli", "list", "-d"};

  app.parse(argc, argv);

  std::istringstream instream;
  std::ostringstream outstream;

  listCommand.execute(instream, outstream);

  std::string result = outstream.str();
  ASSERT_NE(std::string::npos, result.find("list = List all commands"));
  ASSERT_NE(std::string::npos, result.find("buffer = Buffer a geometry"));
  ASSERT_EQ(std::string::npos, result.find("notacommand"));
}