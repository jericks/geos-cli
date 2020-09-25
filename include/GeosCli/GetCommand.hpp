#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class GetOptions {
    public:
        std::string geometry;
        int index;
};

class GetCommand : public Command {

    public:

        GetCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        GetOptions options;

};