#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class ConvexHullOptions {
    public:
        std::string geometry;
};

class ConvexHullCommand : public Command {

    public:

        ConvexHullCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        ConvexHullOptions options;

};