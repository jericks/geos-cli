#include "GeosCli/IntersectionCommand.hpp"

IntersectionCommand::IntersectionCommand(CLI::App* app): Command ("intersection") {
    CLI::App* cmd = app->add_subcommand("intersection", "Calculate the intersection between two geometries");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void IntersectionCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    geos::io::WKTWriter writer;
    auto intersection = geometry->intersection(otherGeometry.get());
    auto wkt = writer.write(intersection.get());
    ostream << wkt << std::endl;
}