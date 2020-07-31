#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos_c.h>

class CentroidOptions {
    public:
        std::string geometry;
        double distance;
};

class CentroidCommand : public Command {

    public:

        CentroidCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        CentroidOptions options;

};