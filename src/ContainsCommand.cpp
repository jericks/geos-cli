#include "GeosCli/ContainsCommand.hpp"

ContainsCommand::ContainsCommand(CLI::App* app): Command ("contains", "Determine if one geometry contains another") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void ContainsCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool contains = geometry.get()->contains(otherGeometry.get());
    ostream << (contains ? "true" : "false") << std::endl;
}