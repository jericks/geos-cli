#include "GeosCli/IsEmptyCommand.hpp"

IsEmptyCommand::IsEmptyCommand(CLI::App* app): Command ("isempty") {
    CLI::App* cmd = app->add_subcommand("isempty", "Determine if a geoemtry is empty");
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