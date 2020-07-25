#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>

class EnvelopeOptions {
    public:
        std::string geometry;
        double distance;
};

class EnvelopeCommand : public Command {

    public:

        EnvelopeCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        EnvelopeOptions options;

};