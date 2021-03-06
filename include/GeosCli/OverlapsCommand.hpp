#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class OverlapsOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class OverlapsCommand : public Command {

    public:

        OverlapsCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        OverlapsOptions options;

};