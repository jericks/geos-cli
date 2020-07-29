#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/geom/Point.h>

class InteriorPointOptions {
    public:
        std::string geometry;
        double distance;
};

class InteriorPointCommand : public Command {

    public:

        InteriorPointCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        InteriorPointOptions options;

};