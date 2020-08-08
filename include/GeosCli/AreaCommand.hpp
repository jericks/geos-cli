#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class AreaOptions {
    public:
        std::string geometry;
};

class AreaCommand : public Command {

    public:

        AreaCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        AreaOptions options;

};