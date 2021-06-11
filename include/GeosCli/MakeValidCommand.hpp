#pragma once

#ifndef USE_UNSTABLE_GEOS_CPP_API
    #define USE_UNSTABLE_GEOS_CPP_API
#endif

#include "CLI/CLI.hpp"
#include "GeosCli/Command.hpp"
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/geom/Geometry.h>
#include <geos/geom/Point.h>
#include <geos/operation/valid/MakeValid.h>

class MakeValidOptions {
    public:
        std::string geometry;
};

class MakeValidCommand : public Command {

    public:

        MakeValidCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        MakeValidOptions options;

};