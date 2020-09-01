#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class CountPointsOptions {
    public:
        std::string geometry;
};

class CountPointsCommand : public Command {

    public:

        CountPointsCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        CountPointsOptions options;

};