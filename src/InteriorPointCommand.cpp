#include "GeosCli/InteriorPointCommand.hpp"

InteriorPointCommand::InteriorPointCommand(CLI::App* app): Command ("interiorpoint", "Get the interior point from a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void InteriorPointCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto point = geometry->getInteriorPoint();
    auto wkt = writer.write(point.get());
    ostream << wkt << std::endl;
}