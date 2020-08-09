#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/triangulate/DelaunayTriangulationBuilder.h>
#include <geos/triangulate/quadedge/QuadEdgeSubdivision.h>

class DelaunayTriangulationOptions {
    public:
        std::string geometry;
};

class DelaunayTriangulationCommand : public Command {

    public:

        DelaunayTriangulationCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        DelaunayTriangulationOptions options;

};