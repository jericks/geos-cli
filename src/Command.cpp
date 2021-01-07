#include "GeosCli/Command.hpp"

Command::Command(std::string commandName, std::string commandDescription) {
    name = commandName;
    description = commandDescription;
};

std::string Command::getName() const {
    return name;
};

std::string Command::getDescription() const {
    return description;
};