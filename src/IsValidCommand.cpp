#include "GeosCli/IsValidCommand.hpp"

IsValidCommand::IsValidCommand(CLI::App* app): Command ("isvalid") {
    CLI::App* cmd = app->add_subcommand("isvalid", "Determine if a geoemtry is valid");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void IsValidCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    bool isValid = geometry.get()->isValid();
    ostream << (isValid ? "true" : "false") << std::endl;
}