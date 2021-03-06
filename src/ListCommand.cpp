#include "GeosCli/ListCommand.hpp"

ListCommand::ListCommand(CLI::App* app, Commands* cmds): Command ("list", "List all commands") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_flag("-d", options.showDescription, "Show Description");
    commands = cmds;
}

void ListCommand::execute(std::istream& istream, std::ostream& ostream) {
    for(auto cmd : commands->get()) {
        ostream << cmd->getName();
        if (options.showDescription == true) {
            ostream << " = " << cmd->getDescription();
        }
        ostream << std::endl;
    }
}