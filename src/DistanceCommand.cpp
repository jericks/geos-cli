#include "GeosCli/DistanceCommand.hpp"

DistanceCommand::DistanceCommand(CLI::App* app): Command ("distance", "Determine the distance between two geometries") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void DistanceCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    double distance = geometry.get()->distance(otherGeometry.get());
    ostream << distance << std::endl;
}