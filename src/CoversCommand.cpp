#include "GeosCli/CoversCommand.hpp"

CoversCommand::CoversCommand(CLI::App* app): Command ("covers", "Determine if one geometry covers another") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void CoversCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool covers = geometry.get()->covers(otherGeometry.get());
    ostream << (covers ? "true" : "false") << std::endl;
}