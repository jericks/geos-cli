#include "GeosCli/CountCommand.hpp"

CountCommand::CountCommand(CLI::App* app): Command ("count", "Get the number of geometries") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void CountCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto count = geometry->getNumGeometries();
    ostream << count << std::endl;
}