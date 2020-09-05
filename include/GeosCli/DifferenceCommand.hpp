#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class DifferenceOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class DifferenceCommand : public Command {

    public:

        DifferenceCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        DifferenceOptions options;

};