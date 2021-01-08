#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class IsWithinDistanceOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
        double distance;
};

class IsWithinDistanceCommand : public Command {

    public:

        IsWithinDistanceCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        IsWithinDistanceOptions options;

};