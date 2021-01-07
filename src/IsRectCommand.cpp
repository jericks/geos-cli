#include "GeosCli/IsRectCommand.hpp"

IsRectCommand::IsRectCommand(CLI::App* app): Command ("isrect", "Determine if a geometry is a rectangle") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void IsRectCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    bool isRect = geometry.get()->isRectangle();
    ostream << (isRect ? "true" : "false") << std::endl;
}