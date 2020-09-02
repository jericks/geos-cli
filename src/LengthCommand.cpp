#include "GeosCli/LengthCommand.hpp"

LengthCommand::LengthCommand(CLI::App* app): Command ("length") {
    CLI::App* cmd = app->add_subcommand("length", "Get the length a geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void LengthCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto area = geometry->getLength();
    ostream << area << std::endl;
}