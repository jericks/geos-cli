#include "GeosCli/RelateCommand.hpp"

RelateCommand::RelateCommand(CLI::App* app): Command ("relate") {
    CLI::App* cmd = app->add_subcommand("relate", "Determine if the input Geometry and the other Geometry are related according to the DE-9IM intersection matrix or calculate the DE-9IM.");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
    cmd->add_option("-m", options.intersectionMatrix, "DE-9IM intesection matrix");
}

void RelateCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    if (!options.intersectionMatrix.empty()) {
        bool related = geometry.get()->relate(otherGeometry.get(), options.intersectionMatrix);
        ostream << (related ? "true" : "false") << std::endl;
    } else {
        std::string matrix = geometry.get()->relate(otherGeometry.get())->toString();
        ostream << matrix << std::endl;
    }
}