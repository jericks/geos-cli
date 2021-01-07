#include "GeosCli/IntersectsCommand.hpp"

IntersectsCommand::IntersectsCommand(CLI::App* app): Command ("intersects", "Determine if one geometry intersects another") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void IntersectsCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool intersects = geometry.get()->intersects(otherGeometry.get());
    ostream << (intersects ? "true" : "false") << std::endl;
}