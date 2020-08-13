#include "GeosCli/BoundaryCommand.hpp"

BoundaryCommand::BoundaryCommand(CLI::App* app): Command ("boundary") {
    CLI::App* cmd = app->add_subcommand("boundary", "Get the bounds of a geometry");
    cmd->add_option("-g", options.geometry, "Input Geometry");
}

void BoundaryCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto envelope = geometry->getBoundary();
    auto wkt = writer.write(envelope.get());
    ostream << wkt << std::endl;
}