#include "GeosCli/IsEmptyCommand.hpp"

IsEmptyCommand::IsEmptyCommand(CLI::App* app): Command ("isempty", "Determine if a geometry is empty") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void IsEmptyCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    bool isEmpty = geometry.get()->isEmpty();
    ostream << (isEmpty ? "true" : "false") << std::endl;
}