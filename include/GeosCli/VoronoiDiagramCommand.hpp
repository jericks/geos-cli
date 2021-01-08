#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/triangulate/VoronoiDiagramBuilder.h>

class VoronoiDiagramOptions {
    public:
        std::string geometry;
};

class VoronoiDiagramCommand : public Command {

    public:

        VoronoiDiagramCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        VoronoiDiagramOptions options;

};