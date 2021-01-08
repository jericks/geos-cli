#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/geom/Geometry.h>

class IsRectOptions {
    public:
        std::string geometry;
};

class IsRectCommand : public Command {

    public:

        IsRectCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        IsRectOptions options;

};