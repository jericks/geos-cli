#include "GeosCli/OverlapsCommand.hpp"

OverlapsCommand::OverlapsCommand(CLI::App* app): Command ("overlaps") {
    CLI::App* cmd = app->add_subcommand("overlaps", "Determine if one geometry overlaps another");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void OverlapsCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool overlaps = geometry.get()->overlaps(otherGeometry.get());
    ostream << (overlaps ? "true" : "false") << std::endl;
}