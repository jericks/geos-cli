#include "GeosCli/AreaCommand.hpp"

AreaCommand::AreaCommand(CLI::App* app): Command ("area", "Get the area a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void AreaCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto area = geometry->getArea();
    ostream << area << std::endl;
}