#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class IntersectsOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class IntersectsCommand : public Command {

    public:

        IntersectsCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        IntersectsOptions options;

};