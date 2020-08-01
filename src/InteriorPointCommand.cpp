#include "GeosCli/InteriorPointCommand.hpp"

InteriorPointCommand::InteriorPointCommand(CLI::App* app): Command ("interiorpoint") {
    CLI::App* cmd = app->add_subcommand("interiorpoint", "Get the interior point from a geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void InteriorPointCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto centroid = geometry->getInteriorPoint();
    auto wkt = writer.write(centroid.get());
    ostream << wkt << std::endl;
}