#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/geom/Point.h>

class CentroidOptions {
    public:
        std::string geometry;
        double distance;
};

class CentroidCommand : public Command {

    public:

        CentroidCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        CentroidOptions options;

};