#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class BufferOptions {
    public:
        std::string geometry;
        double distance;
};

class BufferCommand : public Command {

    public:

        BufferCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        BufferOptions options;

};