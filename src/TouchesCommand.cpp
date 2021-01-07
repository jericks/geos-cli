#include "GeosCli/TouchesCommand.hpp"

TouchesCommand::TouchesCommand(CLI::App* app): Command ("touches", "Determine if one geometry is touches another") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void TouchesCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool touches = geometry.get()->touches(otherGeometry.get());
    ostream << (touches ? "true" : "false") << std::endl;
}