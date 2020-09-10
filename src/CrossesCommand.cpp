#include "GeosCli/CrossesCommand.hpp"

CrossesCommand::CrossesCommand(CLI::App* app): Command ("crosses") {
    CLI::App* cmd = app->add_subcommand("crosses", "Determine if one geometry is crosses another");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void CrossesCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool crosses = geometry.get()->crosses(otherGeometry.get());
    ostream << (crosses ? "true" : "false") << std::endl;
}