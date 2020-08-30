#include "GeosCli/IsWithinDistanceCommand.hpp"

IsWithinDistanceCommand::IsWithinDistanceCommand(CLI::App* app): Command ("iswithindistance") {
    CLI::App* cmd = app->add_subcommand("iswithindistance", "Determine if two geometries are within the given distance");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
    cmd->add_option("-d", options.distance, "Distance")->required();
}

void IsWithinDistanceCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool isWithinDistance = geometry.get()->isWithinDistance(otherGeometry.get(), options.distance);
    ostream << (isWithinDistance ? "true" : "false") << std::endl;
}