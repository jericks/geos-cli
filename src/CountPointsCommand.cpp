#include "GeosCli/CountPointsCommand.hpp"

CountPointsCommand::CountPointsCommand(CLI::App* app): Command ("countpoints", "Get the number of points") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void CountPointsCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto numberOfPoints = geometry->getNumPoints();
    ostream << numberOfPoints << std::endl;
}