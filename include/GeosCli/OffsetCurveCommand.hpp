#pragma once

#define USE_UNSTABLE_GEOS_CPP_API

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/operation/buffer/BufferParameters.h>
#include <geos/operation/buffer/OffsetCurve.h>

class OffsetCurveOptions {
    public:
        std::string geometry;
        double distance;
};

class OffsetCurveCommand : public Command {

    public:

        OffsetCurveCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        OffsetCurveOptions options;

};