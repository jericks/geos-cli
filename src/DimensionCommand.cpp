#include "GeosCli/DimensionCommand.hpp"

DimensionCommand::DimensionCommand(CLI::App* app): Command ("dimension") {
    CLI::App* cmd = app->add_subcommand("dimension", "Get the dimension of the geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void DimensionCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto dimensionType = geometry.get()->getDimension();
    ostream << dimensionType << std::endl;
}