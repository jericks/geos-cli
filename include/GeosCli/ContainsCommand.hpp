#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class ContainsOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class ContainsCommand : public Command {

    public:

        ContainsCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        ContainsOptions options;

};