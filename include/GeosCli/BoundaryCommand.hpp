#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class BoundaryOptions {
    public:
        std::string geometry;
        double distance;
};

class BoundaryCommand : public Command {

    public:

        BoundaryCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        BoundaryOptions options;

};