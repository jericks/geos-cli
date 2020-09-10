#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class CoveredByOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class CoveredByCommand : public Command {

    public:

        CoveredByCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        CoveredByOptions options;

};