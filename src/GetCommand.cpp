#include "GeosCli/GetCommand.hpp"

GetCommand::GetCommand(CLI::App* app): Command ("get") {
    CLI::App* cmd = app->add_subcommand("get", "Get a sub geometry from a geometry collection by index");
    cmd->add_option("-g", options.geometry, "Input Geometry");
    cmd->add_option("-i", options.index, "The index number of the Geometry")->required();
}

void GetCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    size_t numberOfGeometries = geometry->getNumGeometries();
    if (options.index >= 1 && options.index <= numberOfGeometries) {
        geos::io::WKTWriter writer;
        auto subGeometry = geometry->getGeometryN(options.index - 1);
        auto wkt = writer.write(subGeometry);
        ostream << wkt << std::endl;
    }
}