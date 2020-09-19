#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class IsSimpleOptions {
    public:
        std::string geometry;
};

class IsSimpleCommand : public Command {

    public:

        IsSimpleCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        IsSimpleOptions options;

};