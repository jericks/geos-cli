#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class UnionOptions {
    public:
        std::string geometry;
        std::string otherGeometry;
};

class UnionCommand : public Command {

    public:

        UnionCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        UnionOptions options;

};