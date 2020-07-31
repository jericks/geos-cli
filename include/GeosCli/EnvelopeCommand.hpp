#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include <geos_c.h>

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