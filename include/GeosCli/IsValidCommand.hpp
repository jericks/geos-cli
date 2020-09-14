#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class IsValidOptions {
    public:
        std::string geometry;
};

class IsValidCommand : public Command {

    public:

        IsValidCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        IsValidOptions options;

};