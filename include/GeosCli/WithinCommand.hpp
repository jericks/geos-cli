#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class WithinOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class WithinCommand : public Command {

    public:

        WithinCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        WithinOptions options;

};