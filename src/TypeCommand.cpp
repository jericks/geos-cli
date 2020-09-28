#include "GeosCli/TypeCommand.hpp"

TypeCommand::TypeCommand(CLI::App* app): Command ("type") {
    CLI::App* cmd = app->add_subcommand("type", "Get the geometry type a geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void TypeCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto type = geometry->getGeometryType();
    ostream << type << std::endl;
}