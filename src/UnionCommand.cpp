#include "GeosCli/UnionCommand.hpp"

UnionCommand::UnionCommand(CLI::App* app): Command ("union") {
    CLI::App* cmd = app->add_subcommand("union", "Calculate the union between two geometries");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void UnionCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    geos::io::WKTWriter writer;
    auto result = geometry->Union(otherGeometry.get());
    auto wkt = writer.write(result.get());
    ostream << wkt << std::endl;
}