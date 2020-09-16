#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class IsEmptyOptions {
    public:
        std::string geometry;
};

class IsEmptyCommand : public Command {

    public:

        IsEmptyCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        IsEmptyOptions options;

};