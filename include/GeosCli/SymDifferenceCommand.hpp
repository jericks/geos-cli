#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class SymDifferenceOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class SymDifferenceCommand : public Command {

    public:

        SymDifferenceCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        SymDifferenceOptions options;

};