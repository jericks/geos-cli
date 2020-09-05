#include "GeosCli/DifferenceCommand.hpp"

DifferenceCommand::DifferenceCommand(CLI::App* app): Command ("difference") {
    CLI::App* cmd = app->add_subcommand("difference", "Calculate the difference between two geometries");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void DifferenceCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    geos::io::WKTWriter writer;
    auto difference = geometry->difference(otherGeometry.get());
    auto wkt = writer.write(difference.get());
    ostream << wkt << std::endl;
}