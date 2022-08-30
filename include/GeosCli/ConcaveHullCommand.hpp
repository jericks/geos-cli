#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/algorithm/hull/ConcaveHull.h>

class ConcaveHullOptions {
    public:
        std::string geometry;
        double length;
};

class ConcaveHullCommand : public Command {

    public:

        ConcaveHullCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        ConcaveHullOptions options;

};