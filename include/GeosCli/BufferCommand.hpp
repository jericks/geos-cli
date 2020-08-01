#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos_c.h>
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