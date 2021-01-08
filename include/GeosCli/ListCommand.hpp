#pragma once

#include "CLI11.hpp"
#include "GeosCli/Command.hpp"
#include "GeosCli/Commands.hpp"

class ListOptions {
    public:
        bool showDescription = false;
};

class ListCommand : public Command {

    public:

        ListCommand(CLI::App* app, Commands* commands);

        void execute(std::istream& istream, std::ostream& ostream);

    private:

        ListOptions options;

        Commands* commands;
};