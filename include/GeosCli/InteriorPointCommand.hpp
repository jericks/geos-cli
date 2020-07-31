#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos_c.h>

class InteriorPointOptions {
    public:
        std::string geometry;
        double distance;
};

class InteriorPointCommand : public Command {

    public:

        InteriorPointCommand(CLI::App* app);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        InteriorPointOptions options;

};